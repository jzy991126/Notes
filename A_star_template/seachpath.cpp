#include "searchpath.h"

void CSearchPath::SearchPath(zb2 startPoint, zb2 endPoint)
{
	struct heapnode {
		nodeinfo info;
		zb2 zb;

		heapnode(nodeinfo a, zb2 b) :info(a), zb(b) {}

		bool operator<(const heapnode &b) const
		{
			return b.info < info;
		}
	};
	std::priority_queue<heapnode> heap;

	nodeinfo startinfo = nodeinfo(0, euclid_dist(startPoint, endPoint), endPoint);
	openset.insert(make_pair(startPoint, startinfo));
	heap.push(heapnode(startinfo, startPoint));

	while (heap.size()) {
		heapnode cur = heap.top();
		heap.pop();

		nodeset::iterator it = openset.find(cur.zb);
		closeset.insert(make_pair(it->first, it->second));
		openset.erase(it);

		if (cur.zb == endPoint) { //����Ѿ��ҵ��յ�
			//TODO: �ҵ��յ�Ҫ������
			getPath(startPoint, endPoint);
			return;
		}

		for (int i = 0; i < 8; ++i) {
			zb2 tar = cur.zb + d8[i];

			if (cannotPass(tar)) //����ͨ��
				continue;

			it = closeset.find(tar);
			if (it != closeset.end()) //�Ѿ��������
				continue;

			nodeinfo newinfo = nodeinfo(
				cur.info.g + euclid_dist(tar, cur.zb),
				euclid_dist(tar, endPoint),
				cur.zb
			); //�µ����Ϣ

			it = openset.find(tar);
			if (it != openset.end()) { //�ڿ����б���		
				if (newinfo < it->second) //������ž͸�����Ϣ
					it->second = newinfo;
			}
			else {
				openset.insert(make_pair(tar, newinfo));
				heap.push(heapnode(newinfo, tar));
			}
		}
	}
}

void CSearchPath::getPath(zb2 startPoint, zb2 endPoint)
{
	std::vector<zb2> pts;

	for (zb2 now = endPoint;
		!(closeset.find(now)->second.pre == endPoint);
		now = closeset.find(now)->second.pre)
	{
		pts.push_back(now);
	}

	pts.push_back(startPoint);

	std::reverse(pts.begin(), pts.end());
	for (auto &x : pts) {
		std::cout << "(" << x.x << "," << x.y << ")\n";
	}
}

bool CSearchPath::cannotPass(zb2 zb)
{
	return false;
}
