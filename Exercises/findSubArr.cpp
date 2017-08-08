#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, int> findSubArr(vector<int> arr) {
  pair<int, int> subSeq;
  int sumSub = arr[0];
  for (int i = 1; i <= arr.size(); i++) {
    int left = 0;
    int right = left+i-1;
    while (right < arr.size()) {
      int sum = 0;
      for (int j = left; j <= right; j++) {
        sum += arr[j];
      }
      if (abs(sum) <= abs(sumSub)) {
        sumSub = sum;
        subSeq.first = left;
        subSeq.second = right;
      }
      left++;
      right++;
    }
  }
  return subSeq;
}

int main(int argc, char const *argv[]) {
  int a[5] = {2, -5, 4, -6, 3};
  vector<int> arr;
  for (int i = 0; i < 5; i++) {
    arr.push_back(a[i]);
  }

  pair<int, int> subseq = findSubArr(arr);
  cout << subseq.first << ", " << subseq.second << endl;
  return 0;
}
