#include <iostream>

using namespace std;

// Define 2d position
class pos_2D {
public:
  int x;
  int y;
  pos_2D(int x, int y){
    this->x = x;
    this->y = y;
  }
  ~pos_2D(){}
  void set(int x, int y){
    this->x = x;
    this->y = y;
  }
}

// Declaring function
pos_2D findPeak(int** A, int size){
  int n = size;
  pos_2D top_left = pos_2D(0,0);
  pos_2D top_right = pos_2D(0,n-1);
  pos_2D bottom_left = pos_2D(n-1,0);
  pos_2D bottom_right = pos_2D(n-1,n-1);

  while (n > 2){
    k = (size+1)/2;
    if ()
  }
}

int main(int argc, char const *argv[]) {

  // Initializing 2d array
  int n;
  cout << "Input size of 2d-square array: ";
  cin >> n;
  int** A = new int*[n];
  for (int i = 0; i < n; i++){
    A[i] = new int[n];
  }

  //
  return 0;
}
