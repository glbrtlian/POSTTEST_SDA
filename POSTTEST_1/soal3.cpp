#include <iostream>
#include <algorithm>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

bool cmp(Mahasiswa a, Mahasiswa b) {
    return a.ipk < b.ipk; // ascending
}

int main() {
    const int N = 4;
    Mahasiswa mhs[N];

    cout << "Input data mahasiswa:\n";
    for (int i = 0; i < N; i++) {
        cout << "Nama: "; cin >> mhs[i].nama;
        cout << "NIM : "; cin >> mhs[i].nim;
        cout << "IPK : "; cin >> mhs[i].ipk;
    }

    sort(mhs, mhs + N, cmp);

    cout << "\nData mahasiswa setelah diurutkan (IPK ascending):\n";
    for (int i = 0; i < N; i++) {
        cout << mhs[i].nama << " | " << mhs[i].nim << " | " << mhs[i].ipk << endl;
    }
}
