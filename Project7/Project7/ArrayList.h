#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef int Ldata;

typedef struct __ArrayList
{
	Ldata arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;

typedef ArrayList List;

void ListInit(List*plist);
void LInsert(List*plist, Ldata data);

int LFirst(List*plist, Ldata data);
int LNext(List*plist, Ldata data);

Ldata LRemove(List*plist);
int LCount(List*plist);

#endif