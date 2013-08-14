/*
*  LastKthList.h
*  ���ܣ���ȡ�����������е�����k���ڵ�
*
*/

#include "LinkList.h"

//�������еĵ�����k���ڵ�,L�а���һ��ͷ�ڵ㡣
ListNode* GetKthToTail(ListNode* L,unsigned k)
{
	//kΪunsigned����k=0����ѭ����k-1Ϊ 0xffffffff(unsigned)�������
	if (L==NULL || 0==k) 
		return NULL;

	ListNode* pTemp1 = L->m_pNext;//L��һ���ڵ�Ϊͷ�ڵ�
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
