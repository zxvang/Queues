#pragma once

#include <stdexcept>
#include <vector>
#include <list>

using namespace std;

// Template circular-array queue
template <typename T>
class Queue {
public:
    explicit Queue(size_t initial_capacity = 8);
    ~Queue();

    void push(const T& item);
    void pop();
    T& front();
    const T& front() const;
    bool empty() const noexcept { return num_items == 0; }
    size_t size() const noexcept { return num_items; }
    
    // Move the element at front to the rear using only push, front, pop.
    // Throws if queue is empty.
    void move_to_rear();

private:
    void reallocate();

    T* items = nullptr;
    size_t capacity = 0;
    size_t num_items = 0;
    size_t front_index = 0;
    size_t rear_index = 0;
};

// Definitions (must be in header because this is a template)

template <typename T>
Queue<T>::Queue(size_t initial_capacity)
    : items(nullptr), capacity(0), num_items(0), front_index(0), rear_index(0)
{
    if (initial_capacity == 0) initial_capacity = 8;
    capacity = initial_capacity;
    items = new T[capacity];
    front_index = 0;
    rear_index = capacity - 1; // first push moves to 0
}

template <typename T>
Queue<T>::~Queue() {
    delete[] items;
}

template <typename T>
void Queue<T>::reallocate() {
    size_t new_capacity = (capacity == 0) ? 8 : capacity * 2;
    T* new_items = new T[new_capacity];

    for (size_t i = 0; i < num_items; ++i) {
        new_items[i] = items[(front_index + i) % capacity];
    }

    delete[] items;
    items = new_items;
    capacity = new_capacity;
    front_index = 0;
    rear_index = (num_items == 0) ? (capacity - 1) : (num_items - 1);
}

template <typename T>
void Queue<T>::push(const T& item) {
    if (num_items == capacity) {
        reallocate();
    }
    rear_index = (rear_index + 1) % capacity;
    items[rear_index] = item;
    ++num_items;
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) {
        throw underflow_error("Queue::pop() called on empty queue");
    }
    front_index = (front_index + 1) % capacity;
    --num_items;
    if (num_items == 0) {
        front_index = 0;
        rear_index = capacity - 1;
    }
}

template <typename T>
T& Queue<T>::front() {
    if (empty()) {
        throw underflow_error("Queue::front() called on empty queue");
    }
    return items[front_index];
}

template <typename T>
const T& Queue<T>::front() const {
    if (empty()) {
        throw underflow_error("Queue::front() called on empty queue");
    }
    return items[front_index];
}

template <typename T>
void Queue<T>::move_to_rear() {
    if (empty()) {
        throw underflow_error("Queue::move_to_rear() called on empty queue");
    }
    T tmp = front();
    push(tmp);
    pop();
}

// Recursive linear search — return index of last occurrence of target (or -1)
template <typename T>
int linear_search(const vector<T>& items, const T& target, size_t pos_first) {
    if (pos_first >= items.size())
        return -1;
    int found_in_rest = linear_search(items, target, pos_first + 1);
    if (found_in_rest != -1)
        return found_in_rest;
    if (target == items[pos_first])
        return static_cast<int>(pos_first);
    else
        return -1;
}
