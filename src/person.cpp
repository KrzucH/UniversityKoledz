#include "person.hpp"
#include <iomanip>
#include <iostream>

Person::Person(
    const std::string& name,
    const std::string& surname,
    const std::string& street,
    const std::string& pesel,
    const Gender& gender)
    : name_(name), surname_(surname), street_(street), pesel_(pesel), gender_(gender) {}

std::string Person::show() const {
    if (getSala() == 0) {
        std::cout << std::setfill(' ') << std::left << "| "<< std::setw(15) << getName() <<  std::setw(20) << getSurname() << std::setw(45) << getStreet() << std::setw(15) << getID() << std::setw(15) << getPesel() << std::setw(15) << "Student" << changeToString(getGender());
    } else {
        std::cout << std::setfill(' ') << std::left << "| " << std::setw(15) << getName() << std::setw(20) << getSurname() << std::setw(45) << getStreet() << std::setw(15) << getID() << std::setw(15) << getPesel() << std::setw(15) << std::to_string(getSala()) << changeToString(getGender());
    }
    return getName() + "; " + getSurname() + "; " + getStreet() + "; " + getID() + "; " + getPesel() + "; " + std::to_string(getSala()) + "; " + changeToString(getGender());
};

std::string Person::getName() const {
    return name_;
};
std::string Person::getSurname() const {
    return surname_;
};
std::string Person::getStreet() const {
    return street_;
};
std::string Person::getPesel() const {
    return pesel_;
};
Gender Person::getGender() const {
    return gender_;
};
std::string Person::getID() const {
    std::string word{"Employee"};
    return word;
}
size_t Person::getSala() const {
    return 0;
}

void Person::setName(const std::string& name) {
    name_ = name;
};
void Person::setSurname(const std::string& surname) {
    surname_ = surname;
};
void Person::setStreet(const std::string& street) {
    street_ = street;
};
void Person::setPesel(const std::string& pesel) {
    pesel_ = pesel;
};
void Person::setGender(const Gender& gender) {
    gender_ = gender;
};
void Person::setID(const std::string& id) {
    std::string error{"No id"};
    error = id;
}
void Person::setSala(const size_t& sala) {
    size_t number{0};
    number = sala;
}