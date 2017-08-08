#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MaxProdOfSubseqK(vector<int> arr, int k) {
  int prod = 1;
  int begin = 0;
  int end = arr.size()-1;
  sort(arr.begin(), arr.end());
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Case 1
  if (arr[end] == 0) {
    for (int i = 0; i < k; i++) {
      cout << arr[end-i] << " ";
    }
    cout << endl;
    return 0;
  }

  // Case 2
  if (arr[end] < 0 && k%2 != 0) {
    for (int i = 0; i < k; i++) {
      prod = prod * arr[end-i];
      cout << arr[end-i] << " ";
    }
    cout << endl;
    return prod;
  }

  // Case 3
  if (arr[end] > 0 && k%2 != 0) {
    prod = prod * arr[end];
    cout << arr[end] << " ";
    int left = 0;
    int right = arr.size()-2;
    for (int i = 0; i < (k-1)/2; i++) {
      if (arr[left]*arr[left+1] <= arr[right-1]*arr[right]) {
        prod = prod * arr[right-1]*arr[right];
        cout << arr[right] << " " << arr[right-1] << " ";
        right -= 2;
      }
      else {
        prod = prod * arr[left]*arr[left+1];
        cout << arr[left] << " " << arr[left+1] << " ";
        left += 2;
      }
    }
    cout << endl;
    return prod;
  }

  // Case 4
  if (arr[end] > 0 && k%2 == 0) {
    int left = 0;
    int right = arr.size()-1;
    for (int i = 0; i < k/2; i++) {
      if (arr[left]*arr[left+1] <= arr[right-1]*arr[right]) {
        prod = prod * arr[right-1]*arr[right];
        cout << arr[right] << " " << arr[right-1] << " ";
        right -= 2;
      }
      else {
        prod = prod * arr[left]*arr[left+1];
        cout << arr[left] << " " << arr[left+1] << " ";
        left += 2;
      }
    }
    cout << endl;
    return prod;
  }

  return -1;
}

int main(int argc, char const *argv[]) {
  int a[7] = {1, 2, -1, -3, -6, 4, 7};
  vector<int> arr;
  for (int i = 0; i < 7; i++) {
    arr.push_back(a[i]);
  }
  int prod = MaxProdOfSubseqK(arr, 4);
  cout << "Maximum product of subsequence of k: " << prod << endl;
  return 0;
}
