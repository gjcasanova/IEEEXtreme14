#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cB, cP;

    cin >> n >> cB >> cP;

    int matrix[n][2];

    int sumB = 0, sumP = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> matrix[i][0] >> matrix[i][1];
        sumB += matrix[i][0];
        sumP += matrix[i][1];
    }

    int res = (ceil((float)sumB / 10) * cB) + (ceil((float)sumP / 10) * cP);
    cout << res << endl;

    return 0;
}
