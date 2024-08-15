#pragma once
#include <array>
#include <random>
#include <string>

class Generator {
public:
    Generator()
        : rng(std::random_device{}()) {}
    size_t geneGender();
    std::string geneMaleName();
    std::string geneFemaleName();
    std::string geneMaleSurname();
    std::string geneFemaleSurname();
    std::string geneMalePesel();
    std::string geneFemalePesel();
    std::string geneAdress();
    std::string geneIndex();
    size_t geneSalary();

private:
    std::mt19937 rng;
};