/*
ID: wyuan171
PROG: sprime
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 10/25/2014; At first, I define "bool isPrime[100000000]", which is too large. Then I change it to "bool isPrime[10000], and check every number between 10^(N-1) and (10^N - 1), which is too slow. I did two submits for these two changes, but maybe I didn't add them first, so I lost these changes. Sad!
// Now, to get N super primes, start from (N-1) super primes.

class Solution
{
    bool isPrime(int i, vector<bool> &isPrimeMap, vector<int> &primes)
    {
        
        if(i < 10000)
        {
            if(!isPrimeMap[i])
                return false;
        }
        else
        {
            int sqroot = sqrt(i);
            int size = primes.size();
            for(int j=0; j < size && primes[j] <= sqroot; j++)
            {
                if(i % primes[j] == 0)
                    return false;
            }
        }
        
        return true;
    }
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
        int N;
        fin >> N;
        //N=4;
        vector<bool> isPrimeMap(10000, true);
        
        vector<int> primes;
        isPrimeMap[0] = isPrimeMap[1] = false;
        for(int i=2; i<10000; i++)
        {
            if(isPrimeMap[i])
            {
                primes.push_back(i);
                int end = 10000/i;
                for(int times=2; times <= end; times++)
                    isPrimeMap[i * times] = false;
            }
        }
        
        vector<vector<int> > superPrimes(2);
        int len = 1;
        superPrimes[len].push_back(2);
        superPrimes[len].push_back(3);
        superPrimes[len].push_back(5);
        superPrimes[len].push_back(7);
        
        for(int len=2; len<=N; len++)
        {
            int oldSize = superPrimes[(len+1)%2].size();
            superPrimes[len%2].clear();
            for(int i=0; i<oldSize; i++)
            {
                for(int last=0; last < 5; last++)
                {
                    int superPrimeCandi = superPrimes[(len+1)%2][i] * 10 + (2*last + 1);
                    if(isPrime(superPrimeCandi, isPrimeMap, primes))
                        superPrimes[len%2].push_back(superPrimeCandi);
                }
            }
        }
        
        for(int i=0; i<superPrimes[N%2].size(); i++)
            fout<< superPrimes[N%2][i]<<endl;
        
		fin.close();
		fout.close();
	}
private:
	ifstream fin;
	ofstream fout;
};

int main()
{
	Solution sol("sprime.in", "sprime.out");
	sol.main();
	return 0;
}
