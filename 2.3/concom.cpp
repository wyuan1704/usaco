/*
ID: wyuan171
PROG: concom
LANG: C++
*/

#include <fstream>
#include <cstring>
using namespace std;
// 10/28/2014;
class Solution
{
	void addController(int i, int j) // Which is better, (i, j) or (owner, owned) better?
	{
		if(controls[i][j])
			return;
		controls[i][j] = true;
		// i controls j now. Add j's owership to i.
		for(int owned=0; i<owned; owned++)
			owns[i][owned]  +=  owns[j][owned];
		// If one controls i, it controls j too.
		for(int owner=0; owner<101; owner++)
			if(controls[owner][i])
				addController(owner, j);
		// If i controls more company, mark it.
		for(int owned=0; i<owned; owned++)
			if(owns[i][owned] > 50)
				addController(i, owned);
	}

	void addOwnership(const int &i, const int &j, const int &portion)
	{
		for(int owner=0; owner<101; owner++)
			if(controls[owner][i])
				owns[owner][j] += portion; // According to condition 3. Portion is the same for the owner's owner, which may not be right in the right world.
		for(int owner=0; owner<101; owner++)
			if(owns[owner][j] > 50)
				addController(owner, j);
	}
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		memset(owns, 0, sizeof(owns)/sizeof(int));
		memset(controls, false, sizeof(controls)/sizeof(bool));
		for(int i=0; i<101; i++)
			controls[i][i] = true;

		int numOfTriples = 0;
		fin >> numOfTriples;
		int owner=0, owned = 0, portion = 0;
		for(int i=0; i<numOfTriples; i++)
		{
			fin >> owner >> owned >> portion;
			addOwnership(owner, owned, portion);
		}
		for(int owner=1; owner<101; owner++)
		{
			for(int owned=1; owned<101; owned++)
			{
				if(owner != owned && controls[owner][owned])
					fout << owner << " " << owned << endl;
			}
		}
		//fout<<endl;
		fin.close();
		fout.close();
	}
private:
	ifstream fin;
	ofstream fout;
	int owns[101][101];  // owns[i][j] means that the portion that company i owns j. If it >= 50, controls[i][j] is true
	bool controls[101][101]; // controls[i][j] means if company i controls j.
};

int main()
{
	Solution sol("concom.in", "concom.out");
	sol.main();
	return 0;
}
