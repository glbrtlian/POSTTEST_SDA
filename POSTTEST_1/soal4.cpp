#include <iostream>
using namespace std;

// Fungsi tukar dengan reference
void swapRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    cout << "Masukkan dua bilangan: ";
    cin >> x >> y;

    cout << "Sebelum ditukar: x=" << x << ", y=" << y << endl;

    swapRef(x, y);

    cout << "Sesudah ditukar: x=" << x << ", y=" << y << endl;

    return 0;
}

