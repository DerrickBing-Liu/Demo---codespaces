#include "Horse.h"
#include "TestUtils.h"
#include <gtest/gtest.h>

TEST(HorseTest, GetterReturnsConstructorValues) {
  Horse h("Spirit", 5, "Mustang");
  EXPECT_EQ(h.getName(), "Spirit");
  EXPECT_EQ(h.getAge(), 5);
  EXPECT_EQ(h.getBreed(), "Mustang");
}

TEST(HorseTest, SpeakPrintsNeigh) {
  Horse h("Spirit", 5, "Mustang");
  CoutCapture capture;
  h.speak();
  EXPECT_EQ(capture.str(), "Spirit (Mustang) says: Neigh!\n");
}
