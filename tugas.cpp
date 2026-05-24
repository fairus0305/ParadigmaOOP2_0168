#include <iostream>
#include <iomanip>

using namespace std;

class RekeningBank
{
protected:
    string namaPemilik;
    double saldo;

public:
    RekeningBank(string nama, double saldoAwal)
    {
        namaPemilik = nama;
        saldo = saldoAwal;
    }

    virtual void potongAdmin() = 0;

    void tampilkanData()
    {
        cout << "Nama Pemilik : " << namaPemilik << endl;
        cout << "Saldo Akhir  : Rp "
             << fixed << setprecision(0)
             << saldo << endl;
    }
};

class RekeningSyariah : public RekeningBank
{
public:
    RekeningSyariah(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override
    {
        cout << "[Rekening Syariah]" << endl;
        cout << "Tidak ada potongan biaya admin." << endl;
    }
};

class RekeningKonvensional : public RekeningBank
{
public:
    RekeningKonvensional(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override
    {
        saldo -= 15000;

        cout << "[Rekening Konvensional]" << endl;
        cout << "Biaya admin Rp 15.000 berhasil dipotong." << endl;
    }
};

class RekeningPremium : public RekeningBank
{
public:
    RekeningPremium(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override
    {
        cout << "[Rekening Premium]" << endl;

        if (saldo > 10000000)
        {
            cout << "Nasabah bebas biaya admin karena saldo di atas Rp 10.000.000." << endl;
        }
        else
        {
            saldo -= 50000;

            cout << "Biaya admin Rp 50.000 berhasil dipotong." << endl;
        }
    }
};

int main()
{
    RekeningSyariah a("Iqbal", 5000000);
    RekeningKonvensional b("Fairus", 2000000);
    RekeningPremium c("Zidan", 15000000);
    RekeningPremium d("Lalaa", 8000000);

    RekeningBank *daftarRekening[4] =
        {
            &a,
            &b,
            &c,
            &d
        };

    cout << "===== PROSES OTOMATISASI AKHIR BULAN ====="
         << endl
         << endl;

    for (int i = 0; i < 4; i++)
    {
        daftarRekening[i]->potongAdmin();
        daftarRekening[i]->tampilkanData();

        cout << "===================================="
             << endl
             << endl;
    }

    return 0;
}