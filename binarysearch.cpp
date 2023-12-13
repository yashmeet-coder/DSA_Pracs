#include <iostream>
using namespace std;

int main(){
  int* arr;
  int n;
  arr = new int[n];

  cout << "enter the number of elements in the list : ";
  cin >> n;

  cout << "enter the elements in ascending order : ";
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  int x;
  cout << "enter the element you wanna search : ";
  cin >> x;

  int ind = -1;

  int start = 0;
  int end = n-1;
  int mid;

  while (start <= end){
    mid = (start + end)/2;
    if(x == arr[mid]){
      ind = mid;
      break;
    }
    else if(x > arr[mid]){
      start = mid+1;
    }
    else{
      end = mid-1;
    }
  }

  cout << "the index of the element is : " << ind;
}