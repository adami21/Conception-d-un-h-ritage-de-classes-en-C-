#ifndef CANDIDAT_H
#define CANDIDAT_H

#include "Personne.h"
#include <string>
#include <memory>
#include <sstream>

namespace elections {

/**
 * \enum PartisPolitiques
 * \brief Enumération des partis politiques auxquels un candidat peut appartenir.
 *
 * Cette énumération contient les partis politiques principaux dans le système électoral :
 * - BLOC_QUEBECOIS
 * - CONSERVATEUR
 * - INDEPENDANT
 * - LIBERAL
 * - NOUVEAU_PARTI_DEMOCRATIQUE
 */
enum PartisPolitiques {
    BLOC_QUEBECOIS, ///< Bloc Québécois
    CONSERVATEUR, ///< Parti Conservateur
    INDEPENDANT, ///< Indépendant
    LIBERAL, ///< Parti Libéral
    NOUVEAU_PARTI_DEMOCRATIQUE ///< Nouveau Parti Démocratique
};

/**
 * \class Candidat
 * \brief Représente un candidat à une élection.
 * 
 * La classe Candidat hérite de la classe Personne et ajoute des informations spécifiques à un candidat,
 * comme le parti politique auquel il appartient.
 * 
 * Elle permet de récupérer des informations sur un candidat, de cloner l'objet, et de formater
 * l'affichage des données relatives au candidat.
 */
class Candidat : public Personne {
public:
    /**
     * \brief Constructeur de la classe Candidat.
     * 
     * Initialise une instance de la classe Candidat en héritant des informations de la classe Personne
     * et en ajoutant le parti politique auquel le candidat appartient.
     * 
     * \param nas Le NAS du candidat.
     * \param prenom Le prénom du candidat.
     * \param nom Le nom du candidat.
     * \param adresse L'adresse du candidat.
     * \param dateNaissance La date de naissance du candidat.
     * \param parti Le parti politique du candidat.
     */
    Candidat(const std::string& nas, const std::string& prenom, const std::string& nom,
             const std::string& adresse, const util::Date& dateNaissance, PartisPolitiques parti);

    /**
     * \brief Retourne le parti politique du candidat.
     * 
     * \return Le parti politique auquel appartient le candidat, de type PartisPolitiques.
     */
    PartisPolitiques reqPartiPolitique() const;

    /**
     * \brief Crée une copie dynamique de l'objet Candidat.
     * 
     * Cette méthode permet de créer une nouvelle instance de la classe Candidat avec les mêmes valeurs
     * que l'objet actuel.
     * 
     * \return Un pointeur unique vers une copie de l'objet Candidat.
     */
    virtual std::unique_ptr<Personne> clone() const override;

    /**
     * \brief Retourne une chaîne de caractères formatée représentant les informations du candidat.
     * 
     * Cette méthode génère une chaîne de caractères contenant les informations du candidat,
     * y compris son nom, prénom, NAS, adresse, date de naissance et son parti politique.
     * 
     * \return Une chaîne de caractères formatée représentant les informations du candidat.
     */
    std::string reqPersonneFormate() const;

private:
    /**
     * \brief Vérifie les invariants de l'objet Candidat.
     * 
     * Cette méthode valide que les informations relatives au candidat, comme son parti politique,
     * respectent les règles internes de l'application.
     */
    void verifieInvariant() const;

    PartisPolitiques m_partiPolitique; ///< Le parti politique auquel appartient le candidat.
};

} // namespace elections

#endif
