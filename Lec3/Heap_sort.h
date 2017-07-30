#include <iostream>
using namespace std;

#ifndef _Heap_sort_
#define _Heap_sort_

//#define debug

template <class T>
class Heap {
public:
  T* list;
  int last;
  int capacity;

  // Constructions
  Heap(int size){
    if (size > 0) {
      list = new T[size];
      last = -1;
      capacity = size;
    }
  }
  Heap(T*& pList, int size) {
    if (!pList && size > 0) {
      list = pList;
      last = size-1;
      capacity = size;
    }
  }

  //Methods
  void insert(T item){
    if (last < capacity-1) {
      list[++last] = item;
      // Debugging
      #ifdef debug
        cout << "Insert:" << item << endl;
        cout << "last = " << last << endl;
      #endif
    }
  }
  void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
  }
  int heapify(int i) {
    if (2*i+2 <= last) {
      if (list[2*i+1] < list[2*i+2]) {
        swap(list[2*i+2], list[i]);
        // Debugging
        #ifdef debug
          cout << "swap " << 2*i+2 << " and " << i << endl;
        #endif

        return 2*i+2;
      }
      else {
        swap(list[2*i+1], list[i]);
        // Debugging
        #ifdef debug
          cout << "swap " << 2*i+1 << " and " << i << endl;
        #endif

        return 2*i+1;
      }
    }
    else if (2*i+1 <= last) {
      swap(list[2*i+1], list[i]);
      // Debugging
      #ifdef debug
        cout << "swap " << 2*i+1 << " and " << i << endl;
      #endif

      return 2*i+1;
    }
    else { return -1; }
  }
  void buildHeap(T*& pList, int size) {
    if (pList && size > 0) {
      this->insert(pList[0]);
      for (int i = 1; i < size; i++) {
        this->insert(pList[i]);
        int k = i;
        int j = (k-1)/2;
        while (list[k] > list[j]) {
          this->heapify(j);
          k = j;
          j = (k-1)/2;
          // Debugging
          #ifdef debug
            cout << "list[" << k << "] = " << list[k] << endl;
            cout << "list[" << j << "] = " << list[j] << endl;
          #endif

        }
        // Debugging
        #ifdef debug
          for (int i = 0; i <= this->last; i++) {
            cout << this->list[i] << " ";
          }
          cout << endl;
        #endif

      }
    }
  }
  T right(int i) {
    if (2*i+2 <= last){
      return list[2*i+2];
    }
    else { return -1; }
  }
  T left(int i) {
    if (2*i+1 <= last) {
      return list[2*i+1];
    }
    else { return -1; }
  }
  T max() {
    return list[0];
  }
  T extra_max() {
    swap(list[0], list[last]);
    this->last--;
    int i = 0;
    while (2*i+1 <= last) {
      i = this->heapify(i);
    }
    return list[last+1];
  }
  // Destruction
  ~Heap() { delete[] list; }

};


#endif
