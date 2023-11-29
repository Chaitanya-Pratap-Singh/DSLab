#include <stdio.h>
#include <stdlib.h>

// Structure for a binary search tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to perform preorder traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to search for an element in the BST
struct Node* searchElement(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return searchElement(root->left, key);
    }

    return searchElement(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int n, data, option;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements of BST: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("BST Created:\n");
    // You can add code to display the tree structure if needed.

    do {
        printf("\nMAIN MENU\n");
        printf("1. Preorder\n");
        printf("2. Postorder\n");
        printf("3. Inorder\n");
        printf("4. Search\n");
        printf("5. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Preorder: ");
                preorderTraversal(root);
                break;
            case 2:
                printf("Postorder: ");
                postorderTraversal(root);
                break;
            case 3:
                printf("Inorder: ");
                inorderTraversal(root);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &data);
                if (searchElement(root, data) != NULL) {
                    printf("Element %d found in the BST.\n", data);
                } else {
                    printf("Element %d not found in the BST.\n", data);
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 5);

    return 0;
}