#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calcDistance(string a, string b)
{
    int distance = 0;

    for (int i = 0; i < 14; i++)
    {
        if (a[i] != b[i])
        {
            distance++;
        }
    }
    return distance;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, distance, result = 0;
    cin >> n;

    vector<string> coupons;
    string line;

    for (int i = 0; i < n; i++)
    {
        cin >> line;

        for (int j = 0; j < coupons.size(); j++)
        {
            distance = calcDistance(line, coupons[j]);
            if (distance == 1)
            {
                result++;
            }
        }

        coupons.push_back(line);
    }

    cout << result << endl;

    return 0;
}
