#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int array[n];
    int cantSoldaditos = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        cantSoldaditos += array[i];
    }
    int d;
    cin >> d;
    int days[d][3];
    int res = 0;
    for (int i = 0; i < d; i++)
    {
        cin >> days[i][0] >> days[i][1] >> days[i][2];
        res += days[i][2];
    }

    if (cantSoldaditos < res)
    {
        cout << cantSoldaditos << endl;
    }
    else
        cout << res << endl;
}