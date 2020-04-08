//
// Created by sergeyampo on 08.04.2020.
//

#include "KMPSearch.h"
#include <vector>
#include <string>

using namespace std;

/**
 *
 * @param str - строка для которой делаем префикс функцию
 * @return вектор префикс функции
 */
vector<wstring::size_type> makePrefixFunction(const wstring_view str) {
    auto word_size = str.size();
    vector<wstring::size_type> prefix_func(word_size);

    for (wstring::size_type i = 1; i < word_size; ++i) {
        wstring::size_type j = prefix_func[i-1];

        while (j > 0 && str[i] != str[j])
            j = prefix_func[j-1];

        if (str[i] == str[j])
            ++j;

        prefix_func[i] = j;
    }
    return prefix_func;
}


optional<wstring::size_type> KMPSearch(wstring_view source, wstring_view pattern) {
    // Preprocess the pattern (calculate lps[] array)
    auto LPS = makePrefixFunction(pattern);

    auto src_sz = source.size();
    auto patt_sz = pattern.size();

    int i = 0; // индекс для source
    int j = 0; // индекс для pattern
    while (i < src_sz) {
        if (pattern[j] == source[i]) {
            ++j;
            ++i;
        }

        if (j == patt_sz) {
            return i - j;
        }

            // mismatch after j matches
        else if (i < src_sz && pattern[j] != source[i]) {
            if (j != 0)
                j = LPS[j - 1];
            else
                ++i;
        }
    }
    return {};
}


