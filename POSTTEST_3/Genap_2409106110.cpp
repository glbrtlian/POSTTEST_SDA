#include <iostream>
#include <string>
using namespace std;

struct Node {
    string kodePenerbangan;
    string tujuan;
    string status;
    Node* next;
    Node* prev;

    Node(string kode, string tug, string stat) {
        kodePenerbangan = kode;
        tujuan = tug;
        status = stat;
        next = NULL;
        prev = NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;

// Tambah jadwal manual di akhir
void tambahJadwal() {
    string kode, tujuan, status;
    cout << "\n=== Tambah Jadwal Penerbangan ===" << endl;
    cout << "Masukkan kode penerbangan : ";
    cin >> kode;
    cin.ignore();
    cout << "Masukkan tujuan penerbangan : ";
    getline(cin, tujuan);
    cout << "Masukkan status penerbangan : ";
    getline(cin, status);

    Node* newNode = new Node(kode, tujuan, status);

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    cout << "Jadwal berhasil ditambahkan!" << endl;
}

// Sisip jadwal di posisi tertentu (1-based index)
void sisipJadwal() {
    if (head == NULL) {
        cout << "List kosong, jadwal akan ditambahkan di awal." << endl;
        tambahJadwal();
        return;
    }

    int posisi;
    cout << "\nMasukkan posisi sisip (1 = awal): ";
    cin >> posisi;
    if (posisi < 1) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    cin.ignore();

    string kode, tujuan, status;
    cout << "Masukkan kode penerbangan : ";
    cin >> kode;
    cin.ignore();
    cout << "Masukkan tujuan penerbangan : ";
    getline(cin, tujuan);
    cout << "Masukkan status penerbangan : ";
    getline(cin, status);

    Node* newNode = new Node(kode, tujuan, status);

    if (posisi == 1) {
        // Sisip di awal
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        cout << "Jadwal berhasil disisipkan di posisi 1 (awal)." << endl;
        return;
    }

    // Sisip di tengah atau akhir
    Node* temp = head;
    int idx = 1;
    while (temp != NULL && idx < posisi - 1) {
        temp = temp->next;
        idx++;
    }

    if (temp == NULL) {
        // Posisi lebih besar dari panjang list, sisip di akhir
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        cout << "Posisi melebihi panjang list, jadwal disisipkan di akhir." << endl;
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        } else {
            // Sisip di akhir
            tail = newNode;
        }
        temp->next = newNode;
        cout << "Jadwal berhasil disisipkan di posisi " << posisi << "." << endl;
    }
}

// Tampil semua jadwal dari depan ke belakang
void tampilJadwal() {
    cout << "\n=== Daftar Jadwal Penerbangan (Dari Depan) ===" << endl;
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

// Tampil semua jadwal dari belakang ke depan
void tampilJadwalDariBelakang() {
    cout << "\n=== Daftar Jadwal Penerbangan (Dari Belakang) ===" << endl;
    if (tail == NULL) {
        cout << "Belum ada jadwal." << endl;
        return;
    }

    Node* temp = tail;
    while (temp != NULL) {
        cout << "Kode   : " << temp->kodePenerbangan << endl;
        cout << "Tujuan : " << temp->tujuan << endl;
        cout << "Status : " << temp->status << endl;
        cout << "-----------------------------" << endl;
        temp = temp->prev;
    }
}

// Update jadwal berdasarkan kode penerbangan
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

// Hapus jadwal berdasarkan kode penerbangan
void hapusJadwal() {
    if (head == NULL) {
        cout << "Belum ada jadwal untuk dihapus." << endl;
        return;
    }

    string kode;
    cout << "\nMasukkan kode penerbangan yang ingin dihapus: ";
    cin >> kode;

    Node* temp = head;

    while (temp != NULL && temp->kodePenerbangan != kode) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Jadwal dengan kode " << kode << " tidak ditemukan." << endl;
        return;
    }

    if (temp == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
    } else if (temp == tail) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Jadwal berhasil dihapus!" << endl;
}

// Hapus jadwal paling awal (head)
void hapusJadwalAwal() {
    if (head == NULL) {
        cout << "Belum ada jadwal untuk dihapus." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }
    delete temp;
    cout << "Jadwal paling awal berhasil dihapus!" << endl;
}

// Cari dan tampilkan detail jadwal berdasarkan kode atau tujuan
void cariJadwal() {
    if (head == NULL) {
        cout << "Belum ada jadwal untuk dicari." << endl;
        return;
    }

    cout << "\n=== Cari Jadwal Penerbangan ===" << endl;
    cout << "Cari berdasarkan:" << endl;
    cout << "1. Kode Penerbangan" << endl;
    cout << "2. Tujuan Penerbangan" << endl;
    cout << "Pilih: ";
    int pilihanCari;
    cin >> pilihanCari;
    cin.ignore();

    if (pilihanCari == 1) {
        string kode;
        cout << "Masukkan kode penerbangan: ";
        getline(cin, kode);

        Node* temp = head;
        bool found = false;
        while (temp != NULL) {
            if (temp->kodePenerbangan == kode) {
                cout << "\nDetail Jadwal Ditemukan:" << endl;
                cout << "Kode   : " << temp->kodePenerbangan << endl;
                cout << "Tujuan : " << temp->tujuan << endl;
                cout << "Status : " << temp->status << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "Jadwal dengan kode " << kode << " tidak ditemukan." << endl;
        }
    } else if (pilihanCari == 2) {
        string tujuan;
        cout << "Masukkan tujuan penerbangan: ";
        getline(cin, tujuan);

        Node* temp = head;
        bool found = false;
        cout << "\nHasil pencarian untuk tujuan \"" << tujuan << "\":" << endl;
        while (temp != NULL) {
            if (temp->tujuan == tujuan) {
                cout << "-----------------------------" << endl;
                cout << "Kode   : " << temp->kodePenerbangan << endl;
                cout << "Tujuan : " << temp->tujuan << endl;
                cout << "Status : " << temp->status << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "Tidak ditemukan jadwal dengan tujuan " << tujuan << "." << endl;
        }
    } else {
        cout << "Pilihan tidak valid!" << endl;
    }
}

// Tambah data default menggunakan NIM 2409106110
void tambahDefault() {
    string nim = "2409106110";
    string kode1 = nim.substr(0,4) + "-" + nim.substr(4,4) + "-" + nim.substr(8,2); // "2409-1061-10"
    string kode2 = nim.substr(0,4) + "-" + nim.substr(4,4) + "-11"; // "2409-1061-11"
    string kode3 = nim.substr(0,4) + "-" + nim.substr(4,4) + "-12"; // "2409-1061-12"

    Node* n1 = new Node(kode1, "Jakarta", "On Time");
    Node* n2 = new Node(kode2, "Surabaya", "Delayed");
    Node* n3 = new Node(kode3, "Bali", "Cancelled");

    head = n1;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    tail = n3;
}

int main() {
    tambahDefault(); // tambah data default saat program mulai

    int pilihan;

    do {
        cout << "\n======================================" << endl;
        cout << "      SISTEM JADWAL PENERBANGAN       " << endl;
        cout << "======================================" << endl;
        cout << "1. Tambah Jadwal (Akhir)" << endl;
        cout << "2. Sisip Jadwal (Posisi tertentu)" << endl;
        cout << "3. Tampilkan Jadwal (Dari Depan)" << endl;
        cout << "4. Tampilkan Jadwal (Dari Belakang)" << endl;
        cout << "5. Update Jadwal" << endl;
        cout << "6. Hapus Jadwal (Kode Penerbangan)" << endl;
        cout << "7. Hapus Jadwal Paling Awal" << endl;
        cout << "8. Cari Jadwal" << endl;
        cout << "9. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahJadwal(); break;
            case 2: sisipJadwal(); break;
            case 3: tampilJadwal(); break;
            case 4: tampilJadwalDariBelakang(); break;
            case 5: updateJadwal(); break;
            case 6: hapusJadwal(); break;
            case 7: hapusJadwalAwal(); break;
            case 8: cariJadwal(); break;
            case 9: cout << "Program selesai. Terima kasih!" << endl; break;
            default: cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
    } while (pilihan != 9);

    return 0;
}

