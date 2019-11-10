//
//  Binary tree lowest common ancestor.cpp
//  Test
//
//  Created by oluchi david on 2019-11-02.
//  Copyright © 2019 oluchi david. All rights reserved.
//

#include <stdio.h>
using namespace std;
#include <iostream>
#include<vector>
#include <string.h>
#include <array>
class Node {
   public:
    int data;
    Node *right;
    Node *left;
};
int n1 = 5;
int n2 = 4;
Node *LCA(Node *root, int n1, int n2){
   if (root == NULL){return NULL;}
    if ((root->data == n1)||(root->data == n2)){
        return root;}
    Node * left = LCA(root->left, n1, n2);
    Node * right = LCA(root->right, n1,n2);
    if (( left == NULL)&&(right == NULL)){return NULL;}
    if ((left !=NULL) && (right != NULL)){return root;}
    else if (left !=NULL) {return left;} else {return right;}
    }
int main(){
    Node r1; Node r2; Node r3;
    Node *root = &r1;
    r1.data = 3; r1.left = &r2; r1.right = &r3;
    r2.data = 5; r2.left = NULL; r2.right = NULL;
    r3.data = 4; r3.left = NULL; r3.right = NULL;
    Node *d = LCA(root, n1,n2);
    cout << d->data;
    return 0;
}
