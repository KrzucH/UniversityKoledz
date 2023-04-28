#include "database.hpp"
#include <array>
#include <iostream>

void Database::addStudent(const Student& s) {
    if (Database::Peseltest(s.getPesel()) == true && Database::searchPesel(s.getPesel()) == "") {
        db_.push_back(std::make_shared<Student>(s));
    } else if (Database::Peseltest(s.getPesel()) == false) {
        std::cout << "Podałeś zły pesel.\n";
    } else {
        std::cout << "Student jest już w bazie.\n";
    }
}

void Database::addEmpolyee(const Employee& e) {
    if (Database::Peseltest(e.getPesel()) == true && Database::searchPesel(e.getPesel()) == "") {
        db_.push_back(std::make_shared<Employee>(e));
    } else if (Database::Peseltest(e.getPesel()) == false) {
        std::cout << "Podałeś zły pesel.\n";
    } else {
        std::cout << "Pracownik jest już w bazie.\n";
    }
}

void Database::display() const {
    std::cout << show();
}

std::string Database::show() const {
    std::string result = "";
    for (const auto& person : db_) {
        result += person->show();
    }

    return result;
}

std::vector<std::shared_ptr<Person>> Database::searchSurname(const std::string& surname) {
    std::vector<std::shared_ptr<Person>> vec;

    for (const auto& person : db_) {
        if (surname == person->getSurname()) {
            vec.push_back(person);
            std::cout << vec[vec.size() - 1]->show();
        }
    }
    return vec;
}

std::string Database::searchPesel(const std::string& pesel) {
    std::string pesel1{""};
    for (const auto& person : db_) {
        if (pesel == person->getPesel()) {
            pesel1 = person->show();
            return pesel1;
        }
    }
    return pesel1;
}

void Database::sortByPesel() {
    sort(db_.begin(), db_.end(), [](auto first, auto second) {
        std::string pesel1 = first->getPesel();
        std::string pesel2 = second->getPesel();

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
    sort(db_.begin(), db_.end(), [](auto first, auto second) {
        std::string surname1 = first->getSurname();
        std::string surname2 = second->getSurname();
        return surname1 < surname2;
    });
}

void Database::deleteById(std::string id) {
    db_.erase(std::remove_if(db_.begin(), db_.end(), [id](auto Id_) {
        std::string id1 = Id_->getID();
        return id == id1;
    }));
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
        std::string index;
        std::string checker;
        size_t salary;

        while (str >> checker) {
            if (checker == "S" || checker == "s") {
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
                Student st(name, surname, address, pesel, gender, index);
                baza.addStudent(st);
            } else {
                str >> name >> surname >> address >> salary >> pesel >> gender1;
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
                Employee em(name, surname, address, pesel, gender, salary);
                baza.addEmpolyee(em);
            }
        }
    }
}

void Database::saveDataBaseToFile(const Database& baza) {
    std::fstream baza_txt;
    baza_txt.open("CalaBaza.txt", std::ios::out);
    if (!baza_txt) {
        std::cout << "Blad otwarcia\n";
        exit(1);
    }
    for (const auto& n : baza.db_) {
        baza_txt << n->show();
    }
    baza_txt.close();
}
