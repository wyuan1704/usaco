/*
ID: wyuan171
PROG: subset
LANG: C++
*/

#include <fstream>
#include <vector>
using namespace std;

class Solution
{

public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		size_t N = 1;
		fin >> N;
		// 10/27/2014; To be fast, use dynamic sourcing.
		// dp[j] represents the number of sets, which can be made from the set of {1, 2, ..., N}, whose sum is i.
		// dp[j] = sum(dp[j-i) , i is in [1, N]
		size_t dp[(1+39)*40/4 + 1] = {0}; // N is in [1,39];
		dp[0] = 1;
		size_t sum = N * (N+1) / 2;
		size_t res = 0;
		if(sum % 2 == 0)
		{
			sum /=2;
			for (size_t i=1;i<=N;i++)
			{
				for (size_t j=sum; j>=i; j--)
					dp[j] = dp[j] + dp[j-i];
			}
			res = dp[sum] / 2;
		}

		fout << res;
		fout<<endl;
		fin.close();
		fout.close();
	}
private:
	ifstream fin;
	ofstream fout;
};

int main()
{
	Solution sol("subset.in", "subset.out");
	sol.main();
	return 0;
}
