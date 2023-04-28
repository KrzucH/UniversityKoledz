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
        "00270441882",
        Gender::Male,
        "123456"};
    db.addStudent(adam);

    auto content = db.show();
    std::string expected = "Jan; Kowalski; ul. Lesna 12, 00-100 Warszawa; 123456; 00270441882; 0; Male \n";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, SearchByName) {
    std::vector<std::shared_ptr<Person>> Kowalski;
    std::vector<std::shared_ptr<Person>> vec;

    Student adam{
        "Jan",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        "89010595928",
        Gender::Male,
        "882143"};
    db.addStudent(adam);

    Student ewa{
        "Ewa",
        "Kowalska",
        "ul. Lesna 12, 00-100 Warszawa",
        "00270441882",
        Gender::Male,
        "735921"};
    db.addStudent(ewa);

    Employee krzysztof{
        "Krzysztof",
        "Nowak",
        "ul. Lesna 12, 00-100 Warszawa",
        "99021158692",
        Gender::Male,
        1864};
    db.addEmpolyee(krzysztof);

    Student jan{
        "Jan",
        "Samulski",
        "ul. Lesna 12, 00-100 Warszawa",
        "72011953343",
        Gender::Male,
        "654321"};
    db.addStudent(jan);

    Employee zdzislaw{
        "Zdzislaw",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        "61112192856",
        Gender::Male,
        2364};
    db.addEmpolyee(zdzislaw);

    Student marcin{
        "Marcin",
        "Nowicki",
        "ul. Lesna 12, 00-100 Warszawa",
        "02260323723",
        Gender::Male,
        "123456"};
    db.addStudent(marcin);

    Kowalski.push_back(std::make_shared<Student> (adam));
    Kowalski.push_back(std::make_shared<Employee> (zdzislaw));

    auto expected = Kowalski[0]->show();
    auto expected1 = Kowalski[1]->show();

    

    auto content = db.searchSurname("Kowalski");

    int i = 0;
    for (auto n : content) {
        if (n -> getSurname() == Kowalski[i]->getSurname()) {
            vec.push_back(n);
            i++;
        }
    }
    EXPECT_EQ(Kowalski.size(), i);
    EXPECT_EQ(vec[0]->show(), expected);
    EXPECT_EQ(vec[1]->show(), expected1);
}
TEST_F(DatabaseTest, SearchByPesel) {
    std::string pesel;

    Student adam{
        "Jan",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        "89010595928",
        Gender::Male,
        "882143"};
    db.addStudent(adam);

    Student ewa{
        "Ewa",
        "Kowalska",
        "ul. Lesna 12, 00-100 Warszawa",
        "00270441882",
        Gender::Male,
        "735921"};
    db.addStudent(ewa);

    Employee krzysztof{
        "Krzysztof",
        "Nowak",
        "ul. Lesna 12, 00-100 Warszawa",
        "99021158692",
        Gender::Male,
        1864};
    db.addEmpolyee(krzysztof);

    Student jan{
        "Jan",
        "Samulski",
        "ul. Lesna 12, 00-100 Warszawa",
        "72011953343",
        Gender::Male,
        "654321"};
    db.addStudent(jan);

    Employee zdzisław{
        "Zdzisław",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        "61112192856",
        Gender::Male,
        2364};
    db.addEmpolyee(zdzisław);

    Student marcin{
        "Marcin",
        "Nowicki",
        "ul. Lesna 12, 00-100 Warszawa",
        "02260323723",
        Gender::Male,
        "123456"};
    db.addStudent(marcin);

    auto content = db.searchPesel("00270441882");
    auto content1 = db.searchPesel("72011953343");
    auto content2 = db.searchPesel("02260323723");

    bool checker = false;
    for (const auto& n : db.db_) {
        if (content == n->show()) {
            checker = true;
        }
    }
    EXPECT_TRUE(checker);

    checker = false;
    for (const auto& n : db.db_) {
        if (content1 == n->show()) {
            checker = true;
        }
    }
    EXPECT_TRUE(checker);

    checker = false;
    for (const auto& n : db.db_) {
        if (content2 == n->show()) {
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
        "89010595928",
        Gender::Male,
        "882143"};
    db.addStudent(adam);

    Student ewa{
        "Ewa",
        "Kowalska",
        "ul. Lesna 12, 00-100 Warszawa",
        "00270441882",
        Gender::Male,
        "735921"};
    db.addStudent(ewa);

    Employee krzysztof{
        "Krzysztof",
        "Nowak",
        "ul. Lesna 12, 00-100 Warszawa",
        "99021158692",
        Gender::Male,
        1864};
    db.addEmpolyee(krzysztof);

    Student jan{
        "Jan",
        "Samulski",
        "ul. Lesna 12, 00-100 Warszawa",
        "72011953343",
        Gender::Male,
        "654321"};
    db.addStudent(jan);

    Employee zdzisław{
        "Zdzisław",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        "61112192856",
        Gender::Male,
        2364};
    db.addEmpolyee(zdzisław);

    Student marcin{
        "Marcin",
        "Nowicki",
        "ul. Lesna 12, 00-100 Warszawa",
        "02260323723",
        Gender::Male,
        "123456"};
    db.addStudent(marcin);

    db.sortByPesel();

    for (const auto& n : db.db_) {
        pesel.push_back(n->getPesel());
    }

    EXPECT_EQ("61112192856", pesel[0]);
    EXPECT_EQ("72011953343", pesel[1]);
    EXPECT_EQ("89010595928", pesel[2]);
    EXPECT_EQ("99021158692", pesel[3]);
    EXPECT_EQ("00270441882", pesel[4]);
    EXPECT_EQ("02260323723", pesel[5]);
}

TEST_F(DatabaseTest, SortBySurname) {
    std::vector<std::string> surname;

    Student adam{
        "Jan",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        "89010595928",
        Gender::Male,
        "882143"};
    db.addStudent(adam);

    Student ewa{
        "Ewa",
        "Kowalska",
        "ul. Lesna 12, 00-100 Warszawa",
        "00270441882",
        Gender::Male,
        "735921"};
    db.addStudent(ewa);

    Employee krzysztof{
        "Krzysztof",
        "Nowak",
        "ul. Lesna 12, 00-100 Warszawa",
        "99021158692",
        Gender::Male,
        1864};
    db.addEmpolyee(krzysztof);

    Student jan{
        "Jan",
        "Samulski",
        "ul. Lesna 12, 00-100 Warszawa",
        "72011953343",
        Gender::Male,
        "654321"};
    db.addStudent(jan);

    Employee zdzisław{
        "Zdzisław",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        "61112192856",
        Gender::Male,
        2364};
    db.addEmpolyee(zdzisław);

    Student marcin{
        "Marcin",
        "Nowicki",
        "ul. Lesna 12, 00-100 Warszawa",
        "02260323723",
        Gender::Male,
        "123456"};
    db.addStudent(marcin);

    db.sortBySurname();

    for (const auto& n : db.db_) {
        surname.push_back(n -> getSurname());
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
        "89010595928",
        Gender::Male,
        "882143"};
    db.addStudent(adam);

    Student ewa{
        "Ewa",
        "Kowalska",
        "ul. Lesna 12, 00-100 Warszawa",
        "00270441882",
        Gender::Male,
        "735921"};
    db.addStudent(ewa);

    Employee krzysztof{
        "Krzysztof",
        "Nowak",
        "ul. Lesna 12, 00-100 Warszawa",
        "99021158692",
        Gender::Male,
        1864};
    db.addEmpolyee(krzysztof);

    Student jan{
        "Jan",
        "Samulski",
        "ul. Lesna 12, 00-100 Warszawa",
        "72011953343",
        Gender::Male,
        "654321"};
    db.addStudent(jan);

    Employee zdzisław{
        "Zdzisław",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        "61112192856",
        Gender::Male,
        2364};
    db.addEmpolyee(zdzisław);

    Student marcin{
        "Marcin",
        "Nowicki",
        "ul. Lesna 12, 00-100 Warszawa",
        "02260323723",
        Gender::Male,
        "123456"};
    db.addStudent(marcin);
 

    db.deleteById("123456");
    db.deleteById("735921");
    db.deleteById("882143");
    db.deleteById("654321");

    auto content = db.db_.size();

    bool checker = true;
    for (const auto& n : db.db_) {
        if ("123456" == n -> getID()) {
            checker = false;
        }
    }

    EXPECT_TRUE(checker);

    checker = true;
    for (const auto& n : db.db_) {
        if ("236453" == n -> getID()) {
            checker = false;
        }
    }
    EXPECT_TRUE(checker);

    checker = true;
    for (const auto& n : db.db_) {
        if ("882143" == n -> getID()) {
            checker = false;
        }
    }
    EXPECT_TRUE(checker);

    checker = true;
    for (const auto& n : db.db_) {
        if ("186421" == n -> getID()) {
            checker = false;
        }
    }
    EXPECT_TRUE(checker);

    EXPECT_EQ(2, content);
}

TEST_F(DatabaseTest, PeselTest) {
    auto content = db.Peseltest("89010595928");
    auto content1 = db.Peseltest("00270441882");
    auto content2 = db.Peseltest("61112192856");
    auto content3 = db.Peseltest("99021158692");
    auto content4 = db.Peseltest("72011953343");
    auto content5 = db.Peseltest("89011595928");
    auto content6 = db.Peseltest("W9010595928");
    auto content7 = db.Peseltest("9010595928");
    auto content8 = db.Peseltest("901059592811");

    EXPECT_TRUE(content);
    EXPECT_TRUE(content1);
    EXPECT_TRUE(content2);
    EXPECT_TRUE(content3);
    EXPECT_TRUE(content4);
    EXPECT_FALSE(content5);
    EXPECT_FALSE(content6);
    EXPECT_FALSE(content7);
    EXPECT_FALSE(content8);
}