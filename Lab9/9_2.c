#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

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

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

struct Node* searchElement(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return searchElement(root->left, key);
    }

    return searchElement(root->right, key);
}

struct Node* findLargest(struct Node* root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }

    return findLargest(root->right);
}

struct Node* findSmallest(struct Node* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }

    return findSmallest(root->left);
}

int heightOfNode(struct Node* root) {
    if (root == NULL) {
        return -1;
    }

    int leftHeight = heightOfNode(root->left);
    int rightHeight = heightOfNode(root->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int option, data;

    // ... (previous code for creating BST and menu)

    do {
        printf("\nMAIN MENU\n");
        printf("1. Preorder\n");
        printf("2. Postorder\n");
        printf("3. Inorder\n");
        printf("4. Search\n");
        printf("5. Insert\n");
        printf("6. Largest\n");
        printf("7. Smallest\n");
        printf("8. Height\n");
        printf("9. Count leaf nodes\n");
        printf("10. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            // ... (previous cases for traversal and search)
            case 5:
                printf("Enter element to insert in BST: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 6: {
                struct Node* largestNode = findLargest(root);
                printf("Largest element in BST: %d\n", largestNode->data);
                break;
            }
            case 7: {
                struct Node* smallestNode = findSmallest(root);
                printf("Smallest element in BST: %d\n", smallestNode->data);
                break;
            }
            case 8:
                printf("Enter element to find height: ");
                scanf("%d", &data);
                struct Node* node = searchElement(root, data);
                if (node != NULL) {
                    printf("Height of node %d: %d\n", data, heightOfNode(node));
                } else {
                    printf("Element not found in the BST.\n");
                }
                break;
            case 9:
                printf("Count of leaf nodes in BST: %d\n", countLeafNodes(root));
                break;
            case 10:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 10);

    return 0;
}