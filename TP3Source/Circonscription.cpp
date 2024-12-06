#include "Circonscription.h"
#include <sstream>
#include <algorithm>
#include "ContratException.h"
#include "PersonneException.h"

namespace elections {

/**
 * \brief Constructeur de la classe Circonscription.
 * 
 * \param p_nomCirconscription Le nom de la circonscription.
 * \param p_deputeSortant Le député sortant, de type Candidat.
 * \exception std::invalid_argument si le nom de la circonscription est vide.
 */
Circonscription::Circonscription(const std::string& p_nomCirconscription, const Candidat& p_deputeSortant)
    : m_nomCirconscription(p_nomCirconscription), m_deputeSortant(p_deputeSortant) {
    if (p_nomCirconscription.empty()) {
        throw std::invalid_argument("Le nom de la circonscription ne peut pas être vide.");
    }
    verifieInvariant();
}


const std::string& Circonscription::reqNomCirconscription() const {
    return m_nomCirconscription;
}

const Candidat& Circonscription::reqDeputeSortant() const {
    return m_deputeSortant;
}

std::string Circonscription::reqCirconscriptionFormate() const {
    std::ostringstream os;
    os << "Circonscription : " << m_nomCirconscription << "\n";
    os << "Député sortant :\n" << m_deputeSortant.reqPersonneFormate() << "\n";
    os << "Liste des inscrits :\n";
    for (const auto& personne : m_vInscrits) {
        os << personne->reqPersonneFormate() << "\n";
    }
    return os.str();
}

void Circonscription::ajouterElecteur(const Electeur& electeur) {
    m_vInscrits.push_back(electeur.clone());
    verifieInvariant();
}

void Circonscription::inscrire(const Personne& p_nouvelInscrit) {
    if (personneEstDejaPresente(p_nouvelInscrit.reqNas())) {
        throw PersonneDejaPresenteException("La personne est déjà inscrite dans la circonscription.");
    }
    m_vInscrits.push_back(p_nouvelInscrit.clone());
    verifieInvariant();
}

void Circonscription::desinscrire(const std::string& p_nas) {
    auto it = std::find_if(m_vInscrits.begin(), m_vInscrits.end(),
        [&p_nas](const std::unique_ptr<Personne>& personne) {
            return personne->reqNas() == p_nas;
        });

    if (it == m_vInscrits.end()) {
        throw PersonneAbsenteException("La personne avec le NAS fourni n'est pas trouvée dans la circonscription.");
    }

    m_vInscrits.erase(it);
    verifieInvariant();
}

bool Circonscription::personneEstDejaPresente(const std::string& p_nas) const {
    for (const auto& personne : m_vInscrits) {
        if (personne->reqNas() == p_nas) {
            return true;
        }
    }
    return false;
}

void Circonscription::verifieInvariant() const {
    INVARIANT(!m_nomCirconscription.empty());
    for (const auto& personne : m_vInscrits) {
        INVARIANT(personne != nullptr);
    }
}

std::unique_ptr<Circonscription> Circonscription::clone() const {
    auto copie = std::make_unique<Circonscription>(m_nomCirconscription, m_deputeSortant);

    for (const auto& personne : m_vInscrits) {
        copie->m_vInscrits.push_back(personne->clone());
    }

    return copie;
}


} // namespace elections

