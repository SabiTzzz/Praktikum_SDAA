#include <iostream>
#include <conio.h>
using namespace std;

string user = "Muhammad Arya Fayyadh Razan";
string pass = "2309106010";

void clears() {
    system("cls");
}

struct merchandise {
    string tipe;
    string nama;
    double harga;
    merchandise *next;
};

merchandise *head = nullptr;

bool login(string *user, string *pass, int coba = 0) {
    if (coba == 3) {
        cout << "(!) Anda telah melewati batas percobaan, program berhenti.";
        return false;
    }

    string nama, nim;
    cout << "[  Menu Login  ]" << endl;
    cout << "Nama : ";
    getline(cin, nama);
    cout << "NIM  : ";
    getline(cin, nim);

    if (nama == *user && nim == *pass) {
        cout << "\nLogin berhasil!";
        cout << "\nHalo, " << nama << "!" << endl;
        cout << "\n";
        cout << "=================================" << endl;
        return true;
    } else {
        int percobaan = 2 - coba;
        cout << "\n(!) Login gagal, Nama atau NIM yang anda masukkan salah." << endl;
        if (coba != 2) {          
            cout << "(!) Sisa percobaan anda " << percobaan << " kali lagi.\n" << endl;
        }
        return login(user, pass, coba + 1);
    }
}

void tambahDepan(merchandise *&head) {
    int tipenya;
    merchandise *merchBaru = new merchandise;

    cout << "Tipe barang :\n";
    cout << "1. Jersey\n";
    cout << "2. Apparel\n";
    cout << "3. Aksesoris\n";
    cout << "Pilih tipe barang (1/2/3): ";
    cin >> tipenya;
    cin.ignore();

    switch(tipenya) {
        case 1:
            merchBaru->tipe = "Jersey";
            break;
        case 2:
            merchBaru->tipe = "Apparel";
            break;
        case 3:
            merchBaru->tipe = "Aksesoris";
            break;
        default:
            cout << "(!) Pilihan tidak valid!" << endl;
            delete merchBaru;
            return;
    }

    cout << "Nama barang : ";
    getline(cin, merchBaru->nama);
    cout << "Harga barang : Rp.";
    cin >> merchBaru->harga;
    cin.ignore();
    if (!cin || merchBaru->harga <= 0) {
        cout << "(!) Harga barang tidak valid!" << endl;
        delete merchBaru;
        cin.clear();
        cin.ignore();
        return;
    }

    if (head == nullptr) {
        merchBaru->next = nullptr;
        head = merchBaru;
        return;
    }

    merchBaru->next = head;
    head = merchBaru;
    cout << "Data berhasil ditambahkan!" << endl;
}

void tambahBelakang(merchandise *head) {
    int tipenya;
    merchandise *merchBaru = new merchandise;

    cout << "Tipe barang :\n";
    cout << "1. Jersey\n";
    cout << "2. Apparel\n";
    cout << "3. Aksesoris\n";
    cout << "Pilih tipe barang (1/2/3): ";
    cin >> tipenya;
    cin.ignore();

    switch(tipenya) {
        case 1:
            merchBaru->tipe = "Jersey";
            break;
        case 2:
            merchBaru->tipe = "Apparel";
            break;
        case 3:
            merchBaru->tipe = "Aksesoris";
            break;
        default:
            cout << "(!) Pilihan tidak valid!" << endl;
            delete merchBaru;
            return;
    }

    cout << "Nama barang : ";
    getline(cin, merchBaru->nama);
    cout << "Harga barang : Rp.";
    cin >> merchBaru->harga;
    cin.ignore();
    if (!cin || merchBaru->harga <= 0) {
        cout << "(!) Harga barang tidak valid!" << endl;
        delete merchBaru;
        cin.clear();
        cin.ignore();
        return;
    }

    if (head == nullptr) {
        merchBaru->next = nullptr;
        head = merchBaru;
        return;
    }

    merchandise *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = merchBaru;
    cout << "Data berhasil ditambahkan!" << endl;
}

