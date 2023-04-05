#include <iostream>
#include <math.h>

using namespace std;

float detX(float arr1[3], float arr2[3]) {
    return arr1[0] * arr2[1] - arr1[1] * arr2[0];
}

void intersection(float arr1[3], float arr2[3], float& x, float& y) {
    float det = detX(arr1, arr2);
    if (det) {
        x = -1 * (arr1[2] * arr2[1] - arr1[1] * arr2[2]) / det;
        y = -1 * (arr1[0] * arr2[2] - arr1[2] * arr2[0]) / det;
    }
}

float square(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float s1, s2, s3, p;
    s1 = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    s2 = sqrt(pow(x1-x3, 2) + pow(y1-y3, 2));
    s3 = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
    p = (s1 + s2 + s3) / 2;
    return sqrt(p*(p-s1)*(p-s2)*(p-s3));
}

int main()
{
    float arr[3][3];
    cout << "Enter 3 sets of coefficients!" << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        cout << endl;
    }
    bool apb = !detX(arr[0], arr[1]);
    bool apc = !detX(arr[0], arr[2]);
    bool bpc =!detX(arr[1], arr[2]);
    if (apb || apc || bpc)
    {
        cout << "No triangle!" << endl;
    } else
    {
        float x1, y1, x2, y2, x3, y3;
        intersection(arr[0], arr[1], x1, y1);
        intersection(arr[0], arr[2], x2, y2);
        intersection(arr[1], arr[2], x3, y3);
        cout << "Square of the triangle = " << square(x1, y1, x2, y2, x3, y3) << endl;
    }
    return 0;
}
