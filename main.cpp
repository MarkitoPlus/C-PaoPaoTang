#include<stdio.h>
#include<vector>
#include<iostream>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
#include<ege.h>
#include<mmsystem.h>
using namespace std;
#define width 14
#define length 14
int Map[width][length];
PIMAGE start;
PIMAGE play;
PIMAGE itr;
PIMAGE play1;
PIMAGE itr1;
PIMAGE jsh;
PIMAGE bk;
PIMAGE tool;
PIMAGE daoju;
PIMAGE sel;
PIMAGE sel1;
PIMAGE sel2;
PIMAGE rzhuan;
PIMAGE ground;
PIMAGE ltree;
PIMAGE house;
PIMAGE shatan;
PIMAGE yezishu;
PIMAGE yizi;
PIMAGE lengyin;
PIMAGE haixing;
PIMAGE wanju;
PIMAGE mofang;
PIMAGE jinggao;
PIMAGE banshou;
PIMAGE wanjuche;
PIMAGE danjian;
PIMAGE danyi;
PIMAGE dankun;
PIMAGE shuangjian;
PIMAGE shuangyi;
PIMAGE shuangkun;
PIMAGE people1;
PIMAGE people2;
PIMAGE zd1;
PIMAGE zd2;
PIMAGE shengming;
PIMAGE chuizi;
PIMAGE bingqiang;
PIMAGE hudun;
PIMAGE xiezi;
PIMAGE huidu;
PIMAGE zdw1;
PIMAGE zdw2;
PIMAGE zanting;
PIMAGE sl1;
PIMAGE sl2;
PIMAGE shijiandao;
PIMAGE zhasi;
PIMAGE bing;
PIMAGE bingqiang1;
PIMAGE bingqiang2;
PIMAGE shengming1;
PIMAGE shengming2;
PIMAGE hudun1;
PIMAGE hudun2;
PIMAGE xiezi1;
PIMAGE xiezi2;
PIMAGE yaoshui1;
PIMAGE yaoshui2;
PIMAGE yaoshui3;
PIMAGE huaban1;
PIMAGE huaban2;
PIMAGE huaban3;
int second;
void st();//��ʼ
void js();//����
void dj();//����
void sele();//ѡ��
void dr();//����
void sr();//˫��
void dpy1();//����Ϸ
void dpy2();//��ͨ��Ϸ
void dpy3();//������Ϸ
void spy1();//����Ϸ
void spy2();//��ͨ��Ϸ
void spy3();//������Ϸ
void Move1();//1P�����ƶ�
void Move2();//2P�����ƶ�
void Boom1();//ը��
void playsoundst()//��ʼ����
{
	PlaySound(TEXT("��ʼ����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void playsoundyx1()//��Ϸ����
{
	PlaySound(TEXT("��Ϸ����1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void playsoundyx2()//��Ϸ����
{
	PlaySound(TEXT("��Ϸ����2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void playsoundyx3()//��Ϸ����
{
	PlaySound(TEXT("��Ϸ����3.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void playsoundfzd()//��ը��
{
    PlaySound(TEXT("��ը��.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void playsoundbz()//��ը
{
    PlaySound(TEXT("��ը.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void playsoundjs()//����
{
    PlaySound(TEXT("��Ϸ����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
//1P�����
class person
{
private:
    int x;
    int y;
    int v;
    int dir;
    PIMAGE* p;
    int num_zha;
    int sm;
    int fanwei=2;
public:

    person(int x1,int y1,int v1,PIMAGE* p1,int num1)
    {
        x=x1;
        y=y1;
        v=v1;
        p=p1;
        dir=0;
        num_zha=num1;
    }
    void setfw(int f)
    {
        fanwei=f;
    }
    int getfw()
    {
        return fanwei;
    }
    void setP(PIMAGE* pp)
    {
        p=pp;
    }
    int getX()//��ȡ��ҵ�x����
    {
        return x;
    }
    int getY()//��ȡ��ҵ�y����
    {
        return y;
    }
    int getNum()//��ȡ���ը������
    {
        return num_zha;
    }
    void setX(int x1)//�������x����
    {
        x=x1;
    }
    void setY(int y1)//�������y����
    {
        y=y1;
    }
    void setdir(int d)//������ҷ���
    {
        dir=d;
    }
    void setNum(int num)//�������ը������
    {
        num_zha=num;
    }
    void setsm(int ssmm)
    {
        sm=ssmm;
    }
    void setv(int v1)
    {
        v=v1;
    }
    int getSm()
    {
        return sm;
    }
    int getV()//��ȡ����ٶ�
    {
        return v;
    }
    int getdir()//��ȡ��ҷ���
    {
        return dir;
    }
    void loadpeople()//��������ͼƬ
    {
        putimage_transparent(NULL,*p,x,y,BLACK);
    }
    void adjust()//����ҵ�λ����������
    {
        if(dir==1)//��������ƣ�����λ�õ�������������
        {
            x-=v;
            if(x%30!=0){
                if((x)/30 != (x-v)/30){
                    x=(x/30-1)*30;
                }
            }
        }
        if(dir==2)//��������ƣ�����λ�õ�������������
        {
            x+=v;
            if(x%30!=0){
                if((x)/30 != (x+v)/30){
                    x=(x/30+1)*30;
                }
            }
        }
        if(dir==3)//��������ƣ�����λ�õ�������������
        {
            y-=v;
            if(y%30!=0){
                if((y)/30 != (y-v)/30){
                    y=(y/30-1)*30;
                }
            }
        }
        if(dir==4)//��������ƣ�����λ�õ�������������
        {
            y+=v;
            if(y%30!=0){
                 if((y)/30 != (y+v)/30){
                    y=(y/30+1)*30;
                 }
            }
        }

        if(x<30) x=30;
        else if(x>390)x=390;
        if(y<30)y=30;
        else if(y>390)y=390;

        if(x%30==0 && y%30==0){
            dir=0;
        }
    }
};
//�������1
person P1(30,30,2,&people1,2);
//�������2
person P2(390,390,2,&people2,2);

//1Pը����
class zhadan
{
private:
    int x;//ը��x����
    int y;//ը��y����
    person* p;//ը��������
    person* pp;
    PIMAGE *z;
    PIMAGE *s;
    int time;//ը��ͣ��ʱ�䣬Ϊһ��Ĭ��ֵ
    int lb,rb,ub,db;
public:
    zhadan(int x1,int y1,person* p1,PIMAGE *z1,PIMAGE *s1)//���캯��
    {
        x=x1;
        y=y1;
        p=p1;
        z=z1;
        s=s1;
        time=60*2;
    }
    zhadan(int x1,int y1,person* p1,person *p2,PIMAGE *z1,PIMAGE *s1)//���캯��
    {
        x=x1;
        y=y1;
        p=p1;
        pp=p2;
        z=z1;
        s=s1;
        time=60*2;
    }
    int getX()//��ȡը����x����
    {
        return x;
    }
    int getY()//��ȡը����y����
    {
        return y;
    }
    person * getPerson()//��ȡը���������
    {
        return p;
    }
    bool checkalive()//�ж�ը���Ƿ�ը
    {
        time--;
        if(time==30)
        {
            mciSendString("close MySong", NULL, 0, NULL);
            mciSendString(TEXT("open ��ը.wav alias mysong"), NULL, 0, NULL);
            mciSendString(TEXT("play MySong"), NULL, 0, NULL);
        }
        if(time<=5 && time>0){
            loadboom();
        }
        if(time==0)
        {
            //mciSendString("close MySong", NULL, 0, NULL);
            return false;
        }
        return true;
    }
    void setX(int x1)//����ը��x����
    {
        x=x1;
    }
    void setY(int y1)//����ը��y����
    {
        y=y1;
    }
    void setfw(int b)
    {
        lb=rb=ub=db=b;
    }
    void loadzd()//����ը��ͼƬ
    {
        putimage_transparent(NULL,*z,x,y,BLACK);
    }
    void loadboom()//ը����ը˲��
    {
        int r1=rand()%6;
        int flag=0,ff=0;
        lb=rb=ub=db=p->getfw();
        for(int j=0;j<lb;j++){

            if(x-j*30>=30)//������ը��Χ����Խ��
            {
                if(Map[y/30][(x-j*30)/30]!=6)//����ը��Χ���ǿ�ը���壬��ըΪƽ��
                {
                    putimage_transparent(NULL,*s,x-j*30,y,BLACK);
                    //Map[y/30][(x-j*30)/30]=7;
                    if(j!=0&&Map[y/30][(x-j*30)/30]!=7)
                    {
                        if(r1==0)
                        {
                            Map[y/30][(x-j*30)/30]=1;
                            //putimage_transparent(NULL,bingqiang,x-j*30,y,BLACK);
                        }
                        else if(r1==1)
                        {
                            Map[y/30][(x-j*30)/30]=2;
                           // putimage_transparent(NULL,xiezi,x-j*30,y,BLACK);
                        }
                        else if(r1==2)
                        {
                            Map[y/30][(x-j*30)/30]=3;
                          //  putimage_transparent(NULL,hudun,x-j*30,y,BLACK);
                        }
                        else if(r1==3)
                        {
                            Map[y/30][(x-j*30)/30]=4;
                           // putimage_transparent(NULL,shengming,x-j*30,y,BLACK);
                        }
                        else if(r1==4)
                        {
                            Map[y/30][(x-j*30)/30]=10;
                           // putimage_transparent(NULL,shengming,x-j*30,y,BLACK);
                        }
                        else if(r1==5)
                        {
                            Map[y/30][(x-j*30)/30]=11;
                          //  putimage_transparent(NULL,shengming,x-j*30,y,BLACK);
                        }
                    }
                }
                else break;
            }
            else{
                //lb=j;
                break;//������磬������
            }
            if(x-j*30==p->getX() && y==p->getY())//�ж��������
            {
                flag=1;
            }
            if(x-j*30==pp->getX() && y==pp->getY())//�ж��������
            {
                ff=1;
            }
        }
        r1=rand()%6;
        for(int j=0;j<rb;j++){
            if(x+j*30<420)//������ը��Χ����Խ��
            {
                if(Map[y/30][(x+j*30)/30]!=6)//����ը��Χ���ǿ�ը���壬��ըΪƽ��
                {
                    putimage_transparent(NULL,*s,x+j*30,y,BLACK);
                   // Map[y/30][(x+j*30)/30]=7;
                    if(j!=0&&Map[y/30][(x+j*30)/30]!=7)
                    {
                        if(r1==3)
                        {
                            Map[y/30][(x+j*30)/30]=1;
                           // putimage_transparent(NULL,bingqiang,x+j*30,y,BLACK);
                        }
                        else if(r1==2)
                        {
                            Map[y/30][(x+j*30)/30]=2;
                           // putimage_transparent(NULL,xiezi,x+j*30,y,BLACK);
                        }
                        else if(r1==1)
                        {
                            Map[y/30][(x+j*30)/30]=3;
                           // putimage_transparent(NULL,hudun,x+j*30,y,BLACK);
                        }
                        else if(r1==4)
                        {
                            Map[y/30][(x+j*30)/30]=4;
                           // putimage_transparent(NULL,shengming,x+j*30,y,BLACK);
                        }
                        else if(r1==5)
                        {
                            Map[y/30][(x+j*30)/30]=10;
                           // putimage_transparent(NULL,hudun,x+j*30,y,BLACK);
                        }
                        else if(r1==0)
                        {
                            Map[y/30][(x+j*30)/30]=11;
                           // putimage_transparent(NULL,shengming,x+j*30,y,BLACK);
                        }
                    }
                }
                else break;
            }
            else{
                //lb=j;
                break;//������磬������
            }
            if(x+j*30==p->getX() && y==p->getY())//�ж��������
            {
                flag=1;
            }
            if(x+j*30==pp->getX() && y==pp->getY())//�ж��������
            {
                ff=1;
            }
        }
        r1=rand()%6;
        for(int j=0;j<db;j++){
            if(y+j*30<420)//������ը��Χ����Խ��
            {
                if(Map[(y+j*30)/30][x/30]!=6)//����ը��Χ���ǿ�ը���壬��ըΪƽ��
                {
                    putimage_transparent(NULL,*s,x,y+j*30,BLACK);
                   // Map[(y+j*30)/30][x/30]=7;
                    if(j!=0&&Map[(y+j*30)/30][x/30]!=7)
                    {
                        if(r1==2)
                        {
                           // putimage_transparent(NULL,bingqiang,x,y+j*30,BLACK);
                            Map[(y+j*30)/30][x/30]=1;
                        }
                        else if(r1==3)
                        {
                           // putimage_transparent(NULL,xiezi,x,y+j*30,BLACK);
                            Map[(y+j*30)/30][x/30]=2;
                        }
                        else if(r1==4)
                        {
                           // putimage_transparent(NULL,hudun,x,y+j*30,BLACK);
                            Map[(y+j*30)/30][x/30]=3;
                        }
                        else if(r1==5)
                        {
                           // putimage_transparent(NULL,shengming,x,y+j*30,BLACK);
                            Map[(y+j*30)/30][x/30]=4;
                        }
                        else if(r1==1)
                        {
                            //putimage_transparent(NULL,hudun,x,y+j*30,BLACK);
                            Map[(y+j*30)/30][x/30]=10;
                        }
                        else if(r1==0)
                        {
                            //putimage_transparent(NULL,shengming,x,y+j*30,BLACK);
                            Map[(y+j*30)/30][x/30]=11;
                        }
                    }
                }
                else break;//������磬������
            }
            else{
                //lb=j;
                break;//������磬������
            }
            if(x==p->getX() && y+j*30==p->getY())//�ж��������
            {
                flag=1;
            }
            if(x==pp->getX() && y+j*30==pp->getY())//�ж��������
            {
                ff=1;
            }
        }
        r1=rand()%6;
        for(int j=0;j<ub;j++){
            if(y-j*30>=30)//������ը��Χ����Խ��
            {
                if(Map[(y-j*30)/30][x/30]!=6)//����ը��Χ���ǿ�ը���壬��ըΪƽ��
                {
                    putimage_transparent(NULL,*s,x,y-j*30,BLACK);
                    //Map[(y-j*30)/30][x/30]=7;
                    if(j!=0&&Map[(y-j*30)/30][x/30]!=7)
                    {
                        if(r1==3)
                        {
                            //putimage_transparent(NULL,bingqiang,x,y-j*30,BLACK);
                            Map[(y-j*30)/30][x/30]=1;
                        }
                        else if(r1==0)
                        {
                            //putimage_transparent(NULL,xiezi,x,y-j*30,BLACK);
                            Map[(y-j*30)/30][x/30]=2;
                        }
                        else if(r1==1)
                        {
                            //putimage_transparent(NULL,hudun,x,y-j*30,BLACK);
                            Map[(y-j*30)/30][x/30]=3;
                        }
                        else if(r1==5)
                        {
                           // putimage_transparent(NULL,shengming,x,y-j*30,BLACK);
                            Map[(y-j*30)/30][x/30]=4;
                        }
                        else if(r1==2)
                        {
                           // putimage_transparent(NULL,hudun,x,y-j*30,BLACK);
                            Map[(y-j*30)/30][x/30]=10;
                        }
                        else if(r1==4)
                        {
                            //putimage_transparent(NULL,shengming,x,y-j*30,BLACK);
                            Map[(y-j*30)/30][x/30]=11;
                        }
                    }
                }
                else break;
            }
            else{
                //lb=j;
                break;//������磬������
            }
            if(x==p->getX() && y-j*30==p->getY())//�ж��������
            {
                flag=1;
            }
            if(x==pp->getX() && y-j*30==pp->getY())//�ж��������
            {
                ff=1;
            }
        }
        if(flag==1)p->setsm(p->getSm()-1);//��������һ��
        if(ff==1)pp->setsm(pp->getSm()-1);//��������һ��
        //Sleep(1000);//ʹͼƬ����ڼ�֡
    }
};
vector<zhadan>array_zha;//ը������

//��ʼ����
void st()
{
    mciSendString("close MySong", NULL, 0, NULL);
    playsoundst();
    yaoshui1=newimage();
    yaoshui2=newimage();
    yaoshui3=newimage();
    huaban1=newimage();
    huaban2=newimage();
    huaban3=newimage();
    hudun1=newimage();
    hudun2=newimage();
    shengming1=newimage();
    shengming2=newimage();
    xiezi1=newimage();
    xiezi2=newimage();
    bingqiang1=newimage();
    bingqiang2=newimage();
    zhasi=newimage();
    shijiandao=newimage();
    sl1=newimage();
    sl2=newimage();
    zanting=newimage();
    people1=newimage();
    people2=newimage();
    zdw1=newimage();
    zdw2=newimage();
    zd1=newimage();
    zd2=newimage();
    start=newimage();
    play=newimage();
    itr=newimage();
    play1=newimage();
    itr1=newimage();
    jinggao=newimage();
    shengming=newimage();
    chuizi=newimage();
    bingqiang=newimage();
    hudun=newimage();
    xiezi=newimage();
    huidu=newimage();
    bing=newimage();
    getimage(huaban1,"img\\huaban1.png");
    getimage(huaban2,"img\\huaban2.png");
    getimage(huaban3,"img\\huaban3.png");
    getimage(yaoshui1,"img\\yaoshui1.png");
    getimage(yaoshui2,"img\\yaoshui2.png");
    getimage(yaoshui3,"img\\yaoshui3.png");
    getimage(start,"img\\start.png");
    getimage(play,"img\\play.png");
    getimage(itr,"img\\itr.png");
    getimage(play1,"img\\play1.png");
    getimage(itr1,"img\\itr1.png");
    getimage(people1,"img\\renqian1.png");
    getimage(people2,"img\\renqian2.png");
    getimage(zd1,"img\\zhadan.png");
    getimage(zd1,"img\\zhadan.png");
    getimage(jinggao,"img\\����.png");
    getimage(shengming,"img\\shengming.png");
    getimage(xiezi,"img\\xiezi.png");
    getimage(chuizi,"img\\chuizi.png");
    getimage(hudun,"img\\hudun.png");
    getimage(bingqiang,"img\\bingqiang.png");
    getimage(bing,"img\\bing.png");
    getimage(hudun1,"img\\hudun1.png");
    getimage(hudun2,"img\\hudun2.png");
    getimage(shengming1,"img\\shengming1.png");
    getimage(xiezi1,"img\\xiezi1.png");
    getimage(shengming2,"img\\shengming2.png");
    getimage(xiezi2,"img\\xiezi2.png");
    getimage(bingqiang1,"img\\bingqiang1.png");
    getimage(bingqiang2,"img\\bingqiang2.png");
	putimage(0,0,start);
	mouse_msg msg = {0};
	int flag=0,flag1=0,tm=0;
	for ( ; is_run(); delay_fps(60))
	{
		int x, y;
		tm++;
		mousepos(&x, &y);
		if(x>=218&&x<=299&&y>=310&y<=339)
        {
            putimage_transparent(NULL,play1,200,260,BLACK);
        }
        else if(x>=218&&x<=299&&y>=370&y<=399)
        {
            putimage_transparent(NULL,itr1,200,320,BLACK);
        }
        else
        {
            putimage_transparent(NULL,play,200,260,BLACK);
            putimage_transparent(NULL,itr,200,320,BLACK);
        }
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=24&&x<=56&&y>=26&y<=64&&msg.is_left()==1&&msg.is_down()==1&&flag==0&&tm>6)
        {
            PlaySound(NULL,NULL,SND_FILENAME);
            flag1=1;
            tm=0;
        }
        if(x>=24&&x<=56&&y>=26&y<=64&&msg.is_left()==1&&msg.is_down()==1&&flag==1&&tm>6)
        {
            PlaySound(TEXT("��ʼ����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            flag1=0;
            tm=0;
        }
		if(x>=218&&x<=299&&y>=310&y<=339&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            sele();
            break;
        }
        if(x>=218&&x<=299&&y>=370&y<=399&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            js();
            break;
        }
        if(flag1==1)
        {
            flag=1;
        }
        else flag=0;
        /*if(flag%2==1)
        {
            flag1=1;
            PlaySound(NULL,NULL,SND_FILENAME);
        }
        else if(flag1==0)continue;
        else if(flag%2==0)
        {
            flag1=0;
            PlaySound(TEXT("��ʼ����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        }*/
	}
}

//��Ϸ����
void js()
{
    jsh=newimage();
    bk=newimage();
    tool=newimage();
    getimage(jsh,"img\\jsh.jpg");
    getimage(bk,"img\\bk.png");
    getimage(tool,"img\\tool.png");
    putimage(0,0,jsh);
    mouse_msg msg = {0};
    putimage_transparent(NULL,bk,60,370,BLACK);
    putimage_transparent(NULL,tool,160,370,BLACK);
	for ( ; is_run(); delay_fps(60))
	{
		int x, y;
		mousepos(&x, &y);
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=74&&x<=137&&y>=372&y<=399&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            st();
            break;
        }
        else if(x>=173&&x<=238&&y>=372&y<=399&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            dj();
            break;
        }
	}
}

//��Ϸ����
void dj()
{
    daoju=newimage();
    getimage(daoju,"img\\daoju.jpg");
    putimage(0,0,daoju);
    putimage_transparent(NULL,bk,140,390,BLACK);
    mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(60))
	{
		int x, y;
		mousepos(&x, &y);
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=153&&x<=217&&y>=393&y<=419&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            js();
            break;
        }
	}
}

//ѡ��ģʽ
void sele()
{
    sel=newimage();
    getimage(sel,"img\\sel.jpg");
    putimage(0,0,sel);
    mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(60))
	{
		int x, y;
		mousepos(&x, &y);
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=125&&x<=224&&y>=241&y<=263&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            dr();
            break;
        }
        else if(x>=125&&x<=224&&y>=289&y<=311&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            sr();
            break;
        }
        else if(x>=125&&x<=224&&y>=335&y<=358&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            st();
            break;
        }
	}
}

//����
void dr()
{
    sel1=newimage();
    getimage(sel1,"img\\sel1.png");
    putimage(0,0,sel1);
    mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(60))
	{
		int x, y;
		mousepos(&x, &y);
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=125&&x<=224&&y>=241&y<=263&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            dpy1();
            break;
        }
        else if(x>=125&&x<=224&&y>=289&y<=311&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            dpy2();
            break;
        }
        else if(x>=125&&x<=224&&y>=335&y<=358&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            dpy3();
            break;
        }
        else if(x>=125&&x<=224&&y>=387&y<=403&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            sele();
            break;
        }
	}
}

//˫��
void sr()
{
    sel2=newimage();
    getimage(sel2,"img\\sel2.png");
    putimage(0,0,sel2);
    mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(60))
	{
		int x, y;
		mousepos(&x, &y);
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=125&&x<=224&&y>=241&y<=263&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            spy1();
            break;
        }
        else if(x>=125&&x<=224&&y>=289&y<=311&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            spy2();
            break;
        }
        else if(x>=125&&x<=224&&y>=335&y<=358&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            spy3();
            break;
        }
        else if(x>=125&&x<=224&&y>=387&y<=403&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            sele();
            break;
        }
	}
}

//1P�����ƶ�
void Move1(person &p,int dir)//��������ͷ���
{
    if(dir==1)//��
    {
        p.setdir(dir);
        getimage(people1,"img\\renzuo1.png");
    }
    else if(dir==2)//��
    {
        p.setdir(dir);
        getimage(people1,"img\\renyou1.png");
    }
    else if(dir==3)//��
    {
        p.setdir(dir);
        getimage(people1,"img\\renhou1.png");
    }
    else if(dir==4)//��
    {
        p.setdir(dir);
        getimage(people1,"img\\renqian1.png");
    }
}

//2P�����ƶ�
void Move2(person &p,int dir)//��������ͷ���
{
   if(dir==1)//��
    {
        p.setdir(dir);
        getimage(people2,"img\\renzuo2.png");
    }
    else if(dir==2)//��
    {
        p.setdir(dir);
        getimage(people2,"img\\renyou2.png");
    }
    else if(dir==3)//��
    {
        p.setdir(dir);
        getimage(people2,"img\\renhou2.png");
    }
    else if(dir==4)//��
    {
        p.setdir(dir);
        getimage(people2,"img\\renqian2.png");
    }
}

//1pը������
void zdwan1()
{
    getimage(zdw1,"img\\ը����1.png");
    mouse_msg msg = {0};
    for ( ; is_run(); delay_fps(60))
	{
	    int x,y;
		putimage_transparent(NULL,zdw1,0,0,BLACK);
		mousepos(&x, &y);
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=286&&x<=354&&y>=372&y<=401&&msg.is_left()==1&&msg.is_down()==1)
        {
            st();
            break;
        }
	}
}

//2pը������
void zdwan2()
{
    getimage(zdw2,"img\\ը����2.png");
    mouse_msg msg = {0};
    for ( ; is_run(); delay_fps(60))
	{
	    int x,y;
		putimage_transparent(NULL,zdw2,0,0,BLACK);
		mousepos(&x, &y);
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=286&&x<=354&&y>=372&y<=401&&msg.is_left()==1&&msg.is_down()==1)
        {
            st();
            break;
        }
	}
}

//��ͣ��Ϸ
void zt()
{
    getimage(huidu,"img\\�Ҷ�.png");
    getimage(zanting,"img\\��ͣ.png");
    putimage_alphablend(NULL, huidu, 0, 0, 0x80);
    mouse_msg msg = {0};
    for ( ; is_run(); delay_fps(60))
	{
	    int x, y;
		mousepos(&x, &y);
		while (mousemsg())
		{
			msg = getmouse();
		}
        putimage_transparent(NULL,zanting,0,0,BLACK);
        if(x>=0&&x<=640&&y>=0&&y<=480&&!(x>=182&&x<=265&&y>=435&y<=466)&&!(x>=513&&x<=601&&y>=428&y<=457)&&msg.is_left()==1&&msg.is_down()==1)
            break;
	}
}

//����ģʽ��Ұ��Լ�ը��
void zs()
{
    getimage(huidu,"img\\�Ҷ�.png");
    getimage(zhasi,"img\\zhasi.png");
    putimage_alphablend(NULL, huidu, 0, 0, 0x80);
    mouse_msg msg = {0};
    int sum=0;
    for ( ; is_run(); delay_fps(60))
    {
        sum++;
        if(sum==90)
            PlaySound(NULL,NULL,SND_FILENAME);
        int x, y;
        mousepos(&x, &y);
        while (mousemsg())
        {
            msg = getmouse();
        }
        putimage_transparent(NULL,zhasi,0,0,BLACK);
        if(x>=0&&x<=640&&y>=0&&y<=480&&!(x>=182&&x<=265&&y>=435&y<=466)&&!(x>=513&&x<=601&&y>=428&y<=457)&&msg.is_left()==1&&msg.is_down()==1)
        {
            break;
        }
    }
}

//1���������2�����ʤ��
void shengli1()
{
    getimage(huidu,"img\\�Ҷ�.png");
    getimage(sl1,"img\\shengli1.png");
    putimage_alphablend(NULL, huidu, 0, 0, 0x80);
    mouse_msg msg = {0};
    int sum=0;
    for ( ; is_run(); delay_fps(60))
    {
        sum++;
        if(sum==90)
            PlaySound(NULL,NULL,SND_FILENAME);
        int x, y;
        mousepos(&x, &y);
        while (mousemsg())
        {
            msg = getmouse();
        }
        putimage_transparent(NULL,sl1,0,0,BLACK);
        if(x>=0&&x<=640&&y>=0&&y<=480&&!(x>=182&&x<=265&&y>=435&y<=466)&&!(x>=513&&x<=601&&y>=428&y<=457)&&msg.is_left()==1&&msg.is_down()==1)
        {
            break;
        }
    }
}

//2���������1�����ʤ��
void shengli2()
{
    getimage(huidu,"img\\�Ҷ�.png");
    getimage(sl2,"img\\shengli2.png");
    putimage_alphablend(NULL, huidu, 0, 0, 0x80);
    mouse_msg msg = {0};
    int sum=0;
    for ( ; is_run(); delay_fps(60))
    {
        sum++;
        if(sum==90)
            PlaySound(NULL,NULL,SND_FILENAME);
        int x, y;
        mousepos(&x, &y);
        while (mousemsg())
        {
            msg = getmouse();
        }
        putimage_transparent(NULL,sl2,0,0,BLACK);
        if(x>=0&&x<=640&&y>=0&&y<=480&&!(x>=182&&x<=265&&y>=435&y<=466)&&!(x>=513&&x<=601&&y>=428&y<=457)&&msg.is_left()==1&&msg.is_down()==1)
        {
            break;
        }
    }
}

//ʱ�䵽
void sjd()
{
    getimage(huidu,"img\\�Ҷ�.png");
    getimage(shijiandao,"img\\ʱ�䵽.png");
    putimage_alphablend(NULL, huidu, 0, 0, 0x80);
    mouse_msg msg = {0};
    int sum=0;
    for ( ; is_run(); delay_fps(60))
    {
        sum++;
        if(sum==90)
            PlaySound(NULL,NULL,SND_FILENAME);
        int x, y;
        mousepos(&x, &y);
        while (mousemsg())
        {
            msg = getmouse();
        }
        putimage_transparent(NULL,shijiandao,0,0,BLACK);
        if(x>=0&&x<=640&&y>=0&&y<=480&&!(x>=182&&x<=265&&y>=435&y<=466)&&!(x>=513&&x<=601&&y>=428&y<=457)&&msg.is_left()==1&&msg.is_down()==1)
        {
            break;
        }
    }
}

//���˼���Ϸ
void dpy1()
{
    PlaySound(NULL,NULL,SND_FILENAME);
    playsoundyx1();
    second=180;
    P1.setX(30);
    P1.setY(30);
    P1.setsm(6);
    P2.setsm(6);
    //P2.setX(390);
    //P2.setY(390);
    danjian=newimage();
    getimage(danjian,"img\\���˼�.jpg");
    getimage(rzhuan,"img\\��ɫשͷ.jpg");
    getimage(ground,"img\\�ݵ�.jpg");
    getimage(house,"img\\����.jpg");
    getimage(ltree,"img\\����.jpg");
    putimage(0,0,danjian);
    srand(time(NULL));
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    if((fp1=fopen("��map1.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    if((fp2=fopen("��map2.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    if((fp3=fopen("��map3.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    int xu=rand()%3;
    if(xu==0)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp1,"%d",&Map[i][j]);
            }
        }
    }
    else if(xu==1)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp2,"%d",&Map[i][j]);
            }
        }
    }
    else if(xu==2)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp3,"%d",&Map[i][j]);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    for(int i=1;i<width;i++)
    {
        for(int j=1;j<length;j++)
        {
            putimage_transparent(NULL,ground,j*30,i*30,BLACK);//��ͼΪ7
        }
    }
    for(int i=1;i<width;i++)
    {
        for(int j=1;j<length;j++)
        {
            if(Map[i][j]==5) putimage(j*30,i*30,house);
            else if(Map[i][j]==1)putimage_transparent(NULL,ground,j*30,i*30,BLACK);
            else if(Map[i][j]==2)putimage_transparent(NULL,ground,j*30,i*30,BLACK);
            else if(Map[i][j]==3)putimage_transparent(NULL,ground,j*30,i*30,BLACK);
            else if(Map[i][j]==4)putimage_transparent(NULL,ground,j*30,i*30,BLACK);
            else if(Map[i][j]==6)putimage_transparent(NULL,rzhuan,j*30,i*30,BLACK);
            else if(Map[i][j]==7)putimage_transparent(NULL,ground,j*30,i*30,BLACK);
            else if(Map[i][j]==8)putimage_transparent(NULL,ltree,j*30,i*30,BLACK);
        }
    }
    setcolor(EGERGB(248,248,255));
    setfont(16, 0, "����");
    mouse_msg msg = {0};
    int flag,sum=0,n,m,xieshijian=200,bingshijian=500,yaoshijian=500;
	for ( ; is_run(); delay_fps(60))
	{
	    xieshijian++;
	    bingshijian++;
	    yaoshijian++;
	    if(bingshijian==480)getimage(chuizi,"img\\chuizi.png");
	    if(xieshijian==180)P1.setv(2);
	    if(yaoshijian==480)P1.setfw(2);
	    flag=0;
	    putimage(0,0,danjian);
        char str1[10],str2[10],t[10];
	    sprintf(str1, "%d ��", P1.getNum());
	    setbkmode(TRANSPARENT);
        outtextxy(515, 140, str1);
        sum++;
	    if(sum%60==0)
        {
            second--;
        }
        sprintf(t, "%d ��", second);
	    setbkmode(TRANSPARENT);
        outtextxy(560, 374, t);

	    if(GetAsyncKeyState(VK_LEFT) && P1.getdir()==0)//�����ƶ�
        {
            if(Map[P1.getY()/30][P1.getX()/30-1]==7)
                Move1(P1,1);
            else if((Map[P1.getY()/30][P1.getX()/30-1]>=1&&Map[P1.getY()/30][P1.getX()/30-1]<=4)||(Map[P1.getY()/30][P1.getX()/30-1]>=10&&Map[P1.getY()/30][P1.getX()/30-1]<=11))
            {
                if(Map[P1.getY()/30][P1.getX()/30-1]==2||Map[P1.getY()/30][P1.getX()/30-1]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==3||Map[P1.getY()/30][P1.getX()/30-1]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==10)
                {
                    P1.setfw(3);
                    yaoshijian=0;
                }
                n=P1.getY()/30;
                m=P1.getX()/30-1;
                Move1(P1,1);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_RIGHT) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30][P1.getX()/30+1]==7)
                Move1(P1,2);
            else if((Map[P1.getY()/30][P1.getX()/30+1]>=1&&Map[P1.getY()/30][P1.getX()/30+1]<=4)||(Map[P1.getY()/30][P1.getX()/30+1]>=10&&Map[P1.getY()/30][P1.getX()/30+1]<=11))
            {
                if(Map[P1.getY()/30][P1.getX()/30+1]==2||Map[P1.getY()/30][P1.getX()/30+1]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==3||Map[P1.getY()/30][P1.getX()/30+1]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==10)
                {
                    P1.setfw(3);
                    yaoshijian=0;
                }
                n=P1.getY()/30;
                m=P1.getX()/30+1;
                Move1(P1,2);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_UP) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30-1][P1.getX()/30]==7)
                Move1(P1,3);
            else if((Map[P1.getY()/30-1][P1.getX()/30]>=1&&Map[P1.getY()/30-1][P1.getX()/30]<=4)||(Map[P1.getY()/30-1][P1.getX()/30]>=10&&Map[P1.getY()/30-1][P1.getX()/30]<=11))
            {
                if(Map[P1.getY()/30-1][P1.getX()/30]==2||Map[P1.getY()/30-1][P1.getX()/30]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==3||Map[P1.getY()/30-1][P1.getX()/30]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==10)
                {
                    yaoshijian++;
                    P1.setfw(3);
                }
                n=P1.getY()/30-1;
                m=P1.getX()/30;
                Move1(P1,3);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_DOWN) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30+1][P1.getX()/30]==7)
                Move1(P1,4);
            else if((Map[P1.getY()/30+1][P1.getX()/30]>=1&&Map[P1.getY()/30+1][P1.getX()/30]<=4)||(Map[P1.getY()/30+1][P1.getX()/30]>=10&&Map[P1.getY()/30+1][P1.getX()/30]<=11))
            {
                if(Map[P1.getY()/30+1][P1.getX()/30]==2||Map[P1.getY()/30+1][P1.getX()/30]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==3||Map[P1.getY()/30+1][P1.getX()/30]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==10)
                {
                    yaoshijian++;
                    P1.setfw(3);
                }
                n=P1.getY()/30+1;
                m=P1.getX()/30;
                Move1(P1,4);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    //������λ������Ӧ�ĵ���
	    P1.adjust();

	    //����ը��
        if(GetAsyncKeyState(VK_SPACE))
        {
            if(P1.getNum()>0 && (Map[P1.getY()/30][P1.getX()/30]==7)||(Map[P1.getY()/30][P1.getX()/30]>=1&&Map[P1.getY()/30][P1.getX()/30]<=4))//�ж������Ƿ���ը�����������λ���Ƿ���Է�ը��
            {
                zhadan temp(P1.getX(),P1.getY(),&P1,&zd1,&chuizi);//����һ����ʱը�������
                array_zha.push_back(temp); //��ը������ը��������
                P1.setNum(P1.getNum()-1);//�������ը����ӵ�е�ը��������1
                sprintf(str1, "%d ��", P1.getNum());
                setbkmode(TRANSPARENT);
                outtextxy(470, 140, str1);
                Map[P1.getY()/30][P1.getX()/30]=777;//���ը��λ�ã���ʱ���ﲻ�ܴ����λ��ͨ��
            }
        }
        //ˢ�µ�ͼ
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                if(Map[i][j]==5) putimage(j*30,i*30,house);
                else if(Map[i][j]==1)putimage_transparent(NULL,bingqiang,j*30,i*30,BLACK);
                else if(Map[i][j]==2)putimage_transparent(NULL,xiezi,j*30,i*30,BLACK);
                else if(Map[i][j]==3)putimage_transparent(NULL,hudun,j*30,i*30,BLACK);
                else if(Map[i][j]==4)putimage_transparent(NULL,shengming,j*30,i*30,BLACK);
                else if(Map[i][j]==6)putimage_transparent(NULL,rzhuan,j*30,i*30,BLACK);
                else if(Map[i][j]==7)putimage_transparent(NULL,ground,j*30,i*30,BLACK);
                else if(Map[i][j]==8)putimage_transparent(NULL,ltree,j*30,i*30,BLACK);
                else if(Map[i][j]==777)putimage_transparent(NULL,ground,j*30,i*30,BLACK);
                else if(Map[i][j]==10)putimage_transparent(NULL,yaoshui1,j*30,i*30,BLACK);
                else if(Map[i][j]==11)putimage_transparent(NULL,huaban1,j*30,i*30,BLACK);
            }
        }
        //ը����ը˲��
        for(int i=0;i<array_zha.size();i++)
        {
            array_zha[i].loadzd();//ը�����ú���
            if(array_zha[i].checkalive()==false){
                array_zha[i].loadboom();//ը����ը
                Map[array_zha[i].getY()/30][array_zha[i].getX()/30]=7;//ը����ը��ɺ��Ϊ�յ�
                array_zha[i].getPerson()->setNum(array_zha[i].getPerson()->getNum()+1);//ը����ը���������ӵ�е�ը����1
                array_zha.erase(array_zha.begin()+i);//����ը���ը���Ƴ�����
            }
        }

        P1.loadpeople();//��������
        if(second==0)
        {
            sjd();
            break;
        }
        sprintf(str2, "%d ��", P1.getSm()/6);
        setbkmode(TRANSPARENT);
        outtextxy(515, 175, str2);
        if(P1.getSm()/6==0&&P1.getSm()%6==0)
        {
            PlaySound(NULL,NULL,SND_FILENAME);
            playsoundjs();
            zs();
            break;
        }
		int x, y;
		mousepos(&x, &y);
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=182&&x<=265&&y>=435&y<=466&&msg.is_left()==1&&msg.is_down()==1)
        {
            zt();
            putimage(0,0,danjian);
            //break;
        }
        else if(x>=513&&x<=601&&y>=428&y<=457&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            break;
        }
	}
	st();
}

//����һ����Ϸ
void dpy2()
{
    playsoundyx2();
    second=180;
    P1.setsm(6);
    P2.setsm(6);
    P1.setX(30);
    P1.setY(30);
    danyi=newimage();
    getimage(danyi,"img\\����һ��.jpg");
    getimage(shatan,"img\\shatan.png");
    getimage(yizi,"img\\yizi.png");
    getimage(yezishu,"img\\yezishu.png");
    getimage(lengyin,"img\\lengyin.png");
    getimage(haixing,"img\\haixing.png");
    putimage(0,0,danyi);
    srand(time(NULL));
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    if((fp1=fopen("һ��map1.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    if((fp2=fopen("һ��map2.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    if((fp3=fopen("һ��map3.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    int xu=rand()%3;
    if(xu==0)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp1,"%d",&Map[i][j]);
            }
        }
    }
    else if(xu==1)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp2,"%d",&Map[i][j]);
            }
        }
    }
    else if(xu==2)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp3,"%d",&Map[i][j]);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    for(int i=1;i<width;i++)
    {
        for(int j=1;j<length;j++)
        {
            putimage_transparent(NULL,shatan,j*30,i*30,BLACK);//��ͼΪ7
        }
    }
    for(int i=1;i<width;i++)
    {
        for(int j=1;j<length;j++)
        {
            if(Map[i][j]==5) putimage_transparent(NULL,lengyin,j*30,i*30,BLACK);
            else if(Map[i][j]==6)putimage_transparent(NULL,yizi,j*30,i*30,BLACK);
            else if(Map[i][j]==7)putimage_transparent(NULL,shatan,j*30,i*30,BLACK);
            else if(Map[i][j]==8)putimage_transparent(NULL,yezishu,j*30,i*30,BLACK);
            else if(Map[i][j]==9)putimage_transparent(NULL,haixing,j*30,i*30,BLACK);
        }
    }
    setcolor(EGERGB(248,248,255));
    setfont(16, 0, "����");
    mouse_msg msg = {0};
    int flag,sum=0,n,m,xieshijian=200,bingshijian=500,yaoshijian=500;
	for ( ; is_run(); delay_fps(60))
	{
        xieshijian++;
	    bingshijian++;
	    yaoshijian++;
	    if(bingshijian==480)getimage(chuizi,"img\\chuizi.png");
	    if(xieshijian==180)P1.setv(2);
	    if(yaoshijian==480)P1.setfw(2);
	    flag=0;
	    putimage(0,0,danyi);
	    char str1[10],str2[10],t[10];
	    sprintf(str1, "%d ��", P1.getNum());
	    setbkmode(TRANSPARENT);
        outtextxy(515, 140, str1);
        sum++;
	    if(sum%60==0)
        {
            second--;
        }
        sprintf(t, "%d ��", second);
	    setbkmode(TRANSPARENT);
        outtextxy(560, 374, t);

	    if(GetAsyncKeyState(VK_LEFT) && P1.getdir()==0)//�����ƶ�
        {
            if(Map[P1.getY()/30][P1.getX()/30-1]==7)
                Move1(P1,1);
            else if((Map[P1.getY()/30][P1.getX()/30-1]>=1&&Map[P1.getY()/30][P1.getX()/30-1]<=4)||(Map[P1.getY()/30][P1.getX()/30-1]>=10&&Map[P1.getY()/30][P1.getX()/30-1]<=11))
            {
                if(Map[P1.getY()/30][P1.getX()/30-1]==2||Map[P1.getY()/30][P1.getX()/30-1]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==3||Map[P1.getY()/30][P1.getX()/30-1]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==10)
                {
                    P1.setfw(3);
                    yaoshijian=0;
                }
                n=P1.getY()/30;
                m=P1.getX()/30-1;
                Move1(P1,1);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_RIGHT) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30][P1.getX()/30+1]==7)
                Move1(P1,2);
            else if((Map[P1.getY()/30][P1.getX()/30+1]>=1&&Map[P1.getY()/30][P1.getX()/30+1]<=4)||(Map[P1.getY()/30][P1.getX()/30+1]>=10&&Map[P1.getY()/30][P1.getX()/30+1]<=11))
            {
                if(Map[P1.getY()/30][P1.getX()/30+1]==2||Map[P1.getY()/30][P1.getX()/30+1]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==3||Map[P1.getY()/30][P1.getX()/30+1]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==10)
                {
                    P1.setfw(3);
                    yaoshijian=0;
                }
                n=P1.getY()/30;
                m=P1.getX()/30+1;
                Move1(P1,2);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_UP) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30-1][P1.getX()/30]==7)
                Move1(P1,3);
            else if((Map[P1.getY()/30-1][P1.getX()/30]>=1&&Map[P1.getY()/30-1][P1.getX()/30]<=4)||(Map[P1.getY()/30-1][P1.getX()/30]>=10&&Map[P1.getY()/30-1][P1.getX()/30]<=11))
            {
                if(Map[P1.getY()/30-1][P1.getX()/30]==2||Map[P1.getY()/30-1][P1.getX()/30]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==3||Map[P1.getY()/30-1][P1.getX()/30]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==10)
                {
                    yaoshijian++;
                    P1.setfw(3);
                }
                n=P1.getY()/30-1;
                m=P1.getX()/30;
                Move1(P1,3);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_DOWN) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30+1][P1.getX()/30]==7)
                Move1(P1,4);
            else if((Map[P1.getY()/30+1][P1.getX()/30]>=1&&Map[P1.getY()/30+1][P1.getX()/30]<=4)||(Map[P1.getY()/30+1][P1.getX()/30]>=10&&Map[P1.getY()/30+1][P1.getX()/30]<=11))
            {
                if(Map[P1.getY()/30+1][P1.getX()/30]==2||Map[P1.getY()/30+1][P1.getX()/30]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==3||Map[P1.getY()/30+1][P1.getX()/30]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==10)
                {
                    yaoshijian++;
                    P1.setfw(3);
                }
                n=P1.getY()/30+1;
                m=P1.getX()/30;
                Move1(P1,4);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    //������λ������Ӧ�ĵ���
	    P1.adjust();

	    //����ը��
        if(GetAsyncKeyState(VK_SPACE))
        {
            if(P1.getNum()>0 && Map[P1.getY()/30][P1.getX()/30]==7)//�ж������Ƿ���ը�����������λ���Ƿ���Է�ը��
            {
                zhadan temp(P1.getX(),P1.getY(),&P1,&zd1,&chuizi);//����һ����ʱը�������
                array_zha.push_back(temp);//��ը������ը��������
                P1.setNum(P1.getNum()-1);//�������ը����ӵ�е�ը��������1
                sprintf(str1, "%d ��", P1.getNum());
                setbkmode(TRANSPARENT);
                outtextxy(470, 140, str1);
                Map[P1.getY()/30][P1.getX()/30]=777;//���ը��λ�ã���ʱ���ﲻ�ܴ����λ��ͨ��
            }

        }
        //ˢ�µ�ͼ
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                if(Map[i][j]==5) putimage_transparent(NULL,lengyin,j*30,i*30,BLACK);
                else if(Map[i][j]==1)putimage_transparent(NULL,bingqiang1,j*30,i*30,BLACK);
                else if(Map[i][j]==2)putimage_transparent(NULL,xiezi1,j*30,i*30,BLACK);
                else if(Map[i][j]==3)putimage_transparent(NULL,hudun1,j*30,i*30,BLACK);
                else if(Map[i][j]==4)putimage_transparent(NULL,shengming1,j*30,i*30,BLACK);
                else if(Map[i][j]==6)putimage_transparent(NULL,yizi,j*30,i*30,BLACK);
                else if(Map[i][j]==7)putimage_transparent(NULL,shatan,j*30,i*30,BLACK);
                else if(Map[i][j]==8)putimage_transparent(NULL,yezishu,j*30,i*30,BLACK);
                else if(Map[i][j]==9)putimage_transparent(NULL,haixing,j*30,i*30,BLACK);
                else if(Map[i][j]==777)putimage_transparent(NULL,shatan,j*30,i*30,BLACK);
                else if(Map[i][j]==10)putimage_transparent(NULL,yaoshui2,j*30,i*30,BLACK);
                else if(Map[i][j]==11)putimage_transparent(NULL,huaban2,j*30,i*30,BLACK);
            }
        }
        //ը����ը˲��
        for(int i=0;i<array_zha.size();i++)
        {
            array_zha[i].loadzd();//ը�����ú���
            if(array_zha[i].checkalive()==false){
                array_zha[i].loadboom();//ը����ը
                Map[array_zha[i].getY()/30][array_zha[i].getX()/30]=7;//ը����ը��ɺ��Ϊ�յ�
                array_zha[i].getPerson()->setNum(array_zha[i].getPerson()->getNum()+1);//ը����ը���������ӵ�е�ը����1
                array_zha.erase(array_zha.begin()+i);//����ը���ը���Ƴ�����

            }
        }
        P1.loadpeople();//��������
        if(second==0)
        {
            sjd();
            break;
        }
        sprintf(str2, "%d ��", P1.getSm()/6);
        setbkmode(TRANSPARENT);
        outtextxy(515, 175, str2);
        if(P1.getSm()/6==0&&P1.getSm()%6==0)
        {
            PlaySound(NULL,NULL,SND_FILENAME);
            playsoundjs();
            zs();
            break;
        }
		int x, y;
		mousepos(&x, &y);
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=182&&x<=265&&y>=435&y<=466&&msg.is_left()==1&&msg.is_down()==1)
        {
            zt();
            putimage(0,0,danyi);
        }
        else if(x>=513&&x<=601&&y>=428&y<=457&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            break;
        }
	}
	st();
}

