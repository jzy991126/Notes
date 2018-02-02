#include "structures.h"

#include <map>
#include <queue>
#include <iostream>
using std::make_pair;

class CSearchPath {
public:	
	virtual void SearchPath(zb2 startPoint,zb2 endPoint);

	struct nodeinfo {
		double f, g, h;
		zb2 pre;

		nodeinfo(double G = 0, double H = 0, zb2 prev = zb2())
			:g(G), h(H), pre(prev) {
			f = g + h;
		}

		bool operator<(const nodeinfo &b) const
		{
			return f < b.f;
		}
	};

	typedef std::map<zb2, nodeinfo> nodeset;
	
	nodeset openset;
	nodeset closeset;

	virtual void getPath(zb2 startPoint, zb2 endPoint);
	virtual bool cannotPass(zb2 zb);
private:
	const zb2 d8[8] = {
		{-1,0},
		{-1,-1},
		{0,-1},
		{1,-1},
		{1,0},
		{1,1},
		{0,1},
		{-1,1}
	};
};