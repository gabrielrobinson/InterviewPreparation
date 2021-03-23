//
//  main.cpp
//  LinkedList
//
//  Created by Gabriel Robinson on 3/19/21.
//

#include <iostream>
#include "LinkedList.h"

int main(int argc, const char * argv[]) {
    LinkedList list;
    list.PushBack(0);
    assert(list.Contains(0));
    assert(list.Remove(0));
    assert(!list.Contains(0));
    list.PushBack(0);
    list.PushBack(1);
    list.PushBack(2);
    assert(list.Contains(0));
    assert(list.Contains(1));
    assert(list.Contains(2));
    list.Remove(1);
    assert(list.Contains(0));
    assert(!list.Contains(1));
    assert(list.Contains(2));
    std::cout << "Test passed" << std::endl;
    return 0;
}
