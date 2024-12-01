#ifndef CIRCONSCRIPTION_H
#define CIRCONSCRIPTION_H

#include <string>
#include <vector>
#include <memory>
#include "Candidat.h"
#include "Electeur.h"

namespace elections {

/**
 * \class Circonscription
 * \brief Représente une circonscription électorale.
 * 
 * La classe `Circonscription` permet de gérer une circonscription électorale, y compris le nom de la circonscription,
 * le député sortant, ainsi que la liste des électeurs associés à cette circonscription. Elle fournit des méthodes pour
 * ajouter des électeurs, obtenir des informations sur la circonscription, et cloner l'objet.
 */
class Circonscription {
public:
    /**
     * \brief Constructeur de la classe Circonscription.
     * 
     * Ce constructeur initialise une circonscription en fournissant son nom et le député sortant de la circonscription.
     * Il crée également une liste vide d'électeurs.
     * 
     * \param nom Le nom de la circonscription.
     * \param deputeSortant Le député sortant de la circonscription, représenté par un objet de type `Candidat`.
     */
    Circonscription(const std::string& nom, const Candidat& deputeSortant);

    /**
     * \brief Retourne le nom de la circonscription.
     * 
     * Cette méthode retourne le nom de la circonscription sous forme de référence constante à une chaîne de caractères.
     * 
     * \return Le nom de la circonscription.
     */
    const std::string& reqNomCirconscription() const;

    /**
     * \brief Retourne le député sortant de la circonscription.
     * 
     * Cette méthode retourne le député sortant de la circonscription sous forme de référence constante à un objet `Candidat`.
     * 
     * \return Le député sortant de la circonscription.
     */
    const Candidat& reqDeputeSortant() const;

    /**
     * \brief Retourne une chaîne formatée représentant la circonscription.
     * 
     * Cette méthode génère une chaîne de caractères formatée contenant des informations sur la circonscription, y compris
     * son nom, les détails du député sortant, ainsi que les informations sur les électeurs. 
     * 
     * \return Une chaîne de caractères représentant la circonscription de manière lisible.
     */
    std::string reqCirconscriptionFormate() const;

    /**
     * \brief Ajoute un électeur à la circonscription.
     * 
     * Cette méthode permet d'ajouter un électeur à la liste des électeurs de la circonscription. Un objet `Electeur`
     * est ajouté à la collection des électeurs.
     * 
     * \param electeur L'électeur à ajouter à la circonscription.
     */
    void ajouterElecteur(const Electeur& electeur);

    /**
     * \brief Crée une copie dynamique de la circonscription.
     * 
     * Cette méthode crée une copie de l'objet `Circonscription` actuel et la retourne sous forme d'un pointeur unique.
     * 
     * \return Un pointeur unique vers une nouvelle instance de la circonscription.
     */
    std::unique_ptr<Circonscription> clone() const;

private:
    std::string m_nomCirconscription;  ///< Nom de la circonscription.
    Candidat m_deputeSortant;          ///< Député sortant de la circonscription.
    std::vector<Electeur> m_electeurs; ///< Liste des électeurs de la circonscription.

    /**
     * \brief Vérifie les invariants de l'objet Circonscription.
     * 
     * Cette méthode vérifie les conditions invariantes de la classe `Circonscription`. Elle est utilisée pour assurer
     * que l'objet reste dans un état valide tout au long de son cycle de vie.
     */
    void verifieInvariant() const;
};

} // namespace elections

#endif 

