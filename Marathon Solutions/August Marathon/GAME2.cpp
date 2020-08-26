#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    int ten = 1;
    while (ten <= n)
        ten *= 10;
    if (m % ten < n)
        cout << m / ten;
    else
        cout << m / ten + 1;
    return 0;
}
