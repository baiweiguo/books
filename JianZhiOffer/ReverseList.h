#include "LinkList.h"

ListNode* ReverseList(ListNode* L)
{
	if (L==NULL && L->m_pNext==NULL)
		return NULL;
	ListNode* pNode = L->m_pNext;
	ListNode* pPrev = NULL;

	while (pNode!=NULL)
	{		
		ListNode* pNext = pNode->m_pNext;
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	L->m_pNext = pPrev;
	return L;
}