//
// Created by Li on 2019/5/15 21:47.
//

typedef struct orderList//information of the order
{
    int num_order;//number of the order
    int x_res,y_res;//restaurant's location
    int x_cli,y_cli;//client's location
    int dist;//length of the path between the client and the restaurant
    int t0;//starting time
    struct orderList *nextOrder;
}orderList;

typedef struct outputList//information of the order to output
{
    int pro,t;//profit and time
    int get_order;//quantity of the orders that have been got
    int over_order;//quantity of the orders that have been over
    int overtime_order;//quantity of the orders that have been overtime
    int x_rid,y_rid;//riders' location
    int num_rid;//number of riders
    int riderNum;//quantity of riders
    struct outputList *next_time;
}outputList; //for test

typedef struct coor_G_index_around//store arounding indexes of every index in the coordinate graph
{
    int x,y;
    int tag;
    int index;
}AROUND;

typedef struct coor_G_index//information of the indexes of the coordinate graph
{
    int index;//the number of the restaurant or the client if tag = 1 or 2
    int tag;//mark the index to judge whether it's road(0)/cli(1)/res(2)
    int x,y;//coordinates
    AROUND arou[5];//1:up.2:down.3:left.4:right
}COOR_G;

int RG[145][145];//relaition graph
COOR_G CG[17][17];//coordinate graph


