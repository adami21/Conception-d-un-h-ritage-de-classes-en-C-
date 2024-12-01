#ifndef ELECTEUR_H
#define ELECTEUR_H

#include "Personne.h"
#include <string>
#include <memory>
#include <sstream>

namespace elections {

/**
 * \class Electeur
 * \brief Représente un électeur, qui est une personne ayant la possibilité de voter.
 * 
 * La classe `Electeur` hérite de la classe `Personne` et représente une personne enregistrée
 * dans le système d'élections qui possède un droit de vote. Elle permet d'obtenir des informations
 * sur l'électeur, comme son nom, prénom, adresse, date de naissance, ainsi que de formater ces
 * informations sous une forme lisible.
 */
class Electeur : public Personne {
public:
    /**
     * \brief Constructeur de la classe Electeur.
     * 
     * Ce constructeur initialise un objet `Electeur` en utilisant les informations personnelles
     * d'une personne (NAS, prénom, nom, adresse, date de naissance).
     * 
     * \param nas Le NAS de l'électeur.
     * \param prenom Le prénom de l'électeur.
     * \param nom Le nom de l'électeur.
     * \param adresse L'adresse de l'électeur.
     * \param dateNaissance La date de naissance de l'électeur.
     */
    Electeur(const std::string& nas, const std::string& prenom, const std::string& nom,
             const std::string& adresse, const util::Date& dateNaissance);

    /**
     * \brief Crée une copie dynamique de l'électeur.
     * 
     * Cette méthode permet de créer une copie de l'objet `Electeur` actuel. La copie est
     * effectuée en allouant de la mémoire pour un nouvel objet, et le contenu de l'électeur
     * est dupliqué dans cette nouvelle instance.
     * 
     * \return Un pointeur unique vers une nouvelle instance de l'électeur.
     */
    virtual std::unique_ptr<Personne> clone() const override;

    /**
     * \brief Retourne une chaîne de caractères formatée représentant les informations de l'électeur.
     * 
     * Cette méthode génère une chaîne formatée contenant les informations détaillées de l'électeur,
     * y compris son nom, prénom, NAS, adresse et date de naissance. Le format d'affichage est conçu
     * pour être lisible par l'utilisateur.
     * 
     * \return Une chaîne de caractères formatée représentant les informations de l'électeur.
     */
    std::string reqPersonneFormate() const;
};

} // namespace elections

#endif


