# ShortURL

This is a simple Short URL service, the example site is [uich.cc](https://uich.cc). 

## Installation
### Dependencies
You just need to refer to [this page](https://github.com/an-tao/drogon/wiki/CHN-02-%E5%AE%89%E8%A3%85). But remember that the **boost** library must be installed. In Ubuntu for instance, you should run
```bash
sudo apt install libboost-all-dev
```

### Build
#### Fetch the repository
```bash
git clone https://github.com/DRJ31/ShortURL
```

#### Initialize submodules
```bash
git submodule update --init --recursive
```

#### Build projects
```bash
mkdir build
cd build
cmake ..
make
```

### Configuration
You can refer to [this page](https://github.com/an-tao/drogon/wiki/CHN-10-%E9%85%8D%E7%BD%AE%E6%96%87%E4%BB%B6). The default scheme of short url is "http://", if you want to change it into "https://", go to `src/config.h` to change it and rebuild the project.


## Run application
### Normal Way
Copy `ShortURL`, `config.json` and `static` directory to another directory and run `ShortURL`.

### Docker
#### Build image by yourself
Go to `scripts/docker/http` or `scripts/docker/https` (depends on the protocol of your site) and run 
```bash
docker build -t shorturl .
``` 
to build the image.

#### Get image from Docker Hub
```bash
docker pull dengrenjie31/shorturl
```
##### Supported Tags
- `http`, `latest`
- `https`


#### Deployment
```bash
docker run --name shorturl --restart always -v /path:/base -p 3000:3000 -d dengrenjie31/shorturl
```
