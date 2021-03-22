//
//  LinkedList.cpp
//  LinkedList
//
//  Created by Gabriel Robinson on 3/19/21.
//
#include "LinkedList.h"
#include <stdio.h>

LinkedList::LinkedList() { }

LinkedList::~LinkedList() {
    
}

void LinkedList::pushBack(int value) {
    if (this->headNode == NULL) {
        this->headNode = new LinkedListNode();
        this->headNode->value = value;
    } else {
        LinkedListNode* current = this->headNode;
        while(current->next != NULL) current = current->next;
        current->next = new LinkedListNode();
        current->next->value = value;
    }
    
}

void LinkedList::remove(int value) {
    
}

void LinkedList::contains(int value) {
    
}
