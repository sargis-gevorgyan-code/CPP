SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position){
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    SinglyLinkedListNode* tempList = llist;

    if (position == 0){
        newNode->next = llist;
        return newNode;
    }

    for (int i = 0; i < position - 1; i++) {
        tempList = tempList->next;
    }
    newNode->next = tempList->next;
    tempList->next = newNode;

    return llist;
}
