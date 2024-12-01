/**
 * \file Personne.h
 * \brief Définition de la classe Personne et ses méthodes.
 * \author Votre Nom
 * \date 2024
 */

#ifndef PERSONNE_H
#define PERSONNE_H

#include "Date.h"
#include <string>
#include <sstream>
#include <memory>

namespace elections {

/**
 * \class Personne
 * \brief Représente une personne avec des informations telles que le NAS, le prénom, le nom, l'adresse et la date de naissance.
 * 
 * Cette classe permet de manipuler les informations d'une personne dans le cadre des élections, 
 * avec des fonctionnalités telles que la gestion des informations personnelles, le formatage des données, 
 * et la validation des invariants.
 */
class Personne {
public:
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
     * \param p_nas Le NAS de la personne.
     * \param p_prenom Le prénom de la personne.
     * \param p_nom Le nom de la personne.
     * \param p_adresse L'adresse de la personne.
     * \param p_dateNaissance La date de naissance de la personne.
     */
    Personne(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
             const std::string& p_adresse, const util::Date& p_dateNaissance);

    /// \brief Destructeur virtuel de la classe Personne.
    virtual ~Personne() = default;

    /**
     * \brief Retourne le NAS de la personne.
     * 
     * \return Le NAS de la personne.
     */
    std::string reqNas() const;

    /**
     * \brief Retourne le prénom de la personne.
     * 
     * \return Le prénom de la personne.
     */
    std::string reqPrenom() const;

    /**
     * \brief Retourne le nom de la personne.
     * 
     * \return Le nom de la personne.
     */
    std::string reqNom() const;

    /**
     * \brief Retourne l'adresse de la personne.
     * 
     * \return L'adresse de la personne.
     */
    std::string reqAdresse() const;

    /**
     * \brief Retourne la date de naissance de la personne.
     * 
     * \return La date de naissance de la personne.
     */
    util::Date reqDateNaissance() const;

    /**
     * \brief Attribue une nouvelle adresse à la personne.
     * 
     * \param nouvelleAdresse La nouvelle adresse de la personne.
     */
    void asgAdresse(const std::string& nouvelleAdresse);

    /**
     * \brief Formate et retourne les informations d'une personne sous forme de chaîne de caractères.
     * 
     * Cette méthode est utilisée pour afficher les informations d'une personne de manière formatée.
     * 
     * \return Une chaîne de caractères représentant les informations formatées de la personne.
     */
    virtual std::string reqPersonneFormate() const;

    /**
     * \brief Crée une copie dynamique de l'objet Personne.
     * 
     * \return Un pointeur unique vers une copie de l'objet Personne.
     */
    virtual std::unique_ptr<Personne> clone() const;

protected:
    /**
     * \brief Vérifie que les invariants de l'objet sont respectés.
     * 
     * Cette méthode est utilisée pour valider l'intégrité des données d'un objet Personne.
     */
    void verifieInvariant() const;

    std::string m_nas;          ///< NAS de la personne.
    std::string m_prenom;       ///< Prénom de la personne.
    std::string m_nom;          ///< Nom de la personne.
    std::string m_adresse;      ///< Adresse de la personne.
    util::Date m_dateNaissance; ///< Date de naissance de la personne.

private:
    /**
     * \brief Formate une date en chaîne de caractères.
     * 
     * Cette méthode permet de récupérer la date formatée sans modifier la classe `Date`.
     * 
     * \param date La date à formater.
     * \return Une chaîne de caractères représentant la date formatée.
     */
    std::string formatDate(const util::Date& date) const;

};

} // namespace elections

#endif // PERSONNE_H

