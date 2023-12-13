#include <iostream>
using namespace std;

int main(){

  int* arr;
  int n;
  arr = new int[n];

  cout << "enter the number of elements in the list : ";
  cin >> n;
  cout << "enter the elements : ";

  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  int x;
  cout << "enter the element you wanna search : "; 
  cin >> x;

  int ind = -1;
  for (int i = 0; i < n; i++){
    if(arr[i] == x){
      ind = i;
      break; 
    }
  }

  cout << "the element's index is : " << ind; 

  // cout << "the elements are : " << endl;
  // for (int i = 0; i < n; i++){
  //   cout << arr[i] << " ";
  // }
}