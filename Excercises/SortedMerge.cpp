#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedMerge(vector<int> a, vector<int> b) {
  vector<int> v;
  sort(a.begin(), a.begin()+a.size());
  sort(b.begin(), b.begin()+b.size());
  int i = 0;
  int j = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i] <= b[j]) {
      v.push_back(a[i]);
      i++;
    }
    else {
      v.push_back(b[j]);
      j++;
    }
  }
  while (i < a.size()) {
    v.push_back(a[i]);
    i++;
  }
  while (j < b.size()) {
    v.push_back(b[j]);
    j++;
  }
  return v;
}

vector<int> sortedMerge_sol(vector<int> a, vector<int> b) {
  vector<int> v;
  for (int i = 0; i < a.size(); i++) {
    v.push_back(a[i]);
  }
  for (int i = 0; i < b.size(); i++) {
    v.push_back(b[i]);
  }
  sort(v.begin(), v.begin()+v.size());
  return v;
}

int main(int argc, char const *argv[]) {
  int a_ [8] = {10,5,15,42,6,32,63,5};
  int b_ [8] = {20,3,2,7,6,12,65,90};
  vector<int> a;
  for (int i = 0; i < 8; i++) {
    a.push_back(a_[i]);
  }
  vector<int> b;
  for (int i = 0; i < 8; i++) {
    b.push_back(b_[i]);
  }
  vector<int> v = sortedMerge(a,b);
  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;
  vector<int> v1 = sortedMerge_sol(a,b);
  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
