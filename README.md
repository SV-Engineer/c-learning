# c-learning
## Description
This repository is used to create a personal reference of more advanced C concepts; starting from the base axioms. The tutorials and examples assume basic knowledge of git. Please refer to a git tutorial via youtube or the official [git documentation](https://docs.github.com/en/get-started/quickstart). The CLI used is git bash. While the instructions here in some cases may work with windows CLI or power-shell, it is expected that most will not without some amount of translation.

## Disclaimer
The point of this repository is to document and create examples. The use of CMAKE is a "quick-and-dirty" setup because learning that tool extensively is not the main point of this repository. Furthermore the logging found in `log.h` and its respective source is just for fun rather than what I necessarily think a proper logging implementation. As it turns out, it is a decent example of using function pointers and macros in tandem.

# Prerequisites
## MINGW Compiler Installation for Windows 10
See the [instructions](./resources/mingw_install.md) in the resources folder.

## C-Make
Go to: https://cmake.org/download/ and install it. This one is easier than mingw so no hand-holding here. Only thing to note is that you should ensure to enable adding it to path when prompted.

# Generic Running Instructions
## Quick Commands
### Clean Build Directory
Use me to clean. Assumes `${cwd}` is `build`.
  ```
  cd .. && rm -r ./build && mkdir build && cd ./build
  ```
TODO: Add proper clean method.

### Build Then Run
THEN:
  ```
  cmake .. -G "MinGW Makefiles" -DRUN=<Integer Here> && mingw32-make && ./RUN.exe
  ```

## Steps
  1. If D.N.E.: `mkdir build`
  2. `cd ./build`
  3. `cmake .. -G "MinGW Makefiles" -DRUN=<Specified RUN=integer>`
  4. `mingw32-make`
  5. Run the resultant executable.

# Topics
## Recursion -- RUN=1
See file `recursion_with_switch_statements.h` and its source.
To compile and run use:
    > mkdir ./build && cd ./build && cmake .. -G "MinGW Makefiles" -DRUN=1 && mingw32-make && ./RUN.exe

## Pointers -- RUN=<TODO>
W.I.P. - See file `pointer_usage.h` and it's source.

## Function Pointers -- RUN=3
Initially it was just meant to enable formal logging, but `log.h` and its related source file seems to show a "flashy" way of using function pointers. I still wouldn't recommend doing what I've done with the logging in a professional environment.

To compile and run use:
    > mkdir ./build && cd ./build && cmake .. -G "MinGW Makefiles" -DRUN=3 && mingw32-make && ./RUN.exe

