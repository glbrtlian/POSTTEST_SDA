#include <iostream>
#include <string>
using namespace std;

struct Node {
    string kodePenerbangan;
    string tujuan;
    string status;
    Node* next;

    Node(string kode, string tug, string stat) {
        kodePenerbangan = kode;
        tujuan = tug;
        status = stat;
        next = NULL; // pakai NULL agar aman di Dev-C++
    }
};

Node* head = NULL;

// Tambah jadwal manual
void tambahJadwal() {
    string kode, tujuan, status;
    cout << "\n=== Tambah Jadwal Penerbangan ===" << endl;
    cout << "Masukkan kode penerbangan : ";
    cin >> kode;
    cin.ignore(); // buang enter
    cout << "Masukkan tujuan penerbangan : ";
    getline(cin, tujuan);
    cout << "Masukkan status penerbangan : ";
    getline(cin, status);

    Node* newNode = new Node(kode, tujuan, status);

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Jadwal berhasil ditambahkan!" << endl;
}

// Tampil semua jadwal
void tampilJadwal() {
    cout << "\n=== Daftar Jadwal Penerbangan ===" << endl;
    if (head == NULL) {
        cout << "Belum ada jadwal." << endl;
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << "Kode   : " << temp->kodePenerbangan << endl;
        cout << "Tujuan : " << temp->tujuan << endl;
        cout << "Status : " << temp->status << endl;
        cout << "-----------------------------" << endl;
        temp = temp->next;
    }
}

// Update jadwal
void updateJadwal() {
    if (head == NULL) {
        cout << "Belum ada jadwal untuk diupdate." << endl;
        return;
    }

    string kode;
    cout << "\nMasukkan kode penerbangan yang ingin diupdate: ";
    cin >> kode;

    Node* temp = head;
    while (temp != NULL && temp->kodePenerbangan != kode) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Jadwal dengan kode " << kode << " tidak ditemukan." << endl;
        return;
    }

    cin.ignore();
    cout << "Masukkan tujuan baru: ";
    getline(cin, temp->tujuan);
    cout << "Masukkan status baru: ";
    getline(cin, temp->status);

    cout << "Jadwal berhasil diupdate!" << endl;
}

// Hapus jadwal
void hapusJadwal() {
    if (head == NULL) {
        cout << "Belum ada jadwal untuk dihapus." << endl;
        return;
    }

    string kode;
    cout << "\nMasukkan kode penerbangan yang ingin dihapus: ";
    cin >> kode;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->kodePenerbangan != kode) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Jadwal dengan kode " << kode << " tidak ditemukan." << endl;
        return;
    }

    if (prev == NULL) {
        head = temp->next; // hapus head
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Jadwal berhasil dihapus!" << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\n=== Sistem Jadwal Penerbangan ===" << endl;
        cout << "1. Tambah Jadwal" << endl;
        cout << "2. Tampilkan Jadwal" << endl;
        cout << "3. Update Jadwal" << endl;
        cout << "4. Hapus Jadwal" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahJadwal(); break;
            case 2: tampilJadwal(); break;
            case 3: updateJadwal(); break;
            case 4: hapusJadwal(); break;
            case 5: cout << "Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}

