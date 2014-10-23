/*
ID: wyuan171
PROG: transform
LANG: C++
*/
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Solution
{
private:
bool isSame(const vector<vector<bool> > & b1, const vector<vector<bool> > & b2)
{
	// check size? Omit
	for(int r=0; r<N; r++)
		for(int c=0; c<N; c++)
			if(b1[r][c] != b2[r][c])
				return false;
	return true;
}

/*
x1=cos(angle)*x-sin(angle)*y;

y1=cos(angle)*y+sin(angle)*x;
so
(x, y) -> (-y, x) if angle is 90 (counter-clockwise).
        (y, -x) if angle is -90
        (-x, -y) if angle is 180

x, -> (x - mid) -> (2mid - x) == N-x
*/
void rotate90Degree(vector<vector<bool> > &b) // clockwise
{
	double mid = N / 2.0;
	for(int x=0; x<mid; x++)
		for(int y=0; y<=mid; y++)
		{
			int temp = b[x][y];
			b[x][y] = b[N-1-y][x];
			b[N-1-y][x] = b[N-1-x][N-1-y];
			b[N-1-x][N-1-y] = b[y][N-1-x];
			b[y][N-1-x] = temp;
		}
}

void reflect(vector<vector<bool> > &b)
{
	double mid = N / 2.0;
	for(int x=0; x<N; x++)
		for(int y=0; y<mid; y++)
		{
			int temp = b[x][y];
			b[x][y] = b[x][N-1-y];
			b[x][N-1-y] = temp;
		}
}
	
public:
	Solution(const char *finName, const char*foutName): fin(finName), fout(foutName){};
	void main()
	{	
		fin >> N;
		vector<vector<bool> > oriBoard(N, vector<bool>(N));
		vector<vector<bool> > newBoard(N, vector<bool>(N));
		string line;
		for(int r=0; r<N; r++)
		{
			fin >> line;
			for(int c=0; c<N; c++)
			{
				oriBoard[r][c] = (line[c] == '@');
			}
		}
		
		for(int r=0; r<N; r++)
		{
			fin >> line;
			for(int c=0; c<N; c++)
			{
				newBoard[r][c] = (line[c] == '@');
			}
		}
		fin.close();
		
		int res = 0;
		vector<vector<bool> > oriBoardCopy(oriBoard);
		// #1 ~#3
		for(int i=1; i<4; i++)
		{
			rotate90Degree(oriBoardCopy);
			if(isSame(oriBoardCopy, newBoard))
			{
				fout<< i << endl;
				return;
			}
		}
		// #4 #5
		oriBoardCopy = oriBoard;
		reflect(oriBoardCopy);
		if(isSame(oriBoardCopy, newBoard))
		{
			fout<< 4 << endl;
				return;
				}
		for(int i=1; i<4; i++)
		{
			rotate90Degree(oriBoardCopy);
			if(isSame(oriBoardCopy, newBoard))
			{
				fout<< 5 << endl;
				return;
			}
		}
		
		// #6
		if(isSame(oriBoard, newBoard))
		{
			fout<< 6 << endl;
				return;
		}
		
		fout<< 7 << endl;
		fout.close();
	}
private:
	ifstream fin;
	ofstream fout;
	int N; // size N * N
};

int main()
{
	Solution sol("transform.in", "transform.out");
	sol.main();
	return 0;
}
