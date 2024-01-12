#include "lib.h"
#include <gtest/gtest.h>

TEST(TestVersion, ValidVersion)
{
  ASSERT_NE(version(), 100);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
