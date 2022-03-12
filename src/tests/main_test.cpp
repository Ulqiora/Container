#include "test_array.cpp"
#include "test_map.cpp"
#include "test_multiset.cpp"
#include "test_set.cpp"

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
