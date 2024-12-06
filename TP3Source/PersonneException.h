/**
 * \file PersonneException.h
 * \brief Déclaration des exceptions personnalisées liées aux personnes.
 * \author Votre Nom
 * \date 2024
 */

#ifndef PERSONNEEXCEPTION_H
#define PERSONNEEXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * \class PersonneException
 * \brief Exception de base pour les erreurs liées aux personnes.
 */
class PersonneException : public std::runtime_error {
public:
    /**
     * \brief Constructeur de la classe PersonneException.
     * \param message Message décrivant l'exception.
     */
    explicit PersonneException(const std::string& message)
        : std::runtime_error(message) {}
};

/**
 * \class PersonneDejaPresenteException
 * \brief Exception pour signaler qu'une personne est déjà inscrite.
 */
class PersonneDejaPresenteException : public PersonneException {
public:
    /**
     * \brief Constructeur de la classe PersonneDejaPresenteException.
     * \param message Message décrivant l'exception.
     */
    explicit PersonneDejaPresenteException(const std::string& message)
        : PersonneException(message) {}
};

/**
 * \class PersonneAbsenteException
 * \brief Exception pour signaler qu'une personne est absente lors de la suppression.
 */
class PersonneAbsenteException : public PersonneException {
public:
    /**
     * \brief Constructeur de la classe PersonneAbsenteException.
     * \param message Message décrivant l'exception.
     */
    explicit PersonneAbsenteException(const std::string& message)
        : PersonneException(message) {}
};

#endif // PERSONNEEXCEPTION_H

