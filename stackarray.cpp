#include <iostream>
using namespace std;

class Stack{
  private:
  int n;
  int tos = -1;
  int* arr;
  
  public:

  Stack(int n){
    this->n = n;
    arr = new int[n];
  }

  bool isEmpty(){
    if(tos == -1){
      return true;
    }
    else{
      return false;
    }
  }

  void push(int ele){
    if(tos < n-1){
      tos++;
      arr[tos] = ele;
      // print();
      // cout << endl;
    }
    else{
      cout << "cant push more" << endl;
    }
  }

  int pop(){
    if(this->isEmpty() == true){
      cout << "stack empty";
      return -1;
    }
    tos--;
    return arr[tos+1];
  }

  void print(){
    for(int i = 0; i < n; i++){
      cout << arr[n-i-1] << " ";
    }
  }

  int top(){
    if(!this->isEmpty()){
      return arr[tos];
    }
    else{
      return -1;
    }
  }

};

int main(){
  Stack* s1 = new Stack(5);
  // cout << "stack status : " << s1->isEmpty();
  s1->push(5);
  s1->push(7);
  s1->push(8);
  s1->push(10);
  s1->push(17);

  for (int i = 0; i < 5; i++){
    cout << s1->pop() << " ";
  }

}