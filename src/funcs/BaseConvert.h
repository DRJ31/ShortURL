#ifndef SHORTURL_FUNCS_BASECONVERT_H
#define SHORTURL_FUNCS_BASECONVERT_H

#include <string>
#include <stack>

#define B64TABLE "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

namespace shorturl {
namespace funcs {
template <typename T>
class BaseConvert {
public:
    static std::string decToBase62(T num);
    static std::string decToBinary(T num, int bits);
    static std::string base64Encode(std::string str);
    static std::string base64Decode(std::string str);
};

template <typename T>
std::string BaseConvert<T>::decToBase62(T num) {
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
std::string BaseConvert<T>::decToBinary(T num, int bits) {
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

template <typename T>
std::string BaseConvert<T>::base64Encode(std::string str) {
    std::string binaryStr, result;
    std::string::iterator it;
    int count = 0, idx = 0, tmp;

    // Construct binary string
    it = str.begin();
    while (it != str.end()) {
        binaryStr += BaseConvert<char>::decToBinary(*it, 8);
        it++;
    }

    // Convert binary string to Base64 string
    it = binaryStr.begin();
    while (it != binaryStr.end()) {
        if (count < 6) {
            tmp = *it - '0';
            for (int i = 0; i < 5 - count; i++) {
                tmp *= 2;
            }
            idx += tmp;
            count++;
            it++;
        }
        else {
            result += B64TABLE[idx];
            count = 0;
            idx = 0;
        }
    }

    if (idx > 0 || count > 0) {
        result += B64TABLE[idx];
        idx = 0;
        count = 0;
    }

    // Check the tail of Base64
    if (binaryStr.size() % 24 >= 12) {
        result += "=";
    }
    else if (binaryStr.size() % 24 >= 6) {
        result += "==";
    }

    return result;
}

template <typename T>
std::string BaseConvert<T>::base64Decode(std::string str) {
    std::string binaryStr, result;
    std::string::iterator it;
    int count = 0, ascii = 0, tmp, idx;

    // Get binary string of Base64 string
    it = str.begin();
    while (it != str.end() && *it != '=') {
        idx = 0;
        for (char ch : B64TABLE) {
            if (ch == *it) break;
            idx++;
        }
        binaryStr += BaseConvert<int>::decToBinary(idx, 6);
        it++;
    }

    // Convert binary string to original string
    it = binaryStr.begin();
    while (it != binaryStr.end()) {
        if (count < 8) {
            tmp = *it - '0';
            for (int i = 0; i < 7 - count; i++) {
                tmp *= 2;
            }
            ascii += tmp;
            count++;
            it++;
        }
        else {
            result += static_cast<char>(ascii);
            ascii = 0;
            count = 0;
        }
    }
    if (ascii > 0) {
        result += static_cast<char>(ascii);
    }
    return result;
}
}
}

#endif //SHORTURL_FUNCS_BASECONVERT_H
