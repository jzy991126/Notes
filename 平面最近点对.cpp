#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
const double eps=1e-9;
int dcmp(const double &a){
	if(fabs(a)<eps) return 0;
	return a<0?-1:1; 
}
struct point{
	double x,y;
	point(double X=0,double Y=0){}
}p[200020];
int t[200020];
inline bool cmpx(const point &a,const point &b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
inline bool cmpy(const int &a,const int &b){
	return p[a].y<p[b].y;
}
inline double dist(const point &a,const point &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double solve(int l,int r){
	if(r==l) return 1e9;
	if(r-l==1) return dist(p[l],p[r]);
	int mid=(l+r)>>1;
	double dl=solve(l,mid);
	double dr=solve(mid+1,r);
	if(dr<dl) dl=dr;
	
	int tot=0; double dis=0;
	for(int i=l;i<=r;++i)
		if(dcmp(fabs(p[i].x-p[mid].x)-dl)<0)
			t[tot++]=i;
	sort(t,t+tot,cmpy);
	for(int i=0;i<tot;++i)
		for(int j=i+1;j<tot&&p[t[j]].y-p[t[i]].y<dl;++j){
            if((dis=dist(p[t[i]],p[t[j]]))<dl) dl=dis;
        }
	return dl;
}
inline int gn(int a=0,char c=0){
	for(;c<'0'||c>'9';c=getchar());
	for(;c>47&&c<58;c=getchar())a=a*10+c-48;return a;
}
int main(){
	int n=gn();
	for(int i=1;i<=n;++i) p[i].x=gn(),p[i].y=gn();
	sort(p+1,p+n+1,cmpx);
	printf("%.4lf",solve(1,n));
} 
