#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *top = NULL;

void push(int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;
    if(top == NULL) {
        top = newNode;
    } else {
        newNode -> next = top;
        top = newNode;
    }
}

void pop() {
    if (top == NULL) {
        cout << "List kosong!\n";
        return;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
}

void printList() {
    Node *temp = top;
    cout << "Isi Linked List: ";
    while (temp != NULL) {
        cout << temp->value << " => ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int n;
    cout << "==== Impelementasi Stack dengan Linked List====\n";
    cout << "Masukkan 3 angka yang ingin di push : \n";
    for(int i = 0; i < 3; i++) {
        cin >> n;
        push(n);
    }
    printList();
    cout << "Pop stack sebanyak satu kali \n";
    pop();
    printList();
}