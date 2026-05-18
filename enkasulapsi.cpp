#include <iostream>
using namespace std;

class remotelampu
{
private:
    string saklarno[5];

public:
    void setsaklarno(int i, string value)
    {
        saklarno[i] = value;
    }
    string getsaklarno(int i)
    {
        return saklarno[i];
    }
};

int main()
{
    remotelampu lampurumah;

    lampurumah.setsaklarno(0, "Lampu Teras Rumah");
    lampurumah.setsaklarno(1, "Lampu Ruang Tamu");
    lampurumah.setsaklarno(2, "Lampu kamar Tidur");
    lampurumah.setsaklarno(3, "Lampu Dapur");

    

    return 0;
}