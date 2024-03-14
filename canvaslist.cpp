#include "canvaslist.h"

#include <iostream>
#include <string>

using namespace std;

CanvasList::CanvasList() {
    list_size = 0;
    list_front = nullptr;
}

CanvasList::CanvasList(const CanvasList& other) {
    // Initialize list_front and list_size
    list_front = nullptr;
    list_size = 0;

    // If other list is empty, return
    if (other.list_front == nullptr) {
    return;
    }

    Shape* toCopy = nullptr;
    ShapeNode* otherNode = other.list_front;

    while (otherNode) {
        toCopy = otherNode->value->copy();
        push_back(toCopy);
        otherNode = otherNode->next;
    }
}

CanvasList& CanvasList::operator=(const CanvasList& other) {
    if (this == &other) {
        return *this;
    }

    clear();
    Shape* toCopy = nullptr;
    ShapeNode* otherNode = other.list_front;

    while (otherNode) {
        toCopy = otherNode->value->copy();
        push_back(toCopy);
        otherNode = otherNode->next;
    }

    return *this;
}

CanvasList::~CanvasList() {
    clear();
}

void CanvasList::clear() {
    while (list_front != nullptr) {
        ShapeNode* current = list_front;
        list_front = list_front->next;
        delete current->value;
        delete current;
        list_size--;
    }
}

void CanvasList::insert_after(int index, Shape* s) {
    if (index < 0 || index >= list_size) {
        return; // Invalid index, do nothing
    }
    
    ShapeNode* newNode = new ShapeNode();
    newNode->value = s;
    newNode->next = nullptr;
    
    if (list_size == 0) {
        list_front = newNode;
    }
    else {
        // Go to index node, update back pointer to point to newNode
        ShapeNode* current = list_front;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    list_size++;
}

void CanvasList::push_front(Shape* s) {
    // Create new ShapeNode, set value and next pointer
    ShapeNode* newNode = new ShapeNode();
    newNode->value = s;

    newNode->next = list_front;

    // Update front node and increment size
    list_front = newNode;
    list_size++;
}

void CanvasList::push_back(Shape* s) {
    // Create new ShapeNode, insert Shape value and link it to current front node
    ShapeNode* newNode = new ShapeNode();
    newNode->value = s;
    
    if (list_front == nullptr) {
        list_front = newNode;
    }
    else {
        // Go to last node, update back pointer to point to newNode
        ShapeNode* current = list_front;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    list_size++;
}

void CanvasList::remove_at(int index) {
    if (index < 0 || index >= list_size) {
        return;
    }

    if (index == 0) {
        // Remove the first element
        if (list_front) {
            ShapeNode* temp = list_front;
            list_front = list_front->next;
            list_size--;
            delete temp->value;
            delete temp;
        }
    }
    else {
        // Traverse the list to find the element at the specified index
        ShapeNode* current = list_front;
        for (int i = 0; i < index - 1 && current; ++i) {
            current = current->next;
        }

        if (current && current->next) {
            // Remove the element at the specified index
            ShapeNode* temp = current->next;
            current->next = current->next->next;
            delete temp->value;
            delete temp;
            list_size--;
        }
    }
}

void CanvasList::remove_every_other() {
    ShapeNode* current = list_front;
    while (current && current->next) {
        ShapeNode* temp = current->next;
        current->next = current->next->next;
        delete temp->value;
        delete temp;
        current = current->next;
        list_size--;
    }
}

Shape* CanvasList::pop_front() {
    if (list_size == 0) {
        return nullptr;
    }

    ShapeNode* temp = list_front;
    Shape* popVal = temp->value;

    list_front = list_front->next;
    delete temp;
    list_size--;

    return popVal;
}

Shape* CanvasList::pop_back() {
    if (list_size == 0) {
        return nullptr;
    }

    // Move the pointer to the second-last node
    ShapeNode* prev = nullptr;
    ShapeNode* currrent = list_front;

    while (currrent->next != nullptr) {
        prev = currrent;
        currrent = currrent->next;
    }

    // Handle the last node (currrent) being the only node
    if (prev == nullptr) {
        list_front = nullptr;
    }
    else {
        prev->next = nullptr;
    }

    // Extract the value and delete the node
    Shape* popVal = currrent->value;
    delete currrent;

    list_size--;

    return popVal;
}

ShapeNode* CanvasList::front() const {
    return list_front;
}

bool CanvasList::empty() const {
    return list_size == 0;
}

int CanvasList::size() const {
    return list_size;
}

int CanvasList::find(int x, int y) const {
    ShapeNode* current = list_front;
    int index = 0;

    while (current) {
        if (current->value->getX() == x && current->value->getY() == y) {
            return index;
        }

        current = current->next;
        index++;
    }

    return -1;
}

Shape* CanvasList::shape_at(int index) const {
    if (index < 0 || index >= list_size) {
        return nullptr;
    }

    ShapeNode* current = list_front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->value;
}

void CanvasList::draw() const {
    ShapeNode* current = list_front;
    while (current->next) {
        cout << current->value->as_string() << endl;
        current = current->next;
    }
}

void CanvasList::print_addresses() const {
    ShapeNode* current = list_front;
    while (current->next) {
        cout << "Node Address: " << &current << "\tShape Address: " << &current->value << endl;
        current = current->next;
    }
}
