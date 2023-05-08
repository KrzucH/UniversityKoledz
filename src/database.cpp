#include "database.hpp"
#include <array>
#include <iostream>
#include <random>

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

size_t Database::geneGender() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);
    size_t random_index = distrib(gen);

    return random_index;
}

Student Database::geneStudent() {
    if (geneGender() == 1) {
        Student student{geneMaleName(), geneMaleSurname(), geneAdress(), geneMalePesel(), Gender::Male, geneIndex()};
        addStudent(student);
        return student;
    } else {
        Student student{geneFemaleName(), geneFemaleSurname(), geneAdress(), geneFemalePesel(), Gender::Female, geneIndex()};
        addStudent(student);
        return student;
    }
}

Employee Database::geneEmployee() {
    if (geneGender() == 1) {
        Employee employee{geneMaleName(), geneMaleSurname(), geneAdress(), geneMalePesel(), Gender::Male, geneSalary()};
        addEmpolyee(employee);
        return employee;
    } else {
        Employee employee{geneFemaleName(), geneFemaleSurname(), geneAdress(), geneFemalePesel(), Gender::Female, geneSalary()};
        addEmpolyee(employee);
        return employee;
    }
}

std::string Database::geneMaleName() {
    std::array<std::string, 10> Mnames{"Artur", "Damian", "Paweł", "Rafał", "Dominik", "Józef", "Kamil", "Robert", "Jan", "Marek"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    int random_index = distrib(gen);
    return Mnames[random_index];
}

std::string Database::geneFemaleName() {
    std::array<std::string, 10> Fnames{"Ala", "Dominika", "Paulina", "Krystyna", "Monika", "Kinga", "Joanna", "Anna", "Aleksandra", "Beata"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    int random_index = distrib(gen);
    return Fnames[random_index];
}

std::string Database::geneMaleSurname() {
    std::array<std::string, 10> Msurnames{"Wójcik", "Lewandowski", "Zawierucha", "Kowalczyk", "Błasik", "Stuhr", "Koterski", "Woznik", "Szymanski", "Zielinski"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    int random_index = distrib(gen);
    return Msurnames[random_index];
}

std::string Database::geneFemaleSurname() {
    std::array<std::string, 10> Fsurnames{"Wójcik", "Lewandowska", "Zawierucha", "Kowalczyk", "Błasik", "Stuhr", "Koterska", "Wozniak", "Szymanska", "Zielinska"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    int random_index = distrib(gen);
    return Fsurnames[random_index];
}

std::string Database::geneAdress() {
    std::array<std::string, 14> Adress{
        "ul.Czarna 12, 33-400 Zielona Gora", "ul.Anderssa 13, 21-200 Czestochowa", "ul. Kolorowa 7, 10-200 Warszawa", "ul.Wysoka 40, 40-400 Gdynia",
        "ul.Wielka 50, 78-300 Bydgoszcz", "ul.Mala 33, 99-100 Gdansk", "ul.Swieta 1, 65-100 Wielun", "ul.Wysoka 50, 21-200 Szczecin", "ul.Slowackiego 13, 32-300 Wesola",
        "ul.Boguslawa 13, 56-200 Przemysl", "ul.Smieszna 5, 22-300 Poznan", "ul.Wysoka 88, 98-300 Sieradz", "ul.Biala 100, 32-650 Torun", "ul.Nowakow 77, 41-500 Kosazlin"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 13);
    int random_index = distrib(gen);
    return Adress[random_index];
}

std::string Database::geneMalePesel() {
    std::array<std::string, 10> Mpesel{"71030761957", "03270457615", "06273127699",
                                       "74052073916", "63020367393", "97051871859",
                                       "89082431597", "92012159654", "63061768234",
                                       "02322648654"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    int random_index = distrib(gen);
    return Mpesel[random_index];
}

std::string Database::geneFemalePesel() {
    std::array<std::string, 10> Fpesel{"71042337146", "63111916284", "68101537669",
                                       "57072691641", "85010869445", "66062889283",
                                       "70110843442", "86050117884", "83060399648",
                                       "73041626964"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    int random_index = distrib(gen);
    return Fpesel[random_index];
}

std::string Database::geneIndex() {
    std::string index;
    for (int i = 0; i <= 5; i++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, 9);
        int random_index = distrib(gen);
        index += std::to_string(random_index);
    }

    return index;
}

size_t Database::geneSalary() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1000, 10000);
    size_t salary = distrib(gen);

    return salary;
}

size_t Database::modifySalary(std::string pesel) {
    size_t salary{0};
    if (Peseltest(pesel) == true) {
        for (auto n : db_) {
            if (n->getPesel() == pesel) {
                if (n->getID() == "No Index") {
                    std::cout << "Podaj zarobki dla " << n->getName() << " " << n -> getSurname() << " o numrze PESEL " << n -> getPesel() << ": "   ;
                    std::cin >> salary;
                    n->setSala(salary);
                    return salary;
                }
            }
        }
    }
    return salary;
}
