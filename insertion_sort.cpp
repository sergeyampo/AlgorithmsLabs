#include <algorithm>
#include <iterator>
#include <utility>

//Full support for biderectional iterators(STL containers)
template <class Iter>
void insertion_sort(Iter beg, Iter end) {
	if (std::distance(beg, end) <= 1)
		return;

	Iter limiter = std::next(beg, 1);
	do{
		std::advance(limiter, 1);

		auto inner_comp_b = std::prev(limiter);
		auto inner_comp_e = limiter;
		do {
			std::advance(inner_comp_b, -1);
			std::advance(inner_comp_e, -1);

			if (*inner_comp_b > *inner_comp_e) {
				std::swap(*inner_comp_b, *inner_comp_e);
			}
		} while (inner_comp_b != beg);
	} while (limiter != end);
}
