#include "insertion_sort.h"
#include "profile.h"

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdint.h>
#include <iterator>
#include <algorithm>
#include <random>

using namespace std;

template <class T>
void random_fill(T& v) {
	std::generate(begin(v), end(v), std::rand);
}

template <class T>
void print_cont(const T& cont, const char* greet) {
	cout << greet << "\n";
	copy(begin(cont), prev(end(cont)), ostream_iterator<typename T::value_type>(cout, ", "));
	cout << *prev(cont.end()) << "\n";
}

//Тестируем на всех видах структур
int main() {
	vector<uint64_t> vec_f(1200);
	random_fill(vec_f);
	{
		LOG_DURATION("Insertion sort for 1200 elements");
		insertion_sort(begin(vec_f), end(vec_f));
	}

	vector<uint64_t> vec_s(2000);
	random_fill(vec_s);
	{
		LOG_DURATION("Insertion sort for 2000 elements");
		insertion_sort(begin(vec_s), end(vec_s));
	}

	vector<uint64_t> vec_t(7500);
	random_fill(vec_t);
	{
		LOG_DURATION("Insertion sort for 7500 elements");
		insertion_sort(begin(vec_t), end(vec_t));
	}

	
	return 0;
}