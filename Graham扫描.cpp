#include <cmath> 
#include <cstdio>
#include <algorithm>
const int N=50101;
const double eps=1e-9;
int dcmp(const double &a){
    if(fabs(a)<eps)return 0;
    return a<0?-1:1;
}
inline double max(const double &a,const double &b){return dcmp(a-b)>0?a:b;}
struct point{
    double x,y;
    point(const double &X=0,const double &Y=0):x(X),y(Y){}
}p[N],stk[N];int tp,mi;
point operator -(const point &a,const point &b){
    return point(a.x-b.x,a.y-b.y);
}
double operator ^(const point &a,const point &b){
    return a.x*b.x+a.y*b.y;
}
double operator *(const point &a,const point &b){
    return a.x*b.y-a.y*b.x;
}
double len(const point &a){
    return sqrt(a^a);
}
//bool cmpa(const point &a,const point &b){
//	point X=point(1,0),A=a-p[0],B=b-p[0];
//	double coa=(A^X)/len(A),cob=(B^X)/len(B);
//	共线的时候选远的那个.保证前面的在凸包上.
//	if(!dcmp(coa-cob)) return dcmp(len(A)-len(B))>0; 
//	return dcmp(coa-cob)>0;
//} //按夹角排序(点积版)
bool cmpa(const point &a,const point &b){
  	point A=a-p[0],B=b-p[0];
  	if(!dcmp(A*B)) return dcmp(len(A)-len(B))>0;
  	return dcmp(A*B)>0;
} //叉积版 
void grahamScan(point* p,int n){
    std::sort(p+1,p+n,cmpa);
    stk[++tp]=p[0]; stk[++tp]=p[1];
    for(int i=2;i<n;++i){
        while(dcmp((p[i]-stk[tp])*(stk[tp]-stk[tp-1]))>=0&&tp>2) --tp;
        //由于排过序共线的时候一定不优, 所以不逆时针而且能退栈(栈里大于两个点)就退栈
        stk[++tp]=p[i]; //进栈
    }
}
int main(){
    int n; scanf("%d",&n); double my=1e9,ans=0;
    for(int i=0;i<n;++i){
        scanf("%lf%lf",&p[i].x,&p[i].y);
        if(dcmp(p[i].y-my)<0||
        (!dcmp(p[i].y-my)&&dcmp(p[i].x-p[mi].x)<0))
            my=p[i].y,mi=i;	
    } std::swap(p[0],p[mi]);
    grahamScan(p,n);
    for(int i=1;i<tp;++i)
        ans+=len(stk[i]-stk[i+1]);
    printf("%.2lf",ans+len(stk[tp]-p[0]));
}
