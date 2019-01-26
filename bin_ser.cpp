#include <gtest/gtest.h>
#include <iostream>

using namespace std;

int bin_search(int data);

TEST(bin_serch_test, get_20) { EXPECT_EQ(bin_search(20), 1); }
TEST(bin_serch_test, get_0) { EXPECT_EQ(bin_search(00), 0); }
TEST(bin_serch_test, get_100) { EXPECT_EQ(bin_search(100), 0); }
TEST(bin_serch_test, get_30) { EXPECT_EQ(bin_search(30), 1); }
TEST(bin_serch_test, get_10) { EXPECT_EQ(bin_search(10), 1); }
TEST(bin_serch_test, get_40) { EXPECT_EQ(bin_search(40), 1); }
TEST(bin_serch_test, get_50) { EXPECT_EQ(bin_search(50), 1); }
TEST(bin_serch_test, get_60) { EXPECT_EQ(bin_search(60), 1); }
TEST(bin_serch_test, get_70) { EXPECT_EQ(bin_search(70), 1); }

int bin_search(int data) {
  int arr[] = {10, 20, 30, 40, 50, 60, 70};
  int high = sizeof(arr) / sizeof(int) - 1;
  int low = 0;
  int mid = 1;

  while (high >= low) {

    cout << high << " " << low << " " << mid << endl;

    mid = (high + low) / 2;

    if (arr[mid] == data) {
      cout << "found" << endl;
      return 1;
    }
    if (arr[mid] > data)
      high = mid - 1;
    if (arr[mid] <= data)
      low = mid + 1;
  }

  return 0;
}

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