//����������Ϸ
void dpy3()
{
    playsoundyx3();
    int flag,sum=0,n,m,xieshijian=200,bingshijian=500,yaoshijian=500;
    second=180;
    P1.setsm(6);
    P2.setsm(6);
    P1.setX(30);
    P1.setY(30);
    dankun=newimage();
    getimage(dankun,"img\\��������.jpg");
    getimage(wanju,"img\\���.png");
    getimage(wanjuche,"img\\��߳�.png");
    getimage(mofang,"img\\ħ��.png");
    getimage(jinggao,"img\\����.png");
    getimage(banshou,"img\\����.png");
    putimage(0,0,dankun);
    srand(time(NULL));
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    if((fp1=fopen("����map1.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    if((fp2=fopen("����map2.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    if((fp3=fopen("����map3.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    int xu=rand()%3;
    if(xu==0)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp1,"%d",&Map[i][j]);
            }
        }
    }
    else if(xu==1)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp2,"%d",&Map[i][j]);
            }
        }
    }
    else if(xu==2)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp3,"%d",&Map[i][j]);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    for(int i=1;i<width;i++)
    {
        for(int j=1;j<length;j++)
        {
            putimage_transparent(NULL,wanju,j*30,i*30,BLACK);//��ͼΪ7
        }
    }
    for(int i=1;i<width;i++)
    {
        for(int j=1;j<length;j++)
        {
            if(Map[i][j]==5) putimage_transparent(NULL,wanjuche,j*30,i*30,BLACK);
            else if(Map[i][j]==6)putimage_transparent(NULL,banshou,j*30,i*30,BLACK);
            else if(Map[i][j]==7)putimage_transparent(NULL,wanju,j*30,i*30,BLACK);
            else if(Map[i][j]==8)putimage_transparent(NULL,mofang,j*30,i*30,BLACK);
            else if(Map[i][j]==9)putimage_transparent(NULL,jinggao,j*30,i*30,BLACK);
        }
    }
    setcolor(EGERGB(248,248,255));
    setfont(16, 0, "����");
    mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(60))
	{
        xieshijian++;
	    bingshijian++;
	    yaoshijian++;
	    if(yaoshijian==480)P1.setfw(3);
	    if(bingshijian==480)getimage(chuizi,"img\\chuizi.png");
	    if(xieshijian==180)P1.setv(2);
	    flag=0;
	    putimage(0,0,dankun);
	    char str1[10],str2[10],t[10];
	    sprintf(str1, "%d ��", P1.getNum());
	    setbkmode(TRANSPARENT);
        outtextxy(515, 140, str1);
        sum++;
        if(sum%60==0)
        {
            second--;
        }
        sprintf(t, "%d ��", second);
	    setbkmode(TRANSPARENT);
        outtextxy(560, 374, t);

	    if(GetAsyncKeyState(VK_LEFT) && P1.getdir()==0)//�����ƶ�
        {
            if(Map[P1.getY()/30][P1.getX()/30-1]==7)
                Move1(P1,1);
            else if((Map[P1.getY()/30][P1.getX()/30-1]>=1&&Map[P1.getY()/30][P1.getX()/30-1]<=4)||(Map[P1.getY()/30][P1.getX()/30-1]>=10&&Map[P1.getY()/30][P1.getX()/30-1]<=11))
            {
                if(Map[P1.getY()/30][P1.getX()/30-1]==2||Map[P1.getY()/30][P1.getX()/30-1]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==3||Map[P1.getY()/30][P1.getX()/30-1]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==10)
                {
                    P1.setfw(3);
                    yaoshijian=0;
                }
                n=P1.getY()/30;
                m=P1.getX()/30-1;
                Move1(P1,1);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_RIGHT) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30][P1.getX()/30+1]==7)
                Move1(P1,2);
            else if((Map[P1.getY()/30][P1.getX()/30+1]>=1&&Map[P1.getY()/30][P1.getX()/30+1]<=4)||(Map[P1.getY()/30][P1.getX()/30+1]>=10&&Map[P1.getY()/30][P1.getX()/30+1]<=11))
            {
                if(Map[P1.getY()/30][P1.getX()/30+1]==2||Map[P1.getY()/30][P1.getX()/30+1]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==3||Map[P1.getY()/30][P1.getX()/30+1]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==10)
                {
                    P1.setfw(3);
                    yaoshijian=0;
                }
                n=P1.getY()/30;
                m=P1.getX()/30+1;
                Move1(P1,2);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_UP) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30-1][P1.getX()/30]==7)
                Move1(P1,3);
            else if((Map[P1.getY()/30-1][P1.getX()/30]>=1&&Map[P1.getY()/30-1][P1.getX()/30]<=4)||(Map[P1.getY()/30-1][P1.getX()/30]>=10&&Map[P1.getY()/30-1][P1.getX()/30]<=11))
            {
                if(Map[P1.getY()/30-1][P1.getX()/30]==2||Map[P1.getY()/30-1][P1.getX()/30]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==3||Map[P1.getY()/30-1][P1.getX()/30]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==10)
                {
                    yaoshijian++;
                    P1.setfw(3);
                }
                n=P1.getY()/30-1;
                m=P1.getX()/30;
                Move1(P1,3);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_DOWN) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30+1][P1.getX()/30]==7)
                Move1(P1,4);
            else if((Map[P1.getY()/30+1][P1.getX()/30]>=1&&Map[P1.getY()/30+1][P1.getX()/30]<=4)||(Map[P1.getY()/30+1][P1.getX()/30]>=10&&Map[P1.getY()/30+1][P1.getX()/30]<=11))
            {
                if(Map[P1.getY()/30+1][P1.getX()/30]==2||Map[P1.getY()/30+1][P1.getX()/30]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==3||Map[P1.getY()/30+1][P1.getX()/30]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==10)
                {
                    yaoshijian++;
                    P1.setfw(3);
                }
                n=P1.getY()/30+1;
                m=P1.getX()/30;
                Move1(P1,4);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    //������λ������Ӧ�ĵ���
	    P1.adjust();

	    //����ը��
        if(GetAsyncKeyState(VK_SPACE))
        {
            if(P1.getNum()>0 && Map[P1.getY()/30][P1.getX()/30]==7)//�ж������Ƿ���ը�����������λ���Ƿ���Է�ը��
            {
                zhadan temp(P1.getX(),P1.getY(),&P1,&zd1,&chuizi);//����һ����ʱը�������
                array_zha.push_back(temp);//��ը������ը��������
                P1.setNum(P1.getNum()-1);//�������ը����ӵ�е�ը��������1
                sprintf(str1, "%d ��", P1.getNum());
                setbkmode(TRANSPARENT);
                outtextxy(470, 140, str1);
                Map[P1.getY()/30][P1.getX()/30]=777;//���ը��λ�ã���ʱ���ﲻ�ܴ����λ��ͨ��
            }

        }
        //ˢ�µ�ͼ
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                if(Map[i][j]==5) putimage_transparent(NULL,wanjuche,j*30,i*30,BLACK);
                else if(Map[i][j]==1)putimage_transparent(NULL,bingqiang2,j*30,i*30,BLACK);
                else if(Map[i][j]==2)putimage_transparent(NULL,xiezi2,j*30,i*30,BLACK);
                else if(Map[i][j]==3)putimage_transparent(NULL,hudun2,j*30,i*30,BLACK);
                else if(Map[i][j]==4)putimage_transparent(NULL,shengming2,j*30,i*30,BLACK);
                else if(Map[i][j]==6)putimage_transparent(NULL,banshou,j*30,i*30,BLACK);
                else if(Map[i][j]==7)putimage_transparent(NULL,wanju,j*30,i*30,BLACK);
                else if(Map[i][j]==8)putimage_transparent(NULL,mofang,j*30,i*30,BLACK);
                else if(Map[i][j]==9)putimage_transparent(NULL,jinggao,j*30,i*30,BLACK);
                else if(Map[i][j]==777)putimage_transparent(NULL,wanju,j*30,i*30,BLACK);
                else if(Map[i][j]==10)putimage_transparent(NULL,yaoshui3,j*30,i*30,BLACK);
                else if(Map[i][j]==11)putimage_transparent(NULL,huaban3,j*30,i*30,BLACK);
            }
        }
        //ը����ը˲��
        for(int i=0;i<array_zha.size();i++)
        {
            array_zha[i].loadzd();//ը�����ú���
            if(array_zha[i].checkalive()==false){
                array_zha[i].loadboom();//ը����ը
                Map[array_zha[i].getY()/30][array_zha[i].getX()/30]=7;//ը����ը��ɺ��Ϊ�յ�
                array_zha[i].getPerson()->setNum(array_zha[i].getPerson()->getNum()+1);//ը����ը���������ӵ�е�ը����1
                array_zha.erase(array_zha.begin()+i);//����ը���ը���Ƴ�����

            }
        }
        P1.loadpeople();//��������
        if(second==0)
        {
            sjd();
            break;
        }
        sprintf(str2, "%d ��", P1.getSm()/6);
        setbkmode(TRANSPARENT);
        outtextxy(515, 175, str2);
        if(P1.getSm()/6==0&&P1.getSm()%6==0)
        {
            PlaySound(NULL,NULL,SND_FILENAME);
            playsoundjs();
            zs();
            break;
        }
		int x, y;
		mousepos(&x, &y);
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=182&&x<=265&&y>=435&y<=466&&msg.is_left()==1&&msg.is_down()==1)
        {
            zt();
            putimage(0,0,dankun);
        }
        else if(x>=513&&x<=601&&y>=428&y<=457&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            break;
        }
	}
	st();
}

