#include "searchpath.h"

const int N = 6;

class maze:public CSearchPath
{
public:
	void run();
private:
	const int map[N][N] = {
		{0,0,0,0,0,0},
		{0,1,1,0,0,0},
		{0,0,1,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,1,1,1},
		{0,0,0,0,0,0}
	};

	bool cannotPass(zb2 zb) override
	{
		return zb.x < 0 || zb.x >= N || zb.y < 0 || zb.y >= N || map[zb.x][zb.y] != 0;
	}
};

void maze::run()
{
	zb2 op = zb2(0, 0);
	zb2 ed = zb2(5, 5);

	SearchPath(op, ed);
}

int main() {
	maze x;
	x.run();

	getchar();
}