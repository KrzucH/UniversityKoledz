#pragma once
#include "person.hpp"
#include <string>

class Student : public Person {
public:
    Student(const std::string& name,
            const std::string& surname,
            const std::string& street,
            const std::string& pesel,
            const Gender& gender,
            const std::string& id);

    std::string getID() const override;
    void setID(const std::string& id) override;
    

private:
    std::string id_;
};
