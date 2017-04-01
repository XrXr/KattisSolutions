#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string vowels = "aeiouy";
bool isvowel(char a)
{
    return find(vowels.begin(), vowels.end(), a) != vowels.end();
}

int main()
{
    string l;
    while (getline(cin, l))
    {
        bool first = true;
        stringstream ss(l);
        string word;
        while (ss >> word)
        {
            if (!first) cout << ' ';

            if (isvowel(word[0]))
            {
                cout << word + "yay";
            } else {
                int i = 0;
                while (i < word.size() && !isvowel(word[i]))
                {
                    i++;
                }
                cout << word.substr(i) + word.substr(0, i) + "ay";
            }
            first = false;
        }
        cout << endl;
    }
}
