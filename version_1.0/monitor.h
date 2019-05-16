//
// Created by administrator on 2019/5/16.
//

#ifndef COREALGORITHM_MONITOR_H
#define COREALGORITHM_MONITOR_H

typedef struct monitor
{
    int t_until_now;
    int sum;
    int limit_time;
    int *vis_ord;
    int *vis_cli;
    int *t_start;
    int *t_end;
    int get_orders;
    int finish_orders;
    int overtime_orders;
    int x_rid;
    int y_rid;
    int num_riders;//number of riders
    int num_orders;//number of orders
}monitor;

monitor mo;

void initial_monitor();
void update_monitor();
void call_monitor();

#endif //COREALGORITHM_MONITOR_H
