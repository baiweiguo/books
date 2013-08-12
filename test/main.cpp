#include <iostream>
using namespace std;

void makeNext(const char P[],int next[])
{
	int q,k;
	int m = strlen(P);

	next[0] =0;
	for (q=1,k=0;q<m;++q)
	{
		while (k>0 && P[q]!=P[k])
		{
			k=next[k-1];
		}

		if (P[q]==P[k])
		{
			k++;
		}
		next[q] = k;
	}

}

void GetNext(const string& t, int *next)
{
    int j = -1;
    int i = 0;
    next[0] = -1;
    while(i<t.length()-1)
    {
        if( j==-1 || t[i]==t[j]) //�ַ�ƥ�����������j������-1ʱ
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {   //�ַ����ȣ���jֵ����
            j = next[j];
        }
    }

    /*�˴�Ϊkmp���ڼ��㣬next[j]ͳһС1
    //�±��0��ʼ����next����ʱ��������Ҫ+1
    for(i=0; i<t.length(); i++)
    {
        next[i] = next[i]+1;
    }*/

}

int main()
{
	char *p = "abababcd";
	int next[20]={0};
	makeNext(p,next);

	int next1[20]={0};
	GetNext(p,next1);
	system("pause");
	return 0;
}