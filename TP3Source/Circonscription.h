#ifndef CIRCONSCRIPTION_H
#define CIRCONSCRIPTION_H

#include <string>
#include <vector>
#include <memory>
#include "Candidat.h"
#include "Electeur.h"
#include "PersonneException.h"

namespace elections {

/**
 * \class Circonscription
 * \brief Représente une circonscription électorale.
 * 
 * Cette classe permet de gérer les électeurs et le député sortant d'une circonscription électorale.
 */
class Circonscription {
public:
    /**
     * \brief Constructeur de la classe Circonscription.
     * 
     * \param nom Le nom de la circonscription.
     * \param deputeSortant Le député sortant, de type Candidat.
     * \pre Le nom de la circonscription ne doit pas être vide.
     * \post Le nom et le député sortant sont correctement initialisés.
     */
    Circonscription(const std::string& nom, const Candidat& deputeSortant);

    /**
     * \brief Retourne le nom de la circonscription.
     * 
     * \return Une référence constante à la chaîne contenant le nom de la circonscription.
     */
    const std::string& reqNomCirconscription() const;

    /**
     * \brief Retourne le député sortant de la circonscription.
     * 
     * \return Une référence constante au député sortant (objet Candidat).
     */
    const Candidat& reqDeputeSortant() const;

    /**
     * \brief Retourne une chaîne formatée contenant les informations de la circonscription.
     * 
     * \return Une chaîne formatée.
     */
    std::string reqCirconscriptionFormate() const;

    /**
     * \brief Ajoute un électeur à la liste des inscrits.
     * 
     * \param electeur L'objet Electeur à ajouter.
     * \post L'électeur est ajouté à la liste des inscrits.
     */
    void ajouterElecteur(const Electeur& electeur);

    /**
     * \brief Inscrit une personne dans la circonscription.
     * 
     * \param p_nouvelInscrit Une référence à la Personne à inscrire.
     * \exception PersonneDejaPresenteException si la personne est déjà inscrite.
     * \post La personne est ajoutée si elle n'était pas déjà inscrite.
     */
    void inscrire(const Personne& p_nouvelInscrit);

    /**
     * \brief Désinscrit une personne de la circonscription.
     * 
     * \param p_nas Le NAS de la personne à désinscrire.
     * \exception PersonneAbsenteException si la personne n'est pas trouvée.
     * \post La personne est retirée de la liste des inscrits.
     */
    void desinscrire(const std::string& p_nas);

    /**
     * \brief Crée une copie dynamique de l'objet Circonscription.
     * 
     * \return Un pointeur unique vers une copie de l'objet.
     */
    std::unique_ptr<Circonscription> clone() const;

private:
    std::string m_nomCirconscription; ///< Nom de la circonscription.
    Candidat m_deputeSortant;         ///< Député sortant de la circonscription.
    std::vector<std::unique_ptr<Personne>> m_vInscrits; ///< Liste des personnes inscrites.

    /**
     * \brief Vérifie si une personne est déjà inscrite.
     * 
     * \param p_nas Le NAS de la personne à vérifier.
     * \return true si la personne est déjà inscrite, sinon false.
     */
    bool personneEstDejaPresente(const std::string& p_nas) const;

    /**
     * \brief Vérifie les invariants de la classe.
     * 
     * \exception ContratException si un invariant est violé.
     */
    void verifieInvariant() const;
};

} // namespace elections

#endif


