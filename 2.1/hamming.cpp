/*
ID: wyuan171
PROG: hamming
LANG: C++
*/

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

// 10/25/2014; A typical DFS problem. Pay attention to the output format.

class Solution
{
    int bitSets(size_t t)
    {
        int res = 0;
        while(t)
        {
            t &= t-1;
            res++;
        }
        return res;
    }
    int hammingDistance(const size_t &a, const size_t &b)
    {
        size_t t = a ^ b;
        return bitSets(t);
    }
    
    bool dfs(size_t cur, vector<size_t> &visited, const size_t &end, size_t n, const size_t &d)
    {
        visited.push_back(cur);
        if(n == 1)
            return true;
        
        for(size_t i = cur+1; i < end; i++)
        {
            size_t visitedSize = visited.size();
            bool isCandi = true;
            for(size_t j = 0; j<visitedSize; j++)
                if(hammingDistance(visited[j], i) < d)
                {
                    isCandi = false;
                    break;
                }
            if(isCandi && dfs(i, visited, end, n-1, d))
                return true;
                
        }
        visited.pop_back();
        return false;
    }
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
        size_t N; // number of result set
        size_t B; // B bits
        size_t D; // least difference
        fin >> N >> B >> D;
        //N = 16; B=7; D=3;
        // 10/25/2014; A typical dfs problem
        vector<size_t> visited;
        visited.reserve(256);
        
        size_t end = 1 << (B);
		
        if(dfs(0, visited, end, N, D))
        {
            size_t visitedSize = visited.size();
            size_t i=0;
            for(; i<visitedSize; i++)
            {
                fout << visited[i];
                if(i %10 == 9)
                    fout<<endl;
                else if( i != visitedSize-1)
                    fout << " ";
            }
            if(i % 10 != 0) // not 9!! It's (9+1) -> 0
                fout << endl;
        }
        
		fin.close();
		fout.close();
	}
private:
	ifstream fin;
	ofstream fout;
};

int main()
{
	Solution sol("hamming.in", "hamming.out");
	sol.main();
	return 0;
}
