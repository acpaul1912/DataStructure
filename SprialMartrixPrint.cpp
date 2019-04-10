#include<iostream>
#include<vector>

using namespace std;


void printSprialMatrix(vector<vector<int>> &vec) {

	int m = vec.size();

	if(m  == 0) return ;
	int n = vec[0].size();

    int k=0 , l = 0 ;
	while(k < m && l <n) {

		 for(int p = k; p< n ; p++) {
		 	cout<<vec[k][p];
		 }

		 k++;
		 for(int q = k; q < m ; q++) {

		 	cout<< vec[q][n-1];
		 }

		 n--;

		 if(k < m) {

		 	for(int p = n-1; p >= l; p-- ){

		 		cout<<vec[m-1][p];
		 	}		 	
		 	m--;
		 }
		 if(l<n) {

		 	for(int p = m-1; p>= k; p-- ){

		 		cout<<vec[p][l];
		 	}
		 	l++;
		 }
	}
    
        

}

int main() {

	vector< vector<int> >  vec (3, vector<int>(3));
    int k;
	for(int i = 0; i < 3; i ++)
	for(int j = 0; j < 3 ; j++){

		vec[i][j]= k++;

	} 

	printSprialMatrix(vec);


}