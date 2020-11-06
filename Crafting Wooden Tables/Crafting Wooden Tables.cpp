#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c, n, p, w;
    cin >> c >> n >> p >> w;
    int vector[n];
    int res = 0;
    if (c < w)
    {
        for (int i = 0; i < n; i++)
        {
            if (w > p)
            {
                vector[i] = p;
                w -= p;
            }
            else
            {
                vector[i] = w;
                w = 0;
            }
        }

        int temp = 0;
        int disp = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            disp++;
            if (vector[i] < c)
            {
                if (i != 0)
                {
                    temp += vector[i];
                    if (temp + vector[i - 1] >= c)
                    {
                        do
                        {
                            vector[i - 1] = temp + vector[i - 1] - c;
                            temp = 0;
                            res++;
                            disp--;
                            vector[i] = 0;
                        } while (disp != 0 && vector[i - 1] >= c);
                    }
                }
            }
            else if (vector[i] == c)
            {
                res++;
                disp--;
                temp = 0;
            }
            else
            {
                break;
            }
        }
    }
    cout << res << endl;

    return 0;
}