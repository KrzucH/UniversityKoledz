#pragma once
#include <vector>
#include <algorithm>
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
      
};