//
// Created by sergeyampo on 12.04.2020.
//

#include <iterator>
#include <optional>
#include <type_traits>

using namespace std;

template <typename T, typename It, typename = enable_if_t<is_arithmetic_v<T> > >
std::optional<T> interpolation_search(It beg, It end, const T& key){
  const auto size = distance(beg, end);
  if(size == 1)
      if(key == *beg)
        return 0;
      else
        return {};

  It float_beg = beg;
  It float_end = prev(end);
  It move_it = beg;
  T d;
  while(d != 0 || float_beg != float_end) {
      T d = get_interpol_key(float_beg, float_end, key);

      if(d == 0)
          if(*next(move_it) == key)
              return distance(beg, next(move_it));
          else if(*prev(move_it) == key)
              return distance(beg, prev(move_it));
          else
              return {};

      advance(move_it, d);

      if(*move_it == key)
          return static_cast<T>(distance(move_it, beg));
      else if (*move_it > key){
          float_end = prev(move_it);
      }
      else{
          //*move_it < key
          float_beg = next(move_it);
      }
  }

  return {};
}

/**
 *
 * @tparam It - iterator type
 * @tparam T - key type
 * @param i - iterator of start position
 * @param j - iterator of end position
 * @param key - key
 * @return interpolation key for searching from formula: [(j-i)*(k-kj)/(kj-ki)]
 */
template <typename It, typename T>
T get_interpol_key(It i, It j, const T& key){
    if(j == i || key <= *i || *j <= *i)
        return 0;

    auto a = distance(i, j);
    auto b = key - *i;
    auto c = ((distance(i, j)) *(double) (key - *i));
    auto d = (*j - *i);
    auto e = (((distance(i, j)) *(double) (key - *i)) /(double) (*j - *i));
    //using double operations but cast to integer type (it T is)
    return static_cast<T>(((distance(i, j)) *(double) (key - *i)) /(double) (*j - *i));
}