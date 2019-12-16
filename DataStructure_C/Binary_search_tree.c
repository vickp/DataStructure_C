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
	// ���� Ž�� Ʈ���� ��Ʈ ��尡 NULL ���� ���
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->leftChild = root->rightChild = NULL;
		root->value = value;
		return root;
	}
	else {
		// �Է� ���� ���� ��Ʈ ����� ������ ������
		if (root->value > value) {
			root->leftChild = BST_insert(root->leftChild, value);
		}
		// �Է� ���� ���� ��Ʈ ����� ������ ũ��
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

	// ��Ʈ ����� ������ ������
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

	// ��Ʈ ����� ���� �Է¹��� ���� ���� ���
	if (root->value == value) {
		return root;
	}
	// ���� ���
	else if (root->value > value) {
		return BST_Search(root->leftChild, value);
	}
	// Ŭ ���
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
	printf("1. ����\n");
	printf("2. ����\n");
	printf("3. ���\n");
	printf("���ϴ� ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &in);


	while (in != NULL) {
		if (in == 1) {
			printf("�����ϰ� ���� ���ڸ� �Է��ϼ���: ");
			scanf("%d", &sel);
			printf("\n");

			root = BST_insert(root, sel);
		}
		else if (in == 2) {
			printf("�����ϰ� ���� ���ڸ� �Է��ϼ���: ");
			scanf("%d", &sel);
			printf("\n");

			root = BST_delete(root, sel);
		}
		else if (in == 3) {
			BST_print(root);
			printf("\n");
		}
		else {
			printf("�ٽ� �Է��ϼ���!\n");
		}
		printf("BST Studying\n");
		printf("1. ����\n");
		printf("2. ����\n");
		printf("3. ���\n");
		printf("���ϴ� ��ȣ�� �Է��ϼ���: ");
		scanf("%d", &in);
	}

	return 0;
}