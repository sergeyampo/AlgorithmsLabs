#include <iostream>

using namespace std;

#include "KMPSearch.h"

int main() {
    std::locale::global(std::locale(""));

    auto a = makePrefixFunction(L"abcabd");
    optional<wstring::size_type> FoundPos = KMPSearch(L"abcabeabcabcabd", L"abcabd");
    if(FoundPos)
        wcout << L"Найдено в позиции: " << *FoundPos;
    else
        wcout << L"Не найдено!";

    return 0;
}
