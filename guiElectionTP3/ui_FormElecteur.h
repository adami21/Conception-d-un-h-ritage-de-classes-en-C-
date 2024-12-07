/********************************************************************************
** Form generated from reading UI file 'FormElecteur.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMELECTEUR_H
#define UI_FORMELECTEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_FormElecteur
{
public:
    QLabel *lineEditNAS;
    QLabel *lineEditNom;
    QLabel *lineEditAdresse;
    QLabel *lineEditPrenom;
    QPushButton *buttonOK;
    QPushButton *buttonCancel;
    QDateEdit *dateEditNaissance;
    QTextEdit *textEdit;
    QLineEdit *lineEditNAS_2;
    QLineEdit *lineEditPrenom_2;
    QLineEdit *lineEditNom_2;
    QLineEdit *lineEditAdresse_2;

    void setupUi(QDialog *FormElecteur)
    {
        if (FormElecteur->objectName().isEmpty())
            FormElecteur->setObjectName(QString::fromUtf8("FormElecteur"));
        FormElecteur->resize(400, 300);
        lineEditNAS = new QLabel(FormElecteur);
        lineEditNAS->setObjectName(QString::fromUtf8("lineEditNAS"));
        lineEditNAS->setGeometry(QRect(90, 50, 58, 16));
        lineEditNom = new QLabel(FormElecteur);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));
        lineEditNom->setGeometry(QRect(90, 90, 58, 16));
        lineEditAdresse = new QLabel(FormElecteur);
        lineEditAdresse->setObjectName(QString::fromUtf8("lineEditAdresse"));
        lineEditAdresse->setGeometry(QRect(90, 110, 58, 16));
        lineEditPrenom = new QLabel(FormElecteur);
        lineEditPrenom->setObjectName(QString::fromUtf8("lineEditPrenom"));
        lineEditPrenom->setGeometry(QRect(90, 70, 58, 16));
        buttonOK = new QPushButton(FormElecteur);
        buttonOK->setObjectName(QString::fromUtf8("buttonOK"));
        buttonOK->setGeometry(QRect(190, 240, 90, 28));
        buttonCancel = new QPushButton(FormElecteur);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setGeometry(QRect(290, 240, 90, 28));
        dateEditNaissance = new QDateEdit(FormElecteur);
        dateEditNaissance->setObjectName(QString::fromUtf8("dateEditNaissance"));
        dateEditNaissance->setGeometry(QRect(150, 130, 110, 26));
        textEdit = new QTextEdit(FormElecteur);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(90, 130, 51, 31));
        lineEditNAS_2 = new QLineEdit(FormElecteur);
        lineEditNAS_2->setObjectName(QString::fromUtf8("lineEditNAS_2"));
        lineEditNAS_2->setGeometry(QRect(150, 50, 111, 16));
        lineEditPrenom_2 = new QLineEdit(FormElecteur);
        lineEditPrenom_2->setObjectName(QString::fromUtf8("lineEditPrenom_2"));
        lineEditPrenom_2->setGeometry(QRect(150, 70, 111, 16));
        lineEditNom_2 = new QLineEdit(FormElecteur);
        lineEditNom_2->setObjectName(QString::fromUtf8("lineEditNom_2"));
        lineEditNom_2->setGeometry(QRect(150, 90, 113, 16));
        lineEditAdresse_2 = new QLineEdit(FormElecteur);
        lineEditAdresse_2->setObjectName(QString::fromUtf8("lineEditAdresse_2"));
        lineEditAdresse_2->setGeometry(QRect(150, 110, 113, 16));

        retranslateUi(FormElecteur);
        QObject::connect(buttonOK, SIGNAL(clicked()), FormElecteur, SLOT(slotButtonOk()));
        QObject::connect(buttonCancel, SIGNAL(clicked()), FormElecteur, SLOT(slotBoutonCancel()));

        QMetaObject::connectSlotsByName(FormElecteur);
    } // setupUi

    void retranslateUi(QDialog *FormElecteur)
    {
        FormElecteur->setWindowTitle(QCoreApplication::translate("FormElecteur", "FormElecteur", nullptr));
        lineEditNAS->setText(QCoreApplication::translate("FormElecteur", "NAS :", nullptr));
        lineEditNom->setText(QCoreApplication::translate("FormElecteur", "Nom :", nullptr));
        lineEditAdresse->setText(QCoreApplication::translate("FormElecteur", "Adresse :", nullptr));
        lineEditPrenom->setText(QCoreApplication::translate("FormElecteur", "Prenom :", nullptr));
        buttonOK->setText(QCoreApplication::translate("FormElecteur", "OK", nullptr));
        buttonCancel->setText(QCoreApplication::translate("FormElecteur", "Annuler", nullptr));
        textEdit->setHtml(QCoreApplication::translate("FormElecteur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Date :</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormElecteur: public Ui_FormElecteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMELECTEUR_H
