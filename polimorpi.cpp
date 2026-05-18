#include <iostream>
using namespace std;

class seseorang
{
public:
    virtual void pesan() = 0;
    // virtual void pesan(){
    //  cout<<"pesan dari seorang"<,endl;
    //}
};

class joko : public seseorang
{
public:
    void pesan()
    {
        cout << "pesan dari joko" << endl;
    }
};

class lia : public seseorang
{
public:
    void pesan()
    {
        cout << "pesan dari lia" << endl;
    }
};

int main()
{
    seseorang *obyek;
    joko a;
    lia b;

    obyek = &a;
    obyek->pesan();
    // a.seorang::pesan();
    // b.seorang::pesan();
    return 0;
}
