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

    std::string getName () const;
    std::string getSurname () const;
    std::string getStreet () const;
    size_t getId () const;
    std::string getPesel () const;
    Gender getGender () const;

    void setName(const std::string& name);
    void setSurname(const std::string& surname);
    void setStreet(const std::string& street); 
    void setId(const size_t& id); 
    void setPesel(const std::string& pesel); 
    void setGender(const Gender& gender); 
     
private:
    std::string name_;
    std::string surname_;
    std::string street_;
    size_t id_;
    std::string pesel_;
    Gender gender_;
};
