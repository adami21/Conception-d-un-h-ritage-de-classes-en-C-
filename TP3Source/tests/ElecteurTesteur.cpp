#include "Electeur.h"
#include "ContratException.h" // Pour gérer PreconditionException si nécessaire
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

using namespace elections;

TEST(Electeur, ConstructeurValide) {
    Electeur electeur("640 454 286", "Joe", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC", 
                      util::Date(12, 5, 1980));
    ASSERT_EQ(electeur.reqNas(), "640 454 286");
    ASSERT_EQ(electeur.reqPrenom(), "Joe");
    ASSERT_EQ(electeur.reqNom(), "Blo");
    ASSERT_EQ(electeur.reqAdresse(), "235, rue de l'Université, Québec, G1V 0A7, QC");
    ASSERT_EQ(electeur.reqDateNaissance(), util::Date(12, 5, 1980));
}

TEST(Electeur, ConstructeurNasInvalide) {
    ASSERT_THROW(Electeur electeur("", "Joe", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC", 
                                   util::Date(12, 5, 1980)), PreconditionException);
}

TEST(Electeur, ConstructeurPrenomInvalide) {
    ASSERT_THROW(Electeur electeur("640 454 286", "", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC", 
                                   util::Date(12, 5, 1980)), PreconditionException);
}

TEST(Electeur, ConstructeurNomInvalide) {
    ASSERT_THROW(Electeur electeur("640 454 286", "Joe", "", "235, rue de l'Université, Québec, G1V 0A7, QC", 
                                   util::Date(12, 5, 1980)), PreconditionException);
}

TEST(Electeur, ConstructeurAdresseInvalide) {
    ASSERT_THROW(Electeur electeur("640 454 286", "Joe", "Blo", "", util::Date(12, 5, 1980)), PreconditionException);
}

TEST(Electeur, reqPersonneFormate) {
    Electeur electeur("640 454 286", "Joe", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC", 
                      util::Date(12, 5, 1980));
    
    std::ostringstream os;
    os << "Electeur" << std::endl;
    os << "---------------------------" << std::endl;
    os << "NAS                 : 640 454 286" << std::endl;
    os << "Prenom              : Joe" << std::endl;
    os << "Nom                 : Blo" << std::endl;
    os << "Date de naissance   : Lundi le 12 mai 1980" << std::endl;
    os << "Adresse             : 235, rue de l'Université, Québec, G1V 0A7, QC" << std::endl;

    ASSERT_EQ(electeur.reqPersonneFormate(), os.str());
}

TEST(Electeur, Clone) {
    Electeur electeur("640 454 286", "Joe", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC", 
                      util::Date(12, 5, 1980));
    
    std::unique_ptr<Personne> clone = electeur.clone();

    ASSERT_TRUE(clone);
    ASSERT_EQ(clone->reqNas(), electeur.reqNas());
    ASSERT_EQ(clone->reqPrenom(), electeur.reqPrenom());
    ASSERT_EQ(clone->reqNom(), electeur.reqNom());
    ASSERT_EQ(clone->reqAdresse(), electeur.reqAdresse());
    ASSERT_EQ(clone->reqDateNaissance(), electeur.reqDateNaissance());
}

TEST(Electeur, GestionPreconditionException) {
    ASSERT_THROW(Electeur electeur("", "Joe", "Blo", "235, rue de l'Université, Québec, G1V 0A7, QC", 
                                   util::Date(12, 5, 1980)), PreconditionException);
}
