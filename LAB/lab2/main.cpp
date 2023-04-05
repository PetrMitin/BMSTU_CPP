#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter n " << endl;
    cin >> n;
    float arr[50][50];
    float curr_max;
    int ans_i;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (i == j && i > 0)
                if (arr[i][i] * arr[i-1][i-1] > curr_max)
                {
                    curr_max =  arr[i][i] * arr[i-1][i-1];
                    ans_i = i;
                }
        }
        cout << '\n';
    }
    cout << '\n' << "Initial matrix: " << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout << arr[i][j] << ' ';
        cout << '\n';
    }

    cout << '\n' << "Zigzag" << '\n';
    for (int i = -(n-1); i < 2 * n - 1; i++)
    {
       for (int j = 0; j < n; j++)
       {
            int curr_i, curr_j;
            curr_i = (i + n + 1) % 2 == 0 ? n - j - 1 : j;
            curr_j = (i + n + 1) % 2 == 0 ? i + j : i + (n - 1) - j;
            if (curr_i < n && curr_j < n && curr_i >= 0 && curr_j >= 0) cout << arr[curr_i][curr_j] << endl;
       }
    }

    cout << '\n' << "Answer: " << arr[ans_i][ans_i] << ". Row and col of answer: " << ans_i + 1 << ". \n";

    return 0;
}
