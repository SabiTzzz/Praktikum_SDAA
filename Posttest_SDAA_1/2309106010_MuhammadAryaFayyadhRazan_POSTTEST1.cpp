#include <iostream>
using namespace std;

// Rekursif menghitung koefisien binomial untuk segitiga pascal
int koefisien_binomial (int baris, int kolom) {
    if (kolom == 0 || kolom == baris) {
        return 1;
    } else {
        return koefisien_binomial(baris - 1, kolom - 1) + koefisien_binomial(baris - 1, kolom);
    }
}

// Mencetak visualisasi segitiga pascal
void print_pascal (int tingkat) {
    for (int i = 0; i < tingkat; i++) {
        for (int j = 0; j <= i; j++) {
            cout << koefisien_binomial(i, j) << " "; 
        }
        cout << endl;
    }
}

// Berisi tingkat untuk tingkatan segitiga pascal
int main() {
    int tingkat = 3;
    print_pascal(tingkat);
    return 0;
}