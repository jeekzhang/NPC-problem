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

double search_min(double arr[105][105],long long len,long long count) {
  double min=count;
  for (long long i = 0; i < pow(2, len); i++) {
	if (cnt(i) == count) {
	  double s = 0;
	  long long ct=0;
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
 
int test1(long long n,double l,double a[105][105]){
	double min,lc,min_s;
	min_s=2;
	min=1;
	lc=l;
	long long m=1;
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
    for(long long i=2;i<n;i++){
    	double sum_min=i;
    	long long v_min;
    	for(set<long long>::iterator t=sc.begin();t!=sc.end();t++){
    		double sum=0;
    		for(long long j=0;j<i;j++){
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

    return m;
}


double test2(long long n,double l,double a[105][105]){
	
	int max=1;
   
    long long left=1;
    long long right=n;
     while(left < right)
    {
        int mid=(left+right)/2;
        double s=search_min(a,n,mid);
        if(s == l){
            max=mid;
			break;    // 条件一：中间的值与目标值相同
        }
        else if(s > l){
            right=mid;// 条件二：中间的值大于目标值
        }
        else {
        	max=mid+1;
            left=mid+1;// 条件三：中间的值小于目标值
        }
    }

  return max;
}

int main(){
	srand((unsigned)time(NULL)); 
	long long count=0;
//	int c1,c2;
//	c1=c2=0;
	for(long long k=0;k<1000;k++){
	double a[105][105];
	long long n=rand()%20 + 3;
	double l=(double)(rand() % 100) / 10;
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
    int t1=test1(n,l,a);
    int t2=test2(n,l,a);

//    c1+=t1;
//    c2+=t2;
//   if(t1==t2)count++;
    if(t1+1=t2)count++;

}
//	cout<<(c2-c1)/1000<<endl;
	cout<<(double)count/1000 ;
	return 0; 
}
