#include <iostream>
#include <vector>
#include <stack>
#include <queue>

//#define Debug

using namespace std;

bool isPermutation(vector<int> a, vector<int> b) {
  stack<int> permutation;
  int i = 0;
  int j = 0;
  while (i < a.size()) {
    if (!permutation.empty() && (b[i] == permutation.top())) {
      i++;
      permutation.pop();
      #ifdef Debug
      cout << "permutation -> output: " << b[i-1] << endl;
      #endif
    }
    else if (j < a.size()) {
      if (b[i] == a[j]) {
        i++;
        #ifdef Debug
        cout << "input -> output: " << b[i-1] << endl;
        #endif
      }
      else {
        permutation.push(a[j]);
        #ifdef Debug
        cout << "input -> permutation: " << a[j] << endl;
        #endif
      }
      j++;
    }
    else {
      break;
    }
  }
  if (i == a.size()) {
    return true;
  }
  else {
    return false;
  }
}

int main(int argc, char const *argv[]) {
  int arr1[3] = {1,2,3};
  int arr2[3] = {3,1,2};
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < 3; i++) {
    a.push_back(arr1[i]);
    b.push_back(arr2[i]);
  }
  if (isPermutation(a,b)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "Imposible" << endl;
  }
  return 0;
}
