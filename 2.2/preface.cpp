/*
 ID: wyuan171
 PROG: preface
 LANG: C++
 */

// 10/26/2014; Roman integers seem 5-based.
// For [1~9] * 10^x, preCounts are the same while Roman symbols are different.
// For [1~9], we need IVX. For 10~90, we need XLC. For 100~900, we need CDM.
#include <fstream>

using namespace std;

class Solution
{
    void countRoman(int num, int res[], int preCount[10][10])
    {
        int pos = 0;
        while(num > 0)
        {
            int last = num % 10;
            for(int i=0; i<7; i++)
                res[i + pos*2] += preCount[last][i];
            num /= 10;
            pos++;
        }
    }
    
public:
    Solution(const char *finName, const char*foutName): fin(finName), fout(foutName),
    roman("IVXLCDM"){};
    void main()
    {
        int res[7] = {0}; // res[i] is the count of roman[i]
        int preCounts[10][10] =
        {
            {0},    //0
            {1},
            {2},
            {3},
            {1, 1}, //4
            {0, 1}, //5
            {1, 1},
            {2, 1},
            {3, 1},
            {1, 0, 1} //9
        };
        
        int N;
        fin >> N;
        //N = 7;
        for(int i=1; i<=N; i++)
            countRoman(i, res, preCounts);
        
        for(int i=0; i<7; i++)
        {
            if(res[i] != 0)
                fout << roman[i] << " " <<  res[i] << endl;
        }
        
        fin.close();
        fout.close();
    }
private:
    ifstream fin;
    ofstream fout;
    string roman;
};

int main()
{
    Solution sol("preface.in", "preface.out");
    sol.main();
    return 0;
}