//˫�˼���Ϸ
void spy1()
{
    playsoundyx1();
    int flag,sum=0,n,m,xieshijian=200,bingshijian=500,xieshijian1=200,bingshijian1=500,yaoshijian=500,yaoshijian1=500;
    second=180;
    P1.setsm(6);
    P2.setsm(6);
    P1.setX(30);
    P1.setY(30);
    P2.setX(390);
    P2.setY(390);
    shuangjian=newimage();
    getimage(shuangjian,"img\\˫�˼�.jpg");
    getimage(rzhuan,"img\\��ɫשͷ.jpg");
    getimage(ground,"img\\�ݵ�.jpg");
    getimage(house,"img\\����.jpg");
    getimage(ltree,"img\\����.jpg");
    putimage(0,0,shuangjian);
    srand(time(NULL));
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    if((fp1=fopen("��map1.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    if((fp2=fopen("��map2.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    if((fp3=fopen("��map3.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    int xu=rand()%3;
    if(xu==0)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp1,"%d",&Map[i][j]);
            }
        }
    }
    else if(xu==1)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp2,"%d",&Map[i][j]);
            }
        }
    }
    else if(xu==2)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp3,"%d",&Map[i][j]);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    for(int i=1;i<width;i++)
    {
        for(int j=1;j<length;j++)
        {
            putimage_transparent(NULL,ground,j*30,i*30,BLACK);//��ͼΪ7
        }
    }
    for(int i=1;i<width;i++)
    {
        for(int j=1;j<length;j++)
        {
            if(Map[i][j]==5) putimage(j*30,i*30,house);
            else if(Map[i][j]==6)putimage_transparent(NULL,rzhuan,j*30,i*30,BLACK);
            else if(Map[i][j]==7)putimage_transparent(NULL,ground,j*30,i*30,BLACK);
            else if(Map[i][j]==8)putimage_transparent(NULL,ltree,j*30,i*30,BLACK);
        }
    }
    setcolor(EGERGB(248,248,255));
    setfont(16, 0, "����");
    mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(60))
	{
	    xieshijian++;
	    bingshijian++;
	    xieshijian1++;
	    bingshijian1++;
	    yaoshijian1++;
	    yaoshijian++;
	    if(yaoshijian1==480)P2.setfw(3);
	    if(yaoshijian==480)P1.setfw(3);
	    if(bingshijian==480)getimage(chuizi,"img\\chuizi.png");
	    if(xieshijian==180)P1.setv(2);
	    if(bingshijian1==480)getimage(chuizi,"img\\chuizi.png");
	    if(xieshijian1==180)P2.setv(2);
	    flag=0;
	    putimage(0,0,shuangjian);
	    char str1[10],str2[10],str3[10],str4[10],t[10];
	    sprintf(str1, "%d ��", P1.getNum());
	    sprintf(str3, "%d ��", P2.getNum());
	    setbkmode(TRANSPARENT);
        outtextxy(470, 140, str1);
        outtextxy(555, 140, str3);
        sum++;
	    if(sum%60==0)
        {
            second--;
        }
        sprintf(t, "%d ��", second);
	    setbkmode(TRANSPARENT);
        outtextxy(560, 374, t);

	    if(GetAsyncKeyState(VK_LEFT) && P1.getdir()==0)//�����ƶ�
        {
            if(Map[P1.getY()/30][P1.getX()/30-1]==7)
                Move1(P1,1);
            else if((Map[P1.getY()/30][P1.getX()/30-1]>=1&&Map[P1.getY()/30][P1.getX()/30-1]<=4)||(Map[P1.getY()/30][P1.getX()/30-1]>=10&&Map[P1.getY()/30][P1.getX()/30-1]<=11))
            {
                if(Map[P1.getY()/30][P1.getX()/30-1]==2||Map[P1.getY()/30][P1.getX()/30-1]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==3||Map[P1.getY()/30][P1.getX()/30-1]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==10)
                {
                    P1.setfw(3);
                    yaoshijian=0;
                }
                n=P1.getY()/30;
                m=P1.getX()/30-1;
                Move1(P1,1);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_RIGHT) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30][P1.getX()/30+1]==7)
                Move1(P1,2);
            else if((Map[P1.getY()/30][P1.getX()/30+1]>=1&&Map[P1.getY()/30][P1.getX()/30+1]<=4)||(Map[P1.getY()/30][P1.getX()/30+1]>=10&&Map[P1.getY()/30][P1.getX()/30+1]<=11))
            {
                if(Map[P1.getY()/30][P1.getX()/30+1]==2||Map[P1.getY()/30][P1.getX()/30+1]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==3||Map[P1.getY()/30][P1.getX()/30+1]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==10)
                {
                    P1.setfw(3);
                    yaoshijian=0;
                }
                n=P1.getY()/30;
                m=P1.getX()/30+1;
                Move1(P1,2);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_UP) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30-1][P1.getX()/30]==7)
                Move1(P1,3);
            else if((Map[P1.getY()/30-1][P1.getX()/30]>=1&&Map[P1.getY()/30-1][P1.getX()/30]<=4)||(Map[P1.getY()/30-1][P1.getX()/30]>=10&&Map[P1.getY()/30-1][P1.getX()/30]<=11))
            {
                if(Map[P1.getY()/30-1][P1.getX()/30]==2||Map[P1.getY()/30-1][P1.getX()/30]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==3||Map[P1.getY()/30-1][P1.getX()/30]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==10)
                {
                    yaoshijian++;
                    P1.setfw(3);
                }
                n=P1.getY()/30-1;
                m=P1.getX()/30;
                Move1(P1,3);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_DOWN) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30+1][P1.getX()/30]==7)
                Move1(P1,4);
            else if((Map[P1.getY()/30+1][P1.getX()/30]>=1&&Map[P1.getY()/30+1][P1.getX()/30]<=4)||(Map[P1.getY()/30+1][P1.getX()/30]>=10&&Map[P1.getY()/30+1][P1.getX()/30]<=11))
            {
                if(Map[P1.getY()/30+1][P1.getX()/30]==2||Map[P1.getY()/30+1][P1.getX()/30]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==3||Map[P1.getY()/30+1][P1.getX()/30]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==10)
                {
                    yaoshijian++;
                    P1.setfw(3);
                }
                n=P1.getY()/30+1;
                m=P1.getX()/30;
                Move1(P1,4);
                Map[n][m]=7;
                flag=1;
            }
	    }

	    if(GetAsyncKeyState('A') && P2.getdir()==0)//����2�ƶ�
        {
            if(Map[P2.getY()/30][P2.getX()/30-1]==7)
                Move2(P2,1);
            else if((Map[P2.getY()/30][P2.getX()/30-1]>=1&&Map[P2.getY()/30][P2.getX()/30-1]<=4)||(Map[P2.getY()/30][P2.getX()/30-1]>=10&&Map[P2.getY()/30][P2.getX()/30-1]<=11))
            {
                if(Map[P2.getY()/30][P2.getX()/30-1]==2||Map[P2.getY()/30][P2.getX()/30-1]==11)
                {
                    P2.setv(3);
                    xieshijian1=0;
                }
                if(Map[P2.getY()/30][P2.getX()/30-1]==3||Map[P2.getY()/30][P2.getX()/30-1]==4)
                {
                    P2.setsm(P2.getSm()+6);
                }
                if(Map[P2.getY()/30][P2.getX()/30-1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian1=0;
                }
                if(Map[P2.getY()/30][P2.getX()/30-1]==10)
                {
                    P2.setfw(3);
                    yaoshijian1=0;
                }
                n=P2.getY()/30;
                m=P2.getX()/30-1;
                Move2(P2,1);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState('D') && P2.getdir()==0)
        {
            if(Map[P2.getY()/30][P2.getX()/30+1]==7)
                Move2(P2,2);
            else if((Map[P2.getY()/30][P2.getX()/30+1]>=1&&Map[P2.getY()/30][P2.getX()/30+1]<=4)||(Map[P2.getY()/30][P2.getX()/30+1]>=10&&Map[P2.getY()/30][P2.getX()/30+1]<=11))
            {
                if(Map[P2.getY()/30][P2.getX()/30+1]==2||Map[P2.getY()/30][P2.getX()/30+1]==11)
                {
                    P2.setv(3);
                    xieshijian1=0;
                }
                if(Map[P2.getY()/30][P2.getX()/30+1]==3||Map[P2.getY()/30][P2.getX()/30+1]==4)
                {
                    P2.setsm(P2.getSm()+6);
                }
                if(Map[P2.getY()/30][P2.getX()/30+1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian1=0;
                }
                if(Map[P2.getY()/30][P2.getX()/30+1]==10)
                {
                    P2.setfw(3);
                    yaoshijian1=0;
                }
                n=P2.getY()/30;
                m=P2.getX()/30+1;
                Move2(P2,2);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState('W') && P2.getdir()==0)
        {
            if(Map[P2.getY()/30-1][P2.getX()/30]==7)
                Move2(P2,3);
            else if((Map[P2.getY()/30-1][P2.getX()/30]>=1&&Map[P2.getY()/30-1][P2.getX()/30]<=4)||(Map[P2.getY()/30-1][P2.getX()/30]>=10&&Map[P2.getY()/30-1][P2.getX()/30]<=11))
            {
                if(Map[P2.getY()/30-1][P2.getX()/30]==2||Map[P2.getY()/30-1][P2.getX()/30]==11)
                {
                    P2.setv(3);
                    xieshijian1=0;
                }
                if(Map[P2.getY()/30-1][P2.getX()/30]==3||Map[P2.getY()/30-1][P2.getX()/30]==4)
                {
                    P2.setsm(P2.getSm()+6);
                }
                if(Map[P2.getY()/30-1][P2.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian1=0;
                }
                if(Map[P2.getY()/30-1][P2.getX()/30]==10)
                {
                    yaoshijian1++;
                    P2.setfw(3);
                }
                n=P2.getY()/30-1;
                m=P2.getX()/30;
                Move2(P2,3);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState('S') && P2.getdir()==0)
        {
            if(Map[P2.getY()/30+1][P2.getX()/30]==7)
                Move2(P2,4);
            else if((Map[P2.getY()/30+1][P2.getX()/30]>=1&&Map[P2.getY()/30+1][P2.getX()/30]<=4)||(Map[P2.getY()/30+1][P2.getX()/30]>=10&&Map[P2.getY()/30+1][P2.getX()/30]<=11))
            {
                if(Map[P2.getY()/30+1][P2.getX()/30]==2||Map[P2.getY()/30+1][P2.getX()/30]==11)
                {
                    P2.setv(3);
                    xieshijian1=0;
                }
                if(Map[P2.getY()/30+1][P2.getX()/30]==3||Map[P2.getY()/30+1][P2.getX()/30]==4)
                {
                    P2.setsm(P2.getSm()+6);
                }
                if(Map[P2.getY()/30+1][P2.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian1=0;
                }
                if(Map[P2.getY()/30+1][P2.getX()/30]==10)
                {
                    yaoshijian1++;
                    P2.setfw(3);
                }
                n=P2.getY()/30+1;
                m=P2.getX()/30;
                Move2(P2,4);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    //������λ������Ӧ�ĵ���
	    P1.adjust();
        P2.adjust();
	    //����1����ը��
        if(GetAsyncKeyState(VK_RETURN))
        {
            if(P1.getNum()>0 && Map[P1.getY()/30][P1.getX()/30]==7)//�ж������Ƿ���ը�����������λ���Ƿ���Է�ը��
            {
                zhadan temp(P1.getX(),P1.getY(),&P1,&P2,&zd1,&chuizi);//����һ����ʱը�������
                array_zha.push_back(temp);//��ը������ը��������
                P1.setNum(P1.getNum()-1);//�������ը����ӵ�е�ը��������1
                sprintf(str1, "%d ��", P1.getNum());
                setbkmode(TRANSPARENT);
                outtextxy(470, 140, str1);
                Map[P1.getY()/30][P1.getX()/30]=777;//���ը��λ�ã���ʱ���ﲻ�ܴ����λ��ͨ��
            }

        }
        //����2����ը��
        if(GetAsyncKeyState(VK_SPACE))
        {
            if(P2.getNum()>0 && Map[P2.getY()/30][P2.getX()/30]==7)//�ж������Ƿ���ը�����������λ���Ƿ���Է�ը��
            {
                zhadan temp(P2.getX(),P2.getY(),&P2,&P1,&zd1,&chuizi);//����һ����ʱը�������
                array_zha.push_back(temp);//��ը������ը��������
                P2.setNum(P2.getNum()-1);//�������ը����ӵ�е�ը��������1
                sprintf(str3, "%d ��", P2.getNum());
                setbkmode(TRANSPARENT);
                outtextxy(555, 140, str3);
                Map[P2.getY()/30][P2.getX()/30]=777;//���ը��λ�ã���ʱ���ﲻ�ܴ����λ��ͨ��
            }
        }
        //ˢ�µ�ͼ
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                if(Map[i][j]==5) putimage(j*30,i*30,house);
                else if(Map[i][j]==1)putimage_transparent(NULL,bingqiang,j*30,i*30,BLACK);
                else if(Map[i][j]==2)putimage_transparent(NULL,xiezi,j*30,i*30,BLACK);
                else if(Map[i][j]==3)putimage_transparent(NULL,hudun,j*30,i*30,BLACK);
                else if(Map[i][j]==4)putimage_transparent(NULL,shengming,j*30,i*30,BLACK);
                else if(Map[i][j]==6)putimage_transparent(NULL,rzhuan,j*30,i*30,BLACK);
                else if(Map[i][j]==7)putimage_transparent(NULL,ground,j*30,i*30,BLACK);
                else if(Map[i][j]==8)putimage_transparent(NULL,ltree,j*30,i*30,BLACK);
                else if(Map[i][j]==777)putimage_transparent(NULL,ground,j*30,i*30,BLACK);
                else if(Map[i][j]==10)putimage_transparent(NULL,yaoshui1,j*30,i*30,BLACK);
                else if(Map[i][j]==11)putimage_transparent(NULL,huaban1,j*30,i*30,BLACK);
            }
        }
        //ը����ը˲��
        for(int i=0;i<array_zha.size();i++)
        {
            array_zha[i].loadzd();//ը�����ú���
            if(array_zha[i].checkalive()==false){
                array_zha[i].loadboom();//ը����ը
                Map[array_zha[i].getY()/30][array_zha[i].getX()/30]=7;//ը����ը��ɺ��Ϊ�յ�
                array_zha[i].getPerson()->setNum(array_zha[i].getPerson()->getNum()+1);//ը����ը���������ӵ�е�ը����1
                array_zha.erase(array_zha.begin()+i);//����ը���ը���Ƴ�����
            }
        }
        P1.loadpeople();//��������1
        P2.loadpeople();//��������2
        if(second==0)
        {
            sjd();
            break;
        }
        sprintf(str2, "%d ��", P1.getSm()/6);
        sprintf(str4, "%d ��", P2.getSm()/6);
        setbkmode(TRANSPARENT);
        outtextxy(470, 175, str2);
        outtextxy(555, 175, str4);
        if(P1.getSm()/6==0&&P1.getSm()%6==0)
        {
            PlaySound(NULL,NULL,SND_FILENAME);
            playsoundjs();
            shengli1();
            break;
        }
        if(P2.getSm()/6==0&&P2.getSm()%6==0)
        {
            PlaySound(NULL,NULL,SND_FILENAME);
            playsoundjs();
            shengli2();
            break;
        }
		int x, y;
		mousepos(&x, &y);
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=182&&x<=265&&y>=435&y<=466&&msg.is_left()==1&&msg.is_down()==1)
        {
            zt();
            putimage(0,0,shuangjian);
        }
        else if(x>=513&&x<=601&&y>=428&y<=457&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            break;
        }
	}
	st();
}

//˫��һ����Ϸ
void spy2()
{
    playsoundyx2();
    int flag,sum=0,n,m,xieshijian=200,bingshijian=500,xieshijian1=200,bingshijian1=500,yaoshijian=500,yaoshijian1=500;
    second=180;
    P1.setsm(6);
    P2.setsm(6);
    P1.setX(30);
    P1.setY(30);
    P2.setX(390);
    P2.setY(390);
    shuangyi=newimage();
    getimage(shuangyi,"img\\˫��һ��.jpg");
    getimage(shatan,"img\\shatan.png");
    getimage(yizi,"img\\yizi.png");
    getimage(yezishu,"img\\yezishu.png");
    getimage(lengyin,"img\\lengyin.png");
    getimage(haixing,"img\\haixing.png");
    putimage(0,0,shuangyi);
    srand(time(NULL));
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    if((fp1=fopen("һ��map1.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    if((fp2=fopen("һ��map2.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    if((fp3=fopen("һ��map3.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    int xu=rand()%3;
    if(xu==0)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp1,"%d",&Map[i][j]);
            }
        }
    }
    else if(xu==1)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp2,"%d",&Map[i][j]);
            }
        }
    }
    else if(xu==2)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp3,"%d",&Map[i][j]);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    for(int i=1;i<width;i++)
    {
        for(int j=1;j<length;j++)
        {
            putimage_transparent(NULL,shatan,j*30,i*30,BLACK);//��ͼΪ7
        }
    }
    for(int i=1;i<width;i++)
    {
        for(int j=1;j<length;j++)
        {
            if(Map[i][j]==5) putimage_transparent(NULL,lengyin,j*30,i*30,BLACK);
            else if(Map[i][j]==6)putimage_transparent(NULL,yizi,j*30,i*30,BLACK);
            else if(Map[i][j]==7)putimage_transparent(NULL,shatan,j*30,i*30,BLACK);
            else if(Map[i][j]==8)putimage_transparent(NULL,yezishu,j*30,i*30,BLACK);
            else if(Map[i][j]==9)putimage_transparent(NULL,haixing,j*30,i*30,BLACK);
        }
    }
    setcolor(EGERGB(248,248,255));
    setfont(16, 0, "����");
    mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(60))
	{
	    yaoshijian1++;
	    yaoshijian++;
	    xieshijian++;
	    bingshijian++;
	    xieshijian1++;
	    bingshijian1++;
	    if(yaoshijian1==480)P2.setfw(3);
	    if(yaoshijian==480)P1.setfw(3);
	    if(bingshijian==480)getimage(chuizi,"img\\chuizi.png");
	    if(xieshijian==180)P1.setv(2);
	    if(bingshijian1==480)getimage(chuizi,"img\\chuizi.png");
	    if(xieshijian1==180)P2.setv(2);
	    flag=0;
	    putimage(0,0,shuangyi);
	    char str1[10],str2[10],str3[10],str4[10],t[10];
	    sprintf(str1, "%d ��", P1.getNum());
	    sprintf(str3, "%d ��", P2.getNum());
	    setbkmode(TRANSPARENT);
        outtextxy(470, 140, str1);
        outtextxy(555, 140, str3);
        sum++;
	    if(sum%60==0)
        {
            second--;
        }
        sprintf(t, "%d ��", second);
	    setbkmode(TRANSPARENT);
        outtextxy(560, 374, t);

	    if(GetAsyncKeyState(VK_LEFT) && P1.getdir()==0)//�����ƶ�
        {
            if(Map[P1.getY()/30][P1.getX()/30-1]==7)
                Move1(P1,1);
            else if((Map[P1.getY()/30][P1.getX()/30-1]>=1&&Map[P1.getY()/30][P1.getX()/30-1]<=4)||(Map[P1.getY()/30][P1.getX()/30-1]>=10&&Map[P1.getY()/30][P1.getX()/30-1]<=11))
            {
                if(Map[P1.getY()/30][P1.getX()/30-1]==2||Map[P1.getY()/30][P1.getX()/30-1]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==3||Map[P1.getY()/30][P1.getX()/30-1]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==10)
                {
                    P1.setfw(3);
                    yaoshijian=0;
                }
                n=P1.getY()/30;
                m=P1.getX()/30-1;
                Move1(P1,1);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_RIGHT) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30][P1.getX()/30+1]==7)
                Move1(P1,2);
            else if((Map[P1.getY()/30][P1.getX()/30+1]>=1&&Map[P1.getY()/30][P1.getX()/30+1]<=4)||(Map[P1.getY()/30][P1.getX()/30+1]>=10&&Map[P1.getY()/30][P1.getX()/30+1]<=11))
            {
                if(Map[P1.getY()/30][P1.getX()/30+1]==2||Map[P1.getY()/30][P1.getX()/30+1]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==3||Map[P1.getY()/30][P1.getX()/30+1]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==10)
                {
                    P1.setfw(3);
                    yaoshijian=0;
                }
                n=P1.getY()/30;
                m=P1.getX()/30+1;
                Move1(P1,2);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_UP) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30-1][P1.getX()/30]==7)
                Move1(P1,3);
            else if((Map[P1.getY()/30-1][P1.getX()/30]>=1&&Map[P1.getY()/30-1][P1.getX()/30]<=4)||(Map[P1.getY()/30-1][P1.getX()/30]>=10&&Map[P1.getY()/30-1][P1.getX()/30]<=11))
            {
                if(Map[P1.getY()/30-1][P1.getX()/30]==2||Map[P1.getY()/30-1][P1.getX()/30]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==3||Map[P1.getY()/30-1][P1.getX()/30]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==10)
                {
                    yaoshijian++;
                    P1.setfw(3);
                }
                n=P1.getY()/30-1;
                m=P1.getX()/30;
                Move1(P1,3);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_DOWN) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30+1][P1.getX()/30]==7)
                Move1(P1,4);
            else if((Map[P1.getY()/30+1][P1.getX()/30]>=1&&Map[P1.getY()/30+1][P1.getX()/30]<=4)||(Map[P1.getY()/30+1][P1.getX()/30]>=10&&Map[P1.getY()/30+1][P1.getX()/30]<=11))
            {
                if(Map[P1.getY()/30+1][P1.getX()/30]==2||Map[P1.getY()/30+1][P1.getX()/30]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==3||Map[P1.getY()/30+1][P1.getX()/30]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==10)
                {
                    yaoshijian++;
                    P1.setfw(3);
                }
                n=P1.getY()/30+1;
                m=P1.getX()/30;
                Move1(P1,4);
                Map[n][m]=7;
                flag=1;
            }
	    }

	    if(GetAsyncKeyState('A') && P2.getdir()==0)//����2�ƶ�
        {
            if(Map[P2.getY()/30][P2.getX()/30-1]==7)
                Move2(P2,1);
            else if((Map[P2.getY()/30][P2.getX()/30-1]>=1&&Map[P2.getY()/30][P2.getX()/30-1]<=4)||(Map[P2.getY()/30][P2.getX()/30-1]>=10&&Map[P2.getY()/30][P2.getX()/30-1]<=11))
            {
                if(Map[P2.getY()/30][P2.getX()/30-1]==2||Map[P2.getY()/30][P2.getX()/30-1]==11)
                {
                    P2.setv(3);
                    xieshijian1=0;
                }
                if(Map[P2.getY()/30][P2.getX()/30-1]==3||Map[P2.getY()/30][P2.getX()/30-1]==4)
                {
                    P2.setsm(P2.getSm()+6);
                }
                if(Map[P2.getY()/30][P2.getX()/30-1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian1=0;
                }
                if(Map[P2.getY()/30][P2.getX()/30-1]==10)
                {
                    P2.setfw(3);
                    yaoshijian1=0;
                }
                n=P2.getY()/30;
                m=P2.getX()/30-1;
                Move2(P2,1);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState('D') && P2.getdir()==0)
        {
            if(Map[P2.getY()/30][P2.getX()/30+1]==7)
                Move2(P2,2);
            else if((Map[P2.getY()/30][P2.getX()/30+1]>=1&&Map[P2.getY()/30][P2.getX()/30+1]<=4)||(Map[P2.getY()/30][P2.getX()/30+1]>=10&&Map[P2.getY()/30][P2.getX()/30+1]<=11))
            {
                if(Map[P2.getY()/30][P2.getX()/30+1]==2||Map[P2.getY()/30][P2.getX()/30+1]==11)
                {
                    P2.setv(3);
                    xieshijian1=0;
                }
                if(Map[P2.getY()/30][P2.getX()/30+1]==3||Map[P2.getY()/30][P2.getX()/30+1]==4)
                {
                    P2.setsm(P2.getSm()+6);
                }
                if(Map[P2.getY()/30][P2.getX()/30+1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian1=0;
                }
                if(Map[P2.getY()/30][P2.getX()/30+1]==10)
                {
                    P2.setfw(3);
                    yaoshijian1=0;
                }
                n=P2.getY()/30;
                m=P2.getX()/30+1;
                Move2(P2,2);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState('W') && P2.getdir()==0)
        {
            if(Map[P2.getY()/30-1][P2.getX()/30]==7)
                Move2(P2,3);
            else if((Map[P2.getY()/30-1][P2.getX()/30]>=1&&Map[P2.getY()/30-1][P2.getX()/30]<=4)||(Map[P2.getY()/30-1][P2.getX()/30]>=10&&Map[P2.getY()/30-1][P2.getX()/30]<=11))
            {
                if(Map[P2.getY()/30-1][P2.getX()/30]==2||Map[P2.getY()/30-1][P2.getX()/30]==11)
                {
                    P2.setv(3);
                    xieshijian1=0;
                }
                if(Map[P2.getY()/30-1][P2.getX()/30]==3||Map[P2.getY()/30-1][P2.getX()/30]==4)
                {
                    P2.setsm(P2.getSm()+6);
                }
                if(Map[P2.getY()/30-1][P2.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian1=0;
                }
                if(Map[P2.getY()/30-1][P2.getX()/30]==10)
                {
                    yaoshijian1++;
                    P2.setfw(3);
                }
                n=P2.getY()/30-1;
                m=P2.getX()/30;
                Move2(P2,3);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState('S') && P2.getdir()==0)
        {
            if(Map[P2.getY()/30+1][P2.getX()/30]==7)
                Move2(P2,4);
            else if((Map[P2.getY()/30+1][P2.getX()/30]>=1&&Map[P2.getY()/30+1][P2.getX()/30]<=4)||(Map[P2.getY()/30+1][P2.getX()/30]>=10&&Map[P2.getY()/30+1][P2.getX()/30]<=11))
            {
                if(Map[P2.getY()/30+1][P2.getX()/30]==2||Map[P2.getY()/30+1][P2.getX()/30]==11)
                {
                    P2.setv(3);
                    xieshijian1=0;
                }
                if(Map[P2.getY()/30+1][P2.getX()/30]==3||Map[P2.getY()/30+1][P2.getX()/30]==4)
                {
                    P2.setsm(P2.getSm()+6);
                }
                if(Map[P2.getY()/30+1][P2.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian1=0;
                }
                if(Map[P2.getY()/30+1][P2.getX()/30]==10)
                {
                    yaoshijian1++;
                    P2.setfw(3);
                }
                n=P2.getY()/30+1;
                m=P2.getX()/30;
                Move2(P2,4);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    //������λ������Ӧ�ĵ���
	    P1.adjust();
        P2.adjust();
	    //����1����ը��
        if(GetAsyncKeyState(VK_RETURN))
        {
            if(P1.getNum()>0 && Map[P1.getY()/30][P1.getX()/30]==7)//�ж������Ƿ���ը�����������λ���Ƿ���Է�ը��
            {
                zhadan temp(P1.getX(),P1.getY(),&P1,&P2,&zd1,&chuizi);//����һ����ʱը�������
                array_zha.push_back(temp);//��ը������ը��������
                P1.setNum(P1.getNum()-1);//�������ը����ӵ�е�ը��������1
                sprintf(str1, "%d ��", P1.getNum());
                setbkmode(TRANSPARENT);
                outtextxy(470, 140, str1);
                Map[P1.getY()/30][P1.getX()/30]=777;//���ը��λ�ã���ʱ���ﲻ�ܴ����λ��ͨ��
            }

        }
        //����2����ը��
        if(GetAsyncKeyState(VK_SPACE))
        {
            if(P2.getNum()>0 && Map[P2.getY()/30][P2.getX()/30]==7)//�ж������Ƿ���ը�����������λ���Ƿ���Է�ը��
            {
                zhadan temp(P2.getX(),P2.getY(),&P2,&P1,&zd1,&chuizi);//����һ����ʱը�������
                array_zha.push_back(temp);//��ը������ը��������
                P2.setNum(P2.getNum()-1);//�������ը����ӵ�е�ը��������1
                sprintf(str3, "%d ��", P2.getNum());
                setbkmode(TRANSPARENT);
                outtextxy(555, 140, str3);
                Map[P2.getY()/30][P2.getX()/30]=777;//���ը��λ�ã���ʱ���ﲻ�ܴ����λ��ͨ��
            }

        }
        //ˢ�µ�ͼ
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                if(Map[i][j]==5) putimage_transparent(NULL,lengyin,j*30,i*30,BLACK);
                else if(Map[i][j]==1)putimage_transparent(NULL,bingqiang1,j*30,i*30,BLACK);
                else if(Map[i][j]==2)putimage_transparent(NULL,xiezi1,j*30,i*30,BLACK);
                else if(Map[i][j]==3)putimage_transparent(NULL,hudun1,j*30,i*30,BLACK);
                else if(Map[i][j]==4)putimage_transparent(NULL,shengming1,j*30,i*30,BLACK);
                else if(Map[i][j]==6)putimage_transparent(NULL,yizi,j*30,i*30,BLACK);
                else if(Map[i][j]==7)putimage_transparent(NULL,shatan,j*30,i*30,BLACK);
                else if(Map[i][j]==8)putimage_transparent(NULL,yezishu,j*30,i*30,BLACK);
                else if(Map[i][j]==9)putimage_transparent(NULL,haixing,j*30,i*30,BLACK);
                else if(Map[i][j]==777)putimage_transparent(NULL,shatan,j*30,i*30,BLACK);
                else if(Map[i][j]==10)putimage_transparent(NULL,yaoshui2,j*30,i*30,BLACK);
                else if(Map[i][j]==11)putimage_transparent(NULL,huaban2,j*30,i*30,BLACK);
            }
        }
        //ը����ը˲��
        for(int i=0;i<array_zha.size();i++)
        {
            array_zha[i].loadzd();//ը�����ú���
            if(array_zha[i].checkalive()==false){
                array_zha[i].loadboom();//ը����ը
                Map[array_zha[i].getY()/30][array_zha[i].getX()/30]=7;//ը����ը��ɺ��Ϊ�յ�
                array_zha[i].getPerson()->setNum(array_zha[i].getPerson()->getNum()+1);//ը����ը���������ӵ�е�ը����1
                array_zha.erase(array_zha.begin()+i);//����ը���ը���Ƴ�����

            }
        }
        P1.loadpeople();//��������1
        P2.loadpeople();//��������2
        if(second==0)
        {
            sjd();
            break;
        }
        sprintf(str2, "%d ��", P1.getSm()/6);
        sprintf(str4, "%d ��", P2.getSm()/6);
        setbkmode(TRANSPARENT);
        outtextxy(470, 175, str2);
        outtextxy(555, 175, str4);
        if(P1.getSm()/6==0&&P1.getSm()%6==0)
        {
            PlaySound(NULL,NULL,SND_FILENAME);
            playsoundjs();
            shengli1();
            break;
        }
        if(P2.getSm()/6==0&&P2.getSm()%6==0)
        {
            PlaySound(NULL,NULL,SND_FILENAME);
            playsoundjs();
            shengli2();
            break;
        }
		int x, y;
		mousepos(&x, &y);
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=182&&x<=265&&y>=435&y<=466&&msg.is_left()==1&&msg.is_down()==1)
        {
            zt();
            putimage(0,0,shuangyi);
        }
        else if(x>=513&&x<=601&&y>=428&y<=457&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            break;
        }
	}
	st();
}

//˫��������Ϸ
void spy3()
{
    playsoundyx3();
    int flag,sum=0,n,m,xieshijian=200,bingshijian=500,xieshijian1=200,bingshijian1=500,yaoshijian=500,yaoshijian1=500;
    second=180;
    P1.setsm(12);
    P2.setsm(12);
    P1.setX(30);
    P1.setY(30);
    P2.setX(390);
    P2.setY(390);
    shuangkun=newimage();
    getimage(shuangkun,"img\\˫������.jpg");
    getimage(wanju,"img\\���.png");
    getimage(wanjuche,"img\\��߳�.png");
    getimage(mofang,"img\\ħ��.png");
    getimage(jinggao,"img\\����.png");
    getimage(banshou,"img\\����.png");
    putimage(0,0,shuangkun);
    srand(time(NULL));
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    if((fp1=fopen("����map1.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    if((fp2=fopen("����map2.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    if((fp3=fopen("����map3.txt","r+"))==NULL)   //�õ���ͼ��Ϣ
    {
        exit(0);
    }
    int xu=rand()%3;
    if(xu==0)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp1,"%d",&Map[i][j]);
            }
        }
    }
    else if(xu==1)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp2,"%d",&Map[i][j]);
            }
        }
    }
    else if(xu==2)
    {
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                fscanf(fp3,"%d",&Map[i][j]);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    for(int i=1;i<width;i++)
    {
        for(int j=1;j<length;j++)
        {
            putimage_transparent(NULL,wanju,j*30,i*30,BLACK);//��ͼΪ7
        }
    }
    for(int i=1;i<width;i++)
    {
        for(int j=1;j<length;j++)
        {
            if(Map[i][j]==5) putimage_transparent(NULL,wanjuche,j*30,i*30,BLACK);
            else if(Map[i][j]==6)putimage_transparent(NULL,banshou,j*30,i*30,BLACK);
            else if(Map[i][j]==7)putimage_transparent(NULL,wanju,j*30,i*30,BLACK);
            else if(Map[i][j]==8)putimage_transparent(NULL,mofang,j*30,i*30,BLACK);
            else if(Map[i][j]==9)putimage_transparent(NULL,jinggao,j*30,i*30,BLACK);
        }
    }
    setcolor(EGERGB(248,248,255));
    setfont(16, 0, "����");
    mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(60))
	{
	    yaoshijian1++;
	    yaoshijian++;
	    xieshijian++;
	    bingshijian++;
	    xieshijian1++;
	    bingshijian1++;
	    if(yaoshijian1==480)P2.setfw(3);
	    if(yaoshijian==480)P1.setfw(3);
	    if(bingshijian==480)getimage(chuizi,"img\\chuizi.png");
	    if(xieshijian==180)P1.setv(2);
	    if(bingshijian1==480)getimage(chuizi,"img\\chuizi.png");
	    if(xieshijian1==180)P2.setv(2);
	    flag=0;
	    putimage(0,0,shuangkun);
	    char str1[10],str2[10],str3[10],str4[10],t[10];
	    sprintf(str1, "%d ��", P1.getNum());
	    sprintf(str3, "%d ��", P2.getNum());
	    setbkmode(TRANSPARENT);
        outtextxy(470, 140, str1);
        outtextxy(555, 140, str3);
        sum++;
	    if(sum%60==0)
        {
            second--;
        }
        sprintf(t, "%d ��", second);
	    setbkmode(TRANSPARENT);
        outtextxy(560, 374, t);
	    if(GetAsyncKeyState(VK_LEFT) && P1.getdir()==0)//�����ƶ�
        {
            if(Map[P1.getY()/30][P1.getX()/30-1]==7)
                Move1(P1,1);
            else if((Map[P1.getY()/30][P1.getX()/30-1]>=1&&Map[P1.getY()/30][P1.getX()/30-1]<=4)||(Map[P1.getY()/30][P1.getX()/30-1]>=10&&Map[P1.getY()/30][P1.getX()/30-1]<=11))
            {
                if(Map[P1.getY()/30][P1.getX()/30-1]==2||Map[P1.getY()/30][P1.getX()/30-1]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==3||Map[P1.getY()/30][P1.getX()/30-1]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30-1]==10)
                {
                    P1.setfw(3);
                    yaoshijian=0;
                }
                n=P1.getY()/30;
                m=P1.getX()/30-1;
                Move1(P1,1);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_RIGHT) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30][P1.getX()/30+1]==7)
                Move1(P1,2);
            else if((Map[P1.getY()/30][P1.getX()/30+1]>=1&&Map[P1.getY()/30][P1.getX()/30+1]<=4)||(Map[P1.getY()/30][P1.getX()/30+1]>=10&&Map[P1.getY()/30][P1.getX()/30+1]<=11))
            {
                if(Map[P1.getY()/30][P1.getX()/30+1]==2||Map[P1.getY()/30][P1.getX()/30+1]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==3||Map[P1.getY()/30][P1.getX()/30+1]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30][P1.getX()/30+1]==10)
                {
                    P1.setfw(3);
                    yaoshijian=0;
                }
                n=P1.getY()/30;
                m=P1.getX()/30+1;
                Move1(P1,2);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_UP) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30-1][P1.getX()/30]==7)
                Move1(P1,3);
            else if((Map[P1.getY()/30-1][P1.getX()/30]>=1&&Map[P1.getY()/30-1][P1.getX()/30]<=4)||(Map[P1.getY()/30-1][P1.getX()/30]>=10&&Map[P1.getY()/30-1][P1.getX()/30]<=11))
            {
                if(Map[P1.getY()/30-1][P1.getX()/30]==2||Map[P1.getY()/30-1][P1.getX()/30]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==3||Map[P1.getY()/30-1][P1.getX()/30]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30-1][P1.getX()/30]==10)
                {
                    yaoshijian++;
                    P1.setfw(3);
                }
                n=P1.getY()/30-1;
                m=P1.getX()/30;
                Move1(P1,3);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState(VK_DOWN) && P1.getdir()==0)
        {
            if(Map[P1.getY()/30+1][P1.getX()/30]==7)
                Move1(P1,4);
            else if((Map[P1.getY()/30+1][P1.getX()/30]>=1&&Map[P1.getY()/30+1][P1.getX()/30]<=4)||(Map[P1.getY()/30+1][P1.getX()/30]>=10&&Map[P1.getY()/30+1][P1.getX()/30]<=11))
            {
                if(Map[P1.getY()/30+1][P1.getX()/30]==2||Map[P1.getY()/30+1][P1.getX()/30]==11)
                {
                    P1.setv(3);
                    xieshijian=0;
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==3||Map[P1.getY()/30+1][P1.getX()/30]==4)
                {
                    P1.setsm(P1.getSm()+6);
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian=0;
                }
                if(Map[P1.getY()/30+1][P1.getX()/30]==10)
                {
                    yaoshijian++;
                    P1.setfw(3);
                }
                n=P1.getY()/30+1;
                m=P1.getX()/30;
                Move1(P1,4);
                Map[n][m]=7;
                flag=1;
            }
	    }

	    if(GetAsyncKeyState('A') && P2.getdir()==0)//����2�ƶ�
        {
            if(Map[P2.getY()/30][P2.getX()/30-1]==7)
                Move2(P2,1);
            else if((Map[P2.getY()/30][P2.getX()/30-1]>=1&&Map[P2.getY()/30][P2.getX()/30-1]<=4)||(Map[P2.getY()/30][P2.getX()/30-1]>=10&&Map[P2.getY()/30][P2.getX()/30-1]<=11))
            {
                if(Map[P2.getY()/30][P2.getX()/30-1]==2||Map[P2.getY()/30][P2.getX()/30-1]==11)
                {
                    P2.setv(3);
                    xieshijian1=0;
                }
                if(Map[P2.getY()/30][P2.getX()/30-1]==3||Map[P2.getY()/30][P2.getX()/30-1]==4)
                {
                    P2.setsm(P2.getSm()+6);
                }
                if(Map[P2.getY()/30][P2.getX()/30-1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian1=0;
                }
                if(Map[P2.getY()/30][P2.getX()/30-1]==10)
                {
                    P2.setfw(3);
                    yaoshijian1=0;
                }
                n=P2.getY()/30;
                m=P2.getX()/30-1;
                Move2(P2,1);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState('D') && P2.getdir()==0)
        {
            if(Map[P2.getY()/30][P2.getX()/30+1]==7)
                Move2(P2,2);
            else if((Map[P2.getY()/30][P2.getX()/30+1]>=1&&Map[P2.getY()/30][P2.getX()/30+1]<=4)||(Map[P2.getY()/30][P2.getX()/30+1]>=10&&Map[P2.getY()/30][P2.getX()/30+1]<=11))
            {
                if(Map[P2.getY()/30][P2.getX()/30+1]==2||Map[P2.getY()/30][P2.getX()/30+1]==11)
                {
                    P2.setv(3);
                    xieshijian1=0;
                }
                if(Map[P2.getY()/30][P2.getX()/30+1]==3||Map[P2.getY()/30][P2.getX()/30+1]==4)
                {
                    P2.setsm(P2.getSm()+6);
                }
                if(Map[P2.getY()/30][P2.getX()/30+1]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian1=0;
                }
                if(Map[P2.getY()/30][P2.getX()/30+1]==10)
                {
                    P2.setfw(3);
                    yaoshijian1=0;
                }
                n=P2.getY()/30;
                m=P2.getX()/30+1;
                Move2(P2,2);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState('W') && P2.getdir()==0)
        {
            if(Map[P2.getY()/30-1][P2.getX()/30]==7)
                Move2(P2,3);
            else if((Map[P2.getY()/30-1][P2.getX()/30]>=1&&Map[P2.getY()/30-1][P2.getX()/30]<=4)||(Map[P2.getY()/30-1][P2.getX()/30]>=10&&Map[P2.getY()/30-1][P2.getX()/30]<=11))
            {
                if(Map[P2.getY()/30-1][P2.getX()/30]==2||Map[P2.getY()/30-1][P2.getX()/30]==11)
                {
                    P2.setv(3);
                    xieshijian1=0;
                }
                if(Map[P2.getY()/30-1][P2.getX()/30]==3||Map[P2.getY()/30-1][P2.getX()/30]==4)
                {
                    P2.setsm(P2.getSm()+6);
                }
                if(Map[P2.getY()/30-1][P2.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian1=0;
                }
                if(Map[P2.getY()/30-1][P2.getX()/30]==10)
                {
                    yaoshijian1++;
                    P2.setfw(3);
                }
                n=P2.getY()/30-1;
                m=P2.getX()/30;
                Move2(P2,3);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    else if(GetAsyncKeyState('S') && P2.getdir()==0)
        {
            if(Map[P2.getY()/30+1][P2.getX()/30]==7)
                Move2(P2,4);
            else if((Map[P2.getY()/30+1][P2.getX()/30]>=1&&Map[P2.getY()/30+1][P2.getX()/30]<=4)||(Map[P2.getY()/30+1][P2.getX()/30]>=10&&Map[P2.getY()/30+1][P2.getX()/30]<=11))
            {
                if(Map[P2.getY()/30+1][P2.getX()/30]==2||Map[P2.getY()/30+1][P2.getX()/30]==11)
                {
                    P2.setv(3);
                    xieshijian1=0;
                }
                if(Map[P2.getY()/30+1][P2.getX()/30]==3||Map[P2.getY()/30+1][P2.getX()/30]==4)
                {
                    P2.setsm(P2.getSm()+6);
                }
                if(Map[P2.getY()/30+1][P2.getX()/30]==1)
                {
                    getimage(chuizi,"img\\bing.png");
                    bingshijian1=0;
                }
                if(Map[P2.getY()/30+1][P2.getX()/30]==10)
                {
                    yaoshijian1++;
                    P2.setfw(3);
                }
                n=P2.getY()/30+1;
                m=P2.getX()/30;
                Move2(P2,4);
                Map[n][m]=7;
                flag=1;
            }
	    }
	    //������λ������Ӧ�ĵ���
	    P1.adjust();
        P2.adjust();
	    //����1����ը��
        if(GetAsyncKeyState(VK_RETURN))
        {
            if(P1.getNum()>0 && Map[P1.getY()/30][P1.getX()/30]==7)//�ж������Ƿ���ը�����������λ���Ƿ���Է�ը��
            {
                zhadan temp(P1.getX(),P1.getY(),&P1,&P2,&zd1,&chuizi);//����һ����ʱը�������
                array_zha.push_back(temp);//��ը������ը��������
                P1.setNum(P1.getNum()-1);//�������ը����ӵ�е�ը��������1
                sprintf(str1, "%d ��", P1.getNum());
                setbkmode(TRANSPARENT);
                outtextxy(470, 140, str1);
                Map[P1.getY()/30][P1.getX()/30]=777;//���ը��λ�ã���ʱ���ﲻ�ܴ����λ��ͨ��
            }

        }
        //����2����ը��
        if(GetAsyncKeyState(VK_SPACE))
        {
            if(P2.getNum()>0 && Map[P2.getY()/30][P2.getX()/30]==7)//�ж������Ƿ���ը�����������λ���Ƿ���Է�ը��
            {
                zhadan temp(P2.getX(),P2.getY(),&P2,&P1,&zd1,&chuizi);//����һ����ʱը�������
                array_zha.push_back(temp);//��ը������ը��������
                P2.setNum(P2.getNum()-1);//�������ը����ӵ�е�ը��������1
                sprintf(str3, "%d ��", P2.getNum());
                setbkmode(TRANSPARENT);
                outtextxy(555, 140, str3);
                Map[P2.getY()/30][P2.getX()/30]=777;//���ը��λ�ã���ʱ���ﲻ�ܴ����λ��ͨ��
            }

        }
        //ˢ�µ�ͼ
        for(int i=1;i<width;i++)
        {
            for(int j=1;j<length;j++)
            {
                if(Map[i][j]==5) putimage_transparent(NULL,wanjuche,j*30,i*30,BLACK);
                else if(Map[i][j]==1)putimage_transparent(NULL,bingqiang2,j*30,i*30,BLACK);
                else if(Map[i][j]==2)putimage_transparent(NULL,xiezi2,j*30,i*30,BLACK);
                else if(Map[i][j]==3)putimage_transparent(NULL,hudun2,j*30,i*30,BLACK);
                else if(Map[i][j]==4)putimage_transparent(NULL,shengming2,j*30,i*30,BLACK);
                else if(Map[i][j]==6)putimage_transparent(NULL,banshou,j*30,i*30,BLACK);
                else if(Map[i][j]==7)putimage_transparent(NULL,wanju,j*30,i*30,BLACK);
                else if(Map[i][j]==8)putimage_transparent(NULL,mofang,j*30,i*30,BLACK);
                else if(Map[i][j]==9)putimage_transparent(NULL,jinggao,j*30,i*30,BLACK);
                else if(Map[i][j]==777)putimage_transparent(NULL,wanju,j*30,i*30,BLACK);
                else if(Map[i][j]==10)putimage_transparent(NULL,yaoshui3,j*30,i*30,BLACK);
                else if(Map[i][j]==11)putimage_transparent(NULL,huaban3,j*30,i*30,BLACK);
            }
        }
        //ը����ը˲��
        for(int i=0;i<array_zha.size();i++)
        {
            array_zha[i].loadzd();//ը�����ú���
            if(array_zha[i].checkalive()==false){
                array_zha[i].loadboom();//ը����ը
                Map[array_zha[i].getY()/30][array_zha[i].getX()/30]=7;//ը����ը��ɺ��Ϊ�յ�
                array_zha[i].getPerson()->setNum(array_zha[i].getPerson()->getNum()+1);//ը����ը���������ӵ�е�ը����1
                array_zha.erase(array_zha.begin()+i);//����ը���ը���Ƴ�����

            }
        }
        P1.loadpeople();//��������1
        P2.loadpeople();//��������2
        if(second==0)
        {
            sjd();
            break;
        }
        sprintf(str2, "%d ��", P1.getSm()/6);
        sprintf(str4, "%d ��", P2.getSm()/6);
        setbkmode(TRANSPARENT);
        outtextxy(470, 175, str2);
        outtextxy(555, 175, str4);
        if(P1.getSm()/6==0&&P1.getSm()%6==0)
        {
            PlaySound(NULL,NULL,SND_FILENAME);
            playsoundjs();
            shengli1();
            break;
        }
        if(P2.getSm()/6==0&&P2.getSm()%6==0)
        {
            PlaySound(NULL,NULL,SND_FILENAME);
            playsoundjs();
            shengli2();
            break;
        }
		int x, y;
		mousepos(&x, &y);
        while (mousemsg())
		{
			msg = getmouse();
		}
		if(x>=182&&x<=265&&y>=435&y<=466&&msg.is_left()==1&&msg.is_down()==1)
        {
            zt();
            putimage(0,0,shuangkun);
        }
        else if(x>=513&&x<=601&&y>=428&y<=457&&msg.is_left()==1&&msg.is_down()==1)
        {
            cleardevice();
            break;
        }
	}
	st();
}

void del()
{
    delimage(start);
    delimage(play);
    delimage(itr);
    delimage(play1);
    delimage(itr1);
    delimage(jsh);
    delimage(bk);
    delimage(tool);
    delimage(daoju);
    delimage(sel);
    delimage(sel1);
    delimage(sel2);
    delimage(rzhuan);
    delimage(ground);
    delimage(house);
    delimage(ltree);
    delimage(shatan);
    delimage(yizi);
    delimage(yezishu);
    delimage(haixing);
    delimage(lengyin);
    delimage(wanju);
    delimage(wanjuche);
    delimage(mofang);
    delimage(banshou);
    delimage(jinggao);
    delimage(danjian);
    delimage(danyi);
    delimage(dankun);
    delimage(shuangjian);
    delimage(shuangyi);
    delimage(shuangkun);
    delimage(people1);
    delimage(people2);
    delimage(zd1);
    delimage(zd2);
    delimage(chuizi);
    delimage(bingqiang);
    delimage(shengming);
    delimage(hudun);
    delimage(zanting);
    delimage(sl1);
    delimage(sl2);
    delimage(shijiandao);
    delimage(zhasi);
    delimage(bing);
    delimage(xiezi);
    delimage(bingqiang1);
    delimage(bingqiang2);
    delimage(xiezi1);
    delimage(xiezi2);
    delimage(shengming1);
    delimage(shengming2);
    delimage(hudun1);
    delimage(hudun2);
    delimage(yaoshui1);
    delimage(yaoshui2);
    delimage(yaoshui3);
    delimage(huaban1);
    delimage(huaban2);
    delimage(huaban3);
}

int main()
{
    setinitmode(0);
	initgraph(640, 480);//��ʼ��
	shatan=newimage();
    yizi=newimage();
    yezishu=newimage();
    lengyin=newimage();
    haixing=newimage();
    rzhuan=newimage();
    ground=newimage();
    house=newimage();
    ltree=newimage();
    mofang=newimage();
    wanju=newimage();
    wanjuche=newimage();
    jinggao=newimage();
    banshou=newimage();
	st();//��ʼ����
	getch();
	del();//���ͼƬ
	closegraph();
	getchar();
	return 0;
}
