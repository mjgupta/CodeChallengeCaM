#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define lli long long int
vector <long long int> resultantArrayX;
vector <long long int> resultantArrayY;
long long int tolerance=100;
//Steps involved for canny's edge detection includes:
//1. Noise Reduction
//2.Intensity Gradient of the Image Matrix
//3.Non Maximum Supression
//4. Hysterisis Thresholding 
// For the time being we pass a matrix to the function
// function given earlier takes in the image grayscale intensity values

//vector<vector<bool> >edgeDetectedMatrix;
/*
bool checkIfEdgeFound(vector<vector<bool> > mat, long long int x, long long int y)
{
	//cout<<"checkdone"<<endl;
    if(x<0 || x>=mat.size() || y<0 || y>=mat.size()) return 0;
    else if (mat[x][y]==0) return 0;
    
        resultantArrayX.push_back(x);
        resultantArrayY.push_back(y);
    return 1;
}*/
//function given here would take the detected edge output by opencv library canny edge detection function
//function utilizes matrix based approach
/*

int snapToNearestEdgePartB(vector<vector<bool> > edgeDetectedMatrix, long long int a, long long int b)
{
    long long int x =a;
    long long int y=b;
    for(long long int span=0;span<tolerance;span+=1)
    {   
        while(resultantArrayY.empty() && resultantArrayX.empty())
        {
        for(long long int j=span; j>=-1*span || resultantArrayX.empty();j--)
            {
                if((checkIfEdgeFound(edgeDetectedMatrix, x-span, y-j)+checkIfEdgeFound(edgeDetectedMatrix, x-j, y+span)+checkIfEdgeFound(edgeDetectedMatrix, x+span , y+j)+checkIfEdgeFound(edgeDetectedMatrix, x+j, y-span )) >0) break;
                else continue;
            }
        }
    }
}
*/

//function utilizes breadth first search based approach
/*bool inbound(vector<vector<bool> > edgeDetectedMatrix, long long int a , long long int b )
{
    if(a<0 || b<0 || a>=edgeDetectedMatrix.size() || b>=edgeDetectedMatrix.size() ) return 0;
    else return 1;
}
pair<ll, ll> snapToNearestEdgeB(vector<vector<bool> > edgeDetectedMatrix, long long int a , long long int b)
{
    long long int x =a;
    long long int y=b;   
    queue<pair<pair<long long, long long>, long long> > q;
    bool vis[edgeDetectedMatrix.size()][edgeDetectedMatrix.size()];
    memset(vis, 0, sizeof vis);
    q.push(make_pair(make_pair(x, y), 0));
    while(!q.empty()){
        pair<ll, ll> p = q.front().first;
        long long dis = q.front().second;
        vis[p.first][p.second] = 1;
        q.pop();
        if(edgeDetectedMatrix[p.first][p.second] == 1){
            return p;
        }
        if(inbound(edgeDetectedMatrix,x+1, y) && vis[x+1][y] == 0 && dis+1 <= tolerance){
            q.push(mp(mp(x+1, y), dis+1));
        }
        if(inbound(edgeDetectedMatrix,x-1, y) && vis[x-1][y] == 0 && dis+1 <= tolerance){
            q.push(mp(mp(x+1, y), dis+1));
        }
        if(inbound(edgeDetectedMatrix,x, y+1) && vis[x][y+1] == 0 && dis+1 <= tolerance){
            q.push(mp(mp(x+1, y), dis+1));
        }
        if(inbound(edgeDetectedMatrix,x, y-1) && vis[x][y-1] == 0 && dis+1 <= tolerance){
            q.push(mp(mp(x+1, y), dis+1));
        }
    }

}*/

vector<pair<lli,lli> > ans;
void snap(vector<vector<lli> > v, lli x,lli y)
{
	lli threshold = 5000; 
	lli n = v.size();
	lli m = v[0].size(),dist = 100000000000;
	v[x][y]=6;
	for(lli i=0;i<min(threshold,n);i++)
	{
		for(lli j=0;j<min(threshold,m);j++)
		{
			if(v[i][j] == 1)
			{
				dist = min(dist , abs(i-x)+abs(j-y));
			}
		}
	}
	for(lli i=0;i<min(threshold,n);i++)
	{
		for(lli j=0;j<min(threshold,m);j++)
		{
			if(v[i][j] == 1)
			{
				lli distn = abs(i-x)+abs(j-y);
				
				if(distn == dist) {
				ans.push_back(make_pair(i,j));
				v[i][j] = 9;
				//cout<<i<<" "<<j<<endl;
				}
				
			}
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	vector<vector<lli> > edgeDetectedMatrix; long long int r,a,b;
	cout<<"Input no of rows of the square matrix"<<endl;
	cin>>r;
	cout<<"Input matrix values"<<endl;
	for(int i=0;i<r;i++)
	{
		vector<lli> temp;
		for(int j=0;j<r;j++)
		{
			long long int x;
			cin>>x;
			temp.push_back(x);
		}
		edgeDetectedMatrix.push_back(temp);
		cout<<endl;
	}
	
	for (;;)
	{
	cout<<"Enter coordinates"; cin>>a>>b;
		snap(edgeDetectedMatrix,a,b);
		for(int m=0;m<ans.size();m++)
		{	cout<<"Nearest Coordinates: "<<endl;
			cout<<ans[m].first<<" "<<ans[m].second<<endl;
		}
	}
}

