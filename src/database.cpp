#include "database.hpp"

void Database::addStudent(const Student& s) {
    if (Database::Peseltest(s.getPesel()) && !Database::searchPeselTrue_False(s.getPesel())) {
        db_.push_back(std::make_shared<Student>(s));
    }
}

void Database::addEmpolyee(const Employee& e) {
    if (Database::Peseltest(e.getPesel()) && !Database::searchPeselTrue_False(e.getPesel())) {
        db_.push_back(std::make_shared<Employee>(e));
    }
}

void Database::display() const {
    baseMenu();
    show();
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

            vec[vec.size() - 1]->show();
        }
    }
    return vec;
}

bool Database::searchPeselTrue_False(const std::string& pesel) {
    for (const auto& person : db_) {
        if (pesel == person->getPesel()) {
            return true;
        }
    }
    return false;
}

std::string Database::searchPesel(const std::string& pesel) {
    std::string pesel1{""};
    for (const auto& person : db_) {
        if (pesel == person->getPesel()) {
            std::cout << "1. ";
            pesel1 = person->show();
            return pesel1;
        }
    }
    return pesel1;
}

void Database::sortByPesel() {
    // std::sort()
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

void Database::deleteById(const std::string& id) {
    db_.erase(std::remove_if(db_.begin(), db_.end(), [id](auto ID) {
                  std::string index = ID->getID();
                  return id == index;
              }),
              db_.end());
}

bool Database::Peseltest(const std::string& pesel) {
    std::array<size_t, 11> arr1{1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    std::array<size_t, 11> arr{};

    size_t size = (std::count_if(pesel.begin(), pesel.end(), [](unsigned char c) { return std::isdigit(c); }));
    if (((size == pesel.size()) && (pesel.size() == 11))) {
        for (int i = 0; i <= arr.size() - 1; i++) {
            arr[i] = pesel[i] - '0';
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

void Database::loadDataBaseFromaFile(const std::string& baza_txt) {
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
                addStudent(st);
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
                addEmpolyee(em);
            }
        }
    }
}

void Database::saveDataBaseToFile() {
    std::fstream baza_txt;
    baza_txt.open("CalaBaza.txt", std::ios::out);
    if (!baza_txt) {
        std::cout << "Blad otwarcia\n";
        exit(1);
    }
    for (const auto& n : db_) {
        baza_txt << n->show();
    }
    baza_txt.close();
}

Student Database::geneStudent() {
    if (generator.geneGender() == 1) {
        Student student{generator.geneMaleName(), generator.geneMaleSurname(), generator.geneAdress(), generator.geneMalePesel(), Gender::Male, generator.geneIndex()};
        addStudent(student);
        return student;
    } else {
        Student student{generator.geneFemaleName(), generator.geneFemaleSurname(), generator.geneAdress(), generator.geneFemalePesel(), Gender::Female, generator.geneIndex()};
        addStudent(student);
        return student;
    }
}

Employee Database::geneEmployee() {
    if (generator.geneGender() == 1) {
        Employee employee{generator.geneMaleName(), generator.geneMaleSurname(), generator.geneAdress(), generator.geneMalePesel(), Gender::Male, generator.geneSalary()};
        addEmpolyee(employee);
        return employee;
    } else {
        Employee employee{generator.geneFemaleName(), generator.geneFemaleSurname(), generator.geneAdress(), generator.geneFemalePesel(), Gender::Female, generator.geneSalary()};
        addEmpolyee(employee);
        return employee;
    }
}

size_t Database::modifySalary(const std::string& pesel) {
    size_t salary{0};
    if (Peseltest(pesel) == true) {
        for (auto n : db_) {
            if (n->getPesel() == pesel) {
                if (n->getID() == "Employee") {
                    std::cout << "Podaj zarobki dla " << n->getName() << " " << n->getSurname() << " o numerze PESEL " << n->getPesel() << ": ";
                    std::cin >> salary;
                    n->setSala(salary);
                    return salary;
                }
            }
        }
    }
    return salary;
}

void Database::sortbySalary() {
    sort(db_.begin(), db_.end(), [](auto first, auto second) {
        size_t salary1 = first->getSala();
        size_t salary2 = second->getSala();
        return salary1 > salary2;
    });
}

void Database::menu() {
    int choose;
    char repeat;
    std::string searcher;
    std::string delIndex_fileName;
    size_t size = db_.size();

    system("clear");
    std::cout << std::setfill('*') << std::setw(50) << "*"
              << "{ Witaj w BazieDanych - Koledz }****************************************" << '\n';
    std::cout << "\n";
    std::cout << std::setfill(' ') << std::setw(50) << ' '
              << "1. Wyswietl cala baze danych.\n";
    std::cout << std::setw(50) << ' '
              << "2. Dodaj Studenta.\n";
    std::cout << std::setw(50) << ' '
              << "3. Dodaj Pracownika. \n";
    std::cout << std::setw(50) << ' '
              << "4. Wyszukaj po nazwisku. \n";
    std::cout << std::setw(50) << ' '
              << "5. Wyszukaj po numerze PESEL. \n";
    std::cout << std::setw(50) << ' '
              << "6. Sortuj po numerze PESEL. \n";
    std::cout << std::setw(50) << ' '
              << "7. Sortuj po nazwisku. \n";
    std::cout << std::setw(50) << ' '
              << "8. Usuwanie po numerze indeksu. \n";
    std::cout << std::setw(50) << ' '
              << "9. Dodaj losowego studenta. \n";
    std::cout << std::setw(50) << ' '
              << "10. Dodaj losowego pracownika. \n";
    std::cout << std::setw(50) << ' '
              << "11. Modyfikacja zarobków. \n";
    std::cout << std::setw(50) << ' '
              << "12. Sortowanie po zarobkach. \n";
    std::cout << std::setw(50) << ' '
              << "13. Dodaj baze danych z pliku. \n";
    std::cout << std::setw(50) << ' '
              << "14. Zapis bazy danych do pliku. \n";

    std::cout << "\nWybierz cyfre lub nacisnij dowolny klawisz aby zakonczyc:";

    std::cin >> choose;
    switch (choose) {
    case 1:

        display();
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;
    case 2:
        system("clear");
        makeStudent();
        if (size != db_.size()) {
            std::cout << "\nDodano studenta!!!\n";
        } else {
            std::cout << "\nNie dodano studenta!!! Podaj prawidlowe dane!!!\n";
        }
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;
    case 3:
        system("clear");
        makeEmployee();
        if (size != db_.size()) {
            std::cout << "\nDodano pracownika!!!\n";
        } else {
            std::cout << "\nNie dodano pracownika!!! Podaj prawidlowe dane!!!\n";
        }
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;
    case 4:
        system("clear");
        std::cout << "Wpisz nazwisko:";
        std::cin >> searcher;
        baseMenu();
        searchSurname(searcher);
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;

    case 5:
        system("clear");
        std::cout << "Wpisz PESEL:";
        std::cin >> searcher;
        baseMenu();
        searchPesel(searcher);
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;

    case 6:
        system("clear");
        sortByPesel();
        baseMenu();
        display();
        std::cout << "\nPosortowane po numerze PESEL!!!\n";
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;
    case 7:
        system("clear");
        sortBySurname();
        baseMenu();
        display();
        std::cout << "\nPosortowane po Nazwisku!!!\n";
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;

    case 8:
        system("clear");
        std::cout << "Podaj numer Indexu studenta aby go usunac:";
        std::cin >> delIndex_fileName;
        deleteById(delIndex_fileName);
        if (size != db_.size()) {
            std::cout << "\nStudent usuniety!!!\n";
        } else {
            std::cout << "\nPodales zly index!!!!\n";
        }
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;
    case 9:
        system("clear");
        geneStudent();
        std::cout << "\nDodano losowego studenta!!!!\n";
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;
    case 10:
        system("clear");
        geneEmployee();
        std::cout << "\nDodano losowego pracownika!!!!\n";
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;
    case 11:
        system("clear");
        std::cout << "Wpisz PESEL pracownika:";
        std::cin >> searcher;
        if (!modifySalary(searcher)) {
            std::cout << "\nPodales zly PESEL!!!\n";
        } else {
            std::cout << "\nZmieniono zarobki!!!\n";
        }
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;
    case 12:
        system("clear");
        sortbySalary();
        baseMenu();
        display();
        std::cout << "\nPosortowane po Zarobkach!!!\n";
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;
    case 13:
        system("clear");
        std::cout << "Podaj nazwe pliku:";
        std::cin >> delIndex_fileName;
        delIndex_fileName += ".txt";
        loadDataBaseFromaFile(delIndex_fileName);
        if (db_.size() != size) {
            std::cout << "\nDodano bazę!!!\n";
        } else {
            std::cout << "\nPodales zla nazwe, lub podana baza nie istnieje!!!";
        }
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;

    case 14:
        system("clear");
        saveDataBaseToFile();
        system("clear");
        std::cout << "\nCala baza zostala zapisana na dysku!!!!\n";
        std::cout << "\nPowrót do Menu nacisnij 'y' lub nacisnij dowolny klawisz aby zakonczyc:";
        std::cin >> repeat;
        if (repeat == 'y' || repeat == 'Y') {
            return menu();
        } else
            break;

    default:
        break;
    }
}

void Database::baseMenu() const {
    system("clear");

    std::cout << "  "
              << "{NAME}"
              << "        "
              << "{SURNAME}"
              << "                    "
              << "{STREET}"
              << "                             "
              << "{INDEX}"
              << "         "
              << "{PESEL}"
              << "      "
              << "{SALARY}"
              << "       "
              << "{GENDER}";
    std::cout << "\n\n";
}

Student Database::makeStudent() {
    std::string name;
    std::string surname;
    std::string fullstreet{"ul."};
    std::string street;
    std::string index;
    std::string pesel;
    std::string gender;
    Gender gender1;

    std::cout << "Imie studenta:";
    std::cin >> name;
    std::cout << "Nazwisko studenta:";
    std::cin >> surname;
    std::cout << "Podaj ulice:";
    std::cin >> street;
    fullstreet += street + " ";
    std::cout << "Podaj numer mieszkania/domu:";
    std::cin >> street;
    fullstreet += street + ", ";
    std::cout << "Podaj kod pocztowy:";
    std::cin >> street;
    fullstreet += street + " ";
    std::cout << "Podaj miasto:";
    std::cin >> street;
    fullstreet += street;
    std::cout << "Index:";
    std::cin >> index;
    std::cout << "PESEL:";
    std::cin >> pesel;
    std::cout << "Plec Male/Female:";
    std::cin >> gender;
    if (gender == "Male" || gender == "male") {
        gender1 = Gender::Male;
    } else {
        gender1 = Gender::Female;
    }

    Student student{name, surname, fullstreet, pesel, Gender::Male, index};
    addStudent(student);

    return student;
}

Employee Database::makeEmployee() {
    std::string name;
    std::string surname;
    std::string fullstreet{"ul."};
    std::string street;
    size_t salary;
    std::string pesel;
    std::string gender;
    Gender gender1;

    std::cout << "Imie:";
    std::cin >> name;
    std::cout << "Nazwisko:";
    std::cin >> surname;
    std::cout << "Podaj ulice:";
    std::cin >> street;
    fullstreet += street + " ";
    std::cout << "Podaj numer mieszkania/domu:";
    std::cin >> street;
    fullstreet += street + ", ";
    std::cout << "Podaj kod pocztowy:";
    std::cin >> street;
    fullstreet += street + " ";
    std::cout << "Podaj miasto:";
    std::cin >> street;
    fullstreet += street;
    std::cout << "Salary:";
    std::cin >> salary;
    std::cout << "PESEL:";
    std::cin >> pesel;
    std::cout << "Plec Male/Female:";
    std::cin >> gender;
    if (gender == "Male" || gender == "male") {
        gender1 = Gender::Male;
    } else {
        gender1 = Gender::Female;
    }

    Employee employee{name, surname, fullstreet, pesel, Gender::Male, salary};
    addEmpolyee(employee);

    return employee;
}
