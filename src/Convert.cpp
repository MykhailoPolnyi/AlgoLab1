#include "Convert.h"

std::vector<int> strToIntVect(std::string convertedString, std::string delimiter) {
	std::vector<int> result;

	size_t lastPos = 0, nextPos = 0;
	std::string token;
	while (nextPos != std::string::npos) {
		nextPos = convertedString.find(delimiter, lastPos);
		token = convertedString.substr(lastPos, nextPos - lastPos);
		result.push_back(stoi(token));
		lastPos = nextPos + 1;
	}
	return result;
}

bool strToSortOrder(std::string convertedString)
{
	bool isAscSort;

	if (convertedString == "Asc") {
		isAscSort = true;
	}
	else if (convertedString == "Desc") {
		isAscSort = false;
	}
	else
	{
		throw std::invalid_argument("Wrong parameter provided: sort direction should be \"Asc\" or \"Desc\"");
	}

	return isAscSort;
}
