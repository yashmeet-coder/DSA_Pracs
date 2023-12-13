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

class CLList {
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

  void insertAfter(int data, int y){
    node* n = new node(data);
    if (tail == NULL){
      return;
    }

    if(tail->data == y){
      insertAtFront(data);
      return;
    }

    node* curr = tail->next;
    int flag = 0;

    while (curr != tail){
      if(curr->data == y){
        flag = 1;
        break;
      }
      curr = curr->next;
    }
    if(flag == 1){
      node* temp = curr->next;
      curr->next = n;
      n->next = temp;
    }

    else{
      return;
    }
  }

  void insertAtBack(int data){
    if(tail == NULL){
      insertAtFront(data);
      return;
    }
    node* n = new node(data);
    insertAtFront(data);
    tail = tail->next;
  }

  void removeAtBack(){
    if(tail == NULL){
      return;
    }
    if(tail->next = tail){
      tail = NULL;
      return;
    }

    node* curr = tail;
    while (tail->next != curr){
      tail = tail->next;
    }

    node* temp = curr->next;

    tail->next = temp;
    curr->next = NULL;
    delete(curr);

    // node* curr = tail->next;
    // while(curr->next != tail){
    //   curr = curr->next;
    // }
    // tail = curr;
    // node* temp = curr->next;
    // tail->next = tail->next->next;
    // delete(temp);
  }

  void removeAtFront(){
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
  CLList list;
  list.insertAtFront(20);
  list.insertAtFront(30);
  list.insertAtFront(40);

  list.display();

  list.insertAfter(70,20);
  list.insertAfter(50,70);
  list.insertAfter(60,30);
  list.display();

  list.insertAtBack(90);
  list.insertAfter(10,40);
  list.display();

  list.removeAtFront();
  list.display();

  cout << list.tail->data;
}