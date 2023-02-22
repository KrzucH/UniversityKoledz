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

        std::string show() const;
    private:
        std::string name_; 
        std::string surname_;
        std::string street_; 
        size_t id_;
        std::string pesel_;
        Gender gender_;


        
};
