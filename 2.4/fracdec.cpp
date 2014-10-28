/*
ID: wyuan171
PROG: fracdec
LANG: C++
*/

#include <fstream>
#include <string>
using namespace std;

class Solution
{
	void fracToDecimal(int N, int D)
	{
		int integer = N/D;
		fout << integer << ".";
		int repeat = 0;
		bool map[100000+1] = {false};

		int curN = N%D;
		if(curN == 0)
		{
			fout << 0 << endl;
			return;
		}
		int count = 0;
		while(curN > 0 && !map[curN])
		{
			map[curN] = true;
			curN = (curN * 10) % D;
			count++;
		}
		repeat = curN;
		curN = N%D;
		while(count-- > 0)
		{
			if(repeat == curN)
				fout << "(";
			curN *= 10;
			fout << curN/D;
			curN  %= D;
		}
		if(repeat != 0)
			fout << ')';


		fout<<endl;
	}
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		int N=1; // numerator
		int D=1; // denominator
		fin >> N >> D;
		fracToDecimal(N, D);
		/*fracToDecimal(1, 3);
		fracToDecimal(22, 5);
		fracToDecimal(1, 7);
		fracToDecimal(2, 2);
		fracToDecimal(3, 8);
		fracToDecimal(45, 56);*/
		fin.close();
		fout.close();
	}
private:
	ifstream fin;
	ofstream fout;
};

int main()
{
	Solution sol("fracdec.in", "fracdec.out");
	sol.main();
	return 0;
}
