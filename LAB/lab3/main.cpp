#include <iostream>
#include <string>

using namespace std;

bool isPalyndrom(int num)
{
    string st = to_string(num);
    int lb = (st.length() - 1) / 2;
    int rb = st.length() / 2;
    string str1, str2;
    str1 = st.substr(0, lb + 1);
    str2 = st.substr(rb, (st.length() + 1) / 2);
    reverse(str2.begin(), str2.end());
    return str1 == str2;
}

int main()
{
    int n, counter;
    cout << "Enter n: " << endl;
    cin >> n;
    counter = 0;
    cout << '\n' << "Answer" << '\n';
    for (int i = 0; i <= n; i++)
    {
        if (isPalyndrom(i) && isPalyndrom(i*i)) (++counter, cout << i << ' ' << i*i << '\n');
    }
    cout << '\n' << "Number of such integers: " << counter << endl;
    return 0;
}
