template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    }
    else {
        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = n;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    head = nullptr;
    Node* srcNode = copyObj.head;
    Node** link = &head;  // pointer to the mem address of head, *link actually == head, below *link will == ->next

    while (srcNode) {  
        *link = new Node(srcNode->value, nullptr);   // current "next" pointer (starting at head) is set to new node, via deref
        link = &((*link)->next);  // set pointerpointer to point the address of the newNode's next pointer

        srcNode = srcNode->next;
        ++this->length;
    }
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    
    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    // technically length check not needed, loop will just put at end. Unless we want to constrain user/driver
    if (position < 0 || position > this->length) throw string("Invalid position for inserting element");

    Node** link = &head;  // set pointer to the memory address of head pointer, not the pointer itself

    while (position > 0 && *link != nullptr) {  // neat...the loop just needs to run the correct number of times to find the position
        link = &((*link)->next);        // each loop, link is now pointing to address of the ->next pointer, deref for next, then return &
        --position;
    }

    Node* newNode = new Node(elem,*link);  // new node, pass it the pointer to next node (via deref **)

    *link = newNode;    // set current node's next pointer, to newNode (via deref **)

     ++this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    if (this->isEmpty()) {
        cout << "List is already empty" << endl;
        return;
    }
    if (position < 0 || position >= this->length) throw string("Invalid position passed for removing element");

    if (position == 0) {
        Node* removeMe = head;
        head = head->next;
        delete removeMe;
    }
    else {
        Node* removeMe = head;
        Node* prev = head;
        for (int i = 0; i < position-1; ++i) prev = prev->next;

        removeMe = prev->next;
        prev->next = removeMe->next;
        delete removeMe;    
        }

    --this->length;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
