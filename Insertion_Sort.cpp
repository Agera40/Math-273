#include <cstddef>
#include <iostream>

template <typename T>
struct node {
    T key;
    node* next = nullptr;
    node* prev = nullptr;
};

template <typename T>
node<T>* push_front(node<T>*& front, const T& key) {
    node<T>* new_node = new node<T>{ key, front->next, front };
    front->next->prev = new_node;
    front->next = new_node;
    return new_node;
}

template <typename T>
node<T>* push_back(node<T>*& back, const T& key){
    node<T>* new_node = new node<T>{ key, back, back->prev };
    back->prev->next = new_node;
    back->prev = new_node;
    return new_node;
}

template <typename T>
void delete_list(node<T>* front) {
    while (front) {
        node<T>* temp = front;
        front = front->next;
        delete temp;
    }
}

int main() {
    auto front_end = new node<int>{};
    auto back_end = new node<int>{};
    front_end->next = back_end;
    back_end->prev = front_end;

    for (int n : {3, 5, 133}) push_back(back_end, n);
    auto p = push_back(back_end, 23);
    for (int n : {15, 35, 25}) push_back(back_end, n);

    // Print the Key
    std::cout << p->key << std::endl;

    // Print the Initial list
    std::cout << "Initial list:\n";
    for (auto i = front_end->next; i != back_end; i = i->next) {
        std::cout << i->key << '\n';
    }

    // Find where to insert p
    auto target = p->prev;
    while (target != front_end && target->key > p->key) {
        target = target->prev;
    }

    // Insert after target
    p->prev->next = p->next;
    p->next->prev = p->prev;
    target->next->prev = p;
    p->next = target->next;
    target->next = p;
    p->prev = target;

    // Apply insertion sort
    node<int>* current = p->next;
    while (current != back_end) {
        node<int>* next_node = current->next;
        target = current->prev;
        while (target != front_end && target->key > current->key) {
            target = target->prev;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        current->prev = target;
        current->next = target->next;
        target->next->prev = current;
        target->next = current;
        current = next_node;
    }

    // Print the sorted list
    std::cout << "\nSorted List:\n";
    for (auto i = front_end->next; i != back_end; i = i->next) {
        std::cout << i->key << '\n';
    }
}
