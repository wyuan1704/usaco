/*
ID: wyuan171
PROG: lamps
LANG: C++
*/

#include <fstream>
#include <vector>
using namespace std;

class Solution
{

public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		int N=10, C=0; // Number of lamps.
		fin >> N >> C;

		C %=4;

		bool map[100] = {false}; 
		vector< int > lampConfigs;

		for(size_t press=0; press < 16; press++)
		{
			size_t cur = 0;
			if(press & 1) // Button 1 -- Change all -- XOR 0xffff ffff
				cur ^= ~(size_t(0));
			if(press & 2) // Button 2 -- Change all odd -- XOR (010101)
				cur &= 0x55555555;
			if(press & 4) // Button 1 -- Change all -- XOR 101010
				cur &= 0xAAAAAAAA;
			if(press & 8) // Button 1 -- Change all -- XOR 001001
				cur &= 0x9; cur &=63;
			map[cur] = true;
		}
		for(int i=0; i<64; i++)
		{	
			if(map[i])
				lampConfigs.push_back(i);
		}
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
	Solution sol("lamps.in", "lamps.out");
	sol.main();
	return 0;
}
