#include <iostream>
#include <vector>
#include <algorithm>

//#define Debug

using namespace std;

vector<int> countingSort(vector<int> A, int k) {
  vector<int> v;
  vector<int> freq;
  for (int j = 0; j < A.size(); j++) {
    v.push_back(0);
  }
  for (int i = 0; i <= k; i++) {
    freq.push_back(0);
  }
  // freq contains the number of elements equal to i
  for (int j = 0; j < A.size(); j++) {
    freq[A[j]]++;
  }
  // Debugging
  #ifdef Debug
  for (int i = 0; i < freq.size(); i++) {
    cout << freq[i] << " ";
  }
  cout << endl;
  #endif
  // freq contains the number of elements less than or equal to i
  for (int i = 1; i <= k; i++) {
    freq[i] = freq[i] + freq[i-1];
  }
  // Debugging
  #ifdef Debug
  for (int i = 0; i < freq.size(); i++) {
    cout << freq[i] << " ";
  }
  cout << endl;
  #endif
  for (int j = A.size()-1; j >= 0; j--) {
    v[freq[A[j]]-1] = A[j];
    freq[A[j]]--;
  }
  return v;
}

int main(int argc, char const *argv[]) {
  int arr[8] = {2,5,3,0,2,3,0,3};
  vector<int> A;
  for (int i = 0; i < 8; i++) {
    A.push_back(arr[i]);
  }
  vector<int> v = countingSort(A, 5);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}
