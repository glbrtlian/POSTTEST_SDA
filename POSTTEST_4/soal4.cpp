#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Fungsi untuk menyisipkan data agar tetap urut
void sortedInsert(Node*& head_ref, int data) {
    Node* newNode = new Node;
    newNode->data = data;

    // Jika list kosong
    if (head_ref == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node* current = head_ref;

    // Jika data baru lebih kecil dari head
    if (data < head_ref->data) {
        Node* tail = head_ref->prev;
        newNode->next = head_ref;
        newNode->prev = tail;
        tail->next = newNode;
        head_ref->prev = newNode;
        head_ref = newNode;
        return;
    }

    // Sisipkan di tengah/akhir
    while (current->next != head_ref && current->next->data < data)
        current = current->next;

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

void printList(Node* head_ref) {
    if (head_ref == NULL) {
        cout << "List kosong" << endl;
        return;
    }
    Node* temp = head_ref;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head_ref);
    cout << endl;
}

int main() {
    Node* head = NULL;

    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);

    return 0;
}

// ?? Penjelasan:
// Data baru dimasukkan pada posisi yang membuat list tetap urut naik.
// Karena sirkular, node terakhir terhubung ke node pertama lagi.

