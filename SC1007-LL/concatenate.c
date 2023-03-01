////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////

typedef struct _listnode
{
	int num;
	struct _listnode *next;
} ListNode;
typedef struct _linkedlist
{
	ListNode *head;
	int size;
} LinkedList;
typedef struct _dbllistnode
{
	int num;
	struct _dbllistnode *pre;
	struct _dbllistnode *next;
} DblListNode;

////////////////////////////////////////////////////////////////////
////////////
int removeNode(ListNode **ptrHead, int index);
int removeNode2(LinkedList *ll, int index);
int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList);
int duplicateReverse(ListNode *head, ListNode **ptrNewHead);

void printList(ListNode *head);
ListNode *findNode(ListNode *head, int index);
int insertNode(ListNode **ptrHead, int index, int value);
int concatenate(ListNode **ptrHead1, ListNode *head2);

////////////////////////////////////////////////////////////////////
////////////

int main()
{
	int i;
	ListNode *head = NULL;
	ListNode *dupRevHead = NULL;
	ListNode *oddHead = NULL;
	ListNode *evenHead = NULL;
	ListNode *list1Head = NULL, *list2Head = NULL;
	ListNode *combAltHead = NULL;
	DblListNode *dblHead = NULL;
	LinkedList llist;
	int size = 0;

	// build a linked list
	if (insertNode(&head, 0, 6) == 0)
		size++;
	if (insertNode(&head, 0, 4) == 0)
		size++;
	if (insertNode(&head, 0, 2) == 0)
		size++;
	printf("After inserting 3 values.");
	printList(head);

	// removeNode(): question 1
	if (removeNode(&head, 3) == 0)
		size--; // this one can't be removed.
	if (removeNode(&head, 1) == 0)
		size--;
	if (removeNode(&head, 0) == 0)
		size--;

	printf("\nafter remove using removeNode(), "); // 6
	printList(head);

	// insert some nodes
	if (insertNode(&head, 2, 3) == 0)
		size++; // this one can't be inserted.
	if (insertNode(&head, 1, 1) == 0)
		size++;
	if (insertNode(&head, 0, 0) == 0)
		size++;

	printf("\nafter insert, ");
	printList(head);

	// removeNode2(): question 2
	llist.head = head;
	llist.size = size;
	removeNode2(&llist, 2);
	printList(llist.head);
	removeNode2(&llist, 0);
	printList(llist.head);
	removeNode2(&llist, 0);
	head = llist.head;

	printf("\nafter remove using removeNode2(), ");
	printList(llist.head);
	// empty linked list now

	// split(): question 3
	for (i = 1; i < 10; i++) // build a new linked list
		insertNode(&head, 0, i);
	printf("\n\ninsert 1-9 to the linked list,");
	printList(head);
	printf("split the current list, results:\n");
	split(head, &evenHead, &oddHead);
	printf("the even list");
	printList(evenHead);
	printf("the odd list");
	printList(oddHead);

	// duplicateReverse(): question 4
	printf("\n");
	printList(head);
	duplicateReverse(head, &dupRevHead);
	printf("After duplicateReverse(),");
	printList(dupRevHead);

	// 2. concatenate()
	printf("\n************** concatenate() *******************\n");
	concatenate(&head, dupRevHead);
	printf("concatenate(current list, duplicate reverse list)\n  ");
	printList(head);
	return 0;
}

////////////////////////////////////////////////////////////////////
////////////

void printList(ListNode *head)
{
	ListNode *cur = head;

	if (cur == NULL)
		return;

	printf("the current linked list is:\n");
	while (cur != NULL)
	{
		printf("%d ", cur->num);
		cur = cur->next;
	}
	printf("\n");
}

void printDblList(DblListNode *head)
{
	if (head == NULL)
		return;
	while (head != NULL)
	{
		printf("%d ", head->num);
		head = head->next;
	}
	printf("\n");
}

ListNode *findNode(ListNode *head, int index)
{
	if (head == NULL || index < 0)
		return NULL;
	while (index > 0)
	{
		head = head->next;
		if (head == NULL)
			return NULL;
		index--;
	}
	return head;
}

