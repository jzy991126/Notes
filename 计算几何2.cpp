#include <cmath> 
#include <cstdio>
const double eps=1e-9;
int dcmp(const double &a){
	if(fabs(a)<eps) return 0;
	return a<0?-1:1;
}
struct point{
	double x,y;
	point(double X=0,double Y=0):x(X),y(Y){}
	len(){return sqrt(x*x+y*y);}
}poly[202],pt;
point operator -(const point &a,const point &b){return point(a.x-b.x,a.y-b.y);}
double operator *(const point &a,const point &b){return a.x*b.y-a.y*b.x;}
//求p0p1两点确定的直线和直线y=y0的交点 
double Cutx(const double &y0,const point &p0,const point &p1){
	return ((y0-p0.y)*p1.x+(p1.y-y0)*p0.x)/(p1.y-p0.y);
}
//交叉法判断点是否在多边形内
//参数p表示点 pts表示多边形的顶点集 pcnt表示顶点数 
bool cn_ptInPoly(const point &p,point *pts,int pcnt){
	pts[pcnt]=pts[0]; int cnt=0;
	for(int i=1;i<=pcnt;++i)
		if(((dcmp(pts[i].y-p.y)>0&&dcmp(pts[i-1].y-p.y)<1)		//#1
			||(dcmp(pts[i].y-p.y)<1&&dcmp(pts[i-1].y-p.y>0)))	//#2(#3)
			&&(dcmp(p.x-Cutx(p.y,pts[i],pts[i-1]))<0))			//#4
			++cnt; //交点计数一次 
	return cnt&1; //交点奇数时在内, 偶数时在外.
}
//绕数法确定点是否在多边形内 
bool wn_ptInPoly(const point &p,point *pts,int pcnt){
	pts[pcnt]=pts[0]; int cnt=0;
	for(int i=1;i<=pcnt;++i)
		if((dcmp(pts[i].y-p.y)>0&&dcmp(pts[i-1].y-p.y)<1) 		//#1(#3) 
			&&dcmp((p-pts[i-1])*(pts[i]-pts[i-1]))<0) 			//#4逆时针 
			++cnt; 
		else if((dcmp(pts[i].y-p.y)<1&&dcmp(pts[i-1].y-p.y)>0)	//#2(#3) 
			&&dcmp((p-pts[i-1])*(pts[i]-pts[i-1]))>0)			//#4顺时针
			--cnt;
	return cnt;	//只要不为0 
}
//二分确定点是否在凸多边形内
//P.S. 假设点以逆时针给出 
bool ptInConvexPoly(const point &p,point *pts,int pcnt){
	point po=p-pts[0]; //比较常用,所以存一下
	if(dcmp(po*(pts[1]-pts[0]))>0
		||dcmp(po*(pts[pcnt-1]-pts[0]))<0)
		return false;  //"快速排斥"一波
	int l=1,r=pcnt-1;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(!dcmp(po*(pts[mid]-pts[0]))<0) //逆时针方向
			l=mid;
		else r=mid;
	}
	return dcmp((p-pts[l])*(pts[l+1]-pts[l]))<0; //在边的左侧 
}
//求任意多边形面积
double polyArea(point *pts,int pcnt,double s=0){
	pts[pcnt]=pts[0]; 
	for(int i=0;i<pcnt;++i)
		s=pts[i]*pts[i+1]+s;
	return 0.5*s;
}
//求简单多边形重心(没特判线段哦~ 
point polyCenter(point *pts,int pcnt,double sx=0,double sy=0,double area=0){
	pts[pcnt]=pts[0]; double ar;
	for(int i=0;i<pcnt;++i){
		ar=pts[i]*pts[i+1];
		sx+=(pts[i].x+pts[i+1].x)*ar;
		sy+=(pts[i].y+pts[i+1].y)*ar;
		area+=ar;
	} area*=3;
	return point(sx/area,sy/area);
}
int main(){
}
