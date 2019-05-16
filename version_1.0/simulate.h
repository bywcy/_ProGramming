//
// Created by administrator on 2019/5/15.
//

#ifndef COREALGORITHM_STIMULATE_H
#define COREALGORITHM_STIMULATE_H

typedef struct node
{
    int index;
    struct node *next;
}node ,*nodeP;

typedef struct tree
{
    int index;
    struct node *son;
}tree ,*treeP;

extern tree path_tree[145];

void build_tree();
int add_node_tree(int index1 ,int index2);//return the index of the added node
void floyd();
void find_start_P();
int SLP_Ro(int index1 ,int index2);
int SLP_Ro_No(int index ,int x ,int y);
int SLP_Res_Res(int x1 ,int y1 ,int x2 ,int y2);
int SLP_Res_Cli(int x1 ,int y1 ,int x2 ,int y2);
int SLP_Cli_Cli(int x1 ,int y1 ,int x2 ,int y2);


#endif //COREALGORITHM_STIMULATE_H
