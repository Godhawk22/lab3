#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct node {
    char inf[256];       // �������� ����������
    int priority;        // ���������
    struct node* next;   // ������ �� ��������� �������
};

struct node* head = NULL, * last = NULL;

// �������
void spstore_priority(void);
void review(void);
struct node* get_struct_priority(void);

// ������� �������� �������� � �����������
struct node* get_struct_priority(void) {
    struct node* p = NULL;
    char s[256];
    int priority;

    if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) {
        printf("������ ��� ������������� ������\n");
        exit(1);
    }

    printf("������� �������� �������: \n");
    scanf("%s", s);
    strcpy(p->inf, s);

    printf("������� ��������� �������: \n");
    scanf("%d", &priority);
    p->priority = priority;

    p->next = NULL;
    return p; // ���������� ��������� �� ��������� �������
}

// ������� ���������� �������� � ������ ����������
void spstore_priority(void) {
    struct node* p = NULL;
    p = get_struct_priority();

    if (head == NULL) { // ���� ������ ����, ������ ����� ������� �������
        head = p;
        last = p;
    }
    else if (p->priority > head->priority) { // ���� ������� ����� ������� ���������, ��� ������� ������
        p->next = head;
        head = p;
    }
    else {
        // ���� �����, ���� �������� ������� �� ����������
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
// ������� ��������� ����������� ������
void review(void) {
    struct node* struc = head;
    if (head == NULL) {
        printf("������ ����\n");
        return;
    }
    while (struc) {
        printf("��� - %s, ��������� - %d\n", struc->inf, struc->priority);
        struc = struc->next;
    }
    return;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    spstore_priority(); // ��������� ������� � �����������
    spstore_priority(); // ��������� ��� ���� �������
    review();           // ������������� �������
    return 0;
}