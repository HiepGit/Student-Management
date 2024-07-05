#ifndef GUI_H
#define GUI_H
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "core.h"
#include <fstream>
#include <sstream> 
#include <algorithm> 
#include <cctype>    
#include <iomanip>
#include <map>
#include <unistd.h>
using namespace std;

void Color(int x);
void gotoxy(int x, int y); 
void CursorStatus(unsigned size,WINBOOL stt);
void delLine(int x, int y, int leng);
void XoaManHinh();
void SetScreenBufferSize(SHORT width, SHORT height);

void TextSlide1(string Str, int x1, int y1, int x2, int y2, int color);
void TextSlide2(string Str, int x1, int y1, int x2, int y2, int color);
void getHour();
void getDate();
void Intro();


void MakeBorder();
void MakeBorder2(int lenght);
void MakeMainMenuLogin();
void MainMenuLogin();
void BoxLogin();

void MakeData();
void MakeMainMenuTeacher();
void MainMenuTeacher();
void MainMenuHoSo(ListT &l);
void MakeMenuHoSo();
void FileAddStudent(ListT &l);
void DeleteStudent(ListT &l) ;
void GetFromFile(string filename,ListT &l);
void DisplayList(ListT &l);
void SearchStudent(ListT &l);
void XoaVung();
void EditStudent(ListT &l);
void EditStudentSection(ListT &l, NodeT*p);
void MakeBorder3(int lenght);
void MakeMenuIn();
void InDanhSach(ListT &l);

void MainMenuStudent();
void MakeMainMenuStudent();
void WriteToFile(ListT &l);
void ThongKe(ListT &l);//dem so nam so nu
void MakeMenuDiem();
void MainMenuDiem(ListP &l);
NodeT* GetStudentInfo(ListT &list, const string& mahs);
bool IsScoreEntered(ListP &list, const string& mahs);
void FileAddPoint(ListP &l);
void WritePointToFile(ListP &hs);
void GetFromFile2(string filename,ListP &l);

void MakeMenuIn2();
void BangDiem(ListP &l);
void DisplayPoint(ListP &l);
void MakeBorder4(int lenght);
void DeletePoint(ListP &l);
void SearchStudent(ListP &l);
void ThongKeDiem(ListP &l);
void MakeBorder5(int lenght);

void WriteAccToFile(ListT &hs);
void StudentLogin();

void XemHoSo();
void XemDiem();
void MakeMenuEdit2();
void EditPoint(ListP &l);
void EditPointSection(ListP &l, NodeP*p);
void SetScreenBufferSize(SHORT width, SHORT height);
void resizeConsole(int width, int height);


#endif // GUI_H
