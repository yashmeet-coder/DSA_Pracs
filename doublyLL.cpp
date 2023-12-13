#include <iostream>
using namespace std;

class Node{
  public:

  int data;
  Node* prev;
  Node* next;

  Node(int data){
    this->data = data;
    prev = NULL;
    next = NULL;
  }
};

class DLList{
  public:
  Node* head = NULL;
  Node* tail = NULL;

  void insertAtHead(int data){
    Node* n = new Node(data);
    if(head == NULL){
      head = n;
      tail = n;
      return;
    }
    n->next = head;
    head = n;
  }

  void insertAtPosition(int data, int pos){
    Node* n = new Node(data);
    if(pos == 0){
      insertAtHead(data);
      return;
    }
    int idx = 0;
    int len = getlength();
    Node* curr = head;
    while (idx <= len && idx != pos-1){
      curr = curr->next;
      idx++;
    }
    n->prev = curr;
    n->next = curr->next;
    curr->next = n;
    n->next->prev = n;
  }

  void insertAtTail(int data){
    if(head == NULL){
      insertAtHead(data);
      return;
    }
    Node* n = new Node(data);
    tail->next = n;
    n->prev = tail;
    tail = n;
  }

  int getlength(){
    Node* curr = head;
    int len = 0;
    while(curr != NULL){
      curr = curr->next;
      len++;
    }
    return len;
  }

  void display(){
    Node* curr = head;
    while(curr != NULL){
      cout << curr->data << " ";
      curr = curr->next;
    }
    cout<< endl;
  }

};

int main(){
  DLList list;
  list.insertAtHead(10);
  list.insertAtHead(20);
  list.insertAtHead(30);
  list.display();

  list.insertAtPosition(50,0);
  list.insertAtPosition(70,2);
  list.insertAtPosition(60,1);
  list.insertAtTail(100);
  list.display();


  cout << list.head->data << " " << list.tail->data;
}