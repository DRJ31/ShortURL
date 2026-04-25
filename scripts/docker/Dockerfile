FROM debian:12-slim

WORKDIR /home
RUN apt-get update && apt-get install -y --no-install-recommends \
        ca-certificates git gcc g++ build-essential cmake wget \
        libjsoncpp-dev libssl-dev uuid-dev zlib1g-dev \
        libboost-dev libmariadb-dev libc-ares-dev && \
    git clone https://github.com/DRJ31/ShortURL && cd ShortURL && \
    git submodule update --init --recursive && mkdir build && cd build && \
    cmake .. && make && mkdir /base && mv static etc ShortURL /base && \
    cd /home && rm -rf ShortURL && \
    apt-get purge -y git gcc g++ cpp binutils build-essential cmake wget && \
    apt-get autoremove -y && \
    apt-get clean && rm -rf /var/lib/apt/lists/*
WORKDIR /base
CMD ./ShortURL
