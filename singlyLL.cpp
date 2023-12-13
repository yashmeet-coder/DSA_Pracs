#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;

  node(int data){
    this->data = data;
    this->next = NULL;
  }
};

class SLList{
  public:
  node* head = NULL;

  void insertAtHead(int data){
    node* n = new node(data);
    n->next = head;
    head = n;
    return;

  }

  int getlength(){
    int length = 0;
    node* curr = head;
    while (curr != NULL){
      curr = curr->next;
      length++;
    } 
    return length;
  }

  void insertAtPosition(int data, int pos){
    node* curr = head;
    int idx = 0;
    int len = getlength();
    if(pos == 0){
      insertAtHead(data);
      return;
    }
    while(pos <= len && idx != pos-1){
      idx++;
      curr = curr->next;
    }
    node* n = new node(data);
    node* temp = curr->next;
    curr->next = n;
    n->next = temp;

  }

  void removeAtHead(){
    if(head == NULL){
      cout << "empty list";
      return;
    }
    node* temp = head;
    head = head->next;
    delete(temp);
  }

  void removeAtPosition(int pos){
    node* curr = head;
    if (head == NULL){
      cout <<"empty list";
      return;
    }
    if(pos == 0){
      removeAtHead();
      return;
    }
    int len = getlength();
    int idx = 0;
    while(pos < len && idx != pos-1){
      curr = curr->next;
      idx++;
    }
    node* temp = curr->next;
    curr->next = curr->next->next;
    delete(temp);
  }

  node* search(int x){
    node* curr = head;

    while(curr != NULL){
      if(curr->data == x){
        return curr;
      }
      curr = curr->next;
    }
    return nullptr;
  }

  void concat(SLList* l){
    node* curr = head;
    if(head == NULL){
      head = l->head;
      return;
    }
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = l->head;
    
  }

  void display(){
    if(head == NULL){
      cout << "empty list";
    }
    node* curr = head;
    while (curr != NULL){
      cout << curr->data << " ";
      curr = curr->next;
    }
    cout << endl;
    
  }
};

int main(){
  SLList* list = new SLList();
  list->display();
  list->insertAtHead(10);
  list->insertAtHead(20);
  list->display();
  list->insertAtPosition(30,1);
  list->insertAtPosition(40,2);
  list->insertAtPosition(50,1);
  list->display();
  list->removeAtHead();
  list->display();
  list->removeAtPosition(0);
  list->display();
  cout << list->search(40) << " " << list->search(70);

  SLList* list2 = new SLList();
  list2->display();
  list2->insertAtHead(15);
  list2->insertAtHead(25);
  list2->display();

  list->concat(list2);
  list->display();

}