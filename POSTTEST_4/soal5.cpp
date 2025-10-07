#include <iostream>
using namespace std;

// ===============================
// Struktur Node untuk Circular Doubly Linked List
// ===============================
// Node berisi data dan dua pointer (next dan prev)
// karena list ini bersifat melingkar (circular)
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// ===============================
// Fungsi untuk menukar posisi head dan tail
// tanpa menukar data, tapi dengan memanipulasi pointer
// ===============================
void exchangeHeadAndTail(Node *&head_ref) {
    // Jika list kosong atau hanya berisi 1 node,
    // maka tidak perlu dilakukan pertukaran
    if (head_ref == NULL || head_ref->next == head_ref) {
        return;
    }

    // Simpan posisi head dan tail sekarang
    Node* head = head_ref;        // node paling awal
    Node* tail = head_ref->prev;  // node paling akhir

    // Simpan node setelah head dan sebelum tail
    Node* head_next = head->next;
    Node* tail_prev = tail->prev;

    // ===============================
    // Tahapan manipulasi pointer:
    // ===============================

    // 1?? Hubungkan node sebelum tail (tail_prev) ke head
    // supaya head nanti berpindah ke posisi tail
    tail_prev->next = head;
    head->prev = tail_prev;

    // 2?? Hubungkan node setelah head (head_next) ke tail
    // supaya tail nanti berpindah ke posisi head
    head_next->prev = tail;
    tail->next = head_next;

    // 3?? Hubungkan head dan tail satu sama lain
    // agar tetap saling terhubung secara melingkar
    head->next = tail;
    tail->prev = head;

    // 4?? Update head_ref menjadi tail
    // karena sekarang tail menjadi node pertama
    head_ref = tail;
}

// ===============================
// Fungsi untuk menampilkan seluruh isi list
// ===============================
void printList(Node *head_ref)
{
    // Jika list kosong, tampilkan pesan
    if (head_ref == NULL)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    // Perulangan dilakukan sampai kembali ke head
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);

    cout << endl;
}

// ===============================
// Fungsi untuk menambah node baru di bagian akhir list
// ===============================
void insertEnd(Node *&head_ref, int data)
{
    // Buat node baru
    Node *newNode = new Node{data, NULL, NULL};

    // Jika list masih kosong, node menunjuk ke dirinya sendiri
    if (head_ref == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // Jika sudah ada data, hubungkan node baru ke tail dan head
    Node *tail = head_ref->prev;
    newNode->next = head_ref;    // node baru mengarah ke head
    newNode->prev = tail;        // node baru mengarah ke tail lama
    head_ref->prev = newNode;    // head terhubung ke node baru
    tail->next = newNode;        // tail lama terhubung ke node baru
}

// ===============================
// Program utama
// ===============================
int main()
{
    Node *head = NULL;

    // Membuat list berisi 1 2 3 4 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    // Menampilkan list sebelum pertukaran
    cout << "List sebelum exchange: ";
    printList(head);

    // Menukar posisi head dan tail (tanpa menukar data)
    exchangeHeadAndTail(head);

    // Menampilkan list setelah pertukaran
    cout << "List setelah exchange head dan tail: ";
    // Output yang diharapkan: 5 2 3 4 1
    printList(head);

    return 0;
}

