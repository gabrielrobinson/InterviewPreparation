//
//  LinkedList.h
//  LinkedList
//
//  Created by Gabriel Robinson on 3/19/21.
//

#ifndef LinkedList_h
#define LinkedList_h

struct LinkedListNode {
public:
    int value;
    LinkedListNode* next;
};

class LinkedList {
private:
    LinkedListNode* headNode;
public:
    LinkedList();
    ~LinkedList();
    void PushBack(int value);
    bool Remove(int value);
    bool Contains(int value);
};

#endif /* LinkedList_h */
