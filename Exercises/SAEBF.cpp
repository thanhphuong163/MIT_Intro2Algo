#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

//#define debug

using namespace std;

bool compare(pair<int,int>& a, pair<int,int>& b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second > b.second;
}

vector<pair<int,int> > SAEBF(vector<int> arr) {
  vector<pair<int,int> > v;
  sort(arr.begin(),arr.end());

  // Debugging
  #ifdef debug
    for (int i = 0; i < arr.size(); i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  #endif

  int i = 0;
  int j = 0;
  pair<int,int> element;
  element.first = arr[0];
  element.second = 0;
  v.push_back(element);
  while (i < arr.size()) {
    if (v[j].first == arr[i]) {
      v[j].second++;
    }
    else {
      element.first = arr[i];
      element.second = 1;
      v.push_back(element);
      j++;
    }
    i++;
  }
  sort(v.begin(), v.end(), compare);

  // Debugging
  #ifdef debug
    for (int i = 0; i < v.size(); i++) {
      cout << v[i].first << " : " << v[i].second << endl;
    }
    cout << endl;
  #endif
  return v;
}

int main(int argc, char const *argv[]) {
  int a[11] = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
  vector<int> arr;
  for (int i = 0; i < 11; i++) {
    arr.push_back(a[i]);
  }
  vector< pair<int,int> > result = SAEBF(arr);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].second; j++) {
      cout << result[i].first << " ";
    }
  }
  cout << endl;
  return 0;
}
