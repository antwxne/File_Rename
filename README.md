# Rename file by date

Simple GUI tool to rename multiplefiles by creation date (windows) or last modification date (unix system).

## Build

Windows:

```shell
mkdir -p build && cd build && conan install --build=missing ..  && cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build . && cp ../Resources/* ./bin ; cd .. 
```


Unix and MacOS:

```shell
make
```

## Usage