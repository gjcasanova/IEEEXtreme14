#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct palindrome
{
    int start, end;
};

void reverseStr(string &str)
{
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

bool comparePalindrome(palindrome a, palindrome b)
{
    return (a.end - a.start + 1) > (b.end - b.start + 1);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, result;
    string line, subline, subline_reversed;

    palindrome p;
    vector<palindrome> palindromes;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        palindromes.clear();
        result = 0;
        cin >> line;

        for (int j = 0; j < line.size(); j++)
        {
            for (int k = j; k < line.size(); k++)
            {
                if (line[j] == line[k])
                {
                    subline = line.substr(j, k - j + 1);
                    subline_reversed = subline;
                    reverseStr(subline_reversed);

                    if (subline == subline_reversed)
                    {
                        p.start = j;
                        p.end = k;
                        palindromes.push_back(p);
                    }
                }
            }
        }

        sort(palindromes.begin(), palindromes.end(), comparePalindrome);
        
        for (int j = 0; j < palindromes.size() - 1; j++)
        {
            palindrome a = palindromes[j];
            for (int k = j + 1; k < palindromes.size(); k++)
            {
                palindrome b = palindromes[k];
                if (a.end < b.start || b.end < a.start)
                {
                    result = max(result, (a.end - a.start + 1) + (b.end - b.start + 1));
                    break;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
