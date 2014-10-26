/*
ID: wyuan171
PROG: holstein
LANG: C++
*/

#include <fstream>
#include <vector>

using namespace std;
// 10/26/2014; The data is very small. Simply DFS or BFS is OK. Let's try http://graphics.stanford.edu/~seander/bithacks.html#NextBitPermutation to generate a binay code of combination.
class Solution
{
    size_t nextBitPermutation(size_t v)
    {
        size_t t = (v | (v - 1)) + 1;
        return t | ((((t & -t) / (v & -v)) >> 1) - 1);
    }
    
    bool isValid(const size_t &pos, vector<int> needed, vector< vector<int> > &candis)
    {
        for(size_t bit = 0; bit < G; bit++)
            if( (1 << bit) & pos)
            {
                for(int i=0; i<V; i++)
                {
                    needed[i] -= candis[bit][i];
                }
            }
        for(int i=0; i<V; i++)
        {
            if(needed[i] > 0)
                return false;
        }
        return true;
    }
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
    {
        fin >> V;
        vector<int> needed(V);
        for(int i=0; i<V; i++)
            fin >> needed[i];
        
        fin >> G;
        vector< vector<int> > candis(G);
        
        int cur=0;
        for (int g=0; g < G; g++) {
            for(int j=0; j<V; j++)
            {
                fin >> cur;
                candis[g].push_back(cur);
            }
        }
        
        bool found = false;
        for (int g=1; g <= G; g++) {
            size_t pos = (1<<g)-1;
            size_t end = 1<<G;
            while(!found && pos < end)
            {
                if(isValid(pos, needed, candis))
                {
                    fout << g;
                    for(size_t bit = 1; bit <=G; bit++)
                        if( (1<<(bit-1)) & pos)
                            fout << " " << bit;
                    found = true;
                    break;
                }
                pos = nextBitPermutation(pos);
            }
            if(found)
                break;
        }
        
		fout<<endl;
		fin.close();
		fout.close();
	}
private:
	ifstream fin;
	ofstream fout;
    int V; // number of types of vitamins [1,25]
    int G; // number of types of feeds [1,15]
};

int main()
{
	Solution sol("holstein.in", "holstein.out");
	sol.main();
	return 0;
}
