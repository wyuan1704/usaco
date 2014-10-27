/*
ID: wyuan171
PROG: milk
LANG: C++
*/
// A typical Greedy problem
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Farmer{
	int milk;
	int price;
	Farmer(int im=0, int ip=0): milk(im), price(ip){};
};

int comp(const Farmer &a, const Farmer &b)
{
	return a.price < b.price;
}

class Solution
{
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{
		// buy from the lowest price until meet Makers' daily requirement
		int N, M;
		fin >> N >> M;
		vector<Farmer> farmers;
		int milk, price;
		for(int i=0; i<M; i++)
		{
			fin >> price >> milk;
			farmers.push_back(Farmer(milk, price));
		}
		sort(farmers.begin(), farmers.end(), comp);
		int totalCost = 0;
		for(int i=0; i < M && N>0; i++)
		{
			if(farmers[i].milk > N)
			{
				totalCost += farmers[i].price * N;
				break;
			}
			else
			{
				totalCost += farmers[i].price * farmers[i].milk;
				N -= farmers[i].milk;
			}
		}
		fout << totalCost;
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
	Solution sol("milk.in", "milk.out");
	sol.main();
	return 0;
}
