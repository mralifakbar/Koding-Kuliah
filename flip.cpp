#include <bits/stdc++.h>
using namespace std;

array <string, 5> bank = {"BRI", "Mandiri", "BCA", "BNI", "Jago"}; // STL
int panjangAntrian;

void pilihanBank();
void awal()
{
    char tmp[100];
    ifstream readFile("DataAntrian");
    readFile.getline(tmp, 100);
    if(sizeof(tmp) == 0)
    {
        panjangAntrian = -1;
    }
    else
    {

        stringstream length(tmp);
        length >> panjangAntrian;
        if(panjangAntrian != -1)
        {
            panjangAntrian--;
        }
    }
    readFile.close();
}

class User
{
public:
    string namaUser;
    int bankUser;
    int bankTujuan;
    string noRekTujuan;
    long long jumlahTransfer;
};

class Antrian
{
public:
    array <User, 10> data;
    // User data[10];

    bool antrianKosong()
    {
        return panjangAntrian == -1;
    }

    bool antrianPenuh()
    {
        return panjangAntrian == 9;
    }

    void masukkanFile()
    {
        ofstream writeFile("DataAntrian");
        writeFile << panjangAntrian + 1 << "\n\n"; // Karena antrian dimulai dari 1
        for(int i = 0; i <= panjangAntrian; i++)
        {
            writeFile << data[i].namaUser << '\n';
            writeFile << data[i].bankUser << '\n';
            writeFile << data[i].bankTujuan << '\n';
            writeFile << data[i].noRekTujuan << '\n';
            writeFile << data[i].jumlahTransfer << "\n\n";
        }
        writeFile.close();
    }

    void tambahAntrian()
    {
        if(antrianPenuh())
        {
            cout << "Antrian sedang penuh!\n";
        }
        else
        {
            system("cls");
            panjangAntrian++;
            
            cout << "Nama: ";
            cin.ignore(1, '\n');
            getline(cin, data[panjangAntrian].namaUser);
            
            cout << '\n';
            pilihanBank();

            do
            {
                cout << "Bank Asal: ";
                cin >> data[panjangAntrian].bankUser;
            } while(data[panjangAntrian].bankUser < 1 || data[panjangAntrian].bankUser  > 5);

            do
            {
                cout << "Bank Tujuan: ";
                cin >> data[panjangAntrian].bankTujuan;
            } while(data[panjangAntrian].bankTujuan < 1 || data[panjangAntrian].bankTujuan  > 5);
            
            cout << "No. Rek Tujuan: ";
            cin.ignore(1, '\n');
            getline(cin, data[panjangAntrian].noRekTujuan);

            do
            {
                cout << "Jumlah Transfer: ";
                cin >> data[panjangAntrian].jumlahTransfer;
            } while (data[panjangAntrian].jumlahTransfer < 1000 || data[panjangAntrian].jumlahTransfer > 2000000000);
            
            masukkanFile();

            cout << "Data berhasil ditambahkan!\n";
        }
    }

    void prosesAntrian()
    {
        if(antrianKosong())
        {
            cout << "Antrian sedang kosong\n";
        }
        else
        {
            cout << "Antrian terdepan atas nama " << data[0].namaUser << " sedang diproses\n";
            cout << "Tersisa " << panjangAntrian  << " orang dalam antrian\n";

            for(int i = 0; i < panjangAntrian; i++)
            {
                data[i] = data[i + 1];
            }
            
            panjangAntrian--;

            masukkanFile();
        }
    }

    void panjangAntrianSekarang()
    {
        if(antrianKosong())
        {
            cout << "Antrian sedang kosong\n";
        }
        else
        {
            char _getKode[10];
            ifstream readFile("DataAntrian");
            if(!readFile)
            {
                cout << "File tidak ada\n";
            }
            else
            {
                readFile.seekg(0, ios::cur); //File Pointer
                readFile.getline(_getKode, 10);
                cout << "Panjang antrian saat ini: " << _getKode << '\n';
            }
            readFile.close();
        }
    }

    void hapusAntrian()
    {
        if(antrianKosong())
        {
            cout << "Antrian sudah kosong\n";
        }
        else
        {
            data.empty();
            panjangAntrian = -1;
            masukkanFile();
            cout << "Antrian berhasil dihapus\n";
        }
    }

    void tampilkanAntrian()
    {
        char tampung[100];
        char *_kode= new char;
        int _kodeBank;
        if(antrianKosong())
        {
            cout << "Antrian masih kosong\n";
        }
        else
        {
            ifstream readFile("DataAntrian");
            if(!readFile)
            {
                cout << "File tidak ada\n";
            }
            else
            {
                cout << '\n';
                readFile.getline(tampung, 2);
                readFile.getline(tampung, 2);
                for(int i = 0; i <= panjangAntrian; i++)
                {
                    cout << "Antrian ke-" << i + 1 << '\n';
                    readFile.getline(tampung, 100);
                    cout << "Nama\t\t: " << tampung << '\n';
                    readFile.getline(tampung, 100);
                    stringstream userBank(tampung);
                    userBank >> _kodeBank;
                    // _kode[0] = tampung[i];
                    // _kodeBank = atoi(_kode);
                    cout << "Bank Asal\t: " << bank[_kodeBank - 1] << '\n';
                    readFile.getline(tampung, 100);
                    stringstream receiveBank(tampung);
                    receiveBank >> _kodeBank;
                    // _kode[0] = tampung[i];
                    // _kodeBank = atoi(_kode);
                    cout << "Bank Tujuan\t: " << bank[_kodeBank - 1] << '\n';
                    readFile.getline(tampung, 100);
                    cout << "No. Rek Tujuan\t: " << tampung << '\n';
                    readFile.getline(tampung, 100);
                    cout << "Jumlah Transfer\t: " << tampung << '\n';
                    readFile.getline(tampung, 2);
                    cout << '\n';
                }
            }
            readFile.close();
        }
    }
};

int main()
{
    awal();
    Antrian hariIni;
    int pilihan;

    do
    {
        system("cls");
        cout << "Pilihan Layanan: \n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Proses Antrian\n";
        cout << "3. Panjang Antrian Sekarang\n";
        cout << "4. Hapus Antrian\n";
        cout << "5. Tampilkan Antrian\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << '\n';

        switch (pilihan)
        {
        case 1:
            hariIni.tambahAntrian();
            break;
        
        case 2:
            hariIni.prosesAntrian();
            break;
        
        case 3:
            hariIni.panjangAntrianSekarang();
            break;
        
        case 4:
            hariIni.hapusAntrian();
            break;

        case 5:
            hariIni.tampilkanAntrian();
            break;
        
        case 6:
            hariIni.hapusAntrian();
            exit(1);
        }

        cout << '\n';
        system("pause");
    } while(pilihan != 6);
}

void pilihanBank()
{   
    cout << "Pilihan Bank: \n";
    for(int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << bank[i] << '\n';
    }
    cout << '\n';
}