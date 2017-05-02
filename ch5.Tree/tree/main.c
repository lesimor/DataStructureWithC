#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode *nodePointer;
typedef struct treeNode {
    nodePointer left_child;
    nodePointer right_child;
    int level;
    int value;
} treeNode;

nodePointer createTree();

void treeExpand(nodePointer current_node_ptr, int max_level);

void addLeftChild(nodePointer parent, nodePointer child);

void inorder(nodePointer ptr);

void preorder(nodePointer ptr);

void postorder(nodePointer ptr);

int main() {
    nodePointer rootPointer = createTree();

    treeExpand(rootPointer, 10);

    inorder(rootPointer);
    return 0;
}

nodePointer createTree() {
    nodePointer root = malloc(sizeof(*root));
    // root 노드 세팅
    root->value = 1;
    root->level = 0;
    return root;
}

void treeExpand(nodePointer current_node_ptr, int max_level) {
    if(current_node_ptr->level < max_level){
        // 왼쪽 자식 노드 생성.
        nodePointer left_child_node = malloc(sizeof(treeNode));
        left_child_node->level = (current_node_ptr->level) + 1;
        // left_child의 값은 두배.
        left_child_node->value = (current_node_ptr->value) * 2;

        current_node_ptr -> left_child = left_child_node;

        treeExpand(left_child_node, max_level);

        // 오른쪽 자식 노드 생성.
        nodePointer right_child_node = malloc(sizeof(treeNode));
        right_child_node->level = (current_node_ptr->level) + 1;
        // right_child의 값은 세배.
        right_child_node->value = (current_node_ptr->value) * 3;

        current_node_ptr -> right_child = right_child_node;

        treeExpand(right_child_node, max_level);




    }


}

void inorder(nodePointer ptr){
    if(ptr){
        inorder(ptr->left_child);
        printf("%d\n", ptr->value);
        inorder(ptr->right_child);
    }
}

void preorder(nodePointer ptr){
    if(ptr){
        printf("%d\n", ptr->value);
        inorder(ptr->left_child);
        inorder(ptr->right_child);
    }
}

void postorder(nodePointer ptr){
    if(ptr){
        inorder(ptr->left_child);
        inorder(ptr->right_child);
        printf("%d\n", ptr->value);
    }
}