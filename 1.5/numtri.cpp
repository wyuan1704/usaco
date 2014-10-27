/*
 ID: wyuan171
 PROG: numtri
 LANG: C++
 */

#include <fstream>

using namespace std;

// 10/25/2014; Dynamic programming.
class Solution
{
public:
    Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
    void main()
    {
        int N;
        fin >> N;
        int rows[2][1001] = {0};
        
        int cur = 1;
        int old = 0;
        for(int line = 1; line <=N; line++)
        {
            cur ^= 1; // Key here. Swap cur and old. Don't really swap their values.
            old ^= 1;
            for(int i=1; i<= line; i++)
            {
                int temp;
                fin >> temp;
                rows[cur][i] = max(rows[old][i-1], rows[old][i]) + temp;
            }
        }
        int max = 0;
        for(int i=1; i<=N; i++)
        {
            if(rows[cur][i] > max)
                max = rows[cur][i];
        }
        fout << max;
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
    Solution sol("numtri.in", "numtri.out");
    sol.main();
    return 0;
}
