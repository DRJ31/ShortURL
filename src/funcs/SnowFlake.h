#ifndef SHORTURL_FUNCS_SNOWFLAKE_H
#define SHORTURL_FUNCS_SNOWFLAKE_H
#include <string>

#define START_TIME_STAMP 1614556800000L // Start TimeStamp (2021-03-01)

namespace shorturl {
namespace funcs {
class SnowFlake {
public:
    SnowFlake(long wokerId, long dataCenterId);
    ~SnowFlake() = default;

    long nextId();

private:
    // Constants
    const long twepoch = START_TIME_STAMP; // Start Timestamp
    const long workerIdBits = 5L; // Number of Bits of Worker ID
    const long dataCenterIdBits = 5L; // Number of Bits of DataCenter ID
    const long maxWorkerId = -1L ^ (-1L << workerIdBits); // Result should be 31
    const long maxDataCenterId = -1L ^ (-1L << dataCenterIdBits); // Result should be 31
    const long sequenceBits = 12L; // Number of Bits of Sequence ID
    const long workerIdShift = sequenceBits; // Worker ID will be left shift for 12 bits
    const long dataCenterIdShift = sequenceBits + workerIdBits;
    const long timeStampLeftShift = sequenceBits + workerIdBits + dataCenterIdBits;
    const long sequenceMask = -1L ^ (-1L << sequenceBits);

    // Variables
    long workerId, dataCenterId, sequence = 0L, lastTimeStamp = -1L;

    // Functions
    long timeGen();
    long tilNextMillis(long lastTimestamp);
};
}
}

#endif // SHORTURL_FUNCS_SNOWFLAKE_H