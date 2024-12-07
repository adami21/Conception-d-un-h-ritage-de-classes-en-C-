#include "FormElecteur.h"
#include "Electeur.h"
#include <QMessageBox>

FormElecteur::FormElecteur(elections::Circonscription& circonscription, QWidget* parent)
    : QDialog(parent), widget(new Ui::FormElecteur), m_circonscription(circonscription)
{
    widget->setupUi(this);

    connect(widget->buttonOK, &QPushButton::clicked, this, &FormElecteur::slotButtonOk);
    connect(widget->buttonCancel, &QPushButton::clicked, this, &FormElecteur::slotButtonCancel);
}

FormElecteur::~FormElecteur()
{
    delete widget;
}

void FormElecteur::slotButtonOk()
{
    std::string nas = widget->lineEditNAS_2->text().toStdString();
    std::string prenom = widget->lineEditPrenom_2->text().toStdString();
    std::string nom = widget->lineEditNom_2->text().toStdString();
    std::string adresse = widget->lineEditAdresse_2->text().toStdString();
    QDate dateNaissance = widget->dateEditNaissance->date();

    try {
        elections::Electeur nouvelElecteur(nas, prenom, nom, adresse,
                                           util::Date(dateNaissance.day(),
                                                      dateNaissance.month(),
                                                      dateNaissance.year()));

        m_circonscription.inscrire(nouvelElecteur);

        QMessageBox::information(this, "Succès", "L'électeur a été ajouté avec succès.");
        accept();
    } catch (const elections::PersonneDejaPresenteException& e) {
        QMessageBox::warning(this, "Erreur", QString::fromStdString(e.what()));
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Erreur critique", QString::fromStdString(e.what()));
    }
}

void FormElecteur::slotButtonCancel()
{
    reject();
}








