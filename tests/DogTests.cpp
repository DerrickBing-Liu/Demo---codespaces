#include "Dog.h"
#include "TestUtils.h"
#include <gtest/gtest.h>

TEST(DogTest, GetterReturnsConstructorValues) {
  Dog d("Rex", 4, "Labrador");
  EXPECT_EQ(d.getName(), "Rex");
  EXPECT_EQ(d.getAge(), 4);
  EXPECT_EQ(d.getBreed(), "Labrador");
}

TEST(DogTest, SpeakPrintsWoof) {
  Dog d("Rex", 4, "Labrador");
  CoutCapture capture;
  d.speak();
  EXPECT_EQ(capture.str(), "Rex (Labrador) says: Woof!\n");
}

TEST(DogTest, SpeakIsPolymorphicThroughBaseClass) {
  Animal &a = *new Dog("Rex", 4, "Labrador");
  CoutCapture capture;
  a.speak();
  EXPECT_EQ(capture.str(), "Rex (Labrador) says: Woof!\n");
  delete &a;
}
