#include "Circonscription.h"
#include <sstream>
#include <stdexcept>
#include "ContratException.h"

namespace elections {

/**
 * \brief Constructeur de la classe Circonscription.
 * 
 * Ce constructeur initialise une nouvelle circonscription en prenant en entrée le nom de la circonscription et le député
 * sortant associé. Il vérifie également que le nom de la circonscription n'est pas vide. En cas de violation de cette
 * condition, une exception est lancée.
 * 
 * \param p_nomCirconscription Le nom de la circonscription.
 * \param p_deputeSortant Le député sortant de la circonscription, représenté par un objet de type `Candidat`.
 * 
 * \throws std::invalid_argument Si le nom de la circonscription est vide.
 */
Circonscription::Circonscription(const std::string& p_nomCirconscription, const Candidat& p_deputeSortant)
    : m_nomCirconscription(p_nomCirconscription), m_deputeSortant(p_deputeSortant) {
    if (p_nomCirconscription.empty()) {
        throw std::invalid_argument("Le nom de la circonscription ne peut pas être vide.");
    }
    verifieInvariant();
}

/**
 * \brief Retourne le nom de la circonscription.
 * 
 * Cette méthode retourne le nom de la circonscription sous forme de référence constante à une chaîne de caractères.
 * 
 * \return Le nom de la circonscription.
 */
const std::string& Circonscription::reqNomCirconscription() const {
    return m_nomCirconscription;
}

/**
 * \brief Retourne le député sortant de la circonscription.
 * 
 * Cette méthode retourne le député sortant de la circonscription sous forme de référence constante à un objet `Candidat`.
 * 
 * \return Le député sortant de la circonscription.
 */
const Candidat& Circonscription::reqDeputeSortant() const {
    return m_deputeSortant;
}

/**
 * \brief Retourne une chaîne formatée représentant la circonscription.
 * 
 * Cette méthode génère une chaîne de caractères formatée qui inclut des informations sur la circonscription, le député
 * sortant et la liste des électeurs. Elle appelle la méthode `reqPersonneFormate` pour formater les informations sur
 * les électeurs et le député sortant.
 * 
 * \return Une chaîne de caractères représentant la circonscription et ses détails.
 */
std::string Circonscription::reqCirconscriptionFormate() const {
    std::ostringstream os;
    os << "Circonscription : " << m_nomCirconscription << "\n";
    os << "Député sortant :\n" << m_deputeSortant.reqPersonneFormate() << "\n";
    os << "Liste des inscrits :\n";
    for (const auto& electeur : m_electeurs) {
        os << electeur.reqPersonneFormate() << "\n";
    }
    return os.str();
}

/**
 * \brief Ajoute un électeur à la circonscription.
 * 
 * Cette méthode permet d'ajouter un électeur à la liste des électeurs de la circonscription. L'électeur est ajouté à
 * l'aide de la méthode `push_back` du conteneur `std::vector`. Après ajout, la méthode `verifieInvariant` est appelée
 * pour assurer que l'objet reste dans un état valide.
 * 
 * \param electeur L'électeur à ajouter à la circonscription.
 */
void Circonscription::ajouterElecteur(const Electeur& electeur) {
    m_electeurs.push_back(electeur);
    verifieInvariant();
}

/**
 * \brief Crée une copie dynamique de la circonscription.
 * 
 * Cette méthode crée une copie dynamique de l'objet `Circonscription` actuel et retourne un pointeur unique vers cette
 * nouvelle instance. La méthode permet de créer une nouvelle instance qui est une copie exacte de l'original.
 * 
 * \return Un pointeur unique vers une nouvelle instance de `Circonscription`.
 */
std::unique_ptr<Circonscription> Circonscription::clone() const {
    return std::make_unique<Circonscription>(*this);
}

/**
 * \brief Vérifie les invariants de l'objet Circonscription.
 * 
 * Cette méthode vérifie l'invariant de la classe `Circonscription`, c'est-à-dire que le nom de la circonscription ne
 * peut pas être vide. Si cette condition est violée, une exception `ContratException` est lancée.
 * 
 * \throws ContratException Si l'invariant est violé (le nom de la circonscription est vide).
 */
void Circonscription::verifieInvariant() const {
    if (m_nomCirconscription.empty()) {
        throw ContratException(__FILE__, __LINE__, __func__, 
            "Invariant : Le nom de la circonscription ne peut pas être vide.");
    }
}

} // namespace elections





