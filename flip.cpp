#include <bits/stdc++.h>
using namespace std;

array <string, 5> bank = {"BRI", "Mandiri", "BCA", "BNI", "Jago"}; // STL
int kodeAntrianBaru = 1000;

void pilihanBank();

class User
{
public:
    int kodeAntrian;
    string namaUser;
    int bankUser;
    int bankTujuan;
    string noRekTujuan;
    long long jumlahTransfer;
};

class Antrian
{
public:
    User data[10];
    int panjangAntrian = -1;

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
        for(int i = 0; i <= panjangAntrian; i++)
        {
            writeFile << data[i].kodeAntrian << '\n';
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

            pilihanBank();
            
            data[panjangAntrian].kodeAntrian = kodeAntrianBaru;
            kodeAntrianBaru++;

            cout << "Nama: ";
            cin.ignore(1, '\n');
            getline(cin, data[panjangAntrian].namaUser);

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

            cout << "Jumlah Transfer: ";
            cin >> data[panjangAntrian].jumlahTransfer;

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
            cout << "Antrian dengan kode antrian " << data[0].kodeAntrian << " sedang diproses\n";
            cout << "Tersisa " << panjangAntrian  << " orang dalam antrian\n";

            for(int i = 0; i < panjangAntrian; i++)
            {
                data[i] = data[i + 1];
            }
            
            panjangAntrian--;

            masukkanFile();
        }
    }

    void kodeAntrianSekarang()
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
                readFile.seekg(0, ios::beg); //File Pointer
                readFile.getline(_getKode, 10);
                cout << "Kode antrian terdepan : " << _getKode << '\n';
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
            ofstream writeFile("DataAntrian");
            writeFile << "";
            writeFile.close();

            panjangAntrian = -1;
        }
    }

    void tampilkanAntrian()
    {
        char tampung[100];
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
                for(int i = 0; i <= panjangAntrian; i++)
                {
                    cout << "Antrian ke-" << i + 1 << '\n';
                    readFile.getline(tampung, 100);
                    cout << "Kode Antrian: " << tampung << '\n';
                    readFile.getline(tampung, 100);
                    cout << "Nama: " << tampung << '\n';
                    readFile.getline(tampung, 100);
                    cout << "Bank Asal: " << tampung << '\n';
                    readFile.getline(tampung, 100);
                    cout << "Bank Tujuan: " << tampung << '\n';
                    readFile.getline(tampung, 100);
                    cout << "No. Rek Tujuan: " << tampung << '\n';
                    readFile.getline(tampung, 100);
                    cout << "Jumlah Transfer: " << tampung << '\n';
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
    Antrian hariIni;
    int pilihan;

    do
    {
        system("cls");
        cout << "Pilihan Layanan: \n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Proses Antrian\n";
        cout << "3. Kode Antrian Sekarang\n";
        cout << "4. Hapus Antrian\n";
        cout << "5. Tampilkan Antrian\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            hariIni.tambahAntrian();
            break;
        
        case 2:
            hariIni.prosesAntrian();
            break;
        
        case 3:
            hariIni.kodeAntrianSekarang();
            break;
        
        case 4:
            hariIni.hapusAntrian();
            break;

        case 5:
            hariIni.tampilkanAntrian();
            break;
        
        case 6:
            exit(1);
        }

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
}