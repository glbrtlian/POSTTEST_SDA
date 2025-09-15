#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int matriks[N][N];

    cout << "Input matriks 3x3:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matriks[i][j];
        }
    }

    int jumlah = 0;
    for (int j = 0; j < N; j++) {
        jumlah += matriks[2][j]; // baris ke-2 (indeks terakhir)
    }

    cout << "\nMatriks:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nJumlah elemen baris genap (baris ke-2): " << jumlah << endl;
}
