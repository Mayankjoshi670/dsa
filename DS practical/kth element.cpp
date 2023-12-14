#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void kthLargestUtil(struct node* root, int k, int* count, struct node** result) {
    if (root == NULL || *count >= k) {
        return;
    }

    kthLargestUtil(root->right, k, count, result);

    (*count)++;
    if (*count == k) {
        *result = root;
        return;
    }

    kthLargestUtil(root->left, k, count, result);
}

struct node* kthLargest(struct node* root, int k) {
    int count = 0;
    struct node* result = NULL;

    kthLargestUtil(root, k, &count, &result);

    return result;
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80) ;
    printf("Enter k for kth largest element: ");
    int k;
    scanf("%d", &k);

    struct node* kthLargestNode = kthLargest(root, k);

    if (kthLargestNode != NULL) {
        printf("kth largest element: %d\n", kthLargestNode->data);
    } else {
        printf("Invalid k value or tree has fewer nodes\n");
    }

    return 0;
}

