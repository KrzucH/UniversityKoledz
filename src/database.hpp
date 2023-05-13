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
    bool searchPeselTrue_False(const std::string& pesel);
    void sortByPesel();
    void sortBySurname();
    void deleteById(const std::string& id);
    bool Peseltest(const std::string& pesel);
    void loadDataBaseFromaFile(const std::string& baza_txt);
    void saveDataBaseToFile();

    Student geneStudent();
    Employee geneEmployee();

    size_t geneGender();
    std::string geneMaleName() const;
    std::string geneFemaleName() const;
    std::string geneMaleSurname() const;
    std::string geneFemaleSurname() const;
    std::string geneMalePesel() const;
    std::string geneFemalePesel() const;
    std::string geneAdress() const;
    std::string geneIndex() const;
    size_t geneSalary() const;

    size_t modifySalary(const std::string& pesel);
    void sortbySalary();

    void menu();
    void baseMenu() const;
    Student makeStudent();
    Employee makeEmployee();
};