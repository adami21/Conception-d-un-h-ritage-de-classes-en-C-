
#include "FormPrincipal.h"
#include "FormElecteur.h"
#include "Candidat.h"
#include "Electeur.h"
#include "Date.h"

FormPrincipal::FormPrincipal (): m_circonscription("Circonscription n°1",
                                                   elections::Candidat ("nasCandidat", "prenomCandidat", "nomCandidat", "adresseCandidat", util::Date(1, 1, 2003), elections::INDEPENDANT))
{
  widget.setupUi (this);
  //Les quatres lignes suivantes soivent partir apres
  elections::Candidat candidat("nasCandidat", "prenomCandidat", "nomCandidat", "adresseCandidat", util::Date(1, 1, 2003), elections::INDEPENDANT);
  elections::Electeur electeur("nasElecteur", "prenomElecteur", "nomElecteur", "adresseElecteur", util::Date(1, 1, 2003));
  
  m_circonscription.inscrire(candidat);
  m_circonscription.inscrire(electeur);
  
  widget.textEditPrincipal->setPlainText (m_circonscription.reqCirconscriptionFormate().c_str());
}

FormPrincipal::~FormPrincipal () { }

void FormPrincipal::slotOuvrirElecteur(){
  
  FormElecteur formElecteur;
  formElecteur.exec();
}

