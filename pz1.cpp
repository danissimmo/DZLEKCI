#include <iostream>
using namespace std;


class MasClass
{

  int l;
  int* arr;
  int* newarr;
   
  public:
    MasClass(int len)
    {
        l = len;
        arr = new int[len];
        newarr = new int[len + 1];
    }
    MasClass(const MasClass& obj)
    {
        l = obj.l;
        arr = new int[l];

        for (int i = 0; i < l; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
    ~MasClass() 
    {
        cout << endl << "Array deleted" << endl;
        delete[] arr;
    }
    void set(int num, int value)
    {
        if ((num >= 0) && (num < l))
        {
            if ((value > -100) && (value < 100))
            {
                arr[num] = value;
            }
            else
            {
                cout << "Error value" << endl;
            }
        }
        else
        {
            cout << "Error index" << endl;
        }

    }
    int get (int num)
    {
        if ((num >= 0) && (num < l))
        {
            return arr[num];
        }
        else
        {
            cout << "Error index" << endl;
        }
    }
    void dobav(int value)
    {
        if (value >= -100 && value <= 100)
        {
            for (int i = 0; i < l; i++)
            {
                newarr[i] = arr[i];
            }
            newarr[l] = value;
            l++;
            delete[] arr;
            arr = newarr;
        }
        else cout << "Error" << endl;
    }
    void summ(const MasClass& obj)
    {
        cout << endl;
        for (int i = 0; i < l; i++)
        {
            arr[i] += obj.arr[i];
        }
    }
    void pazn(const MasClass& obj)
    {
        for (int i = 0; i < l; i++)
        {
            arr[i] -= obj.arr[i];
        }
    }
     void out() 
    {
        for (int i = 0; i < l; i++)
        {
            cout << arr[i] << "\tabulacia";
        }
        cout << endl;
    }
};
int main()
{
    return 0;
}
