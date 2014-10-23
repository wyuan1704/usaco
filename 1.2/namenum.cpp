/*
ID: wyuan171
PROG: namenum
LANG: C++11
*/
// 10/23/2014; Instead of store all candidates, use dfs to save memory.
#include <fstream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution
{
	void dfs(const string &digits, string &candi, char map[9-1][3], const int &size, int s)
	{
		if(s == size)
		{
			if(dict.find(candi) != dict.end())
			{
				found = true;
				fout<< candi <<endl;
			}
			return;
		}
		int cur = digits[s] - '2';
		if(cur < 0 || cur > 9-2)
			return;
		for(int i=0; i<3; i++)
		{
			candi.push_back(map[cur][i]);
			dfs(digits, candi, map, size, s+1);
			candi.pop_back();
		}
	}
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName), found(false)
	{

	};
	void main()
	{		
		string digits ;
		fin >> digits;
		char map[9-1][3] = { 'A','B','C',  'D','E','F',   'G','H','I',
			'J','K','L', 'M','N','O',   'P','R','S',
			'T','U','V',  'W','X','Y'};

		int size = digits.size();

		ifstream fdict("dict.txt");
		string word;
		fdict>>word;
		// To save some memory.
		while (fdict.good()) {
			if(word.size() == size)
				dict.insert(word);
			fdict>>word;
		}
		fdict.close();

		string candi;
		dfs(digits, candi, map, size, 0);

		if(!found)
			fout<<"NONE"<<endl;

		fin.close();
		fout.close();
	}
private:
	ifstream fin;
	ofstream fout;
	bool found;
	unordered_set<string> dict;
};

int main()
{
	Solution sol("namenum.in", "namenum.out");
	sol.main();
	return 0;
}
