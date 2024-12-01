/**
 * @file validationFormat.h
 * @brief Ce fichier contient les déclarations des fonctions utilisées pour valider le format d'un numéro d'assurance sociale (NAS) canadien et pour valider un fichier d'électeurs et de candidats.
 *
 * Ce fichier inclut les prototypes des fonctions nécessaires pour valider :
 * - Un numéro d'assurance sociale (NAS) selon un format précis (9 chiffres, l'algorithme de Luhn).
 * - Le format d'un fichier contenant des informations sur des électeurs et des candidats, telles que le NAS, le prénom, le nom, la date de naissance et l'adresse.
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <string>
#include <istream>

/**
 * @brief Valide un numéro d'assurance sociale (NAS).
 *
 * Cette fonction vérifie qu'un NAS est valide selon les critères suivants :
 * - Il contient exactement 9 chiffres après suppression des espaces et des tirets.
 * - Il respecte l'algorithme de Luhn.
 *
 * @param nas Le numéro d'assurance sociale à valider.
 * @return true Si le NAS est valide, sinon false.
 */
bool validerNas(const std::string& nas);

/**
 * @brief Valide le format d'un fichier contenant des informations sur des candidats et des électeurs.
 *
 * Cette fonction lit un fichier et vérifie que chaque ligne respecte les critères de format spécifiés :
 * - La première ligne (nom de la circonscription) ne peut pas être vide.
 * - Les informations des candidats et des électeurs doivent être complètes et respecter le format des dates, des NAS, et des noms.
 *
 * @param p_is Le flux d'entrée du fichier à valider.
 * @return true Si le fichier est valide, sinon false.
 */
bool validerFormatFichier(std::istream& p_is);

#endif /* VALIDATIONFORMAT_H_ */

