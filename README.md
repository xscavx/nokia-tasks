# nokia-tasks
Solution of test tasks for C/C++ developers before applying for a technical interview in Nokia

### Development
Requirements
* clang version 11.0.0 or higher
* CMake version 3.20 or higher
* GTest version 1.10 or higher

How to build and run tests:
* `cd nokia-tasks/../
* `mkdir nokia-tasks-build && cd nokia-tasks-build
* `cmake -DCMAKE_C_COMPILER:FILEPATH=clang -DCMAKE_CXX_COMPILER:FILEPATH=clang++ -H../nokia-tasks/ -B./ -G Ninja
* `cmake --build ./
* `/tests/nokia-tasks-tests
