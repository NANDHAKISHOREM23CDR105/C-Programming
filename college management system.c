#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Student {
    int id;
    char name[50];
    float cgpa;
};

void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count, int id);
void updateStudent(struct Student students[], int count, int id);

int main() {
    struct Student students[100]; // Array to store student records
    int count = 0; // Number of students in the system

    int choice;
    do {
        printf("\nCollege Management System Menu:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
        printf("4. Update Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3: {
                int id;
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(students, &count, id);
                break;
            }
            case 4: {
                int id;
                printf("Enter student ID to update: ");
                scanf("%d", &id);
                updateStudent(students, count, id);
                break;
            }
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent(struct Student students[], int *count) {
    if (*count >= 100) {
        printf("Cannot add more students. Limit reached.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student CGPA: ");
    scanf("%f", &newStudent.cgpa);

    students[*count] = newStudent;
    (*count)++;
    printf("Student added successfully.\n");
}

void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students in the system.\n");
        return;
    }

    printf("ID\tName\tCGPA\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].cgpa);
    }
}

void deleteStudent(struct Student students[], int *count, int id) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            found = 1;
            // Shift remaining elements to the left
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student with ID %d deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}
void updateStudent(struct Student students[], int count, int id) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("Enter new name for student: ");
            scanf("%s", students[i].name);
            printf("Enter new CGPA for student: ");
            scanf("%f", &students[i].cgpa);
            printf("Student information updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}
