#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>>& a, vector<vector<int>>& vis,int i ,int j) {
  
  return (i< 5 && i >= 0 && j < 5 && j >= 0 && a[i][j] && !vis[i][j]);
}

void DFS(vector<vector<int>>& a,vector<vector<int>>& vis ,int i , int j, int& numberofelement) {
	
	static int row[] = { 0,0,-1,1};
	static int col[] = { -1, 1, 0,0};
	vis[i][j] = 1;
	numberofelement++;
	for(int k = 0; k < 8 ; k++){
		if(isSafe(a,vis, i+ row[k], j + col[k]))
			DFS(a,vis, i+ row[k], j + col[k], numberofelement);
	}

}




int findNumberOfIsland(vector<vector<int>>& a, int m ,int n) {
	
	int count =0;int numberofelement = 0;
	vector<vector<int>> vis (m,vector<int>(n,0));

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++ ){
			if(a[i][j] && !vis[i][j]) {				
				DFS(a,vis, i, j,numberofelement);
				cout<< "Number of element is " << numberofelement <<endl;
				numberofelement = 0;
				count++;
			}
		}
	}
	return count;
}

int main() {
	
    vector<vector<int>> a(5,vector<int>(5));

      a[0] = {1, 1, 0, 0, 0};
      a[1] = {0, 1, 0, 0, 1};
      a[2] = {1, 0, 0, 1, 1};
      a[3] = {1, 1, 0, 0, 0};
      a[4] = {1, 1, 1, 1, 1} ;



    int i =  findNumberOfIsland(a,5,5);
    cout <<  "total island is : "  << i;
}