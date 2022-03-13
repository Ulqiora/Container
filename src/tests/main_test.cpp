#include "test_array.cpp"
#include "test_list.cpp"
#include "test_map.cpp"
#include "test_multiset.cpp"
#include "test_queue.cpp"
#include "test_set.cpp"
#include "test_stack.cpp"
#include "test_vector.cpp"

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
