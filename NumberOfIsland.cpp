#include<iostream>
#include<vector>
using namespace std;

void moveHorizonatallyAndVertically(vector<vector<int>>& a, int m ,int n, int i , int j) {
	if((i < m && i >= 0) && (j < n && j >= 0))   {
		if(a[i][j] ==1){
			a[i][j] = 0;
			moveHorizonatallyAndVertically(a, m ,n , i+1, j);
			moveHorizonatallyAndVertically(a, m ,n , i, j+1);
			moveHorizonatallyAndVertically(a, m ,n , i, j-1);
			moveHorizonatallyAndVertically(a, m ,n , i-1, j);
			moveHorizonatallyAndVertically(a, m ,n , i-1, j);
			moveHorizonatallyAndVertically(a, m ,n , i-1, j-1);
			moveHorizonatallyAndVertically(a, m ,n , i+1, j+1);
		}
}
	return;

}

void display(vector<vector<int>>& a, int m ,int n) {
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++ ){

			cout<< a[i][j];
		}
		cout<<endl;
	}
}


int findNumberOfIsland(vector<vector<int>>& a, int m ,int n) {
	
	int count =0;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++ ){

			if(a[i][j] == 1) {
				count++;
				moveHorizonatallyAndVertically(a, m ,n , i, j);
			}

			//display(a,m,n);

		}
	}
	return count;
}

int main() {
	
	 int M[][5]= { 
	    {1, 1, 0, 0, 0}, 
        {0, 1, 0, 0, 1}, 
        {1, 0, 0, 1, 1}, 
        {0, 0, 0, 0, 0}, 
        {1, 0, 1, 0, 1} 
    }; 

    vector<vector<int>> a(5,vector<int>(5));

      a[0] = {1, 1, 0, 0, 0};
      a[1] = {0, 1, 0, 0, 1};
      a[2] = {1, 0, 0, 1, 1};
      a[3] = {0, 1, 0, 0, 0};
      a[4] = {1, 0, 1, 1, 1} ;



    cout << findNumberOfIsland(a,5,5);
}