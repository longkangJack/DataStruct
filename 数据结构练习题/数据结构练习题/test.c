1.����һ������ͷ��� head �ķǿյ���������������м��㡣
����������м��㣬�򷵻صڶ����м��㡣
ʾ�� 1��
���룺[1, 2, 3, 4, 5]
��������б��еĽ�� 3 (���л���ʽ��[3, 4, 5])
���صĽ��ֵΪ 3 ��(����ϵͳ�Ըý�����л�������[3, 4, 5])��
ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans��������
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.
ʾ�� 2��
���룺[1, 2, 3, 4, 5, 6]
��������б��еĽ�� 4 (���л���ʽ��[4, 5, 6])
���ڸ��б��������м��㣬ֵ�ֱ�Ϊ 3 �� 4�����Ƿ��صڶ�����㡣
��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/middle-of-the-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
//
int GetLength(struct ListNode* head)
{
	int NodeCount = 0;
	struct ListNode* p = head;
	while (p)
	{
		NodeCount++;
		p = p->next;
	}

	return NodeCount;
}

struct ListNode* middleNode(struct ListNode* head)
{
	int NodeCount = GetLength(head);
	int i = 0;
	struct ListNode* p = head;
	for (i = 0; i<NodeCount / 2; ++i)
	{
		p = p->next;
	}
	return p;
}
2.��תһ��������

ʾ�� :

���� : 1->2->3->4->5->NULL
��� : 5->4->3->2->1->NULL

 ���� :
����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/reverse-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* p;
	struct ListNode* q;
	if (head&&head->next)
	{
		p = head;
		q = p->next;
		p->next = NULL;
		while (q)
		{
			p = q;
			q = q->next;
			p->next = head;
			head = p;
		}
		return head;
	}
	return head;
}
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺


�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�


ע����ַ����ɱ���Ϊ����Ч�ַ�����

//ջ������
bool isValid(char* s)
{

	int length = 0;//�����ַ�������
	while (*(s + length))length++;//��ȡ�ַ�������
	char* ptr = (char*)malloc(length / 2);//�����ڴ�ռ�
	memset(ptr, 0, length / 2);//��ʼ���ڴ�ռ�
	int i, a = 0;
	for (i = 0; i < length; i++)
	{
		if ((*(s + i) == '(') || (*(s + i) == '{') || (*(s + i) == '['))
		{
			a++;
			*(ptr + a) = *(s + i);
		}
		//'('��')'��ASCIIֵ��1��'['��']'��'{'��'}'��ASCIIֵ��2
		else if ((*(s + i) == (*(ptr + a) + 1)) || (*(s + i) == (*(ptr + a) + 2)))
		{
			a--;
		}
		else return 0;
	}
	if (a)
		return 0;
	return 1;
}
ʹ��ջʵ�ֶ��е����в�����


push(x) --��һ��Ԫ�ط�����е�β����
pop() --�Ӷ����ײ��Ƴ�Ԫ�ء�
peek() --���ض����ײ���Ԫ�ء�
empty() --���ض����Ƿ�Ϊ�ա�
#define DataType int
#define MAXSIZE  100
typedef struct
{
	DataType *stack_in;
	DataType *stack_out;
	int top_in;
	int top_out;
} MyQueue;
/** Initialize your data structure here. */
MyQueue* myQueueCreate() {
	MyQueue *S = (MyQueue*)malloc(sizeof(MyQueue));
	if (S == NULL)
		return NULL;
	S->stack_in = (int*)malloc(sizeof(DataType)*MAXSIZE);
	S->stack_out = (int*)malloc(sizeof(DataType)*MAXSIZE);
	S->top_in = -1;
	S->top_out = -1;
	return S;
}
/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	obj->stack_in[++(obj->top_in)] = x;
}
/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (obj->top_out == -1)
	{
		while (obj->top_in != -1)
		{
			obj->stack_out[++(obj->top_out)] = obj->stack_in[(obj->top_in)--];
		}
	}
	return obj->stack_out[(obj->top_out)--];
}
/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (obj->top_out != -1)
	{
		return obj->stack_out[(obj->top_out)];
	}
	else if (obj->top_in != -1)
	{
		return obj->stack_in[0];
	}
	else
		return 0;
}
/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return (obj->top_in == -1 && obj->top_out == -1) ? true : false;
}

void myQueueFree(MyQueue* obj) {
	free(obj);
}
/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/
//������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������

//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��//
typedef struct {
	int *que;
	int front;
	int rear;
	int length;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue *q1;
	q1 = malloc(sizeof(MyCircularQueue));
	q1->que = malloc(sizeof(int)* (k + 1));
	q1->front = q1->rear = 0;
	q1->length = k + 1;
	return q1;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if ((obj->rear + 1) % (obj->length) == obj->front)
		return false;
	else
	{
		obj->rear = (obj->rear + 1) % (obj->length);
		obj->que[obj->rear] = value;
		return true;
	}
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->rear == obj->front)
		return false;
	else
	{
		obj->front = (obj->front + 1) % (obj->length);
		return true;
	}
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->rear == obj->front)
		return -1;
	return obj->que[(obj->front + 1) % obj->length];

}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->rear == obj->front)
		return -1;
	return obj->que[obj->rear];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->rear == obj->front)
		return true;
	return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if ((obj->rear + 1) % (obj->length) == obj->front)
		return true;
	return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	int *tmp;
	tmp = obj->que;
	obj->que = NULL;
	free(tmp);
}
