/********************************************************************************
** Form generated from reading UI file 'FormPrincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPRINCIPAL_H
#define UI_FORMPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPrincipal
{
public:
    QAction *actionSupprimer;
    QAction *actionQuitter;
    QAction *actionElecteur;
    QAction *actionElecteur_2;
    QAction *actionCandidat;
    QWidget *centralwidget;
    QTextEdit *textEditPrincipal;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FormPrincipal)
    {
        if (FormPrincipal->objectName().isEmpty())
            FormPrincipal->setObjectName(QString::fromUtf8("FormPrincipal"));
        FormPrincipal->resize(800, 600);
        actionSupprimer = new QAction(FormPrincipal);
        actionSupprimer->setObjectName(QString::fromUtf8("actionSupprimer"));
        actionQuitter = new QAction(FormPrincipal);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionElecteur = new QAction(FormPrincipal);
        actionElecteur->setObjectName(QString::fromUtf8("actionElecteur"));
        actionElecteur_2 = new QAction(FormPrincipal);
        actionElecteur_2->setObjectName(QString::fromUtf8("actionElecteur_2"));
        actionCandidat = new QAction(FormPrincipal);
        actionCandidat->setObjectName(QString::fromUtf8("actionCandidat"));
        centralwidget = new QWidget(FormPrincipal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEditPrincipal = new QTextEdit(centralwidget);
        textEditPrincipal->setObjectName(QString::fromUtf8("textEditPrincipal"));
        textEditPrincipal->setGeometry(QRect(10, 10, 471, 381));
        textEditPrincipal->setStyleSheet(QString::fromUtf8("font: 25 italic 11pt \"Ubuntu\";"));
        FormPrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FormPrincipal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter = new QMenu(menuMenu);
        menuAjouter->setObjectName(QString::fromUtf8("menuAjouter"));
        FormPrincipal->setMenuBar(menubar);
        statusbar = new QStatusBar(FormPrincipal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FormPrincipal->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter->menuAction());
        menuMenu->addAction(actionSupprimer);
        menuMenu->addAction(actionQuitter);
        menuAjouter->addAction(actionElecteur_2);
        menuAjouter->addAction(actionCandidat);

        retranslateUi(FormPrincipal);
        QObject::connect(actionQuitter, SIGNAL(triggered()), FormPrincipal, SLOT(close()));

        QMetaObject::connectSlotsByName(FormPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *FormPrincipal)
    {
        FormPrincipal->setWindowTitle(QCoreApplication::translate("FormPrincipal", "FormPrincipal", nullptr));
        actionSupprimer->setText(QCoreApplication::translate("FormPrincipal", "Supprimer", nullptr));
        actionQuitter->setText(QCoreApplication::translate("FormPrincipal", "Quitter", nullptr));
        actionElecteur->setText(QCoreApplication::translate("FormPrincipal", "Electeur", nullptr));
        actionElecteur_2->setText(QCoreApplication::translate("FormPrincipal", "Electeur", nullptr));
        actionCandidat->setText(QCoreApplication::translate("FormPrincipal", "Candidat", nullptr));
        textEditPrincipal->setHtml(QCoreApplication::translate("FormPrincipal", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:24; font-style:italic;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">aaa</p></body></html>", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("FormPrincipal", "Menu", nullptr));
        menuAjouter->setTitle(QCoreApplication::translate("FormPrincipal", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPrincipal: public Ui_FormPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPRINCIPAL_H
