#include <iostream>
using namespace std;

#define MAX 6
int queue[MAX];
int front = -1, rear =-1;

// enqueue
void enqueue(int value) {
    if(rear == MAX -1) {
        cout << "Queue penuh !\n";
    } else{
        if (front == -1) front =0;
        rear++;
        queue[rear] = value;
        cout << value << " masuk ke queue.\n";
    }
}

//dequeue
void dequeue() {
    if(front == -1 || front > rear) {
        cout << "Queueu kosong !\n";
    } else {
        cout << queue[front] << " keluar dari queue\n";
        front++;
    }
}

//nampilkan queue
void display(){
    if (front == -1 || front > rear){
        cout << "Queue kosong !\n";
    } else {
        cout << "isi queue :";
        for(int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    
    display();
    enqueue(6);
    display();

    dequeue();
    display();

    return 0;
}