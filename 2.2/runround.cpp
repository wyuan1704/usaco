/*
ID: wyuan171
PROG: runround
LANG: C++
*/

#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

class Solution
{
	bool isRunaround(size_t num)
	{
		string numStr("");
		std::stringstream lSStream;
		lSStream << num;
		lSStream >> numStr;

		memset(visited, false, sizeof(visited)/sizeof(bool));
		size_t size = numStr.size();
		for(size_t i=0; i<size; i++)
		{
			int cur = numStr[i] - '0';
			if(visited[cur])
				return false;
			visited[cur] = true;
		}
		if(visited[0])
			return false;
		size_t count = size;
		int index = 0;
		while(count-- > 0)
		{
			int cur = numStr[index] - '0'; 
			if(cur == 0)
				return false; 
			numStr[index] = '0';
			//visited[cur] = false;
			index += cur;
			index %= size;
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
	bool visited[10];
};

int main()
{
	Solution sol("runround.in", "runround.out");
	sol.main();
	return 0;
}
