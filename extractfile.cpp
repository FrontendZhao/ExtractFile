#include "extractfile.h"
#include "qfile.h"

#include "qfiledialog.h"
#include "qmessagebox.h"
ExtractFile::ExtractFile(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.progressBar->setVisible(false);
	
	connect(ui.SelectBtn, SIGNAL(clicked()), this, SLOT(OnSelectBtn()));
	connect(ui.AppointBtn, SIGNAL(clicked()), this, SLOT(OnAppointBtn()));
	connect(ui.ExtractBtn , SIGNAL(clicked()), this, SLOT(OnExtractBtn()));
}

ExtractFile::~ExtractFile()
{
	delete io;//清除io
}

void ExtractFile::OnAppointBtn()
{
	QDir dir;
	RootDir = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("选择文件夹"),	dir.currentPath(),QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	ui.AppointText->setText(RootDir);
}
void ExtractFile::OnExtractBtn()
{
	if (io == nullptr)
	{
		QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("未选择文件！"));
		return;
	}
	if (RootDir.length() == 0)
	{
		QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("未选择文件夹！"));
		return;
	}
	NowProcess = 0;
	ui.progressBar->setVisible(true);
	Extract(0,RootDir);
	ui.progressBar->setValue(io->FileCount);
	//ui.progressBar->setVisible(false);
	QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("抽取完成！"));
}
void ExtractFile::Extract(i32_t DID,QString path)
{
	QVector<Directory> *vec=io->FilePool[DID];
	for each(Directory direct in *vec)
	{
		QString str = QString::fromUtf16((ushort*)(direct.EntryName), direct.NameSize / 2-1);//文件名字
		QString currentstr = path + QString::fromLocal8Bit("/");
		currentstr.append(str);
		QByteArray arr = currentstr.toLocal8Bit();//这个地方不太明白，为啥要分开去写比较合适
		char *tmp = arr.data();
		if (direct.EntryType == 1)
		{
			QDir  dir;
			dir.cd(path);
			dir.mkdir(str);
			Extract(direct.DID, path + "/" + str);
		}
		else
		{
			byte_t *p;
			if (direct.StreamSize <io-> m_Header.MiniSize)
				p =io-> ReadShortStreamFromSID(direct.SID, direct.StreamSize);
			else
				p = io->ReadStreamFromSID(direct.SID, direct.StreamSize);//一次性把所需要写的字符流读取，然后写入文件
			FILE * pFile;
			pFile = fopen(tmp, "wb");
			fwrite(p, sizeof(char), direct.StreamSize, pFile);
			fclose(pFile);
			NowProcess++;
			ui.progressBar->setValue(NowProcess);

		}
	}
	
}
void ExtractFile::OnSelectBtn()
{
	QString path = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("打开文件"), ".", "MDS Files(*.mds)");
	if (path.length() == 0) {
		QMessageBox::information(NULL, tr("Path"), QString::fromLocal8Bit("你未选择任何文件！"));
	}
	else {
		ui.SelectText->setText(path);
		if (io)
			delete io;
		io = new ComDocIO(path);
		ui.progressBar->setRange(0, io->FileCount);
	}
}