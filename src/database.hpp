#pragma once
#include <vector>
#include "student.hpp"

class Database {
public:
    void add(const Student& s);
    void display() const;
    std::string show() const;
    std::vector<Student> searchSurname(const std::string& surname);

private:
    bool isAdded_ = false;
    std::vector<Student> students_;
};