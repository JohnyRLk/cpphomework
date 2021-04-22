#include <iostream>
template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
Node<T>* arrayToList(const T arr[], size_t size) {

    struct Node<T>* head;
    struct Node<T>* tmp1 = new Node<T>;
    tmp1->data = arr[0];
    tmp1->next = NULL;
    head = tmp1;

    for (int i = 1; i <= size; i++) {
        struct Node<T>* tmp2 = new Node<T>;
        tmp1->next = tmp2;
        tmp2->data = arr[i];
        tmp2->next = NULL;
        tmp1 = tmp2;

    }

    return head;

}

template <typename T, typename Pred>
void removeBad(Node<T>*& head, Pred p) {

    Node<T>* tmp;

    while (head != nullptr && p(head->data)) {
        std::cout << "DEL: " << head->data << " ";
        tmp = head->next;
        delete head;
        head = tmp;
    }

    if (head == nullptr) {
        return;
    }

    Node<T>* tmp_node1 = head;
    Node<T>* tmp_node2;

    while (tmp_node1 != nullptr) {
        tmp_node2 = tmp_node1->next;
        while (tmp_node2  != nullptr && p(tmp_node2->data)) {
            std::cout << "DEL: " << tmp_node2->data << " ";
            tmp = tmp_node2 ->next;
            delete tmp_node2;
            tmp_node2 = tmp;
        }

        tmp_node1->next = tmp_node2;
        tmp_node1 = tmp_node2;
    }
    std::cout << std::endl;
}
template <typename T>
void showList(const Node<T>* head) {
    if (head == nullptr) {
        std::cout << "Pusta lista" << " ";
    }
    else {
        while (head != nullptr) {
            std::cout << head->data << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
};
template <typename T>
void deleteList(Node<T>*& head) {
    struct Node<T>* tmp = new Node<T>;
    while (head != NULL) {
        std::cout << "DEL: " << head->data << " ";
        tmp = head;
        head = tmp->next;
        delete tmp;
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    size_t size = std::size(arr);
    Node<int>* head = arrayToList(arr, size);
    showList(head);
    removeBad(head, [](int n) {return n % 2 != 0; });
    showList(head);
    removeBad(head, [](int n) {return n < 5; });
    showList(head);
    removeBad(head, [](int n) {return n > 9; });
    showList(head);
    deleteList(head);
    showList(head);

}