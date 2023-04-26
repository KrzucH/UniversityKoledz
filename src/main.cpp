#include <iostream>
#include "database.hpp"
#include "student.hpp"

int main() {
    Database db;
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "89010595928",
        Gender::Male};
    Student jacek{
        "Jacek",
        "Sztuka",
        "ul. Wesola 42, 13-100 Szczecin",
        654321,
        "00270441882",
        Gender::Male};
    Student agnieszka{
        "Agnieszka",
        "Kowalska",
        "ul. Lesna 12, 00-100 Warszawa",
        832439,
        "99021158692",
        Gender::Female};
    Student mariusz{
        "Mariusz",
        "Kowalski",
        "ul. Zimna 22, 11-100 Krakow",
        657433,
        "72011953343",
        Gender::Male};
    Student jan{
        "Jan",
        "Nowak",
        "ul. Szkolna 15, 12-100 Poznan",
        192534,
        "61112192856",
        Gender::Male};
    Student adam1{
        "Adam",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "89010595928",
        Gender::Male};
    Student adam2{
        "Adam",
        "Kowalski",
        "ul. Lesna 12, 00-100 Warszawa",
        123456,
        "89010595928",
        Gender::Male};
    db.add(adam);
    db.add(agnieszka);
    db.add(mariusz);
    db.add(jan);
    db.add(jacek);
    db.add(adam1);
    db.add(adam2);

    db.loadDataBaseFromaFile("Baza.txt", db);
    db.display();
    db.saveDataBaseToFile(db);
    // std::cout << '\n';
    // db.searchSurname("Kowalski");
    // std::cout << '\n';
    // std::cout << db.searchPesel("89010595928");
    // db.sortByPesel();
    // db.sortBySurname();
    // db.deleteById(654321);
    // db.display();
    // db.Peseltest("06070704033");
    // db.Peseltest("93070704033");

    return 0;
}