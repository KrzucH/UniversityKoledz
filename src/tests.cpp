#include <gtest/gtest.h>
#include "student.hpp"
#include "database.hpp"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

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
  db.add(adam);

}