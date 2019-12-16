#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct {
	int value;
	struct NodeStruct* leftChild;
	struct NodeStruct* rightChild;
} Node;

Node* root = NULL;

Node* BST_insert(Node* root, int value) {
	// 이진 탐색 트리의 루트 노드가 NULL 값일 경우
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->leftChild = root->rightChild = NULL;
		root->value = value;
		return root;
	}
	else {
		// 입력 받은 값이 루트 노드의 값보다 작으면
		if (root->value > value) {
			root->leftChild = BST_insert(root->leftChild, value);
		}
		// 입력 받은 값이 루트 노드의 값보다 크면
		else {
			root->rightChild = BST_insert(root->rightChild, value);
		}
		return root;
	}
}

Node* findMinNode(Node* root) {
	Node* tmp = root;
	while (tmp->leftChild != NULL) {
		tmp = tmp->leftChild;
	}
	return tmp;
}

Node* BST_delete(Node* root, int value) {
	Node* tNode = NULL;

	if (root == NULL) {
		return NULL;
	}

	// 루트 노드의 값보다 작으면
	if (root->value > value) {
		root->leftChild = BST_delete(root->leftChild, value);
	}
	else if (root->value < value) {
		root->rightChild = BST_delete(root->rightChild, value);
	}
	else {
		if (root->rightChild != NULL && root->leftChild != NULL) {
			tNode = findMinNode(root->rightChild);
			root->value = tNode->value;
			root->rightChild = BST_delete(root->rightChild, tNode->value);
		}
		else {
			tNode = (root->leftChild == NULL) ? root->rightChild : root->leftChild;
			free(root);
			return tNode;
		}
	}
	return root;
}

Node* BST_Search(Node* root, int value) {
	if (root == NULL) {
		return NULL;
	}

	// 루트 노드의 값과 입력받은 값이 같을 경우
	if (root->value == value) {
		return root;
	}
	// 작을 경우
	else if (root->value > value) {
		return BST_Search(root->leftChild, value);
	}
	// 클 경우
	else {
		return BST_Search(root->rightChild, value);
	}
}
void BST_print(Node* root) {
	if (root == NULL) {
		return;
	}

	printf("%d ", root->value);
	BST_print(root->leftChild);
	BST_print(root->rightChild);
}

int main() {

	int sel = 0, in = 0;

	printf("BST Studying\n");
	printf("1. 삽입\n");
	printf("2. 삭제\n");
	printf("3. 출력\n");
	printf("원하는 번호를 입력하세요: ");
	scanf("%d", &in);


	while (in != NULL) {
		if (in == 1) {
			printf("삽입하고 싶은 숫자를 입력하세요: ");
			scanf("%d", &sel);
			printf("\n");

			root = BST_insert(root, sel);
		}
		else if (in == 2) {
			printf("삭제하고 싶은 숫자를 입력하세요: ");
			scanf("%d", &sel);
			printf("\n");

			root = BST_delete(root, sel);
		}
		else if (in == 3) {
			BST_print(root);
			printf("\n");
		}
		else {
			printf("다시 입력하세요!\n");
		}
		printf("BST Studying\n");
		printf("1. 삽입\n");
		printf("2. 삭제\n");
		printf("3. 출력\n");
		printf("원하는 번호를 입력하세요: ");
		scanf("%d", &in);
	}

	return 0;
}