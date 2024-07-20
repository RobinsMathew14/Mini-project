#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASKS 100
#define MAX_TASK_NAME 50
typedef struct {
    int id;
    char name[MAX_TASK_NAME];
    int priority;
    int isComplete;
    int hours;
} Task;
Task taskList[MAX_TASKS];
int taskCount = 0;
void AssignHoursBasedOnPriority(Task *task) {
    int priorityHours[] = {0, 1, 2, 4, 6, 8};
    task->hours = priorityHours[task->priority];
}
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    Task newTask;
    newTask.id = taskCount + 1;
    newTask.isComplete = 0;
    printf("Enter task name: ");
    scanf(" %[^\n]", newTask.name);
    printf("Enter task priority (1-5): ");
    scanf("%d", &newTask.priority);
    AssignHoursBasedOnPriority(&newTask);
    taskList[taskCount++] = newTask;
    printf("Task added successfully!\n");
}
void removeTask() {
    if (taskCount == 0) {
        printf("No tasks to remove!\n");
        return;
    }
    int id;
    printf("Enter task ID to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < taskCount; i++) {
        if (taskList[i].id == id) {
            for (int j = i; j < taskCount - 1; j++) {
                taskList[j] = taskList[j + 1];
            }
            taskCount--;
            printf("Task removed successfully!\n");
            return;
        }
    }
    printf("Task with ID %d not found!\n", id);
}
void displayTasks() {
    if (taskCount == 0) {
        printf("No tasks to display!\n");
        return;
    }
    printf("ID\tName\t\tPriority\tHours\tStatus\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d\t%s\t\t%d\t\t%d\t%s\n", taskList[i].id, taskList[i].name, taskList[i].priority, taskList[i].hours, taskList[i].isComplete ? "Complete" : "Incomplete");
    }
}
void markTaskComplete() {
    if (taskCount == 0) {
        printf("No tasks to mark as complete!\n");
        return;
    }
    int id;
    printf("Enter task ID to mark as complete: ");
    scanf("%d", &id);
    for (int i = 0; i < taskCount; i++) {
        if (taskList[i].id == id) {
            taskList[i].isComplete = 1;
            printf("Task marked as complete!\n");
            return;
        }
    }
    printf("Task with ID %d not found!\n", id);
}
void menu() {
    int choice;
    while (1) {
        printf("\nTask Management System\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Display Tasks\n");
        printf("4. Mark Task as Complete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addTask(); break;
            case 2: removeTask(); break;
            case 3: displayTasks(); break;
            case 4: markTaskComplete(); break;
            case 5: exit(0); break;
            default: printf("Invalid choice!\n");
        }
    }
}
int main() {
    menu();
    return 0;
}


