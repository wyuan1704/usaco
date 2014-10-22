/*
ID: wyuan171
PROG: ride
LANG: C++
*/
/*
In the official solution, "hash" is a good name. He also checks isalpha() while I don't.
int hash(char *s)
{
	int i, h;

	h = 1;
	for(i=0; s[i] && isalpha(s[i]); i++)
		h = ((s[i]-'A'+1)*h) % 47;
	return h;
}
*/

#include <fstream>
#include <string>
using namespace std;

int getCode(string &s)
{
	int res = 1;
	int size = s.size();
	for(int i=0; i<size; i++)
	{
		res *= s[i] - 'A' + 1;
		res %= 47;
	}
	return res;
}

int main()
{
	ifstream fin("ride.in");
	string group("");
	string comet("");
	fin >> group >> comet;
	fin.close();

	ofstream fout("ride.out");
	if(getCode(group) == getCode(comet))
		fout<<"GO"<<endl;
	else
		fout<<"STAY"<<endl;

	fout.close();
	return 0;
}
