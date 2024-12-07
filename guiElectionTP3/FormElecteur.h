#ifndef FORMELECTEUR_H
#define FORMELECTEUR_H

#include "ui_FormElecteur.h"
#include "Circonscription.h"
#include <QDialog>

class FormElecteur : public QDialog
{
    Q_OBJECT

public:
    explicit FormElecteur(elections::Circonscription& circonscription, QWidget* parent = nullptr);
    ~FormElecteur();

private slots:
    void slotButtonOk();
    void slotButtonCancel();

private:
    Ui::FormElecteur* widget;
    elections::Circonscription& m_circonscription;
};

#endif // FORMELECTEUR_H
