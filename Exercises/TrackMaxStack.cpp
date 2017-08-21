#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {
  int arr[6] = {40, 19, 7, 14, 20, 5};
  stack<int> A;
  stack<int> max;
  max.push(arr[0]);
  for (int i = 0; i < 6; i++) {
    A.push(arr[i]);
    if (max.top() < A.top()) {
      max.push(A.top());
    }
    cout << max.top() << endl;
  }
  return 0;
}
