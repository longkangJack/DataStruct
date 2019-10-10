//循环链表
//单链表只有向后结点，当单链表的尾链表不指向NULL，而是指向头结点时候，
//形成了一个环，成为单循环链表，简称循环链表。当它是空表，
//向后结点就只想了自己，这也是它与单链表的主要差异，
//判断node->next是否等于head。
//然后实现 功能
//循环链表之约瑟夫环的问题
//约瑟夫环（约瑟夫问题）是一个数学的应用问题：
//已知n个人（以编号1，2，3…n分别表示）围坐在一张圆桌周围。从编号为k的人开始报数，数到m的那个人出列；
//他的下一个人又从1开始报数，数到m的那个人又出列；依此规律重复下去，直到圆桌周围的人全部出列。这类问题用循环列表的思想刚好能解决。
//注意：编写代码的时候，注意报数为m = 1的时候特殊情况
#include  <stdio.h>
#include  <stdlib.h>
/*--------------------------结构体------------*/
typedef struct Lnode          /*  结点的结构定义  */

{
	int  num;              /*  编号子域        */
	int  sm;               /*  密码子域        */
	struct Lnode *next;        /*  指针域          */

}Lnode, *LinkList;
/* 函数声明   */
LinkList creat();
void  print1(LinkList  h);
void  print2(LinkList  h);
LinkList shanchu(LinkList h);
void outs(LinkList  h, int m);

/*  主函数  */
main()
{
	int  m;  LinkList  head;
	head = creat();
	print1(head);//带头结点输出（其实是跳过了头结点）
	head = shanchu(head);
	print2(head);//删除头结点后输出
	printf("\n  enter the begin secret code, m=（m>1）");   scanf("%d", &m);
	outs(head, m);//按照密码输出
}  /* main  */

/*  创建约瑟夫环 带头结点的单链表 */
LinkList  creat()
{
	int  i = 0, mi;
	LinkList  h, p2, p1;
	h = (LinkList)malloc(sizeof(Lnode));
	p1 = h;
	p1->next = h;
	printf("\n 个人密码为： ");  scanf("%d", &mi);

	while (mi != -111)                    //  密码为-111，结束循环  
	{
		p2 = (LinkList)malloc(sizeof(Lnode));  //  申请数据元素结点空间

		i++;
		p2->num = i;
		p2->sm = mi;
		p2->next = h;//连成环 
		p1->next = p2;
		p1 = p2;
		printf("\n 个人密码为：  ");  scanf("%d", &mi);   
		//读入下一个密码
	}  //while  
	return(h);
}
/*---------------------------------------带头结点输出（跳过头结点输出）----------------*/
void  print1(LinkList  h)
{
	LinkList q;
	q = h->next;
	printf("带头结点链表输出：\n");
	// 与头插法创建链表对应的输出函数
	while (q != h)
	{
		printf("%6d %6d  \n", q->num, q->sm);
		q = q->next;
	}
}
LinkList shanchu(LinkList h){
	LinkList m, p;
	m = h;
	for (p = h; p->next != h; p = p->next);
	p->next = h->next;
	h = h->next;
	free(m);
	return(h);
}
/*----------------------删除头结点后输出-------------------*/
void  print2(LinkList  h)
{
	LinkList r;
	r = h;
	printf("不带头结点链表输出：\n");
	while (r->next != h)
	{
		printf("%6d %6d  \n", r->num, r->sm);
		r = r->next;
	}
	printf("%6d %6d  \n", r->num, r->sm);// 头指针指向第一个数据元素结点

}
/*--------------------------------按照密码输出某个人------------*/
void outs(LinkList  h, int m)
{
	int i;   LinkList q = h, p;
	printf("\n ");
	while (q->next != q)
	{
		for (i = 1; i<m; i++){ p = q; q = q->next; }      // 报数到第m个人

		printf("%6d %6d\n ", q->num, q->sm);     //  输出第m个人的编号和密码  
		m = q->sm;
		p->next = q->next;  free(q);           //  第m个人出列

		q = p->next;
	}
	printf("%6d %6d  \n", q->num, q->sm);         //   输出最后一个结点的编号值

	free(q);
} //outs 

