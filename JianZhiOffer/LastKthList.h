/*
*  LastKthList.h
*  功能：获取给定的链表中倒数第k个节点
*
*/

#include "LinkList.h"

//求链表中的倒数第k个节点,L中包含一个头节点。
ListNode* GetKthToTail(ListNode* L,unsigned k)
{
	//k为unsigned，若k=0，则循环中k-1为 0xffffffff(unsigned)“无穷大”
	if (L==NULL || 0==k) 
		return NULL;

	ListNode* pTemp1 = L->m_pNext;//L第一个节点为头节点
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
