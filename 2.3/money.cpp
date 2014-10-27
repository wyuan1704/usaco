/*
ID: wyuan171
PROG: money
LANG: C++
*/

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// 10/27/2014; https://oj.leetcode.com/problems/combination-sum/

class Solution
{
    unsigned long long combinationSum(vector<int> &candidates, const int &target) {
        
        sort(candidates.begin(), candidates.end(), greater<int>());
        unsigned long long res=0;
    
        helper(res, candidates, 0, 0, target);
        return res;
    }
    void helper(unsigned long long &res, vector<int> &candidates, int curSum, int start, const int &target)
    {
        for(int i = start; i<V; i++)
        {
            int cur = candidates[i] + curSum;
            if(cur > target)
                continue;
            else if(cur == target)
            {
                res++;
                continue;
            }
            else
            {
                // The same repeated number may be chosen from C unlimited number of times.!!!
                //helper(res, candidates, curRes, curSum + candidates[i], i+1, target);
                helper(res, candidates, cur, i, target);
            }
        }
    }
    
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
        fin >> V;
        int N;
        fin >> N;
        vector<int> coins(V);
        for(int i=0; i<V; i++)
            fin >> coins[i];
        
        fout << combinationSum(coins, N);
		
		fout<<endl;
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
