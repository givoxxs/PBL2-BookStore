#ifndef FirstLib_Menu_h
#define FirstLib_Menu_h

#include<bits/stdc++.h>
#include <windows.h>
#include "FirstLib.h"

using namespace std;

void bright_bar(int x,int y,int w,int h,int b_color,string nd);
void bar(int x,int y,int w,int h,int t_color,int b_color,string nd);
void Mulbar(int x,int y,int w,int h,int t_color,int b_color,string nd[],int n);
int Menu_bar(int x,int y,int w,int h,int t_color,int b_color,string nd[],int n);
string Search_BOOK(string nd);
void bar_Add_Book();
// Menu _ bar
int Menu_bar(int x,int y,int w,int h,int t_color,int b_color,string nd[],int n)
{
    Show_Cur(0);
    Mulbar(x,y,w,h,t_color,b_color,nd,n);

    int posbefore=0,pos=0;
    int xpoint=x,ypoint=y;
    int xbefore=x,ybefore=y;
    bool check=false;

    bright_bar(xpoint,ypoint,w,h,4,nd[pos]);
    while (true)
    {
        if (check==true)
        {
            goto_XY(xbefore,ybefore);
            bright_bar(xbefore,ybefore,w,h,b_color,nd[posbefore]);
            bright_bar(xpoint,ypoint,w,h,4,nd[pos]);
            check=false;
        }
        if (_kbhit())
        {
            char c=_getch();
            if (c==13) break;
            if (c==-32)
            {
                check=true;
                c=_getch();
                ybefore=ypoint;
                posbefore=pos;
                if (c==72)
                {
                    if (ypoint!=y) {
                        ypoint-=h;
                        pos--;
                    }
                    else {
                        pos=n-1;
                        ypoint = y+h*(n-1);
                    }
                }
                if(c==80)
                {
                    if (ypoint != y+h*(n-1)) {
                        ypoint+=h;
                        pos++;
                    }
                    else {
                        pos=0;
                        ypoint=y;
                    }
                }
            }
        }
    }
    Set_Color(7);
    Show_Cur(1);
    return pos;
}

void bright_bar(int x,int y,int w,int h,int b_color,string nd)
{
    Set_Color(b_color);
    for (int i=x+1;i<x+w;i++)
    {
        for(int j=y+1;j<y+h;j++)
        {
            goto_XY(i,j);cout << " ";
        }
    }
    Set_Color(b_color);
    goto_XY(x+1,y+1);
    cout << nd;
}

void bar(int x,int y,int w,int h,int t_color,int b_color,string nd)
{
    Set_Color(b_color);
    for (int i=x;i<=x+w;i++)
    {
        for(int j=y;j<=y+h;j++)
        {
            goto_XY(i,j);cout << " ";
        }
    }
    Set_Color(t_color);
    goto_XY(x+1,y+1);
    cout << nd;
    Set_Color(b_color%t_color);
    if (h<=1 || w<=1) return;
    for(int i=x;i<=x+w;i++)
    {
        goto_XY(i,y);
        cout << char(196);
        goto_XY(i,y+h);
        cout << char(196);
    }
    for (int i=y;i<=y+h;i++)
    {
        goto_XY(x,i);
        cout << char(179);
        goto_XY(x+w,i);
        cout << char(179);
    }
    goto_XY(x,y);cout << char(218);
    goto_XY(x+w,y);cout << char(191);
    goto_XY(x,y+h);cout << char(192);
    goto_XY(x+w,y+h);cout << char(217);
}

void Mulbar(int x,int y,int w,int h,int t_color,int b_color,string nd[],int n)
{
    for (int i=0;i<n;i++)
    {
        bar(x,y+h*i,w,h,t_color,b_color,nd[i]);
        if(i!=0)
        {
            goto_XY(x,y+h*i); cout << char(195);
            goto_XY(x+w,y+h*i); cout << char(180);
        }
    }
}
// Chức năng tìm kiếm của BOOK;
string bar_Search_BOOK(string nd) {
    int t_color = 11, b_color = 75;
    int x = 70, y = 16, w = 50, h = 2;
    string answer;
    Set_Color(b_color);
    for (int i=x;i<=x+w;i++)
    {
        for(int j=y;j<=y+h+2;j++)
        {
            goto_XY(i,j);cout << " ";
        }
    }
    Set_Color(b_color%t_color);
    for(int i=x;i<=x+w;i++)
    {
        goto_XY(i,y);
        cout << char(196);
        goto_XY(i,y+h);
        cout << char(196);
        goto_XY(i,y+h+2);
        cout << char(196);
    }
    for (int i=y;i<=y+h+2;i++)
    {
        goto_XY(x,i); 
        cout << char(179);
        goto_XY(x+w,i);
        cout << char(179);
    }
    goto_XY(x,y);cout << char(218);
    goto_XY(x+w,y);cout << char(191);
    goto_XY(x,y+h+2);cout << char(192);
    goto_XY(x+w,y+h+2);cout << char(217);
    goto_XY(x,y+h); cout << char(195);
    goto_XY(x+w,y+h); cout << char(180);

    Set_Color(15);
    goto_XY(x+1,y+1);
    cout <<"Nhap " + nd + " can tim kiem";
    goto_XY(x+1, y+3);
    cout << nd + ":  ";
    goto_XY(x+12, y+3);
    Set_Color(15);
    cin >> answer;
    goto_XY(0, y + 8);
    return answer;

}
// Thêm 1 quyển sách vào KHO;
void bar_Add_Book() {
    int t_color = 11, b_color = 75;
    int x = 80, y = 5, w = 50, h = 2, n = 10;
    string nd[n];
    nd[0] = "ID: ";
    nd[1] = "Tieu de: ";    nd[2] = "Tac gia: ";    nd[3] = "The loai: ";
    nd[4] = "Gia: ";        nd[5] = "So luong: ";   nd[6] = "Nha xuat ban: ";
    nd[7] = "Nam xuat ban: ";    nd[8] = "Ke sach: ";  nd[9] = "Ngon ngu: ";

    // Set_Color(b_color%t_color);
    for(int i=x;i<=x+w;i++)
    {
        for (int j=0;j<=n;j++) {
            goto_XY(i,y+h*j);
            cout << char(196);
        }
    }
    for (int i=y;i<=y+h*n;i++)
    {
        goto_XY(x,i); 
        cout << char(179);
        goto_XY(x+w,i);
        cout << char(179);
    }
    goto_XY(x,y);cout << char(218);
    goto_XY(x+w,y);cout << char(191);
    goto_XY(x,y+h*n);cout << char(192);
    goto_XY(x+w,y+h*n);cout << char(217);
    for (int i = 1; i<n; i++) {
        goto_XY(x,y+h*i); cout << char(195);
        goto_XY(x+w,y+h*i); cout << char(180);
    }


    Set_Color(t_color);
    for (int i = 0; i<n; i=i+1) {
        goto_XY(x + 1, y + 2*i + 1);
        cout << nd[i] ;
    }
    Set_Color(15);
}
#endif // MyMenu_bar_h