#include <iostream>
using namespace std;

template <typename T> class Node{
  public:
  T data;
  Node<T>* next;

  Node(T data){
    this->data = data;
    this->next = NULL;
  }
};

template <typename T> class Lstack{
  public:
  Node<T>* head;

  Lstack(){
    head = NULL;
  }

  void push(T ele){
    Node<T>* n = new Node<T>(ele);
    n->next = head;
    head = n;
  }

  void pop(){
    if (head == NULL){
      cout << "empty" << endl;
      return;
    }
    cout << head->data << endl;
    Node<T>* temp = head;
    head = head->next;
    delete(temp);

  }

  T top(){
    return head->data;
  }
};


int main(){
  Lstack<int> list;
  list.push(10);
  list.push(40);
  list.push(50);

  for (int i = 0; i < 3; i++){
    list.pop();
  }
}