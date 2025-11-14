// Queues.cpp : Interactive menu for Queue<T> (choose type, then operate)
#include "Headers.h"
#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
bool read_value_from_stdin(T& out) {
    // Special-case string to allow spaces
    if constexpr (is_same_v<T, string>) {
        string line;
        getline(cin >> ws, line);
        out = line;
        return true;
    } else if constexpr (is_same_v<T, char>) {
        string token;
        if (!(cin >> token)) return false;
        out = token.empty() ? '\0' : token[0];
        return true;
    } else {
        // Numeric or other types that support operator>>
        T tmp;
        if (!(cin >> tmp)) {
            // clear fail state and consume invalid token
            cin.clear();
            string bad;
            getline(cin, bad);
            return false;
        }
        out = tmp;
        return true;
    }
}

template <typename T>
void display_using_queue_ops(Queue<T>& q) {
    // Print all elements using only queue public functions (front, push, pop, size)
    size_t n = q.size();
    for (size_t i = 0; i < n; ++i) {
        // print front
        if constexpr (is_same_v<T, string>) {
            cout << q.front();
        } else {
            cout << q.front();
        }
        if (i + 1 < n) cout << ' ';
        // rotate
        q.push(q.front());
        q.pop();
    }
    cout << '\n';
}

template <typename T>
void run_queue_menu() {
    Queue<T> q;
    for (;;) {
        cout << "\n--- Queue Menu (type: " 
             << (is_same_v<T, int> ? "int" :
                 is_same_v<T, double> ? "double" :
                 is_same_v<T, string> ? "string" :
                 is_same_v<T, char> ? "char" : "unknown")
             << ") ---\n";
        cout << "1) push\n2) pop\n3) front\n4) display all (use only queue ops)\n5) size\n6) empty\n7) move_to_rear\n8) clear queue\n9) back to type menu\nChoose option: ";
        int opt;
        if (!(cin >> opt)) {
            cin.clear();
            string junk;
            getline(cin, junk);
            cout << "Invalid input.\n";
            continue;
        }

        if (opt == 1) {
            cout << "Enter value to push: ";
            T val;
            if (!read_value_from_stdin(val)) {
                cout << "Invalid value. Try again.\n";
                continue;
            }
            q.push(val);
            cout << "Pushed.\n";
        } else if (opt == 2) {
            try {
                q.pop();
                cout << "Popped front element.\n";
            } catch (const exception& e) {
                cout << "Error: " << e.what() << '\n';
            }
        } else if (opt == 3) {
            try {
                cout << "Front: " << q.front() << '\n';
            } catch (const exception& e) {
                cout << "Error: " << e.what() << '\n';
            }
        } else if (opt == 4) {
            if (q.empty()) {
                cout << "(queue empty)\n";
            } else {
                cout << "Queue contents: ";
                display_using_queue_ops(q);
            }
        } else if (opt == 5) {
            cout << "Size: " << q.size() << '\n';
        } else if (opt == 6) {
            cout << (q.empty() ? "Queue is empty\n" : "Queue is not empty\n");
        } else if (opt == 7) {
            try {
                q.move_to_rear();
                cout << "Moved front element to rear.\n";
            } catch (const exception& e) {
                cout << "Error: " << e.what() << '\n';
            }
        } else if (opt == 8) {
            // clear by popping until empty
            while (!q.empty()) q.pop();
            cout << "Cleared queue.\n";
        } else if (opt == 9) {
            // return to type selection
            return;
        } else {
            cout << "Unknown option.\n";
        }
    }
}

// Demo: iterative linear search for last occurrence (int vector)
static void demo_last_occurrence_linear_int() {
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n < 0) {
        cin.clear();
        string junk;
        getline(cin, junk);
        cout << "Invalid count.\n";
        return;
    }
    vector<int> v;
    v.reserve(static_cast<size_t>(n));
    cout << "Enter " << n << " integers separated by spaces or newlines:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        if (!(cin >> x)) {
            cin.clear();
            string bad;
            getline(cin, bad);
            cout << "Invalid input.\n";
            return;
        }
        v.push_back(x);
    }
    cout << "Enter target value: ";
    int target;
    if (!(cin >> target)) {
        cin.clear();
        string bad;
        getline(cin, bad);
        cout << "Invalid target.\n";
        return;
    }
    int idx = last_occurrence_linear(v, target);
    if (idx == -1) cout << "Target not found.\n";
    else cout << "Last occurrence index: " << idx << '\n';
}

// Demo: in-place insertion sort for std::list<int>
static void demo_insertion_sort_list() {
    cout << "Enter number of elements for list: ";
    int n;
    if (!(cin >> n) || n < 0) {
        cin.clear();
        string junk;
        getline(cin, junk);
        cout << "Invalid count.\n";
        return;
    }
    list<int> lst;
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        if (!(cin >> x)) {
            cin.clear();
            string bad;
            getline(cin, bad);
            cout << "Invalid input.\n";
            return;
        }
        lst.push_back(x);
    }
    insertionSortListInPlace(lst);
    cout << "Sorted list: ";
    for (int v : lst) cout << v << ' ';
    cout << '\n';
}

int main() {
    for (;;) {
        cout << "\nChoose queue data type:\n";
        cout << "1) int\n2) double\n3) string\n4) char\n5) Demo: last_occurrence_linear (int vector)\n6) Demo: insertionSortListInPlace (int list)\n7) Quit\nSelection: ";
        int sel;
        if (!(cin >> sel)) {
            cin.clear();
            string junk;
            getline(cin, junk);
            cout << "Invalid input.\n";
            continue;
        }

        if (sel == 1) {
            run_queue_menu<int>();
        } else if (sel == 2) {
            run_queue_menu<double>();
        } else if (sel == 3) {
            // consume newline and run string menu
            run_queue_menu<string>();
        } else if (sel == 4) {
            run_queue_menu<char>();
        } else if (sel == 5) {
            demo_last_occurrence_linear_int();
        } else if (sel == 6) {
            demo_insertion_sort_list();
        } else if (sel == 7) {
            cout << "Exiting.\n";
            break;
        } else {
            cout << "Invalid selection.\n";
        }
    }

    return 0;
}