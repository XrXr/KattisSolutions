#include <iostream>
#include <string>

using namespace std;

int main()
{
    string l;
    getline(cin, l);
    
    bool one = true;
    bool two = false;
    bool three = false;

    for (char c : l)
    {
        if (c == 'A')
            swap(one, two);
        else if (c == 'B')
            swap(two, three);
        else swap (one, three);
    }

    if (one)
        cout << 1;
    else if (two)
        cout << 2;
    else
        cout << 3;

    cout << endl;
}
