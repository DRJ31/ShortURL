#include "funcs/SnowFlake.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include "funcs/BaseConvert.h"

using namespace shorturl::funcs;

TEST(SnowFlakeTest, nextId) {
    auto *snowFlakeIdWorker = new SnowFlake(0, 0);

    long id;
    for (int i = 0; i < 5; i++) {
        id = snowFlakeIdWorker->nextId();
        std::cout << i << ". ";
        std::cout << "ID: " << id;
        std::cout << " URL: " << BaseConvert<long>::decToBase62(id) << std::endl;
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}