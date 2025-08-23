# c-learning
## Description
This repository is used to create a personal reference of more advanced C concepts; starting from the base axioms. The tutorials below assume basic knowledge of git. Please refer to a git tutorial via youtube or the official [git documentation](https://docs.github.com/en/get-started/quickstart).

## Disclaimer
The point of this repository is to doucument and create examples. The use of CMAKE is a "quick-and-dirty" setup because learning that tool extensively is not the main point of this repository. Furthermore the logging found in `log.h` and its respective source is just for fun rather than what I necessarily think a proper logging implementation.

# Prerequisites
## MINGW Compiler Installation for Windows 10
See the [instructions](./resources/mingw_install.md) in the resources folder.

## C-Make
Go to: https://cmake.org/download/ and install it. This one is easier than mingw so no handholding here. Only thing to note is that you should ensure to enable adding it to path when prompted.

# Generic Running Instructions
## Quick Commands
### Clean Build Directory
Use me to clean.
  ```
  rm -r ./build && mkdir build && cd ./build
  ```
TODO: Add proper clean method.

### Build Then Run
THEN:
  ```
  cmake .. -G "MinGW Makefiles" -DRUN=1 && mingw32-make && RUN.exe
  ```

## Steps
  1. If D.N.E.: `mkdir build`
  2. `cd ./build`
  3. `cmake .. -G "MinGW Makefiles"`
  4. `mingw32-make`
  5. Run the resultant executable.

# Topics
## Recursion
See file `recursion_with_switch_statements.h` and its source.
To compile and run use:
    > mkdir ./build && cd ./build && cmake .. -G "MinGW Makefiles" -DRUN=1 && mingw32-make && RUN.exe

## Pointers
See file `pointer_usage.h` and it's source.
