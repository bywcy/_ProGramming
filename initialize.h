//initialize module 
//including building graph module and order module

#ifndef INITIALIZE_H
#define INITIALIZE_H 

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

extern COOR_G CG[][17];
extern int RG[][145];

void initial_Coor_G(COOR_G a[][17]);//initial coordinate graph 
void initial_Rel_G();//initial relational graph 
void initial_Tree();//initial tree
void initial_Ord_Q();//initial order queue

//initialize inner module
//these Functions should be only used in the Functions of initial module

void confirm_Id();//confirm which node is road / cli / res
int assign_Ind();//assign index to every road_nodes 
void connect_Rel();//connect relaitionship between res / cli and road

#endif 

//2019.5.15 16:07 by Cui Siying
