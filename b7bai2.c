#include <stdio.h>
#include <stdlib.h>

// C?u trúc nút cây nh? phân
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Hàm t?o nút m?i
Node* newNode(int k) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = k;
    p->left = p->right = NULL;
    return p;
}

// T?o cây t? m?ng ki?u heap
Node* createTree(int a[], int i, int n) {
    if (i >= n || a[i] == -1)
        return NULL;
    Node* root = newNode(a[i]);
    root->left = createTree(a, 2*i + 1, n);
    root->right = createTree(a, 2*i + 2, n);
    return root;
}

// Duy?t NLR (ti?n t?)
void NLR(Node* r) {
    if (!r) return;
    printf("%d ", r->key);
    NLR(r->left);
    NLR(r->right);
}

// Duy?t LNR (trung t?)
void LNR(Node* r) {
    if (!r) return;
    LNR(r->left);
    printf("%d ", r->key);
    LNR(r->right);
}

// Duy?t LRN (h?u t?)
void LRN(Node* r) {
    if (!r) return;
    LRN(r->left);
    LRN(r->right);
    printf("%d ", r->key);
}

// Duy?t BFS (theo m?c)
void BFS(Node* root) {
    if (!root) return;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node* cur = queue[front++];
        printf("%d ", cur->key);
        if (cur->left) queue[rear++] = cur->left;
        if (cur->right) queue[rear++] = cur->right;
    }
}

// Tính s? lá
int countLeaf(Node* r) {
    if (!r) return 0;
    if (!r->left && !r->right)
        return 1;
    return countLeaf(r->left) + countLeaf(r->right);
}

// Tính chi?u cao cây
int height(Node* r) {
    if (!r) return 0;
    int hl = height(r->left);
    int hr = height(r->right);
    return (hl > hr ? hl : hr) + 1;
}

// Chuong trình chính
int main() {
    int A[] = {10, 5, 15, 3, 7, -1, 18};
    int n = sizeof(A)/sizeof(A[0]);
    Node* root = createTree(A, 0, n);

    printf("Duyet NLR: "); NLR(root); printf("\n");
    printf("Duyet LNR: "); LNR(root); printf("\n");
    printf("Duyet LRN: "); LRN(root); printf("\n");
    printf("Duyet BFS: "); BFS(root); printf("\n");

    printf("So la: %d\n", countLeaf(root));
    printf("Chieu cao cay: %d\n", height(root));

    return 0;
}

