#include <iostream>
#include <string>

using namespace std;

int main() {
    string menuNama[] = {"Nasi Goreng", "Mie Goreng", "Ayam Goreng", "Es Teh Manis", "Es Jeruk"};
    int menuHarga[] = {15000, 12000, 18000, 5000, 6000};
    int jumlahMenu = 5;

    string username, password, namaPembeli;
    char pilihanMember;
    double diskon = 0.0;
    bool statusValid = false;

    cout << "SELAMAT DATANG DI RESTORAN SEDERHANA" << endl;
    while (!statusValid) {
        cout << "Apakah anda member? (y/n): ";
        cin >> pilihanMember;

        if (pilihanMember == 'y' || pilihanMember == 'Y') {
            cout << "Username : ";
            cin >> username;
            cout << "Password : ";
            cin >> password;

            if (username == "sansan" && password == "11223344") {
                namaPembeli = "Hassan";
                diskon = 0.05;
                cout << "Login Berhasil! Selamat Datang, " << namaPembeli << " (Member - Diskon 5%)" << endl;
                statusValid = true;
            } else if (username == "jojo" && password == "44332211") {
                namaPembeli = "Joshe";
                diskon = 0.05;
                cout << "Login Berhasil! Selamat Datang, " << namaPembeli << " (Member - Diskon 5%)" << endl;
                statusValid = true;
            } else {
                cout << "Username/Password salah, anda mungkin bukan member." << endl;
            }
        } else if (pilihanMember == 'n' || pilihanMember == 'N') {
            cout << "Masukkan Nama Pembeli : ";
            cin.ignore();
            getline(cin, namaPembeli);
            diskon = 0.0; 
            cout << "Status: Non-Member (Diskon 0%)" << endl;
            statusValid = true; 
        } else {
            cout << "Pilihan tidak valid! Kembali ke pertanyaan awal." << endl;
        }
    }

    cout << endl;
    cout << "Daftar Menu:" << endl;
    for (int i = 0; i < jumlahMenu; i++) {
        cout << i + 1 << ". " << menuNama[i] << " - Rp" << menuHarga[i] << endl;
    }

    int totalBelanja = 0;
    char lanjutBeli = 'y';

    while (lanjutBeli == 'y' || lanjutBeli == 'Y') { 
        int idPilihan, jumlahPorsi;

        cout << endl << "Masukkan ID Menu (1-5): ";
        cin >> idPilihan;

        cout << "Masukkan Jumlah Porsi: ";
        cin >> jumlahPorsi;

        switch (idPilihan) {
            case 1:
                totalBelanja += menuHarga[0] * jumlahPorsi;
                cout << jumlahPorsi << "x " << menuNama[0] << " ditambahkan." << endl;
                break;
            case 2:
                totalBelanja += menuHarga[1] * jumlahPorsi;
                cout << jumlahPorsi << "x " << menuNama[1] << " ditambahkan." << endl;
                break;
            case 3:
                totalBelanja += menuHarga[2] * jumlahPorsi;
                cout << jumlahPorsi << "x " << menuNama[2] << " ditambahkan." << endl;
                break;
            case 4:
                totalBelanja += menuHarga[3] * jumlahPorsi;
                cout << jumlahPorsi << "x " << menuNama[3] << " ditambahkan." << endl;
                break;
            case 5:
                totalBelanja += menuHarga[4] * jumlahPorsi;
                cout << jumlahPorsi << "x " << menuNama[4] << " ditambahkan." << endl;
                break;
            default:
                cout << "ID Menu tidak valid!" << endl;
                break;
        }

        cout << "Tambah pesanan lain? (y/n): ";
        cin >> lanjutBeli;
    }

    int nominalDiskon = totalBelanja * diskon;
    int totalBayar = totalBelanja - nominalDiskon;

    cout << endl;
    cout << "Ringkasan Pembayaran:" << endl;
    cout << "Nama Pembeli : " << namaPembeli << endl;
    cout << "Total Belanja: Rp" << totalBelanja << endl;
    cout << "Diskon       : Rp" << nominalDiskon << endl;
    cout << "Total Bayar  : Rp" << totalBayar << endl;

    int nominalUang = 0;
    cout << endl << "Masukkan Nominal Uang Pembayaran: Rp";
    cin >> nominalUang;

    while (nominalUang < totalBayar) {
        cout << "Uang tidak cukup! Total bayar: Rp" << totalBayar << endl;
        cout << "Masukkan kembali Nominal Uang: Rp";
        cin >> nominalUang;
    }

    int kembalian = nominalUang - totalBayar; 
    cout << endl;
    cout << "NOTA PEMBAYARAN" << endl;
    cout << "Nama Pembeli  : " << namaPembeli << endl;
    cout << "Total Bayar   : Rp" << totalBayar << endl;
    cout << "Uang Diterima : Rp" << nominalUang << endl;
    cout << "Kembalian     : Rp" << kembalian << endl; 
    cout << "PEMBAYARAN BERHASIL DILAKUKAN!" << endl; 
}