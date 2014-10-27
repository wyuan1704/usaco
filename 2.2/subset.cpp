/*
ID: wyuan171
PROG: subset
LANG: C++
*/

#include <fstream>

using namespace std;

class Solution
{
	void dfs(int &res, int start, const int &end, int &target)
	{	if(target == 0)
			res ++;

		for(int i=start+1; i<=end; i++)
		{
			target -= i;
			dfs(res, i, end, target);
			target += i;
		}
	}
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		int N = 1;
		fin >> N;
		int sum = N *(N+1) / 2;
		int res = 0;
		if(sum % 2 == 0)
		{
			int target = sum/2;
			target -= 1; // Let 1 always be in the subset, then we don't have to divide res by 2.
			dfs(res, 1, N, target);
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
