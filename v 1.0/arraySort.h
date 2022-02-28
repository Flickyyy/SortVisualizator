#pragma once
#include<bits/stdc++.h>
#include <random>
//32int vector that have
//intermediate sort situations
class arraySort
{
public:
	arraySort(int size);
	void create(int size);
	std::vector< std::vector< int > > statisticSort();

	std::function<void(std::vector<int>&, std::function<bool(int, int)>)> funcSort;
private:
	std::mt19937 rand32{ std::random_device{}() };
	std::vector<int> vec;
};

