#include "database.hpp"
#include <array>
#include <iostream>

void Database::add(const Student& s) {
    if (Database::Peseltest(s.getPesel()) == true && Database::searchPesel(s.getPesel()) == "") {
        students_.push_back(s);
    } else if (Database::Peseltest(s.getPesel()) == false) {
        std::cout << "Podałeś zły pesel.\n";
    } else {
        std::cout << "Student jest już w bazie.\n";
    }
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

    for (const auto& student : students_) {
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
    std::string pesel1{""};
    for (const auto& student : students_) {
        if (pesel == student.getPesel()) {
            pesel1 = student.show();
            return pesel1;
        }
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

bool Database::Peseltest(std::string pesel) {
    std::array<size_t, 11> arr1{1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    std::array<size_t, 11> arr{};

    size_t size = (std::count_if(pesel.begin(), pesel.end(), [](unsigned char c) { return std::isdigit(c); }));
    if (((size == pesel.size()) && (pesel.size() == 11))) {
        for (int i = 0; i <= arr.size() - 1; i++) {
            arr[i] = pesel[i] - '0';
            // std::cout << arr[i];
        }
        size_t number{};
        for (int i = 0; i <= arr.size() - 1; i++) {
            number += arr1[i] * arr[i];
        }
        if (number % 10 == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void Database::loadDataBaseFromaFile(const std::string& baza_txt, Database& baza) {
    {
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
}

void Database::saveDataBaseToFile(const Database& baza) {
    std::fstream baza_txt;
    baza_txt.open("CalaBaza.txt", std::ios::out);
    if(!baza_txt) {
        std::cout << "Blad otwarcia\n";
        exit(1);
    }
    for (const auto& n : baza.students_) {
        baza_txt << n.show();
    }
    baza_txt.close();
}
