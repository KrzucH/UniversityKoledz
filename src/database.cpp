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
    for (auto&& student : students_ ) {
        if(surname == student.getSurname()) {
            vec.push_back(student);
            std::cout << vec[vec.size() - 1].show();
        }             
    }
    if(vec.size() == 0) {
        std::cout << "Nie ma takiej osoby o danym NAZWISKU w bazie danych.";
    }
    return vec;
}

std::vector<Student> Database::searchPesel(const size_t& pesel) {
    std::vector<Student> vec;
    std::string pesel1 = std::to_string(pesel);
    for(auto&& student : students_) {
        if(pesel1 == student.getPesel()) {
            vec.push_back(student);
            std::cout << vec[vec.size() - 1].show();
        }
    }
    if(vec.size() == 0) {
        std::cout << "Nie ma takiej osoby o danym PESELU w bazie danych.";
    }
    return vec;
}

void Database::sortByPesel() const {
    // std::stable_sort(students_.begin(), students_.end());

   for(auto&& n : students_) {
        std::string num = n.getPesel();
        num.erase(num.begin() + 4, num.end());
        for(int i = 0; i <= students_.size(); i++) {
            std::string num2 = students_[i].getPesel();
            num2.erase(num2.begin() + 4, num2.end());
        }
   }
}
