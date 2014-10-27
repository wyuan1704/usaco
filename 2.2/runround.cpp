/*
ID: wyuan171
PROG: runround
LANG: C++
*/
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

class Solution
{
	bool isRunaround(size_t num)
	{
		numVec.clear();
		bool map[10] = {false};
		// No digit is Zero. No digit is repeated.
		while(num > 0)
		{
			int cur = num%10;
			if(cur == 0 || map[cur])
				return false;
			map[cur] = true;
			numVec.push_back(cur);
			num /= 10;
		}
		// Go around
		size_t size = numVec.size(); 
		reverse(numVec.begin(), numVec.end());
		int index = 0; int cur= index;
		for(size_t i=0; i<size; i++)
		{  
			cur = index;
			if(numVec[cur] == 0)
				return false;
			index = (index + numVec[cur]) % size;

			numVec[cur] = 0;
		}
		return index == 0;
	}
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		size_t M = 81361;
		fin >> M;
		for(size_t i = M+1; ; i++)
		{
			if(isRunaround(i))
			{
				fout << i;
				break;
			}
		}
		fout<<endl;
		fin.close();
		fout.close();
	}
private:
	ifstream fin;
	ofstream fout;
	vector<int> numVec;
};

int main()
{
	Solution sol("runround.in", "runround.out");
	sol.main();
	return 0;
}
