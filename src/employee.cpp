#include "employee.hpp"

Employee::Employee(const std::string& name,
                   const std::string& surname,
                   const std::string& street,
                   const std::string& pesel,
                   const Gender& gender,
                   const size_t salary)
    : Person(name, surname, street, pesel, gender), salary_(salary) {}

size_t Employee::getSala() const {
   return salary_;
}

void Employee::setSala(const size_t& salary) {
   salary_ = salary;
}

