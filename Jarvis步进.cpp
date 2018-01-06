#include <cmath> 
#include <cstdio>
const int N=10101;
const double eps=1e-9;
int dcmp(const double &a){
	if(fabs(a)<eps)return 0;
	return a<0?-1:1;
}
struct point{
	double x,y;
	point(const double &X=0,const double &Y=0):x(X),y(Y){}
}p[N];
point operator -(const point &a,const point &b){
	return point(a.x-b.x,a.y-b.y);
}
double operator *(const point &a,const point &b){
	return a.x*b.y-a.y*b.x;
}
double len(const point &a){
	return sqrt(a.x*a.x+a.y*a.y);
}
int po[N],tot,mi;
void jarvisMarch(point *p,int n){
	int h=mi;
	do{
		int h2=-1;
		for(int i=0;i<n;++i)
			if(h!=i&&(h2<0||dcmp((p[i]-p[h])*(p[h2]-p[h]))>0
				||(!dcmp((p[i]-p[h])*(p[h2]-p[h]))
				&&dcmp(len(p[h2]-p[h])-len(p[i]-p[h]))<0)))
				h2=i;
		po[++tot]=h=h2;
	}while(h!=mi);
}
int main(){
	int n;scanf("%d",&n); double ans=0,mx=1e9;
	for(int i=0;i<n;++i){
		scanf("%lf%lf",&p[i].x,&p[i].y);
		if(dcmp(p[i].x-mx)<0)
			mx=p[i].x,mi=i;
	}
	jarvisMarch(p,n);
	for(int i=1;i<=tot;++i)
		printf("%d ",po[i]);
	for(int i=1;i<tot;++i)
		ans+=len(p[po[i]]-p[po[i+1]]);
	printf("%.2lf",ans+len(p[po[tot]]-p[po[1]]));
}
