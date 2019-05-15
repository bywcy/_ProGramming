//Functions list
//I have no time to make a beautiful table to store these Functions, sooooooorry 'bout that
//And I have no time to solve the problems of Github, soooooooooorry 'bout that
//confirm arguments and return value by yourselves
//@ 2019.05.11 Ur great group leader :/

//initialize module 初始化模块
//including building graph module and order module

void initial_Coor_G()//initial coordinate graph 初始化二维图
void initial_Rel_G()//initial relational graph 初始化关系图
void initial_Tree()//initial tree 初始化树
void initial_Ord_Q()//initial order queue 初始化订单队列

//initialize inner module
//these Functions should be only used in the Functions of initial module

void confirm_Id()//confirm which node is road / cli / res 确定点的身份
int assign_Ind()//assign index to every road_nodes 给道路节点分配index
void connect_Rel()//connect relaitionship between res / cli and road 联系res/cli与road

//input / output module 输入/输出模块
//Please using function freopen to redirect stdin and stdout into file
//then maybe we can use the functions of stdin and stdout instead of file to
//manage input and output
//we ignore output in animation for a while
//ATTENTION: If we use freopen, the input and output of file and terminal are the same.
//用freopen()

void input_File()//input by file 文件输入
void input_Ter()//
void output_File()//output to file 文件输出
void output_Ter()//output to terminal 输出到终端

//duipai(in Chinese) module 对拍模块
//using random method to generate data ,which can be used to test programs
//U can ignore this module.

void data()

//simulate module 模拟模块

void floyd()//floyd to find to shortest path between road_nodes floyd找最短路
void find_Sta_P()//find the start point 找起点
int SLP_Ro()//get the shortest length of path between road_nodes and restaurant_nodes or client_nodes (I change SPL into SLP)
			//找道路节点和res/cli节点的SPL
			//下同
int SLP_Res_Res()//get the shortest length of path between res_nodes and res_nodes
int SLP_Res_Cli()//get the shortest length of path between res_nodes and cli_nodes
int SLP_Cli_Cli()//get the shortest length of path between cli_nodes and cli_nodes
//the SLP Functions essentially are SLP_Ro
//Remember to record the path using initial_Tree() 记得记录路径在树中
//If U R free U can find which are LLP(longest length path as definition)

int get_Tol_Time()//get the total time of current rider 计算总时长
void get_Inv_Ord()//the orders the current rider cannot deliver in this bout（回合）, we call "invalid orders" 
				//这一轮当前rider送不了的订单
//we need to judge if the invalid orders can be delivered by the same rider in next bout
//we need this kind of judge again and again until the current rider cannot find any valid order in new about

void judge_Step()//core algorithm ,which is to judge the next step of current rider using the tree
				//获取路径 通过树
//then we can update

//update module 更新模块也是监控模块
//also monitor modle

void up_Posi_Rider()//update the position of rider 更新骑手位置
void up_Num_Rider()//If we need more riders, using up_Num_Rider 更新骑手数量
void up_Time_Beg()//update the cost of time from beginning 更新时间
void up_Time_Ord()//update the rest of time of order 更新订单还剩下的时间
void up_Visited_Res()//update the set of visited_Res 更新集合visited_Res
void up_Visited_Cli()//update the set of visited_Cli 更新集合visited_Cli
void up_Money()//update the situation of "money" ,including bankrupt 更新钱的情况
//I thought U'd need an argument of "flag" to choose the situation
//1. If we have visited this node(res / cli), we update the set
//2. If there is another same order, we alse need to update the set

//test module 测试模块
//some module we need to test can be seen in display_up 
//these all need to be displayed 这个模块的函数都要显示出来
//ATTENTIOM: display labels that we assign to various test Function 记得显示测试模块的时候写个label做标识
void test_Rel_G()
void test_Coor_G()
void test_Tree()
void test_ord_Q()
void test_SLP()//test all kinds of SLP using Rel_G 显示各种SLP 用关系图
void display_Up()//display update module 显示更新模块的数据

//用英文的原因
//1. 避免不同系统兼容性问题导致中文乱码显示
//2. 打字更少 写得更快
//3. 不用浪费力气和脑神经做中英文转换
//If U need any help or Function list need to be added something, let me know
//God bless team 28.
//@ 2019.05.11 Ur sad group leader :(
