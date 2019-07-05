#include <iostream>
#include <string>
#include <vector>

using namespace std;

// tree
// linked list
// child를 vector로 연결

class Node {
public:
	int data;
	vector<Node*> child;
	//Node* child1; // 벡터로 써서 다시
	//Node* child2; // child 끼리 연결 필요하므로
	//Node* child3;

	Node* parent;

	Node(Node* tmp,int item) {
		data = item;

		//child1 = NULL;
		//child2 = NULL;
		//child3 = NULL;

		parent = tmp;
	}
};

class Tree {
public:
	Node* root;
	Node* pn;

	Tree(int data) {
		root = new Node(NULL,data);
		pn = root;
	}
	Node* GetRoot() {
		return root;
	}

	///////////////////////////////////
	void insertNode(int parentData, int data) {
		Node* tmp = findNode(parentData);
		if (tmp->child[0] == NULL) {
			tmp->child[0] = new Node(tmp, data);
			//pn = tmp->child1;
		}
		else if (tmp->child[1] == NULL) {
			tmp->child[1] = new Node(tmp, data);
			//pn = tmp->child2;
		}
		else if (tmp->child[2] == NULL) {
			tmp->child[2] = new Node(tmp, data);
			//pn = tmp->child3;
		}
	}
	////////////////////////////////////
	Node* findNode(int Data) {
		Node* tmp = root;
		pn = root; // 변화
			while (pn->data != Data && pn !=NULL) {
				pn = tmp->child[0];
				if (pn->data == Data) {
					return pn;
				}
				pn = tmp->child[1];
				if (pn->data == Data) {
					return pn;
				}

				pn = tmp->child[2];
				if (pn->data == Data) return pn;

				tmp = tmp->child[0];
		}
		return pn;
	}
	//////////////////////////////////

	//void removeNode(int data) {
	//	Node* rmv_node = findNode(data);
	//	Node* tmp_1 = rmv_node->child1;
	//	while (tmp_1 != NULL) {
	//		if (!isExternal(tmp_1)) {
	//			tmp_1 = tmp_1->child1;
	//			break;
	//		}
	//		delete tmp_1;
	//	}
	//	rmv_node = NULL;

	//}

	int size() {
		int num_size = 0;
		pn = root;
		while (pn != NULL) {
			num_size++;
			preorder(pn->child[0]);
			preorder(pn->child[1]);
			preorder(pn->child[2]);
		}
	}
	//bool empty() {
	//}
	bool isRoot(Node* p_n) {
		if (p_n == root) return true;
		else return false;
	}
	bool isExternal(Node* p_n) {
		if (p_n->child[0] == NULL) return true;
		else return false;
	}


	void preorder(Node* p_node) {
		while (p_node != NULL) {
			cout << p_node->data << " ";
			preorder(p_node->child[0]);
			preorder(p_node->child[1]);
			preorder(p_node->child[2]);
			return; // 이거 왜 필요했지 하핫
		}

	}
	void inorder(Node* p_node) {
		while (p_node != NULL) {
			preorder(p_node->child[0]);
			cout << p_node->data << " ";
			preorder(p_node->child[1]);
			preorder(p_node->child[2]);
			return;
		}


	}
	void postorder(Node* p_node) {
		while (p_node != NULL) {
			preorder(p_node->child[0]);
			preorder(p_node->child[1]);
			preorder(p_node->child[2]);
			cout << p_node->data << " ";
			return;
		}
	}
};



int main() {
	Tree Tree1(1);
	Tree1.insertNode(1, 2);
	Tree1.insertNode(1, 3);
	Tree1.insertNode(1, 4);
	Tree1.insertNode(2, 5);
	Tree1.insertNode(3, 6);
	Tree1.insertNode(3, 7);
	Tree1.insertNode(4, 8);
	Tree1.insertNode(4, 9);
	Tree1.insertNode(4, 10);



	cout << "preorder  : ";
	Tree1.preorder(Tree1.GetRoot());
	cout << endl;

	cout << "inorder   : ";
	Tree1.inorder(Tree1.GetRoot());
	cout << endl;

	cout << "postorder : ";
	Tree1.postorder(Tree1.GetRoot());
	cout << endl;
	return 0;
}