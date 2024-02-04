#include <iostream>
using namespace std;
class Robot{
public:
    unsigned int team;
    unsigned int identifier;
    unsigned int type;
    int blood_volume;
    int heat;
    unsigned int rate;
    unsigned int state;
};
class Destroy_robot{
public:
    unsigned int team;
    unsigned int identifier;
};
class Manager{
public:
    unsigned int time;
    char command;
    unsigned int num_1;//所属队伍
    unsigned int num_2;//机器人标识符
    unsigned int num_3;
};
void kill_blood(unsigned int a,int *b,int *c,unsigned int d,unsigned int e,unsigned int *f)
{
    if(a==1) {
        if(*b>0) {
            if (*b-e > 0) {
                *c-=e;
                *b-=e;
            } else {
                *c-=*b;
                *b=0;
            }
        }//工程机器人
    }
    else {
        if(d==1)
        {
            if(*b>100) {
                if (*b - e > 100) {
                    *c-=e;
                    *b-=e;
                } else {
                    *c-=*b;
                    *b=100;
                }
            }
        }
        if(d==2)
        {
            if(*b>200) {
                if (*b - e > 200) {
                    c -= e;
                    *b-=e;
                } else {
                    *c -= *b;
                    *b=200;
                }
            }
        }
        if(d==3)
        {
            if(*b>300) {
                if (*b- e > 300) {
                    *c-= e;
                    *b-=e;
                } else {
                    *c-=*b;
                    *b=300;
                }
            }
        }
    }


}
int main() {
    int N,j=0,r=0;//j用来记录机器人数量
    cin>>N;//输入有几行命令
    Manager manager[N];
    Robot robot[2000];
    Destroy_robot destroyRobot[2000];

    for(int i=0;i<N;i++) {
        int judge=0;
        cin >> manager[i].time >> manager[i].command>> manager[i].num_1>> manager[i].num_2 >> manager[i].num_3;
        if(manager[i].command=='A')
        {
            for(int c=0;c<j;c++)
            {
                if(robot[c].state==1) {
                    kill_blood(robot[c].type, &robot[c].heat, &robot[c].blood_volume, robot[c].rate, manager[i].time,
                               &robot[c].state);
                    if(robot[c].blood_volume<=0)
                    {
                        robot[c].state=2;
                        destroyRobot[r].team=robot[c].team;
                        destroyRobot[r].identifier=robot[c].identifier;
                        r++;
                    }
                }
                if(robot[c].state==2)//2代表被击毁
                {
                    if(robot[c].team ==manager[i].num_1&&robot[c].identifier==manager[i].num_2&&robot[c].type==manager[i].num_3)//满足指令A的条件
                    {
                        robot[c].state=1;//1代表正常机器人
                        robot[c].heat=0;
                        if(manager[i].num_3==0)
                        {
                            robot[c].blood_volume=100;
                            robot[c].rate =1;
                        }
                        else
                        {
                            robot[c].blood_volume=300;
                            robot[c].rate =0;
                        }
                        judge=1;

                    }

                }
                else
                {
                    if(robot[c].team ==manager[i].num_1&&robot[c].identifier==manager[i].num_2&&robot[c].type==manager[i].num_3)//满足指令A的条件
                    {
                        judge=2;
                    }

                }
            }
            if(judge==0)//如果既没找到被击毁的机器人，也没找到正常机器人，则添加新机器人
            {
                robot[j].team=manager[i].num_1;
                robot[j].identifier=manager[i].num_2;
                robot[j].type=manager[i].num_3;
                robot[j].state =1;
                robot[j].heat =0;
                if(manager[i].num_3==0)
                {
                    robot[j].blood_volume=100;
                    robot[j].rate =1;
                }
                else
                {
                    robot[j].blood_volume=300;
                    robot[j].rate =0;
                }
                j++;
            }

        }

        if(manager[i].command=='F')//命令字F
        {

            for(int c=0;c<j;c++)
            {
                if(robot[c].state==1) {
                    kill_blood(robot[c].type, &robot[c].heat, &robot[c].blood_volume, robot[c].rate, manager[i].time,
                               &robot[c].state);
                    if(robot[c].blood_volume<=0)
                    {
                        robot[c].state=2;
                        destroyRobot[r].team=robot[c].team;
                        destroyRobot[r].identifier=robot[c].identifier;
                        r++;
                    }
                }
            }
            for(int c=0;c<j;c++)
            {
                if(robot[c].state ==1)
                {
                    if(robot[c].team ==manager[i].num_1&&robot[c].identifier==manager[i].num_2)
                    {

                        robot[c].blood_volume -= manager[i].num_3;
                        if (robot[c].blood_volume <= 0) {
                            robot[c].state = 2;//被击毁
                            destroyRobot[r].team=robot[c].team;
                            destroyRobot[r].identifier=robot[c].identifier;
                            r++;
                        }
                    }
                }


            }
        }
        if(manager[i].command=='H') {
            for (int c = 0; c < j; c++) {
                if(robot[c].state==1) {
                    kill_blood(robot[c].type, &robot[c].heat, &robot[c].blood_volume, robot[c].rate, manager[i].time,
                               &robot[c].state);
                    if(robot[c].blood_volume<=0)
                    {
                        robot[c].state=2;
                        destroyRobot[r].team=robot[c].team;
                        destroyRobot[r].identifier=robot[c].identifier;
                        r++;
                    }
                }
                if (robot[c].state == 1) {
                    if (robot[c].team == manager[i].num_1 && robot[c].identifier == manager[i].num_2) {
                        if (robot[c].type == 0) {
                            robot[c].heat += manager[i].num_3;
                        }
                    }
                }
            }
        }
        if(manager[i].command=='U')
        {
            for(int c=0;c<j;c++)
            {
                if(robot[c].state==1) {
                    kill_blood(robot[c].type, &robot[c].heat, &robot[c].blood_volume, robot[c].rate, manager[i].time,
                               &robot[c].state);
                    if(robot[c].blood_volume<=0)
                    {
                        robot[c].state=2;
                        destroyRobot[r].team=robot[c].team;
                        destroyRobot[r].identifier=robot[c].identifier;
                        r++;
                    }
                }
                if(robot[c].state==1)
                {
                    if(robot[c].team ==manager[i].num_1&&robot[c].identifier==manager[i].num_2)
                    {
                        if(robot[c].type==0) {
                            if (manager[i].num_3 > robot[c].rate) {
                                if (manager[i].num_3 == 2) {
                                    robot[c].blood_volume = 150;
                                } else {
                                    robot[c].blood_volume = 250;
                                }
                            }
                        }
                    }
                }
            }


        }
    }//输入多行指令并处理
    for(int i=0;i<r;i++)
    {
        cout<<'D'<<" "<<destroyRobot[i].team<<" "<<destroyRobot[i].identifier<<endl;
    }

    return 0;
}
