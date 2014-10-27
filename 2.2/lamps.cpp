/*
ID: wyuan171
PROG: lamps
LANG: C++
*/

#include <fstream>
#include <algorithm>
using namespace std;

class Solution
{
// Pressing any button even times is equal to not pressing. Pressing odd times is equal to pressing once.
vector<bool> genLampCofig(int pressing, int N)
{
	bool defaultVal = (pressing & 1); // button 1
	vector<bool> res(N+1, defaultVal);
		
	if(pressing & 2) // button 2
	{
		for(int i=0; 2*i + 1 <= N; i++)
			res[2*i + 1] ^= res[2*i + 1];
	}
	
	if(pressing & 4) // button 3
	{
		for(int i=0; 2*i<=N; i++)
			res[2*i] ^= res[2*i];
	}
	
	if(pressing & 8) // button 4
	{
		for(int i=0; 3*i + 1 <=N; i++)
			res[3*i + 1] ^= res[3*i + 1];
	}
	return res;
}

bool isValid(vector<bool> &lampConfig, vector<int> &lightOn, vector<int> &lightOff)
{
	size_t onSize = lightOn.size();
	for(size_t i=0; i<onSize; i++)
		if(lampConfig[lightOn[i] == false)
			return false;
	
	size_t offSize = lightOff.size();
	for(size_t i=0; i<offSize; i++)
		if(lampConfig[lightOff[i] == true)
			return false;
	
	return true;
}
int compare(vector<bool> &lamp1, vector<bool> &lamp1, int N)
{
	for(int i=1;  i<=N; i++)
	{
		if(lamp1[i] > lamp2[i])
			return -1;
		else if(lamp1[i] < lamp2[i])
			return 1;
	}
	return 0;
}
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		int N=10, C=0; // Number of lamps.
		fin >> N >> C;
		
		C %=4;
		vector< vector<bool> > lampCofigs;
		switch(c)
		{
			
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
