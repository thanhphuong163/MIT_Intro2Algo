#ifndef _Heap_sort_
#define _Heap_sort_

template <typename T>
class Heap {
public:
  T* list;
  int count = 0;
  
  // Constructions
  Heap();
  Heap(T*& pList);

  //Methods
  void heapify(){

  }
  void buildHeap(){

  }

  // Destruction
  ~Heap(){ delete[] list;}

};


#endif
