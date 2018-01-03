#include <cstdio>
#include <cmath>
const double eps=1e-9;
template<class T>
inline T abs(const T &a){
	return a>0?a:-a;
}
template<class T,class U>
inline T max(const T &a,const U &b){
	return a>b?a:b;
}
template<class T,class U>
inline T min(const T &a,const U &b){
	return a<b?a:b;
}
inline int dcmp(const double &a){
  	if(fabs(a)<eps) return 0;
	return a<0?-1:1;
}
struct vec{
	double x,y;
	vec(double p,double q):x(p),y(q){}
	vec(){x=y=0.0;}
};
inline double len(const vec &a){
	return sqrt(a.x*a.x+a.y*a.y);
}
inline double dis(const vec &a,const vec &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
vec operator +(const vec &a,const vec &b){
	return vec(a.x+b.x,a.y+b.y);
}
vec operator -(const vec &a,const vec &b){
	return vec(a.x-b.x,a.y-b.y);
}
vec operator *(const vec &a,const double &b){
	return vec(a.x*b,a.y*b);
}
vec operator *(const double &b,const vec &a){
	return vec(a.x*b,a.y*b);
}
vec operator /(const vec &a,const double &b){
	return vec(a.x/b,a.y/b);
}
double operator ^(const vec &a,const vec &b){
	return a.x*b.x+a.y*b.y;
}
double operator *(const vec &a,const vec &b){
	return a.x*b.y-a.y*b.x;
}
inline bool ptInRect(const vec &q,const vec &p0,const vec &p1){
	return min(p0.x,p1.x)<=q.x&&q.x<=max(p0.y,p1.y)
		&&min(p0.y,p1.y)<=q.y&&q.y<=max(p0.y,p1.y);
}
inline bool ptOnSeg(const vec &q,const vec &p0,const vec &p1){
	return (p1-p0)*q==0&&ptInRect(q,p0,p1);
}
inline bool segCutLine(const vec &p0,const vec &p1,const vec &q0,const vec &q1){
	return ((p0-q0)*(q1-q0))*((q1-q0)*(p1-q0))>=0;
}
inline bool segCutSeg(const vec &p0,const vec &p1,const vec &q0,const vec &q1){
	if(min(p0.x,p1.x)>max(q0.x,q1.x)||min(q0.x,q0.y)>max(p0.x,p1.x)
		||min(p0.y,p1.y)>max(q0.y,q1.y)||min(q0.y,q1.y)>max(p0.y,p1.y)) return false; //快速排斥实验
	return ((p0-q0)*(q1-q0))*((q1-q0)*(p1-q0))>=0&&((q0-p0)*(p1-p0))*((p1-p0)*(q1-p0))>=0;
}
inline bool rectInRect(const vec &p0,const vec &p1,const vec &q0,const vec &q1){
	return min(p0.x,p1.x)<min(q0.x,q1.x)&&max(p0.x,p1.x)>max(q0.x,q1.x)
		&&min(p0.y,p1.y)<min(q0.y,q1.y)&&max(p0.y,p1.y)>max(q0.y,q1.y);
}
inline bool cirInRect(const vec &o,const double &r,const vec &p0,const vec &p1){
	return ptInRect(o,p0,p1)&&min(
		min(abs(min(p0.x,p1.x)-o.x),abs(max(p0.x,p1.x)-o.x)),
		min(abs(min(p0.y,p1.y)-o.y),abs(max(p0.y,p1.y)-o.y))
	)<r;
}
inline bool ptInCir(const vec &p,const vec &o,const double &r){
	return dis(p,o)<r;
}
inline bool cirInCir(const vec &o1,const double &r1,const vec &o2,const double &r2){
	return dis(o1,o2)<=r2-r1;
}
inline bool ptDisLine(const vec &p,const vec &q0,const vec &q1){
	return (p-q0)*(q1-q0)/len(q1-q0);
}
inline bool ptDisSeg(const vec &p,const vec &q0,const vec &q1){
	if(!dcmp((p-q0)^(q1-q0))) return dis(p,q0); //也可以写成len(p-q0).. 
	if(!dcmp((p-q1)^(q0-q1))) return dis(p,q1);
	return (p-q0)*(q1-q0)/len(q1-q0);
}
inline vec lineCutLineNode(const vec &p0,const vec &p1,const vec &q0,const vec &q1){
	double a1,b1,c1,a2,b2,c2,d;
	a1=p1.x-p0.x; b1=p0.y-p1.y; c1=p0*p1;
	a2=q1.x-q0.x; b2=q0.y-q1.y; c2=q0*q1;
	d=a1*b2-a2*b1;
	return vec((b2*c1-b1*c2)/d,(a1*c2-a2*c1)/d);
}
int main(){
}
