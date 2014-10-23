/*
ID: wyuan171
PROG: issue
LANG: C++
*/

#include <fstream>

using namespace std;

class Solution
{
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		
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
	Solution sol("issue.in", "issue.out");
	sol.main();
	return 0;
}
