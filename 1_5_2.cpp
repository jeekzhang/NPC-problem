//m=？ 
#include<iostream>
#include<vector>
#include<queue> 
#include<set>
#include<stdlib.h>
#include<time.h> 
#include<math.h>

using namespace std;

long long cnt(long long a) {
  long long i=a;
  long long count = 0;
  while( i ) {
   if(i & 1){
    ++count;
   }
   i >>= 1;
  }
  return count;
}
 
double test1(long long n,long long m,double a[105][105]){
	double min=1;
	double min_s=2;
	vector<long long>vc;
	vector<double>sum_v; 
	sum_v.push_back(0);//把0位占掉，则以后序号即是点的编号 
	set<long long>sc;
	for(long long i=1;i<=n;i++)sc.insert(i);
	long long vx,vy;
	for(long long i=1;i<=n;i++)
    {
    	double s=0;
        for(long long j=1;j<=n;j++)
        {
            s+=a[i][j];
			}
		sum_v.push_back(s);
        }
    
	    for(long long i=1;i<=n;i++)
        for(long long j=i+1;j<=n;j++)
        { 
            if(a[i][j]<=min){
			if(a[i][j]==min&&(sum_v[i]+sum_v[j])>=min_s);//因为这样一下选了两个点，所以求的是和的最小值 
            	else{
				min_s=sum_v[i]+sum_v[j];
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
    for(long long i=2;i<m;i++){
    	double sum_min=i;
    	long long v_min;
    	for(set<long long>::iterator t=sc.begin();t!=sc.end();t++){
    		double sum=0;
    		for(long long j=0;j<i;j++){
    			sum+=a[vc[j]][*t];
			}
    		if(sum<=sum_min){
    			if(sum==sum_min&&(sum_v[v_min]<=sum_v[*t]));
    			else{//sum<sum_min,sum==sum_min&&sum_v[v_min]>sum_v[*t]
    			sum_min=sum;
    			v_min=*t;
    		}
			}
		}
        min+=sum_min;
        vc.push_back(v_min);
        sc.erase(v_min);
	}
	return min;
    
}

double test3(long long n,long long m,double a[105][105]){
	double min=1;
	double min_s=2;
	vector<long long>vc;
	vector<double>sum_v; 
	sum_v.push_back(0);//把0位占掉，则以后序号即是点的编号 
	set<long long>sc;
	for(long long i=1;i<=n;i++)sc.insert(i);
	long long vx,vy;
	for(long long i=1;i<=n;i++)
    {
    	double s=0;
        for(long long j=1;j<=n;j++)
        {
            s+=a[i][j];
			}
		sum_v.push_back(s);
        }
    
	    for(long long i=1;i<=n;i++)
    {
        for(long long j=i+1;j<=n;j++)
        { 
            if(a[i][j]<min){
				min_s=sum_v[i]+sum_v[j];
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
    for(long long i=2;i<m;i++){
    	double sum_min=i;
    	long long v_min;
    	for(set<long long>::iterator t=sc.begin();t!=sc.end();t++){
    		double sum=0;
    		for(long long j=0;j<i;j++){
    			sum+=a[vc[j]][*t];
			}
    		if(sum<sum_min){
    			
    			//sum<sum_min,sum==sum_min&&sum_v[v_min]>sum_v[*t]
    			sum_min=sum;
    			v_min=*t;
    		
			}
		}
        min+=sum_min;
        vc.push_back(v_min);
        sc.erase(v_min);
	}
	return min;
    
}

double test2(long long len,long long count,double arr[105][105]){
	double min=count;
  for(long long i = 0; i < pow(2, len); i++) {
	if (cnt(i) == count) {
	  double s = 0;
	  for(long long j = 1; j <= len; j++)
	  	for(long long k = j+1; k <= len; k++)
	   {
		if (((i>>(j-1))&1==1)&&((i>>(k-1))&1==1)) {
		  s += arr[j][k];
		}
	  }
	  if(s<min)min=s;
	  if(min==0)break;
	}
  }
  return min;
}

int main(){
	srand((unsigned)time(NULL)); 
	long long count=0;
	double c1,c2,c3;
	c1=c2=c3=0;
	for(long long k=0;k<1000;k++){
	double a[105][105];
	long long n=rand()%20 + 3;
	long long m=rand()%n + 1;
	for(long long i=1;i<=n;i++)
    {
        for(long long j=i;j<=n;j++)
        {
            if(i==j)a[i][j]=0;
			else {
				a[i][j]=(double)(rand() % 10) / 10;
				a[j][i]=a[i][j];
			}
        }
    }
    double t1=test1(n,m,a);
    double t2=test2(n,m,a);
    double t3=test3(n,m,a);
    c1+=t1;
    c2+=t2;
    c3+=t3;
    if(abs(t1-t2)<0.001)count++;
//    if(abs(t3-t2)<0.001)count++;//副产品 

}
	cout<<(c3-c1)/1000<<endl;
//	cout<<(double)count/1000 ;
	return 0; 
}
