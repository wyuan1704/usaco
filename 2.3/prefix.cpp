/*
ID: wyuan171
PROG: prefix
LANG: C++11
*/

#include <fstream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

// 10/27/2014; This is like https://oj.leetcode.com/problems/word-break/. Leetcode is loose. USACO is more strict. In fact, there're solutions much faster than this. To do - optimize.

class Solution
{
    int longestPrefix(string &s, unordered_set<string> &dict, int maxWordLen) {
        // wyuan; 10/09/2014; Dynamic programming. dp[i] means that s[0]~s[i] can be segmented.
        int size = s.size();
        vector<bool> dp(size+1, false);
        dp[0] = true;
        for(int i = 0; i <= size; i++)
        {
            if(!dp[i])
                continue;
            
            for(int len = 1; len <= maxWordLen; len++)
            {
                if(!dp[i+len] && dict.find(s.substr(i, len)) != dict.end())
                   dp[i+len] = true;
            }
        }
        
        for(int i=size; i>0; i--)
        {
            if(dp[i])
                return i;
        }
        
        return 0;
    }
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
        unordered_set<string> dict;
        int maxWordLen = 0;
        string word("");
        fin >> word;
        while(word != ".")
        {
            if(maxWordLen < word.size())
                maxWordLen = word.size();
            dict.insert(word);
            fin >> word;
        }
        
        string target("");
        fin >> word;
        while(fin.good())
        {
            target += word;
            fin >> word;
        }
        
        fout << longestPrefix(target, dict, maxWordLen);
        
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
	Solution sol("prefix.in", "prefix.out");
	sol.main();
	return 0;
}
