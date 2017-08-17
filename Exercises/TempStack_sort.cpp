#include <iostream>
#include <stack>

using namespace std;

stack<int> Stack_sort(stack<int> A) {
  stack<int> temp;
  while (!A.empty()) {
    int x = A.top();
    A.pop();
    while (!temp.empty() && temp.top() <= x) {
      A.push(temp.top());
      temp.pop();
    }
    temp.push(x);
  }
  return temp;
}

int main(int argc, char const *argv[]) {
  int arr[6] = {34, 3, 31, 98, 92, 23};
  stack<int> A;
  for (int i = 0; i < 6; i++) {
    A.push(arr[i]);
  }
  stack<int> s = Stack_sort(A);
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  return 0;
}
