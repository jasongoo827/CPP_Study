#include <iostream>
#include <vector>

using namespace std;

// boj 16935

int n, m;
int arr[100][100];
int r;

void cal1()
{
    int tmp[100][100];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            tmp[n - i - 1][j] = arr[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            arr[i][j] = tmp[i][j];
}

void cal2()
{
    int tmp[100][100];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            tmp[i][m - j - 1] = arr[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            arr[i][j] = tmp[i][j]; 
}

void cal3()
{
    int tmp[100][100];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            tmp[j][n - i - 1] = arr[i][j];
    swap(n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            arr[i][j] = tmp[i][j];
}

void cal4()
{
    int tmp[100][100];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            tmp[m - j - 1][i] = arr[i][j];
    swap(n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            arr[i][j] = tmp[i][j];
}

void cal5()
{
    int tmp[100][100];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i < n / 2 && j < m / 2)
                tmp[i][j + m / 2] = arr[i][j];
            else if (i < n / 2 && j >= m / 2)
                tmp[i + n / 2][j] = arr[i][j];
            else if (i >= n / 2 && j >= m / 2)
                tmp[i][j - m / 2] = arr[i][j];
            else if (i >= n / 2 && j < m / 2)
                tmp[i - n / 2][j] = arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            arr[i][j] = tmp[i][j];
}

void cal6()
{
    int tmp[100][100];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i < n / 2 && j < m / 2)
                tmp[i + n / 2][j] = arr[i][j];
            else if (i < n / 2 && j >= m / 2)
                tmp[i][j - m / 2] = arr[i][j];
            else if (i >= n / 2 && j >= m / 2)
                tmp[i - n / 2][j] = arr[i][j];
            else if (i >= n / 2 && j < m / 2)
                tmp[i][j + m / 2] = arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            arr[i][j] = tmp[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    vector<int> rot(r);
    vector<int> opt;
    for (int i = 0; i < r; ++i)
        cin >> rot[i];
    
    int i = 0;
    while (i < r)
    {
        int op = rot[i];
        int cnt = 1;

        while (i + 1 < r && rot[i + 1] == op)
        {
            cnt++;
            i++;
        }
        if (op == 1 || op == 2)
            cnt %= 2;
        else if (op == 3 || op == 4)
        {
            cnt %= 4;
            if (cnt == 3)
            {
                if (op == 3)
                    op = 4;
                else if (op == 4)
                    op = 3;
                cnt = 1;
            }
        }
        else if (op == 5 || op == 6)
        {
            cnt %= 4;
            if (cnt == 3)
            {
                if (op == 5)
                    op = 6;
                else if (op == 6)
                    op = 5;
                cnt = 1;
            }
        }
        for (int j = 0; j < cnt; ++j)
            opt.push_back(op);
        i++;
    }

    for (int i = 0; i < opt.size(); ++i)
    {
        if (i + 1 < opt.size() && \
        ((opt[i] == 3 && opt[i + 1] == 4) || (opt[i] == 4 && opt[i + 1] == 3) || \
        (opt[i] == 5 && opt[i + 1] == 6) || (opt[i] == 6 && opt[i + 1] == 5)))
            i++;
        else
        {
            if (opt[i] == 1)
                cal1();
            else if (opt[i] == 2)
                cal2();
            else if (opt[i] == 3)
                cal3();
            else if (opt[i] == 4)
                cal4();
            else if (opt[i] == 5)
                cal5();
            else if (opt[i] == 6)
                cal6();
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << arr[i][j] << " ";
        cout << '\n';
    }

    return 0;
}