#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = n;

    for (int i = 1; i < n; i++)
    {
        int there;
        cin >> there;
        sum -= there;
        sum += i;
    }

    cout << sum;

    return 0;
}