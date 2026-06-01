#include <stdio.h>
#include <string.h>

#define MAX 100

struct Symbol {
    char name[50];
    char datatype[20];
};

struct Symbol table[MAX];
int count = 0;

// Insert symbol
void insert() {
    printf("Enter Symbol Name: ");
    scanf("%s", table[count].name);

    printf("Enter Data Type: ");
    scanf("%s", table[count].datatype);

    count++;
    printf("Symbol inserted successfully!\n");
}

// Display symbol table
void display() {
    int i;

    if (count == 0) {
        printf("Symbol Table is Empty!\n");
        return;
    }

    printf("\nSymbol Table:\n");
    printf("--------------------------------\n");
    printf("Index\tSymbol\t\tData Type\n");
    printf("--------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%d\t%s\t\t%s\n",
               i + 1,
               table[i].name,
               table[i].datatype);
    }
}

// Search symbol
void search() {
    char sym[50];
    int i, found = 0;

    printf("Enter Symbol to Search: ");
    scanf("%s", sym);

    for (i = 0; i < count; i++) {
        if (strcmp(table[i].name, sym) == 0) {
            printf("Symbol Found!\n");
            printf("Name: %s\n", table[i].name);
            printf("Data Type: %s\n", table[i].datatype);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Symbol not found!\n");
}

// Delete symbol
void deleteSymbol() {
    char sym[50];
    int i, j, found = 0;

    printf("Enter Symbol to Delete: ");
    scanf("%s", sym);

    for (i = 0; i < count; i++) {
        if (strcmp(table[i].name, sym) == 0) {
            found = 1;

            for (j = i; j < count - 1; j++) {
                table[j] = table[j + 1];
            }

            count--;
            printf("Symbol deleted successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Symbol not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Symbol Table Operations ---\n");
        printf("1. Insert Symbol\n");
        printf("2. Display Symbol Table\n");
        printf("3. Search Symbol\n");
        printf("4. Delete Symbol\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                deleteSymbol();
                break;

            case 5:
                printf("Exiting Program...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
