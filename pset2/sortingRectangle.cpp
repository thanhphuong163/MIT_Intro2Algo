#include <iostream>
#include <vector>
#include <algorithm>

//#define debug

using namespace std;

vector<int> merge(vector<int> a, vector<int> b) {
  vector<int> v;
  int n = a.size();
  int m = b.size();
  for (int i = 0; i < n; i++) {
    v.push_back(a[i]);
  }
  for (int i = 0; i < m; i++) {
    v.push_back(b[i]);
  }
  sort(v.begin(), v.begin()+v.size());
  return v;
}

vector<int> sortingRectangle(vector< vector<int> > rect, int first, int last) {
  if (first == last) {
    return rect[first];
  }
  else {
    int mid = (first + last) / 2;
    vector<int> a = sortingRectangle(rect, first, mid);
    // Debug
    #ifdef debug
      for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
      }
      cout << endl;
    #endif
    vector<int> b = sortingRectangle(rect, mid+1, last);
    #ifdef debug
      for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
      }
      cout << endl;
    #endif
    return merge(a, b);
  }
}

int main(int argc, char const *argv[]) {
  int matrix[3][4] = {{1,2,4,8},{3,5,5,10},{4,6,19,30}};
  vector< vector<int> > rect;
  for (int i = 0; i < 3; i++) {
    vector<int> rect_i;
    for (int j = 0; j < 4; j++) {
      rect_i.push_back(matrix[i][j]);
    }
    rect.push_back(rect_i);
  }

  vector<int> v = sortingRectangle(rect, 0, rect.size()-1);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}
