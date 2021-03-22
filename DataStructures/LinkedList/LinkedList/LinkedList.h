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
    void pushBack(int value);
    void remove(int value);
    void contains(int value);
}

#endif /* LinkedList_h */
