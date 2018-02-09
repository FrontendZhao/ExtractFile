#ifndef EXTRACTFILE_H
#define EXTRACTFILE_H

#include <QtWidgets/QMainWindow>
#include "ui_extractfile.h"
#include "ComDocIO.h"

class ExtractFile : public QMainWindow
{
	Q_OBJECT

public:
	ExtractFile(QWidget *parent = 0);
	~ExtractFile();
	public slots:
	void OnSelectBtn();
	void OnAppointBtn();
	void OnExtractBtn();
public:
	ComDocIO *io;
	QString RootDir;
	void Extract(i32_t DID,QString path);
	i32_t NowProcess = 0;
private:
	Ui::ExtractFileClass ui;
};

#endif // EXTRACTFILE_H
