/*Parallelopied property
It has three sets of four parallel edges and the edges within each set have equal measurement of length.*/

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int a[12];
            for (int i = 0; i < 12; i++)
                cin >> a[i];
            bool ans = true;
            for (int i = 0; i < 12; i++) {
                int k = 0;
                for (int j = 0; j < 12; j++)
                    k += (a[i] == a[j]);
                if (k % 4 != 0) ans = false;

        }
        cout << ((ans) ? "yes" : "no") << endl;
    }
}
