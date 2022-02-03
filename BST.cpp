//
//  BST.cpp
//  BSTbullard
//
//  Created by Brandon lyons on 12/19/21.
//  Copyright © 2021 Brandon lyons. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class treenode{
public:
    string info;
    treenode *lchild, *rchild;
};
class BST{
    BST(){root = 0;}
    ~BST();
    bool empty();
    void insert(string item);
    void insert(treenode * &, string item);
    void del(string item);
    void del(treenode * & locptr, string item);
    treenode * searchtree(treenode *, string item);
    treenode * searchtree(string item);
    treenode * inordersucc(treenode *);
    void print();
    void print(treenode *);
private:
    treenode *root;
};


bst::~bst(){
    while (root != 0)
    {
        del_name(root-> county_name);
    }
}

bool BST::empty(){
    return (root = 0);
}
void BST::insert(string item){
    insert(root, item);
}
void BST::insert(treenode * & locptr, string item){
    if(locptr == 0){
        locptr = new treenode;
        locptr -> lchild = locptr -> rchild = 0;
        locptr -> info = item;
    }
    else if (locptr -> info > item)
        insert(locptr -> lchild, item);
    else if (locptr -> info < item)
        insert(locptr -> rchild, item);
    else
        cout << "Item in tree already." << endl;
}

treenode * BST::searchtree(string item){
    return searchtree(root, item);
}

treenode * BST::searchtree(treenode * locptr, string item){
    if(locptr != 0){
        if(locptr -> info == item){
            return locptr;
        }
        else if(locptr -> info > item){
            return searchtree(locptr -> lchild, item);
        }
        else{
            return searchtree(locptr -> rchild, item);
        }
    }
    else{
        return locptr;
    }
}
void BST::del(string item){
    del(root, item);
}
void BST::del(treenode * & locptr, string item){
    if(locptr == 0){
        cout << "Not in tree!";
        
    }
    else if(locptr -> info > item){
        del(locptr -> lchild, item);
    }
    else if(locptr -> info < item){
        del(locptr -> rchild, item);
    }
    else{
        treenode * ptr;
        if( locptr -> lchild == 0){
            ptr = locptr -> rchild;
            delete locptr;
            locptr = ptr;
        }
        else if( locptr -> rchild == 0){
            ptr = locptr -> lchild;
            delete locptr;
            locptr = ptr;
        }
        else{
            ptr = inordersucc(locptr);
            locptr -> info = ptr -> info;
            del(locptr -> rchild, ptr -> info);
        }
    }
}

void BST::print(){
    print(root);
}
void BST::print(treenode * locptr){
    if( locptr != 0 ){
        print(locptr -> lchild);
        cout << locptr -> info << endl;
        print(locptr -> rchild);
    }
}
treenode * BST::inordersucc(treenode * locptr){
    treenode *ptr = locptr -> rchild;
    while(ptr -> lchild != 0 ){
        ptr = ptr -> lchild;
        
    }
    return ptr;
}
int main( int argc, char * argv[]){
    
}
