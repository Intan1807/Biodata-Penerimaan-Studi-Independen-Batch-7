#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Struktur data untuk menyimpan biodata mahasiswa
struct Mahasiswa {
    string nama;
    string prodi;
    string NIM;
    string usia;
    string lahir;
    string alamat;
    string programIndependen;
};

// Fungsi untuk meminta input dari user
void inputBiodata(Mahasiswa &mhs) {
    cout << "Masukkan Nama Mahasiswa: ";
    getline(cin, mhs.nama);
    cout << "Masukkan Program Studi: ";
    getline(cin, mhs.prodi);
    cout << "Masukkan NIM Mahasiswa: ";
    getline(cin, mhs.NIM);
    cout << "Masukkan Usia: ";
    getline(cin, mhs.usia);
    cout << "Masukkan Tanggal Lahir: ";
    getline(cin, mhs.lahir);
    cout << "Masukkan Alamat Rumah: ";
    getline(cin, mhs.alamat);
    cout << "Masukkan Program Studi Independen: ";
    getline(cin, mhs.programIndependen);
    cout << endl;
}

// Fungsi untuk menampilkan biodata mahasiswa
void tampilkanBiodata(const Mahasiswa &mhs) {
    cout << "______________________________________________________________________________________" << endl;
    cout << "HASIL DETAIL BIODATA PENERIMA STUDI INDEPENDEN BATCH 7" << endl;
    cout << "Nama                             = " << mhs.nama << endl;
    cout << "Prodi                            = " << mhs.prodi << endl;
    cout << "NIM                              = " << mhs.NIM << endl;
    cout << "Usia                             = " << mhs.usia << endl;
    cout << "Tanggal Lahir                    = " << mhs.lahir << endl;
    cout << "Alamat                           = " << mhs.alamat << endl;
    cout << "Program Studi Independen         = " << mhs.programIndependen << endl;
    cout << "_______________________________________________________________________________________" << endl;
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
int cariMahasiswa(const Mahasiswa daftarMahasiswa[], int jumlah, const string &nim) {
    for (int i = 0; i < jumlah; i++) {
        if (daftarMahasiswa[i].NIM == nim) {
            return i; // Mengembalikan index mahasiswa jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}

// Fungsi untuk mengedit biodata mahasiswa
void editBiodata(Mahasiswa &mhs) {
    cout << "Masukkan Nama Mahasiswa: ";
    getline(cin, mhs.nama);
    cout << "Masukkan Program Studi: ";
    getline(cin, mhs.prodi);
    cout << "Masukkan NIM Mahasiswa: ";
    getline(cin, mhs.NIM);
    cout << "Masukkan Usia: ";
    getline(cin, mhs.usia);
    cout << "Masukkan Tanggal Lahir: ";
    getline(cin, mhs.lahir);
    cout << "Masukkan Alamat Rumah: ";
    getline(cin, mhs.alamat);
    cout << "Masukkan Program Studi Independen: ";
    getline(cin, mhs.programIndependen);
}

// Fungsi untuk menghapus biodata mahasiswa
void hapusMahasiswa(Mahasiswa daftarMahasiswa[], int &jumlah, int index) {
    for (int i = index; i < jumlah - 1; i++) {
        daftarMahasiswa[i] = daftarMahasiswa[i + 1];
    }
    jumlah--; // Mengurangi jumlah mahasiswa
}

// Fungsi untuk menampilkan menu utama
void tampilkanMenu() {
    cout << "\n======================== MENU UTAMA =========================" << endl;
    cout << "1. Tambah Biodata Mahasiswa" << endl;
    cout << "2. Lihat Semua Biodata Mahasiswa" << endl;
    cout << "3. Cari Biodata Mahasiswa Berdasarkan NIM" << endl;
    cout << "4. Edit Biodata Mahasiswa" << endl;
    cout << "5. Hapus Biodata Mahasiswa" << endl;
    cout << "6. Keluar" << endl;
    cout << "============================================================" << endl;
}

int main() {
    int jumlahMahasiswa = 0;
    const int kapasitasMahasiswa = 100;
    Mahasiswa daftarMahasiswa[kapasitasMahasiswa]; // Array untuk menyimpan data mahasiswa
    char pilihan;

    cout << "                                         BIODATA PENERIMAAN STUDI INDEPENDEN BATCH 7                         " << endl;

    do {
        tampilkanMenu();
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer setelah input menu

        switch (pilihan) {
            case '1':
                if (jumlahMahasiswa < kapasitasMahasiswa) {
                    cout << "\n--- Masukkan Biodata Mahasiswa ke-" << (jumlahMahasiswa + 1) << " ---" << endl;
                    inputBiodata(daftarMahasiswa[jumlahMahasiswa]);
                    jumlahMahasiswa++;
                } else {
                    cout << "Daftar mahasiswa sudah penuh!" << endl;
                }
                break;

            case '2':
                cout << "\n========================= DETAIL BIODATA MAHASISWA =========================" << endl;
                for (int i = 0; i < jumlahMahasiswa; i++) {
                    cout << "\n--- Biodata Mahasiswa ke-" << (i + 1) << " ---" << endl;
                    tampilkanBiodata(daftarMahasiswa[i]);
                }
                break;

            case '3': {
                string nim;
                cout << "Masukkan NIM mahasiswa yang dicari: ";
                getline(cin, nim);
                int index = cariMahasiswa(daftarMahasiswa, jumlahMahasiswa, nim);
                if (index != -1) {
                    cout << "\n--- Biodata Ditemukan ---" << endl;
                    tampilkanBiodata(daftarMahasiswa[index]);
                } else {
                    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan!" << endl;
                }
                break;
            }

            case '4': {
                string nim;
                cout << "Masukkan NIM mahasiswa yang ingin diedit: ";
                getline(cin, nim);
                int index = cariMahasiswa(daftarMahasiswa, jumlahMahasiswa, nim);
                if (index != -1) {
                    cout << "\n--- Mengedit Biodata Mahasiswa ---" << endl;
                    editBiodata(daftarMahasiswa[index]);
                } else {
                    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan!" << endl;
                }
                break;
            }

            case '5': {
                string nim;
                cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
                getline(cin, nim);
                int index = cariMahasiswa(daftarMahasiswa, jumlahMahasiswa, nim);
                if (index != -1) {
                    hapusMahasiswa(daftarMahasiswa, jumlahMahasiswa, index);
                    cout << "Biodata mahasiswa dengan NIM " << nim << " telah dihapus!" << endl;
                } else {
                    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan!" << endl;
                }
                break;
            }

            case '6':
                cout << "Jumlah mahasiswa yang telah ditambahkan: " << jumlahMahasiswa << endl;
                cout << "Selesai! Terima kasih sudah menggunakan pemrograman ini!" << endl;
                break;

            default:
                cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != '6');

    return 0;
}
