//VARIANT 1
#include <iostream>
#include <Windows.h> 
#include <string.h>
#include <stdlib.h>
using namespace std;

int const MaxSize = 10;
class FooString
{
private:
    char* buf;
public:
    FooString();
    ~FooString();
    void show();
    int length();
    int testInput();
    void testData();
};
 
FooString::FooString()
{
    buf = new char[MaxSize];
    testData();
}

FooString::~FooString()
{
    delete[]buf;
}

void FooString::testData()
{
    cout << "VVEDITE STROKU: ";
    cin.getline(buf, MaxSize);
}

int FooString::length()
{
    int i=0;
    while (true)
    {
        if (buf[i] == '\0')
            break;
        else
            i++;
    }
    i++;
    return i;
}

void FooString::show()
{
    int l = length();
    cout << "PAZMER MAS: " << l << endl;
    for (int i = 0; i < l; i++)
        cout << buf[i];
}



int FooString::testInput() 
{
    if (cin.fail()) 
    {
        cin.clear(); 
        cin.ignore(32767, '\n'); 
        cout << "OSHIBKA." << endl;
        return -1;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FooString mas;
    if (mas.testInput() == -1)
            return -1;
    mas.show();
}
