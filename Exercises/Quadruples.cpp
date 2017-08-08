#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct output {
  int count;
  vector< vector<int> > quadruples;
};

output* Quadruples(vector< vector<int> > matrix, int x) {
  output* n = new output();
  n->count = 0;
  for (int i = 0; i < matrix[0].size(); i++) {
    for (int j = 0; j < matrix[1].size(); j++) {
      for (int k = 0; k < matrix[2].size(); k++) {
        for (int t = 0; t < matrix[3].size(); t++) {
          if (matrix[0][i]+matrix[1][j]+matrix[2][k]+matrix[3][t] == x){
            n->count++;
            vector<int> quad;
            quad.push_back(matrix[0][i]);
            quad.push_back(matrix[1][j]);
            quad.push_back(matrix[2][k]);
            quad.push_back(matrix[3][t]);
            n->quadruples.push_back(quad);
          }
        }
      }
    }
  }
  return n;
}

bool isExist(vector<int> arr, int left, int right, int k) {
  while (left <= right) {
    int mid = (left+right)/2;
    if (arr[mid] == k) {
      return true;
    }
    else if (arr[mid] < k) {
      left = mid+1;
    }
    else {
      right = mid-1;
    }
  }
  return false;
}

int Quadruples_BinSearch(vector< vector<int> > matrix, int x) {
  int count = 0;
  for (int i = 0; i < matrix[0].size(); i++) {
    for (int j = 0; j < matrix[1].size(); j++) {
      for (int k = 0; k < matrix[2].size(); k++) {
        int T = matrix[0][i]+matrix[1][j]+matrix[2][k];
        if (isExist(matrix[3], 0, matrix[3].size()-1, x-T)){
          count++;
        }
      }
    }
  }
  return count;
}

int main(int argc, char const *argv[]) {
  int arr1[4] = {1, 4, 5, 6};
  int arr2[4] = {2, 3, 7, 8};
  int arr3[4] = {1, 4, 6, 10};
  int arr4[4] = {2, 4, 7, 8};
  vector< vector<int> > matrix(4);
  for (int i = 0; i < 4; i++) {
    matrix[0].push_back(arr1[i]);
    matrix[1].push_back(arr2[i]);
    matrix[2].push_back(arr3[i]);
    matrix[3].push_back(arr4[i]);
  }
  output* n = Quadruples(matrix, 25);
  cout << "Output : " << n->count << endl;
  cout << "The Quadruples are: " << endl;
  for (int i = 0; i < n->count; i++){
    cout << "{ ";
    for (int a : n->quadruples[i]){
      cout << a << " ";
    }
    cout << "}" << endl;
  }

  int count = Quadruples_BinSearch(matrix, 25);
  cout << "Output : " << count << endl;
  return 0;
}
