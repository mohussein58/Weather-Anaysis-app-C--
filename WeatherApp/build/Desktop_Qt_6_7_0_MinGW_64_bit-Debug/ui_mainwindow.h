/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *submitBtn;
    QLineEdit *Location;
    QLabel *label;
    QLineEdit *startDate;
    QLineEdit *endDate;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *chartWidget;
    QWidget *humidityWidget;
    QWidget *precipWidget;
    QWidget *windWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1367, 895);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        submitBtn = new QPushButton(centralwidget);
        submitBtn->setObjectName("submitBtn");
        submitBtn->setGeometry(QRect(930, 50, 111, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        submitBtn->setFont(font);
        Location = new QLineEdit(centralwidget);
        Location->setObjectName("Location");
        Location->setGeometry(QRect(380, 60, 160, 30));
        QFont font1;
        font1.setPointSize(12);
        Location->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(380, 20, 80, 20));
        label->setFont(font);
        startDate = new QLineEdit(centralwidget);
        startDate->setObjectName("startDate");
        startDate->setGeometry(QRect(660, 20, 240, 30));
        startDate->setFont(font1);
        endDate = new QLineEdit(centralwidget);
        endDate->setObjectName("endDate");
        endDate->setGeometry(QRect(660, 60, 240, 30));
        endDate->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(570, 20, 81, 21));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(570, 60, 81, 21));
        label_3->setFont(font);
        chartWidget = new QWidget(centralwidget);
        chartWidget->setObjectName("chartWidget");
        chartWidget->setGeometry(QRect(50, 110, 600, 350));
        humidityWidget = new QWidget(centralwidget);
        humidityWidget->setObjectName("humidityWidget");
        humidityWidget->setGeometry(QRect(670, 110, 600, 350));
        precipWidget = new QWidget(centralwidget);
        precipWidget->setObjectName("precipWidget");
        precipWidget->setGeometry(QRect(50, 507, 600, 350));
        windWidget = new QWidget(centralwidget);
        windWidget->setObjectName("windWidget");
        windWidget->setGeometry(QRect(670, 500, 600, 350));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1367, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        submitBtn->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Location", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Start Date", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "End Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
