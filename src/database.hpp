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
    void loadDataBaseFromaFile(const std::string& baza_txt, Database& baza) {
        std::ifstream str(baza_txt);
        std::string name;
        std::string surname;
        std::string address;
        std::string pesel;
        std::string gender1;
        Gender gender;
        size_t index;

        str >> name >> surname >> address >> index >> pesel >> gender1;
        if (gender1 == "Male") {
            gender = Gender::Male;
        } else {
            gender = Gender::Female;
        }
        for (auto& n : address) {
            if (n == '_') {
                n = ' ';
            }
        }

        Student st(name, surname, address, index, pesel, gender);
        baza.add(st);
    }
};