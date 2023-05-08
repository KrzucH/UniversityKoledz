#pragma once
#include <algorithm>
#include <fstream>
#include <memory>
#include <vector>
#include "employee.hpp"
#include "student.hpp"

class Database {
public:
    std::vector<std::shared_ptr<Person>> db_{};

    void addStudent(const Student& s);
    void addEmpolyee(const Employee& e);
    void display() const;
    std::string show() const;

    std::vector<std::shared_ptr<Person>> searchSurname(const std::string& surname);
    std::string searchPesel(const std::string& pesel);
    void sortByPesel();
    void sortBySurname();
    void deleteById(std::string id);
    bool Peseltest(std::string pesel);
    void loadDataBaseFromaFile(const std::string& baza_txt, Database& baza);
    void saveDataBaseToFile(const Database& baza);

    Student geneStudent();
    Employee geneEmployee();

    size_t geneGender();
    std::string geneMaleName();
    std::string geneFemaleName();
    std::string geneMaleSurname();
    std::string geneFemaleSurname();
    std::string geneMalePesel();
    std::string geneFemalePesel();
    std::string geneAdress();
    std::string geneIndex();
    size_t geneSalary();
    
    size_t modifySalary(std::string pesel);

    void sortbySalary();
    
};