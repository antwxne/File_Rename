# CPP_Template
Template repository for C++ project using Conan

## Build

Windows:

```shell
mkdir -p build && cd build && conan install .. --build=missing && cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build . --target a.out ; cd .. 
```

Unix and MacOS:

```shell
make
```


## Tests

Windows:

```shell
mkdir -p build && cd build && conan install .. --build=missing && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release .. && cmake --build . --target unit_tests ; cd ..
```

Unix and MacOS:

```shell
make tests_run
```