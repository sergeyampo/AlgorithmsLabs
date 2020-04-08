# AlgorithmsLabs
Алгоритм Кнута — Морриса — Пратта
### Компиляция и тесты
```shell
cmake CMakeLists.txt
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ./second
cmake --build ./second/cmake-build-debug --target Google_Tests_run -- -j 4
cd cmake-build-debug/Google_tests && ./Google_Tests_run
 ```
 
 ### Необходимо
 * g++ >= 9
 * CMake
 * Linux / Windows MinGW
 * Понимание концептов CMake и Google Test
