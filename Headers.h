#pragma once

#include <stdexcept>
#include <vector>
#include <list>

using namespace std;

// Template circular-array queue (header-only)
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
    // Use only push, front, pop as required
    T tmp = front();
    push(tmp);
    pop();
}

// Q2: Recursive search — return index of last occurrence of target (or -1)
template <typename T>
int last_occurrence_recursive(const std::vector<T>& v, const T& target, size_t idx = 0) {
    if (idx >= v.size()) return -1;
    int found_in_rest = last_occurrence_recursive(v, target, idx + 1);
    if (found_in_rest != -1) return found_in_rest;
    return (v[idx] == target) ? static_cast<int>(idx) : -1;
}

// Q3: Insertion sort for std::list<int> (linked list version)
inline void insertionSortList(std::list<int>& lst) {
    if (lst.empty()) return;
    std::list<int> sorted;
    for (int value : lst) {
        auto it = sorted.begin();
        while (it != sorted.end() && *it < value) ++it;
        sorted.insert(it, value);
    }
    lst.swap(sorted);
}

// In-place insertion sort for std::list<int> using splice (stable, no extra list)
inline void insertionSortListInPlace(std::list<int>& lst) {
    if (lst.empty()) return;
    auto it = lst.begin();
    ++it; // start from second element
    while (it != lst.end()) {
        auto curr = it++;
        // find insertion position: after any elements <= *curr to preserve stability
        auto insert_pos = lst.begin();
        while (insert_pos != curr && *insert_pos <= *curr) ++insert_pos;
        if (insert_pos != curr) {
            lst.splice(insert_pos, lst, curr); // move current before insert_pos
        }
    }
}
// Iterative linear search for last occurrence (safer than the recursive version)
template <typename T>
int last_occurrence_linear(const std::vector<T>& v, const T& target) {
    if (v.empty()) return -1;
    // use signed type for indexing from end
    long long n = static_cast<long long>(v.size());
    for (long long i = n - 1; i >= 0; --i) {
        if (v[static_cast<size_t>(i)] == target) return static_cast<int>(i);
    }
    return -1;
}