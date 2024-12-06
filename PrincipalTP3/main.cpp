/**
 * @file main.cpp
 * @brief Programme principal pour l'inscription des candidats, des électeurs, et la gestion des circonscriptions.
 * 
 * Ce programme permet d'enregistrer un candidat, un électeur et de les associer à une circonscription. 
 * Il présente aussi un système simple de validation de l'entrée et de création d'objets pour la gestion des élections.
 * 
 * @author VotreNom
 * @date 2024-11-28
 */

#include <iostream>
#include <string>
#include "Circonscription.h"
#include "Candidat.h"
#include "Electeur.h"
#include "Date.h"

using namespace std;
using namespace elections;

/**
 * @namespace elections
 * 
 * Namespace contenant les classes et structures relatives aux élections, telles que les partis politiques, les candidats, les électeurs et les circonscriptions.
 */

/**
 * @brief Fonction principale qui gère l'inscription d'un candidat, d'un électeur et la création d'une circonscription.
 * 
 * Cette fonction guide l'utilisateur à travers les étapes d'enregistrement des informations nécessaires pour l'inscription d'un candidat et d'un électeur.
 * Elle associe ensuite un électeur à une circonscription et affiche les informations formatées de cette circonscription.
 * 
 * @return 0 en cas de succès, 1 en cas d'erreur.
 */
int main() {
    cout << "----------------------------------------------" << endl;
    cout << "Bienvenue à l'outil de gestion des listes électorales" << endl;
    cout << "----------------------------------------------" << endl;

    // Inscription d'un candidat
    cout << "Inscription d'un candidat" << endl;

    /**
     * @brief Choix du parti politique pour le candidat.
     * 
     * L'utilisateur choisit un parti politique pour le candidat. 
     * La valeur est convertie en un type d'énumération `PartisPolitiques`.
     */
    cout << "Choisissez un parti : " << endl;
    cout << "0:BLOC_QUEBECOIS, 1:CONSERVATEUR, 2:INDEPENDANT, 3:LIBERAL, 4:NOUVEAU_PARTI_DEMOCRATIQUE" << endl;
    int partiPolitiqueInt;
    cin >> partiPolitiqueInt;

    // Vérifier la validité de l'entrée et convertir en type PartisPolitiques
    if (partiPolitiqueInt < 0 || partiPolitiqueInt > 4) {
        cerr << "Erreur : choix de parti invalide !" << endl;
        return 1;
    }
    PartisPolitiques partiPolitique = static_cast<PartisPolitiques>(partiPolitiqueInt);

    // Saisie de la date de naissance
    int jour, mois, annee;
    cout << "Veuillez saisir sa date de naissance :" << endl;
    cout << "Le jour [1..31]: ";
    cin >> jour;
    cout << "Le mois [1..12]: ";
    cin >> mois;
    cout << "L'année [1970..2037]: ";
    cin >> annee;

    util::Date dateCandidat(jour, mois, annee);

    // Saisie des autres informations
    cout << "Veuillez saisir son adresse : ";
    string adresseCandidat;
    cin.ignore(); // Ignorer le caractère de nouvelle ligne
    getline(cin, adresseCandidat);

    cout << "Entrez le nom : ";
    string nomCandidat;
    getline(cin, nomCandidat);

    cout << "Entrez le prénom : ";
    string prenomCandidat;
    getline(cin, prenomCandidat);

    cout << "Entrez le numéro d'assurance sociale : ";
    string nasCandidat;
    cin >> nasCandidat;

    // Création du candidat
    Candidat candidat(nasCandidat, prenomCandidat, nomCandidat, adresseCandidat, dateCandidat, partiPolitique);

    // Inscription d'un électeur
    cout << "\nInscription d'un électeur" << endl;

    /**
     * @brief Saisie des informations pour l'inscription de l'électeur.
     * 
     * L'utilisateur saisit les informations nécessaires pour inscrire un électeur, telles que la date de naissance, le nom, le prénom et le NAS.
     */
    cout << "Veuillez saisir sa date de naissance :" << endl;
    cout << "Le jour [1..31]: ";
    cin >> jour;
    cout << "Le mois [1..12]: ";
    cin >> mois;
    cout << "L'année [1970..2037]: ";
    cin >> annee;

    util::Date dateElecteur(jour, mois, annee);

    cout << "Veuillez saisir son adresse : ";
    string adresseElecteur;
    cin.ignore();
    getline(cin, adresseElecteur);

    cout << "Entrez le nom : ";
    string nomElecteur;
    getline(cin, nomElecteur);

    cout << "Entrez le prénom : ";
    string prenomElecteur;
    getline(cin, prenomElecteur);

    cout << "Entrez le numéro d'assurance sociale : ";
    string nasElecteur;
    cin >> nasElecteur;

    // Création de l'électeur
    Electeur electeur(nasElecteur, prenomElecteur, nomElecteur, adresseElecteur, dateElecteur);

    // Création de la circonscription
    Circonscription circonscription("Circonscription n°1", candidat);

    // Ajout de l'électeur dans la circonscription
    circonscription.ajouterElecteur(electeur); // Utilisation correcte de la méthode ajouterElecteur

    // Affichage des informations de la circonscription
    cout << "\n" << circonscription.reqCirconscriptionFormate() << endl;

    cout << "Fin du programme" << endl;

    return 0;
}
