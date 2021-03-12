#ifndef SHORTURL_FUNCS_SNOWFLAKE_H
#define SHORTURL_FUNCS_SNOWFLAKE_H
#include <string>

namespace shorturl {
namespace funcs {
class SnowFlake {
public:
    SnowFlake() = default;
    ~SnowFlake() = default;

    std::string getSnowFlake();
};
}
}

#endif // SHORTURL_FUNCS_SNOWFLAKE_H