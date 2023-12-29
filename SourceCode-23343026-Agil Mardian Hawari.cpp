#include <iostream>

using namespace std;

const int MAX_MAHASISWA = 40;

typedef struct
{
    string nama;
    char jenisKelamin;
    int umur;
    string nim;
    string prodi;
    string departemen;
    float ipk;
} Mahasiswa;

Mahasiswa data[MAX_MAHASISWA];
int totalData = 0;

// Fungsi untuk menambah data mahasiswa
void tambahMahasiswa()
{

    cout << "\nMasukkan nama: ";
    cin.ignore();
    getline(cin, data[totalData].nama);
    cout << "Masukkan nim: ";
    cin >> data[totalData].nim;
    cin.ignore();
    cout << "Masukkan prodi: ";
    getline(cin, data[totalData].prodi);
    cout << "Masukkan departemen: ";
    getline(cin, data[totalData].departemen);
    cout << "Masukkan jenis kelamin (L/P): ";
    cin >> data[totalData].jenisKelamin;
    cout << "Masukkan umur: ";
    cin >> data[totalData].umur;

    data[totalData].ipk = 0;

    totalData++;
}

// Fungsi untuk memperbarui nilai IPK mahasiswa dengan memilih dari nim
void updateIPK()
{
    string nimInput;
    cout << "\nMasukkan nim mahasiswa: ";
    cin >> nimInput;

    for (int i = 0; i < totalData; i++)
    {
        if (nimInput == data[i].nim)
        {
            // Memasukkan rata-rata nilai mahasiswa, nilai UTS, dan nilai UAS
            float rataRata, nilaiUTS, nilaiUAS;
            cout << "Masukkan rata-rata nilai harian mahasiswa: ";
            cin >> rataRata;
            cout << "Masukkan nilai UTS mahasiswa: ";
            cin >> nilaiUTS;
            cout << "Masukkan nilai UAS mahasiswa: ";
            cin >> nilaiUAS;

            // Menghitung IPK dengan nilai tertinggi 4.0
            data[i].ipk = (rataRata * 0.4 + nilaiUTS * 0.3 + nilaiUAS * 0.3) / 25;

            cout << "IPK mahasiswa dengan nim " << nimInput << " berhasil diperbarui." << endl;
            return;
        }
    }

    cout << "NIM tidak ditemukan." << endl;
}

// fungsi untuk menampilkan semua data mahasiswa yang tersedia

void displayData()
{
    for (int i = 0; i < totalData; i++)
    {
        cout << "\nNama: " << data[i].nama << endl;
        cout << "NIM: " << data[i].nim << endl;
        cout << "Prodi: " << data[i].prodi << endl;
        cout << "Jenis Kelamin: " << data[i].jenisKelamin << endl;
        cout << "Umur: " << data[i].umur << endl;
        cout << "IPK: " << data[i].ipk << endl;
        cout << "Departemen: " << data[i].departemen << endl;
        cout << "=========================" << endl;
    }
}

// fungsi untuk mencari mahasiswa berdasarkan nim
void cariMahasiswa()
{
    string nimCari;
    cout << "masukkan nim mahasiswa yang ingin di cari: ";
    cin >> nimCari;

    for (int i = 0; i < totalData; i++)
    {
        if (data[i].nim == nimCari)
        {
            cout << "\nNim : " << data[i].nim << endl;
            cout << "Nama : " << data[i].nama << endl;
            cout << "Prodi : " << data[i].prodi << endl;
            cout << "ipk : " << data[i].ipk << endl;
            break;
        }
        else
        {
            cout << "NIM Tidak Ditemukan" << endl;
        }
    }
}

//  Fungsi untuk menghapus data mahasiswa berdasarkan nim
void hapusMahasiswa()
{
    string nimHapus;
    cout << "Masukkan nim mahasiswa yang ingin dihapus: ";
    cin >> nimHapus;

    for (int i = 0; i < totalData; i++)
    {
        if (data[i].nim == nimHapus)
        {
            // Geser data ke posisi sebelumnya untuk menutup celah data yang dihapus
            for (int j = i; j < totalData - 1; j++)
            {
                data[j] = data[j + 1];
            }

            // Kurangi totalData untuk menandakan satu data telah dihapus
            totalData--;

            cout << "Data mahasiswa dengan nim " << nimHapus << " berhasil dihapus." << endl;
            return;
        }
    }

    cout << "NIM tidak ditemukan. Tidak ada data yang dihapus." << endl;
}

int main()
{
    int pil;
    do
    {
        cout << "\n===== MENU PROGRAM =====" << endl;
        cout << "1. Tambahkan data mahasiswa" << endl;
        cout << "2. update ipk mahasiswa" << endl;
        cout << "3. Tampilkan semua data mahasiswa yang tersedia" << endl;
        cout << "4. cari mahasiswa" << endl;
        cout << "5. hapus data mahasiswa" << endl;
        cout << "6. keluar dari program" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            tambahMahasiswa();
            break;
        case 2:
            updateIPK();
            break;
        case 3:
            displayData();
            break;
        case 4:
            cariMahasiswa();
            break;
        case 5:
            hapusMahasiswa();
            break;
        case 6:
            cout << "\nterimakasih telah menggunakan program ini, program berhenti\n";
            break;
        default:
            cout << "Pilihan Anda tidak valid. Silakan coba lagi." << endl;
        }
    } while (pil != 6);

    return 0;
}
