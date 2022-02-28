#include "arraySort.h"

arraySort::arraySort(int size) {
	create(size);
}

void arraySort::create(int size) {
	vec.resize(size);
	std::iota(vec.begin(), vec.end(), 1);
	shuffle(vec.begin(), vec.end(), rand32);
}

std::vector< std::vector< int > > arraySort::statisticSort() {
	std::vector< std::vector< int > > statistic;
	funcSort(vec, std::function([&](int a, int b) -> bool {
		if (statistic.empty() or statistic.back() != vec)
			statistic.push_back(vec);
		return a < b;
		}));
	if (statistic.empty() or statistic.back() != vec)
		statistic.push_back(vec);
	return statistic;
}