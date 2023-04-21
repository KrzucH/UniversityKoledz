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
    for (auto n : content) {
        if (n.show() == Kowalski[i].show()) {
            i++;
        }
    }
    EXPECT_EQ(Kowalski.size(), i);
}
TEST_F(DatabaseTest, SearchByPesel) {
    std::string pesel;
    Student adam{
        "Jan",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "93070302143",
        Gender::Male};
    db.add(adam);

    Student ewa{
        "Ewa",
        "Kowalska",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "10272050321",
        Gender::Male};
    db.add(ewa);

    Student krzysztof{
        "Krzysztof",
        "Nowak",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "45091309453",
        Gender::Male};
    db.add(krzysztof);

    Student jan{
        "Jan",
        "Samulski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "80123009842",
        Gender::Male};
    db.add(jan);

    Student zdzisław{
        "Zdzisław",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "95040478923",
        Gender::Male};
    db.add(zdzisław);

    Student marcin{
        "Marcin",
        "Nowicki",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "06301585831",
        Gender::Male};
    db.add(marcin);

    auto content = db.searchPesel("06301585831");
    auto content1 = db.searchPesel("95040478923");
    auto content2 = db.searchPesel("10272050321");

    bool checker = false;
    for (const auto& n : db.students_) {
        if (content == n.show()) {
            checker = true;
        }
    }
    EXPECT_TRUE(checker);

    checker = false;
    for (const auto& n : db.students_) {
        if (content1 == n.show()) {
            checker = true;
        }
    }
    EXPECT_TRUE(checker);

    checker = false;
    for (const auto& n : db.students_) {
        if (content2 == n.show()) {
            checker = true;
        }
    }
    EXPECT_TRUE(checker);
}

TEST_F(DatabaseTest, SortByPesel) {
    std::vector<std::string> pesel;
    Student adam{
        "Jan",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "93070302143",
        Gender::Male};
    db.add(adam);

    Student ewa{
        "Ewa",
        "Kowalska",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "10272050321",
        Gender::Male};
    db.add(ewa);

    Student krzysztof{
        "Krzysztof",
        "Nowak",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "45091309453",
        Gender::Male};
    db.add(krzysztof);

    Student jan{
        "Jan",
        "Samulski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "80123009842",
        Gender::Male};
    db.add(jan);

    Student zdzisław{
        "Zdzisław",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "95040478923",
        Gender::Male};
    db.add(zdzisław);

    Student marcin{
        "Marcin",
        "Nowicki",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "06301585831",
        Gender::Male};
    db.add(marcin);

    db.sortByPesel();

    for (const auto& n : db.students_) {
        pesel.push_back(n.getPesel());
    }

    EXPECT_EQ("45091309453", pesel[0]);
    EXPECT_EQ("80123009842", pesel[1]);
    EXPECT_EQ("93070302143", pesel[2]);
    EXPECT_EQ("95040478923", pesel[3]);
    EXPECT_EQ("06301585831", pesel[4]);
    EXPECT_EQ("10272050321", pesel[5]);
}

TEST_F(DatabaseTest, SortBySurname) {
    std::vector<std::string> surname;

    Student adam{
        "Jan",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "93070302143",
        Gender::Male};
    db.add(adam);

    Student ewa{
        "Ewa",
        "Kowalska",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "10272050321",
        Gender::Male};
    db.add(ewa);

    Student krzysztof{
        "Krzysztof",
        "Nowak",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "45091309453",
        Gender::Male};
    db.add(krzysztof);

    Student jan{
        "Jan",
        "Samulski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "80123009842",
        Gender::Male};
    db.add(jan);

    Student zdzisław{
        "Zdzisław",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "95040478923",
        Gender::Male};
    db.add(zdzisław);

    Student marcin{
        "Marcin",
        "Nowicki",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "06301585831",
        Gender::Male};
    db.add(marcin);

    db.sortBySurname();

    for (const auto& n : db.students_) {
        surname.push_back(n.getSurname());
    }
    EXPECT_EQ("Kowalska", surname[0]);
    EXPECT_EQ("Kowalski", surname[1]);
    EXPECT_EQ("Kowalski", surname[2]);
    EXPECT_EQ("Nowak", surname[3]);
    EXPECT_EQ("Nowicki", surname[4]);
    EXPECT_EQ("Samulski", surname[5]);
}

TEST_F(DatabaseTest, DeleteById) {
    Student adam{
        "Jan",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        882143,
        "93070302143",
        Gender::Male};
    db.add(adam);

    Student ewa{
        "Ewa",
        "Kowalska",
        "ul. Lesna 12, 00-100 Warszawa",
        735921,
        "10272050321",
        Gender::Male};
    db.add(ewa);

    Student krzysztof{
        "Krzysztof",
        "Nowak",
        "ul. Lesna 12, 00-100 Warszawa",
        186421,
        "45091309453",
        Gender::Male};
    db.add(krzysztof);

    Student jan{
        "Jan",
        "Samulski",
        "ul. Lesna 12, 00-100 Warszawa",
        654321,
        "80123009842",
        Gender::Male};
    db.add(jan);

    Student zdzisław{
        "Zdzisław",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        236453,
        "95040478923",
        Gender::Male};
    db.add(zdzisław);

    Student marcin{
        "Marcin",
        "Nowicki",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "06301585831",
        Gender::Male};
    db.add(marcin);

    db.deleteById(123456);
    db.deleteById(236453);
    db.deleteById(882143);
    db.deleteById(186421);

    auto content = db.students_.size();

    bool checker = true;
    for (const auto& n : db.students_) {
        if (123456 == n.getId()) {
            checker = false;
        }
    }

    EXPECT_TRUE(checker);

    checker = true;
    for (const auto& n : db.students_) {
        if (236453 == n.getId()) {
            checker = false;
        }
    }
    EXPECT_TRUE(checker);

    checker = true;
    for (const auto& n : db.students_) {
        if (882143 == n.getId()) {
            checker = false;
        }
    }
    EXPECT_TRUE(checker);

    checker = true;
    for (const auto& n : db.students_) {
        if (186421 == n.getId()) {
            checker = false;
        }
    }
    EXPECT_TRUE(checker);

    EXPECT_EQ(2, content);
}
