#include "ECLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/* get the length of the linked list: how many nodes in the linked list */
/* pHead: head node pointer to the linked list */
/* return the number of nodes of the linked list pointed by pHead */
int ECGetLinkedListLength(struct ECLinkedListNode *pHead )
{
  /* your code here */
  int count = 0;
  while (pHead != NULL)
  {
    count+=1;
    pHead = pHead->pNext;
  }
  return count;
}

/* delete all nodes with a specific value from the linked list */
/* input: pHead: head node pointer to the linked list which to be processed */
/* input: val: all nodes with value equal to val should be deleted */
/* output: the pointer to the head ndoe of the linked list after the delete operation */
struct ECLinkedListNode *ECLinkedListDeleteVal(struct ECLinkedListNode *pHead, int val)
{
  /* your code here */
  struct ECLinkedListNode* headNode = pHead;
  struct ECLinkedListNode* currentNode = pHead;
  while (true)
  {
    if (headNode == NULL)
    {
      return NULL;
    }
    if (headNode->value == val)
    {
      headNode = headNode->pNext;
    }
    else
    {
      break;
    }
  }
  currentNode = headNode;
  while (currentNode != NULL)
  {
    if (currentNode->pNext != NULL && currentNode->pNext->value == val)
    {
      currentNode->pNext = currentNode->pNext->pNext;
    }
    else
    {
      currentNode = currentNode->pNext;
    }
  }
  return headNode;
}
