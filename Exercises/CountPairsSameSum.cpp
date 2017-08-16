#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool binSearch(vector<int> A, int left, int right, int k) {
  if (left <= right) {
    int mid = (left + right) / 2;
    if (A[mid] == k) {
      return true;
    }
    else if (A[mid] < k) {
      return binSearch(A, mid+1, right, k);
    }
    else {
      return binSearch(A, left, mid-1, k);
    }
  }
  else {
    return false;
  }
}

int countPairs(vector<int> v1, vector<int> v2, int n) {
  int count = 0;
  int k = 0;
  sort(v2.begin(), v2.begin() + v2.size());
  for (int i = 0; i < v1.size(); i++) {
    k = n - v1[i];
    if (k >= v2[0] && k <= v2[v2.size()-1]) {
      if (binSearch(v2, 0, v2.size()-1, k)) {
        count++;
      }
    }
  }
  return count;
}

int main(int argc, char const *argv[]) {
  int arr1[7] = {4,3,5,7,11,2,1};
  int arr2[7] = {2,3,4,5,6,8,12};
  vector<int> v1, v2;
  for (int i = 0; i < 7; i++) {
    v1.push_back(arr1[i]);
    v2.push_back(arr2[i]);
  }
  int count = countPairs(v1,v2,9);
  cout << count << endl;
  return 0;
}
