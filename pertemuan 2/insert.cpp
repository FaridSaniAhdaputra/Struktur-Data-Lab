#include <iostream>
using namespace std;

// Deklarasi sebuah struct node
struct node {
    int value;
    node *next;
};

node *head = NULL;
node *tail = NULL;

// Insert di depan
void insertFirst(int n) {
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL) {
    head = newNode;
    tail = head;
    } else {
    newNode -> next = head;
    head = newNode;
}
}


// Insert di belakang
void insertClass(int n) {
      node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL){
        head = newNode;
        tail = head;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }
}

// Insert dengan nilai tertentu 
void insertAfter(int n, int after) {
    if (head == NULL) {
        cout << "List kosong, insert di depan dulu\n";
        return;
    }

    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;
    int check = after;

    node *p = head;
    while (p != NULL && p -> value != check) {
        p = p -> next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check << "tidak ditemukan\n";
        delete newNode;
    } else {
        newNode -> next = p -> next;
        p -> next = newNode;
        if (p == tail) {
            tail = newNode;
        }
    }
  }

  // Cetak linked list
  void printList() {
       node *temp = head;
       cout << " isi dari linked list : ";
       while (temp != NULL) {
        cout << temp -> value << " -> ";
        temp = temp -> next;
       }
       cout << "NULL\n";
  }


int main() {
    system("clear");
    insertClass(10);
    insertClass(20);
    insertClass(30);            
    insertAfter(25, 20);
    insertFirst(5);      
    printList();
    return 0;
}