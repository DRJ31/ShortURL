FROM alpine:3.12

WORKDIR /home
RUN apk add --no-cache git gcc g++ build-base linux-headers cmake wget && \
    apk add --no-cache jsoncpp-dev openssl-dev libuuid zlib-dev boost-dev mariadb-dev c-ares-dev util-linux-dev && \
    git clone https://github.com/DRJ31/ShortURL && cd ShortURL && \
    git submodule update --init --recursive && mkdir build && cd build && \
    cmake .. && make && mkdir /base && mv static etc ShortURL /base && cd / && rm -rf /ShortURL /home/*.tar.xz

WORKDIR /base
CMD ./ShortURL
