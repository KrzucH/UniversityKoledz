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
        "1234567891011",
        Gender::Male};
    Student agnieszka{
        "Agnieszka",
        "Kowalska",
        "ul. Leśna 12, 00-100 Warszawa",
        832439,
        "2314623461342",
        Gender::Female};
    Student mariusz{
        "Mariusz",
        "Kowalski",
        "ul. Zimna 22, 11-100 Kraków",
        657433,
        "1110987654321",
        Gender::Male};
    Student jan{
        "Jan",
        "Nowak",
        "ul. Szkolna 15, 12-100 Poznań",
        192534,
        "9352315879911",
        Gender::Male};
    Student jacek{
        "Jacek",
        "Sztuka",
        "ul. Wesoła 42, 13-100 Szczecin",
        654321,
        "7891234567711",
        Gender::Male};

    db.add(adam);
    db.add(agnieszka);
    db.add(mariusz);
    db.add(jan);
    db.add(jacek);

    db.display();
    std::cout << '\n';
    db.searchSurname("Kowalski");
    return 0;
}