int insertNode(ListNode **ptrHead, int index, int value)
{
	ListNode *pre, *cur;
	// If empty list or inserting first node, need to update head pointer
	if (*ptrHead == NULL || index == 0)
	{
		cur = *ptrHead;
		*ptrHead = malloc(sizeof(ListNode));
		(*ptrHead)->num = value;
		(*ptrHead)->next = cur;
		return 0;
	}
	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ptrHead, index - 1)) != NULL)
	{
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->num = value;
		pre->next->next = cur;
		return 0;
	}
	return -1;
}

////////////////////////////////////////////////////////////////////
////////////

int removeNode(ListNode **ptrHead, int index)
{

	ListNode *cur, *pre;
	if (index < 0 || *ptrHead == NULL)
		return -1;
	if (index == 0)
	{
		cur = *ptrHead;
		*ptrHead = (*ptrHead)->next;
		free(cur);
		return 0;
	}

	else
	{
		if ((pre = findNode(*ptrHead, index - 1)) != NULL)
		{
			if (pre->next == NULL)
				return -1;
			cur = pre->next;
			pre->next = cur->next;
			free(cur);
			return 0;
		}
	}
	return -1;
}

////////////////////////////////////////////////////////////////////////////////
////////////

int removeNode2(LinkedList *ll, int index)
{

	ListNode *pre, *cur;
	if (index < 0 || ll->head == NULL)
	{
		return -1;
	}
	if (index == 0)
	{
		cur = ll->head;
		ll->head = ll->head->next;
		free(cur);
		ll->size--;
		return 0;
	}
	else
	{
		if ((pre = findNode(ll->head, index - 1)) != NULL)
		{
			if (pre->next == NULL)
				return -1;
			cur = pre->next;
			pre->next = cur->next;
			free(cur);
			ll->size--;
			return 0;
		}
	}
	return -1;
}

int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList)
{
	ListNode *cur = head;
	int i = 0, j = 0;
	if (cur == NULL)
		return -1;
	while (cur != NULL)
	{
		if (cur->num % 2 == 0)
		{
			insertNode(ptrEvenList, i, cur->num);
			i++;
		}
		else
		{
			insertNode(ptrOddList, j, cur->num);
			j++;
		}
		cur = cur->next;
	}
	return 0;
}

int duplicateReverse(ListNode *head, ListNode **ptrNewHead)
{
	int index = 0;
	ListNode *cur = head;
	if (head == NULL)
		return -1;
	while (cur != NULL)
	{
		insertNode(ptrNewHead, index, cur->num);
		index++;
		cur = cur->next;
	}

	ListNode *pre = NULL, *temp = *ptrNewHead, *next = NULL;
	while (temp != NULL)
	{
		next = temp->next;
		temp->next = pre;
		pre = temp;
		temp = next;
	}
	*ptrNewHead = pre;
	return 0;
}

////////////////////////////////////////////////////////////////////
////////////

int moveMaxToFront(ListNode **ptrHead)
{
	ListNode *max = malloc(sizeof(ListNode));
	max->num = (*ptrHead)->num;
	max->next = NULL;

	ListNode *cur = *ptrHead, *beforeMax;
	if (cur == NULL)
		return -1;
	while (cur != NULL)
	{
		if (cur->next == NULL)
			break;
		if (cur->next->num > max->num)
		{
			max->num = cur->next->num;
			beforeMax = cur;
		}
		cur = cur->next;
	}

	// remove original max node
	ListNode *temp = beforeMax->next;
	beforeMax->next = temp->next;
	free(temp);

	// insert new max node infront
	max->next = *ptrHead;
	*ptrHead = max;
	return 0;
}

int concatenate(ListNode **ptrHead1, ListNode *head2)
{
	if (*ptrHead1 == NULL || head2 == NULL)
		return -1;
	else if ((*ptrHead1)->next == NULL)
	{
		(*ptrHead1)->next = head2;
		return 0;
	}
	ListNode *end = *ptrHead1;
	while (end->next != NULL)
		end = end->next;
	end->next = head2;
}
