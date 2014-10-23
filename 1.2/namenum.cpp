/*
ID: wyuan171
PROG: namenum
LANG: C++11
*/

#include <fstream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName)
	{

	};
	void main()
	{		
		string digits ;
		fin >> digits;
		char map[9-1][3] = { 'A','B','C',  'D','E','F',   'G','H','I',
			'J','K','L', 'M','N','O',   'P','R','S',
			'T','U','V',  'W','X','Y'};
		vector<vector<string> > res(2); string emptyStr("");
		res[0].push_back(emptyStr);
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

		for(int i = 0; i < size; i++)
		{
			int d = digits[i] - '0';
			if(d < 2 || d > 9)
			{
				fout<<"NONE"<<endl;
				fout.close();
				return;
			}
			d -= 2;
			vector<string> &cur = res[i%2];
			vector<string> &temp = res[(i+1)%2];
			temp.clear();
			int curSize = cur.size();
			for(int j = 0; j < curSize; j++)
			{
				for(int k = 0; k < 3; k++)
				{
					string str = cur[j];
					str.push_back(map[d][k]);
					temp.push_back(str);
				}
			}
		}

		vector<string> &cur = res[(size)%2];
		bool found = false;
		for(int i=0; i < cur.size(); i++)
		{
			if(dict.find(cur[i]) != dict.end())
			{
				found = true;
				fout<<cur[i]<<endl;
			}	
		}
		if(!found)
			fout<<"NONE"<<endl;

		fin.close();
		fout.close();
	}
private:
	ifstream fin;
	ofstream fout;
	unordered_set<string> dict;
};

int main()
{
	Solution sol("namenum.in", "namenum.out");
	sol.main();
	return 0;
}
