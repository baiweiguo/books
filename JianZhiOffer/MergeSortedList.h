#include "LinkList.h"

ListNode* SortList(ListNode* L)
{
	if (L==NULL || L->m_pNext==NULL)
		return L;
	ListNode* sort = L->m_pNext;
	ListNode* smallest;// = L->m_pNext;
	ListNode* tmp;// = smallest->m_pNext;
	while (sort!=NULL)
	{
		smallest = sort;
		tmp = smallest->m_pNext;
		while (tmp!=NULL)
		{
			if (tmp->m_nValue<smallest->m_nValue)
				smallest = tmp;				
			tmp = tmp->m_pNext;
		}
		if (sort!=smallest)
		{
			sort->m_nValue = (sort->m_nValue)^(smallest->m_nValue);
			smallest->m_nValue = (sort->m_nValue)^(smallest->m_nValue);
			sort->m_nValue = (sort->m_nValue)^(smallest->m_nValue);
		}
		sort = sort->m_pNext;
	}
	
	return L;
}


ListNode* MergeSortedList(ListNode*L1,ListNode*L2)
{
	ListNode* LMerged = new ListNode;
	LMerged->m_pNext = NULL;

	if (L1==NULL || L1->m_pNext==NULL)
		return L2;
	if (L2==NULL || L2->m_pNext==NULL)
		return L1;

	ListNode* tmp = LMerged;

	ListNode* p1 = L1->m_pNext;
	ListNode* p2 = L2->m_pNext;

	while (p1!=NULL && p2!=NULL)
	{
		if (p1->m_nValue<p2->m_nValue)
		{
			tmp->m_pNext = p1;
			p1 = p1->m_pNext;
			tmp = tmp->m_pNext;
		}
		else
		{
			tmp->m_pNext = p2;
			p2 = p2->m_pNext;
			tmp = tmp->m_pNext;
		}

		if (p1==NULL)
			tmp->m_pNext = p2;
		if (p2==NULL)
			tmp->m_pNext = p1;
	}
	return LMerged;
}

//采用递归的方法：(无头节点)
ListNode* MergeSortedList2(ListNode* L1,ListNode* L2)
{
	if (NULL==L1)
		return L2;
	else if (NULL==L2)
		return L1;

	ListNode* L=NULL;
	if (L1->m_nValue<L2->m_nValue)
	{
		L = L1;
		L1->m_pNext = MergeSortedList2(L1->m_pNext,L2);
	}
	else
	{
		L = L2;
		L2->m_pNext = MergeSortedList2(L1,L2->m_pNext);
	}
	return L;
}