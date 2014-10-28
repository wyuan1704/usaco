/*
ID: wyuan171
PROG: money
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
        fin >> V;
        int N;
        fin >> N;
        
		vector<long long> dp(N+1, false); // dp[i] means the total number of ways to construct i money units.
		dp[0] = 1;
		int coin = 0;
        for(int i=0; i<V; i++)
		{
            fin >> coin;
			for(int j=coin; j<= N; j++)
				dp[j] += dp[j-coin];
        }
       		
		fout << dp[N] << endl;
		fin.close();
		fout.close();
	}
private:
	ifstream fin;
	ofstream fout;
    int V;
};

int main()
{
	Solution sol("money.in", "money.out");
	sol.main();
	return 0;
}
