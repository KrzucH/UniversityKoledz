#pragma once
#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <memory>
#include <random>
#include <vector>
#include "employee.hpp"
#include "generator.hpp"
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
    Generator generator;

    size_t modifySalary(const std::string& pesel);
    void sortbySalary();

    void menu();
    void baseMenu() const;
    Student makeStudent();
    Employee makeEmployee();
};