/*
 ID: wyuan171
 PROG: dualpal
 LANG: C++
 */
// 10/23/2014
#include <fstream>
#include <string>


using namespace std;

class Solution
{
    bool isPal(size_t num, const int &base)
    {
        if(base < 1)
            return false;
        string pal("");
        while(num)
        {
            pal.push_back(digits[num%base]);
            num /= base;
        }
        size_t size = pal.size();
        size_t mid = size/2;
        for(size_t i=0; i<mid; i++)
            if(pal[i] != pal[size-1-i])
                return false;
        return true;
    }
    bool isDualPal(size_t num)
    {
        int count = 0;
        for(int i=2; i<=10; i++)
        {
            if(isPal(num, i))
                count++;
            if(count == 2)
                break;
        }
        return count == 2;
    }
    
public:
    Solution(const char *finName, const char*foutName): fin(finName), fout(foutName),
    digits("0123456789ABCDEFGHJKLMNOPQRSTUVWXYZ"){};
    void main()
    {
        size_t N = 3;
        size_t S = 25;
        fin>> N >> S;
        
        while(N > 0)
        {
            S++;
            while(!isDualPal(S))
                S++;
            fout<<S<<endl;
            N--;
        }
        
        fin.close();
        fout.close();
    }
private:
    ifstream fin;
    ofstream fout;
    string digits;
};

int main()
{
    Solution sol("dualpal.in", "dualpal.out");
    sol.main();
    return 0;
}
