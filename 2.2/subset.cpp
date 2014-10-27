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
// vector<int> &resVec is just for debugging.
	void dfs(int &res, vector<int> &resVec, int start, const int &end, int &target)
	{	
		if(target == 0)
		{	
			res ++;
			return;
		}

		if(start >= end || target < 0)
			return;

		dfs(res, resVec, start+1, end, target);
		target -= start+1; resVec.push_back(start+1);
		dfs(res, resVec, start+1, end, target); 
		target += start+1; resVec.pop_back();
	}
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		int N = 1;
		fin >> N;
		int sum = N *(N+1) / 2;
		int res = 0; vector<int> resVec;
		if(sum % 2 == 0)
		{
			int target = sum/2; 
			resVec.push_back(1);
			target -= 1; // Let 1 always be in the subset, then we don't have to divide res by 2.
			dfs(res, resVec, 1, N, target);
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
