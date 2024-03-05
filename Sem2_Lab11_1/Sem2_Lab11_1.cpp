#include <iostream>
#include <string>

using namespace std;

// Структура элемента списка
struct Node {
    string key;
    Node* prev;
    Node* next;
};

// Функция для создания нового узла
Node* createNode(const string& key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Функция для добавления нового элемента в конец списка
void appendNode(Node*& head, const string& key) {
    Node* newNode = createNode(key);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Функция для удаления элемента с заданным ключом
void deleteNode(Node*& head, const string& key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            if (current == head) {
                head = current->next;
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

// Функция для добавления K элементов после элемента с заданным ключом
void insertKNodesAfter(Node*& head, const string& key, int K) {
    Node* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            for (int i = 0; i < K; i++) {
                Node* newNode = createNode("Зверь");
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next != nullptr) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                current = newNode;
            }
            return;
        }
        current = current->next;
    }
}

// Функция для печати списка
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    Node* head = nullptr;

    // Добавляем элементы в список
    appendNode(head, "Свин");
    appendNode(head, "Лис");
    appendNode(head, "Заяц");
    appendNode(head, "Медведь");
    appendNode(head, "Морж");

    cout << "Исходный список:" << endl;
    printList(head);

    // Удаляем элемент с заданным ключом
    deleteNode(head, "Лис");
    cout << "Список после удаления элемента с ключом 'Лис':" << endl;
    printList(head);

    // Добавляем 2 элемента после элемента с заданным ключом
    insertKNodesAfter(head, "Заяц", 2);
    cout << "Список после добавления 2 элементов после элемента с ключом 'Заяц':" << endl;
    printList(head);

    return 0;
}