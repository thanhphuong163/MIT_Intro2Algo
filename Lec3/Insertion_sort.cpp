#include <iostream>
#include <time.h>

using namespace std;

void insertionSort(int* A, int n){
  // Algorithm
  for (int i = 1; i < n; i++){
    int key = A[i];
    int j = i-1;
    while (j >= 0 && key < A[j]){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    /*
    for (int i = 0; i < n; i++){
      cout << A[i] << " ";
    }
    cout << endl;
    */
  }
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
  insertionSort(A, n);

  // Ending counting time
  clock_t end = clock();

  // Output
  for (int i = 0; i < n; i++){
    cout << A[i] << " ";
  }
  cout << endl;

  // Printing running time of algorithm
  double runningTime = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
  cout << "Running time of the Algorithm is " << runningTime << " ms" << endl;

  delete A;
  return 0;
}
