#include <iostream>
#include "Tree.h"

using namespace std;

int main(int argc, char const *argv[]) {
  int arr[11] = {15,6,18,3,7,17,20,2,4,13,9};
  Tree<int>* tree = new Tree<int>();
  for (int i = 0; i < 11; i++) {
    tree->Insert(arr[i]);
    //cout << arr[i] << endl;
  }
  cout << tree->Search(6)->parent->key << endl;
  cout << tree->PredecessorOf(20)->key << endl;
  if (tree->SuccessorOf(20)) {
    cout << tree->SuccessorOf(20)->key << endl;
  }
  tree->Remove(20);
  if (!tree->Search(20)) {
    cout << "Deleted node 20" << endl;
  }
  return 0;
}
