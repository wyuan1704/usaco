/*
ID: wyuan171
PROG: pprime
LANG: C++
*/

#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

// 10/25/2014.
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
    
    int getPal(int i, bool isOdd)
    {
        int res = i;
        if(isOdd)
        {
            i /=10;
        }
        
        while(i > 0)
        {
            res = res*10 + i%10;
            i /=10;
        }
        
        return res;
    }

public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
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

        // Let's generate all the pprime in [1, 100,000,000], then output those in [a, b].
        // This is bad in the real world, but OK in this problem
        int a = 5, b = 500;
        fin >> a >> b;
        int start = 1;
        int end = 10;
        for(int width = 0; width < 4; width++)
        {
            for(int i=start; i<end; i++)
            {
                // odd
                int pal = getPal(i, true);
                if(isPrime(pal, isPrimeMap, primes) && pal >=a && pal <= b)
                {
                    fout << pal <<endl;
                }
            }
            
            for(int i=start; i<end; i++)
            {
                // even
                int pal = getPal(i, false);
                if(isPrime(pal, isPrimeMap, primes) && pal >=a && pal <= b)
                {
                    fout << pal <<endl;
                }
            }
            start *= 10;
            end *=10;
        }
		
		//fout<<endl;
		fin.close();
		fout.close();
	}
private:
	ifstream fin;
	ofstream fout;
};

int main()
{
	Solution sol("pprime.in", "pprime.out");
	sol.main();
	return 0;
}
