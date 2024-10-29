#include<bits/stdc++.h>
using namespace std;

struct Node{
	double heSo;
	int mu; 
	Node *next;
};

struct DT{
	Node* head;
	int bac; //bac cua da thuc
};

Node* makeNode(double heSo, int mu){
	Node* newNode = new Node;
	newNode->heSo = heSo;
	newNode->mu = mu;
	newNode->next = NULL;
	return newNode;
}

void themCuoi(Node*& head, Node* them){
	if(head == NULL) head = them;
	else{
		Node* tmp = head;
		while(tmp->next != NULL) tmp = tmp->next;
		tmp->next = them;
	}
}

void nhapDT(DT& dathuc){
	cout << "Nhap bac cua da thuc: "; cin >> dathuc.bac;
	cout << "Nhap he so cua da thuc: ";
	for(int i = 0; i <= dathuc.bac; i++){
		double heSo; cin >> heSo;
		if(heSo == 0) continue;
		Node* newNode = makeNode(heSo, i);
		themCuoi(dathuc.head, newNode);
	}
}

void inDT(DT dathuc){
	if(dathuc.head == NULL){
		cout << "0";
		return;
	}
	Node* tmp = dathuc.head;
	while(tmp != NULL){
		if(tmp->mu == 0) cout << tmp->heSo;
		else cout << tmp->heSo << "x^" << tmp->mu;
		if(tmp->next != NULL) cout << " + ";
		tmp = tmp->next;
	}
}

int main(){
	DT dathuc;
	dathuc.head = NULL;
	nhapDT(dathuc);
	inDT(dathuc);
}
