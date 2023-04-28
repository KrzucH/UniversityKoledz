#include "student.hpp"

Student::Student(const std::string& name,
                 const std::string& surname,
                 const std::string& street,
                 const std::string& pesel,
                 const Gender& gender,
                 const std::string& id)
    : Person(name, surname, street, pesel, gender), id_(id) {}

std::string Student::getID() const {
    return id_;
}

void Student::setID(const std::string& id) {
    id_ = id;
}


