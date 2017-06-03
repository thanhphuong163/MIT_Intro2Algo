#ifndef peakFinding_H
#define peakFinding_H

#include <iostream>

struct pos_2D{
  int x;
  int y;
};
//  arr is an integer arrray
//  left is the begin of arr
//  right is the end of arr
//  if arr has n elements then left = 0 and right = n-1
//  function will return position of the peak
int peak_1D(int* arr, int left, int right);

//  arr is an integer array
//  length is the length of arr
//  function will return position of maximum
int max(int* arr, int length);

//  mat is an integer matrix
//  above is the begining row of the matrix
//  bottom is the ending row of the matrix
//  cols is the number column of the matrix
//  function will return position of the peak
pos_2D peak_2D(int mat[5][5], int above, int bottom, int cols);

#endif
