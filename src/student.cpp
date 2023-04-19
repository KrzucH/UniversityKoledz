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

void Student::setName(const std::string& name) {
    name_ = name;
};
void Student::setSurname(const std::string& surname) {
    surname_ = surname;
};
void Student::setStreet(const std::string& street) {
    street_ = street;
};
void Student::setId(const size_t& id) {
    id_ = id;
};
void Student::setPesel(const std::string& pesel) {
    pesel_ = pesel;
};
void Student::setGender(const Gender& gender) {
    gender_ = gender;
};
