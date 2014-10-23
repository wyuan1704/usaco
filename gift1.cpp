/*
ID: wyuan171
PROG: gift1
LANG: C++11
*/

#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
	ifstream fin;
	ofstream fout;
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		unordered_map<string, int> map; // name -> net value
		int NP; //Number of Persons.
		fin>>NP; 
		vector<string> persons(NP); // store orders.
		for(int i=0; i<NP; i++)
		{
			string name;
			fin>>name;
			map[name] = 0;
			persons[i] = name;
		}
		// Give money
		for(int i=0; i<NP; i++)
		{
			string giverName;
			int giveAmount;
			int recipients;
			fin>> giverName >> giveAmount >> recipients;
			if(recipients > 0)
			{	
				// Assume that all the input data is valid. So we don't have to check if someone is the map.
				map[giverName] -= giveAmount / recipients * recipients;
				string reciName;
				for(int j=0; j<recipients; j++)
				{
					fin>>reciName;
					map[reciName] += giveAmount / recipients;
				}
			}
		}
		// output
		for(int i=0; i<NP; i++)
		{
			fout << persons[i] << " " << map[persons[i]] << endl;
		}

		fin.close();
		fout.close();
	}

};

int main()
{
	Solution sol("gift1.in", "gift1.out");
	sol.main();
	return 0;
}
