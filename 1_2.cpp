//m=2
#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
	float a[105][105];
	cin>>n;
	int p;
	float min=9;
	vector<int>x,y,z;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }

	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++){
			float p=a[j][k]+a[i][j]+a[i][k];
			if(p<=min){
				if(p<min){
				min=p;
				x.clear();
				y.clear();
				z.clear();
			}
				x.push_back(i);
				y.push_back(j);
				z.push_back(k);
			}
		}

	cout<<"����������:"<<min<<endl;
	for(int i=0;i<x.size();i++){
	cout<<"�������õ����ֲ��ǵ�"<<x[i]<<"�֡���"<<y[i]<<"�ֺ͵�"<<z[i]<<"��"<<endl;
}
	return 0; 
}
