#include <iostream>
#include <time.h>

using namespace std;

int* merge(int* Left, int* Right, int Lsize, int Rsize){
  // Create an array to return
  int* result = new int[Lsize+Rsize];
  int iResult = 0;

  // Initializing index for Left and Right array
  int iLeft = 0;
  int iRight = 0;

  // Merging
  while (iLeft < Lsize || iRight < Rsize){
    if(Left[iLeft] <= Right[iRight]){
      result[iResult] = Left[iLeft];
      iLeft++;
    }
    else{
      result[iResult] = Right[iRight];
      iRight++;
    }
    iResult++;
  }
  delete[] Left;
  delete[] Right;
  return result;
}

int* mergeSort(int* A, int n){
  int* result = NULL;
  if(n <= 1){
    result = A;
  }
  else{
    // Calculating the middle and sizes
    int mid = n/2;
    int Lsize = n/2;
    int Rsize = n - Lsize;

    // Divide
    int* Left = &A[0];
    int* Right = &A[mid];

    // Conquer
    Left = mergeSort(Left, Lsize);
    Right = mergeSort(Right, Rsize);

    // Merge
    result =  merge(Left, Right, Lsize, Rsize);
  }
  return result;
}

int main(int argc, char const *argv[]) {
  // Initializing
  int n;
  cout << "Type the length of array: ";
  cin >> n;
  int* A = new int[n];
  cout << "Type elements of array:" << endl;
  for (int i = 0; i < n; i++){
    cin >> A[i];
  }
  // Starting counting time
  clock_t start = clock();

  // Run the Algorithm
  int* result = mergeSort(A, n);

  // Ending counting time
  clock_t end = clock();

  // Output
  for (int i = 0; i < n; i++){
    cout << result[i] << " ";
  }
  cout << endl;

  // Printing running time of algorithm
  double runningTime = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
  cout << "Running time of the Algorithm is " << runningTime << " ms" << endl;

  return 0;
}
