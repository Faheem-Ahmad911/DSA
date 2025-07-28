void List::merge(List& list1, List& list2) {
    Node* t1 = list1.head;
    Node* t2 = list2.head;

    // Clear this list first
    head = nullptr;
    Node* tail = nullptr;

    while (t1 != nullptr && t2 != nullptr) {
        // Take node from list1
        if (head == nullptr) {
            head = t1;
            tail = t1;
        } else {
            tail->next = t1;
            tail = tail->next;
        }
        t1 = t1->next;

        // Take node from list2
        tail->next = t2;
        tail = tail->next;
        t2 = t2->next;
    }

    // Set ends and empty the other lists
    tail->next = nullptr;
    list1.head = nullptr;
    list2.head = nullptr;
}
