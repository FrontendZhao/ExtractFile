/********************************************************************************
** Form generated from reading UI file 'extractfile.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTRACTFILE_H
#define UI_EXTRACTFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExtractFileClass
{
public:
    QWidget *centralWidget;
    QPushButton *SelectBtn;
    QLineEdit *SelectText;
    QPushButton *AppointBtn;
    QLineEdit *AppointText;
    QProgressBar *progressBar;
    QPushButton *ExtractBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExtractFileClass)
    {
        if (ExtractFileClass->objectName().isEmpty())
            ExtractFileClass->setObjectName(QStringLiteral("ExtractFileClass"));
        ExtractFileClass->resize(582, 230);
        centralWidget = new QWidget(ExtractFileClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SelectBtn = new QPushButton(centralWidget);
        SelectBtn->setObjectName(QStringLiteral("SelectBtn"));
        SelectBtn->setGeometry(QRect(50, 40, 75, 23));
        SelectText = new QLineEdit(centralWidget);
        SelectText->setObjectName(QStringLiteral("SelectText"));
        SelectText->setGeometry(QRect(170, 40, 351, 20));
        AppointBtn = new QPushButton(centralWidget);
        AppointBtn->setObjectName(QStringLiteral("AppointBtn"));
        AppointBtn->setGeometry(QRect(50, 100, 75, 23));
        AppointText = new QLineEdit(centralWidget);
        AppointText->setObjectName(QStringLiteral("AppointText"));
        AppointText->setGeometry(QRect(170, 100, 351, 20));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(170, 150, 351, 23));
        progressBar->setValue(24);
        ExtractBtn = new QPushButton(centralWidget);
        ExtractBtn->setObjectName(QStringLiteral("ExtractBtn"));
        ExtractBtn->setGeometry(QRect(50, 150, 75, 23));
        ExtractFileClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ExtractFileClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 582, 23));
        ExtractFileClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExtractFileClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ExtractFileClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ExtractFileClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ExtractFileClass->setStatusBar(statusBar);

        retranslateUi(ExtractFileClass);

        QMetaObject::connectSlotsByName(ExtractFileClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExtractFileClass)
    {
        ExtractFileClass->setWindowTitle(QApplication::translate("ExtractFileClass", "ExtractFile", Q_NULLPTR));
        SelectBtn->setText(QApplication::translate("ExtractFileClass", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
        AppointBtn->setText(QApplication::translate("ExtractFileClass", "\346\214\207\345\256\232\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        ExtractBtn->setText(QApplication::translate("ExtractFileClass", "\346\212\275\345\217\226", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExtractFileClass: public Ui_ExtractFileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTRACTFILE_H
