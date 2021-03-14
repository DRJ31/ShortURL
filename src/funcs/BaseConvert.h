#ifndef SHORTURL_FUNCS_BASECONVERT_H
#define SHORTURL_FUNCS_BASECONVERT_H

#include <string>
#include <stack>

#define B64TABLE "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

namespace shorturl {
namespace funcs {
namespace BaseConvert {
std::string base64Encode(const std::string& str);

std::string base64Decode(const std::string& str);

template <typename T>
std::string decToBase62(T num) {
    int remainder;
    char ch;
    std::string result;
    std::stack<char> resultStack;

    while (num > 0) {
        remainder = num % 62;
        if (remainder < 10) {
            ch = '0' + remainder;
        }
        else if (remainder < 36) {
            ch = 'a' + remainder - 10;
        }
        else {
            ch = 'A' + remainder - 36;
        }
        resultStack.push(ch);
        num /= 62;
    }

    while (!resultStack.empty()) {
        result += resultStack.top();
        resultStack.pop();
    }
    return result;
}

template <typename T>
std::string decToBinary(T num, int bits) {
    int remainder, count = 0;
    std::string result;
    std::stack<char> resultStack;

    while (num > 0) {
        remainder = num % 2 + '0';
        resultStack.push(remainder);
        count++;
        num /= 2;
    }

    // Fill empty bits
    if (count < bits) {
        for (int i = 0; i < bits - count; i++) {
            result += '0';
        }
    }

    while (!resultStack.empty()) {
        result += resultStack.top();
        resultStack.pop();
    }
    return result;
}
}
}
}

#endif //SHORTURL_FUNCS_BASECONVERT_H
