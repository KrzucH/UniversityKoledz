#include "student.hpp"

Student::Student(
            std::string name, 
            std::string surname, 
            std::string street, 
            size_t id,
            std::string pesel,
            Gender gender)
                : name_(name)
                , surname_(surname)
                , street_(street)
                , id_(id)
                , pesel_(pesel)
                , gender_(gender)
{}

std::string Student::show () const {
    return name_ + " " + surname_ + "; " + street_ + "; " + std::to_string(id_) + "; " + pesel_ + "; " + "Male";

}