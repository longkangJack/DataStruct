��ϣ��
HashTable.cpp
typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;
����
��ϣ������ H(key) : K->D, key �� K
���췽��
ֱ�Ӷ�ַ��
����������
���ַ�����
�۵���
ƽ��ȡ�з�
��ͻ������
����ַ����key ��ͬ���õ���������
���Ŷ�ַ��
����̽�ⷨ��key ��ͬ->�ŵ� key ����һ��λ�ã� Hi = (H(key) + i) % m
����̽�ⷨ��key ��ͬ->�ŵ� Di = 1 ^ 2, -1 ^ 2, ..., ����k) ^ 2, (k <= m / 2��
���̽�ⷨ�� H = (H(key) + α�����) % m
����̽��Ĺ�ϣ�����ݽṹ
����̽��Ĺ�ϣ�����ݽṹ��ͼƬ
�ݹ�
����
����ֱ�ӻ��ӵص�������
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
�ݹ�
����
����ֱ�ӻ��ӵص�������
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
�ݹ������
���η�
����ķֽ�
�����ģ�ķֽ�
�۰���ң��ݹ飩
�鲢���ң��ݹ飩
�������򣨵ݹ飩
�ݹ������
�������������ñ�����ֵ�Ƴ���ֵ
�۰���ң�������
�鲢���ң�������
�����
ͷβ����洢��ʾ
������ͷβ����洢��ʾ��ͼƬ
// ������ͷβ����洢��ʾ
typedef enum { ATOM, LIST } ElemTag;
// ATOM==0��ԭ�ӣ�LIST==1���ӱ�
typedef struct GLNode {
	ElemTag tag;
	// �������֣���������ԭ�ӽ��ͱ���
	union {
		// ԭ�ӽ��ͱ�������ϲ���
		AtomType atom;
		// atom ��ԭ�ӽ���ֵ��AtomType ���û�����
		struct {
			struct GLNode *hp, *tp;
		} ptr;
		// ptr �Ǳ����ָ����prt.hp �� ptr.tp �ֱ�ָ���ͷ�ͱ�β
	} a;
} *GList, GLNode
��չ��������洢��ʾ
��չ��������洢��ʾ��ͼƬ
// ��������չ��������洢��ʾ
typedef enum { ATOM, LIST } ElemTag;
// ATOM==0��ԭ�ӣ�LIST==1���ӱ�
typedef struct GLNode1 {
	ElemTag tag;
	// �������֣���������ԭ�ӽ��ͱ���
	union {
		// ԭ�ӽ��ͱ�������ϲ���
		AtomType atom; // ԭ�ӽ���ֵ��
		struct GLNode1 *hp; // ����ı�ͷָ��
	} a;
	struct GLNode1 *tp;
	// �൱����������� next��ָ����һ��Ԫ�ؽ��
} *GList1, GLNode1;