#include <gtest/gtest.h>
#include "Personne.h"
#include "Date.h"
#include "ContratException.h"
#include <iostream>

using namespace elections;
using namespace util;

class PersonneTest : public Personne {
public:
    PersonneTest(const std::string& nas, const std::string& prenom, const std::string& nom,
                 const std::string& adresse, const Date& dateNaissance)
        : Personne(nas, prenom, nom, adresse, dateNaissance) {}

    virtual std::string reqPersonneFormate() const override {
        return Personne::reqPersonneFormate();
    }
};

TEST(Personne, Constructor) {
    PersonneTest unePersonne("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", Date(12, 5, 1979));
    ASSERT_EQ(unePersonne.reqNas(), "046 454 286");
    ASSERT_EQ(unePersonne.reqPrenom(), "Jean");
    ASSERT_EQ(unePersonne.reqNom(), "Louis");
    ASSERT_EQ(unePersonne.reqAdresse(), "235, rue de l'Université, Québec, G1V 0A7, QC");
    ASSERT_EQ(unePersonne.reqDateNaissance(), Date(12, 5, 1979));
}

TEST(Personne, ConstructorInvalidNas) {
    ASSERT_THROW(PersonneTest("", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", Date(12, 5, 1979)),
                 PreconditionException);
}

TEST(Personne, ConstructorInvalidPrenom) {
    ASSERT_THROW(PersonneTest("046 454 286", "", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", Date(12, 5, 1979)),
                 PreconditionException);
}

TEST(Personne, ConstructorInvalidNom) {
    ASSERT_THROW(PersonneTest("046 454 286", "Jean", "", "235, rue de l'Université, Québec, G1V 0A7, QC", Date(12, 5, 1979)),
                 PreconditionException);
}

TEST(Personne, ConstructorInvalidAdresse) {
    ASSERT_THROW(PersonneTest("046 454 286", "Jean", "Louis", "", Date(12, 5, 1979)), PreconditionException);
}

TEST(Personne, ConstructorInvalidDate) {
    ASSERT_THROW(PersonneTest("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", Date(12, 5, 1900)),
                 PreconditionException);
}

class UnePersonne : public ::testing::Test {
public:
    UnePersonne()
        : personne("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", Date(12, 5, 1979)) {}

    PersonneTest personne;
};

TEST_F(UnePersonne, reqNas) {
    ASSERT_EQ(personne.reqNas(), "046 454 286");
}

TEST_F(UnePersonne, reqPrenom) {
    ASSERT_EQ(personne.reqPrenom(), "Jean");
}

TEST_F(UnePersonne, reqNom) {
    ASSERT_EQ(personne.reqNom(), "Louis");
}

TEST_F(UnePersonne, reqAdresse) {
    ASSERT_EQ(personne.reqAdresse(), "235, rue de l'Université, Québec, G1V 0A7, QC");
}

TEST_F(UnePersonne, reqDateNaissance) {
    ASSERT_EQ(personne.reqDateNaissance(), Date(12, 5, 1979));
}

TEST_F(UnePersonne, ModifierAdresse) {
    personne.asgAdresse("456, rue DEF, Québec, G2E 2B4, QC");
    ASSERT_EQ(personne.reqAdresse(), "456, rue DEF, Québec, G2E 2B4, QC");
}

TEST_F(UnePersonne, reqPersonneFormate) {
    std::ostringstream os;
    os << "NAS                 : 046 454 286\n"
       << "Prenom              : Jean\n"
       << "Nom                 : Louis\n"
       << "Date de naissance   : Samedi le 12 mai 1979\n"
       << "Adresse             : 235, rue de l'Université, Québec, G1V 0A7, QC\n";

    const std::string expected = os.str();
    const std::string actual = personne.reqPersonneFormate();

    if (expected != actual) {
        std::cerr << "Expected:\n" << expected << "\n";
        std::cerr << "Actual:\n" << actual << "\n";
    }

    ASSERT_EQ(expected, actual);
}

TEST(Personne, InvariantNasVide) {
    ASSERT_THROW(PersonneTest("", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", Date(12, 5, 1979)),
                 PreconditionException);
}

TEST(Personne, InvariantPrenomVide) {
    ASSERT_THROW(PersonneTest("046 454 286", "", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", Date(12, 5, 1979)),
                 PreconditionException);
}

TEST(Personne, InvariantNomVide) {
    ASSERT_THROW(PersonneTest("046 454 286", "Jean", "", "235, rue de l'Université, Québec, G1V 0A7, QC", Date(12, 5, 1979)),
                 PreconditionException);
}

TEST(Personne, InvariantAdresseVide) {
    ASSERT_THROW(PersonneTest("046 454 286", "Jean", "Louis", "", Date(12, 5, 1979)), PreconditionException);
}

TEST(Personne, InvariantDateInvalide) {
    ASSERT_THROW(PersonneTest("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec, G1V 0A7, QC", Date(12, 5, 1900)),
                 PreconditionException);
}
