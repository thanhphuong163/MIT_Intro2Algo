#include <iostream>
#include "Heap_sort.h"

using namespace std;

int main(){
  int* pList = new int[10];
  int arr[10] = {3,5,4,6,1,7,8,2,9,11};
  for (int i = 0; i < 10; i++) {
    pList[i] = arr[i];
  }
  Heap<int> heap (10);
  heap.buildHeap(pList,10);
  for (int i = 0; i < 10; i++) {
    cout << heap.list[i] << " ";
  }
  cout << endl;
  cout << heap.right(3) << endl;
  cout << heap.right(4) << endl;
  cout << heap.left(5) << endl;
  cout << "max: " << heap.max() << endl;
  cout << "extra_max: " << heap.extra_max() << endl;
  for (int i = 0; i <= heap.last; i++) {
    cout << heap.list[i] << " ";
  }
  cout << endl;
  return 0;
}
