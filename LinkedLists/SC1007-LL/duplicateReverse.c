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

// these are for the practice questions
int moveMaxToFront(ListNode **ptrHead);
int concatenate(ListNode **ptrHead1, ListNode *head2);
int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2);
int insertDbl(DblListNode **ptrHead, int index, int value);
void printDblList(DblListNode *head);

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

	printf("\nafter remove using removeNode(), ");
	printList(head);

	// insert some nodes
	if (insertNode(&head, 2, 3) == 0)
		size++; // this one can't be inserted.
	if (insertNode(&head, 1, 1) == 0)
		size++;
	if (insertNode(&head, 0, 0) == 0)
		size++;

	for (i = 1; i < 10; i++) // build a new linked list
		insertNode(&head, 0, i);
        
	// duplicateReverse(): question 4
	printf("\n");
	printList(head);
	duplicateReverse(head, &dupRevHead);
	printf("After duplicateReverse(),");
	printList(dupRevHead);
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
	ListNode *curr, *pre;
	if (ll->head == NULL || index < 0 || index >= ll->size)
		return -1;
	if (index == 0)
	{
		curr = ll->head;
		ll->head = ll->head->next;
		free(curr);
		ll->size--;
		return 0;
	}
	if ((pre = findNode(ll->head, index - 1)) != NULL)
	{
		if (pre->next == NULL)
			return -1;
		else
		{
			curr = pre->next;
			pre->next = curr->next;
			free(curr);
			ll->size--;
			return 0;
		}
	}
	return -1;
}

int duplicateReverse(ListNode *head, ListNode **ptrNewHead)
{
	ListNode *prev = NULL;
	ListNode *next = NULL;
	ListNode *curr = head;
	// empty list
	if (curr == NULL) return -1;

	// create new list
	int index = 0;
	while (curr != NULL)
	{
		insertNode(ptrNewHead, index, curr->num);
		index++;
		curr = curr->next;
	}

	// reverse new list
	curr = *ptrNewHead;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	} 
	*ptrNewHead = prev;
	return 0;
}

