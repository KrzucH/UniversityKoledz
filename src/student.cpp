#include "student.hpp"

Student::Student(
    std::string name,
    std::string surname,
    std::string street,
    size_t id,
    std::string pesel,
    Gender gender)
    : name_(name), surname_(surname), street_(street), id_(id), pesel_(pesel), gender_(gender) {}

std::string Student::show() const {
    return name_ + " " + surname_ + "; " + street_ + "; " + std::to_string(id_) + "; " + pesel_ + "; " + "Male \n";
};

std::string Student::getName() const {
    return name_;
};
std::string Student::getSurname() const {
    return surname_;
};
std::string Student::getStreet() const {
    return street_;
};
size_t Student::getId() const {
    return id_;
};
std::string Student::getPesel() const {
    return pesel_;
};
Gender Student::getGender() const {
    return gender_;
};

void Student::setName(std::string& name) {
    name = name_;
};
void Student::setSurname(std::string& surname) {
    surname = surname_;
};
void Student::setStreet(std::string& street) {
    street = street_;
};
void Student::setId(size_t& id) {
    id = id_;
};
void Student::setPesel(std::string& pesel) {
    pesel = pesel_;
};
void Student::setGender(Gender& gender) {
    gender = gender_;
};
