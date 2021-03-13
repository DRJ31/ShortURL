#include "funcs/BaseConvert.h"
#include <gtest/gtest.h>
#include <string>

using namespace shorturl::funcs;

TEST(BaseConvertTest, Base62) {
    std::string str = BaseConvert<long>::decToBase62(1615596859);
    ASSERT_TRUE(str.compare(""));
    EXPECT_STREQ(str.data(), "1LkSxR");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}