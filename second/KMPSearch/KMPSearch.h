//
// Created by sergeyampo on 08.04.2020.
//

#ifndef ALGORITHMSSECOND_KMPSEARCH_H
#define ALGORITHMSSECOND_KMPSEARCH_H

#include <stdint.h>
#include <vector>
#include <string>
#include <optional>
#include <string_view>

//Поддерживаем wstring для поддержки 2 байтной кодировки
//Функция возвращает вектор префикс функции для переданного слова
std::vector<std::wstring::size_type> makePrefixFunction(const std::wstring_view);

//Функция возвращает опциональный объект позиции, в которой найдено слово, если оно не найдено
//мы обработаем этот случай(вместо нелепого возвращения -1 или исключения)
std::optional<std::wstring::size_type> KMPSearch(std::wstring_view, std::wstring_view);

#endif //ALGORITHMSSECOND_KMPSEARCH_H