#include "Electeur.h"
#include <sstream>
#include "ContratException.h"

namespace elections {

/**
 * \class Electeur
 * \brief Implémentation de la classe Electeur.
 * 
 * La classe `Electeur` représente une personne ayant le droit de voter. Elle hérite de la classe `Personne`
 * et permet d'afficher les informations personnelles d'un électeur, telles que le NAS, le prénom, le nom,
 * l'adresse et la date de naissance. Elle fournit aussi un mécanisme pour cloner un électeur.
 */

/**
 * \brief Constructeur de la classe Electeur.
 * 
 * Ce constructeur initialise un objet `Electeur` en utilisant les informations personnelles d'une personne.
 * Il appelle également le constructeur de la classe de base `Personne` pour initialiser les attributs communs.
 * 
 * \param nas Le NAS de l'électeur.
 * \param prenom Le prénom de l'électeur.
 * \param nom Le nom de l'électeur.
 * \param adresse L'adresse de l'électeur.
 * \param dateNaissance La date de naissance de l'électeur.
 */
Electeur::Electeur(const std::string& nas, const std::string& prenom, const std::string& nom,
                   const std::string& adresse, const util::Date& dateNaissance)
    : Personne(nas, prenom, nom, adresse, dateNaissance) {
    INVARIANTS(); 
}

/**
 * \brief Crée une copie dynamique de l'électeur.
 * 
 * Cette méthode permet de créer une copie de l'objet `Electeur` actuel. La copie est effectuée en allouant de la mémoire
 * pour un nouvel objet, et le contenu de l'électeur est dupliqué dans cette nouvelle instance.
 * 
 * \return Un pointeur unique vers une nouvelle instance de l'électeur.
 */
std::unique_ptr<Personne> Electeur::clone() const {
    return std::make_unique<Electeur>(*this);
}

/**
 * \brief Retourne une chaîne de caractères formatée représentant les informations de l'électeur.
 * 
 * Cette méthode génère une chaîne formatée contenant les informations détaillées de l'électeur, y compris son nom, prénom,
 * NAS, adresse et date de naissance. Elle ajoute un préfixe "Electeur" et un séparateur avant d'afficher les informations
 * formatées de la classe de base `Personne`.
 * 
 * \return Une chaîne de caractères formatée représentant les informations de l'électeur.
 */
std::string Electeur::reqPersonneFormate() const {
    std::ostringstream os;
    os << "Electeur" << std::endl;
    os << "---------------------------" << std::endl;
    os << Personne::reqPersonneFormate();
    return os.str();
}

} // namespace elections



