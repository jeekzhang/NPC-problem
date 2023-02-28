#include <iostream>
#include<fstream>
#include <stdlib.h>
#include <time.h> 
using namespace std;

int main()
{
	int n;
	cin>>n;
	float a[105][105];
	srand((unsigned)time(NULL)); 
	
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){
			if(i==j)a[i][j]=0;
			else {
				a[i][j]=a[j][i]=(double)(rand() % 10) / 10;
			}
		}
		
	ofstream fout( "matrix.txt" );	
   	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fout<<a[i][j]<<" ";
		} 
		fout<<endl;
	}

    return 0;
}
