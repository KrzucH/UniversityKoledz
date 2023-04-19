#include "database.hpp"
#include "student.hpp"

int main() {
    Database db;
    Student adam{
        "Jan",
        "Kowalski",
        "ul. Leśna 12, 00-100 Warszawa",
        123456,
        "1234567891011",
        Gender::Male};

    db.add(adam);
    db.display();
    return 0;
}