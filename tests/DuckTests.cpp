#include "Duck.h"
#include "TestUtils.h"
#include <gtest/gtest.h>

TEST(DuckTest, GetterReturnsConstructorValues) {
  Duck d("Donald", 2, "Mallard");
  EXPECT_EQ(d.getName(), "Donald");
  EXPECT_EQ(d.getAge(), 2);
  EXPECT_EQ(d.getBreed(), "Mallard");
}

TEST(DuckTest, SpeakPrintsQuack) {
  Duck d("Donald", 2, "Mallard");
  CoutCapture capture;
  d.speak();
  EXPECT_EQ(capture.str(), "Donald (Mallard) says: Quack!\n");
}
