/*************************************************************************
    > File Name: myhead.h
    > Author: Liu Shengxi 
    > Mail: 13689209566@163.com
    > Created Time: 2018��07��26�� ������ 22ʱ59��58��
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
    Node *header; //header��㲢�Ǹ���㣬header->leftָ��Ĳ��Ǹ���㡣

    Node *ll_ratate(Node *y);

    Node *rr_ratate(Node *y);
    Node *lr_ratate(Node *y);
    Node *rl_ratate(Node *y);

    int get_height(Node *node);
    int get_balance(Node *node);

    Node *insert_real(int key, Node *node);
    Node *&find_real(int key, Node *&node);

    Node *erase_real(int key, Node *node);

    void in_order(Node *root);      //�������
    void root_order(Node *root);    // �������
    void after_order(Node *root); //�������

    int destory(Node *node);

public:
    AVL();
    ~AVL();
    void insert(int key);
    // (�ݹ�ʵ��)����"AVL"�м�ֵΪkey�Ľڵ�
    Node *find(int key);

    //(�ǵݹ�ʵ��)����"AVL"�м�ֵΪkey�Ľڵ�
    Node *loop_find(int key);

    void erase(int key);
    void print(int tag);
};
#endif

