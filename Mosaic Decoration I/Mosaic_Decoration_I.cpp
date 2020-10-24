#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <limits>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef long double ld;

const int INF = numeric_limits<int>::max();

void printVector2D(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printVector1D(vector<int> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << matrix[i] << " ";
    }
    cout << endl;
}

void printArray2D(int matrix[][2], int size_x, int size_y)
{
    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printArray1D(int *matrix, int size_x)
{
    for (int i = 0; i < size_x; i++)
    {
        cout << matrix[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cB, cP;    

    cin>>n>>cB>>cP;

    int matrix[n][2];

    int sumB=0, sumP=0;
    for(int i=0;i<n;i++){
        cin>>matrix[i][0]>>matrix[i][1];
        sumB+=matrix[i][0];
        sumP+=matrix[i][1];
    }

    int res= (ceil((float)sumB/10)*cB)+(ceil((float)sumP/10)*cP);
    cout<<res<<endl;

    //printArray2D(matrix,2,n);

    // For read numbers
    // int number;
    // while (iss >> number)
    // {
    //     values[i][number] = 0;
    // }

    // For find the position of an element into a vector.
    // vector<string> books;
    // vector<string>::iterator search = find(books.begin(), books.end(), "topic");
    // if (search != books.end())
    // {
    //     int index = std::distance(books.begin(), search);
    // }

    /* code */
    return 0;
}
