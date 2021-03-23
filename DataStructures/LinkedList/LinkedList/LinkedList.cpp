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
    if (this->headNode != NULL) {
        LinkedListNode* previousNode = NULL;
        LinkedListNode* currentNode = this->headNode;
        while (currentNode->next != NULL) {
            previousNode = currentNode;
            currentNode = currentNode->next;
            delete previousNode;
        }
    }
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
    if (this->headNode != NULL && this->headNode->value == value) {
        LinkedListNode* nodeToDelete = headNode;
        if (nodeToDelete->next != NULL) this->headNode = nodeToDelete->next;
        delete nodeToDelete;
    } else {
        LinkedListNode* previousNode = NULL;
        LinkedListNode* currentNode = this->headNode;
        if (currentNode != NULL) {
            while (currentNode->next != NULL) {
                previousNode = currentNode;
                currentNode = currentNode->next;
                if (currentNode->value == value) {
                    previousNode->next = currentNode->next;
                    delete currentNode;
                }
            }
        }
    }
}

bool LinkedList::contains(int value) {
    if (this->headNode != NULL) {
        if (this->headNode->value == value) {
            return true;
        } else {
            LinkedListNode* node = this->headNode;
            while (node->next != NULL) {
                node = node->next;
                if (node->value == value) return true;
            }
        }
    }
    return false;
}
