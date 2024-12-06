#include <gtest/gtest.h>
#include <sstream>
#include "Circonscription.h"
#include "Candidat.h"
#include "Electeur.h"
#include "PersonneException.h"

using namespace elections;

TEST(Circonscription, ConstructeurValide) {
    Candidat candidat("640 454 286", "Jean", "Louis", "235 Rue de l'Université, Québec, QC, G1V 0A7",
                      util::Date(1, 1, 1980), LIBERAL);
    Circonscription circonscription("Circonscription-1", candidat);

    ASSERT_EQ(circonscription.reqNomCirconscription(), "Circonscription-1");
    ASSERT_EQ(circonscription.reqDeputeSortant().reqNas(), "640 454 286");
}

TEST(Circonscription, ConstructeurNomInvalide) {
    Candidat candidat("640 454 286", "Jean", "Louis", "235 Rue de l'Université, Québec, QC, G1V 0A7",
                      util::Date(1, 1, 1980), LIBERAL);
    ASSERT_THROW(Circonscription("", candidat), std::invalid_argument);
}


TEST(Circonscription, AjouterElecteurValide) {
    Candidat candidat("640 454 286", "Jean", "Louis", "235 Rue de l'Université, Québec, QC, G1V 0A7",
                      util::Date(1, 1, 1980), LIBERAL);
    Circonscription circonscription("Circonscription-1", candidat);

    Electeur electeur("123 456 789", "Alice", "Smith", "456 Rue Centrale, Montréal, QC, H3H 1H1",
                      util::Date(15, 3, 1990));

    circonscription.inscrire(electeur);

    std::ostringstream os;
    os << "Circonscription : Circonscription-1\n";
    os << "Député sortant :\n" << candidat.reqPersonneFormate() << "\n";
    os << "Liste des inscrits :\n";
    os << electeur.reqPersonneFormate() << "\n";

    ASSERT_EQ(circonscription.reqCirconscriptionFormate(), os.str());
}

TEST(Circonscription, AjouterElecteurDejaPresent) {
    Candidat candidat("640 454 286", "Jean", "Louis", "235 Rue de l'Université, Québec, QC, G1V 0A7",
                      util::Date(1, 1, 1980), LIBERAL);
    Circonscription circonscription("Circonscription-1", candidat);

    Electeur electeur("123 456 789", "Alice", "Smith", "456 Rue Centrale, Montréal, QC, H3H 1H1",
                      util::Date(15, 3, 1990));

    circonscription.inscrire(electeur);
    ASSERT_THROW(circonscription.inscrire(electeur), PersonneDejaPresenteException);
}

TEST(Circonscription, DesinscrireElecteurValide) {
    Candidat candidat("640 454 286", "Jean", "Louis", "235 Rue de l'Université, Québec, QC, G1V 0A7",
                      util::Date(1, 1, 1980), LIBERAL);
    Circonscription circonscription("Circonscription-1", candidat);

    Electeur electeur("123 456 789", "Alice", "Smith", "456 Rue Centrale, Montréal, QC, H3H 1H1",
                      util::Date(15, 3, 1990));

    circonscription.inscrire(electeur);
    circonscription.desinscrire("123 456 789");

    std::ostringstream os;
    os << "Circonscription : Circonscription-1\n";
    os << "Député sortant :\n" << candidat.reqPersonneFormate() << "\n";
    os << "Liste des inscrits :\n";

    ASSERT_EQ(circonscription.reqCirconscriptionFormate(), os.str());
}

TEST(Circonscription, DesinscrireElecteurInexistant) {
    Candidat candidat("640 454 286", "Jean", "Louis", "235 Rue de l'Université, Québec, QC, G1V 0A7",
                      util::Date(1, 1, 1980), LIBERAL);
    Circonscription circonscription("Circonscription-1", candidat);

    ASSERT_THROW(circonscription.desinscrire("987 654 321"), PersonneAbsenteException);
}

TEST(Circonscription, CloneCirconscription) {
    Candidat candidat("640 454 286", "Jean", "Louis", "235 Rue de l'Université, Québec, QC, G1V 0A7",
                      util::Date(1, 1, 1980), LIBERAL);
    Circonscription circonscription("Circonscription-1", candidat);

    Electeur electeur("123 456 789", "Alice", "Smith", "456 Rue Centrale, Montréal, QC, H3H 1H1",
                      util::Date(15, 3, 1990));
    circonscription.inscrire(electeur);

    std::unique_ptr<Circonscription> circonscriptionClone = circonscription.clone();

    ASSERT_EQ(circonscriptionClone->reqNomCirconscription(), circonscription.reqNomCirconscription());
    ASSERT_EQ(circonscriptionClone->reqDeputeSortant().reqNas(), circonscription.reqDeputeSortant().reqNas());
    ASSERT_EQ(circonscriptionClone->reqCirconscriptionFormate(), circonscription.reqCirconscriptionFormate());
}



