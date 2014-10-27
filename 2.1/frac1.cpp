/*
ID: wyuan171
PROG: frac1
LANG: C++
*/

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

struct Fraction
{
    int n; //numerator
    int d; //Denominator;
    Fraction(int in, int id):n(in), d(id){};
};

int comp(const Fraction &a, const Fraction &b)
{
    return a.n * b.d < a.d * b.n;
}

class Solution
{
    int isReducedFrac(int n, int d)
    {
        if(n == 1)
            return true;
        if(d %n == 0)
            return false;
        int sqroot = sqrt(n);
        for(int i=2; i<=sqroot; i++)
            if(n%i == 0 && (d%i == 0 || d%(n/i) ==0))
                return false;
        return true;
    }

public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
        size_t N;
        fin >> N;
        //N = 7;
        vector<Fraction> fracs;
        fracs.push_back(Fraction(0, 1));
        for(int i=1; i<N; i++)
            for(int j=i+1; j<=N; j++)
            {
                if(isReducedFrac(i, j))
                    fracs.push_back(Fraction(i, j));
            }
		
        sort(fracs.begin(), fracs.end(), comp);
        fracs.push_back(Fraction(1, 1));
        
        size_t size = fracs.size();
        for(int i=0; i < size; i++)
            fout << fracs[i].n << '/' << fracs[i].d << endl;
        
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
	Solution sol("frac1.in", "frac1.out");
	sol.main();
	return 0;
}
