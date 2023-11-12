#ifndef CustomerLib_Menu_h
#define CustomerLib_Menu_h

#include<bits/stdc++.h>
#include <windows.h>
#include "MyLib.h"

using namespace std;

void bar_Add_Customer();
string bar_Search_Customer(string nd);
//Dang ky thanh vien
void bar_Add_Customer() {
    int t_color = 11, b_color = 75;
    int x = 80, y = 5, w = 35, h = 2, n = 4;
    string nd[n];
    nd[0] = "ID KH: ";              nd[1] = "Ho va ten: ";     
    nd[2] = "So dien thoai: ";      nd[3] = "Nam sinh: ";       
    box(80, 2, 35, 2, 11, 75, "DIEN THONG TIN KHACH HANG");
    for(int i=x;i<=x+w;i++)
    {
        for (int j=0;j<=n;j++) {
            gotoXY(i,y+h*j);
            cout << char(196);
        }
    }
    for (int i=y;i<=y+h*n;i++)
    {
        gotoXY(x,i); 
        cout << char(179);
        gotoXY(x+w,i);
        cout << char(179);
    }
    gotoXY(x,y);cout << char(218);
    gotoXY(x+w,y);cout << char(191);
    gotoXY(x,y+h*n);cout << char(192);
    gotoXY(x+w,y+h*n);cout << char(217);
    for (int i = 1; i<n; i++) {
        gotoXY(x,y+h*i); cout << char(195);
        gotoXY(x+w,y+h*i); cout << char(180);
    }

    SetColor(t_color);
    for (int i = 0; i<n; i=i+1) {
        gotoXY(x + 1, y + 2*i + 1);
        cout << nd[i] ;
    }
    SetColor(15);
}
// Search
string bar_Search_Customer(string nd) {
    int t_color = 11, b_color = 75;
    int x = 70, y = 12, w = 50, h = 2;
    string answer;
    SetColor(b_color);
    for (int i=x;i<=x+w;i++)
    {
        for(int j=y;j<=y+h+2;j++)
        {
            gotoXY(i,j);cout << " ";
        }
    }
    SetColor(b_color%t_color);
    for(int i=x;i<=x+w;i++)
    {
        gotoXY(i,y);
        cout << char(196);
        gotoXY(i,y+h);
        cout << char(196);
        gotoXY(i,y+h+2);
        cout << char(196);
    }
    for (int i=y;i<=y+h+2;i++)
    {
        gotoXY(x,i); 
        cout << char(179);
        gotoXY(x+w,i);
        cout << char(179);
    }
    gotoXY(x,y);cout << char(218);
    gotoXY(x+w,y);cout << char(191);
    gotoXY(x,y+h+2);cout << char(192);
    gotoXY(x+w,y+h+2);cout << char(217);
    gotoXY(x,y+h); cout << char(195);
    gotoXY(x+w,y+h); cout << char(180);

    SetColor(15);
    gotoXY(x+1,y+1);
    cout <<"Nhap " + nd + " can tim kiem";
    gotoXY(x+1, y+3);
    cout << nd + ":  ";
    gotoXY(x+18, y+3);
    SetColor(15);
    getchar();
    getline(cin, answer);
    gotoXY(0, y + 7);
    return answer;

}
#endif