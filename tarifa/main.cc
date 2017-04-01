#include <iostream>
#include <utility>

using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    int r = x;
    while (n--)
    {
        int xx;
        cin >> xx;
        r += x - xx;
    }
    cout << r << endl;
}
