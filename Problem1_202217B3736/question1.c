#include <stdio.h>
#include <conio.h>
#define MAX 10

void create();
void insert();
void deletion();
void search();
void display();

int a, b[20], n, p, e, f, i, pos;

void main() {
    int ch;
    char g = 'y';
    do {
        printf("\n Main Menu");
        printf("\n 1. Create \n 2. Delete \n 3. Search \n 4. Insert \n 5. Display \n 6. Exit \n");
        printf("\n Enter your Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                return; // Use return to exit main
            default:
                printf("\n Enter the correct choice:");
        }
        printf("\n Do you want to continue? (y/n): ");
        scanf(" %c", &g); // Added a space before %c to ignore any previous newline character
    } while (g == 'y' || g == 'Y');
    getch();
}

void create() {
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\n Enter the Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\n Enter the position you want to delete: ");
    scanf("%d", &pos);
    if (pos >= n) {
        printf("\n Invalid Location:");
    } else {
        for (i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
    }
    printf("\n The Elements after deletion:");
    for (i = 0; i < n; i++) {
        printf("\t%d", b[i]);
    }
}

void search() {
    int found = 0; // Added a flag to check if the element is found
    printf("\n Enter the Element to be searched: ");
    scanf("%d", &e);
    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is in the %d Position\n", i + 1);
            found = 1; // Set flag to true if element is found
            break; // Exit the loop if the element is found
        }
    }
    if (!found) {
        printf("Value %d is not in the list.\n", e);
    }
}

void insert() {
    printf("\n Enter the position you need to insert: ");
    scanf("%d", &pos);
    if (pos >= n) {
        printf("\n Invalid Location:");
    } else {
        for (i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }
        printf("\n Enter the element to insert: ");
        scanf("%d", &p);
        b[pos] = p;
        n++;
    }
    printf("\n The list after insertion:\n");
    display();
}

void display() {
    printf("\n The Elements of the list ADT are:");
    for (i = 0; i < n; i++) {
        printf("\n\n%d", b[i]);
    }
}