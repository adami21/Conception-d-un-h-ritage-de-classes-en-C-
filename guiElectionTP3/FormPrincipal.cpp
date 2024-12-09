
#include "FormPrincipal.h"
#include "Candidat.h"
#include "Date.h"

FormPrincipal::FormPrincipal (): m_circonscription("Circonscription n°1",
                                                   elections::Candidat ("nasCandidat", "prenomCandidat", "nomCandidat", "adresseCandidat", util::Date(1, 1, 2003), elections::INDEPENDANT))
{
  widget.setupUi (this);
}

FormPrincipal::~FormPrincipal () { }
