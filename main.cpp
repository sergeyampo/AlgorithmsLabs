#include "insertion_sort.h"

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdint.h>
#include <iterator>

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
	vector<uint64_t> vec(100);
	random_fill(vec);
	print_cont(vec, "Vector before sorting:");
	insertion_sort(begin(vec), end(vec));
	print_cont(vec, "Vector after sorting:");

	list<uint64_t> list(100);
	random_fill(list);
	print_cont(list, "List before sorting:");
	insertion_sort(begin(list), end(list));
	print_cont(list, "List after sorting:");

	deque<uint64_t> deq(100);
	random_fill(deq);
	print_cont(deq, "Deque before sorting:");
	insertion_sort(begin(deq), end(deq));
	print_cont(deq, "Deque after sorting:");

	
	return 0;
}