// Daily 211 Hard CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


int main()
{
	std::ifstream f("input.txt");

	std::vector<int> vec((std::istream_iterator<int>(f)), std::istream_iterator<int>());
	std::vector<int> best(vec.size());
	std::sort(vec.begin(), vec.end());
	
	int max = 0;

	do {
		int sum = 0;

		if (vec[0] != vec[1])
			sum += vec[0] > vec[1] ? 1 : -1;

		if (vec[vec.size() - 2] != vec[vec.size() - 1])
			sum += vec[vec.size() - 2] < vec[vec.size() - 1] ? 1 : -1;

		for (int i = 1; i < vec.size(); i++)
		{
			if (vec[i-1] < vec[i] && vec[i+1] < vec[i]) 
			{
				sum++;
			}
			else if (vec[i - 1] > vec[i] && vec[i + 1] > vec[i]) {
				sum--;
			}
		}

	} while (std::next_permutation(vec.begin(), vec.end()));
    return 0;
}

