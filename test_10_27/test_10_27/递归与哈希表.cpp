哈希表
HashTable.cpp
typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;
概念
哈希函数： H(key) : K->D, key ∈ K
构造方法
直接定址法
除留余数法
数字分析法
折叠法
平方取中法
冲突处理方法
链地址法：key 相同的用单链表链接
开放定址法
线性探测法：key 相同->放到 key 的下一个位置， Hi = (H(key) + i) % m
二次探测法：key 相同->放到 Di = 1 ^ 2, -1 ^ 2, ..., ±（k) ^ 2, (k <= m / 2）
随机探测法： H = (H(key) + 伪随机数) % m
线性探测的哈希表数据结构
线性探测的哈希表数据结构和图片
递归
概念
函数直接或间接地调用自身
typedef char KeyType;
typedef struct {
	KeyType key;
}RcdType;
typedef struct {
	RcdType *rcd;
	int size;
	int count;
	bool *tag;
}HashTable;
递归
概念
函数直接或间接地调用自身
typedef char KeyType;
typedef struct {
	KeyType key;
}RcdType;
typedef struct {
	RcdType *rcd;
	int size;
	int count;
	bool *tag;
}HashTable;
递归与分治
分治法
问题的分解
问题规模的分解
折半查找（递归）
归并查找（递归）
快速排序（递归）
递归与迭代
迭代：反复利用变量旧值推出新值
折半查找（迭代）
归并查找（迭代）
广义表
头尾链表存储表示
广义表的头尾链表存储表示和图片
// 广义表的头尾链表存储表示
typedef enum { ATOM, LIST } ElemTag;
// ATOM==0：原子，LIST==1：子表
typedef struct GLNode {
	ElemTag tag;
	// 公共部分，用于区分原子结点和表结点
	union {
		// 原子结点和表结点的联合部分
		AtomType atom;
		// atom 是原子结点的值域，AtomType 由用户定义
		struct {
			struct GLNode *hp, *tp;
		} ptr;
		// ptr 是表结点的指针域，prt.hp 和 ptr.tp 分别指向表头和表尾
	} a;
} *GList, GLNode
扩展线性链表存储表示
扩展线性链表存储表示和图片
// 广义表的扩展线性链表存储表示
typedef enum { ATOM, LIST } ElemTag;
// ATOM==0：原子，LIST==1：子表
typedef struct GLNode1 {
	ElemTag tag;
	// 公共部分，用于区分原子结点和表结点
	union {
		// 原子结点和表结点的联合部分
		AtomType atom; // 原子结点的值域
		struct GLNode1 *hp; // 表结点的表头指针
	} a;
	struct GLNode1 *tp;
	// 相当于线性链表的 next，指向下一个元素结点
} *GList1, GLNode1;