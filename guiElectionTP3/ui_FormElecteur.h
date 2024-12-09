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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_FormElecteur
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FormElecteur)
    {
        if (FormElecteur->objectName().isEmpty())
            FormElecteur->setObjectName(QString::fromUtf8("FormElecteur"));
        FormElecteur->resize(400, 300);
        buttonBox = new QDialogButtonBox(FormElecteur);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(FormElecteur);
        QObject::connect(buttonBox, SIGNAL(accepted()), FormElecteur, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FormElecteur, SLOT(reject()));

        QMetaObject::connectSlotsByName(FormElecteur);
    } // setupUi

    void retranslateUi(QDialog *FormElecteur)
    {
        FormElecteur->setWindowTitle(QCoreApplication::translate("FormElecteur", "FormElecteur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormElecteur: public Ui_FormElecteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMELECTEUR_H
