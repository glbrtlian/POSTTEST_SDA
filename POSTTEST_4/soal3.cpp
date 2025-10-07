#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

// Tambah dokumen ke antrian (enqueue)
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node;
    newNode->document = document;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode; // jika kosong, front & rear sama
    } else {
        rear->next = newNode;   // sambungkan ke belakang
        rear = newNode;         // pindah rear ke node baru
    }
}

// Ambil dokumen dari antrian (dequeue)
string dequeue(Node*& front, Node*& rear) {
    if (front == NULL) return ""; // kosong

    Node* temp = front;
    string doc = temp->document;
    front = front->next;
    if (front == NULL) rear = NULL; // jika antrian jadi kosong
    delete temp;
    return doc;
}

// Proses semua dokumen di antrian
void processAllDocuments(Node*& front, Node*& rear) {
    while (front != NULL) {
        cout << "Memproses: " << dequeue(front, rear) << endl;
    }
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}

// ?? Penjelasan:
// Queue memakai prinsip FIFO, jadi dokumen yang pertama masuk akan diproses lebih dulu.

