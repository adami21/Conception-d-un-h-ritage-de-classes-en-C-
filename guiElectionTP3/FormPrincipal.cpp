#include "FormPrincipal.h"
#include "FormElecteur.h"

FormPrincipal::FormPrincipal() : m_circonscription("Circonscription n°1",
                                                   elections::Candidat("nasCandidat", "prenomCandidat", "nomCandidat", "adresseCandidat", util::Date(1, 1, 2003), elections::INDEPENDANT))
{
    widget.setupUi(this);

    // Connecter les actions
    connect(widget.actionInscrireElecteur, &QAction::triggered, this, &FormPrincipal::slotOuvrirElecteur);
    connect(widget.actionInscrireCandidat, &QAction::triggered, this, &FormPrincipal::slotOuvrirCandidat);

    // Initialiser la zone de texte avec les données de la circonscription
    widget.textEditPrincipal->setPlainText(m_circonscription.reqCirconscriptionFormate().c_str());
}

FormPrincipal::~FormPrincipal() {}

void FormPrincipal::slotOuvrirElecteur() {
    FormElecteur formElecteur(m_circonscription, this);
    if (formElecteur.exec() == QDialog::Accepted) {
        // Mettre à jour l'affichage après l'inscription
        widget.textEditPrincipal->setPlainText(m_circonscription.reqCirconscriptionFormate().c_str());
    }
}

void FormPrincipal::slotOuvrirCandidat() {
    // Implémentez cette méthode si nécessaire
}



