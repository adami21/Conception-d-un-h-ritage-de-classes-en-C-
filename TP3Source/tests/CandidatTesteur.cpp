#include "Candidat.h"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "ContratException.h"

using namespace elections;
using namespace std;

TEST(Candidat, ConstructeurDefaut) {
    Candidat candidat("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", 
                      util::Date(12, 5, 1979), BLOC_QUEBECOIS);
    ASSERT_EQ(candidat.reqNas(), "046 454 286");
    ASSERT_EQ(candidat.reqPrenom(), "Jean");
    ASSERT_EQ(candidat.reqNom(), "Louis");
    ASSERT_EQ(candidat.reqAdresse(), "235, rue de l'Université, Québec, G1V 0A7, QC");
    ASSERT_EQ(candidat.reqDateNaissance(), util::Date(12, 5, 1979));
    ASSERT_EQ(candidat.reqPartiPolitique(), BLOC_QUEBECOIS);
}

TEST(Candidat, ConstructeurNasInvalide) {
    ASSERT_THROW(Candidat candidat("", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", 
                                   util::Date(12, 5, 1979), BLOC_QUEBECOIS), PreconditionException);
}

TEST(Candidat, ConstructeurPrenomInvalide) {
    ASSERT_THROW(Candidat candidat("046 454 286", "", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", 
                                   util::Date(12, 5, 1979), BLOC_QUEBECOIS), PreconditionException);
}

TEST(Candidat, ConstructeurNomInvalide) {
    ASSERT_THROW(Candidat candidat("046 454 286", "Jean", "", "235, rue de l'Université, Québec, G1V 0A7, QC", 
                                   util::Date(12, 5, 1979), BLOC_QUEBECOIS), PreconditionException);
}

TEST(Candidat, ConstructeurAdresseInvalide) {
    ASSERT_THROW(Candidat candidat("046 454 286", "Jean", "Louis", "", util::Date(12, 5, 1979), BLOC_QUEBECOIS), PreconditionException);
}

TEST(Candidat, ConstructeurDateNaissanceInvalide) {
    ASSERT_THROW(Candidat candidat("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", 
                                   util::Date(12, 5, 1900), BLOC_QUEBECOIS), PreconditionException);
}

class CandidatTest : public ::testing::Test {
public:
    CandidatTest() 
        : candidat("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", 
                   util::Date(12, 5, 1979), BLOC_QUEBECOIS) {}

    Candidat candidat;  
};

TEST_F(CandidatTest, reqPartiPolitique) {
    ASSERT_EQ(candidat.reqPartiPolitique(), BLOC_QUEBECOIS);
}

TEST_F(CandidatTest, reqPersonneFormate) {
    std::ostringstream os;
    os << "Candidat\n"
       << "----------------------------------------------\n"
       << "NAS : 046 454 286\n"
       << "Prenom : Jean\n"
       << "Nom : Louis\n"
       << "Date de naissance : Samedi le 12 mai 1979\n"
       << "Adresse : 235, rue de l'Université, Québec, G1V 0A7, QC\n"
       << "Parti politique : BLOC_QUEBECOIS\n";

    ASSERT_EQ(candidat.reqPersonneFormate(), os.str());
}

TEST_F(CandidatTest, Clone) {
    std::unique_ptr<Personne> clone = candidat.clone();

    ASSERT_TRUE(clone);
    ASSERT_EQ(clone->reqNas(), candidat.reqNas());
    ASSERT_EQ(clone->reqPrenom(), candidat.reqPrenom());
    ASSERT_EQ(clone->reqNom(), candidat.reqNom());
    ASSERT_EQ(clone->reqAdresse(), candidat.reqAdresse());
    ASSERT_EQ(clone->reqDateNaissance(), candidat.reqDateNaissance());
    ASSERT_EQ(dynamic_cast<Candidat*>(clone.get())->reqPartiPolitique(), candidat.reqPartiPolitique());
}

