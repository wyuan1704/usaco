/*
PROG: combo
ID: yuanwan1
LANG: C++
*/
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int comboLen(int a, int b, int N)
{
	vector<bool> lVec;
	for(int i = 0; i<N; i++)
		lVec.push_back(0);
	for(int i = -2; i <=2; i++)
	{
		lVec[(i+a+N)%N] = true;
		lVec[(i+b+N)%N] = true;
	}
	int lRet = 0;
	for(int i = 0; i < N; i++)
	{
		if(lVec[i])
			lRet++;
	}
	return lRet;
}
	
int main()
{
    // wyuan; 10/01/2014. Just think about only one number. When N<=5, every number is close enough. When N > 5, [num-2, num+2] is the range. Two keys may overlap. We should get the valid range.
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	int N;
	int johnCode[3];
	int masterCode[3];	
	fin>>N;
	for(int i=0; i<3; i++)	
		fin>>johnCode[i];
	for(int i=0; i<3; i++)
		fin>>masterCode[i];
	int combo = 1;
	for(int i = 0; i<3; i++)
		combo *= 2*(5>N?N:5) - comboLen(johnCode[i], masterCode[i], N);
	int len = 5>N?N:5;
	combo = 2*len*len*len - combo;
	fout<<combo<<endl;
	return 0;
}
	
