/*
ID: wyuan171
PROG: nocows
LANG: C++
*/

#include <fstream>
#include <cmath>
using namespace std;
// 10/28/2014; Dynamic programming.
/*
1) Let B(n, d) be number of possible pedigrees binary tree, whose nodes are n and depth are d.
B(n, d) = Sum( B(j, d1) * B(n-1 -j, d2) ), where j is in [0, n-1], if max(d1, d2) == d-1.
This formula is complicated and not easy to implemented.

2) A simpler solution. Let B(n, d) be the number of possible pedigrees binary tree, whose nodes are n and depth are <= d.
B(n, d) = B(n1, d-1) * B(n-1-n1, d-1).
Then B(N, K) - B(N, K-1).
*/
class Solution
{

	size_t log2(size_t v)
	{

		size_t r = 0; 
		while (v >>= 1)
		{
			r++;
		} return r;
	}
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		size_t N =0, K=0;
		fin >> N >> K;
		long long dp[200][100] = {0};
		// !!! boundary conditions
		for(int k=1; k<100; k++)
			dp[1][k] = 1;
		for(size_t n=2; n<200; n++)
		{
			for(size_t depth = 1; depth<= K; depth++)
			{
				for(size_t n1=1; n1<n; n1++)
				{
					dp[n][depth] += dp[n1][depth-1] * dp[n-1-n1][depth-1];
					dp[n][depth] %= 9901;
				}		
			}
		}
		long long res = (dp[N][K] - dp[N][K-1] + 9901) % 9901;
		fout << res << endl;
		fin.close();
		fout.close();
	}
private:
	ifstream fin;
	ofstream fout;
};

int main()
{
	Solution sol("nocows.in", "nocows.out");
	sol.main();
	return 0;
}
