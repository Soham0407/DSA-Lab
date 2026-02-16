#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* rotateDLL(Node* head, int k) {
    if (!head || k == 0)
        return head;

    Node* curr = head;
    int count = 1;

    // Move to k-th node
    while (count < k && curr) {
        curr = curr->next;
        count++;
    }

    if (!curr)
        return head;

    Node* kthNode = curr;
    Node* newHead = kthNode->next;

    if (!newHead)
        return head;

    newHead->prev = nullptr;
    kthNode->next = nullptr;

    // Move to last node
    Node* tail = newHead;
    while (tail->next)
        tail = tail->next;

    // Attach old head at the end
    tail->next = head;
    head->prev = tail;

    return newHead;
}

void insertEnd(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertEnd(head, x);
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    head = rotateDLL(head, k);
    printList(head);

    return 0;
}
