/*
ID: wyuan171
PROG: milk2
LANG: C++
*/

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool comp(const Interval &a, const Interval &b)
{
	if(a.start == b.start)
		return a.end < b.end;

	return a.start < b.start;
}


class Solution
{
	ifstream fin;
	ofstream fout;
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		// wyuan; 10/23/2014; 
		int N;
		fin >> N;
		if(N < 1)
		{
			fout<< 0 << " " << 0 << endl;
			fin.close();
			fout.close();
		}		
		vector<Interval> intervals(N);
		int start, end;
		for(int i=0; i<N; i++)
		{
			fin >> start >> end;
			intervals[i] = Interval(start, end);
		}
		sort(intervals.begin(), intervals.end(), comp);

		Interval cur = intervals[0];
		int maxOcuSpan = cur.end - cur.start;
		int maxNonOcuSpan = 0;
		for(int i=1; i<N; i++)
		{
			if(cur.end < intervals[i].start)
			{
				if(cur.end - cur.start > maxOcuSpan)
					maxOcuSpan = cur.end - cur.start;
				if(intervals[i].start - cur.end > maxNonOcuSpan)
					maxNonOcuSpan = intervals[i].start - cur.end;
				cur = intervals[i];
			}
			else if(cur.end < intervals[i].end)
			{
				cur.end = intervals[i].end;
			}
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
