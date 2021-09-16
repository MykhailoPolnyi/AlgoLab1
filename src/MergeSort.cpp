#include "MergeSort/MergeSort.h"

int comparisonsCounter;

std::vector<int> merge(std::vector<int> leftVector, std::vector<int> rightVector, bool isSortAsc);

std::vector<int> mergeSort(std::vector<int> inputVect, bool isAscSort) {

	std::vector<int> result;

	std::vector<int> leftVect, rightVect;

	if (inputVect.size() > 1) {
		
		std::vector<int>::iterator inputVectIter = inputVect.begin();
		std::vector<int>::iterator inputVectMiddle = next(inputVect.begin(), inputVect.size() / 2);

		for (inputVectIter; inputVectIter != inputVectMiddle; inputVectIter++) {
			leftVect.push_back(*inputVectIter);
		}

		for (inputVectIter; inputVectIter != inputVect.end(); inputVectIter++) {
			rightVect.push_back(*inputVectIter);
		}

		leftVect = mergeSort(leftVect, isAscSort);
		rightVect = mergeSort(rightVect, isAscSort);

		result = merge(leftVect, rightVect, isAscSort);
	}
	else
	{
		result = inputVect;
	}
	
	return result;
}

std::vector<int> merge(std::vector<int> leftVector, std::vector<int> rightVector, bool isAscSort) {
	
	std::vector <int> mergedVector;

	std::vector<int>::iterator leftVectIter = leftVector.begin();
	std::vector<int>::iterator rightVectIter = rightVector.begin();

	while ((leftVectIter < leftVector.end()) && (rightVectIter < rightVector.end())) {
		if ((*leftVectIter < *rightVectIter) == isAscSort) {
			mergedVector.push_back(*leftVectIter);
			leftVectIter++;
		}
		else {
			mergedVector.push_back(*rightVectIter);
			rightVectIter++;
		}
		comparisonsCounter++;
	}

	mergedVector.insert(mergedVector.end(), leftVectIter, leftVector.end());
	mergedVector.insert(mergedVector.end(), rightVectIter, rightVector.end());

	return mergedVector;
}

int getComparisonCounter() {
	return comparisonsCounter;
}

void resetComparisonCounter() {
	comparisonsCounter = 0;
}