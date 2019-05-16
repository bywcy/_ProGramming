//
// Created by administrator on 2019/5/16.
//

#include <stdio.h>
#include "monitor.h"


void initial_monitor()
{
    mo.t_until_now=0;
    mo.sum=0;
    mo.limit_time=30;
    mo.vis_ord;
    mo.vis_cli;
    mo.t_start=NULL;
    mo.t_end=NULL;
    mo.get_orders=0;
    mo.finish_orders=0;
    mo.overtime_orders=0;
    mo.x_rid=0;
    mo.y_rid=0;
    mo.num_riders=1;//number of riders
    mo.num_orders=0;//number of orders
}
