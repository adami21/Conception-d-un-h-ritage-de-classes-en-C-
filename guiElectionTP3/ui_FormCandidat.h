/********************************************************************************
** Form generated from reading UI file 'FormCandidat.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCANDIDAT_H
#define UI_FORMCANDIDAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_FormCandidat
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FormCandidat)
    {
        if (FormCandidat->objectName().isEmpty())
            FormCandidat->setObjectName(QString::fromUtf8("FormCandidat"));
        FormCandidat->resize(400, 300);
        buttonBox = new QDialogButtonBox(FormCandidat);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(FormCandidat);
        QObject::connect(buttonBox, SIGNAL(accepted()), FormCandidat, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FormCandidat, SLOT(reject()));

        QMetaObject::connectSlotsByName(FormCandidat);
    } // setupUi

    void retranslateUi(QDialog *FormCandidat)
    {
        FormCandidat->setWindowTitle(QCoreApplication::translate("FormCandidat", "FormCandidat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCandidat: public Ui_FormCandidat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCANDIDAT_H
