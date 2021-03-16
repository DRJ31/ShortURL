FROM alpine:3.12

WORKDIR /home
RUN apk add --no-cache git gcc g++ build-base linux-headers cmake wget && \
    apk add --no-cache jsoncpp-dev openssl-dev libuuid zlib-dev boost-dev mariadb-dev c-ares-dev util-linux-dev && \
    wget https://github.com/DRJ31/ShortURL/releases/download/v1.0.0/shorturl-with-submodule.tar.xz && \
    tar xvf shorturl-with-submodule.tar.xz -C / && cd /ShortURL && mkdir build && cd build && \
    cmake .. && make && mkdir /base && mv static etc ShortURL /base && cd / && rm -rf /ShortURL /home/*.tar.xz

WORKDIR /base
CMD ./ShortURL
