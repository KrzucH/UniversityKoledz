#include <iostream>
#include "database.hpp"
#include "employee.hpp"
#include "person.hpp"
#include "student.hpp"

int main() {
    Database db;
    Student adam{
        "Adam",
        "Kowalski",
        "ul.Lesna 12, 00-100 Warszawa",
        "89010595928",
        Gender::Male,
        "123456"};
    Student jacek{
        "Jacek",
        "Sztuka",
        "ul.Wesola 42, 13-100 Szczecin",
        "00270441882",
        Gender::Male,
        "654321"};
    Student agnieszka{
        "Agnieszka",
        "Kowalska",
        "ul.Lesna 12, 00-100 Warszawa",
        "99021158692",
        Gender::Female,
        "832439"};
    Employee mariusz{
        "Mariusz",
        "Kowalski",
        "ul.Zimna 22, 11-100 Krakow",
        "72011953343",
        Gender::Male,
        1657};
    Student jan{
        "Jan",
        "Nowak",
        "ul.Szkolna 15, 12-100 Poznan",
        "61112192856",
        Gender::Male,
        "192534"};
    Employee janusz{
        "Adam",
        "Kowalski",
        "ul.Lesna 12, 00-100 Warszawa",
        "89010595928",
        Gender::Male,
        3456};
    Employee ewa{
        "Adam",
        "Kowalski",
        "ul.Lesna 12, 00-100 Warszawa",
        "8901059528",
        Gender::Male,
        2500};
    db.addStudent(adam);
    db.addStudent(agnieszka);
    db.addEmpolyee(mariusz);
    db.addStudent(jan);
    db.addStudent(jacek);
    db.addEmpolyee(janusz);
    db.addEmpolyee(ewa);

    db.loadDataBaseFromaFile("Baza.txt", db);
    db.display();
    std::cout <<'\n';
    db.show();
    // std::cout << "\n";
    db.saveDataBaseToFile(db);
    // std::cout << '\n';
    db.searchSurname("Kowalski");
    std::cout << '\n';
    std::cout << db.searchPesel("89010595928");
    db.sortByPesel();
    db.sortBySurname();
    db.deleteById("654321");
    std::cout << '\n';
    db.display();
     return 0;
}