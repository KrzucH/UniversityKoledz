#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

struct DatabaseTest : ::testing::Test {
    Database db;
};

TEST_F(DatabaseTest, DisplayEmptyDb) {
    auto content = db.show();
    std::string expected = "";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, DisplayNonEmptDb) {
    Student adam{
        "Jan",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "1234567891011",
        Gender::Male};
    db.add(adam);

    auto content = db.show();
    std::string expected = "Jan Kowalski; ul. Lesna 12, 00-100 Warszawa; 123456; 1234567891011; Male \n";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, SearchByName) {
    std::vector<Student> Kowalski;
    // std::vector<
    Student adam{
        "Jan",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "1234567891011",
        Gender::Male};
    db.add(adam);

    Student ewa{
        "Ewa",
        "Kowalska",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "1234567891011",
        Gender::Male};
    db.add(ewa);

    Student krzysztof{
        "Krzysztof",
        "Nowak",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "1234567891011",
        Gender::Male};
    db.add(krzysztof);

    Student jan{
        "Jan",
        "Samulski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "1234567891011",
        Gender::Male};
    db.add(jan);

    Student zdzisław{
        "Zdzisław",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "1234567891011",
        Gender::Male};
    db.add(zdzisław);

    Student marcin{
        "Marcin",
        "Nowicki",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "1234567891011",
        Gender::Male};
    db.add(marcin);

    
    Kowalski.push_back(adam);
    Kowalski.push_back(zdzisław);
    
    auto content = db.searchSurname("Kowalski");
    int i = 0;
    bool Checker = true;
    for (auto n : content) {
        if (n.show() == Kowalski[i].show()) {
            i++;
        }
        //     Checker = false;
    }
    // EXPECT_TRUE(Checker);
    EXPECT_EQ(Kowalski.size(), i);
}

