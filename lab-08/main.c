#include <stdio.h>
#include "linked_list.h"

int main() {

    Node* number1=covertIntToList();
    Node* number2=covertIntToList();
    Node *uj=addLists(number1,number2);
    printList(uj );
    return 0;
}
