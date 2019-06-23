#include <iostream>
#include <sstream>
#include <string>
#include "myhead.h"
#include <algorithm>
using namespace std;

AVL::AVL()
{
    header = new Node(-100);
}

AVL::~AVL()
{
    destory(header->left); //????????????
}

int AVL::destory(Node *p)
{
    if (p == nullptr)
        return 0;
    // test++;
    // cout << "test ==  " << test << endl;
    destory(p->left); //??????,????p??,???????p->left,p->right
    destory(p->right);
    delete p;
    p = nullptr;
}

void AVL::insert(int key)
{
    header->left = insert_real(key, header->left);
}
int AVL::get_height(Node *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}
int AVL::get_balance(Node *node)
{
    if (node == nullptr)
        return 0;
    return get_height(node->left) - get_height(node->right);
}
Node *AVL::insert_real(int key, Node *node) //???????,???????
{
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert_real(key, node->left);
    else if (key > node->key)
        node->right = insert_real(key, node->right);
    else
        return node;

    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    //??????????,?????????????? +1
    int balance = get_balance(node); //???

    // ????
    /*? "????" ????????? 2,???(? x)?????????? 1*/
    if (balance > 1 && get_balance(node->left) > 0)
        return ll_ratate(node);

    //????
    /*"????" ????????? 2,???(? x)?????????? 1?*/
    if (balance < -1 && get_balance(node->right) < 0)
        return rr_ratate(node);

    // ????
    /*"????" ????????? 2,???(? x)?????????? 1??*/
    if (balance > 1 && get_balance(node->left) < 0)
        return lr_ratate(node);

    // ????
    /*""????" ????????? 2,???(? x)?????????? 1?*/
    if (balance < -1 && get_balance(node->right) > 0)
        return rl_ratate(node);

    return node;
}
void AVL::print(int tag)
{
    if (tag == 1)
    {
        cout << " ???? : " << endl;
        root_order(header->left);
        cout << endl;
    }
    if (tag == 2)
    {
        cout << " ???? : " << endl;
        in_order(header->left);
        cout << endl;
    }
    if (tag == 3)
    {
        cout << " ???? : " << endl;
        after_order(header->left);
        cout << endl;
    }
}
void AVL::after_order(Node *root)
{
    if (root != nullptr)
    {
        after_order(root->left);
        after_order(root->right);
        cout << "[ " << root->key << " ," << root->height << " ]" << endl;
    }
}

void AVL::in_order(Node *root)
{
    if (root != nullptr)
    {
        in_order(root->left); //??????
        cout << "[ " << root->key << " ," << root->height << " ]" << endl;
        in_order(root->right);
    }
}

void AVL::root_order(Node *root)
{
    if (root != nullptr)
    {
        cout << "[ " << root->key << " ," << root->height << " ]" << endl;
        root_order(root->left); //??????
        root_order(root->right);
    }
}

Node *AVL::ll_ratate(Node *y)
{
    Node *x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    return x; //?????
}
Node *AVL::rr_ratate(Node *y)
{
    Node *x = y->right;
    y->right = x->left;
    x->left = y;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    return x;
}
Node *AVL::lr_ratate(Node *y)
{
    Node *x = y->left;
    y->left = rr_ratate(x);
    return ll_ratate(y);
}
Node *AVL::rl_ratate(Node *y)
{
    Node *x = y->right;
    y->right = ll_ratate(x);
    return rr_ratate(y);
}
Node *AVL::find(int key)
{
    return find_real(key, header->left);
}
Node *&AVL::find_real(int key, Node *&node)
{
    if (node == nullptr)
        return node;
    if (key < node->key)
        find_real(key, node->left);
    else if (key > node->key)
        find_real(key, node->right);
    else // ??????
        return node;
}

Node *AVL::loop_find(int key)
{
    Node *p = header->left; // p ?????
    while (p && p->key != key)
    {
        if (key < p->key)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}
Node *AVL::erase_real(int key, Node *node)
{
    if (node == nullptr)
    {
        cout << key << "??? AVL ??" << endl;
        return node;
    }

    if (key < node->key)
        node->left = erase_real(key, node->left);
    else if (key > node->key)
        node->right = erase_real(key, node->right);
    else
    {
        if (node->left && node->right)
        {
            // ??????
            Node *x = node->right;
            while (x->left)
                x = x->left;

            // ??????
            node->key = x->key;

            // ???????
            node->right = erase_real(x->key, node->right);
        }
        else
        {
            Node *t = node;
            node = node->left ? node->left : node->right;
            delete t;
            if (node == nullptr)
                return nullptr;
        }
    }

    node->height = max(get_height(node->left), get_height(node->right)) + 1;

    int balance = get_balance(node);

    // ????
    if (balance > 1 && get_balance(node->left) >= 0) // ?????
        return ll_ratate(node);

    // ????
    if (balance < -1 && get_balance(node->right) <= 0) // ?????
        return rr_ratate(node);

    // ????
    if (balance > 1 && get_balance(node->left) < 0)
        return lr_ratate(node);

    // ????
    if (balance < -1 && get_balance(node->right) > 0)
        return rl_ratate(node);

    return node;
}

void AVL::erase(int key)
{
    header->left = erase_real(key, header->left);
}
int main(void)
{
    AVL avl;

    // test "insert"
    vector<int> intVec{3, 2, 1, 4, 4, 5, 6, 7, 10, 9, 7, 8};

    for (auto i : intVec)
        avl.insert(i);

    avl.print(1);

    //test "find"
    Node *p = nullptr;
    cout << ((p = avl.find(2)) ? p->key : -1) << endl;   //  2
    cout << ((p = avl.find(100)) ? p->key : -1) << endl; // -1

    cout << ((p = avl.loop_find(14)) ? p->key : -1) << endl; // ????? -1
    cout << ((p = avl.loop_find(5)) ? p->key : -1) << endl;  // ???? 5

    // test "erase"
    avl.erase(100);
    avl.print(2);

    avl.erase(9);
    avl.print(3);

    avl.erase(8);
    avl.print(3);
system("pause");
    return 0;
}
