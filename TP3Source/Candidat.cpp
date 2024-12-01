#include "Candidat.h"
#include "ContratException.h"
#include "Date.h"
#include <sstream>

namespace elections {

/**
 * \brief Convertit une valeur de type PartisPolitiques en une chaîne de caractères.
 * 
 * Cette fonction permet de convertir une valeur d'énumération `PartisPolitiques` en une chaîne
 * de caractères correspondant au nom du parti. Elle est utilisée pour afficher le nom du parti
 * dans le format lisible par un utilisateur.
 * 
 * \param parti Le parti politique à convertir.
 * \return Une chaîne de caractères représentant le parti politique.
 */
std::string enumToString(PartisPolitiques parti) {
    switch (parti) {
        case BLOC_QUEBECOIS: return "BLOC_QUEBECOIS";
        case CONSERVATEUR: return "CONSERVATEUR";
        case INDEPENDANT: return "INDEPENDANT";
        case LIBERAL: return "LIBERAL";
        case NOUVEAU_PARTI_DEMOCRATIQUE: return "NOUVEAU_PARTI_DEMOCRATIQUE";
        default: return "UNKNOWN";
    }
}

/**
 * \brief Constructeur de la classe Candidat.
 * 
 * Ce constructeur initialise un objet `Candidat` en utilisant les informations personnelles d'une
 * personne (NAS, prénom, nom, adresse, date de naissance) et ajoute une information spécifique à
 * un candidat, à savoir son parti politique.
 * 
 * \param nas Le NAS du candidat.
 * \param prenom Le prénom du candidat.
 * \param nom Le nom du candidat.
 * \param adresse L'adresse du candidat.
 * \param dateNaissance La date de naissance du candidat.
 * \param parti Le parti politique auquel le candidat appartient.
 */
Candidat::Candidat(const std::string& nas, const std::string& prenom, const std::string& nom,
                   const std::string& adresse, const util::Date& dateNaissance, PartisPolitiques parti)
    : Personne(nas, prenom, nom, adresse, dateNaissance), m_partiPolitique(parti) {
    PRECONDITION(parti >= BLOC_QUEBECOIS && parti <= NOUVEAU_PARTI_DEMOCRATIQUE);
    POSTCONDITION(m_partiPolitique == parti);
    INVARIANTS();
}

/**
 * \brief Retourne le parti politique du candidat.
 * 
 * Cette méthode permet de récupérer le parti politique auquel appartient le candidat.
 * 
 * \return Le parti politique du candidat de type `PartisPolitiques`.
 */
PartisPolitiques Candidat::reqPartiPolitique() const {
    return m_partiPolitique;
}

/**
 * \brief Crée une copie dynamique du candidat.
 * 
 * Cette méthode permet de créer une copie de l'objet `Candidat` actuel. La copie est
 * effectuée en allouant de la mémoire pour un nouvel objet, et le contenu du candidat
 * est dupliqué dans cette nouvelle instance.
 * 
 * \return Un pointeur unique vers une nouvelle instance du candidat.
 */
std::unique_ptr<Personne> Candidat::clone() const {
    return std::make_unique<Candidat>(*this);
}

/**
 * \brief Retourne une chaîne de caractères formatée représentant les informations du candidat.
 * 
 * Cette méthode génère une chaîne formatée contenant les informations détaillées du candidat,
 * y compris son nom, prénom, NAS, adresse, date de naissance, et son parti politique. Le format
 * d'affichage est conçu pour être lisible par l'utilisateur.
 * 
 * \return Une chaîne de caractères formatée représentant les informations du candidat.
 */
std::string Candidat::reqPersonneFormate() const {
    std::ostringstream os;
    os << "Candidat\n"
       << "----------------------------------------------\n"  // Ajustez le nombre de tirets si nécessaire
       << "NAS : " << m_nas << "\n"
       << "Prenom : " << m_prenom << "\n"
       << "Nom : " << m_nom << "\n"
       << "Date de naissance : " << m_dateNaissance.reqDateFormatee() << "\n"  // Assurez-vous que la date est formatée sans le jour de la semaine
       << "Adresse : " << m_adresse << "\n"
       << "Parti politique : " << enumToString(m_partiPolitique) << "\n";  // Utilisez enumToString ici
    return os.str();
}

/**
 * \brief Vérifie les invariants de l'objet Candidat.
 * 
 * Cette méthode valide que les informations relatives au candidat respectent les règles internes
 * de l'application. Elle s'assure que le parti politique du candidat est un des partis valides définis
 * dans l'énumération `PartisPolitiques`.
 */
void Candidat::verifieInvariant() const {
    INVARIANT(m_partiPolitique >= BLOC_QUEBECOIS && m_partiPolitique <= NOUVEAU_PARTI_DEMOCRATIQUE);
}

} // namespace elections
