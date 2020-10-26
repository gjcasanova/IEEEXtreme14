#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, k, n, m, aux, result;

    vector<ll> hotel;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        result = 0;
        hotel.clear();
        cin >> m >> n >> k;

        for (int j = 0; j < m; j++)
        {
            cin >> aux;
            hotel.push_back(aux);
        }
        sort(hotel.begin(), hotel.end());

        int j;

        for (j = 0; j < k; j++)
        {
            result += n - hotel[j];
        }

        for (int h = j; h < m; h++)
        {
            result += hotel[h];
        }

        cout << result << endl;
    }

    return 0;
}
