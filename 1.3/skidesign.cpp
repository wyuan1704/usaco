/*
 ID: wyuan171
 PROG: skidesign
 LANG: C++
 */
// 10/25/2014; N and elevations are small. Brutal force. Suppose the ideal range is [low, high], where low is in [lowest, highest-17]. Find the minimum cost of each range.
// If N and elevations are very large, what should we do?
#include <fstream>
#include <vector>

using namespace std;

class Solution
{
    int cost(int low, int high)
    {
        int res = 0;
        int diff = 0;
        for(int i=0; i<N; i++)
        {
            diff = 0;
            if(hights[i] > high)
                diff = (hights[i] - high);
            else if(hights[i] < low)
                diff = low - hights[i];
            res += diff * diff;
        }
        return res;
    }
public:
    Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
    void main()
    {
        fin >> N;
        int lowest = 101;
        int highest = -1;
        for(int i=0; i<N; i++)
        {
            int hight;
            fin >> hight;
            hights.push_back(hight);
            if(hight < lowest)
                lowest = hight;
            if(hight > highest)
                highest = hight;
        }
        
        int minCost = cost(lowest, lowest+17);
        for(int low = lowest+1; low <= highest-17; low++)
        {
            int newCost = cost(low, low+17);
            if(newCost < minCost)
                minCost = newCost;
        }
        fout << minCost;
        fout<<endl;
        fin.close();
        fout.close();
    }
private:
    ifstream fin;
    ofstream fout;
    int N;
    vector<int> hights;
};

int main()
{
    Solution sol("skidesign.in", "skidesign.out");
    sol.main();
    return 0;
}
