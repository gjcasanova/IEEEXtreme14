#include <iostream>
#include <math.h>

using namespace std;

void llenado(int **mat, int **matrix, int k, int l, int n, int m, int r, int c)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mat[i][j] = matrix[k][l];
            res += mat[i][j];
            //cout<<mat[i][j]<<" ";
            l++;
            if (l == c)
                l = 0;
        }
        k++;
        if (k == r)
            k = 0;
        //cout<<endl;
    }
    cout << res;
}

int main()
{
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    int **matrix = new int *[r];
    for (int j = 0; j < r; j++)
    {
        matrix[j] = new int[c];
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int **mat = new int *[n];
    for (int j = 0; j < n; j++)
    {
        mat[j] = new int[m];
    }

    llenado(mat, matrix, 0, 1, n, m, r, c);

    return 0;
}