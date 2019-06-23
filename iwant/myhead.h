/*************************************************************************
    > File Name: myhead.h
    > Author: Liu Shengxi 
    > Mail: 13689209566@163.com
    > Created Time: 2018年07月26日 星期四 22时59分58秒
 ************************************************************************/

#ifndef _MYHEAD_H
#define _MYHEAD_H
#include<vector>
class Node
{
public:
    int key = 0;
    int height = 0;
    Node *left = NULL;
    Node *right = null;
    Node(int key_t = 0)
    {
        key = key_t;
        height = 1;
        left = right = nullptr;
    }
};
class AVL
{
private:
    Node *header; //header结点并非根结点，header->left指向的才是根结点。

    Node *ll_ratate(Node *y);

    Node *rr_ratate(Node *y);
    Node *lr_ratate(Node *y);
    Node *rl_ratate(Node *y);

    int get_height(Node *node);
    int get_balance(Node *node);

    Node *insert_real(int key, Node *node);
    Node *&find_real(int key, Node *&node);

    Node *erase_real(int key, Node *node);

    void in_order(Node *root);      //中序遍历
    void root_order(Node *root);    // 先序遍历
    void after_order(Node *root); //后序遍历

    int destory(Node *node);

public:
    AVL();
    ~AVL();
    void insert(int key);
    // (递归实现)查找"AVL"中键值为key的节点
    Node *find(int key);

    //(非递归实现)查找"AVL"中键值为key的节点
    Node *loop_find(int key);

    void erase(int key);
    void print(int tag);
};
#endif

