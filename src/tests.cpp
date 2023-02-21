#include <gtest/gtest.h>
#include "student.hpp"
#include "database.hpp"

TEST(Struct_Check, Task1_and_2){
  Student adam {
    "Jan",
    "Kowalski",
    "ul. Leśna 12, 00-100 Warszawa",
    123456,
    "1234567891011",
    Gender::Male
  };

  Database db;
  // db.add(adam);
  // auto isAdded = db.add(adam);
  EXPECT_TRUE(db.add(adam));
  EXPECT_FALSE(db.add(adam));


}