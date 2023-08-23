#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    int (*operation)(int, int);
    struct Node *left;
    struct Node *right;
} Node;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero.\n");
        return 0;
    }
}

Node *makeFunc(int (*operation)(int, int), int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->operation = operation;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int evaluate(Node *node) {
    if (node == NULL) {
        return 0;
    }
    if (node->operation == NULL) {
        return node->value;
    }
    int leftValue = evaluate(node->left);
    int rightValue = evaluate(node->right);
    return node->operation(leftValue, rightValue);
}

void calc(Node *node) {
    int result = evaluate(node);
    printf("%s : %d\n", node->operation == add ? "add" :
                          node->operation == subtract ? "sub" :
                          node->operation == multiply ? "mul" : "div", result);
}

int main() {
    Node *add = makeFunc(add, 10);
    add->left = makeFunc(NULL, 10);
    add->right = makeFunc(NULL, 6);

    Node *mul = makeFunc(multiply, 5);
    mul->left = makeFunc(NULL, 5);
    mul->right = makeFunc(NULL, 4);

    Node *sub = makeFunc(subtract, 0);
    sub->left = mul;
    sub->right = add;

    Node *fibo = makeFunc(subtract, 0);
    fibo->left = sub;

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    return 0;
}
