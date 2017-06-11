#include <stdio.h>
#include <stdlib.h>
#define NULL 0;

typedef struct element* nodePointer;

typedef struct element {
    int key;
    nodePointer left_child;
    nodePointer right_child;
} element;

// 트리 루트 노드 생성
nodePointer treeInit(int key);
nodePointer search(nodePointer node, int key);
nodePointer modifiedSearch(nodePointer node, int key);
void insert(nodePointer* node, int key);

int main() {
    printf("Hello, World!!\n");
    nodePointer root = treeInit(400);
    root->left_child = treeInit(100);

    insert(&root, 160);

    if(search(root, 100)){
        printf("Found!!");
    } else {
        printf("Not found");
    }
    printf("%d", root->key);
    return 0;
}

// init_tree
nodePointer treeInit(int key){
    nodePointer root = (nodePointer)malloc(sizeof(element));
    root->key = key;
    return root;
}

nodePointer search(nodePointer node, int key){
    if(!node)return NULL;
    if(node->key == key) return node;
    if(key < node->key) search(node->left_child, key);
    if(node->key < key) search(node->right_child, key);
}

// 트리가 공백이거나 값이 존재하면 NULL을, 값이 존재하지 않은 경우 마지막으로 검사했던 노드를 반환.
nodePointer modifiedSearch(nodePointer node, int key){
    if(node -> key == key){
        return NULL;
    }
    // 해당 노드의 키값보다 작은데 왼쪽 노드가 없으면 해당 노드를 리턴.
    if((key < node -> key && !(node->left_child)) || (key > node -> key && !(node->right_child))){
        return node;
    } else {
        return NULL;
    }

}

void insert(nodePointer* node, int key){
    printf("삽입!");
    nodePointer ptr, temp = modifiedSearch(*node, key);

    if(temp || !(*node)){
        ptr = (nodePointer)malloc(sizeof(nodePointer));
        ptr->key = key;

        if(*node){
            if(key < temp->key) temp->left_child = ptr;
            else temp->right_child = ptr;
        }else {
            *node = ptr;
        }
    }

}

