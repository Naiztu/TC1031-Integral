#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <string>
#include <sStream>
#include <iostream>

template <class T> class SplayTree;

template <class T>
class Node{
    public:
        Node(T);
        Node(T, Node*, Node*, Node*);
        Node(T, Node*);

        Node* add(T);
        Node* find(T);
        int size();

        Node* rot_right(Node*);
        Node* rot_left(Node*);
        Node* splay(Node*, Node*);
        void removeChilds();
        void print_tree(std::stringstream &) const;

        friend class SplayTree<T>;

    private:
        T value;
        Node *left, *right, *parent;

};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0), parent(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri, Node<T> *p): value(val), left(le), right(ri), parent(p) {}

template <class T>
Node<T>::Node(T val, Node<T> *p): value(val), left(0), right(0), parent(p) {}

template <class T>
Node<T>* Node<T>::add(T val){
    if(val>value)
        if(right != 0)
            return right -> add(val);
        else{
            right = new Node(val, this);
            return right;
        }
    else
        if(left != 0)
            return left -> add(val);
        else{
            left = new Node(val, this);
            return left;
        }
}

template <class T>
Node<T>* Node<T>::find(T val){
    if(value == val)
        return this;
    else if(val > value)
            if(right != 0)
                return right->find(val);    
            else
                return 0;
        else if(left !=0)
            return left->find(val);
            else 
                return 0;
}

template <class T>
int Node<T>::size(){
    int l = 0, r = 0;
    if (left != 0) l = left->size() + 1;
    if (right != 0) r = right->size() + 1;
    if ((right != 0) && (left != 0)) r-=1;
    if (left == 0 && right == 0) return 1;
    return r + l;

}

template <class T>
Node<T>* Node<T>::rot_right(Node<T>* y){
    Node<T> *x = y->left;
    
    y->left = x->right;
    if(x->right) y->left->parent = y;

    x->right = y;
    x->parent = y->parent;
    y->parent = x;

    if (x->parent)
        if ((x->parent->right) && (x->parent->value < x->value))
            x->parent->right = x;
        else
            x->parent->left = x;

    return x;
}

template <class T>
Node<T>* Node<T>::rot_left(Node<T>* x){
    Node<T> *y = x->right;

    x->right = y->left;
    if(x->right) x->right->parent = x;

    y->left = x;
    y->parent = x->parent;
    x->parent = y;

    if(y->parent)
        if((y->parent->left)&&(y->parent->value > y->value))
            y->parent->left = y;
        else
            y->parent->left = y;

    return y;
}

template <class T>
Node<T>* Node<T>::splay(Node<T> *rt, Node<T> *x){
    while(x->parent != 0){

        if(rt->value == x->parent->value)
            if(x->parent->left && x->parent->left->value == x->value)
                rot_right(rt);   //Zag
            else
                rot_left(rt);  //Zig
        else{
            Node<T>*p = x->parent; 
			Node<T>*g = p->parent;
                //Zig-Zig
            if((g->left) && (p->left) &&
                (g->left->value == p->value) && (p->left->value == x->value)){
                rot_right(g);
                rot_right(p);
            }   //Zag-Zag 
            else if((g->right) && (p->right) &&
                    (g->right->value == p->value) && (p->right->value == x->value)){
                    rot_left(g);
                    rot_left(p);
            }   //Zag-Zig
            else if((g->left) && (p->right) && 
                    (g->left->value == p->value) && (p->right->value == x->value)){
                    rot_left(p);
                    rot_right(g);
            }   //Zig-Zag
            else{
                rot_right(p);
                rot_left(g);    
            }
        }

    }
    return x;
}
template <class T>
void Node<T>::print_tree(std::stringstream &aux) const {
	if (left != 0) aux << "\n ->" << left->value.getName();
	if (right != 0) aux << "\n ->" << right->value.getName();
    if (right != 0) right->print_tree(aux);
	if (left != 0)  left->print_tree(aux);
}

template <class T>
void Node<T>::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

template <class T>
class SplayTree{
    public:
        SplayTree();
        ~SplayTree();
        bool empty() const;
        void add(T);
        bool find(T);
        int size();
        void removeAll();
        std::string print_tree() const;

    private:
        Node<T> *root;

};

template <class T>
SplayTree<T>::SplayTree() : root(0) {}

template <class T>
SplayTree<T>::~SplayTree(){
    removeAll();
}

template <class T>
bool SplayTree<T>::empty() const{
    return (root == 0);
}

template <class T>
void SplayTree<T>::removeAll() {
    if (root != 0)  root->removeChilds();
    delete root;
    root = 0;
}

template <class T>
void SplayTree<T>::add(T val){
    if(empty())
        root = new Node<T>(val);
    else{
        Node<T> *added = root -> add(val);
        root = root->splay(root, added);
    }
}

template <class T>
bool SplayTree<T>::find(T val){
    if(!empty()){
        Node<T> *found = root->find(val);
        if(found != 0) root = root->splay(root, found);
        else return -false;
        return true;
    }
    return false;
}

template <class T>
int SplayTree<T>::size(){
    if(!empty()) return root->size();
    return 0;
}

template <class T>
std::string SplayTree<T>::print_tree() const {
    std::stringstream aux;

    aux << "\n ================================ ";
        
    if (!empty()){
        aux << "\n Ultimo Pedido:" << root->value.getName();
        aux << "\n sugerencias del dia: " ;
        root->print_tree(aux);
    }   
    aux << "\n ================================ \n";
    return aux.str();
}

#endif