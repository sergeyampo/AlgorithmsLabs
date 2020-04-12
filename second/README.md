# AlgorithmsLabs
Алгоритм Кнута — Морриса — Пратта
### Компиляция и тесты
```shell
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ./second/KMPSearch
cmake --build ./second/KMPSearch --target Google_Tests_run -- -j 4
cd second/KMPSearch/Google_tests && ./Google_Tests_run
 ```
 Интерполяционный поиск
 ### Компиляция и тесты
 ```shell
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ./second/interpolation_search
cmake --build ./second/interpolation_search --target Google_Tests_run -- -j 4
cd second/interpolation_search/Google_tests && ./Google_Tests_run
 ```
 
 ### Необходимо
 * g++ >= 9
 * CMake
 * Linux / Windows MinGW
 * Понимание концептов CMake и Google Test
