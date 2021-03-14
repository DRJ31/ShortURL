#include "BaseConvert.h"

namespace shorturl {
namespace funcs {
namespace BaseConvert {
std::string base64Encode(std::string str) {
    std::string binaryStr, result;
    std::string::iterator it;
    int count = 0, idx = 0, tmp;

    // Construct binary string
    it = str.begin();
    while (it != str.end()) {
        binaryStr += decToBinary(*it, 8);
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

std::string base64Decode(std::string str) {
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
        binaryStr += decToBinary(idx, 6);
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
}