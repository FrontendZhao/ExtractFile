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
	delete io;//���io
}

void ExtractFile::OnAppointBtn()
{
	QDir dir;
	RootDir = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("ѡ���ļ���"),	dir.currentPath(),QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	ui.AppointText->setText(RootDir);
}
void ExtractFile::OnExtractBtn()
{
	if (io == nullptr)
	{
		QMessageBox::information(NULL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("δѡ���ļ���"));
		return;
	}
	if (RootDir.length() == 0)
	{
		QMessageBox::information(NULL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("δѡ���ļ��У�"));
		return;
	}
	NowProcess = 0;
	ui.progressBar->setVisible(true);
	Extract(0,RootDir);
	ui.progressBar->setValue(io->FileCount);
	//ui.progressBar->setVisible(false);
	QMessageBox::information(NULL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��ȡ��ɣ�"));
}
void ExtractFile::Extract(i32_t DID,QString path)
{
	QVector<Directory> *vec=io->FilePool[DID];
	for each(Directory direct in *vec)
	{
		QString str = QString::fromUtf16((ushort*)(direct.EntryName), direct.NameSize / 2-1);//�ļ�����
		QString currentstr = path + QString::fromLocal8Bit("/");
		currentstr.append(str);
		QByteArray arr = currentstr.toLocal8Bit();//����ط���̫���ף�ΪɶҪ�ֿ�ȥд�ȽϺ���
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
				p = io->ReadStreamFromSID(direct.SID, direct.StreamSize);//һ���԰�����Ҫд���ַ�����ȡ��Ȼ��д���ļ�
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
	QString path = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("���ļ�"), ".", "MDS Files(*.mds)");
	if (path.length() == 0) {
		QMessageBox::information(NULL, tr("Path"), QString::fromLocal8Bit("��δѡ���κ��ļ���"));
	}
	else {
		ui.SelectText->setText(path);
		if (io)
			delete io;
		io = new ComDocIO(path);
		ui.progressBar->setRange(0, io->FileCount);
	}
}