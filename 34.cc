#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};


void createLoop(Node* head, int pos) {
    if (pos == 0) return;
    
    Node* loopNode = head;
    for (int i = 1; i < pos; i++) {
        if (loopNode->next)
            loopNode = loopNode->next;
        else
            return;
    }

    Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    tail->next = loopNode;
}


bool removeLoop(Node* head) {
    if (!head || !head->next) return true;

    Node* slow = head;
    Node* fast = head;

  
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) break;
    }


    if (slow != fast) return true;


    slow = head;
    Node* prev = NULL;

 
    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
        fast->next = NULL;
        return true;
    }

    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = NULL;
    return true;
}


Node* createList(const vector<int>& vals) {
    if (vals.empty()) return NULL;

    Node* head = new Node(vals[0]);
    Node* curr = head;

    for (int i = 1; i < vals.size(); ++i) {
        curr->next = new Node(vals[i]);
        curr = curr->next;
    }

    return head;
}


bool hasLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}


int main() {
    vector<int> values;
    int x;
    while (cin.peek() != '\n' && cin >> x) {
        values.push_back(x);
    }

    int pos;
    cin >> pos;

    Node* head = createList(values);
    createLoop(head, pos);

  
    removeLoop(head);

  
    bool stillHasLoop = hasLoop(head);

    cout << (stillHasLoop ? "false" : "true") << endl;

    return 0;
}
