#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findKMissing(vector<int> arr, int k) {
  sort(arr.begin(), arr.begin()+arr.size());
  for (int n : arr) {
    cout << n << " ";
  }
  cout << endl;
  vector<int> v;
  int i = 1;
  int j = 0;
  int count = 0;
  while (count < k) {
    if (i < arr[j]) {
      v.push_back(i);
      count++;
    }
    else {
      j++;
    }
    i++;
  }
  return v;
}

int main(int argc, char const *argv[]) {
  int a[5] = {3,7,5,15,13};
  vector<int> arr;
  for (int i = 0; i < 5; i++) {
    arr.push_back(a[i]);
  }
  vector<int> v = findKMissing(arr,5);
  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
