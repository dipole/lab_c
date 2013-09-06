#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <conio.h>
#include <string.h>

#define TIME_OUT 10
#define TOTAL 20

int total;
int yes;
int answer;
int user_answer;
char user_name[20];

int init();
int main_body();
int print_math();
int answer_question();
int random_num(int x);
int see_grade();
int copyRight();
int getName();
int writeEile();

int main(void) {
	srand(time(0));
	getName();
	while(1){
		int i;
		init();

		while(scanf("%d", &i) != 1 || i < 1 || i > 3) {
			printf("敲错了，老兄！\n选数字1/2/3\n");
			while(getchar() != '\n');
		}

		if(i == 1) {
			main_body();
			see_grade();
		}
		else if(i == 2)
			see_grade();
		else if(i == 3)
			break;
	}
	copyRight();
	return 0;
}

int main_body() {
    total = TOTAL;
	yes = 0;

	while(total > 0 ){
		print_math(TOTAL - total + 1);
		answer_question();
		total--;
    }
    return 0;
}

int print_math(int num) {
    
    char c[] = {'+','-','*','/'};
    char *pc;
    int x;
    int y;
    int r;

    r = random_num(4);
    user_answer = 0;
    pc = c;
    pc += r;
    switch(r){
    case 0:
    	x = random_num(50);
    	y = random_num(50);
        answer = x + y;
        break;
    case 1:
    	x = random_num(100);
    	y = random_num(50);
        answer = x - y;
        break;
    case 2:
    	x = random_num(10);
    	y = random_num(10);
        answer = x * y;
        break;
    case 3:
    	x = random_num(100);
    	y = random_num(10);
        if(y == 0) y++;
        answer = x / y;
        x = answer * y;
        break;
    }
    printf("第%d题: ", num);
    printf("%d%c%d=", x , *pc , y );
    return 0;
}

int answer_question(){
    while(scanf("%d", &user_answer) != 1){
		while(getchar() != '\n');
		return 0;
	}
    if(user_answer == answer) 
		yes++; 
	return 0;
}
int random_num(int x){
    int i;
    i = rand();
    return (int)((float) i / RAND_MAX * x);
}
int init(){
    printf("小学生四则运算考试模拟系统\n");
    printf("   1.开始\n");
    printf("   2.成绩\n");
    printf("   3.退出\n");
    printf("请选择（输入数字）：\n");
    return 0;
}

int see_grade(){
    printf("============================\n");
    printf("尊敬的%s\n",user_name);
    printf("您的上一次答题情况\n");
    printf("答对题数%d\n",yes);
    printf("得分为：%d分\n",yes * 100 / TOTAL);
    printf("满分为100分\n");
    printf("============================\n");
    writeFile();
    fflush(stdin);
    return 0;
}

int copyRight(){
    printf("本软件由屌丝编写\n");
    printf("感谢您的使用！\n");
    return 0;
}

int getName(){
    printf("欢迎您使用小学生四则运算考试模拟系统\n");
    printf("请输入您的姓名：\n");
    scanf("%s",user_name);
    fflush(stdin);
    return 0;
}

int writeFile(){
    char ch[100];
    char num[10];
    FILE * write;
    write = fopen("data.txt","w");
    if(write == NULL){
        perror("data.txt");
        return 1;
    }
    strcpy(ch,user_name);
    strcat(ch,"\n您的成绩如下\n您共作对");
    //itoa(yes,num,10);
	sprintf(num, "%d", yes);
    strcat(ch,num);
    strcat(ch,"道题\n您的得分为");
    //itoa(yes * 100 / TOTAL , num, 10);
	sprintf(num, "%d", yes * 100 / TOTAL);
    strcat(ch,num);
    strcat(ch,"分\n满分为100分\n");
    fputs(ch,write);
    fclose(write);
    return 0;
}
