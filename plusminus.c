#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HoopsPlayer
{
    char name[63];
    int teamPoints;
    int oppPoints;
    int difference;
    HoopsPlayer *next;

} HoopsPlayer;

void sortList(HoopsPlayer **head)
{
    int is_sorted = 0;

    while (!is_sorted)
    {
        HoopsPlayer *curr = *head;
        HoopsPlayer *prev = NULL;
        is_sorted = 1;

        while (curr != NULL && curr->next != NULL)
        {
            HoopsPlayer *next = curr->next;

            if (curr->difference < next->difference || (curr->difference == next->difference && strcmp(curr->name, next->name) > 0))
            {
                is_sorted = 0;
                curr->next = next->next;
                next->next = curr;

                if (prev != NULL) {
                    prev->next = next;
                }
                else {
                    *head = next;
                }
                prev = next;
            }
            else {
                prev = curr;
                curr = next;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    HoopsPlayer *head = (HoopsPlayer *)malloc(sizeof(HoopsPlayer));
    HoopsPlayer *ptr = head;

    while (1)
    {
        HoopsPlayer *newPlayer = (HoopsPlayer *)malloc(sizeof(HoopsPlayer));
        if (fscanf(file, "%s %d %d", newPlayer->name, &newPlayer->teamPoints, &newPlayer->oppPoints) != 3)
        {
            free(newPlayer);
            break;
        }
        newPlayer->difference = newPlayer->teamPoints - newPlayer->oppPoints;
        newPlayer->next = NULL;
        ptr->next = newPlayer;
        ptr = ptr->next;
    }
    fclose(file);

    HoopsPlayer *temp = head;
    head = head->next;
    free(temp);

    sortList(&head);

    while (head != NULL)
    {
        printf("%s %d\n", head->name, head->difference);
        HoopsPlayer *temp2 = head;
        head = head->next;
        free(temp2);
    }

    return EXIT_SUCCESS;
}