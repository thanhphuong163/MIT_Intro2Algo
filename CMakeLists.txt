cmake_minimum_required(VERSION 3.8)
project(MIT_Intro2Algo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Exercises/CountPairsSameSum.cpp
        Exercises/findSubArr.cpp
        Exercises/KMissing.cpp
        Exercises/MaxProdOfSubseqK.cpp
        Exercises/Quadruples.cpp
        Exercises/RecursiveSelSort.cpp
        Exercises/SAEBF.cpp
        Exercises/SortedMerge.cpp
        Exercises/StackPermutation.cpp
        Exercises/TempStack_sort.cpp
        Exercises/TrackMaxStack.cpp
        Lec1_peakFinding/peakFinding.cpp
        Lec1_peakFinding/peakFinding.h
        Lec3/Bubble_sort.cpp
        Lec3/Bucket_sort.cpp
        Lec3/Counting_sort.cpp
        Lec3/Heap_sort.cpp
        Lec3/Heap_sort.h
        Lec3/Insertion_sort.cpp
        Lec3/Merge_sort.cpp
        Lec3/Quick_sort.cpp
        Lec3/Radix_sort.cpp
        Lec3/test.cpp
        Lec4/AVLTree.h
        Lec4/test.cpp
        Lec4/Tree.h
        pset1/unbalanced_peak.cpp
        pset2/sortingRectangle.cpp)

add_executable(MIT_Intro2Algo ${SOURCE_FILES})