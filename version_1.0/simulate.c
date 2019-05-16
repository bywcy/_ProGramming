//
// Created by administrator on 2019/5/16.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "initialize.h"
#include "simulate.h"
#include "input_output.h"
#include "monitor.h"

tree path_tree[145];

void floyd()
{
    for(int i = 1; i < 144; ++i)
        for(int j = 1; j < 144 ;++j)
            for(int k = 1; k < 144 ;++k)
            {
                if(RG[j][i] + RG[i][k] < RG[j][k])
                    RG[j][k] = RG[j][i] + RG[i][k];
            }
}

void build_tree()
{
    for(int i=1 ;i<=144 ;++i)
    {
        path_tree[i].index=i;
        path_tree[i].son=NULL;
    }
}

int add_node_tree(int index1 ,int index2)
{
    nodeP p=path_tree[index1].son;
    nodeP _p=(nodeP)malloc(sizeof(node));

    _p->index=index2;
    _p->next=NULL;

    while(p != NULL)
        p=p->next;

    p=_p;

    return _p->index;
}

int SLP_Ro_No(int index ,int x ,int y)
{
    int SLP=MAX;
    int mark_index[5];
    memset(index ,0 , sizeof(index));

    if(CG[x][y].tag == RES)
    {
        for(int i = 1; i <= 4; ++i)
        {
            int cur_index = CG[x][y].arou[i].index;
            int order_st_ti = CG[x][y].t0;
            int right=RG[index][cur_index]+mo.t_until_now;//I dont know how to name it
            int max=right>order_st_ti?right:order_st_ti;

            SLP=SLP<max?SLP:max
        }

        for(int i = 1 ;i <= 4 ;++i)
        {
            int cur_index = CG[x][y].arou[i].index;
            int order_st_ti = CG[x][y].t0;
            int right=RG[index][cur_index]+mo.t_until_now;//I dont know how to name it
            int max=right>order_st_ti?right:order_st_ti;

            if(SLP == max)
                add_node_tree(index ,cur_index);
        }
    }

    else if(CG[x][y].tag == CLI)
    {
        for(int i=1 ;i<=4 ;++i)
        {
            int cur_index = CG[x][y].arou[i].index;
            SLP=SLP<RG[index][cur_index]?SLP:RG[index][cur_index];
        }

        for(int i=1 ;i<=4 ;++i)
        {
            int cur_index = CG[x][y].arou[i].index;
            if(SLP == RG[index][cur_index])
                add_node_tree(index ,cur_index);
        }

    }
    return SLP;
}

void operate()
{
    while(mo.sum <= mo.limit_time)
}

#define A
#ifdef A

int main()
{
    int root

}


