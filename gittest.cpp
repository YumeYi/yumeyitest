#include <iostream>
using namespace std;

class Arr1D
{
private:
    int length;
    int *ar;

public:
    Arr1D() //defalt constructor
    {
        length = 2;
        ar = new int[length];
        for (int i = 0; i < length; i++)
        {
            ar[i] = 0;
        }
    }

    Arr1D(int len) //constructor
    {
        length = len;
        ar = new int[length];
        for (int i = 0; i < length; i++)
        {
            ar[i] = 0;
        }
    }

    Arr1D(Arr1D &copy) //deep copy
    {
        length = copy.length;
        ar = new int[copy.length];
        for (int i = 0; i < length; i++)
        {
            ar[i] = 0;
        }
    }

    void SetLength(int len) //setter for length
    {
        length = len;
        delete[] ar;
        ar = new int[length];
        for (int i = 0; i < length; i++)
        {
            ar[i] = 0;
        }
    }

    void SetVal() //setter for every element
    {
        for (int i = 0; i < length; i++)
        {
            cin >> *(ar + i);
        }
    }

    void SetAnyEle(int ele, int val) //setter for chosen element
    {
        ar[ele] = val;
    }

    void ReviArr(int len) //setter for revise array and set every value
    {
        length = len;
        delete[] ar;
        ar = new int[length];
        for (int i = 0; i < length; i++)
        {
            cin >> *(ar + i);
        }
    }

    int GetEleVal(int ele) //get a element's value
    {
        return ar[ele];
    }

    void DisplayArr1D() //get a array's value
    {
        for (int i = 0; i < length; i++)
        {
            cout << *(ar + i) << " "; //*(ar++)?
        }
    }

    Arr1D operator+(Arr1D &that)
    {
        Arr1D temp(this->length);

        for (int i = 0; i < this->length; i++)
        {
            temp.SetAnyEle(i, (this->GetEleVal(i) + that.GetEleVal(i)));
        }

        return temp;
    }

    void operator=(const Arr1D &that)
    {
        this->ar = that.ar;
    }
};

int main()
{

    int length = 0;
    cout << "How long would you like your array to be? ";
    cin >> length;
    Arr1D array_a(length);
    Arr1D array_b(length);
    Arr1D array_c(length);

    cout << "Initialize array_a :" << endl;
    array_a.SetVal();

    cout << "Initialize array_b :" << endl;
    array_b.SetVal();

    cout << "Do you want to revise the array?(y/n) ";
    char reviLen = '\0';
    cin >> reviLen;
    if (reviLen == 'y')
    {
        cout << "How long would you like your array to be? ";
        cin >> length;
        cout << "Initialize array_a: ";
        array_a.ReviArr(length);
        cout << "Initialize array_b: ";
        array_b.ReviArr(length);
        array_c.SetLength(length);
    }

    cout << "Would you like to change any element in any array?(y/n) ";
    char chaEle = '\0';
    cin >> chaEle;
    if (chaEle == 'y')
    {
        enum selec
        {
            a = 'a',
            b = 'b',
            both = 't',
        };
        char choose = '\0';
        cout << "Select array by pressing 'a' for array_a, 'b' for array_b, 't' for both: ";
        cin >> choose;
        int ele = 0, val = 0;
        switch (choose)
        {
        case a:
            cout << "Which element would you like to change? (0-" << length - 1 << ") ";
            cin >> ele;
            cout << "Value is: ";
            cin >> val;
            array_a.SetAnyEle(ele, val);
            break;
        case b:
            cout << "Which element would you like to change? (0-" << length - 1 << ") ";
            cin >> ele;
            cout << "Value is: ";
            cin >> val;
            array_b.SetAnyEle(ele, val);
            break;
        case both:
            cout << "Which element in array_a would you like to change? (0-" << length - 1 << ") ";
            cin >> ele;
            cout << "Value is: ";
            cin >> val;
            array_a.SetAnyEle(ele, val);
            cout << "Which element in array_b would you like to change? (0-" << length - 1 << ") ";
            cin >> ele;
            cout << "Value is: ";
            cin >> val;
            array_b.SetAnyEle(ele, val);
            break;
        }
    }

    array_c = array_a + array_b;

    cout << "Display array_a: ";
    array_a.DisplayArr1D();
    cout << endl;
    cout << "Display array_b: ";
    array_b.DisplayArr1D();
    cout << endl;
    cout << "Display array_c: ";
    array_c.DisplayArr1D();
    cout << endl;

    cout << "Would you like to display any element in any array?(y/n) ";
    char disEle = '\0';
    cin >> disEle;
    if (disEle == 'y')
    {
        cout << "How many element do you want to display? ";
        int num = 0;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            char selecArr = '\0';
            int selecEle = 0;
            cout << "The element you want to display is in: ";
            cin >> selecArr;
            cout << "Which element?(0-" << length - 1 << ") ";
            cin >> selecEle;
            if (selecArr == 'a')
                cout << array_a.GetEleVal(selecEle) << endl;
            else if (selecArr == 'b')
                cout << array_b.GetEleVal(selecEle) << endl;
            else if (selecArr == 'c')
                cout << array_c.GetEleVal(selecEle) << endl;
        }
    }

    cout<<"test";

    system("pause");
    return 0;
}