#ifndef SHORTURL_FUNCS_BASECONVERT_H
#define SHORTURL_FUNCS_BASECONVERT_H

#include <string>
#include <stack>

namespace shorturl {
namespace funcs {
template <typename T>
class BaseConvert {
public:
    static std::string decToBase62(T num);
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
}
}



#endif //SHORTURL_FUNCS_BASECONVERT_H
