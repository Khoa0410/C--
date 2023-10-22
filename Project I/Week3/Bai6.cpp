/*
Given a family tree represented by child-parent (c,p) relations in which c is a child of p.
Perform queries about the family tree:
descendants <name>: return number of descendants of the given <name>
generation <name>: return the number of generations of the descendants of the given <name>
*/

#include <bits/stdc++.h> 
#include <cstring>
using namespace std;

struct Node {
    string data;	
    vector<Node*> children;
    Node(string value) : data(value) {}
};

// Thêm nút child vào danh sách nút con của nút parent
void addChild(Node* parent, Node* child) {
    parent->children.push_back(child);
} 

// Đếm số phần tử của cây
void printPreorder(Node* root, int &count) {
    count++; 
    for (int i = 0; i < root->children.size(); ++i) {
        printPreorder(root->children[i], count); 
    }
}

// Tính độ cao của 1 nút
int height(Node* root) {
    
    int max = -1;
    for (int i = 0; i < root->children.size(); ++i) {
        int t = height(root->children[i]);
        if(t > max) max = t; 
    }
    return 1+max;
}


// Tìm vị trí của nút có tên là text trong vector nút con
int check(vector<Node*> &node, string &text) {
	for (int i = 0; i < node.size(); i++) {
		if(node[i] -> data == text) return i;
	}
	return -1;
}

int main() {
    //freopen(".inp", "r", stdin);

	vector<Node*> node;
	string line = "";
	
	while(true) {
		getline(cin, line);
		if(line == "***") break;
		
		// Lấy tên của child và parent
		string linecopy1="";
		string linecopy2="";
		    int i;
			for (i = 0; line[i] != ' '; i++) linecopy1 = linecopy1 + line[i];
			i++;
			for (int j = i; j < line.length(); j++) linecopy2 = linecopy2 + line[j];
		
		// Đưa child vào vector nút con của parent 
		if(check(node,linecopy2) == -1) {
		    Node* parent = new Node(linecopy2);
		    node.push_back(parent);
		}
		
		if(check(node,linecopy1) == -1) {
		    Node* child = new Node(linecopy1);
		    node.push_back(child);
		}
		
		addChild(node[check(node,linecopy2)], node[check(node,linecopy1)]);
	}
	
	while(true) {
	    getline(cin, line);
	    if(line=="***") break;
	    
	    // Đếm số nút con của 1 nút
	    if(line[0] == 'd') {
	        int count = 0;
	        string nameParent = "";
	        for(int i=12; i < line.length(); i++) {
	            nameParent = nameParent + line[i];
	        }
	        printPreorder(node[check(node,nameParent)], count);
	        cout << count-1 << endl;
	    }
	    
	    // Đếm số thế hệ sau của 1 nút
	    if(line[0] == 'g') {
	        int count = 0;
	        string nameParent = "";
	        for(int i=11; i < line.length(); i++) {
	            nameParent = nameParent + line[i];
	        }
	        
	        cout << height(node[check(node,nameParent)]) << endl;
	    }
	}

    return 0;
}

