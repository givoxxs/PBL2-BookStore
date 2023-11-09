#ifndef MyLib_h
#define MyLib_h

#include <stdio.h>
#include <conio.h>
#include<ctime> /* thư viện hỗ trợ về thời gian thực */
#include "windows.h" // thư viện này bá đạo lắm nhé - chứa nhiều đồ chơi nek - cứ tìm hiểu dần dần s
//======= lấy tọa độ x của con trỏ hiện tại =============
#define KEY_NONE	-1
void thanh_sang(int x,int y,int w,int h,int b_color,std::string nd);
void box(int x,int y,int w,int h,int t_color,int b_color,std::string nd);
void MulBox(int x,int y,int w,int h,int t_color,int b_color,std::string nd[],int n);
int Menu(int x,int y,int w,int h,int t_color,int b_color,std::string nd[],int n);
int whereX();
int whereY();
void gotoXY(short x, short y);
void SetColor(WORD color);
void SetBGColor(WORD color);
void ShowCur(bool CursorVisibility);
int inputKey();
void bar_Change_E();

#endif // MyLib_h // tránh đụng độ thư viện khi gọi chồng file lên nhau
