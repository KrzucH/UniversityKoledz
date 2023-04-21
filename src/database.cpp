#include "database.hpp"
#include <array>
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

std::string Database::searchPesel(const std::string& pesel) {
    std::string pesel1;
    for (auto&& student : students_) {
        if (pesel == student.getPesel()) {
            pesel1 = student.show();
            std::cout << pesel1 << '\n';
        }
    }
    if (pesel1 == "") {
        std::cout << "Nie ma takiego osoby o danym PESEL w bazie danych.\n";
    }
    return pesel1;
}

void Database::sortByPesel() {
    sort(students_.begin(), students_.end(), [](auto first, auto second) {
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

void Database::sortBySurname() {
    sort(students_.begin(), students_.end(), [](auto first, auto second) {
        std::string surname1 = first.getSurname();
        std::string surname2 = second.getSurname();
        return surname1 < surname2;
    });
}

void Database::deleteById(size_t id) {
    int i = 0;
    for (const auto& n : students_) {
        if (id == n.getId()) {
            auto it = students_.begin() + i;
            students_.erase(it);
        }
        i++;
    }
}

void Database::Peseltest(std::string pesel) {
    std::array<size_t, 11> arr1{1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    std::array<size_t, 11> arr{};
    if (pesel[0] == '0') {
        pesel.erase(pesel.begin());

    } else {
        for (int i = 0; i <= arr.size() - 1; i++) {
            arr[i] = pesel[i] - '0';
            // std::cout << arr[i];
        }
        size_t number {};
        for (int i = 0; i <=arr.size() - 1; i++) {
            number += arr1[i] * arr[i];            
        }
        if(number % 10 == 0){
            std::cout << "Podałeś dobry Pesel\n";
        }
    }   
}