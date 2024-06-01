#include <stdio.h>
#include "operation.h"


void displayMenu() {
    printf("Enter your choice:  1. List files | 2. Create file | 3. Delete file | 4. Write to file | 5. Read from file | 6. Exit\n");
}


int main() {
    int choice;
    char filename[100]; 
    char content[2048];
    while (1){
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                listFiles(".");
                break;
            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);
                createFile(filename);
                break;
            case 3:
                printf("Enter filename: ");
                scanf("%s", filename);
                deleteFile(filename);
                break;
            case 4:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter content: ");
                scanf(" %[^\n]", content);
                writeFile(filename, content);
                break;
            case 5:
                printf("Enter filename: ");
                scanf("%s", filename);
                readFile(filename);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    printf("Welcome to the Simple File Manager!\n");
    return 0;
}
