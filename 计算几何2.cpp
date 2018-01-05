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
//��p0p1����ȷ����ֱ�ߺ�ֱ��y=y0�Ľ��� 
double Cutx(const double &y0,const point &p0,const point &p1){
	return ((y0-p0.y)*p1.x+(p1.y-y0)*p0.x)/(p1.y-p0.y);
}
//���淨�жϵ��Ƿ��ڶ������
//����p��ʾ�� pts��ʾ����εĶ��㼯 pcnt��ʾ������ 
bool cn_ptInPoly(const point &p,point *pts,int pcnt){
	pts[pcnt]=pts[0]; int cnt=0;
	for(int i=1;i<=pcnt;++i)
		if(((dcmp(pts[i].y-p.y)>0&&dcmp(pts[i-1].y-p.y)<1)		//#1
			||(dcmp(pts[i].y-p.y)<1&&dcmp(pts[i-1].y-p.y>0)))	//#2(#3)
			&&(dcmp(p.x-Cutx(p.y,pts[i],pts[i-1]))<0))			//#4
			++cnt; //�������һ�� 
	return cnt&1; //��������ʱ����, ż��ʱ����.
}
//������ȷ�����Ƿ��ڶ������ 
bool wn_ptInPoly(const point &p,point *pts,int pcnt){
	pts[pcnt]=pts[0]; int cnt=0;
	for(int i=1;i<=pcnt;++i)
		if((dcmp(pts[i].y-p.y)>0&&dcmp(pts[i-1].y-p.y)<1) 		//#1(#3) 
			&&dcmp((p-pts[i-1])*(pts[i]-pts[i-1]))<0) 			//#4��ʱ�� 
			++cnt; 
		else if((dcmp(pts[i].y-p.y)<1&&dcmp(pts[i-1].y-p.y)>0)	//#2(#3) 
			&&dcmp((p-pts[i-1])*(pts[i]-pts[i-1]))>0)			//#4˳ʱ��
			--cnt;
	return cnt;	//ֻҪ��Ϊ0 
}
//����ȷ�����Ƿ���͹�������
//P.S. ���������ʱ����� 
bool ptInConvexPoly(const point &p,point *pts,int pcnt){
	point po=p-pts[0]; //�Ƚϳ���,���Դ�һ��
	if(dcmp(po*(pts[1]-pts[0]))>0
		||dcmp(po*(pts[pcnt-1]-pts[0]))<0)
		return false;  //"�����ų�"һ��
	int l=1,r=pcnt-1;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(!dcmp(po*(pts[mid]-pts[0]))<0) //��ʱ�뷽��
			l=mid;
		else r=mid;
	}
	return dcmp((p-pts[l])*(pts[l+1]-pts[l]))<0; //�ڱߵ���� 
}
//�������������
double polyArea(point *pts,int pcnt,double s=0){
	pts[pcnt]=pts[0]; 
	for(int i=0;i<pcnt;++i)
		s=pts[i]*pts[i+1]+s;
	return 0.5*s;
}
//��򵥶��������(û�����߶�Ŷ~ 
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
