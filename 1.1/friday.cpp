/*
 ID: wyuan171
 PROG: friday
 LANG: C++
 */

// wyuan on 10/22/2014. Last year, I saw a formular for a given date. Do you know it now?

#include <fstream>
using namespace std;

bool isLeap(int year)
{
    if(year%100 == 0)
    {
        return year%400 == 0;
    }
    else
        return year%4 == 0;
}

int main(){
    ifstream fin("friday.in");
    int N;
    fin>>N;
    fin.close();
    int month[2][12] =
    {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    };
    int res[7] = {0};
    int cur = 5; // 6-1 Saturday.
    for(int i=1900; i < 1900+N; i++)
    {
        bool isLeapYear = isLeap(i);
        for(int m=0; m<12; m++)
        {
            res[cur]++;
            cur += month[isLeapYear][m];
            cur %= 7;
        }
    }
    
    ofstream fout("friday.out");
    fout<<res[5];
    // Satruday, Sunday, ..., Friday
    for(int i=0; i<6; i++)
        fout<< " " << res[(i+6)%7];
    fout<<endl;
    fout.close();
    
    return 0;
}

