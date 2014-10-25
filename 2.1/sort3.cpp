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
        int posCount[4][4] = {0}; // posCount[i][j] is the count of j in the i position.
        for(int i=0; i<counts[1]; i++)
        {
            posCount[1][vals[i]] ++;
            if(vals[i] != 1)
                wrongPosCount++;
        }
        
        for(int i=counts[1]; i<counts[2]; i++)
        {
            posCount[2][vals[i]] ++;
            if(vals[i] != 2)
                wrongPosCount++;
        }

        
        for(int i=counts[2]; i<counts[3]; i++)
        {
            posCount[3][vals[i]] ++;
            if(vals[i] != 3)
                wrongPosCount++;
        }
        
        // These are two types of swaps.
        // 1) direct swaps -- 1,2    1, 3   2,3  Two wrong position and 1 swap.
        // 2) cyclic swaps -- 2,3,1 or 3,1,2   Three wrong positions and 2 swaps.
        // swap
        int directSwapCounts =
          min(posCount[1][2], posCount[2][1])
        + min(posCount[1][3], posCount[3][1])
        + min(posCount[2][3], posCount[3][2]);
        
        
        fout << directSwapCounts + (wrongPosCount-2*directSwapCounts)*2/3 << endl;
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
