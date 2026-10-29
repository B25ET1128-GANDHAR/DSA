#include <stdio.h>
#include <string.h>

#define max 5

struct employee {
    int emp_id;
    char name[50];
    int salary;
    int experience;
} emp[max];

int insert(int i) {
    if (i < max) {
        printf("\nEnter Employee ID: ");
        scanf("%d", &emp[i].emp_id);

        printf("Enter Name: ");
        scanf("%s", emp[i].name);

        printf("Enter Salary: ");
        scanf("%d", &emp[i].salary);

        printf("Enter Experience: ");
        scanf("%d", &emp[i].experience);

        i++;
    } else {
        printf("\nDatabase is full.");
    }

    return i;
}

void display(int i) {
    int j;

    if (i == 0) {
        printf("\nNo employee records available.");
        return;
    }

    printf("\n\nEmployee Details\n");

    for (j = 0; j < i; j++) {
        printf("\nEmployee ID: %d", emp[j].emp_id);
        printf("\nName: %s", emp[j].name);
        printf("\nSalary: %d", emp[j].salary);
        printf("\nExperience: %d years\n", emp[j].experience);
    }
}

void modify(int i) {
    int id, j, found = 0;

    printf("\nEnter employee ID to modify: ");
    scanf("%d", &id);

    for (j = 0; j < i; j++) {
        if (emp[j].emp_id == id) {
            printf("Enter new name: ");
            scanf("%s", emp[j].name);

            printf("Enter new salary: ");
            scanf("%d", &emp[j].salary);

            printf("Enter new experience: ");
            scanf("%d", &emp[j].experience);

            printf("\nEmployee record modified successfully.");
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nEmployee not found.");
    }
}

void search(int i) {
    int id, j, found = 0;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (j = 0; j < i; j++) {
        if (emp[j].emp_id == id) {
            printf("\nEmployee Found!");
            printf("\nEmployee ID: %d", emp[j].emp_id);
            printf("\nName: %s", emp[j].name);
            printf("\nSalary: %d", emp[j].salary);
            printf("\nExperience: %d years\n", emp[j].experience);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nEmployee not found.");
    }
}

void sort(int i) {
    int j, k;
    struct employee temp;

    for (j = 0; j < i - 1; j++) {
        for (k = j + 1; k < i; k++) {
            if (emp[j].emp_id > emp[k].emp_id) {
                temp = emp[j];
                emp[j] = emp[k];
                emp[k] = temp;
            }
        }
    }

    printf("\nRecords sorted by Employee ID successfully.");
}

int main() {
    int choice;
    int i = 0;

    do {
        printf("\n\n    DATABASE     ");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Modify");
        printf("\n4. Search");
        printf("\n5. Sort");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                i = insert(i);
                break;
            case 2:
                display(i);
                break;
            case 3:
                modify(i);
                break;
            case 4:
                search(i);
                break;
            case 5:
                sort(i);
                break;
            case 6:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice.");
        }

    } while (choice != 6);

    return 0;
}
