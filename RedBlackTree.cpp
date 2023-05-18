/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions.
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c == 0) ? 1 : 0;
}

template <class T>
class RBTNode {
    RBTNode<T>* parent, * left, * right;
    T data;
    int color;

public:
    RBTNode(T data)
        : data(data),
        color(RED),
        parent(nullptr),
        left(nullptr),
        right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1>*);
    template <class T1>
    friend int getColor(RBTNode<T1>*);
    //////////////////////////////////////////////Testing Code//////////////////////////////
    T getData() {
        return data;
    }
    T getLeft() {
        if (left != nullptr) {
            return left->data;
        } 
    }
    T getRight() {
        if (right != nullptr) {
            return right->data;
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////////
    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T>* node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T>* node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T>* root;
    void singleCCR(RBTNode<T>*& point);
    void doubleCR(RBTNode<T>*& point);
    void singleCR(RBTNode<T>*& point);
    void doubleCCR(RBTNode<T>*& point);

public:
    RBT() : root(nullptr) {}

    void insert(const T&);
    void insert(const T&, RBTNode<T>*& point, RBTNode<T>* parent);
    void prettyPrint() const { root->prettyPrint(0); }
    ///////////////////////////////// TEST CODE PURPOSES ONLY//////////////////////////////////////////////
    void getRoot() {
        cout << root->getData() << " " << root->getRight() << " " << root->getLeft() << endl;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T>*& point) {
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T>*& point) {
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T>*& point) {
    RBTNode<T>* grandparent = point;
    RBTNode<T>* parent = point->left;
    // TODO: ADD ROTATION CODE HERE
    grandparent->left = parent->right;
    if (parent->right != nullptr) {
        parent->right->parent = grandparent;
    }
    parent->right = grandparent;
    parent->parent = grandparent->parent;
    if (parent->parent == nullptr) {
        root = parent;
        swapColor(parent);
    }
    grandparent->parent = parent;
    if (parent->parent == nullptr) {
        cout << "YES" << endl;
    }
    point = parent;
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T>*& point) {
    RBTNode<T>* grandparent = point;
    RBTNode<T>* parent = point->right;
    
    // TODO: ADD ROTATION CODE HERE
    grandparent->right = parent->left;
    if (parent->left != nullptr) {
        parent->left->parent = grandparent;
    }
    parent->left = grandparent;
    parent->parent = grandparent->parent;
    if (parent->parent == nullptr) {
        root = parent;
        swapColor(parent);
    }
    grandparent->parent = parent;
    
    point = parent;
}

template <class T>
void RBT<T>::insert(const T& toInsert, RBTNode<T>*& point, RBTNode<T>* parent) {
    if (point == nullptr) {               // leaf location is found so insert node
        point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point //the point will automatically have a red color
        // is passed by reference
        point->parent = parent;

        RBTNode<T>* curr_node = point; // curr_node will be set appropriately when walking up the tree
        // TODO: ADD RBT RULES HERE (one rule of changing the color as you go down the list may not work here and I might have to change the color after the insertion
        //funcions I can use: singleCCR, single CR, doubleCCR, doubleCR, getColor, swapColor
        //I am currently will not add the check to see if there is any black parent with two red children
        if (parent == nullptr) {
            swapColor(curr_node);
            root = curr_node;
        }
        if(parent != nullptr && parent->parent != nullptr){
            if (getColor(parent) == RED) {
                if (getColor(parent->right) == BLACK || getColor(parent->left) == BLACK) {
                    if (point == parent->left && parent == parent->parent->left) {
                        parent->parent->getData();
                        if (parent->parent->parent == nullptr) {
                            cout << "YES" << endl;
                        }
                        parent->getData();
                        singleCR(parent->parent);

                        //this needs a check for color change and restabalizing the color rules
                    }
                    else if (point == parent->right && parent == parent->parent->right) {
                        parent->parent->getData();
                        if (parent->parent->parent != nullptr) {
                           cout << parent->parent->parent->getData() << endl;
                        }
                        
                        if (parent->parent->parent == nullptr) {
                            cout << "YES" << endl;
                        }
                        parent->getData();
                        singleCCR(parent->parent);
                        //needs a check for color change and restabilizing the color rules
                    }
                    else if (point == parent->left && parent == parent->parent->right) {
                        doubleCCR(parent->parent);
                        //needs a check for color change and restabilizing the color rules
                    }
                    else if (point == parent->right && parent == parent->parent->left) {
                        doubleCR(parent->parent);
                        //needs a check for color change and restabilizing the color rules
                    }
                }
            }
            ///////////////FOR TESTING PURPOSESING ONLY////////////////////////////////////
            //parent->prettyPrint(0);
            /////////////////////////////////////////////////////////////////////////////
        }
        
    }
    else if (toInsert < point->data) { // recurse down the tree to left to find correct leaf locationn //this is where i would put the total tree color change
        insert(toInsert, point->left, point);
    }
    else { // recurse down the tree to right to find correct leaf location
        insert(toInsert, point->right, point);
    }
}

template <class T>
void RBT<T>::insert(const T& toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 4;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }
    //b.getRoot();
    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */

    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    //assert(height <= 2 * log2(count));
}