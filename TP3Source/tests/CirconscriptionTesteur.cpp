#include <gtest/gtest.h>
#include <sstream>
#include "Circonscription.h"
#include "Candidat.h"
#include "Electeur.h"

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
    ASSERT_THROW(Circonscription circonscription("", candidat), std::invalid_argument);
}

TEST(Circonscription, reqCirconscriptionFormate) {
    Candidat candidat("640 454 286", "Jean", "Louis", "235 Rue de l'Université, Québec, QC, G1V 0A7",
                      util::Date(1, 1, 1980), LIBERAL);
    Circonscription circonscription("Circonscription-1", candidat);

    Electeur electeur1("123 456 789", "Alice", "Smith", "456 Rue Centrale, Montréal, QC, H3H 1H1",
                       util::Date(15, 3, 1990));
    Electeur electeur2("987 654 321", "Bob", "Brown", "789 Rue de l'Église, Laval, QC, H7N 4G5",
                       util::Date(20, 6, 1985));

    circonscription.ajouterElecteur(electeur1);
    circonscription.ajouterElecteur(electeur2);

    std::ostringstream os;
    os << "Circonscription : Circonscription-1\n";
    os << "Député sortant :\n" << candidat.reqPersonneFormate() << "\n";
    os << "Liste des inscrits :\n";
    os << electeur1.reqPersonneFormate() << "\n";
    os << electeur2.reqPersonneFormate() << "\n";

    ASSERT_EQ(circonscription.reqCirconscriptionFormate(), os.str());
}

TEST(Circonscription, AjouterElecteur) {
    Candidat candidat("640 454 286", "Jean", "Louis", "235 Rue de l'Université, Québec, QC, G1V 0A7",
                      util::Date(1, 1, 1980), LIBERAL);
    Circonscription circonscription("Circonscription-1", candidat);

    Electeur electeur("123 456 789", "Alice", "Smith", "456 Rue Centrale, Montréal, QC, H3H 1H1",
                      util::Date(15, 3, 1990));

    circonscription.ajouterElecteur(electeur);

    std::ostringstream os;
    os << "Circonscription : Circonscription-1\n";
    os << "Député sortant :\n" << candidat.reqPersonneFormate() << "\n";
    os << "Liste des inscrits :\n";
    os << electeur.reqPersonneFormate() << "\n";

    ASSERT_EQ(circonscription.reqCirconscriptionFormate(), os.str());
}

TEST(Circonscription, Clone) {
    Candidat candidat("640 454 286", "Jean", "Louis", "235 Rue de l'Université, Québec, QC, G1V 0A7",
                      util::Date(1, 1, 1980), LIBERAL);
    Circonscription circonscription("Circonscription-1", candidat);

    Electeur electeur("123 456 789", "Alice", "Smith", "456 Rue Centrale, Montréal, QC, H3H 1H1",
                      util::Date(15, 3, 1990));
    circonscription.ajouterElecteur(electeur);

    std::unique_ptr<Circonscription> circonscriptionClone = circonscription.clone();

    ASSERT_EQ(circonscriptionClone->reqNomCirconscription(), circonscription.reqNomCirconscription());
    ASSERT_EQ(circonscriptionClone->reqDeputeSortant().reqNas(), circonscription.reqDeputeSortant().reqNas());
    ASSERT_EQ(circonscriptionClone->reqCirconscriptionFormate(), circonscription.reqCirconscriptionFormate());
}


