cmake_minimum_required( VERSION 3.0 )

project( MergeSort )

set(CMAKE_CXX_STANDART 11)

include_directories( ./include ./src ./test )

add_executable( MergeSort 
	./src/main.cpp 
	./src/MergeSort.cpp 
	./src/Convert.cpp 
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  MergeSortTest
  test/MergeSortTest.cpp
  ./src/MergeSort.cpp
)
target_link_libraries(
  MergeSortTest
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(MergeSortTest)

