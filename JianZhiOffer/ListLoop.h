#include "LinkList.h"

//LΪ����ͷ�ڵ������
bool ListLoopExist(ListNode*L)
{
	if(NULL==L || NULL==L->m_pNext)
		return false;

	ListNode* fast = L->m_pNext;
	ListNode* slow = L->m_pNext;

	while (fast && fast->m_pNext)
	{
		slow = slow->m_pNext;
		fast = fast->m_pNext->m_pNext;

		if (slow==fast)
			return true;
	}

	return false;
}


//Ѱ�һ�����ڵ�
ListNode* FindLoopPort(ListNode* L)
{
	if (L==NULL || L->m_pNext==NULL)
		return NULL;
	ListNode* fast = L->m_pNext;
	ListNode* slow = L->m_pNext;

	while (fast!=NULL && fast->m_pNext!=NULL)
	{
		fast = fast->m_pNext->m_pNext;
		slow = slow->m_pNext;
		if (fast == slow)
			break;
	}
	if (fast==NULL)
		return NULL;

	slow = L->m_pNext;
	while (fast!=slow)
	{
		fast = fast->m_pNext;
		slow = slow->m_pNext;
	}

	return slow;



}