#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArrayHandler.h"


int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}