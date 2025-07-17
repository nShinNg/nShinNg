#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to represent a student
struct Student {
    int id;
    char name[50];
    float grade;
};

// Function prototypes
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void findStudent(struct Student students[], int count);
float calculateAverage(struct Student students[], int count);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    
    do {
        printf("\n--- Student Records Management ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Find Student by ID\n");
        printf("4. Calculate Average Grade\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(count < MAX_STUDENTS) {
                    addStudent(students, &count);
                } else {
                    printf("Maximum number of students reached!\n");
                }
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                findStudent(students, count);
                break;
            case 4:
                if(count > 0) {
                    printf("Average grade: %.2f\n", calculateAverage(students, count));
                } else {
                    printf("No students added yet!\n");
                }
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);
    
    return 0;
}

void addStudent(struct Student students[], int *count) {
    printf("Enter student ID: ");
    scanf("%d", &students[*count].id);
    
    printf("Enter student name: ");
    getchar(); // Clear buffer
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = 0; // Remove newline
    
    printf("Enter student grade: ");
    scanf("%f", &students[*count].grade);
    
    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(struct Student students[], int count) {
    if(count == 0) {
        printf("No students to display!\n");
        return;
    }
    
    printf("\n--- Student List ---\n");
    printf("ID\tName\t\tGrade\n");
    printf("--------------------------------\n");
    for(int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

void findStudent(struct Student students[], int count) {
    int searchId;
    printf("Enter student ID to search: ");
    scanf("%d", &searchId);
    
    for(int i = 0; i < count; i++) {
        if(students[i].id == searchId) {
            printf("Student found:\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Grade: %.2f\n", students[i].grade);
            return;
        }
    }
    printf("Student with ID %d not found!\n", searchId);
}

float calculateAverage(struct Student students[], int count) {
    float sum = 0;
    for(int i = 0; i < count; i++) {
        sum += students[i].grade;
    }
    return sum / count;
}