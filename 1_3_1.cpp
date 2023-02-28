//m=？ 
#include<iostream>
#include<vector>
#include<queue> 
#include<set>

using namespace std;

int main(){
	int n,m;
	float a[105][105];
	cin>>n;
	cin>>m;
	float min=1;
	vector<int>vc;
	set<int>sc;
	for(int i=1;i<=n;i++)sc.insert(i);
	int vx,vy;
	    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]<min&&i<j){
            	min=a[i][j];
            	vx=i;
            	vy=j;
			}
        }
    }
    vc.push_back(vx);
    sc.erase(vx);
    vc.push_back(vy);
    sc.erase(vy);
    for(int i=2;i<m;i++){
    	float sum_min=i;
    	int v_min=1;
    	for(set<int>::iterator t=sc.begin();t!=sc.end();t++){
    		float sum=0;
    		for(int j=0;j<i;j++){
    			sum+=a[vc[j]][*t];
			}
    		if(sum<sum_min){
    			sum_min=sum;
    			v_min=*t;
			}
		}
        min+=sum_min;
        vc.push_back(v_min);
        sc.erase(v_min);
	}
    
	cout<<"适配度:"<<min<<endl;
	cout<<"最适配的m种菜:";
	for(int i=0;i<m;i++)
	cout<<vc[i]<<" ";
	return 0; 
}
