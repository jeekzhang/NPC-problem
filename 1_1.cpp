//m=2
#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
	float a[105][105];
	cin>>n;
	int p;
	float min=4;
	vector<int>x,y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }

	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(a[i][j]<=min){
				if(a[i][j]<min){
				min=a[i][j];
				x.clear();
				y.clear();
			}
				x.push_back(i);
				y.push_back(j);
			}
		}
		
	cout<<"����������:"<<min<<endl;
	for(int i=0;i<x.size();i++){
	cout<<"�������õ����ֲ��ǵ�"<<x[i]<<"�ֺ͵�"<<y[i]<<"��"<<endl;
}
	return 0; 
}
