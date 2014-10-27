/*
ID: wyuan171
PROG: lamps
LANG: C++
*/
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
	// Use 6 bits to store all the lamp configurations.
	size_t getLampConfig(size_t press, size_t &pressCount)
	{
		size_t cur=~0;
		pressCount = 0;
		if(press & 1) // Button 1 -- Change all -- XOR 0xffff ffff
		{
			cur ^= ~(size_t(0));
			pressCount++;
		}
		if(press & 2) // Button 2 -- Change all odd -- XOR (010101)
		{
			cur ^= 0x55555555;
			pressCount++;
		}
		if(press & 4) // Button 1 -- Change all -- XOR 101010
		{
			cur ^= 0xAAAAAAAA;
			pressCount++;
		}
		if(press & 8) // Button 1 -- Change all -- XOR 001001
		{
			cur ^= 0x9;
			pressCount++;
		}
		cur &=63;
		return cur;
	}

	string output(size_t cur, size_t N)
	{
		string res("");
		for(int i=0; i<N; i++)
		{
			bool curbit = (cur & (1 <<(i%6)));
			res.push_back(curbit + '0');
		}
		return res;
	}
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		// Get all the configurations.
		bool map[5][100] = {false}; 
		vector< vector<int> > lampConfigs(5);
		for(size_t press=0; press < 16; press++)
		{
			size_t pressCount = 0;
			size_t cur = getLampConfig(press, pressCount);

			map[pressCount][cur] = true;
		}
		for(int pressCount=0; pressCount<5; pressCount++)
		{	
			for(int i=0; i<64; i++)
			{	
				if(map[pressCount][i])
				{
					lampConfigs[pressCount].push_back(i);
					if(pressCount+2 < 5)
						lampConfigs[pressCount+2].push_back(i);
					if(pressCount+4 < 5)
						lampConfigs[pressCount+4].push_back(i);
				}
			}
		}

		for(int pressCount=0; pressCount<5; pressCount++)
			sort(lampConfigs[pressCount].begin(), lampConfigs[pressCount].end());
		// Init
		size_t N=10, C=0; // Number of lamps.
		fin >> N >> C;

		size_t onLight = 0, offLight = 0;
		size_t lightNum = 0;
		fin >> lightNum;
		while(lightNum != -1)
		{
			onLight |= 1<<((lightNum-1)%6);
			fin >> lightNum;
		}

		fin >> lightNum;
		while(lightNum != -1)
		{
			offLight |= 1<<((lightNum-1)%6);
			fin >> lightNum;
		}

		// output.
		size_t p = 0;
		if(C > 0)
		{
			p = (C%4);
			if( p == 0)
				p = 4;
		}
		int found = 0;
		vector<string> res;
		for(int i=0; i < lampConfigs[p].size(); i++)
		{
			size_t cur = lampConfigs[p][i];
			if( ((cur & onLight) == onLight) && ((cur & offLight) == 0))
			{
				found++;
				res.push_back(output(cur, N));
			}
		}
		sort(res.begin(), res.end());
		for(int i=0; i<found; i++)
			fout<<res[i]<<endl;

		if(found == 0)
			fout<< "IMPOSSIBLE" << endl;
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
