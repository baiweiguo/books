#include "LastKthList.h"


int main()
{
	ListNode* L = CreateListTail(15);
	PrintList(L);

	ListNode* KthToTail = GetKthToTail(L,10);
	cout<<KthToTail->m_nValue<<endl;
	system("pause");
	return 0;
}