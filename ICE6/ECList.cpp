#include "ECListNode.h"
#include "ECList.h"

// Linked list 
ECList :: ECList() 
{
    pHead = nullptr;
    numNodes = 0;
}
  
// insert node with value val after a node
// if node is NULL, insert to the front
void ECList :: Insert(int val, ECListNode *pPre)
{
    ECListNode *newNode = new ECListNode(); 
    newNode->SetValue(val);

    if (pPre == nullptr)
    {
        newNode->SetNext(pHead);
        pHead = newNode;
    }
    else
    {
        newNode->SetNext(pPre->GetNext());
        pPre->SetNext(newNode);
    }
    numNodes++;
}

// delete a node
void ECList :: Delete(ECListNode *pNode)
{
    ECListNode *previous = pHead;
    ECListNode *current = pHead->GetNext();
    if (pHead == pNode)
    {
        pHead = pHead->GetNext();
        delete pNode;
        numNodes--;
        return;
    }

    while (current != nullptr)
    {
        if(current == pNode)
        {
            previous->SetNext(current->GetNext());
            delete pNode;
            numNodes--;
            return;
        }
        previous = previous->GetNext();
        current = current->GetNext();
    }
    return;
}

// get a node with value; if multiple nodes with the same value, return the first from head
ECListNode * ECList::GetNode(int val)
{
    ECListNode *current = pHead;
    while(current != nullptr)
    {
        if (current->GetValue() == val)
        {
            return current;
        }
        current = current->GetNext(); 
    }
    return nullptr;
}

// get the number of nodes in the list
int ECList:: GetSize() const
{
    return numNodes;
}

