/**
 * @file validationFormat.h
 * @brief Ce fichier contient les fonctions de validation de format pour un NAS et pour un fichier de données d'électeurs et de candidats.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <regex>

using namespace std;

/**
 * @brief Fonction qui valide un numéro d'assurance sociale (NAS) canadien.
 *
 * Cette fonction vérifie que le NAS est constitué de 9 chiffres, sans caractères autres que des chiffres,
 * des espaces ou des tirets, et que le numéro respecte l'algorithme de Luhn pour garantir son authenticité.
 *
 * @param p_nas Le numéro d'assurance sociale à valider.
 * @return true Si le NAS est valide, sinon false.
 *
 * @note Le NAS est valide si :
 * - Il contient exactement 9 chiffres après suppression des espaces et tirets.
 * - Il respecte l'algorithme de Luhn (somme des chiffres selon un certain calcul modulo 10).
 */
bool validerNas(const std::string& p_nas)
{
    bool valide = true;  ///< Indicateur de validité du NAS, initialisé à true

    // Vérifier que le NAS a exactement 11 caractères (y compris les espaces et tirets)
    if (p_nas.size() != 11) {
        return false;  ///< Longueur invalide
    }

    std::string nasSansEspaces;  ///< Chaîne pour stocker les chiffres du NAS sans espaces ni tirets
    for (char c : p_nas) {
        if (std::isdigit(c)) {
            nasSansEspaces += c;  ///< Conserve uniquement les chiffres
        } else if (c != ' ' && c != '-') {
            valide = false;  ///< Retourne faux si un caractère non conforme est détecté
            break;  ///< Sortir de la boucle
        }
    }

    // Vérification que le NAS contient exactement 9 chiffres après suppression des espaces
    if (nasSansEspaces.length() != 9) {
        valide = false;  ///< Un NAS valide doit contenir 9 chiffres
    }

    // Algorithme de Luhn pour valider le NAS
    if (valide) {
        int somme = 0;
        bool double_chiffre = false;

        for (int i = nasSansEspaces.length() - 1; i >= 0; --i) {
            int chiffre = nasSansEspaces[i] - '0';  ///< Convertit le caractère en entier
            if (double_chiffre) {
                chiffre *= 2;
                if (chiffre > 9) {
                    chiffre -= 9;  ///< Si la multiplication donne un nombre à deux chiffres, soustraire 9
                }
            }
            somme += chiffre;
            double_chiffre = !double_chiffre;  ///< Alterne le doublement des chiffres
        }

        valide = (somme % 10 == 0);  ///< Le NAS est valide si la somme est un multiple de 10
    }

    return valide;  ///< Retourne la validité du NAS
}

/**
 * @brief Fonction qui valide le format d'un fichier d'électeurs et de candidats.
 *
 * Cette fonction lit un fichier et valide son contenu. Le fichier doit respecter certaines règles de format
 * pour les informations des candidats et des électeurs, telles que :
 * - Le nom de la circonscription (ne peut pas être vide).
 * - Le NAS, prénom, nom, date de naissance et adresse doivent être présents et au bon format.
 * - La date de naissance doit être au format "jj mm aaaa".
 * - Les partis politiques doivent être suivis par des informations de candidats.
 *
 * @param p_is Flux d'entrée du fichier à valider.
 * @return true Si le fichier est valide, sinon false.
 */
bool validerFormatFichier(std::istream & p_is)
{
    std::string ligne;  ///< Variable pour stocker chaque ligne lue
    bool valide = true;  ///< Indicateur de validité du fichier, initialisé à true

    // Lire la première ligne (le nom de la circonscription), qui ne doit pas être vide
    if (std::getline(p_is, ligne)) {
        if (ligne.empty()) {
            return false;  ///< Si la première ligne est vide, le fichier est invalide
        }
    } else {
        return false;  ///< Si la lecture échoue, fichier invalide
    }

    // Expression régulière pour valider les dates (format "jj mm aaaa")
    std::regex date_regex(R"(\d{2} \d{2} \d{4})");

    // Lire les lignes suivantes pour valider les informations des candidats et électeurs
    while (std::getline(p_is, ligne)) {
        if (ligne.empty()) continue;  ///< Ignorer les lignes vides

        // Si la ligne contient un nom de parti politique
        if (ligne == "BLOC_QUEBECOIS" || ligne == "CONSERVATEUR" ||
            ligne == "INDEPENDANT" || ligne == "LIBERAL" ||
            ligne == "NOUVEAU_PARTI_DEMOCRATIQUE") {

            // Lire les lignes suivantes pour valider les informations du candidat
            if (!std::getline(p_is, ligne) || !validerNas(ligne)) {
                return false;  ///< NAS invalide ou ligne manquante
            }

            // Lire et vérifier le prénom
            if (!std::getline(p_is, ligne) || ligne.empty()) {
                return false;  ///< Prénom manquant ou vide
            }

            // Lire et vérifier le nom
            if (!std::getline(p_is, ligne) || ligne.empty()) {
                return false;  ///< Nom manquant ou vide
            }

            // Lire et vérifier la date de naissance (format "jj mm aaaa")
            if (!std::getline(p_is, ligne) || !std::regex_match(ligne, date_regex)) {
                return false;  ///< Date de naissance au mauvais format
            }

            // Lire et vérifier l'adresse
            if (!std::getline(p_is, ligne) || ligne.empty()) {
                return false;  ///< Adresse manquante ou vide
            }

        // Si la ligne contient un NAS, c'est un électeur
        } else if (validerNas(ligne)) {

            // Valider le prénom, le nom, la date de naissance et l'adresse
            if (!std::getline(p_is, ligne) || ligne.empty()) {
                return false;  ///< Prénom manquant ou vide
            }

            if (!std::getline(p_is, ligne) || ligne.empty()) {
                return false;  ///< Nom manquant ou vide
            }

            if (!std::getline(p_is, ligne) || !std::regex_match(ligne, date_regex)) {
                return false;  ///< Date de naissance au mauvais format
            }

            if (!std::getline(p_is, ligne) || ligne.empty()) {
                return false;  ///< Adresse manquante ou vide
            }

        } else {
            return false;  ///< Ligne non reconnue
        }
    }

    return valide;  ///< Si toutes les validations sont passées, le fichier est valide
}



