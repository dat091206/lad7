#include <stdio.h>
#include <stdlib.h>

// (a) Khai báo c?u trúc cây nh? phân
typedef struct TNode {
    int key;
    struct TNode *left, *right;
} TNode;

// (b) Kh?i t?o cây r?ng
TNode* createEmptyTree() {
    return NULL;
}

// (c) Thêm ph?n t? vào cây (BST insert)
TNode* insertNode(TNode* root, int x) {
    if (root == NULL) {
        TNode* p = (TNode*)malloc(sizeof(TNode));
        p->key = x;
        p->left = p->right = NULL;
        return p;
    }
    if (x < root->key)
        root->left = insertNode(root->left, x);
    else if (x > root->key)
        root->right = insertNode(root->right, x);
    return root;
}

// (d) Tìm ph?n t? trong cây
TNode* searchNode(TNode* root, int x) {
    if (root == NULL || root->key == x)
        return root;
    if (x < root->key)
        return searchNode(root->left, x);
    else
        return searchNode(root->right, x);
}

// (e) Xóa m?t nút trong cây
TNode* findMin(TNode* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

TNode* deleteNode(TNode* root, int x) {
    if (root == NULL) return NULL;

    if (x < root->key)
        root->left = deleteNode(root->left, x);
    else if (x > root->key)
        root->right = deleteNode(root->right, x);
    else {
        // Nút c?n xóa du?c tìm th?y
        if (root->left == NULL) {
            TNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TNode* temp = root->left;
            free(root);
            return temp;
        }
        // Nút có 2 con
        TNode* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// (f) Duy?t NLR (ti?n t?)
void NLR(TNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        NLR(root->left);
        NLR(root->right);
    }
}

// (g) Duy?t LNR (trung t?)
void LNR(TNode* root) {
    if (root != NULL) {
        LNR(root->left);
        printf("%d ", root->key);
        LNR(root->right);
    }
}

// (h) Duy?t LRN (h?u t?)
void LRN(TNode* root) {
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        printf("%d ", root->key);
    }
}

// === Hàm main ki?m th? ===
int main() {
    TNode* root = createEmptyTree();
    int n, x;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
	int i;
    for (i = 0; i < n; i++) {
        printf("Nhap gia tri thu %d: ", i + 1);
        scanf("%d", &x);
        root = insertNode(root, x);
    }

    printf("\nDuyet NLR (Tien tu): ");
    NLR(root);

    printf("\nDuyet LNR (Trung tu): ");
    LNR(root);

    printf("\nDuyet LRN (Hau tu): ");
    LRN(root);

    printf("\n\nNhap phan tu can tim: ");
    scanf("%d", &x);
    TNode* found = searchNode(root, x);
    if (found)
        printf("Tim thay %d trong cay.\n", x);
    else
        printf("Khong tim thay %d trong cay.\n", x);

    printf("\nNhap phan tu can xoa: ");
    scanf("%d", &x);
    root = deleteNode(root, x);
    printf("Cay sau khi xoa %d (LNR): ", x);
    LNR(root);

    return 0;
}

