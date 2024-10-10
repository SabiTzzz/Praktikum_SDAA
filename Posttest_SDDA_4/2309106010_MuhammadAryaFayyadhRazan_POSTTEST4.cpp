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

int nextID = 1;

struct merchandise {
    int id;
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

bool kosong() {
    return head == nullptr;
}

void push(merchandise *&head) {
    int tipenya;
    merchandise *merchBaru = new merchandise;

    merchBaru->id = nextID++;

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
    if (kosong()) {
        cout << "Data masih kosong." << endl;
        return;
    }

    merchandise* temp = head;
    head = head->next;
    if (kosong()) {
        tail = nullptr;
    }
    delete temp;
    cout << "Data berhasil dihapus!" << endl;
}

void peek(merchandise *head) {
    if (kosong()) {
        cout << "Data masih kosong." << endl;
    } else {
        cout << "\nData teratas" << endl;
        cout << "ID barang : " << head->id << endl;
        cout << "Tipe barang : " << head->tipe << endl;
        cout << "Nama barang : " << head->nama << endl;
        cout << "Harga barang : Rp." << head->harga << endl;
    }
}

void enqueue(merchandise *&tail) {
    int tipenya;
    merchandise *merchBaru = new merchandise;

    merchBaru->id = nextID++;

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
    if (kosong()) {
        head = tail;
    }
    cout << "Data berhasil ditambahkan" << endl;
}

void dequeue(merchandise *&head) {
    if (kosong()) {
        cout << "Data masih kosong." << endl;
        return;
    }

    merchandise* temp = head;
    head = head->next;
    if (kosong()) {
        tail = nullptr;
    }
    delete temp;
    cout << "Data berhasil dihapus dari Queue (dequeue)!" << endl;
}

void tampilkan(merchandise *head) {
    if (kosong()) {
        cout << "Data masih kosong." << endl;
    } else {
        merchandise* temp = head;
        int i = 1;
        while (temp != nullptr) {
            cout << "\nData ke-" << i << endl;
            cout << "ID barang : " << temp->id << endl;
            cout << "Tipe barang : " << temp->tipe << endl;
            cout << "Nama barang : " << temp->nama << endl;
            cout << "Harga barang : Rp." << temp->harga << endl;
            i++;
            temp = temp->next;
        }
    }
}

void ubah(merchandise *head) {
    if (kosong()) {
        cout << "Data masih kosong." << endl;
        return;
    }

    int idBarang;
    cout << "Masukkan ID barang yang ingin diubah: ";
    cin >> idBarang;
    cin.ignore();

    merchandise *temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->id == idBarang) {
            found = true;
            int tipenya;
            cout << "Barang ditemukan!" << endl;
            cout << "ID barang sekarang : " << temp->id << endl;
            cout << "Tipe barang sekarang : " << temp->tipe << endl;
            cout << "Nama barang sekarang : " << temp->nama << endl;
            cout << "Harga barang sekarang : Rp." << temp->harga << endl;

            cout << "\nTipe barang baru:\n";
            cout << "1. Jersey\n";
            cout << "2. Apparel\n";
            cout << "3. Aksesoris\n";
            cout << "Pilih tipe barang (1/2/3): ";
            cin >> tipenya;
            cin.ignore();

            switch(tipenya) {
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

            cout << "Nama barang baru: ";
            getline(cin, temp->nama);

            cout << "Harga barang baru: Rp.";
            cin >> temp->harga;
            cin.ignore();
            if (!cin || temp->harga <= 0) {
                cout << "(!) Harga barang tidak valid!" << endl;
                cin.clear();
                cin.ignore();
                return;
            }

            cout << "Data berhasil diubah!" << endl;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Barang dengan ID '" << idBarang << "' tidak ditemukan." << endl;
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
            << "[7] Ubah data\n"
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
        cout << "\n";
        string lanjut;
        cout << "Tekan [Enter] untuk ke menu utama...";
        getline(cin, lanjut);
        clears();
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
    } else if (pilihan == "7"){
        clears();
        tampilkan(head);
        ubah(head);
        menu();
    } else if (pilihan == "0") {
        cout << "Terima Kasih & Sampai Jumpa!" << endl;
    } else {
        cout << "(!) Pilihan tidak valid!" << endl;
        menu();
    }
}

int main() {
    merchandise *first = new merchandise{nextID++, "Jersey", "JERSEY HOME BORNEO FC", 450000, nullptr};
    merchandise *second = new merchandise{nextID++, "Jersey", "JERSEY AWAY BORNEO FC", 450000, nullptr};
    first->next = second;
    head = first;
    tail = second;

    clears();
    if (login(&user, &pass)) {
        menu();
    }

    return 0;
}
