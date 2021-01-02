# Read Me Template

> This repository contains files created while learning GTest and GMock

---

### Table of Contents

- [Description](#description)
- [How To Use](#how-to-use)
- [References](#references)

---

## Description

GTest:
GMock:

---

## How To Use

#### Installation
Installing GoogleTest and GoogleMock on Linux (Ubuntu):
1. Download the source files from the [GoogleTest github page](https://github.com/google/googletest) and unzip them.
2. Open a terminal and go to the googletest folder. Let’s say it’s ~/googletest-master
3. Install cmake, if you don’t already have it installed:
```html
    sudo apt install cmake
```
4. Build the project:
```html
    cmake CMakeLists.txt
    make
```
5. Copy all the static libraries into /usr/lib:
```html
    cd lib
    sudo cp * /usr/lib
```
6. Go to the ​ googlemock/include ​ subfolder and copy the entire ​ gmock ​ folder into
/usr/local/include:
```html
    cd googlemock/include
    sudo cp -r gmock /usr/local/include
```
7. Similarly from the project root folder (~/googletest-master) go to googletest/include and copy the entire ​ gtest ​ folder into /usr/local/include
```html
    cd googletest/include
    sudo cp -r gtest /usr/local/include
```
---

## References
1. [GoogleTest Github](https://github.com/google/googletest)


