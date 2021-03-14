#include "funcs/BaseConvert.h"
#include <gtest/gtest.h>
#include <string>

using namespace shorturl::funcs;

TEST(BaseConvertTest, Base62) {
    std::string str = BaseConvert::decToBase62(1615596859);
    ASSERT_TRUE(str.compare(""));
    EXPECT_STREQ(str.data(), "1LkSxR");
}

TEST(BaseConvertTest, Binary) {
    std::string str = BaseConvert::decToBinary(7, 8);
    ASSERT_TRUE(str.compare(""));
    EXPECT_STREQ(str.data(), "00000111");
}

TEST(BaseConvertTest, Base64Encode) {
    std::string str1 = BaseConvert::base64Encode("1234");
    std::string str2 = BaseConvert::base64Encode("123");
    std::string str3 = BaseConvert::base64Encode("12");
    ASSERT_TRUE(str1.compare(""));
    ASSERT_TRUE(str2.compare(""));
    ASSERT_TRUE(str3.compare(""));
    EXPECT_STREQ(str1.data(), "MTIzNA==");
    EXPECT_STREQ(str2.data(), "MTIz");
    EXPECT_STREQ(str3.data(), "MTI=");
}

TEST(BaseConvertTest, Base64Decode) {
    std::string str1 = BaseConvert::base64Decode("MTIzNA==");
    std::string str2 = BaseConvert::base64Decode("MTIz");
    std::string str3 = BaseConvert::base64Decode("MTI=");
    ASSERT_TRUE(str1.compare(""));
    ASSERT_TRUE(str2.compare(""));
    ASSERT_TRUE(str3.compare(""));
    EXPECT_STREQ(str1.data(), "1234");
    EXPECT_STREQ(str2.data(), "123");
    EXPECT_STREQ(str3.data(), "12");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}