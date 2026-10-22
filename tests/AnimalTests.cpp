#include "Animal.h"
#include "TestUtils.h"
#include <gtest/gtest.h>

TEST(AnimalTest, GetterReturnsConstructorValues) {
  Animal a("Cat", 3);
  EXPECT_EQ(a.getName(), "Cat");
  EXPECT_EQ(a.getAge(), 3);
}

TEST(AnimalTest, SpeakPrintsGenericSound) {
  Animal a("Cat", 3);
  CoutCapture capture;
  a.speak();
  EXPECT_EQ(capture.str(), "Cat makes a sound.\n");
}
