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
You can refer to [this page](https://github.com/an-tao/drogon/wiki/CHN-10-%E9%85%8D%E7%BD%AE%E6%96%87%E4%BB%B6). The default scheme of short url is "http://", if you want to change it into "https://", go to `etc/config.json` to change it in `app->scheme`.


## Run application
### Normal Way
Copy `ShortURL`, `etc/` and `static/` to another directory and run `ShortURL`.

### Docker
#### Build image by yourself
Go to `scripts/docker` and run 
```bash
docker build -t shorturl .
``` 
to build the image.

#### Get image from Docker Hub
```bash
docker pull dengrenjie31/shorturl
```
##### Supported Tags
- `v1.0.1`, `latest`
- `v1.0.0`


#### Deployment
The default configuration file is `etc/config.json`. If your configuration is exactly the same as it, you can run the application as below:
```bash
docker run --name shorturl --restart always -p 3000:3000 -d dengrenjie31/shorturl
```

If you want to modify the configuration file, edit the file, put it in a certain path and run the application as below:
```bash
docker run --name shorturl --restart always -p 3000:3000 -v /path/to/config.json:/base/etc -d dengrenjie31/shorturl
```