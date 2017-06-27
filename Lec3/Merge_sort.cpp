#include <iostream>
#include <time.h>

using namespace std;

void merge(int*& A, int left, int mid, int right) {
  // Create temp array to store
  int* temp = new int[right-left+1];
  int iTemp = 0;

  // Initializing index
  int i = left;
  int j = mid+1;

  // Merge
  while (i <= mid && j <= right){
    if (A[i] <= A[j]) {
      temp[iTemp] = A[i];
      i++;
    }
    else {
      temp[iTemp] = A[j];
      j++;
    }
    iTemp++;
  }
  while (i <= mid) {
    temp[iTemp] = A[i];
    i++;
    iTemp++;
  }
  while (j <= right) {
    temp[iTemp] = A[j];
    j++;
    iTemp++;
  }

  // Copy from temp to A
  iTemp = 0;
  for (int i = left; i <= right ; i++) {
    A[i] = temp[iTemp];
    //cout << A[i] << " ";
    iTemp++;
  }
  //cout << endl;

  delete[] temp;
}

void mergeSort(int*& A, int left, int right) {
  if (left < right){
    // Divide and Conquer
    int mid = (left + right) / 2;
    //cout << mid << endl;
    mergeSort(A, left, mid);
    mergeSort(A, mid+1, right);

    //Merge
    merge(A, left, mid, right);
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

  //int A [6]= {2,5,4,6,1,3};
  // Starting counting time
  clock_t start = clock();

  // Run the Algorithm
  mergeSort(A, 0, n-1);

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

  return 0;
}
