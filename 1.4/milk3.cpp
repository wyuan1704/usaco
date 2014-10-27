/*
 ID: wyuan171
 PROG: milk3
 LANG: C++
 */

#include <fstream>

using namespace std;

// 10/25/2015. Use visited[i][j] to store the state of (a, b). Print out C - visited[0][j]
class Solution
{
    int min(int a, int b)
    {
        return a < b? a:b;
    }
    void dfs(bool visited[21][21], const int a, const int b, const int c)
    {
        if(visited[a][b])
            return;
        visited[a][b] = true;
        int ta, tb, tc;
        if(a > 0)
        {
            // a -> b
            tb = min(a+b, capB);
            ta = capC - tb - c;
            tc = c;
            dfs(visited, ta, tb, tc);
            // a -> c
            tc = a+c;
            tb = b;
            ta = 0;
            dfs(visited, ta, tb, tc);
        }
        if(b > 0)
        {
            // b -> a
            ta = min(a+b, capA);
            tb = capC - ta - c;
            tc = c;
            dfs(visited, ta, tb, tc);
            // b -> c
            tc = b+c;
            tb = 0;
            ta = a;
            dfs(visited, ta, tb, tc);
        }
        if(c > 0)
        {
            // c -> a
            ta = min(c+a, capA);
            tb = b;
            tc = capC - ta - tb;
            dfs(visited, ta, tb, tc);
            // c -> b
            tb = min(c+b, capB);
            ta = a;
            tc = capC - ta - tb;
            dfs(visited, ta, tb, tc);
        }
    }
public:
    Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
    void main()
    {
        fin >> capA >> capB >> capC;
        //capA = 8; capB = 9; capC = 10;
        bool visited[21][21] = {false};
        
        dfs(visited, 0, 0, capC);
        
        for(int j=20; j>0; j--)
        {
            if(visited[0][j])
                fout << capC - j << " ";
        }
        fout<<capC;
        fout<<endl;
        fin.close();
        fout.close();
    }
private:
    ifstream fin;
    ofstream fout;
    int capA, capB, capC;
};

int main()
{
    Solution sol("milk3.in", "milk3.out");
    sol.main();
    return 0;
}
