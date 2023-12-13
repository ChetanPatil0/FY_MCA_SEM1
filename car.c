

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char model[50];
    float price;
    char manufacturer[50];
    float engine_capacity;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;

Node* head = NULL;

void insert() {
    Node* new_node = (Node*)malloc(sizeof(Node));

    printf("Enter Car Model: ");
    scanf("%s", new_node->model);
    printf("Enter Price: ");
    scanf("%f", &new_node->price);
    printf("Enter Manufacturer: ");
    scanf("%s", new_node->manufacturer);
    printf("Enter Engine Capacity: ");
    scanf("%f", &new_node->engine_capacity);

    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }

    printf("Car model inserted successfully.\n");
}

void delete() {
    char model[50];
    printf("Enter the model to delete: ");
    scanf("%s", model);

    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->model, model) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            printf("%s deleted successfully.\n", model);
            return;
        }
        current = current->next;
    }

    printf("%s not found.\n", model);
}

void update() {
    char model[50];
    float new_price;

    printf("Enter the model to update price: ");
    scanf("%s", model);

    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->model, model) == 0) {
            printf("Enter the new price: ");
            scanf("%f", &new_price);
            current->price = new_price;
            printf("Price for %s updated successfully.\n", model);
            return;
        }
        current = current->next;
    }

    printf("%s not found.\n", model);
}

void range() {
    float min_price, max_price;

    printf("Enter the minimum price: ");
    scanf("%f", &min_price);
    printf("Enter the maximum price: ");
    scanf("%f", &max_price);

    printf("\nCar models within the specified price range:\n");
    Node* current = head;
    while (current != NULL) {
        if (current->price >= min_price && current->price <= max_price) {
            printf("%s - $%.2f\n", current->model, current->price);
        }
        current = current->next;
    }
}

void display() {
    char model[50];

    Node* current = head;
    while (current != NULL) {

            printf("\n***********Car Model Details:*********\n");
            printf(">>>Model: %s\n", current->model);
            printf(">>>Price: $%.2f\n", current->price);
            printf(">>>Manufacturer: %s\n", current->manufacturer);
            printf(">>>Engine Capacity: %.2f\n", current->engine_capacity);


        current = current->next;
    }

}

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Car Model\n");
        printf("2. Delete Car Model\n");
        printf("3. Update Price\n");
        printf("4. List Models in  Price Range\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                update();
                break;
            case 4:
                range();
                break;
            case 5:
                display();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
