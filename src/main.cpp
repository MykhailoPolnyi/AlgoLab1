#include <iostream>
#include <chrono>

#include <MergeSort/MergeSort.h>
#include <Convert.h>

using namespace std::chrono;

int main(int argc, char* argv[])
{	
	if (argc < 3) {
		std::cout << "Not enough parameters provided(expected 2). Closing program...";
		return 1;
	}

	bool isAscSort;
	try {
		isAscSort = strToSortOrder(argv[1]);
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what();
		return 1;
	}
	std::vector<int> vectorToSort;

	try {
		vectorToSort = strToIntVect(argv[2], ",");
	}
	catch (std::invalid_argument& e) {
		std::cout << "Wrong parameter provided: sorted array should contain only numbers.\nClosing program..." ;
		return 1;
	}
	catch (std::out_of_range& e) {
		std::cout << e.what() << "\nClosing program...";
		return 1;
	}

	resetComparisonCounter();

	auto startTime = high_resolution_clock::now();
	std::vector<int> a = mergeSort(vectorToSort, isAscSort);
	auto endTime = high_resolution_clock::now();

	auto exDuration = duration_cast<microseconds>(endTime - startTime);

	std::cout << "Merge Sort:\n Duration time: " << exDuration.count() << "us\n Comparisons: " <<getComparisonCounter();

	std::cout << "\n Sorted Array: [";
	for (auto i = a.begin(); i < a.end() ; i++) {
		std::cout << *i << ",";
	}
	std::cout << char(8)<<']';
}
