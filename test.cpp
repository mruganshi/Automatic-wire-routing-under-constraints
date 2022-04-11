#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
using namespace std;
const int N=301;
const int M=301;
class QItem {
public:
	int row;
	int col;
	int dist;
	QItem(int x, int y, int w)
		: row(x), col(y), dist(w)
	{
	}
};
int grid[N][M];
int minDistance()
{
	QItem source(0, 0, 0);
	bool visited[N][M];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == 3)
				visited[i][j] = true;
			else
				visited[i][j] = false;


			if (grid[i][j] == 1000)
			{
			source.row = i;
			source.col = j;
			}
		}
	}

	// applying DFS on matrix cells starting from source
	/*
	used stack instead of queue because in initial there will be many pathwith same minimum length and we want only one path which we used at first and that can be found by stack .
	*/
	stack<QItem> q;      // here we can use both stack and queue because it tracks only row and column indices.
    stack<QItem> path;   //keep track at which distance is changing
	q.push(source);      //source will be first visited
	visited[source.row][source.col] = true;
	int output=-1;
	while (!q.empty()) {
		QItem p = q.top();
        path.push(q.top());
        q.pop();

		// moving up
		//if we can go one step up to find minimum path

		if (p.row - 1 >= 0 && visited[p.row - 1][p.col] == false) {
			q.push(QItem(p.row - 1, p.col, p.dist + 1));
			visited[p.row - 1][p.col] = true;
			if (grid[p.row-1][p.col] == 3000){
            	while(!path.empty()){
                	QItem x=path.top();
                	grid[x.row][x.col]++;
                	path.pop();
            	}
            	output=p.dist;
            	break;
        	}
		}

		// moving left
		//if we can go one step left to find min path

		if (p.col - 1 >= 0 && visited[p.row][p.col - 1] == false) {
			q.push(QItem(p.row, p.col - 1, p.dist + 1));
			visited[p.row][p.col - 1] = true;
			if (grid[p.row][p.col-1] == 3000){
            	while(!path.empty()){
                	QItem x=path.top();
                	grid[x.row][x.col]++;
                	path.pop();
            	}
            	output=p.dist;
            	break;
            	return p.dist;
			}
		}


		// moving down
		//if we can go one step down to find minimum path

		if (p.row + 1 < N && visited[p.row + 1][p.col] == false) {
			q.push(QItem(p.row + 1, p.col, p.dist + 1));
			visited[p.row + 1][p.col] = true;
			if (grid[p.row+1][p.col] == 3000){
            	while(!path.empty()){
                	QItem x=path.top();
                	grid[x.row][x.col]++;
                	path.pop();
            	}
            	output=p.dist;
            	break;
            	return p.dist;
			}
		}


		// moving right
		//if we can go one step right to find minimum path

		if (p.col + 1 < M && visited[p.row][p.col + 1] == false) {
			q.push(QItem(p.row, p.col + 1, p.dist + 1));
			visited[p.row][p.col + 1] = true;
			if (grid[p.row][p.col+1] == 3000){
            	while(!path.empty()){
                	QItem x=path.top();
                	grid[x.row][x.col]++;
                	path.pop();
            	}
            	output=p.dist;
            	break;
            	return p.dist;
        	}
		}		
	}


	if(output!=-1){ 
        return output+1;
    } 
	else{
		return -1;
	} 
}
int ans=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("1st32.txt", "r", stdin);
    int a, b;
	int n=32;
    while(n--){
		cin>>a>>b;    
    	a=a/2000;
    	b=b/2000;
		if(n==31){
			for(int i=0;i<N;i++){
    			for(int j=0;j<M;j++){
      				if(i==a && j==b){
        				grid[i][j]=1000;
      				}
      				else if(i==300 && j==300){
        				grid[i][j]=3000;
      				}
      				else{
        				grid[i][j]=0;
      				}
    			}
  			}
		}
		else{
			for(int i=0;i<N;i++){
    			for(int j=0;j<M;j++){
					if(grid[i][j]==1001){
						grid[i][j]=1;
					}
      				if(i==a && j==b){
        				grid[i][j]=1000;
      				}     				
    			}
  			}
		}  
		int x= minDistance();     
		cout << x <<endl;
		if(x!=-1){
			ans+=x;
		}
	}
	cout<<"Total wire length under the congestion limit considered as 3 is "<< ans<< endl;
	return 0;
}
