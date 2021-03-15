#include "SnowFlake.h"
#include <cstdio>
#include <ctime>
#include <stdexcept>


namespace shorturl {
namespace funcs {
SnowFlake::SnowFlake(long workerId, long dataCenterId) {
    char message[BUFSIZE];
    const char* strFormat = "%s should not be more than %ld or less than 0.";
    if (workerId > maxWorkerId || workerId < 0) {
        std::sprintf(message, strFormat, "WorkerID", maxWorkerId);
        throw std::out_of_range(message);
    }
    if (dataCenterId > maxDataCenterId || dataCenterId < 0) {
        std::sprintf(message, strFormat, "DataCenterID", maxDataCenterId);
        throw std::out_of_range(message);
    }
    this->workerId = workerId;
    this->dataCenterId = dataCenterId;
}

long SnowFlake::nextId() {
    long timeStamp = timeGen();

    if (timeStamp < lastTimeStamp) {
        throw std::runtime_error("Clock move backwards.");
    }

    if (lastTimeStamp == timeStamp) {
        sequence = (sequence + 1) & sequenceMask;
        if (sequence == 0) {
            timeStamp = tilNextMillis(lastTimeStamp);
        }
    }
    else {
        sequence = 0L;
    }

    lastTimeStamp = timeStamp;

    return ((timeStamp - twepoch) << timeStampLeftShift)
            | (dataCenterId << dataCenterIdShift)
            | (workerId << workerIdShift)
            | sequence;
}

long SnowFlake::timeGen() {
    time_t now = std::time(nullptr);
    return now;
}

long SnowFlake::tilNextMillis(long lastTimestamp) {
    long timeStamp = timeGen();
    while (timeStamp <= lastTimestamp) {
        timeStamp = timeGen();
    }
    return timeStamp;
}
}
}