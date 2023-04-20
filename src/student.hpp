#pragma once
#include <string>
#include <vector>

enum class Gender {
    Male,
    Female
};

class Student {
public:
    Student(const std::string& name,
            const std::string& surname,
            const std::string& street,
            const size_t& id,
            const std::string& pesel,
            const Gender& gender);

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
