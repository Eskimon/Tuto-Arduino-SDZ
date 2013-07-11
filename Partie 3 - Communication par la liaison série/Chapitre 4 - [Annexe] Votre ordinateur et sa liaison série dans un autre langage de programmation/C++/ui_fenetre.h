/********************************************************************************
** Form generated from reading UI file 'fenetre.ui'
**
** Created: Sat May 5 00:24:49 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETRE_H
#define UI_FENETRE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fenetre
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *ComboPort;
    QLabel *label_2;
    QComboBox *comboVitesse;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnConnection;
    QFrame *line;
    QLabel *label_3;
    QTextEdit *boxEmission;
    QLabel *label_4;
    QTextEdit *boxReception;

    void setupUi(QWidget *Fenetre)
    {
        if (Fenetre->objectName().isEmpty())
            Fenetre->setObjectName(QString::fromUtf8("Fenetre"));
        Fenetre->resize(580, 356);
        verticalLayout_3 = new QVBoxLayout(Fenetre);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Fenetre);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        ComboPort = new QComboBox(Fenetre);
        ComboPort->setObjectName(QString::fromUtf8("ComboPort"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ComboPort->sizePolicy().hasHeightForWidth());
        ComboPort->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(ComboPort);

        label_2 = new QLabel(Fenetre);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        comboVitesse = new QComboBox(Fenetre);
        comboVitesse->setObjectName(QString::fromUtf8("comboVitesse"));
        sizePolicy1.setHeightForWidth(comboVitesse->sizePolicy().hasHeightForWidth());
        comboVitesse->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(comboVitesse);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnConnection = new QPushButton(Fenetre);
        btnConnection->setObjectName(QString::fromUtf8("btnConnection"));
        sizePolicy1.setHeightForWidth(btnConnection->sizePolicy().hasHeightForWidth());
        btnConnection->setSizePolicy(sizePolicy1);
        btnConnection->setCheckable(true);

        horizontalLayout->addWidget(btnConnection);


        verticalLayout_3->addLayout(horizontalLayout);

        line = new QFrame(Fenetre);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        label_3 = new QLabel(Fenetre);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        boxEmission = new QTextEdit(Fenetre);
        boxEmission->setObjectName(QString::fromUtf8("boxEmission"));

        verticalLayout_3->addWidget(boxEmission);

        label_4 = new QLabel(Fenetre);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        boxReception = new QTextEdit(Fenetre);
        boxReception->setObjectName(QString::fromUtf8("boxReception"));
        boxReception->setReadOnly(true);

        verticalLayout_3->addWidget(boxReception);


        retranslateUi(Fenetre);

        QMetaObject::connectSlotsByName(Fenetre);
    } // setupUi

    void retranslateUi(QWidget *Fenetre)
    {
        Fenetre->setWindowTitle(QApplication::translate("Fenetre", "SdZ terminal voie s\303\251rie", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Fenetre", "Port : ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Fenetre", "Vitesse : ", 0, QApplication::UnicodeUTF8));
        btnConnection->setText(QApplication::translate("Fenetre", "Connecter", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Fenetre", "Emission :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Fenetre", "R\303\251ception :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Fenetre: public Ui_Fenetre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETRE_H
