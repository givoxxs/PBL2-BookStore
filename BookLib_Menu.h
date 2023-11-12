#ifndef BookLib_Menu_h
#define BookLib_Menu_h

#include<bits/stdc++.h>
#include <windows.h>
#include "Mylib.h"

using namespace std;

string Search_BOOK(string nd);
void box_Add_Book();

// Chức năng tìm kiếm của BOOK;
string box_Search_BOOK(string nd) {
    int t_color = 11, b_color = 75;
    int x = 70, y = 16, w = 50, h = 2;
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
    gotoXY(x+12, y+3);
    SetColor(15);
    getchar();
    getline(cin,answer);
    gotoXY(0, y + 8);
    return answer;

}
// Thêm 1 quyển sách vào KHO;
void box_Add_Book() {
    int t_color = 11, b_color = 75;
    int x = 80, y = 5, w = 50, h = 2, n = 10;
    string nd[n];
    nd[0] = "ID: ";
    nd[1] = "Tieu de: ";    nd[2] = "Tac gia: ";    nd[3] = "The loai: ";
    nd[4] = "Gia: ";        nd[5] = "So luong: ";   nd[6] = "Nha xuat ban: ";
    nd[7] = "Nam xuat ban: ";    nd[8] = "Ke sach: ";  nd[9] = "Ngon ngu: ";

    // SetColor(b_color%t_color);
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
#endif // MyMenu_h