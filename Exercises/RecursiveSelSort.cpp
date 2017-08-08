#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

struct node {
  int value;
  node* next;
};

class linkedList {
public:
  node* first;
  node* last;
  int count;

  linkedList() {
    this->first = NULL;
    this->count = 0;
    this->last = NULL;
  }
  void push_back(int value) {
    node* item = new node();
    item->value = value;
    item->next = NULL;
    if (this->count > 0) {
      this->last->next = item;
      this->last = item;
    }
    else {
      this->last = item;
      this->first = item;
    }
    this->count++;
  }
  void swap(node*& a, node*& b) {
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
  }
};

void _recursiveSelSort(linkedList*& pList, node* first){
  if (first) {
    node* min = first;
    node* run = first->next;
    while (run) {
      if (min->value > run->value) {
        min = run;
      }
      run = run->next;
    }
    // Swap
    pList->swap(first, min);
    _recursiveSelSort(pList, first->next);
  }
}

void recursiveSelSort(linkedList*& pList) {
  _recursiveSelSort(pList, pList->first);
}

int main(int argc, char const *argv[]) {
  int arr[5] = {10,12,8,4,6};
  linkedList* pList = new linkedList();
  for (int i = 0; i < 5; i++) {
    pList->push_back(arr[i]);
  }
  node* run = pList->first;
  while (run) {
    if (run->next) {
      cout << run->value << " -> ";
    }
    else {
      cout << run->value << ";";
    }
    run = run->next;
  }
  cout << endl;
  recursiveSelSort(pList);
  run = pList->first;
  while (run) {
    if (run->next) {
      cout << run->value << " -> ";
    }
    else {
      cout << run->value << ";";
    }
    run = run->next;
  }
  cout << endl;
  return 0;
}
