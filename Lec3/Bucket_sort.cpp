#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<float> Bucket_sort(vector<float> A) {
  int n = A.size();
  vector< vector<float> > B;
  for (int i = 0; i < n; i++) {
    vector<float> B_i;
    B.push_back(B_i);
  }

  for (int i = 0; i < n; i++) {
    B[floor(n*A[i])].push_back(A[i]);
  }

  for (int i = 0; i < n; i++) {
    if (!B[i].empty()) {
      sort(B[i].begin(), B[i].begin() + B[i].size());
    }
  }
  vector<float> v;
  for (int i = 0; i < n; i++) {
    if (!B[i].empty()) {
      for (int j = 0; j < B[i].size(); j++) {
        v.push_back(B[i][j]);
      }
    }
  }
  return v;
}

int main(int argc, char const *argv[]) {
  float arr[10] = {0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68};
  vector<float> A;
  for (int i = 0; i < 10; i++) {
    A.push_back(arr[i]);
  }
  vector<float> v = Bucket_sort(A);
  for (int i = 0; i < 10; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}
