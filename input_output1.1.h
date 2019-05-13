//input / output module 

#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

struct orderList//information of the order
{
    int num_order;//number of the order
    int x_res,y_res;//restaurant's location
    int x_cli,y_cli;//client's location
    int dist;//length of the path between the client and the restaurant
    int t0;//starting time
    struct orderList *nextOrder;
}; 
typedef struct orderList orderlist;
typedef orderlist *orderlistptr;

struct outputList//information of the order to output
{
    int pro,t;//profit and time
	int get_order;//quantity of the orders that have been got
	int over_order;//quantity of the orders that have been over 
	int overtime_order;//quantity of the orders that have been overtime
	int x_rid,y_rid;//riders' location
	int num_rid;//number of riders
	int riderNum;//quantity of riders
	struct outputList *next_time; 
}; 
typedef struct outputList outputlist;
typedef outputlist *outputlistptr;

orderlistptr input_File();//input by file 
void input_Ter();//input by terminal
void output_File();//output to file 
void output_Ter();//output to terminal 

#endif


