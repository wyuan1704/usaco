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

// 10/27/2014; This is like https://oj.leetcode.com/problems/word-break/

class Solution
{
    int longestPrefix(string s, unordered_set<string> &dict) {
        // wyuan; 10/09/2014; Dynamic programming. dp[i] means that s[0]~s[i] can be segmented.
        int size = s.size();
        vector<bool> dp(size, false);
        for(int i = 0; i < size; i++)
        {
            if(dp[i])
                continue;
            // if 0~i can be found in dict
            dp[i] = (dict.find(s.substr(0, i+1)) != dict.end() ? true:false);
            if(!dp[i])
            {
                // Check if it can be formed be smaller words
                for(int j=0; j<i; j++)
                {
                    if(dp[j])
                    {
                        dp[i] = (dict.find(s.substr(j+1, i-j)) != dict.end() ? true:false);
                        if(dp[i])
                            break;
                    }
                }
            }
        }
        
        for(int i=size-1; i>=0; i--)
        {
            if(dp[i])
                return i+1;
        }
        
        return 0;
    }
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
        unordered_set<string> dict;
        
        string word("");
        fin >> word;
        while(word != ".")
        {
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
        
        fout << longestPrefix(target, dict);
        
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
