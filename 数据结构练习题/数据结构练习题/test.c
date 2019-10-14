1.给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。
示例 1：
输入：[1, 2, 3, 4, 5]
输出：此列表中的结点 3 (序列化形式：[3, 4, 5])
返回的结点值为 3 。(测评系统对该结点序列化表述是[3, 4, 5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
示例 2：
输入：[1, 2, 3, 4, 5, 6]
输出：此列表中的结点 4 (序列化形式：[4, 5, 6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/middle-of-the-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
2.反转一个单链表。

示例 :

输入 : 1->2->3->4->5->NULL
输出 : 5->4->3->2->1->NULL

 进阶 :
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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