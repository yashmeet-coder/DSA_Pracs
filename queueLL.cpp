#include <iostream>
using namespace std;

class node {
  public :
  int data;
  node* next;

  node (int data){
    this->data = data;
    this->next = NULL;
  }
};

class CLqueue {
  public : 
  node* tail = NULL;

  void insertAtFront(int data){
    node* n = new node(data);
    if(tail == NULL){
      tail = n;
      n->next = n;
      return;
    }
    node* temp = tail->next;
    tail->next = n;
    n->next = temp;
  }

  void enqueue(int data){
    if(tail == NULL){
      insertAtFront(data);
      return;
    }
    node* n = new node(data);
    insertAtFront(data);
    tail = tail->next;
  }

  void dequeue(){
    if (tail == NULL){
      return;
    }
    if (tail->next == tail){
      tail = NULL;
      return;
    }
    node* temp = tail->next;
    tail->next = temp->next;
    temp->next = NULL;
    delete(temp);
  }

  void display(){
    node* curr = tail->next;
    while(curr != tail){
      cout << curr->data << " ";
      curr = curr->next;
    }
    cout << curr->data << endl;
  }
};

int main(){
  CLqueue list;
  list.enqueue(20);
  list.enqueue(30);
  list.enqueue(40);
  list.enqueue(90);
  list.display();

  list.dequeue();
  list.display();

}