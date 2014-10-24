/*
 ID: wyuan171
 PROG: crypt1
 LANG: C++
 */

#include <fstream>
#include <vector>
using namespace std;

class Solution
{
    bool isValid(int num, vector<bool> &map, int width)
    {
        while(width > 0)
        {
            if(!map[num % 10])
                return false;
            num /= 10;
            width--;
        }
        if(num !=0)
            return false;
        return true;
    }
public:
    Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
    void main()
    {
        // wyuan; 10/24/2014; Small data set. Brutal force is OK.
        int N=0;
        fin >> N;
        vector<bool> map(20, false);  // is 10 enough?
        int digits[N];
        for(int i=0; i<N; i++)
        {
            fin >> digits[i];
            map[digits[i]] = true;
        }
        
        // a  b  c
        // *  d  e
        int n3 = N*N*N;
        int count = 0;
        for(int i=0; i<n3; i++)
        {
            int abc = digits[i/(N*N)] * 100 + digits[(i/N)%N] * 10 + digits[i%N];
            for(int d=0; d<N; d++)
                for(int e=0; e<N; e++)
                {
                    int par1 = abc * digits[e];
                    int par2 = abc * digits[d];
                    if(isValid(par1, map, 3)
                       && isValid(par2, map, 3)
                       && isValid(par1 + 10*par2, map, 4))
                        count ++;
                }
        }
        
        
        fout<< count <<endl;
        fin.close();
        fout.close();
    }
private:
    ifstream fin;
    ofstream fout;
};

int main()
{
    Solution sol("crypt1.in", "crypt1.out");
    sol.main();
    return 0;
}
