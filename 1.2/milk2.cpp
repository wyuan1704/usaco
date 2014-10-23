/*
ID: wyuan171
PROG: milk2
LANG: C++
*/

#include <fstream>
#include <cstring> //memset

using namespace std;

class Solution
{
	ifstream fin;
	ofstream fout;
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		// wyuan; 10/23/2014; Sacrifice memory for easiness. I read this solution from DD two years ago. Later I'll try sort the intervals as I did for Merge Intervals on leetcode.
		bool map[1000000+1] = {false};
		// memset(map, sizeof(map), false); // No need for C++
		int N=0; // Number of lines.
		fin>>N;
		int start, end;
		int minS = 1000000;
		int maxE = 0;
		for(int i=0; i<N; i++)
		{
			fin>> start >> end; // [1,3] -> map[1] and map[2] will be true. Point and Interval are different.
			memset(map+start, true, sizeof(bool)*(end-start));
			if(start < minS)
				minS = start;
			if(end > maxE)
				maxE = end;
		}
		int maxOcuSpan = 0;
		int maxNonOcuSpan = 0;
		int OcuSpan=0;
		int NonOcuSpan = 0;
		for(int i=minS; i<maxE; i++)
		{
			if(map[i])
			{
				OcuSpan++;
				NonOcuSpan=0;
			}
			else
			{
				OcuSpan=0;
				NonOcuSpan++;
			}
			if(OcuSpan > maxOcuSpan)
				maxOcuSpan = OcuSpan;
			if(NonOcuSpan > maxNonOcuSpan)
				maxNonOcuSpan = NonOcuSpan;
		}
		fout<< maxOcuSpan << " " << maxNonOcuSpan << endl;
		fin.close();
		fout.close();
	}

};

int main()
{
	Solution sol("milk2.in", "milk2.out");
	sol.main();
	return 0;
}
