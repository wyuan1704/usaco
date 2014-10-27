/*
 ID: wyuan171
 PROG: zerosum
 LANG: C++
 */

#include <fstream>

using namespace std;

class Solution
{
    int sign(int i)
    {
        if(i > 0) return 1;
        if(i < 0) return -1;
        return 0;
    }
    
    void dfs(int sum,int last,int cur, string res)
    {
        if(cur == N+1)
        {
            if(sum == 0)
                fout << res <<endl;
            return;
        }
        char curChar = cur + '0';
        
        // Key here.
        dfs(sum + (last*9 + sign(last) * cur), // Not 10, but 9, because, last is added to sum in upper layer.
            last*10 + sign(last) * cur, cur+1,  res + " " + curChar);
        
        dfs(sum + cur,  cur, cur + 1, res + "+" + curChar);
        dfs(sum - cur, -cur, cur + 1, res + "-" + curChar);
    }
    
public:
    Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
    void main()
    {
        fin >> N;
        // 10/27/2014; This is very like 2.2/subset.
        dfs(1, 1, 2, "1");
        
        fin.close();
        fout.close();
    }
private:
    ifstream fin;
    ofstream fout;
    int N;
};

int main()
{
    Solution sol("zerosum.in", "zerosum.out");
    sol.main();
    return 0;
}
