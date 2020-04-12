#include <iostream>
#include "interpolation_search.h"

#include <vector>

using namespace std;

int main() {
    vector<int> vec = { 2, 7, 30, 40, 80, 82, 90, 110, 112, 123, 130, 150 };
    cout << interpolation_search(begin(vec), end(vec), 123).value_or(-1) << "\n";
    vector<int> vec2 = {10, 12, 13, 16, 18, 19, 20, 21,
                        22, 23, 24, 33, 35, 42, 47};
    cout << interpolation_search(begin(vec2), end(vec2), 18).value_or(-1);
}
