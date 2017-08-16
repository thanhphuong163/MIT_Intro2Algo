#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

//#define Debug

using namespace std;

vector<int> countingSort(vector<int> A, int base) {
  vector<int> v ;
  vector<int> freq;
  for (int j = 0; j < A.size(); j++) {
    v.push_back(0);
  }
  for (int i = 0; i <= 9; i++) {
    freq.push_back(0);
  }
  // freq contains the number of elements equal to i
  for (int j = 0; j < A.size(); j++) {
    freq[(A[j] % base) / (base/10)]++;
  }

  // freq contains the number of elements less than or equal to i
  for (int i = 1; i <= 9; i++) {
    freq[i] = freq[i] + freq[i-1];
  }

  for (int j = A.size()-1; j >= 0; j--) {
    v[freq[(A[j] % base) / (base/10)] - 1] = A[j];
    freq[(A[j] % base) / (base/10)]--;
  }
  return v;
}

vector<int> Radix_sort(vector<int> A, int d) {
  vector<int> v = A;
  for (int i = 1; i <= d; i++) {
    v = countingSort(v, pow(10,i));
    // Debug
    #ifdef Debug
    for (int j = 0; j < v.size(); j++) {
      cout << v[j] << " ";
    }
    cout << endl;
    #endif
  }
  return v;
}

int main(int argc, char const *argv[]) {
  int arr[7] = {329,457,657,839,436,720,355};
  vector<int> A;
  for (int i = 0; i < 7; i++) {
    A.push_back(arr[i]);
  }
  vector<int> v = Radix_sort(A, 3);
  for (int i = 0; i < 7; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}
