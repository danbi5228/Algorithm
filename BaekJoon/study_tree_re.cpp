#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// tree
// linked list
// child를 vector로 연결

class Node {
public:
	int data;
	int num_child = 0;
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
		pn->child.push_back(new Node(tmp, data)); 
		pn->num_child = pn->num_child + 1;

		//if (tmp->num_child == 0) {
		//	tmp->child.push_back(new Node(tmp, data));
		//	//pn = tmp->child1;
		//}
		//else if (tmp->child[1] == NULL) {
		//	tmp->child.push_back(new Node(tmp, data));
		//	//pn = tmp->child2;
		//}
		//else if (tmp->child[2] == NULL) {
		//	tmp->child.push_back(new Node(tmp, data));
		//	//pn = tmp->child3;
		//}
	}
	////////////////////////////////////
	Node* findNode(int Data) {
		Node* tmp = root;
		pn = root; // 변화
		vector <Node*> visitNode;
		int visit = 0;

		//if (pn->data == Data) return pn;
		visitNode.push_back(tmp);

		while (pn->data != Data && pn != NULL) {
				pn = visitNode[visit];
				if (pn->data == Data) return pn;
				for (int j = 0; j < pn->num_child; j++) {
					visitNode.push_back(pn->child[j]);
				}
				visit++;
		}
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
			for (int i = 0; i < pn->num_child; i++) {
				preorder(pn->child[i]);
			}
		}
		return num_size;
	}
	//bool empty() {
	//}
	bool isRoot(Node* p_n) {
		if (p_n == root) return true;
		else return false;
	}
	bool isExternal(Node* p_n) {
		if (p_n->num_child == 0) return true;
		else return false;
	}


	void preorder(Node* p_node) {
		while (p_node != NULL) {
			cout << p_node->data << " ";
			for (int i = 0; i < p_node->num_child; i++) {
				preorder(p_node->child[i]);
			}
			return; // 이거 왜 필요했지 하핫
		}

	}
	void inorder(Node* p_node) {
		while (p_node != NULL) {
			if(p_node->num_child !=0) inorder(p_node->child[0]);
			cout << p_node->data << " ";
			for (int i = 1; i < p_node->num_child; i++) {
				inorder(p_node->child[i]);
			}
			return;
		}


	}
	void postorder(Node* p_node) {
		while (p_node != NULL) {
			for (int i = 0; i < p_node->num_child; i++) {
				postorder(p_node->child[i]);
			}
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
	Tree1.insertNode(5, 11);


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