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
    for (auto&& student : students_) {
        if (surname == student.getSurname()) {
            vec.push_back(student);
            std::cout << vec[vec.size() - 1].show();
        }
    }
    if (vec.size() == 0) {
        std::cout << "Nie ma takiej osoby o danym NAZWISKU w bazie danych.";
    }
    return vec;
}

std::vector<Student> Database::searchPesel(const size_t& pesel) {
    std::vector<Student> vec;
    std::string pesel1 = std::to_string(pesel);
    for (auto&& student : students_) {
        if (pesel1 == student.getPesel()) {
            vec.push_back(student);
            std::cout << vec[vec.size() - 1].show();
        }
    }
    if (vec.size() == 0) {
        std::cout << "Nie ma takiej osoby o danym PESELU w bazie danych.";
    }
    return vec;
}

void Database::sortByPesel() {
    std::sort(students_.begin(), students_.end(), [](auto first, auto second) {
        std::string pesel1 = first.getPesel();
        std::string pesel2 = second.getPesel();

        if ((pesel1[0] == '0') || (pesel1[0] == '1')) {
            pesel1 += 1;
        }
        if ((pesel2[0] == '0') || (pesel2[0] == '1')) {
            pesel2 += 1;
        }

        if (pesel1.size() == pesel2.size()) {
            return pesel1 < pesel2;
        } else {
            return pesel1.size() < pesel2.size();
        }

        return pesel1 > pesel2;
    });
    
}
