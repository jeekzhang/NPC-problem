#include <iostream>
#include <vector>
#include <math.h>
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
 
int main(){
	long long n;
	double l;
	int max=1;
	cin>>n>>l;
	double a[105][105];
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
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
	cout<<"-------"<<endl;
	cout<<max;
}