void tampilkan(merchandise *head) {
    if (head == nullptr) {
        cout << "Data masih kosong." << endl;
    } else {
        merchandise* temp = head;
        int i = 1;
        while (temp != nullptr) {
            cout << "\nData ke-" << i << endl;
            cout << "Tipe barang : " << temp->tipe << endl;
            cout << "Nama barang : " << temp->nama << endl;
            cout << "Harga barang : Rp." << temp->harga << endl;
            i++;
            temp = temp->next;
        }
    }
}

void ubah(merchandise *&head) {
    int pilihan;
    merchandise* temp = head;

    if (head == nullptr) {
        cout << "Data masih kosong." << endl;
        return;
    }

    tampilkan(head);
    cout << "\nPilih nomor data yang ingin diubah : "; cin >> pilihan;
    cin.ignore();

    int i = 1;
    while (temp != nullptr && i < pilihan) {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr) {
        cout << "(!) Data tidak ditemukan!" << endl;
        return;
    }

    int tipenya;
    cout << "Tipe barang :\n";
    cout << "1. Jersey\n";
    cout << "2. Apparel\n";
    cout << "3. Aksesoris\n";
    cout << "Pilih tipe barang (1/2/3): ";
    cin >> tipenya;
    cin.ignore();

    switch (tipenya) {
        case 1:
            temp->tipe = "Jersey";
            break;
        case 2:
            temp->tipe = "Apparel";
            break;
        case 3:
            temp->tipe = "Aksesoris";
            break;
        default:
            cout << "(!) Pilihan tidak valid!" << endl;
            return;
    }

    cout << "Nama barang : ";
    getline(cin, temp->nama);
    cout << "Harga barang : Rp.";
    cin >> temp->harga;
    if (!cin || temp->harga <= 0) {
        cout << "(!) Harga barang tidak valid!" << endl;
        cin.clear();
        cin.ignore();
        return;
    }

    cout << "Data berhasil diubah!" << endl;
}

void hapusDepan(merchandise *&head) {
    if (head == nullptr) {
        cout << "Data masih kosong." << endl;
        return;
    }

    merchandise* temp = head;
    head = head->next;
    delete temp;
    cout << "Data berhasil dihapus!" << endl;
}

void hapusBelakang(merchandise *&head) {
    if (head == nullptr) {
        cout << "Data masih kosong." << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    merchandise* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp-> next;
    temp->next = nullptr;
    cout << "Data berhasil dihapus!" << endl;
}

void menu() {
    string pilihan;
    cout << "\n";
    cout << "   Merchandise Borneo FC\n"
            << "[1] Tambah data (depan) merchandise\n"
            << "[2] Tambah data (belakang) merchandise\n"
            << "[3] Tampilkan data merchandise\n"
            << "[4] Ubah data merchandise\n"
            << "[5] Hapus data (depan) merchandise\n"
            << "[6] Hapus data (belakang) merchandise\n"
            << "Pilih menu (1/2/3/4/0): ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == "1") {
        clears();
        tambahDepan(head);
        menu();
    } else if (pilihan == "2") {
        clears();
        tambahBelakang(head);
        menu();
    } else if (pilihan == "3") {
        clears();
        tampilkan(head);
        cout << "\n";
        string lanjut;
        cout << "Tekan [Enter] untuk ke menu utama...";
        getline(cin, lanjut);
        clears();
        menu();
    } else if (pilihan == "4") {
        clears();
        ubah(head);
        menu();
    } else if (pilihan == "5") {
        clears();
        hapusDepan(head);
        menu();
    } else if (pilihan == "6") {
        clears();
        hapusBelakang(head);
        menu();
    } else if (pilihan == "0") {
        cout << "Terima Kasih & Sampai Jumpa!" << endl;
    } else {
        cout << "(!) Pilihan tidak valid!" << endl;
        menu();
    }
}

int main() {
    merchandise *first = new merchandise{"Jersey", "JERSEY HOME BORNEO FC", 450000, nullptr};
    merchandise *second = new merchandise{"Jersey", "JERSEY AWAY BORNEO FC", 450000, nullptr};
    first->next = second;
    head = first;

    clears();
    if (login(&user, &pass)) {
        menu();
    }

    return 0;
}
