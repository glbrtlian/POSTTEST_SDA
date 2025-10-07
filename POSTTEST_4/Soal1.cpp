#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi untuk menambah elemen ke Stack (push)
void push(Node*& top, char data) {
    Node* newNode = new Node;  // buat node baru
    newNode->data = data;      // simpan karakter
    newNode->next = top;       // sambungkan ke top lama
    top = newNode;             // jadikan node baru sebagai top
}

// Fungsi untuk menghapus elemen dari Stack (pop)
char pop(Node*& top) {
    if (top == NULL) return '\0'; // jika kosong, return karakter kosong
    Node* temp = top;             // simpan alamat top
    char poppedValue = temp->data;// ambil datanya
    top = top->next;              // pindah top ke bawahnya
    delete temp;                  // hapus node lama
    return poppedValue;
}

// Fungsi membalik string menggunakan stack
string reverseString(string s) {
    Node* stackTop = NULL;
    string reversed = "";

    // masukkan tiap karakter ke stack
    for (int i = 0; i < s.length(); i++) {
        push(stackTop, s[i]);
    }

    // keluarkan tiap karakter dari stack
    while (stackTop != NULL) {
        reversed += pop(stackTop);
    }

    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; // Output: ataD rutkurtS
    return 0;
}

// ?? Penjelasan:
// Karena Stack bersifat LIFO (masuk terakhir keluar pertama),
// maka saat semua karakter dipop, hasilnya jadi kebalikan dari string aslinya.

