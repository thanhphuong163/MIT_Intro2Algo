#include <iostream>
#include <time.h>

using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void bubbleSort(int* A, int n){
  // Algorithm
  for (int i = 0; i < n-1; i++){
    for (int j = i+1; j < n; j++){
      if (A[i] > A[j]) {
        swap(A[i], A[j]);
      }
    }
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
  bubbleSort(A, n);

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

  delete[] A;
  return 0;
}
