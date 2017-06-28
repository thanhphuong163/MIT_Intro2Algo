#include <iostream>
#include <time.h>

using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void quickSort(int* A, int left, int right){
  // Algorithm
  // Pick pivot randomly
  srand(time(NULL));
  int pivot = (rand() % (right-left+1)) + left; // choose randomly in interval [left,right]
  int key = A[pivot];

  // Partition
  int i = left;
  int j = right;
  while (i <= j) {
    while (A[i] < key) { i++; }   // Find A[i] >= key
    while (A[j] > key) { j--; }   // Find A[j] <= key
    if (i <= j) {
      swap(A[i], A[j]);           // A[i] >= key >= A[j] then swap
      i++;
      j--;
    }
  }

  // Call recursion
  if (left < j){
    quickSort(A, left, j);
  }
  if (i < right){
    quickSort(A, i, right);
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
  quickSort(A, 0, n-1);

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
