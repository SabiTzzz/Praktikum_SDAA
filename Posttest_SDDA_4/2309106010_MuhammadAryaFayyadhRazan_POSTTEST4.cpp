#include <iostream>
#include <conio.h>
using namespace std;

// string user = "Muhammad Arya Fayyadh Razan";
// string pass = "2309106010";
string user = "";
string pass = "";

void clears() {
    system("cls");
}

struct merchandise {
    string tipe;
    string nama;
    double harga;
    merchandise *next;
};

merchandise *head = nullptr, *tail = nullptr;

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

void push(merchandise *&head) {
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

    merchBaru->next = head;
    head = merchBaru;
    if (tail == nullptr) {
        tail = head;
    }
    cout << "Data berhasil ditambahkan!" << endl;
}

void pop(merchandise *&head) {
    if (head == nullptr) {
        cout << "Data masih kosong." << endl;
        return;
    }

    merchandise* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    cout << "Data berhasil dihapus!" << endl;
}

void peek(merchandise *head) {
    if (head == nullptr) {
        cout << "Data masih kosong." << endl;
    } else {
        cout << "\nData teratas (Stack):" << endl;
        cout << "Tipe barang : " << head->tipe << endl;
        cout << "Nama barang : " << head->nama << endl;
        cout << "Harga barang : Rp." << head->harga << endl;
    }
}

void enqueue(merchandise *&tail) {
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

    merchBaru->next = nullptr;
    if (tail != nullptr) {
        tail->next = merchBaru;
    }
    tail = merchBaru;
    if (head == nullptr) {
        head = tail;
    }
    cout << "Data berhasil ditambahkan" << endl;
}

void dequeue(merchandise *&head) {
    if (head == nullptr) {
        cout << "Data masih kosong." << endl;
        return;
    }

    merchandise* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    cout << "Data berhasil dihapus dari Queue (dequeue)!" << endl;
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

void menu() {
    string pilihan;
    cout << "\n";
    cout << "   Merchandise Borneo FC\n"
            << "[1] Push (Tambah data depan)\n"
            << "[2] Pop (Hapus data depan)\n"
            << "[3] Peek (Lihat data teratas)\n"
            << "[4] Enqueue (Tambah data belakang)\n"
            << "[5] Dequeue (Hapus data depan)\n"
            << "[6] Tampilkan data\n"
            << "[0] Keluar\n"
            << "Pilih menu (1/2/3/4/5/6/0): ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == "1") {
        clears();
        push(head);
        menu();
    } else if (pilihan == "2") {
        clears();
        pop(head);
        menu();
    } else if (pilihan == "3") {
        clears();
        peek(head);
        menu();
    } else if (pilihan == "4") {
        clears();
        enqueue(tail);
        menu();
    } else if (pilihan == "5") {
        clears();
        dequeue(head);
        menu();
    } else if (pilihan == "6") {
        clears();
        tampilkan(head);
        cout << "\n";
        string lanjut;
        cout << "Tekan [Enter] untuk ke menu utama...";
        getline(cin, lanjut);
        clears();
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
    tail = second;

    clears();
    if (login(&user, &pass)) {
        menu();
    }

    return 0;
}