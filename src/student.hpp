#pragma once
#include <string>

enum class Gender {
    Male,
    Female
};

class Student {
    public:
        Student(std::string name, 
                std::string surname, 
                std::string street, 
                size_t id,
                std::string pesel,
                Gender gender);

    private:

        Gender g;
};
