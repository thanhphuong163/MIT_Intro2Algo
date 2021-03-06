#include "peakFinding.h"

using namespace std;

int peak_1D(int* arr, int left, int right){
  if (left != right){
    int middle = (left + right) / 2;
    if (arr[middle] < arr[middle-1]){
      return peak_1D(arr, left, middle-1);
    }
    else if (arr[middle] < arr[middle+1]){
      return peak_1D(arr, middle+1, right);
    }
    else {
      return middle;
    }
  }
  else return left;
}

int max(int* arr, int length){
  int max_pos = 0;
  for (int i = 1; i < length; i++){
    if (arr[i] > arr[max_pos]){
      max_pos = i;
    }
  }
  return max_pos;
}

pos_2D peak_2D(int** mat, int above, int bottom, int cols){
  pos_2D peak;
  int middle_row = (above + bottom) / 2;
  int max_pos = max(mat[middle_row], cols);
  //cout << max_pos << endl;
  if (above != bottom){
    if (mat[middle_row][max_pos] < mat[middle_row-1][max_pos]){
      peak = peak_2D(mat, above, middle_row, cols);
    }
    else if (mat[middle_row][max_pos] < mat[middle_row+1][max_pos]){
      peak = peak_2D(mat, middle_row, bottom, cols);
    }
    else {
      peak.x = middle_row+1;
      peak.y = max_pos+1;
    }
  }
  else {
    peak.x = above+1;
    peak.y = max_pos+1;
  }
  return peak;
}

int main(int argc, char const *argv[]) {
  /*
  int n;
  cout << "Input the length of arr: ";
  cin >> n;
  int* arr = new int[n];
  cout << "Input the arr: ";
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  int peak = peak_1D(arr, 0, n-1);
  cout << "The position of peak of arr is " << peak+1 << endl;
  */

  int rows;
  int cols;
  cout << "Input the number of row of the matrix: ";
  cin >> rows;
  cout << "Input the number of column of the matrix: ";
  cin >> cols;

  int** mat = new int*[rows];
  for (int i = 0; i < rows; i++){
    mat[i] = new int[cols];
  }

  cout << "Input the matrix:" << endl;
  for (int i = 0; i < rows; i++){
    cout << "Input the row " << i+1 << endl;
    for (int j = 0; j < cols; j++){
      cin >> mat[i][j];
    }
  }

  pos_2D peak = peak_2D(mat, 0, rows-1, cols);
  cout << "The position of peak of the matrix is (" << peak.x << "," << peak.y << ")" << endl;

  //gather garbage
  for(int i = 0; i < rows; i++){
    delete []mat[i];
  }
  delete []mat;

  return 0;
}
