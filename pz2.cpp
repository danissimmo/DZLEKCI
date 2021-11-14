#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Mas
{

  int l;
  T* arr;
  T* newarr;
   
  public:
    Mas(int len)
    {
        this->l = l;
        arr = new T[len];
        newarr = new T[len + 1];
    }
    Mas(const Mas& obj)
    {
        l = obj.l;
        arr = new T[l];

        for (int i = 0; i < l; i++)
        {
            arr[i] = obj.arr[i];
        }
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

	friend ostream& operator << (ostream& os, const Mas &ar)
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
  int* newarr;
   
  public:
    MasClass(int len)
    {
        this->l = l;
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
        if ((num >= 0) && (num < l)) throw out_of_range("Array out of bounds");
        if ((value > -100) && (value < 100)) throw invalid_argument("Element out of range");
                arr[num] = value;
    }
    int get (int num)
    {
        if ((num >= 0) && (num < l)) throw out_of_range("Array out of bounds");
        return arr[num];
       
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

MasClass operator + (MasClass obj1, MasClass obj2)
{
	int min_l = ((obj1.l < obj2.l) ? obj1.l : obj2.l);
	MasClass out(min_l);
	for (int i = 0; i < min_l; i++) out.set(i, obj1.get(i) + obj2.get(i));

	return out;
}

MasClass operator - (MasClass obj1, MasClass obj2)
{
	int min_l = ((obj1.l < obj2.l) ? obj1.l : obj2.l);
	MasClass out(min_l);
	for (int i = 0; i < min_l; i++) out.set(i, obj1.get(i) - obj2.get(i));

	return out;
}
int main()
{
	try
	{
		MasClass obj1(3);
		for (int i = 0; i < 3; i++) obj1.set(i, i + 1);

		MasClass obj2(obj1);
		obj1.dobav(4);
		obj1.out();
		obj2.out();
		cout << "Push back works\n" << endl;
		obj1.set(1, 101); //Setter error
		obj1.set(101, 1); //Setter error
		obj1.get(101); //Getter error
		cout << "Get 3rd element: " << obj1.get(2) << "\n" << endl;
		MasClass obj3 = obj1 - obj2;
		obj3.out();
		MasClass obj4 = obj1 + obj2;
		obj4.out();	
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
