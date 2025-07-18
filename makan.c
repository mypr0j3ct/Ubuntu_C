#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
    char name[20];
    char house[20];
    struct Student *next;
} Student;

int main()
{
    // Create linked list nodes
    Student *head = malloc(sizeof(Student));
    strcpy(head->name, "Hermione");
    strcpy(head->house, "Gryffindor");

    head->next = malloc(sizeof(Student));
    strcpy(head->next->name, "Harry");
    strcpy(head->next->house, "Gryffindor");

    head->next->next = malloc(sizeof(Student));
    strcpy(head->next->next->name, "Ron");
    strcpy(head->next->next->house, "Gryffindor");

    head->next->next->next = malloc(sizeof(Student));
    strcpy(head->next->next->next->name, "Draco");
    strcpy(head->next->next->next->house, "Slytherin");
    head->next->next->next->next = NULL;

    // Access Hermione’s house
    Student *current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, "Hermione") == 0)
        {
            printf("%s\n", current->house); // Output: Gryffindor
            break;
        }
        current = current->next;
    }

    // Free memory
    while (head != NULL)
    {
        Student *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}