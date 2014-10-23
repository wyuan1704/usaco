/*
 ID: wyuan171
 PROG: namenum
 LANG: C++11
 */
// 10/23/2014; There are only one number and many dictionary words. Instead of using a dictionary, we can if check every word's number is the given number.
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    Solution(const char *finName, const char*foutName): fin(finName), fout(foutName)
    {
        
    };
    void main()
    {
        char map[256] = {0};
        map['A'] = map['B'] = map['C'] = '2';
        map['D'] = map['E'] = map['F'] = '3';
        map['G'] = map['H'] = map['I'] = '4';
        map['J'] = map['K'] = map['L'] = '5';
        map['M'] = map['N'] = map['O'] = '6';
        map['P'] = map['R'] = map['S'] = '7';
        map['T'] = map['U'] = map['V'] = '8';
        map['W'] = map['X'] = map['Y'] = '9';
        
        string digits ;
        fin >> digits;
        
        int size = digits.size();
        
        ifstream fdict("dict.txt");
        string word;
        fdict>>word;
        size_t count = 0;
        // To save some memory.
        while (fdict.good()) {
            if(word.size() == size)
            {
                bool found = true;
                for(size_t i=0; i<size; i++)
                {
                    if(digits[i] != map[word[i]])
                    {
                        found = false;
                        break;
                    }
                }
                if(found)
                {
                    count++;
                    fout<< word<<endl;
                }
            }
            fdict>>word;
        }
        fdict.close();
        
        if(count == 0)
            fout<<"NONE"<<endl;
        
        fin.close();
        fout.close();
    }
private:
    ifstream fin;
    ofstream fout;
};

int main()
{
    Solution sol("namenum.in", "namenum.out");
    sol.main();
    return 0;
}
