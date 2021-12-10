#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Mas
{
    int l;
    T* arr;

public:
    Mas(int len)
    {
        this->l = l;
        arr = new T[len];
    }
    Mas(const Mas &obj)
    {
        l = obj.l;
        arr = new T[l];

        for (int i = 0; i < l; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
        void print()
	{
		for (int i = 0; i < l; i++) cout << arr[i] << " ";
		cout << endl;
	}
    ~Mas()
    {
        cout << endl << "Array deleted" << endl;
        delete[] arr;
    }
    void set(int num, T value)
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
    int get(int num)
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
    void dobav(T value)
    {
        T* new_mas = new T[l + 1];
        memcpy(new_mas, arr, l * sizeof(T));
        new_mas[l] = value;

        l++;
        arr = new_mas;
    }

    void out()
    {
        for (int i = 0; i < l; i++)
        {
            cout << arr[i] << "\tabulacia";
        }
        cout << endl;
    }
    double dist(Mas& ar)
    {
        int sq = 0.0;
        for (int i = 0; i < l; i++) sq += (arr[i] - ar.arr[i]) * (arr[i] - ar.arr[i]);

        return sqrt(sq);
    }

    friend ostream& operator << (ostream& os, const Mas& ar)
    {
        for (int i = 0; i < ar.l; i++) os << ar.arr[i] << ' ';
        os << endl;

        return os;
    }
    Mas& operator=(const Mas& ar)
    {
        if (this == &ar) return *this;

        l = ar.l;
        arr = new T[l];
        for (int i = 0; i < l; i++) arr[i] = ar.arr[i];

        return *this;
    }
};
class MasClass
{

    int l;
    int* arr;

public:
    MasClass(int l)
    {
        this->l = l;
        arr = new int[l];
    }
    MasClass(const MasClass& ob)
    {
        l = ob.l;
        arr = new int[l];

        for (int i = 0; i < l; i++)
        {
            arr[i] = ob.arr[i];
        }
    }
    ~MasClass()
    {
        cout << endl << "Array deleted" << endl;
        delete[] arr;
    }
    void set(int num, int value)
    {
        if ((num >= 0) && (num < l)) throw out_of_range("Array out of bounds");
        if ((value > -100) && (value < 100)) throw invalid_argument("Element out of range");
        arr[num] = value;
    }
    int get(int num)
    {
        if ((num >= 0) && (num < l)) throw out_of_range("Array out of bounds");
        return arr[num];

    }
    void dobav(int value)
    {
		int* new_mas = new int[l + 1];
		memcpy(new_mas, arr, l * sizeof(int));
		new_mas[l] = value;

		l++;
		arr = new_mas;
	}

    void out()
    {
        for (int i = 0; i < l; i++)
        {
            cout << arr[i] << "\tabulacia";
        }
        cout << endl;
    }

    friend MasClass operator + (MasClass, MasClass);
    friend MasClass operator - (MasClass, MasClass);
};

MasClass operator + (MasClass ob1, MasClass ob2)
{
    int min_l = ((ob1.l < ob2.l) ? ob1.l : ob2.l);
    MasClass out(min_l);
    for (int i = 0; i < min_l; i++) out.set(i, ob1.get(i) + ob2.get(i));

    return out;
}

MasClass operator - (MasClass ob1, MasClass ob2)
{
    int min_l = ((ob1.l < ob2.l) ? ob1.l : ob2.l);
    MasClass out(min_l);
    for (int i = 0; i < min_l; i++) out.set(i, ob1.get(i) - ob2.get(i));

    return out;
}
int main()
{
    try
    {
        MasClass ob1(3);
        for (int i = 0; i < 3; i++) ob1.set(i, i + 1);

        MasClass ob2(ob1);
        ob1.dobav(4);
        ob1.out();
        ob2.out();
        cout << "Push back works\n" << endl;
        ob1.set(1, 101); //Setter error
        ob1.set(101, 1); //Setter error
        ob1.get(101); //Getter error
        cout << "Get 3rd element: " << ob1.get(2) << "\n" << endl;
        MasClass ob3 = ob1 - ob2;
        ob3.out();
        MasClass ob4 = ob1 + ob2;
        ob4.out();
    }
    catch (bad_alloc e)
    {
        cout << "Error while initiating array" << endl << e.what() << endl;
    }
    catch (out_of_range e)
    {
        cout << "Error while accessing array element" << endl << e.what() << endl;
    }
    catch (invalid_argument e)
    {
        cout << "Error while setting arguments" << endl << e.what() << endl;
    }
}
