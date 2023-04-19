#include "database.hpp"
#include <iostream>

void Database::add(const Student& s) {
    students_.push_back(s);
}

void Database::display() const {
    std::cout << show();
}

std::string Database::show() const {
    std::string result = "";
    for (auto&& student : students_) {
        result += student.show();
    }
    return result;
}

std::vector<Student> Database::searchSurname(const std::string& surname) {
    std::vector<Student> vec;
    std::string female = surname;
    female.erase(female.size() - 1, 1);
    female += "a";
        for (auto&& student : students_ ) {
        if(surname == student.getSurname() || female == student.getSurname()) {
            vec.push_back(student);
            std::cout << vec[vec.size() - 1].show();
        }             
    }
    return vec;
}
