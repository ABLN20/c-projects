#ifndef _EC_LIST_NODE_H
#define _EC_LIST_NODE_H

#include <iostream>

// Class for linked list node
class ECListNode
{
public:
  ECListNode() : value(0), next(nullptr) {}
  ECListNode *GetNext() const { return next; }
  void SetNext(ECListNode *pn) { next = pn; }
  int GetValue() const { return value; }
  void SetValue(int v) { value = v; }

private:
  // ???
  int value;
  ECListNode *next;
};

#endif
