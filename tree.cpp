#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int vi[10000];
ifstream input("tree.inp");
ofstream output("tree.out");

typedef struct treeNode {
	pair<char, int> key;
	int visit;
	treeNode *left;
	treeNode *right;
} treeNode;

treeNode *insertNode(treeNode *p, char x, int y) {
	treeNode *newNode;

	if (p == NULL) {
		newNode = (treeNode *)malloc(sizeof(treeNode));
		newNode->visit = 0;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->key.first = x;
		newNode->key.second = y;
		
		return newNode;
	}
	else if (p->left == NULL) {
		p->left = insertNode(p->left, x, y);
	}
	else if (p->left->visit != 1 && p->left->key.first == 'r' && vi[p->left->key.second] != 2) {
		p->left = insertNode(p->left, x, y);
	}
	else if (p->right == NULL) {
		p->right = insertNode(p->right, x, y);
	}
	else if (p->right->visit != 1 && p->right->key.first == 'r' && vi[p->right->key.second] != 2) {
		p->right = insertNode(p->right, x, y);
	}
	return p;
}
void preorder(treeNode *n) {
	output << n->key.first << n->key.second << "\n";
	if (n->left != NULL)
		preorder(n->left);
	if (n->right != NULL)
		preorder(n->right);
}
void inorder(treeNode *n) {
	if (n->left != NULL)
		inorder(n->left);
	output << n->key.first << n->key.second << "\n";
	if (n->right != NULL)
		inorder(n->right);
}
int main() {
	int count;
	input >> count;

	while (count != 0) {
		int temp = 0;
		treeNode *root = NULL;
		root = insertNode(root, 'r', 0);
		int left = 0;
		int right = 0;
		int center = 0;
		while (1) {
			string a;
			input >> a;
			output << a << " ";
			if (a == "(") {
				if (temp == 0) {
					temp++;
					left++;
					continue;
				}
				left++;
				vi[temp] = 1;
				insertNode(root, 'r', temp);
				temp++;
			}
			else if (a == ")") {
				right++;
				for (int i = temp; i > 0; i--) {
					if (vi[i] == 1) {
						vi[i] = 2;
						break;
					}
				}
			}
			else {
				int result = 0;
				char tmp = a.at(0);
				for (int i = 1; i < a.size(); i++) {
					int ten = 1;
					char tmp2 = a.at(i);
					int tmp3 = tmp2 - 48;
					for (int j = i; j < a.size() - 1; j++) {
						ten *= 10;
					}
					result += tmp3 * ten;
				}
				insertNode(root, tmp, result);
			}
			if (left == right)
				break;
		}
		output << "\n";
		output << "Preorder\n";
		preorder(root);
		output << "Inorder\n";
		inorder(root);
		count--;
		for (int i = 0; i <= temp; i++) {
			vi[i] = 0;
		}
	}
}