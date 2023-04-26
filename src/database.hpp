#pragma once
#include <algorithm>
#include <fstream>
#include <vector>
#include "student.hpp"

class Database {
public:
    std::vector<Student> students_;
    void add(const Student& s);
    void display() const;
    std::string show() const;
    std::vector<Student> searchSurname(const std::string& surname);
    std::string searchPesel(const std::string& pesel);
    void sortByPesel();
    void sortBySurname();
    void deleteById(size_t id);
    bool Peseltest(std::string pesel);
    void loadDataBaseFromaFile(const std::string& baza_txt, Database& baza);
    void saveDataBaseToFile(const Database& baza);
};