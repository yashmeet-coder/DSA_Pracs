#include <iostream>
using namespace std;

class Cqueue{
  public :

  int* arr;
  int cap;
  int front = -1;
  int rear = -1;

  Cqueue(int cap){
    this->cap = cap;
    arr = new int[cap];
  }

  void enqueue(int data){
    if ((rear + 1)%cap == front){
      return;
    }
    if(front == -1){
      front = 0;
    }
    rear = (rear+1)%cap;
    arr[rear] = data;
  }

  int dequeue(){
    if(front == -1){
      return -999;
    }

    int res = arr[front];

    if(front == rear){
      front = rear = -1;
    }

    else{
      front = (front+1)%cap;
    }

    return res;

  }


};

int main(){

}