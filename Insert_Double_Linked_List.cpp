DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data){
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
    DoublyLinkedListNode* tempList = llist;

    if (llist == nullptr){
        return newNode;
    }

    if (data <= llist->data) {
        newNode->next = llist;
        llist->prev = newNode;
        return newNode;
    }

    while(tempList->next != nullptr && tempList->next->data < data){
        tempList = tempList->next;
    }

    newNode->next = tempList->next;
    newNode->prev = tempList;

    if(tempList->next != nullptr) {
        tempList->next->prev = newNode;
    }

    tempList->next = newNode;

    return llist;
}
