#pragma once
#include <string>
#include <vector>

enum class Gender {
    Male,
    Female
};
constexpr const char* changeToString(Gender gender) noexcept {
    switch (gender) {
    case Gender::Female:
        return "Female \n";
    case Gender::Male:
        return "Male \n";
    }
}

class Person {
public:
    Person(const std::string& name,
            const std::string& surname,
            const std::string& street,
            const std::string& pesel,
            const Gender& gender);

    virtual ~Person() = default;

    std::string show() const;

    std::string getName() const;
    std::string getSurname() const;
    std::string getStreet() const;
    std::string getPesel() const;
    Gender getGender() const;
    std::string virtual getID() const;
    size_t virtual getSala() const;

    void setName(const std::string& name);
    void setSurname(const std::string& surname);
    void setStreet(const std::string& street);
    void setPesel(const std::string& pesel);
    void setGender(const Gender& gender);
    void virtual setID(const std::string& id);
    void virtual setSala(const size_t& salary);

private:
    std::string name_;
    std::string surname_;
    std::string street_;
    std::string pesel_;
    Gender gender_;
};