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
	L=new ListNode;
	L->m_pNext = NULL;

	srand(time(0));
	ListNode* p = NULL;
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
	}
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

//�������еĵ�����k���ڵ�
ListNode* GetKthToTail(ListNode* L,unsigned k)
{
	if (L==NULL || 0==k)
		return NULL;

	ListNode* pTemp1 = L->m_pNext;
	for (int i=0;i<k-1;i++)
	{
		if (pTemp1->m_pNext!=NULL)
		{
			pTemp1 = pTemp1->m_pNext;
		}
		else
		{
			return NULL;
		}
		
	}
	ListNode* pTemp2 = L->m_pNext;

	while (pTemp1->m_pNext!=NULL)
	{
		pTemp1 = pTemp1->m_pNext;
		pTemp2 = pTemp2->m_pNext;
	}
	
	return pTemp2;
}
