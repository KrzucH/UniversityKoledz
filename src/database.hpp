#pragma once
#include <algorithm>
#include <fstream>
#include <vector>
#include "student.hpp"
#include "employee.hpp"
#include <memory>

class Database {
public:
    std::vector<Student> students_;
    std::vector<Employee> employees_;
    void addStudent(const Student& s);
    void addEmpolyee(const Employee& e);
    void display() const;
    std::string show() const;
    std::vector<Student> searchSurname(const std::string& surname);
    std::string searchPesel(const std::string& pesel);
    void sortByPesel();
    void sortBySurname();
    void deleteById(std::string id);
    bool Peseltest(std::string pesel);
    void loadDataBaseFromaFile(const std::string& baza_txt, Database& baza);
    void saveDataBaseToFile(const Database& baza);
    std::vector<std::shared_ptr<Person>> db_ {};
};