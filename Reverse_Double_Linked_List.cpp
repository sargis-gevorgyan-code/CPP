DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* tempList = llist;
    DoublyLinkedListNode* tempNode = nullptr;

    while (tempList != nullptr) {
        tempNode = tempList->prev;

        tempList->prev = tempList->next;
        tempList->next = tempNode;

        tempList = tempList->prev;
    }

    if (tempNode != nullptr) {
        llist = tempNode->prev;
    }

    return llist;
}
