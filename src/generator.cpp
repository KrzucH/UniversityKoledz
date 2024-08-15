#include "generator.hpp"

size_t Generator::geneGender() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);

    return distrib(rng);
}

std::string Generator::geneMaleName() {
    std::array<std::string, 10> Mnames{"Artur", "Damian", "Pawel", "Rafal", "Dominik", "Jozef", "Kamil", "Robert", "Jan", "Marek"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);

    return Mnames[distrib(rng)];
}

std::string Generator::geneFemaleName() {
    std::array<std::string, 10> Fnames{"Ala", "Dominika", "Paulina", "Krystyna", "Monika", "Kinga", "Joanna", "Anna", "Aleksandra", "Beata"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);

    return Fnames[distrib(rng)];
}

std::string Generator::geneMaleSurname() {
    std::array<std::string, 10> Msurnames{"Wojcik", "Lewandowski", "Zawierucha", "Kowalczyk", "Blasik", "Stuhr", "Koterski", "Woznik", "Szymanski", "Zielinski"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);

    return Msurnames[distrib(rng)];
}

std::string Generator::geneFemaleSurname() {
    std::array<std::string, 10> Fsurnames{"Wojcik", "Lewandowska", "Zawierucha", "Kowalczyk", "Blasik", "Stuhr", "Koterska", "Wozniak", "Szymanska", "Zielinska"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);

    return Fsurnames[distrib(rng)];
}

std::string Generator::geneAdress() {
    std::array<std::string, 14> Adress{
        "ul.Czarna 12, 33-400 Zielona Gora", "ul.Anderssa 13, 21-200 Czestochowa", "ul.Kolorowa 7, 10-200 Warszawa", "ul.Wysoka 40, 40-400 Gdynia",
        "ul.Wielka 50, 78-300 Bydgoszcz", "ul.Mala 33, 99-100 Gdansk", "ul.Swieta 1, 65-100 Wielun", "ul.Wysoka 50, 21-200 Szczecin", "ul.Slowackiego 13, 32-300 Wesola",
        "ul.Boguslawa 13, 56-200 Przemysl", "ul.Smieszna 5, 22-300 Poznan", "ul.Wysoka 88, 98-300 Sieradz", "ul.Biala 100, 32-650 Torun", "ul.Nowakow 77, 41-500 Kosazlin"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 13);

    return Adress[distrib(rng)];
}

std::string Generator::geneMalePesel() {
    std::array<std::string, 10> Mpesel{"71030761957", "03270457615", "06273127699",
                                       "74052073916", "63020367393", "97051871859",
                                       "89082431597", "92012159654", "63061768234",
                                       "02322648654"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);

    return Mpesel[distrib(rng)];
}

std::string Generator::geneFemalePesel() {
    std::array<std::string, 10> Fpesel{"71042337146", "63111916284", "68101537669",
                                       "57072691641", "85010869445", "66062889283",
                                       "70110843442", "86050117884", "83060399648",
                                       "73041626964"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);

    return Fpesel[distrib(rng)];
}

std::string Generator::geneIndex() {
    std::string index;
    for (int i = 0; i <= 5; i++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, 9);
        ;
        index += std::to_string(distrib(rng));
    }

    return index;
}

size_t Generator::geneSalary() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1000, 10000);

    return distrib(rng);
}