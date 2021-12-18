#include <gtest/gtest.h>
#include <vector>
#include <MergeSort/MergeSort.h>

 
class MergeSortTest : public ::testing::Test {
protected:
	std::vector<int> shuffledVector;
	std::vector<int> sortedVectorAsc;
	std::vector<int> sortedVectorDesc;

	void SetUp() override{
		shuffledVector = { 553,220,369,3923,249,329,204,2492,1942,2459,194,1111 };
		sortedVectorAsc = { 194,204,220,249,329,369,553,1111,1942,2459,2492,3923 };
		sortedVectorDesc = { 3923,2492,2459,1942,1111,553,369,329,249,220,204,194 };
	}
};

TEST_F(MergeSortTest, CheckShuffledVector) {
	EXPECT_EQ(mergeSort(shuffledVector, true), sortedVectorAsc) << "Vector isn't sorted by ascending.";
	EXPECT_EQ(mergeSort(shuffledVector, false), sortedVectorDesc) << "Vector isn't sorted by descending.";
}

TEST_F(MergeSortTest, AscSortedVector) {
	EXPECT_EQ(mergeSort(sortedVectorAsc, true), sortedVectorAsc) << "Vector isn't sorted by ascending.";
	EXPECT_EQ(mergeSort(sortedVectorAsc, false), sortedVectorDesc) << "Vector isn't sorted by descending.";
}

TEST_F(MergeSortTest, DescSortedVector) {
	EXPECT_EQ(mergeSort(sortedVectorDesc, true), sortedVectorAsc) << "Vector isn't sorted by ascending.";
	EXPECT_EQ(mergeSort(sortedVectorDesc, false), sortedVectorDesc) << "Vector isn't sorted by descending.";
}

