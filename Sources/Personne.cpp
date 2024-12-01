/**
 * \file Personne.cpp
 * \brief Implémentation des méthodes de la classe Personne.
 * \author Votre Nom
 * \date 2024
 */

#include "Personne.h"
#include "ContratException.h"
#include <sstream>
#include <iomanip> 
#include "Date.h"

namespace elections {

/**
 * \brief Constructeur de la classe Personne.
 * 
 * Initialise une instance de la classe Personne avec les informations suivantes :
 * - NAS
 * - Prénom
 * - Nom
 * - Adresse
 * - Date de naissance
 * 
 * Effectue des vérifications pour garantir que les informations sont valides.
 * 
 * \param p_nas Le NAS de la personne.
 * \param p_prenom Le prénom de la personne.
 * \param p_nom Le nom de la personne.
 * \param p_adresse L'adresse de la personne.
 * \param p_dateNaissance La date de naissance de la personne.
 */
Personne::Personne(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
                   const std::string& p_adresse, const util::Date& p_dateNaissance)
    : m_nas(p_nas), m_prenom(p_prenom), m_nom(p_nom), m_adresse(p_adresse), m_dateNaissance(p_dateNaissance)
{
    PRECONDITION(!p_nas.empty()); ///< Vérifie que le NAS n'est pas vide.
    PRECONDITION(!p_prenom.empty()); ///< Vérifie que le prénom n'est pas vide.
    PRECONDITION(!p_nom.empty()); ///< Vérifie que le nom n'est pas vide.
    PRECONDITION(!p_adresse.empty()); ///< Vérifie que l'adresse n'est pas vide.
    PRECONDITION(util::Date::validerDate(p_dateNaissance.reqJour(), p_dateNaissance.reqMois(), p_dateNaissance.reqAnnee())); ///< Vérifie que la date de naissance est valide.

    verifieInvariant(); ///< Vérifie les invariants de la classe.
    
    // Postconditions
    POSTCONDITION(m_nas == p_nas); ///< Vérifie que le NAS a bien été affecté.
    POSTCONDITION(m_prenom == p_prenom); ///< Vérifie que le prénom a bien été affecté.
    POSTCONDITION(m_nom == p_nom); ///< Vérifie que le nom a bien été affecté.
    POSTCONDITION(m_adresse == p_adresse); ///< Vérifie que l'adresse a bien été affectée.
    POSTCONDITION(m_dateNaissance == p_dateNaissance); ///< Vérifie que la date de naissance a bien été affectée.
}

/**
 * \brief Retourne le NAS de la personne.
 * 
 * \return Le NAS de la personne.
 */
std::string Personne::reqNas() const {
    return m_nas;
}

/**
 * \brief Retourne le prénom de la personne.
 * 
 * \return Le prénom de la personne.
 */
std::string Personne::reqPrenom() const {
    return m_prenom;
}

/**
 * \brief Retourne le nom de la personne.
 * 
 * \return Le nom de la personne.
 */
std::string Personne::reqNom() const {
    return m_nom;
}

/**
 * \brief Retourne l'adresse de la personne.
 * 
 * \return L'adresse de la personne.
 */
std::string Personne::reqAdresse() const {
    return m_adresse;
}

/**
 * \brief Retourne la date de naissance de la personne.
 * 
 * \return La date de naissance de la personne.
 */
util::Date Personne::reqDateNaissance() const {
    return m_dateNaissance;
}

/**
 * \brief Attribue une nouvelle adresse à la personne.
 * 
 * \param nouvelleAdresse La nouvelle adresse de la personne.
 */
void Personne::asgAdresse(const std::string& nouvelleAdresse) {
    PRECONDITION(!nouvelleAdresse.empty()); ///< Vérifie que la nouvelle adresse n'est pas vide.
    
    m_adresse = nouvelleAdresse; ///< Attribue la nouvelle adresse à la personne.
    verifieInvariant(); ///< Vérifie les invariants après modification.
    
    // Postcondition
    POSTCONDITION(m_adresse == nouvelleAdresse); ///< Vérifie que l'adresse a bien été modifiée.
}

/**
 * \brief Formate une date en chaîne de caractères.
 * 
 * Cette méthode utilise la méthode `reqDateFormatee` de la classe `Date` pour récupérer la date formatée.
 * 
 * \param date La date à formater.
 * \return Une chaîne de caractères représentant la date formatée.
 */
std::string Personne::formatDate(const util::Date& date) const {
    return date.reqDateFormatee(); ///< Utilise la méthode publique pour récupérer la date formatée.
}

/**
 * \brief Retourne une chaîne de caractères formatée représentant les informations de la personne.
 * 
 * La méthode génère une chaîne de caractères contenant les informations de la personne,
 * formatées avec des labels alignés.
 * 
 * \return Une chaîne de caractères représentant les informations de la personne.
 */
std::string Personne::reqPersonneFormate() const {
    std::ostringstream os; ///< Flux de sortie pour construire la chaîne de caractères formatée.
    const int labelWidth = 20; ///< Largeur fixe pour les labels (ajustez si nécessaire).

    os << std::left; ///< Aligne le texte des labels à gauche.
    os << std::setw(labelWidth) << "NAS" << ": " << m_nas << "\n"
       << std::setw(labelWidth) << "Prenom" << ": " << m_prenom << "\n"
       << std::setw(labelWidth) << "Nom" << ": " << m_nom << "\n"
       << std::setw(labelWidth) << "Date de naissance" << ": " << formatDate(m_dateNaissance) << "\n"
       << std::setw(labelWidth) << "Adresse" << ": " << m_adresse << "\n";

    return os.str(); ///< Retourne la chaîne formatée.
}

/**
 * \brief Crée une copie dynamique de l'objet Personne.
 * 
 * Cette méthode permet de créer une nouvelle instance de la classe Personne avec les mêmes valeurs.
 * 
 * \return Un pointeur unique vers une copie de l'objet Personne.
 */
std::unique_ptr<Personne> Personne::clone() const {
    return std::make_unique<Personne>(*this); ///< Crée une copie de l'objet avec les mêmes valeurs.
}

/**
 * \brief Vérifie les invariants de l'objet Personne.
 * 
 * Cette méthode est utilisée pour valider l'intégrité des données d'un objet Personne. Elle est appelée
 * à la création de l'objet et après chaque modification des informations personnelles.
 */
void Personne::verifieInvariant() const {
    INVARIANT(!m_nas.empty()); ///< Vérifie que le NAS n'est pas vide.
    INVARIANT(!m_prenom.empty()); ///< Vérifie que le prénom n'est pas vide.
    INVARIANT(!m_nom.empty()); ///< Vérifie que le nom n'est pas vide.
    INVARIANT(!m_adresse.empty()); ///< Vérifie que l'adresse n'est pas vide.
    INVARIANT(util::Date::validerDate(m_dateNaissance.reqJour(), m_dateNaissance.reqMois(), m_dateNaissance.reqAnnee())); ///< Vérifie que la date de naissance est valide.
}

} // namespace elections
