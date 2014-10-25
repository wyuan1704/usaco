/*
 ID: wyuan171
 PROG: sort3
 LANG: C++
 */

#include <fstream>

using namespace std;

class Solution
{
public:
    Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
    void main()
    {
        // 10/25/2014; This problem is explained in the official introduction of Greedy Algorithm.
        // We don't have to sort them. Just count them, find the number of those that are not in the right place. Divide the (number+1) by 2.
        int N;
        int vals[1001] = {0};
        int counts[4] = {0};
        fin >> N;
        for(int i=0; i<N; i++)
        {
            int cur;
            fin >> cur;
            vals[i] = cur;
            switch(cur)
            {
                case 1:
                    counts[1] ++;
                case 2:
                    counts[2] ++;
                case 3:
                    counts[3] ++;
                    break;
                default:
                    break;
            }
        }
        int wrongPosCount = 0;
        for(int i=0; i<counts[1]; i++)
            if(vals[i] != 1)
                wrongPosCount++;
        
        for(int i=counts[1]; i<counts[2]; i++)
            if(vals[i] != 2)
                wrongPosCount++;
        
        for(int i=counts[2]; i<counts[3]; i++)
            if(vals[i] != 3)
                wrongPosCount++;
        
        
        fout << (wrongPosCount+1)/2 << endl;
        fin.close();
        fout.close();
    }
private:
    ifstream fin;
    ofstream fout;
};

int main()
{
    Solution sol("sort3.in", "sort3.out");
    sol.main();
    return 0;
}
