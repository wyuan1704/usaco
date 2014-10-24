/*
ID: wyuan171
PROG: barn1
LANG: C++
*/
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
// 10/24/2014; The official gives a greedy solution in "Greedy Algorithm". For form N=5 solution, we look in the N=4 solution, find the longest unnecessary span and delete it. When N=1, we can put one board to cover all of them. For N=2, we cut the board into half by removing the longest unnecessary span.
class Solution
{
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{	
		size_t M, S, C;
		fin >> M >> S >> C;

		vector<bool> map(S, false); // true if occupied by a cow

		int stall;
		for(int i=0; i<C; i++)
		{
			fin>>stall;
			map[stall-1] = true;
		}

		// find all the spans between two continuous boards
		//  3, 4,   6,    9,   12
		// span:  1    2     2
		vector<size_t> spans;
		size_t count = C;
		size_t curSpan = 0;
		bool foundFirst = false;
		for(int i=0; i < S && count > 0; i++)
		{
			if(map[i])
			{
				if(foundFirst && curSpan > 0)
					spans.push_back(curSpan);
				foundFirst = true;
				curSpan = 0;
			}
			else
				curSpan++;
		}

		sort(spans.begin(), spans.end());

		size_t totalCoverd = C;
		if(spans.size() > M-1) // Do you know why this is necessary? Consider bool b = int(0) <  size_t(-1);
		{
			int end = spans.size() - (M - 1);
			for(int i=0; i < end; i++) // Remove the largest (M-1) spans.
			{
				totalCoverd += spans[i];
			}
		}

		fout<<totalCoverd;
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
	Solution sol("barn1.in", "barn1.out");
	sol.main();
	return 0;
}
