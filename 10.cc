#include <iostream>
using namespace std;

bool rotation(string s1, string s2)
{
    int n = s1.length();
    if (n != s2.length())
        return false;

    string clockwise = s1.substr(n - 2) + s1.substr(0, n - 2);

    string anticlockwise = s1.substr(2) + s1.substr(0, 2);

    return (s2 == clockwise || s2 == anticlockwise);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << (rotation(s1, s2) ? "true" : "false") << endl;

    return 0;
}
