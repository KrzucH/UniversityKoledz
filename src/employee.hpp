#pragma once
#include <iostream>
#include "person.hpp"

class Employee : public Person {
public:
    Employee(const std::string& name,
             const std::string& surname,
             const std::string& street,
             const std::string& pesel,
             const Gender& gender,
             const size_t salary);

    size_t getSala() const override;
    void setSala(const size_t& salary) override;
    
private:
    size_t salary_;
};