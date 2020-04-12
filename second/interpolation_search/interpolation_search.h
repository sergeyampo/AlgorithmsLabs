//
// Created by sergeyampo on 12.04.2020.
//

#ifndef INTERPOLATION_SEARCH_INTERPOLATION_SEARCH_H
#define INTERPOLATION_SEARCH_INTERPOLATION_SEARCH_H
#include <type_traits>
#include <optional>

template <typename T, typename It, typename = std::enable_if_t<std::is_arithmetic_v<T>> >
std::optional<T> interpolation_search(It, It, const T&);

template <typename It, typename T>
T get_interpol_key(It, It, const T&);

#endif //INTERPOLATION_SEARCH_INTERPOLATION_SEARCH_H
#include "interpolation_search.cpp"
