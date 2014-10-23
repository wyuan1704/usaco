/*
 ID: wyuan171
 PROG: palsquare
 LANG: C++
 */
// 10/23/2014
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
    // key here.
    bool isPal(int num, string &pal, const int &base)
    {
        if(base < 1)
            return false;
        pal.clear();
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
    string convert(int num, const int &base)
    {
        string res("");
        while(num)
        {
            res.push_back(digits[num%base]);
            num /= base;
        }
        reverse(res.begin(), res.end());
        return res;
    }
public:
    Solution(const char *finName, const char*foutName): fin(finName), fout(foutName),
    digits("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ") // Key
    {};
    void main()
    {
        int base = 2;
        fin>>base;
        string pal("");
        
        for (int i=1; i<=300; i++) {
            int squre = i*i;
            if(isPal(squre, pal, base))
                fout<< convert(i, base) << " " <<pal<<endl;
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
    Solution sol("palsquare.in", "palsquare.out");
    sol.main();
    return 0;
}
