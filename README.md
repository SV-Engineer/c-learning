# c-learning
This repository is used to create a personal reference of more advanced C concepts; starting from the base axioms. The tutorials below assume basic knowledge of git. Please refer to a git tutorial via youtube or the official [git documentation](https://docs.github.com/en/get-started/quickstart).

# Prerequisites
## MINGW Compiler Installation for Windows 10
See the [instructions](./resources/mingw_install.md) in the resources folder.

## C-Make
Go to: https://cmake.org/download/ and install it. This one is easier than mingw so no handholding here. Only thing to note is that you should ensure to enable adding it to path when prompted.

# Running Instructions
  1. `cd ./build`
  2. `cmake .. -G "MinGW Makefiles"`
  3. `mingw32-make`
  4. Run the resultant executable.

# Topics
## Recursion
See file `recursion_with_switch_statements.h` and its source.

## Pointers
See file `pointer_usage.h` and it's source.
