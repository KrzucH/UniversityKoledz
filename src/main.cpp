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
        "7606567891011",
        Gender::Male};
    Student jacek{
        "Jacek",
        "Sztuka",
        "ul. Wesola 42, 13-100 Szczecin",
        654321,
        "1023234567711",
        Gender::Male};
    Student agnieszka{
        "Agnieszka",
        "Kowalska",
        "ul. Lesna 12, 00-100 Warszawa",
        832439,
        "4501623461342",
        Gender::Female};
    Student mariusz{
        "Mariusz",
        "Kowalski",
        "ul. Zimna 22, 11-100 Krakow",
        657433,
        "0930987654321",
        Gender::Male};
    Student jan{
        "Jan",
        "Nowak",
        "ul. Szkolna 15, 12-100 Poznan",
        192534,
        "9306315879911",
        Gender::Male};
   
    db.add(adam);
    db.add(agnieszka);
    db.add(mariusz);
    db.add(jan);
    db.add(jacek);

    db.display();
    std::cout << '\n';
    db.searchSurname("Kowalski");
    std::cout << '\n';
    db.searchPesel("1023234567711");
    db.sortByPesel();
    db.sortBySurname();
    db.deleteById(654321);
    db.display();
    db.Peseltest("93070704033");
    
    return 0;
}