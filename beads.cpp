/*
 ID: wyuan171
 PROG: beads
 LANG: C++
 */

// wyuan on 10/23/14. From one breaking point, we should count two ways. When we get one end, we should cross a virtual line to the other end, which is a little hard to code. Let's connect two copies of the beads, then we don't have to go outside. If the count is larger than the origial size, just print the original size.

#include <fstream>
#include <assert.h>
using namespace std;


int main(){
    ifstream fin("beads.in");
    int N;
    string beads;
    //string beads("wwwbbrwrbrbrrbrbrwrwwrbwrwrrb");
    // N= 29;
    fin>> N >> beads;
    assert(N == beads.size());
    fin.close();
    
    string ss(beads);
    ss += beads;
    int size2 = 2*N;
    int max = -1;
    
    for(int i=0; i<size2-1; i++)
    {
        char cur = ss[i];
        if(cur == 'w') // Don't break at the white bead
            continue;
        // go down
        int downEnd = i-1;
        while(downEnd >= 0 && (ss[downEnd] == cur || ss[downEnd] == 'w'))
        {
            downEnd--;
        }
        
        // go up
        int upEnd = i+1;
        while(upEnd < size2 && ss[upEnd] == 'w')
            upEnd++;
        cur = ss[upEnd];
        upEnd++;
        while(upEnd < size2 && (ss[upEnd] == cur || ss[upEnd] == 'w'))
        {
            upEnd++;
        }
       
        if(upEnd - downEnd - 1 > max)
            max = upEnd - downEnd - 1;
    }
    
    // We may ignore these two cases.
    if(max == -1 // all 'w'
    || max > N)
        max = N;
    ofstream fout("beads.out");
    fout<< max;
    
    fout<<endl;
    fout.close();
    
    return 0;
}

