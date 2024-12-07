#ifndef FORMPRINCIPAL_H
#define FORMPRINCIPAL_H

#include <QMainWindow>
#include "ui_FormPrincipal.h"
#include "Circonscription.h"

class FormPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    FormPrincipal();
    ~FormPrincipal();

private slots:
    void slotOuvrirElecteur();

private:
    Ui::FormPrincipal widget;
    elections::Circonscription m_circonscription;
};

#endif // FORMPRINCIPAL_H

