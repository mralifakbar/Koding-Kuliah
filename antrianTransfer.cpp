#include <bits/stdc++.h>
using namespace std;

array <string, 5> namaBank = {"BRI", "BCA", "Mandiri", "BNI", "Jago"};
int kodeAntrianAwal = 1000;

class User
{
public:
    string nama;
    int kodeBankUser;
    long long jumlahTransfer;
    string noRekTujuan;
    int kodeBankTujuan;
    int kodeAntrian;
};

class Antrian
{
public:
    array <User, 10> data;
    int jumlahAntrian = -1;
    
    bool antrianKosong()
    {
        return jumlahAntrian == -1;
    }

    bool antrianPenuh()
    {
        return jumlahAntrian == 9;
    }

    void tambahAntrian()
    {
        if(antrianPenuh())
        {
            cout << "Antrian Sudah Penuh!\n";
        }
        else
        {
            system("cls");
            jumlahAntrian++;

            cout << "Nama\t: ";
            getline(cin, data[jumlahAntrian].nama);
            cout << "Kode Bank\t: ";
            cin >> data[jumlahAntrian].kodeBankUser;
            cout << "No. Rekening Tujuan: ";
            cin >> data[jumlahAntrian].noRekTujuan;
            cout << "Kode Bank Tujuan: ";
            cin >> data[jumlahAntrian].kodeBankTujuan;
            cout << "Jumlah Transfer: ";
            cin >> data[jumlahAntrian].jumlahTransfer;
            data[jumlahAntrian].kodeAntrian = kodeAntrianAwal;
            kodeAntrianAwal++;

            ofstream outfile;

            outfile.open("DataAntrian", ios::app);
            outfile << "#" << data[jumlahAntrian].kodeAntrian << '\n';
            outfile << "Nama\t: " << data[jumlahAntrian].nama << '\n';
            outfile << "Kode Bank\t: " << data[jumlahAntrian].kodeBankUser << '\n';
            outfile << "No. Rekening Tujuan\t: " << data[jumlahAntrian].noRekTujuan << '\n';
            outfile << "Kode Bank Tujuan\t: " << data[jumlahAntrian].kodeBankTujuan << '\n';
            outfile << "Jumlah Transfer\t: " << data[jumlahAntrian].jumlahTransfer << '\n';
            outfile.close();
        }
    }


    
};

void pushToTxt()
{

}

int main()
{

}