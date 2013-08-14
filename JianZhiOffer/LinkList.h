/*  ͷ�ļ��� LinkList.h
*   ���ܣ��򵥵Ķ�������ڵ㣬����һ����������ӡ����
*
*/

#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

#define NULL 0

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

//����һ����ͷ�ڵ�������ڴ���������L��β�����β���n���ڵ㡣
ListNode* CreateListTail(int n)
{
	ListNode* L;
	L = new ListNode;
	L->m_pNext = NULL;

	srand(time(0));
	ListNode* p = NULL;

	ListNode* r = L;
	for (int i=0;i<n;i++)
	{
		p = new ListNode;
		p->m_nValue = rand()%100 + 1;

		r->m_pNext = p;
		r = p;
	}

	r->m_pNext = NULL;


	/*
	for (int i=0;i<n;i++)
	{
		p = new ListNode;
		p->m_nValue = rand()%100+1;
		p->m_pNext = NULL;
		ListNode* q=L;
		while (q->m_pNext!=NULL)
		{
			q = q->m_pNext;
		}
		q->m_pNext = p;
	}*/
	return L;
}

//��ӡ����
void PrintList(ListNode* L)
{
	ListNode* p = L->m_pNext;
	while (p!=NULL)
	{
		cout<<p->m_nValue<<" ";
		p = p->m_pNext;
	}
	cout<<endl;
}


#endif