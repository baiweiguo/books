#include "LastKthList.h"
#include "ListLoop.h"
#include "ReverseList.h"
#include "MergeSortedList.h"

#include <windows.h>

int main()
{
	ListNode* L1 = CreateListTail(5);
	L1 = SortList(L1);
	PrintList(L1);
	Sleep(1000);
	ListNode* L2 = CreateListTail(6);
	L2 = SortList(L2);
	PrintList(L2);

	ListNode* L = MergeSortedList(L1,L2);

	PrintList(L);

/*	FILETIME beg,end;
	GetSystemTimeAsFileTime(&beg);
	ListNode* L = CreateListTail(2000);		
	GetSystemTimeAsFileTime(&end);
	PrintList(L);
	L = ReverseList(L);
	PrintList(L);
	
	unsigned long t = (100*(end.dwLowDateTime-beg.dwLowDateTime));
	
	cout<<double(t)/1000<<"us"<<endl;*/
/*	ListNode* p = L;
	while (p->m_pNext!=NULL)
	{
		p = p->m_pNext;
	}*/
//	p->m_pNext = L->m_pNext->m_pNext->m_pNext->m_pNext->m_pNext->m_pNext;

//	cout<<FindLoopPort(L)->m_nValue<<endl;

//	ListNode* KthToTail = GetKthToTail(L,10);
//	cout<<KthToTail->m_nValue<<endl;
	system("pause");
	return 0;
}