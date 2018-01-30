/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *equationInsertLabel;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *degreeLabel;
    QSpinBox *degreeSpinBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *xSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *ySpinBox;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QFrame *framePlot;
    QPushButton *cleanButton;
    QPushButton *computeButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(692, 552);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QStringLiteral("background-color:rgb(186, 186, 186)"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_5->setContentsMargins(10, -1, 10, 20);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(301, 41));
        label->setMaximumSize(QSize(16777215, 150));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QLatin1String("font: 87 20pt \"Segoe UI Black\";\n"
"color:rgb(0, 80, 117);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(400, 50));
        groupBox_2->setMaximumSize(QSize(16777215, 151));
        groupBox_2->setStyleSheet(QLatin1String("font: 87 10pt \"Segoe UI Black\";\n"
"color:rgb(0, 80, 117);"));
        groupBox_2->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, -1, -1, -1);
        equationInsertLabel = new QLabel(groupBox_2);
        equationInsertLabel->setObjectName(QStringLiteral("equationInsertLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(equationInsertLabel->sizePolicy().hasHeightForWidth());
        equationInsertLabel->setSizePolicy(sizePolicy2);
        equationInsertLabel->setStyleSheet(QLatin1String("font: 87 8pt \"Segoe UI Black\";\n"
"color:black;\n"
""));
        equationInsertLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_3->addWidget(equationInsertLabel);


        horizontalLayout_8->addWidget(groupBox_2);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(10, 40, 10, 10);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setMaximumSize(QSize(200, 200));
        groupBox->setStyleSheet(QLatin1String("font: 87 10pt \"Segoe UI Black\";\n"
"color:rgb(0, 80, 117);\n"
""));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 151, 171));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        degreeLabel = new QLabel(layoutWidget);
        degreeLabel->setObjectName(QStringLiteral("degreeLabel"));
        degreeLabel->setStyleSheet(QLatin1String("font: 8pt \"MS Reference Sans Serif\";\n"
"color:black;\n"
""));

        horizontalLayout_4->addWidget(degreeLabel);

        degreeSpinBox = new QSpinBox(layoutWidget);
        degreeSpinBox->setObjectName(QStringLiteral("degreeSpinBox"));
        degreeSpinBox->setStyleSheet(QLatin1String("color:black;\n"
""));
        degreeSpinBox->setMinimum(1);
        degreeSpinBox->setMaximum(4);

        horizontalLayout_4->addWidget(degreeSpinBox);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("font: 8pt \"MS Reference Sans Serif\";\n"
"color:black;\n"
"\n"
""));

        horizontalLayout->addWidget(label_2);

        xSpinBox = new QSpinBox(layoutWidget);
        xSpinBox->setObjectName(QStringLiteral("xSpinBox"));
        xSpinBox->setStyleSheet(QLatin1String("color:black;\n"
""));
        xSpinBox->setMaximum(1000);

        horizontalLayout->addWidget(xSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("color:black;\n"
"font: 8pt \"MS Reference Sans Serif\";"));

        horizontalLayout_2->addWidget(label_3);

        ySpinBox = new QSpinBox(layoutWidget);
        ySpinBox->setObjectName(QStringLiteral("ySpinBox"));
        ySpinBox->setStyleSheet(QLatin1String("color:black;\n"
""));
        ySpinBox->setMaximum(1000);

        horizontalLayout_2->addWidget(ySpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("background-color:rgb(214, 214, 214);\n"
"font: 87 8pt \"Segoe UI Black\";"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout_6->addWidget(groupBox);

        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        horizontalLayout_5->addLayout(horizontalLayout_6);

        framePlot = new QFrame(centralWidget);
        framePlot->setObjectName(QStringLiteral("framePlot"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(framePlot->sizePolicy().hasHeightForWidth());
        framePlot->setSizePolicy(sizePolicy4);
        framePlot->setStyleSheet(QStringLiteral(""));
        framePlot->setFrameShape(QFrame::StyledPanel);
        framePlot->setFrameShadow(QFrame::Raised);
        groupBox_2->raise();

        horizontalLayout_5->addWidget(framePlot);


        verticalLayout_5->addLayout(horizontalLayout_5);

        cleanButton = new QPushButton(centralWidget);
        cleanButton->setObjectName(QStringLiteral("cleanButton"));
        cleanButton->setEnabled(false);
        cleanButton->setMaximumSize(QSize(150, 16777215));
        cleanButton->setAutoFillBackground(false);
        cleanButton->setStyleSheet(QLatin1String("background-color:rgb(214, 214, 214);\n"
"color:rgb(0, 80, 117);\n"
"font: 87 8pt \"Segoe UI Black\";"));
        cleanButton->setIconSize(QSize(45, 45));
        cleanButton->setCheckable(true);

        verticalLayout_5->addWidget(cleanButton);

        computeButton = new QPushButton(centralWidget);
        computeButton->setObjectName(QStringLiteral("computeButton"));
        computeButton->setEnabled(false);
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(computeButton->sizePolicy().hasHeightForWidth());
        computeButton->setSizePolicy(sizePolicy5);
        computeButton->setMaximumSize(QSize(150, 16777215));
        computeButton->setAutoFillBackground(false);
        computeButton->setStyleSheet(QLatin1String("font: 87 8pt \"Segoe UI Black\";\n"
"background-color:rgb(214, 214, 214);\n"
"color:rgb(0, 80, 117);\n"
""));
        computeButton->setFlat(false);

        verticalLayout_5->addWidget(computeButton);


        verticalLayout_3->addLayout(verticalLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 692, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Approssimazione ai minimi quadrati", 0));
        label->setText(QApplication::translate("MainWindow", "Approssimazione ai minimi quadrati", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Equazione", 0));
        equationInsertLabel->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Input", 0));
        degreeLabel->setText(QApplication::translate("MainWindow", "Grado:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Inserisci X: ", 0));
        label_3->setText(QApplication::translate("MainWindow", "Inserisci Y: ", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Inserisci punto", 0));
        cleanButton->setText(QApplication::translate("MainWindow", "Cancella tutto", 0));
        computeButton->setText(QApplication::translate("MainWindow", "Calcola approssimazione", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
