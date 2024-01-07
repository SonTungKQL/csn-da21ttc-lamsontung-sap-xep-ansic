#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** headRef, int newData) 
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void printList(Node *node) 
{
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Node* head) 
{
    bool swapped;
    Node *ptr1;
    Node *lptr = nullptr;

    if (head == nullptr) return;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(&ptr1->data, &ptr1->next->data);
                swapped = true;
				printList(head);
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

Node* getLastNode(Node* cur) 
{
    while (cur != nullptr && cur->next != nullptr)
        cur = cur->next;
    return cur;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node *prev = nullptr, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == nullptr) (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == nullptr) (*newHead) = pivot;

    (*newEnd) = tail;

	printList(*newHead);
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) 
{
    if (!head || head == end)
        return head;

    Node *newHead = nullptr, *newEnd = nullptr;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = nullptr;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getLastNode(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node** headRef) 
{
    (*headRef) = quickSortRecur(*headRef, getLastNode(*headRef));
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
		for (int i = 0; i < n; ++i) {
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
}

void heapSort(vector<int>& arr, int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void convertListToArray(Node* head, vector<int>& arr) 
{
    while (head != nullptr) {
        arr.push_back(head->data);
        head = head->next;
    }
}

Node* convertArrayToList(vector<int>& arr) 
{
    Node* newHead = nullptr;
    for (int i = arr.size() - 1; i >= 0; i--) {
        push(&newHead, arr[i]);
    }
    return newHead;
}

int main() 
{
    Node *head = nullptr;

    // Thêm dữ liệu vào danh sách liên kết
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);

    cout << "Danh sách liên kết trước khi sắp xếp:\n";
    printList(head);

    // Áp dụng BubbleSort
    bubbleSort(head);
    cout << "Danh sách liên kết sau BubbleSort:\n";
    printList(head);

    // Reset danh sách và thêm dữ liệu để thử QuickSort
    head = nullptr;
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);

    quickSort(&head);
    cout << "Danh sách liên kết sau QuickSort:\n";
    printList(head);

    head = nullptr;
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);

    vector<int> arr;
    convertListToArray(head, arr);
    heapSort(arr, arr.size());
    head = convertArrayToList(arr);

    cout << "Danh sách liên kết sau HeapSort:\n";
    printList(head);

    return 0;
}
