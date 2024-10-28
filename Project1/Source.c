#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct node {
    char inf[256];       // полезная информация
    int priority;        // приоритет
    struct node* next;   // ссылка на следующий элемент
};

struct node* head = NULL, * last = NULL;

// Функции
void spstore_priority(void);
void review(void);
struct node* get_struct_priority(void);

// Функция создания элемента с приоритетом
struct node* get_struct_priority(void) {
    struct node* p = NULL;
    char s[256];
    int priority;

    if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }

    printf("Введите название объекта: \n");
    scanf("%s", s);
    strcpy(p->inf, s);

    printf("Введите приоритет объекта: \n");
    scanf("%d", &priority);
    p->priority = priority;

    p->next = NULL;
    return p; // возвращаем указатель на созданный элемент
}

// Функция добавления элемента с учетом приоритета
void spstore_priority(void) {
    struct node* p = NULL;
    p = get_struct_priority();

    if (head == NULL) { // Если список пуст, делаем новый элемент головой
        head = p;
        last = p;
    }
    else if (p->priority > head->priority) { // Если элемент имеет больший приоритет, чем текущая голова
        p->next = head;
        head = p;
    }
    else {
        // Ищем место, куда вставить элемент по приоритету
        struct node* current = head;
        while (current->next != NULL && current->next->priority >= p->priority) {
            current = current->next;
        }
        p->next = current->next;
        current->next = p;
        if (p->next == NULL) {
            last = p;
        }
    }
    return;
}
// Функция просмотра содержимого списка
void review(void) {
    struct node* struc = head;
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }
    while (struc) {
        printf("Имя - %s, Приоритет - %d\n", struc->inf, struc->priority);
        struc = struc->next;
    }
    return;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    spstore_priority(); // Добавляем элемент с приоритетом
    spstore_priority(); // Добавляем еще один элемент
    review();           // Просматриваем очередь
    return 0;
}