typedef struct node {
    int data; 
    struct node *lchild, *rchild;
} node;

int N2, NL, NR, N0;

void count(node *t) {
    if (t->lchild != NULL) {
        if (t->rchild != NULL) // 1. 有非空左右孩子
            N2++;
        else // 2. 只有非空左孩子
            NL++;
    } else {
        if (t->rchild != NULL) // 3. 只有非空右孩子
            NR++;
        else // 叶子节点
            N0++;
    }

    if (t->lchild != NULL) // 4. 递归处理左子树
        count(t->lchild);

    if (t->rchild != NULL) // 5. 递归处理右子树
        count(t->rchild);
}
