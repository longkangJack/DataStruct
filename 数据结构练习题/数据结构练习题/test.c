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