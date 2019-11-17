输入一个链表，输出该链表中倒数第k个结点。

```c
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
    {
        if(pListHead == NULL)
            return NULL;
        ListNode *fast,*slow;
        fast = slow = pListHead;
        while(k-->0)
        {
            if(fast == NULL)
                return NULL;
            fast = fast->next;
            
        }
        while(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
```

