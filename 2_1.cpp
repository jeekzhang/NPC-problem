#include<iostream>
#include<vector>
#include<queue> 
#include<set>

int main(){
	int n;
	float l,min,lc,min_s;
	float a[105][105];
	cin>>n;
	cin>>l;
	min_s=2;
	min=1;
	lc=l;
	int m=1;
	vector<int>vc;
	vector<float>sum_v; 
	sum_v.push_back(0);//把0位占掉，则以后序号即是点的编号 
	set<int>sc;
	for(int i=1;i<=n;i++)sc.insert(i);
	int vx,vy;
	    	for(int i=1;i<=n;i++)
    {
    	float s=0;
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            s+=a[i][j];
			}
		sum_v.push_back(s);
        }
    
	    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        { 
            if(a[i][j]<=min){
            	if(a[i][j]==min&&(sum_v[i]+sum_v[j])>=min_s);
            	else{
				min_s=sum_v[i]+sum_v[j];
            	min=a[i][j];
            	vx=i;
            	vy=j;
            }
			}
        }
    }
    if(lc>=min){
    lc-=min;
    m=2;
    vc.push_back(vx);
    sc.erase(vx);
    vc.push_back(vy);
    sc.erase(vy);
    for(int i=2;i<n;i++){
    	float sum_min=i;
    	int v_min;
    	for(set<int>::iterator t=sc.begin();t!=sc.end();t++){
    		float sum=0;
    		for(int j=0;j<i;j++){
    			sum+=a[vc[j]][*t];
			}
    		if(sum<=sum_min){
    			if(sum==sum_min&&sum_v[v_min]<=sum_v[*t]);
    			else{
    			sum_min=sum;
    			v_min=*t;
    		}
    	}
		}
        if(lc<sum_min)break;
        lc-=sum_min;
        m=i+1;
        vc.push_back(v_min);
        sc.erase(v_min);
	}
}

	cout<<"最多蔬菜数:"<<m<<endl;
//	cout<<"最多蔬菜数:"<<m+1<<endl;//更优解 
	return 0; 
}
