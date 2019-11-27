#include<stdio.h>
#include "ArrayList.h"


void ListInit(List*plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
	
}
void LInsert(List*plist, Ldata data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("저장이 불가능합니다.");
		return;
	}
	plist->arr[ plist->numOfData ] = data;
	(plist->numOfData)++;
	
}

int LFirst(List*plist, Ldata*pdata)
{
	if (plist->numOfData == 0)
		return FALSE;//저장된 데이터가 하나도 없다면 FALSE반환

	plist->curPosition = 0;
	*pdata = plist->arr[0];
	return TRUE;
	
}
int LNext(List*plist, Ldata*pdata) 
{
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;//더 이상 참조할 데이터가 없다면
	
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

Ldata LRemove(List*plist) 
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	Ldata rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;

}
int LCount(List*plist)
{
	return plist->numOfData;
}

