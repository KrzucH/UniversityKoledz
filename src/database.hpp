#pragma once
#include <vector>
#include <algorithm>
#include "student.hpp"

class Database {
public:
    void add(const Student& s);
    void display() const;
    std::string show() const;
    std::vector<Student> searchSurname(const std::string& surname);
    std::vector<Student> searchPesel(const size_t& pesel);
    void sortByPesel() const;

private:
    bool isAdded_ = false;
    std::vector<Student> students_;
};