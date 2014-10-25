/*
 ID: wyuan171
 PROG: ariprog
 LANG: C++
 */

//#define DEBUG
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
    void main()
    {
        fin >> N >> M;
#ifdef DEBUG
        N = 5; M = 7;
#endif
        int size = 2*M*M + 1;
        vector<bool> bisquare(size, false);
        
        for(int p=0; p<=M; p++)
            for(int q=p; q<=M; q++)
                bisquare[p*p + q*q] = true;
        
        bool found = false;
        
        int maxLen = (size+1) / (N-1);
        for(int len=1; len < maxLen; len++)
        {
            for(int i=0; i < size; i++)
            {
                if(bisquare[i] && (i + len*(N-1) < size))
                {
                    
                    bool isCandi = true;
                    for(int count=1; count < N; count++)
                    {
                        if(!bisquare[i + len*count])
                        {
                            isCandi = false;
                            break;
                        }
                    }
                    if(isCandi)
                    {
                        found = true;
#ifndef DEBUG
                        fout << i << " " << len << endl;
#else
                        cout << i << " " << len << endl;
#endif
                        
                    }
                }
            }
        }
        
        if(!found)
            fout << "NONE"<<endl;
        
        //fout<<endl;
        fin.close();
        fout.close();
    }
private:
    ifstream fin;
    ofstream fout;
    int N, M;
};

int main()
{
    Solution sol("ariprog.in", "ariprog.out");
    sol.main();
    return 0;
}
