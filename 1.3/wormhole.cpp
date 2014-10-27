/*
 ID: wyuan171
 PROG: wormhole
 LANG: C++
 */
// 10/25/2014. Make pairs greedily first. (a, b) is the same with (b, a). Pick the first non-paired wormhole, then make pair with other successors. DFS is good for this.
// Eg. N=4. 1 --> (1,2)  --> (1,2) 3 --> (1,2), (3,4)
//          (1,3) (2,4)
//          (1,4), (2,3)
// When one pairing is made, check if there's a cycle.
// When a worm walks out of a wormhole, it will enter the closest wormhole on its right side along the X direction. Then it will walks out of another wormhole. If there's no wormhole on its right side, he will not be trapped.
// If it can be trapped, it will have a wormhole on its right after N walks.
#include <fstream>

using namespace std;

struct Point{
    int x;
    int y;
    Point(int ix=0, int iy=0): x(ix), y(iy){};
};

class Solution
{
    bool isTrapped()
    {
        for(int i=1; i<=N; i++)
        {
            int pos = i;
            // it walks out of wormholw i
            for(int j=0; j<N; j++)
            {
                pos = pair[ closestRight[pos]];
            }
            if(pos != 0)
                return true;
        }
        return false;
    }
    
    int solve()
    {
        int i; // find the first non-paired wormhole.
        for(i=1; i<=N; i++)
        {
            if(pair[i] == 0)
                break;
        }
        if( i > N)
        {
            // one pairing is made
            if(isTrapped())
                return 1;
            return 0;
        }
        int total = 0;
        for(int j=i+1; j<=N; j++)
        {
            if(pair[j] == 0)
            {
                pair[i] = j;
                pair[j] = i;
                
                total += solve();
                
                pair[i] = 0;
                pair[j] = 0;
            }
        }
        return total;
    }
    
public:
    Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
    void main()
    {
        fin >> N;
        
        closestRight[0] = 0;
        pair[0] = 0;
        
        for(int i=1; i<=N; i++)
        {
            fin >> points[i].x >> points[i].y;
            closestRight[i] = 0;
            pair[i] = 0;
        }
        
        for(int i=1; i<=N; i++)
            for (int j=1; j<=N; j++) {
                if(points[j].x > points[i].x && points[i].y == points[j].y) // j is on i's right
                {
                    if(closestRight[i] == 0 // has no right before
                       || points[j].x < points[closestRight[i]].x) // need update
                        closestRight[i] = j;
                }
            }
        fout << solve() << endl;
        fin.close();
        fout.close();
    }
private:
    ifstream fin;
    ofstream fout;
    
    Point points[13];
    int closestRight[13];
    int pair[13]; // pair[i] == j && pair[j] == i if (i,j) is one pair.
    int N;
};

int main()
{
    Solution sol("wormhole.in", "wormhole.out");
    sol.main();
    return 0;
}
