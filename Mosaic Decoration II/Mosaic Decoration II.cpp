#include <iostream>
#include <math.h>

using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    lli w, h, a, b, m, c;

    cin >> w >> h >> a >> b >> m >> c;

    lli row = 0;
    for (lli i = 0; i < w; i += a)
        row++;

    lli col = 0;
    for (lli i = 0; i < h; i += b)
        col++;

    lli tamRow = row * a;
    lli tamCol = col * b;

    lli cropRow = tamRow - w;
    lli cropCol = tamCol - h;

    tamRow -= cropRow;
    tamCol -= cropCol;

    lli resRow = 0;
    if (row * a != tamRow)
        resRow = tamCol;
    lli resCol = 0;
    if (col * b != tamCol)
        resCol = tamRow;

    lli crop = c * (resRow + resCol);
    lli numVal = row * col;
    lli res = 0;
    if ((numVal * m) / 10 < m)
    {
        res = m + crop;
    }
    else
    {
        res = ((numVal * m) / 10) + crop;
    }
    cout << res;

    return 0;
}
