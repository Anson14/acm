#include "iostream"
#include "cstdio"

#define MAXNUM 1000
#define INFINTE 10000000

using namespace std;

struct segTreeNode
{
	int val;
}segTree[MAXNUM];

/*
 功能：构建线段树
 root：当前线段树的根节点下标 
 arr: 用来构造线段树的数组
 istart：数组的起始位置
 iend：数组的结束位置
*/
void build(int root, int arr[], int istart, int iend) {
	if(istart == iend) {
		segTree[root].val = arr[istart];
	} else {
		int mid = (istart + iend) / 2;
		build(root*2+1, arr, istart, mid);
		build(root*2+2, arr, mid+1, iend);

		segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
	}
}

/*
功能：线段树的区间查询
root：当前线段树的根节点下标
[nstart, nend]: 当前节点所表示的区间
[qstart, qend]: 此次查询的区间
*/

int query(int root, int nstart, int nend, int qstart, int qend)  {
	if(qstart > nend || qend < nstart) {
		return INFINTE;
	}
	if (qstart <= nstart && qend >= nend) {
		return segTree[root].val;
	}

	int mid = (nstart+nend)/2;
	return min(query(root*2+1, nstart, mid, qstart, qend),query(root*2+2, mid+1, nend, qstart, qend));
}

/*
 * 功能：更新线段树中的某个叶子节点的值
 * root：当前线段树的根节点下标
 * [nstart, nend]:当前节点所表示的区间
 * index:待更新节点在原始数组中的下标
 * addVal:更新的值（原来的值加上addVal）
 */
void updateOne(int root, int nstart, int nend, int index, int addVal) {
    if (nstart == nend ) {
        if (index == nstart) {
            segTree[root].val += addVal;
        }
    return;
    }
    int mid = (nstart+nend)/2;
    if(index <= mid) {
        updateOne(root*2+1, nstart, mid, index, addVal);
    } else {
        updateOne(root*2+2, mid+1, nend, index, addVal);
    }
    segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
}

int main() {

}
