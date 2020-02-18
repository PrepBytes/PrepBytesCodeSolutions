#include <bits/stdc++.h>
using namespace std;

vector<pair<long,long>> factors;  // to store factor pair
vector <pair<int,int>> primeNumbers; // to store count of each prime factor

int xPosSide[100001],xNegSide[100001],yPosSide[100001],yNegSide[100001];
int sieve[100001]={0};

// to calculate smallest prime factor of each number using sieve
void sieveSmallestPrime()
{
    for(int i=2;i<100001;i++)
    {
        if(sieve[i]==0)
        {
            for(int j=i;j<100001;j=j+i)
                if(sieve[j]==0)
                    sieve[j]=i;
        }
    }
}

// Getting all the factors from the prime factors using recursion (121 factors for 10^10 case)
void calAllFactors(int flag, long long den, long long num)
{
    if(flag < 0) {
        if(den < 100001 && num/den < 100001) {
            factors.emplace_back(make_pair(den, num/den));
          //  cout<<"factor1= "<< den<<" ,factor2= "<< num/den<<"\n";

        }
        return;
    }
    long long val = primeNumbers[flag].first, mul = 1;
    for(int j=0;j<primeNumbers[flag].second+1;j++) {
        if(flag >= 0)
            calAllFactors(flag-1, den * mul, num);
        mul *= val;
       // cout<<"mul= "<< mul<<"\n";
    }
}

// function to calculate the count of each prime factor. if 1000 then 2 is 3 times and 5 is 3 times(log n)
void calPrimeFac(long long ele)
{
    primeNumbers.clear();
    factors.clear();
    long long sq = ele*ele;
    while(ele>1)
    {
        int smallestPrime = sieve[ele], primeCount=0;
        while(ele%smallestPrime==0)
        {
            ele = ele/smallestPrime;
            primeCount++;
        }
        primeNumbers.emplace_back(make_pair(smallestPrime,2*primeCount));
        //cout<<"smallest prime= "<< smallestPrime<<" ,primeCount= "<< primeCount<<"\n";
    }
    calAllFactors(int(primeNumbers.size())-1, 1, sq);
}
int main() {
    ios_base::sync_with_stdio(false);
    sieveSmallestPrime();
   // calPrimeFac(2);
    int t;
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        long long xaxis[n], yaxis[m];
        int zerox = 0, zeroy = 0;
        long long count = 0, factorCount = 0;
        memset(xPosSide, 0, sizeof(xPosSide));
        memset(xNegSide, 0, sizeof(xNegSide));
        memset(yPosSide, 0, sizeof(yPosSide));
        memset(yNegSide, 0, sizeof(yNegSide));
        for (int i = 0; i < n; i++) {
            cin >> xaxis[i];
            if (xaxis[i] == 0)
                zerox++;
            else if (xaxis[i] > 0)
                xPosSide[xaxis[i]] = 1;
            else
                xNegSide[abs(xaxis[i])] = 1;
        }
        for (int i = 0; i < m; i++) {
            cin >> yaxis[i];
            if (yaxis[i] == 0)
                zeroy++;
            else if (yaxis[i] > 0)
                yPosSide[yaxis[i]] = 1;
            else
                yNegSide[abs(yaxis[i])] = 1;
        }
        for (int i = 0; i < m; i++) {
            calPrimeFac(abs(yaxis[i]));
            for (int j = 0; j < factors.size(); j++) {
                factorCount = 0;
                if (xPosSide[factors[j].first] == 1 && xNegSide[factors[j].second] == 1)
                    factorCount++;
                /*if (xPosSide[factors[j].second] == 1 && xNegSide[factors[j].first] == 1 && factors[j].first != factors[j].second)
                    factorCount++;*/
                count += factorCount;
            }

        }
        for (int i = 0; i < n; i++) {
            calPrimeFac(abs(xaxis[i]));
            for (int j = 0; j < factors.size(); j++) {
                factorCount = 0;
                if (yPosSide[factors[j].first] == 1 && yNegSide[factors[j].second] == 1)
                    factorCount++;
               /* if (yPosSide[factors[j].second] == 1 && yNegSide[factors[j].first] == 1 &&
                    factors[j].first != factors[j].second)
                    factorCount++;*/
               
                count += factorCount;
            }

        }

        if (zerox != 0 || zeroy != 0) {
            count += ((long long) (n - zerox) * (m - zeroy));
        }
        cout << count << "\n";


    }
    return 0;
}
