#include "gui.h"

using namespace std;

void Color(int x) {
    HANDLE color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, x);
}

void CursorStatus(unsigned size, WINBOOL stt) {
    CONSOLE_CURSOR_INFO crs_inf = {size, stt};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &crs_inf);
}

void gotoxy(int x, int y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x - 1, y - 1};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void XoaManHinh() {
    for (int i = 66; i < 120; i++) {
        for (int j = 12; j < 35; j++) {
            gotoxy(i, j);
            cout << " ";
        }
    }
}

void delLine(int x, int y, int leng) {
    gotoxy(x, y);
    for (int i = 1; i <= leng; i++) {
        cout << " ";
    }
    gotoxy(x, y);
}

void TextSlide2(string Str, int x1, int y1, int x2, int y2, int color) {
    Color(color);
    for (int i = 0; i < 4; i++) {
        delLine(x1, y1, Str.length());
        gotoxy(x1, y1);
        Sleep(50);
        cout << Str;
        Sleep(50);
    }
}

void getHour() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime); // lay thoi gian hien tai
    timeinfo = localtime(&rawtime); // chuyen doi thoi gian hien tai thanh cau truc tm

    // in gio va phut voi dinh dang 2 chu so
     cout <<  setfill('0') <<  setw(2) << timeinfo->tm_hour << ":"
              <<  setfill('0') <<  setw(2) << timeinfo->tm_min <<  endl;
}

void getDate() {
    time_t rawtime;
    struct tm * timeinfo;
    rawtime = time(NULL);
    timeinfo = localtime(&rawtime);
    cout << timeinfo->tm_mday << "/" << timeinfo->tm_mon + 1 << "/" << timeinfo->tm_year + 1900;
}
void Intro() {
    //make border
    CursorStatus(25, FALSE);
    Color(12);
    //bien trai
    gotoxy(41, 11);
    printf("%c", 186);
    for (int i = 12; i < 35; i++) {
        gotoxy(41, i);
        printf("|");
        Sleep(5);
    }
    //bien duoi
    gotoxy(41, 35);
    printf("%c", 186);
    for (int i = 42; i < 120; i++) {
        gotoxy(i, 35);
        printf("_");
        Sleep(5);
    }
    //bien phai
    gotoxy(120, 35);
    printf("%c", 186);
    for (int i = 34; i > 11; i--) {
        gotoxy(120, i);
        printf("|");
        Sleep(5);
    }
    //bien tren
    gotoxy(120, 11);
    printf("%c", 186);
    for (int i = 119; i > 41; i--) {
        gotoxy(i, 11);
        printf("_");
        Sleep(5);
    }

    Color(11);
    gotoxy(43, 13);
    cout << " TRUONG DAI HOC BACH KHOA DA NANG ";
    gotoxy(45, 14);
    Color(13);
    cout << " Khoa: Cong nghe thong tin ";
    gotoxy(110, 12);
    Color(11);
    getHour();
    gotoxy(108, 13);
    getDate();
    
    gotoxy(78, 19);
    Color(12);
    cout << "_CHUONG TRINH_";
    TextSlide2("_*_ Quan Ly hoc sinh _*_", 72, 21, 110, 21, 14);
    gotoxy(68, 24);
    Color(15);
    cout << "Chao Mung Den Voi Chuong Trinh..!";
    gotoxy(66, 27);
    cout << "Made By: ";
    TextSlide2("HUYNH DINH THAI", 78, 27, 105, 27, 14);
    TextSlide2("CAO HUU HIEP", 78, 28, 105, 27, 14); 
    Color(12);
    gotoxy(65, 30);
    system("PAUSE");
}

void MakeBorder() {
    Color(9);
    for (int i = 12; i < 35; i++) {
        gotoxy(41, i);
        printf("|");
        gotoxy(120, i);
        printf("|");
    }
    for (int i = 42; i < 120; i++) {
        gotoxy(i, 11);
        printf("_" );
        gotoxy(i, 35);
        printf("_");
    }
    for (int i = 12; i < 35; i++) {
        gotoxy(65, i);
        printf("|");
    }
    gotoxy(41, 11);
    printf("%c", 186);
    gotoxy(120, 11);
    printf("%c", 186);
    gotoxy(41, 35);
    printf("%c", 186);
    gotoxy(120, 35);
    printf("%c", 186);
    gotoxy(65, 11);
    printf("%c", 186);
    gotoxy(65, 35);
    printf("%c", 186);
    gotoxy(45, 35);
}

void MakeBorder2(int lenght) {
  
    Color(9);
    int pos_y = 6;
    for (int i = 2; i <= lenght + pos_y; i++) {
        gotoxy(1, i);
        printf("|");
        gotoxy(8,i);
        printf("|");
        gotoxy(17,i);
        printf("|");
        gotoxy(41, i);
        printf("|");
        gotoxy(53, i);
        printf("|");
        gotoxy(60, i);
        printf("|");
        gotoxy(73, i);
        printf("|");
        gotoxy(99, i);
        printf("|");
        gotoxy(113, i);
        printf("|");
        gotoxy(136, i);
        printf("|");
        gotoxy(150, i);
        printf("|");
    }

    for (int i = 2; i < 150; i++) {
        gotoxy(i, 2);
        printf("_");
        gotoxy(i, 4);
        printf("_");
        gotoxy(i, lenght + pos_y);
        printf("_");
    }
    gotoxy(30, 1);
    Color(12);
    cout << "__***IN Danh Sach Sinh Vien***__    ";
    Color(11);
    gotoxy(2,3);
    cout<<"Ma hs";
    gotoxy(11,3);
    cout <<"Lop";
    gotoxy(26, 3);
    cout << "Ho ten";
    gotoxy(42, 3);
    cout << "Ngay sinh";
    gotoxy(55,3);
    cout<< "Sex";
    gotoxy(65, 3);
    cout << "Sdt";
    gotoxy(80, 3);
    cout << "Ten bo";
    gotoxy(103, 3);
    cout << "Sdt bo";
    gotoxy(121, 3);
    cout << "Ten me";
    gotoxy(140, 3);
    cout << "Sdt me";
    gotoxy(2, 5);
    Color(15);
}

void MakeMenuIn(){
	Color(15);
	gotoxy(71,15);
	cout<< "In danh sach duoc sap xep theo?";
	gotoxy(71,16);
	cout<<"Ten ";
	gotoxy(71,17);
	cout<<"Lop ";
}

void InDanhSach(ListT &l){
	Color(15);
	system("cls");
	MakeMenuHoSo();
	int pos = 1;
    char choise;
    MakeMenuIn();
    do {
        switch (pos) {
        	case 1:
                MakeMenuIn();
                gotoxy(71, 16);
                Color(172);
                cout << "Ten ";
                char et;
                et = getch();
                if (int(et) == 13) {
                	Color(15);
                	SortByName(l);
                	DisplayList(l);
                	MainMenuHoSo(l);;
                }               
                break;
            case 2:
                MakeMenuIn();
                gotoxy(71, 17);
                Color(172);
                cout << "Lop ";
                char et1;
                et1 = getch();
                if (int(et1) == 13) {
                	Color(15);
                	SortByClass(l);
                	DisplayList(l);
                	MainMenuHoSo(l);;
                }
                break;
    }
    
        choise = getch();
        if (choise == 72 || choise == 80) pos = (choise == 72 && pos > 0) ? --pos : ((pos < 2) ? ++pos : pos = 1);

    } while (choise != 8);
}	

void DisplayList(ListT &l) { 
	NodeT* temp = l.head;
    int pos_y=6;
    system("cls");
    MakeBorder2(lenghtNode(l));
    while (temp != NULL) {
    gotoxy(2,pos_y);
    cout<< temp->mahs;
    gotoxy(11,pos_y);
    cout << temp->lop;
    gotoxy(19, pos_y);
    cout << temp->name;
    gotoxy(42, pos_y);
    cout << temp->birthday;
    gotoxy(56,pos_y);
    cout<<temp->sex;
    gotoxy(62, pos_y);			
    cout << temp->phone;
    gotoxy(75, pos_y);
    cout << temp->fathername;
    gotoxy(101, pos_y);
    cout << temp->fatherphone;
    gotoxy(115, pos_y );
    cout << temp->mothername;
    gotoxy(137, pos_y );
    cout << temp->motherphone;
    pos_y += 1;
    temp = temp->next;
	}
	gotoxy(110,1);
	system("PAUSE");
}

void MakeMainMenuLogin() {
    Color(15);
    gotoxy(46,12);
    cout << "**LOGIN**" ;
    gotoxy(42,15);
    cout<<"Giao vien";
    gotoxy(42,16);
    cout<<"Hoc sinh";
    MakeBorder();
}

void MainMenuLogin() {
	SetScreenBufferSize(151,10000);
    CursorStatus(25, FALSE);
    fflush(stdin);
    MakeData();
    system("cls");
    int pos = 1;
    MakeMainMenuLogin();
    do {
        char choise;
        switch (pos) {
            case 1:Color(15);
                //system("cls");
                MakeMainMenuLogin();
                gotoxy(42, 15);
                Color(172);
                cout << "Giao vien";
                char et;
                et = getch();
				if (int(et) == 13) {
					BoxLogin();	
				}
                Color(15);
                break;
            case 2:Color(15);                
                MakeMainMenuLogin();
                gotoxy(42, 16);
                Color(172);
                cout << "Hoc sinh";
                char et2;
                et2 = getch();
                if(int(et2)==13) {
                	StudentLogin();
				}
                break;            
        }
        choise = getch();
        if (choise != 0) {

            if (choise == 72 || choise == 80) pos = (choise == 72 && pos > 0) ? --pos : ((pos < 2) ? ++pos : pos = 1);
        }

    } while (1);
}

ListT hs;
ListP hs1;

void MakeData() {
    Init(hs);
    ifstream file;
    string filename = "HoSo.txt";
    GetFromFile(filename, hs);

    Init2(hs1);
    ifstream file1;
    string filename1 = "Diem.txt";
    GetFromFile2(filename1, hs1);
}


void BoxLogin() {
	string Password;
	string Username;
	bool loginSuccess = false;
    while(!loginSuccess) {
    	Color(15);    	
    	delLine(70,15, 30);
    	delLine(70,17,30);
    	delLine(75,19,30);
	    gotoxy(70,15);
	    cout<<"Username:";
	    gotoxy(82,15);
	    CursorStatus(25, TRUE);
	    fflush(stdin);
	    cin>>Username;
	    CursorStatus(25, FALSE);
	    gotoxy(70, 17);
	    cout<<"Password:";
	    gotoxy(82,17);
	    CursorStatus(25, TRUE);
	    fflush(stdin);
	    cin>>Password;
	    CursorStatus(25, FALSE);
	    	if(CheckAcc1(Username, Password)) {			
				loginSuccess = true;
			} else {
				gotoxy(75,19);
				cout<<"Sai tai khoan hoac mat khau!";
				Sleep(300);
				cin.clear();
	        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
						    	
			}
		}
	MainMenuTeacher();		
	}

void MakeMainMenuTeacher() {
	Color(15);
    gotoxy(46, 12);
    cout << "**MainMenu**" ;
    gotoxy(42,15);
    cout << "Quan li ho so ";
    gotoxy(42, 16);
    cout << "Quan li diem ";
    gotoxy(42,17);
    cout<< "Exit ";
    MakeBorder();
}

void MainMenuTeacher() {
	CursorStatus(25, FALSE);
    fflush(stdin);
    system("cls");
    int pos = 1;
    MakeMainMenuLogin();
    
    do {
        char choise;
        switch (pos) {
            case 1:Color(15);
                MakeMainMenuTeacher();
                gotoxy(42, 15);
                Color(172);
                cout << "Quan li ho so ";
                Color(15);
                char et;
                et = getch();
				if (int(et) == 13) {
					gotoxy(70,18);
					Color(2);
					cout<<"Du lieu duoc luu o file HoSo.txt";
					Sleep(500);
					MainMenuHoSo(hs);
				}
                Color(15);
                break;
            case 2:Color(15);               
                MakeMainMenuTeacher();
                gotoxy(42, 16);
                Color(172);
                cout << "Quan li diem ";
                char et2;
                et2 = getch();
                if(int(et2)==13){
                	gotoxy(70,18);
					Color(2);
					cout<<"Du lieu duoc luu o file Diem.txt";
					Sleep(500);
					MainMenuDiem(hs1);
				}
                
                break; 
			case 3: Color(15);
			    MakeMainMenuTeacher();
				gotoxy(42,17);
				Color(172);
				cout<< "Exit ";
				char et3;
				et3=getch();
				if(int(et3)==13) {
					Color(15);
					exit(1);}
				Color(15);
				break;
			
        }
        choise = getch();
        if (choise != 0) {

            if (choise == 72 || choise == 80) pos = (choise == 72 && pos > 0) ? --pos : ((pos < 3) ? ++pos : pos = 1);
        }

    } while (1);
}

void FileAddStudent(ListT &l){	
	int k,n;       
	string lop;
	string birthday;
	string sex;
    string name;
	string phone;
	string fathername;
	string fatherphone;
	string mothername;
	string motherphone;	
	Color(15);	
    gotoxy(72,17);
    cout<<"Nhap so hoc sinh them vao:";
    do {
    	Color(15);
    	gotoxy(100,17);
    	delLine(100,17,5);
    	CursorStatus(25,TRUE);
    	fflush(stdin);
    	cin>>n;
    	CursorStatus(25,FALSE);
    if (cin.fail() || n <= 0) {
		Color(4);
		gotoxy(73,18) ;		
        cout << "Khong hop le. Vui long nhap lai";     
		cout.flush();   
        Sleep(300);
        cin.clear();
        delLine(73,18,40);
    	} else {
        break; // thoat vong lap neu nhap dung
    	}
	} while (true);   
    for(int i=1;i<=n;i++) {
    	string mahs = MakeID(l);
    	Color(15);
    	XoaManHinh();
    	delLine(70,15,50);
    	delLine(70,17,50);
    	gotoxy(80,13);
    	cout<<"Hoc sinh thu:"<<i;
    	gotoxy(71,15);
    	cout<<"Ma hoc sinh:";
    	gotoxy(90,15);
    	cout<<mahs;
    	gotoxy(71,16);
    	cout << "Lop:";
    	gotoxy(90,16);
    	CursorStatus(25,TRUE);
    	fflush(stdin);
    	cin>>lop;
    	CursorStatus(25,FALSE);
    	gotoxy(71,17);
    	cout<<"Ten hoc sinh:";
    	gotoxy(90,17);
    	CursorStatus(25,TRUE);
    	fflush(stdin);
    	getline(cin, name);
    	CursorStatus(25,FALSE);
    	fflush(stdin);
    	ChuanHoa(&name);
    	delLine(90,17,30);
    	cout<<name;
    	gotoxy(71,18);
    	cout<<"Ngay sinh(X/Y/Z):";
    	gotoxy(90,18);
    	CursorStatus(25,TRUE);
    	fflush(stdin);
    	cin>>birthday;
    	CursorStatus(25,FALSE);
    	gotoxy(71,19);
    	cout<<"Gioi tinh:";
    	gotoxy(90,19);
    	CursorStatus(25, TRUE);
    	fflush(stdin);
    	cin>>sex;
    	ChuanHoa(&sex);
    	CursorStatus(25,FALSE);
    	gotoxy(71,20);
    	cout<<"SÐT:";
    	gotoxy(90,20);
    	CursorStatus(25, TRUE);
    	while (true) {
            fflush(stdin);
            getline(cin, phone);
            if (isPhoneNumberValid(phone)) {
                break; // thoat neu sdt hop le
            } else {
            	gotoxy(90,20);
            	Color(4);
                cout << "Sdt khong hop le!";
                Sleep(200);
                Color(15);
                delLine(90,20,30); // xoa sdt cu
            }
        }
        CursorStatus(25,FALSE);
    	gotoxy(71,21);
    	cout<<"Ten cha:";
    	gotoxy(90,21);
    	CursorStatus(25, TRUE);
    	fflush(stdin);
    	getline(cin, fathername);
    	CursorStatus(25,FALSE);
    	gotoxy(71,22);
    	cout<<"SÐT cha:";
    	gotoxy(90,22);
    	CursorStatus(25, TRUE);
    	while (true) {
            fflush(stdin);
            getline(cin, fatherphone);
            if (isPhoneNumberValid(fatherphone)) {
                break; // thoat neu sdt hop le
            } else {
            	gotoxy(90,22);
            	Color(4);
                cout << "Sdt khong hop le!";
                Sleep(200);
                Color(15);
                delLine(90,22,30); // xoa sdt cu
            }
        }
    	CursorStatus(25,FALSE);
    	gotoxy(71,23);
    	cout<<"Ten me:";
    	gotoxy(90,23);
    	CursorStatus(25, TRUE);
    	fflush(stdin);
    	getline(cin,mothername);
    	CursorStatus(25,FALSE);
    	gotoxy(71,24);
    	cout<<"SÐT me:";
    	gotoxy(90,24);
    	CursorStatus(25, TRUE);
    	while (true) {
            fflush(stdin);
            getline(cin, motherphone);
            if (isPhoneNumberValid(motherphone)) {
                break; // Thoat neu sdt hop le
            } else {
            	gotoxy(90,24);
            	Color(4);
                cout << "Sdt khong hop le!";
                Sleep(200);
                Color(15);
                delLine(90,24,30); // xoa sdt cu
            }
        }
    	CursorStatus(25,FALSE);
    	bool exists = checkIfExists(l, name, phone);
        while (exists) {
        	gotoxy(85,27);
        	Color(4);
            cout << "Hoc sinh da ton tai. Hay nhap lai!" << endl;
            Sleep(800);
            Color(15);
    	XoaManHinh();
    	delLine(70,15,50);
    	delLine(70,17,50);
    	gotoxy(80,13);
    	cout<<"Hoc sinh thu:"<<i;
    	gotoxy(71,15);
    	cout<<"Ma hoc sinh:";
    	gotoxy(90,15);
    	cout<<mahs;
    	gotoxy(71,16);
    	cout << "Lop:";
    	gotoxy(90,16);
    	CursorStatus(25,TRUE);
    	fflush(stdin);
    	cin>>lop;
    	CursorStatus(25,FALSE);
    	gotoxy(71,17);
    	cout<<"Ten hoc sinh:";
    	gotoxy(90,17);
    	CursorStatus(25,TRUE);
    	fflush(stdin);
    	getline(cin, name);
    	CursorStatus(25,FALSE);
    	fflush(stdin);
    	ChuanHoa(&name);
    	delLine(90,17,30);
    	cout<<name;
    	gotoxy(71,18);
    	cout<<"Ngay sinh(X/Y/Z):";
    	gotoxy(90,18);
    	CursorStatus(25,TRUE);
    	fflush(stdin);
    	cin>>birthday;
    	CursorStatus(25,FALSE);
    	gotoxy(71,19);
    	cout<<"Gioi tinh:";
    	gotoxy(90,19);
    	CursorStatus(25, TRUE);
    	fflush(stdin);
    	cin>>sex;
    	CursorStatus(25,FALSE);
    	gotoxy(71,20);
    	cout<<"SÐT:";
    	gotoxy(90,20);
    	CursorStatus(25, TRUE);
    	while (true) {
            fflush(stdin);
            getline(cin, phone);
            if (isPhoneNumberValid(phone)) {
                break; // thoat neu sdt hop le
            } else {
            	gotoxy(90,20);
            	Color(4);
                cout << "Sdt khong hop le!";
                Sleep(200);
                Color(15);
                delLine(90,20,30); // xoa sdt cu
            }
        }
        CursorStatus(25,FALSE);
    	gotoxy(71,21);
    	cout<<"Ten cha:";
    	gotoxy(90,21);
    	CursorStatus(25, TRUE);
    	fflush(stdin);
    	getline(cin, fathername);
    	CursorStatus(25,FALSE);
    	gotoxy(71,22);
    	cout<<"SÐT cha:";
    	gotoxy(90,22);
    	CursorStatus(25, TRUE);
    	while (true) {
            fflush(stdin);
            getline(cin, fatherphone);
            if (isPhoneNumberValid(fatherphone)) {
                break; // thoat neu sdt hop le
            } else {
            	gotoxy(90,22);
            	Color(4);
                cout << "Sdt khong hop le!";
                Sleep(200);
                Color(15);
                delLine(90,22,30); // xoa sdt cu
            }
        }
    	CursorStatus(25,FALSE);
    	gotoxy(71,23);
    	cout<<"Ten me:";
    	gotoxy(90,23);
    	CursorStatus(25, TRUE);
    	fflush(stdin);
    	getline(cin,mothername);
    	CursorStatus(25,FALSE);
    	gotoxy(71,24);
    	cout<<"SÐT me:";
    	gotoxy(90,24);
    	CursorStatus(25, TRUE);
    	while (true) {
            fflush(stdin);
            getline(cin, motherphone);
            if (isPhoneNumberValid(motherphone)) {
                break; // thoat neu sdt hop le
            } else {
            	gotoxy(90,24);
            	Color(4);
                cout << "Sdt khong hop le!";
                Sleep(200);
                Color(15);
                delLine(90,24,30); // xoa sdt cu
            }
        }
    	CursorStatus(25,FALSE);
    	exists = checkIfExists(l, name, phone);
        }
    	addTail(l,mahs,lop,name,birthday,sex,phone,fathername,fatherphone,mothername,motherphone);
	   	
	}	
}

void MakeMenuHoSo() {
	Color(15);	
    gotoxy(46, 12);
    cout << "**Menu**" ;
    gotoxy(42, 15);
    cout << "Them hoc sinh ";
    gotoxy(42, 16);
    cout << "Xoa hoc sinh ";
    gotoxy(42, 17);
    cout << "In danh sach lop ";
    gotoxy(42, 18);
    cout << "Tim kiem hoc sinh ";
    gotoxy(42,19);
    cout<< "Sua thong tin ";
    gotoxy(42,20);
    cout<< "Thong Ke ";
    gotoxy(42,21);
    cout<< "Back ";
    MakeBorder();
}

void MainMenuHoSo(ListT &l){
	string filename = "HoSo.txt";		
	CursorStatus(25, FALSE);
    fflush(stdin);
    system("cls");
    int pos = 1;
    MakeMenuHoSo();
    do {
        char choise;
        switch (pos) {
            case 1:Color(15);
                //system("cls");
                MakeMenuHoSo();
                gotoxy(42, 15);
                Color(172);
                cout << "Them hoc sinh ";
                char et1;
                et1 = getch();
				if (int(et1) == 13) {
					FileAddStudent(l);
					WriteToFile(l);
					WriteAccToFile(l);
					gotoxy(72,27);    
					Color(2);cout<<"Da them vao file!";Color(15);
					Sleep(500);
					MainMenuHoSo(l);;	
				}
                Color(15);
                break;
            case 2:Color(15);                
                MakeMenuHoSo();
                gotoxy(42, 16);
                Color(172);
                cout << "Xoa hoc sinh ";
                char et2;
                et2 = getch();
                if(int(et2)==13) {
                	Color(15);
                	gotoxy(72,16);
    				cout << "Xem danh sach de xoa!";
    				gotoxy(72,18);
    				system("PAUSE");
    				SortByClass(l);
    				DisplayList(l);
                	DeleteStudent(l);
                	DeleteInFile(filename);
					WriteToFile(l);
					MainMenuHoSo(l);;
				}
                Color(15);
                break; 
            case 3:Color(15);                
                MakeMenuHoSo();
                gotoxy(42, 17);
                Color(172);
                cout << "In danh sach lop ";
                char et3;
                et3 = getch();
                if(int(et3)==13) {
				    Color(15);           	
					InDanhSach(l);					
				               	
				}
                Color(15);
                break; 
            case 4:Color(15);                
                MakeMenuHoSo();
                gotoxy(42, 18);
                Color(172);
                cout << "Tim kiem hoc sinh ";
                char et4;
                et4 = getch();
                if(int(et4)==13) {
                	SearchStudent(l);
                	MainMenuHoSo(l);;
				}
                Color(15);
                break;
            case 5:Color(15);                
                MakeMenuHoSo();
                gotoxy(42, 19);
                Color(172);
                cout << "Sua thong tin ";
                char et5;
                et5 = getch();
                if(int(et5)==13) {
                	Color(15);
                	gotoxy(72,16);
    				cout << "Xem danh sach de sua!";
    				gotoxy(72,18);
    				system("PAUSE");
    				SortByClass(l);
    				DisplayList(l);
    				system("cls");
                	EditStudent(l);
				}
                Color(15);
                break;
			case 6:Color(15);                
                MakeMenuHoSo();
                gotoxy(42, 20);
                Color(172);
                cout << "Thong Ke ";
                char et6;
                et6 = getch();
                if(int(et6)==13) {
                	 ThongKe(l);
                	 MainMenuHoSo(l);;;
				}
                Color(15);
                break;  
			case 7: Color(15);
			    MakeMenuHoSo();
				gotoxy(42,21);
				Color(172);
				cout<< "Back ";
				char et7;
				et7=getch();
				if(int(et7)==13) {
					Color(15);
					MainMenuTeacher();
				Color(15);
				break;
		}
        }
        choise = getch();
        if (choise != 0) {

            if (choise == 72 || choise == 80) pos = (choise == 72 && pos > 0) ? --pos : ((pos < 7) ? ++pos : pos = 1);
        }

    } while (1);
}
void MakeMenuContinue(){
	Color(1);
	gotoxy(85,22);
	cout<<"Tiep Tuc";
	gotoxy(85,23);
	cout<<"Quay lai";
}

void DeleteStudent(ListT &l) {
	system("cls");
	MakeMenuHoSo();
    string keyMahs;
    Color(15);
    gotoxy(72, 17);
    cout << "Nhap ma hoc sinh can xoa: ";
    gotoxy(100, 17);
    CursorStatus(25, TRUE);
    cin>>keyMahs;
    CursorStatus(25, FALSE);
	NodeT *p = l.head; 
    NodeT *prev = NULL;
    bool isDeleted = false;
    while (p != NULL) {
        if (p->mahs == keyMahs) {
            if (p == l.head) {
                l.head = p->next;
                if (l.head == NULL) {  // Neu danh sach chi co 1 node
                    l.tail = NULL;
                }
            } else {
                prev->next = p->next;
                if (p->next == NULL) {  // Neu node xoa la cuoi cung
                    l.tail = prev;
                }
            }
            delete p;
            isDeleted = true;
            break;
        }
        prev = p;
        p = p->next;
    }

    if (!isDeleted) {
        Color(4);
        gotoxy(75, 19);
        cout << "Khong tim thay hoc sinh do!";
        int pos = 1;
        bool continueDeletion = true;
        MakeMenuContinue();
        do {
            char choice;
            switch (pos) {
                case 1:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 22);
                    Color(172);
                    cout << "Tiep tuc";
                    char et1;
                    et1 = getch();
                    if (int(et1) == 13) {
                    	Color(15);
                    	delLine(100,17,20);
                    	delLine(70,19,50);
                    	delLine(85,22,12);
                    	delLine(85,23,12);                        
                        DeleteStudent(l);
                        continueDeletion = false;
                    }
                    break;
                case 2:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 23);
                    Color(172);
                    cout << "Quay lai";
                    char et2;
                    et2 = getch();
                    if (int(et2) == 13) {
                    	Color(15);
                        MainMenuHoSo(l);;
                        return;
                    }
                    Color(15);
                    break;
            }
            if (!continueDeletion) break;
            choice = getch();
            if (choice != 0) {
                if (choice == 72 || choice == 80) pos = (choice == 72 && pos > 0) ? --pos : ((pos < 2) ? ++pos : pos = 1);
            }
        } while (continueDeletion);
    }
    else {
    	gotoxy(72,20);
    	cout<<"Da xoa! Xem danh sach sau khi xoa.";
    	gotoxy(72,22);
    	system("PAUSE");
    	SortByClass(l);
        DisplayList(l);
    }
}

void SearchStudent(ListT &l) { 
    string key;
    Color(15);
    gotoxy(72, 17);
    cout << "Nhap noi dung can tim: ";
    gotoxy(100, 17);
    CursorStatus(25, TRUE);
    getline(cin, key);
    CursorStatus(25, FALSE);
   	ListT temp;
   	Init(temp);
   	NodeT *p =l.head;
   	while (p != NULL) {
        if (search(p, key) != NULL) {
        NodeT*q = new NodeT;
        copyNode(p, q);
        addHead(temp, q);
        }
        p = p->next;
        }
    if (isEmpty(temp)) { // Neu danh sach rong
       	Color(4);
        gotoxy(75, 19);
        cout << "Khong tim thay!";
        int pos = 1;
        bool continueDeletion = true;
        MakeMenuContinue();
        do {
            char choice;
            switch (pos) {
                case 1:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 22);
                    Color(172);
                    cout << "Tiep tuc";
                    char et1;
                    et1 = getch();
                    if (int(et1) == 13) {
                    	Color(15);
                    	delLine(100,17,20);
                    	delLine(70,19,50);
                    	delLine(85,22,12);
                    	delLine(85,23,12);                        
                        SearchStudent(l);
                        continueDeletion = false;
                    }
                    break;
                case 2:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 23);
                    Color(172);
                    cout << "Quay lai";
                    char et2;
                    et2 = getch();
                    if (int(et2) == 13) {
                    	Color(15);
                        MainMenuHoSo(l);;
                        return;
                    }
                    Color(15);
                    break;
            }
            if (!continueDeletion) break;
            choice = getch();
            if (choice != 0) {
                if (choice == 72 || choice == 80) pos = (choice == 72 && pos > 0) ? --pos : ((pos < 2) ? ++pos : pos = 1);
            }
        } while (continueDeletion);

    } else {
    	SortByClass(temp);
        DisplayList(temp);
        delList(temp);
		gotoxy(110,1);
		system("Pause");
				
    }
}

void GetFromFile(string filename,ListT &l) {

    ifstream file;
    file.open(filename.c_str(), ios::in);
    if (!file.is_open()) {
        Sleep(50);
        cout << "Error opening file.\n";
        return;
    } else {
        string line;
        while(getline(file, line)) {
            stringstream ss(line);
            string mahs, lop, name, birthday, sex, phone, fathername, fatherphone, mothername, motherphone;
            getline(ss, mahs, ';');
            getline(ss, lop, ';');
            getline(ss, name, ';');
            getline(ss, birthday, ';');
            getline(ss, sex, ';');
            getline(ss, phone, ';');
            getline(ss, fathername, ';');
            getline(ss, fatherphone, ';');
            getline(ss, mothername, ';');
            getline(ss, motherphone, ';');
            addTail(l,mahs,lop,name,birthday,sex,phone,fathername,fatherphone,mothername,motherphone);
        }
    }
}

void WriteAccToFile(ListT &hs){
	ofstream outfile;
	string filename= "HocSinh.txt";
	outfile.open(filename.c_str(), ios::out);
    if (!outfile.is_open()) {
            gotoxy(75,18);
            Sleep(50);
            Color(12);
            cout << "Error opening file.\n";
            return;
        } else {
            NodeT *temp = hs.head;
            while (temp != NULL) {
                outfile << temp->phone << endl;
                temp = temp->next;
            }
        }
        outfile.close();          
}


void WriteToFile(ListT &hs){
    ofstream outfile;
    string filename= "HoSo.txt";
    outfile.open(filename.c_str(), ios::out);
    if (!outfile.is_open()) {
        gotoxy(75,18);
        Sleep(50);
        Color(12);
        cout << "Error opening file.\n";
        return;
    } else {
        NodeT *temp = hs.head;
        while (temp != NULL) {
            outfile << temp->mahs << ";"
                    << temp->lop << ";"
                    << temp->name << ";"
                    << temp->birthday << ";"
                    << temp->sex << ";"
                    << temp->phone << ";"
                    << temp->fathername << ";"
                    << temp->fatherphone << ";"
                    << temp->mothername << ";"
                    << temp->motherphone << endl;
            temp = temp->next;
        }
    }
    outfile.close();  
}

void MakeBorder3(int lenght) {
    Color(9);
    int pos_y = 15;
    for (int i = 13; i <= lenght + pos_y; i++) {
        gotoxy(51, i);
        printf("|");
        gotoxy(60,i);
        printf("|");
        gotoxy(70, i);
        printf("|");
        gotoxy(80, i);
        printf("|");
        gotoxy(90, i);
        printf("|");
}
    for (int i = 52; i < 90; i++) {
        gotoxy(i, 12);
        printf("_");
        gotoxy(i, 14);
        printf("_");
        gotoxy(i, lenght + pos_y);
        printf("_");
    }
    gotoxy(60, 11);
    Color(12);
    cout << "__***Bang Thong Ke***__ ";
    Color(11);
    gotoxy(53,13);
    cout <<"-Lop-";
    gotoxy(63, 13);
    cout << "-Si so-";
    gotoxy(73, 13);
    cout << "-Nam-";
    gotoxy(83,13);
    cout<< "-Nu-";
    Color(15);
}

void ThongKe(ListT &l) {
	    NodeT* current = l.head;
	    map<string, int> classCounts;
	    map<string, int> maleCounts;
	    map<string, int> femaleCounts;
	    int numberOfClasses = 0; // bien dem so luong lop
	    while (current != NULL) {
	        if (classCounts.find(current->lop) == classCounts.end()) {
	            // Neu lop chua co trong map, tang bien dem lop
	            numberOfClasses++;
	        }
	        classCounts[current->lop]++;
	        if (current->sex == "Nam") {
	            maleCounts[current->lop]++;
	        } else if (current->sex == "Nu") {
	            femaleCounts[current->lop]++;
	        }
	        current = current->next;
	    }
	    int pos_y=15;
	    Color(15);
	    system("cls");
	    MakeBorder3(numberOfClasses);
	     for (map<string, int>::const_iterator it = classCounts.begin(); it != classCounts.end(); ++it) {
	    	Color(15);
	         string classKey = it->first; // ley key tu cap key-value
	        gotoxy(55, pos_y);
	        cout << classKey;
	        gotoxy(65,pos_y);
	        cout << it->second;
	        gotoxy(75,pos_y);
	        cout << maleCounts[classKey] ;
	        gotoxy(85,pos_y);
	        cout << femaleCounts[classKey];
	        pos_y+=1;
	    }
	    gotoxy(85,11);
	    system("PAUSE");
	}


void MakeMenuEdit(){
	Color(7);
	gotoxy(71,16);
	cout<<"Lop ";
	gotoxy(71,17);
	cout<<"Ho ten ";
	gotoxy(71,18);
	cout<<"Ngay sinh ";
	gotoxy(71,19);
	cout<<"Gioi tinh ";
	gotoxy(71,20);
	cout<< "So dien thoai ";
	gotoxy(71,21);
	cout<<"Ten bo ";
	gotoxy(71,22);
	cout<<"Sdt bo ";
	gotoxy(71,23);
	cout<<"Ten me ";
	gotoxy(71,24);
	cout<<"Sdt me ";
	gotoxy(71,25);
	cout<<"Xem ket qua va thoat ";
}
void XoaVung() {
	for(int i=68;i<=110;i++) {
		for(int j=13;j<=30;j++){
			gotoxy(i,j);
			cout<<" ";
		}
	}
}
void EditStudent(ListT &l){
	Color(15);
	XoaVung();
	MakeMenuHoSo();
	string mahsEdit;
	Color(15);
	gotoxy(71,16);
	cout<<"Nhap ma hoc sinh can sua:";
	gotoxy(100,16);
	CursorStatus(25, TRUE);
	getline(cin,mahsEdit);
	CursorStatus(25,FALSE);	
	Color(15);
	system("cls");
	MakeMenuHoSo();
        NodeT* p = l.head;
     while (p != NULL) {
        if (p->mahs == mahsEdit) {
            break;
        }
        p = p->next;
    }
    if (p == NULL) {
   	Color(4);
   	gotoxy(71,17);
   	cout<<"Khong tim thay hoc sinh!";
   	int pos = 1;
        bool continueDeletion = true;
        MakeMenuContinue();
        do {
            char choice;
            switch (pos) {
                case 1:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 22);
                    Color(172);
                    cout << "Tiep tuc";
                    char et1;
                    et1 = getch();
                    if (int(et1) == 13) {
                    	Color(15);
                    	delLine(100,17,20);
                    	delLine(70,19,50);
                    	delLine(85,22,12);
                    	delLine(85,23,12);                        
                        EditStudent(l);
                        continueDeletion = false;
                    }
                    break;
                case 2:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 23);
                    Color(172);
                    cout << "Quay lai";
                    char et2;
                    et2 = getch();
                    if (int(et2) == 13) {
                    	Color(15);
                        MainMenuHoSo(l);;
                        return;
                    }
                    Color(15);
                    break;
            }
            if (!continueDeletion) break;
            choice = getch();
            if (choice != 0) {
                if (choice == 72 || choice == 80) pos = (choice == 72 && pos > 0) ? --pos : ((pos < 2) ? ++pos : pos = 1);
            }
        } while (continueDeletion);
    }
	XoaVung();
	EditStudentSection(l,p);
}	

void EditStudentSection(ListT &l, NodeT*p){
	Color(15);
	int pos = 1;
    char choise;
    XoaVung();
    MakeMenuEdit();
    do {
        switch (pos) {
        	case 1:
                MakeMenuEdit();
                gotoxy(71, 16);
                Color(172);
                cout << "Lop ";
                char et;
                et = getch();
                if (int(et) == 13) {
                	Color(15);
                	XoaVung();                	
                	gotoxy(71,16);                	
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	CursorStatus(25,TRUE);
                	getline(cin,p->lop);
                	CursorStatus(25,FALSE);
                	NodeP*t=hs1.head;
                	while (t != NULL) {
        				if (t->mahs == p->mahs) {
						t->lop = p->lop;
						break;
        			}
        			t = t->next;
    				} 
    				WritePointToFile(hs1);  
                	Color(15);
                	EditStudentSection(l,p);
                }               
                break;
            case 2:
                MakeMenuEdit();
                gotoxy(71, 17);
                Color(172);
                cout << "Ho ten ";
                char et1;
                et1 = getch();
                if (int(et1) == 13) {
                	Color(15);
                	XoaVung();
                	gotoxy(71,17);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	CursorStatus(25,TRUE);
                	getline(cin,p->name);
                	CursorStatus(25,FALSE);
                	ChuanHoa(&p->name);
                	NodeP*t=hs1.head;
                	while (t != NULL) {
        				if (t->mahs == p->mahs) {
						t->name = p->name;
						break;
        			}
        			t = t->next;
    				} 
    				WritePointToFile(hs1);  
                	Color(15);
                	EditStudentSection(l,p);
                }
                break;
            case 3: 
                MakeMenuEdit();
                gotoxy(71, 18);
                Color(172);
                cout << "Ngay sinh ";
                char et2;
                et2 = getch();
                if (int(et2) == 13) {
                	Color(15);
                    XoaVung();
                	gotoxy(71,18);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	CursorStatus(25,TRUE);
                	getline(cin,p->birthday);
                	CursorStatus(25,FALSE);
                	Color(15);
                	EditStudentSection(l,p);
                }               
                break;
            case 4:
                MakeMenuEdit();
                gotoxy(71, 19);
                Color(172);
                cout << "Gioi tinh ";
                char et3;
                et3 = getch();
                if (int(et3) == 13) {
                	Color(15);
                	string sex;
                    XoaVung();
                	gotoxy(71,19);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	CursorStatus(25,TRUE);
                	getline(cin,sex);
                	ChuanHoa(&sex);
                	p->sex=sex;
                	CursorStatus(25,FALSE);
                	Color(15);
                	EditStudentSection(l,p);
                }               
                break;
            case 5: 
                MakeMenuEdit();
                gotoxy(71, 20);
                Color(172);
                cout << "So dien thoai ";
                char et4;
                et4 = getch();
                if (int(et4) == 13) {
                	Color(15);
                    XoaVung();
                	gotoxy(71,20);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	gotoxy(90,20);
                	CursorStatus(25,TRUE);
                	while (true) {
            fflush(stdin);
            getline(cin, p->phone);
            if (isPhoneNumberValid(p->phone)) {
            	string filename2="HocSinh.txt";
            	DeleteInFile(filename2);
                WriteAccToFile(l);
                break; // thoat neu sdt hop le
            } else {
            	gotoxy(90,20);
            	Color(4);
                cout << "Sdt khong hop le!";
                Sleep(200);
                Color(15);
                delLine(90,20,30); // xoa sdt cu
            }
        }
        CursorStatus(25,FALSE);
                	
                	Color(15);
                	NodeP*t=hs1.head;
                	while (t != NULL) {
        				if (t->mahs == p->mahs) {
						t->phone = p->phone;
						break;
        			}
        			t = t->next;
    				} 
    				WritePointToFile(hs1);    				
                	EditStudentSection(l,p);
                }                
                break;
            case 6:
                MakeMenuEdit();
                gotoxy(71, 21);
                Color(172);
                cout << "Ten bo ";
                char et5;
                et5 = getch();
                if (int(et5) == 13) {
                	Color(15);
                   	XoaVung();
                	gotoxy(71,21);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	CursorStatus(25,TRUE);
                	getline(cin,p->fathername);
                	CursorStatus(25,FALSE);
                	fflush(stdin);
                	ChuanHoa(&p->fathername);
                	Color(15);
                	EditStudentSection(l,p);               	
                }
                break;
            case 7:
                MakeMenuEdit();
                gotoxy(71, 22);
                Color(172);
                cout << "Sdt bo ";
                char et6;
                et6 = getch();
                if (int(et6) == 13) {
                	Color(15);
                    XoaVung();
                	gotoxy(71,22);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	CursorStatus(25,TRUE);
                	getline(cin,p->fatherphone);
                	CursorStatus(25,FALSE);
                	Color(15);
                	EditStudentSection(l,p);
                }
                break;
            case 8:
                MakeMenuEdit();
                gotoxy(71, 23);
                Color(172);
                cout << "Ten me ";
                char et7;
                et7 = getch();
                if (int(et7) == 13) {
                	Color(15);
                    XoaVung();
                	gotoxy(71,23);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	CursorStatus(25,TRUE);
                	getline(cin,p->mothername);
                	CursorStatus(25,FALSE);
                	ChuanHoa(&p->mothername);
                	Color(15);
                	EditStudentSection(l,p);
                }
                break;
            case 9:
                MakeMenuEdit();
                gotoxy(71, 24);
                Color(172);
                cout << "Sdt me ";
                char et8;
                et8 = getch();
                if (int(et8) == 13) {
                	Color(15);
                    XoaVung();
                	gotoxy(71,24);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	CursorStatus(25,TRUE);
                	getline(cin,p->motherphone);
                	CursorStatus(25,FALSE);
                	Color(15);
                	EditStudentSection(l,p);
                }
                break;
            case 10: 
				MakeMenuEdit();
                gotoxy(71, 25);
                Color(172);
                cout << "Xem ket qua va thoat ";
                char et9;
                et9 = getch();
                if (int(et9) == 13) {                    
                    Color(15);
                    ListT temp3;
                    Init(temp3);
                    NodeT *temp31 = new NodeT;
                    copyNode(p,temp31);
                    addHead(temp3,temp31);
                    WriteToFile(l);
                	gotoxy(76,20);
                	Sleep(300);
                	cout<<"Danh sach sau khi sua!";
                	DisplayList(temp3);
              	    delList(temp3);         	
                	MainMenuHoSo(l);; 
                }

            default: break;

        }

        choise = getch();
        if (choise == 72 || choise == 80) pos = (choise == 72 && pos > 0) ? --pos : ((pos < 10) ? ++pos : pos = 1);

    } while (choise != 8);
}

void MakeMenuDiem() {
	Color(15);	
    gotoxy(46, 12);
    cout << "**Menu**" ;
    gotoxy(42, 15);
    cout << "Nhap diem ";
    gotoxy(42, 16);
    cout << "Xoa diem ";
    gotoxy(42,17);
    cout<< "Sua diem ";
    gotoxy(42, 18);
    cout << "In bang diem ";
    gotoxy(42, 19);
    cout << "Tim kiem hoc sinh ";
    gotoxy(42,20);
    cout<< "Thong Ke ";
    gotoxy(42,21);
    cout<< "Back ";
    MakeBorder();
}

void MainMenuDiem(ListP &l){	
	string filename="Diem.txt";
	CursorStatus(25, FALSE);
    fflush(stdin);
    system("cls");
    int pos = 1;
    MakeMenuDiem();
    do {
        char choise;
        switch (pos) {
            case 1:Color(15);
                //system("cls");
                MakeMenuDiem();
                gotoxy(42, 15);
                Color(172);
                cout << "Nhap diem ";
                char et1;
                et1 = getch();
				if (int(et1) == 13) {
					FileAddPoint(l);
					WritePointToFile(l);
					Color(4);
					gotoxy(72,28);
					cout<<"Da them vao file!"	;
					Sleep(500); 
					MainMenuDiem(l);	
				}
                Color(15);
                break;
            case 2:Color(15);                
                MakeMenuDiem();
                gotoxy(42, 16);
                Color(172);
                cout << "Xoa diem ";
                char et2;
                et2 = getch();
                if(int(et2)==13) {
                	Color(15);
                	gotoxy(72,16);
    				cout << "Xem danh sach de xoa!";
    				gotoxy(72,18);
    				system("PAUSE");
    				SortByClass(l);
    				DisplayPoint(l);
                	DeletePoint(l);
                	DeleteInFile(filename);
					WritePointToFile(l);
					MainMenuDiem(l);
				}
                Color(15);
                break; 
            case 3:Color(15);                
                MakeMenuDiem();
                gotoxy(42, 17);
                Color(172);
                cout << "Sua diem ";
                char et0;
                et0 = getch();
                if(int(et0)==13) {
                	Color(15);
                	gotoxy(72,16);
    				cout << "Xem danh sach de sua!";
    				gotoxy(72,18);
    				system("PAUSE");
    				SortByClass(l);
    				DisplayPoint(l);
					EditPoint(l);                	
				}
                Color(15);
                break;
            case 4:Color(15);                
                MakeMenuDiem();
                gotoxy(42, 18);
                Color(172);
                cout << "In bang diem ";
                char et3;
                et3 = getch();
                if(int(et3)==13) {
				    BangDiem(l);
					MainMenuDiem(l);              	
				}
                Color(15);
                break; 
            case 5:Color(15);                
                MakeMenuDiem();
                gotoxy(42, 19);
                Color(172);
                cout << "Tim kiem hoc sinh ";
                char et4;
                et4 = getch();
                if(int(et4)==13) {
                	SearchStudent(l);
                	MainMenuDiem(l);
				}
                Color(15);
                break;
			case 6:Color(15);                
                MakeMenuDiem();
                gotoxy(42, 20);
                Color(172);
                cout << "Thong Ke ";
                char et5;
                et5 = getch();
                if(int(et5)==13) {
                	ThongKeDiem(l);
                	MainMenuDiem(l);
				}
                Color(15);
                break;  
			case 7: Color(15);
			    MakeMenuDiem();
				gotoxy(42,21);
				Color(172);
				cout<< "Back ";
				char et6;
				et6=getch();
				if(int(et6)==13) {
					Color(15);
					MainMenuTeacher();
				Color(15);
				break;
		}
        }
        choise = getch();
        if (choise != 0) {

            if (choise == 72 || choise == 80) pos = (choise == 72 && pos > 0) ? --pos : ((pos < 7) ? ++pos : pos = 1);
        }

    } while (1);
}

NodeT* GetStudentInfo(ListT &list, const string& mahs) {
    NodeT* current = list.head;
    while (current != NULL) {
        if (current->mahs == mahs) {
            return current; // tra ve node chua thong tin hoc sinh neu tim thay
        }
        current = current->next;
    }
    return NULL; // tra ve null neu khong tim thay hs voi ma hs do
}
bool IsScoreEntered(ListP &list, const string& mahs) {
    NodeP* current = list.head;
    while (current != NULL) {
        if (current->mahs == mahs) {
            return true; // tra ve true neu tim thay node voi ma hs khop
        }
        current = current->next;
    }
    return false; // tra ve false neu khong tim thay node nao co ma hs khop
}
void FileAddPoint(ListP &l){
	Color(15);
	XoaVung();
	int k,n;
	string lop;
	string name;
	string mahs;
	string phone;
	ListT temp;
	Init(temp);
	GetFromFile("HoSo.txt", temp);
	ListP temp1;
	Init2(temp1);
	GetFromFile2("Diem.txt", temp1);
	float toan;
	float li;
	float hoa;
	float sinh;
	float van;
	float su;
	float dia;
	float english;
	float dtb;
	Color(15);	
    gotoxy(72,17);
    cout<<"Nhap so hoc sinh them vao:";
    do {
    	Color(15);
    	gotoxy(100,17);
    	delLine(100,17,5);
    	CursorStatus(25,TRUE);
    	fflush(stdin);
    	cin>>n;
    	CursorStatus(25,FALSE);
    if (cin.fail() || n <= 0) {
		Color(4);
		gotoxy(73,18) ;		
        cout << "Khong hop le. Vui long nhap lai";     
		cout.flush();   
        Sleep(300);
        cin.clear();
        delLine(73,18,40);
    } else {
        break; // thoat neu nhap dung
    }
} while (true);   
    for(int i=1;i<=n;i++) {
    	Color(15);
    	XoaManHinh();
    	delLine(30,5,50);
    	delLine(30,7,50);
    	gotoxy(80,13);
    	cout<<"Hoc sinh thu:"<<i;
    	NodeT* studentInfo = NULL;
    	do {
    		Color(15);
    	gotoxy(71,16);
    	cout<<"Nhap ma hoc sinh:";
    	delLine(90,16,10);
    	gotoxy(90,16);    	
    	CursorStatus(25,TRUE);
    	cin>> mahs;
    	CursorStatus(25,FALSE);
    	studentInfo = GetStudentInfo(temp, mahs);
        if (studentInfo == NULL) {
        	gotoxy(71,17);
        	Color(4);
            cout << "Hoc sinh khong ton tai. Vui long nhap lai.";       
			Sleep(300);
			delLine(71,17,42); 
			Color(4);
        int pos = 1;
        bool continueDeletion = true;
        MakeMenuContinue();
        do {
            char choice;
            switch (pos) {
                case 1:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 22);
                    Color(172);
                    cout << "Tiep tuc";
                    char et1;
                    et1 = getch();
                    if (int(et1) == 13) {
                    	Color(15);
                    	delLine(100,17,20);
                    	delLine(70,19,50);
                    	delLine(85,22,12);
                    	delLine(85,23,12);                        
                        FileAddPoint(l);
                        continueDeletion = false;
                    }
                    break;
                case 2:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 23);
                    Color(172);
                    cout << "Quay lai";
                    char et2;
                    et2 = getch();
                    if (int(et2) == 13) {
                    	Color(15);
                        MainMenuDiem(l);;
                        return;
                    }
                    Color(15);
                    break;
            }
            if (!continueDeletion) break;
            choice = getch();
            if (choice != 0) {
                if (choice == 72 || choice == 80) pos = (choice == 72 && pos > 0) ? --pos : ((pos < 2) ? ++pos : pos = 1);
            }
        } while (continueDeletion);    
        }else  if(IsScoreEntered(temp1, mahs)) {
          	gotoxy(71,17);
        	Color(4);
            cout << "Hoc sinh da duoc nhap diem. Vui long nhap lai.";       
			Sleep(300);
			delLine(71,17,45);  
			Color(4);
        int pos = 1;
        bool continueDeletion = true;
        MakeMenuContinue();
        do {
            char choice;
            switch (pos) {
                case 1:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 22);
                    Color(172);
                    cout << "Tiep tuc";
                    char et1;
                    et1 = getch();
                    if (int(et1) == 13) {
                    	Color(15);
                    	delLine(100,17,20);
                    	delLine(70,19,50);
                    	delLine(85,22,12);
                    	delLine(85,23,12);                        
                        FileAddPoint(l);
                        continueDeletion = false;
                    }
                    break;
                case 2:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 23);
                    Color(172);
                    cout << "Quay lai";
                    char et2;
                    et2 = getch();
                    if (int(et2) == 13) {
                    	Color(15);
                        MainMenuDiem(l);;
                        return;
                    }
                    Color(15);
                    break;
            }
            if (!continueDeletion) break;
            choice = getch();
            if (choice != 0) {
                if (choice == 72 || choice == 80) pos = (choice == 72 && pos > 0) ? --pos : ((pos < 2) ? ++pos : pos = 1);
            }
        } while (continueDeletion);
		  }  
		 else {
        	break;
		}
}while(true);
		name = studentInfo->name;
        phone = studentInfo->phone;
        lop= studentInfo->lop;
        Color(15);
		gotoxy(71,18);
    	cout<<"Diem toan:";
    	while (true) {
            gotoxy(90, 18);
            CursorStatus(25, TRUE);
            fflush(stdin);
            cin >> toan;
            CursorStatus(25, FALSE);
            if (CheckPoint(toan)) break;
            else {
                gotoxy(90, 19);
                Color(4);
                cout << "Diem khong hop le!";
                Sleep(200);
                cin.clear();
                Color(15);
                delLine(90, 18, 10);
                delLine(90,19,30);
            }
        }
    	gotoxy(71,19);
    	cout<<"Diem li:";
        while (true) {
            gotoxy(90, 19);
            CursorStatus(25, TRUE);
            fflush(stdin);
            cin >> li;
            CursorStatus(25, FALSE);
            if (CheckPoint(li)) break;
            else {
                gotoxy(90, 20);
                Color(4);
                cout << "Diem khong hop le!";
                Sleep(200);
                cin.clear();
                Color(15);
                delLine(90, 19, 10);
                delLine(90,20,30);
            }
        }

        gotoxy(71, 20);
        cout << "Diem hoa:";
        while (true) {
            gotoxy(90, 20);
            CursorStatus(25, TRUE);
            fflush(stdin);
            cin >> hoa;
            CursorStatus(25, FALSE);
            if (CheckPoint(hoa)) break;
            else {
                gotoxy(90, 21);
                Color(4);
                cout << "Diem khong hop le!";
                Sleep(200);
                cin.clear();
                Color(15);
                delLine(90, 20, 10);
                delLine(90,21,30);
            }
        }

        gotoxy(71, 21);
        cout << "Diem sinh:";
        while (true) {
            gotoxy(90, 21);
            CursorStatus(25, TRUE);
            fflush(stdin);
            cin >> sinh;
            CursorStatus(25, FALSE);
            if (CheckPoint(sinh)) break;
            else {
                gotoxy(90, 22);
                Color(4);
                cout << "Diem khong hop le!";
                Sleep(200);
                cin.clear();
                Color(15);
                delLine(90, 21, 10);
                delLine(90,22,30);
            }
        }
    
        gotoxy(71, 22);
        cout << "Diem Van:";
        while (true) {
            gotoxy(90, 22);
            CursorStatus(25, TRUE);
            fflush(stdin);
            cin >> van;
            CursorStatus(25, FALSE);
            if (CheckPoint(van)) break;
            else {
                gotoxy(90, 23);
                Color(4);
                cout << "Diem khong hop le!";
                Sleep(200);
                cin.clear();
                Color(15);
                delLine(90, 22, 10);
                delLine(90,23,30);
            }
        }
    
        gotoxy(71, 23);
        cout << "Diem su:";
        while (true) {
            gotoxy(90, 23);
            CursorStatus(25, TRUE);
            fflush(stdin);
            cin >> su;
            CursorStatus(25, FALSE);
            if (CheckPoint(su)) break;
            else {
                gotoxy(90, 24);
                Color(4);
                cout << "Diem khong hop le!";
                Sleep(200);
                cin.clear();
                Color(15);
                delLine(90, 23, 10);
                delLine(90,24,30);
            }
        }

    
        gotoxy(71, 24);
        cout << "Diem dia:";
        while (true) {
            gotoxy(90, 24);
            CursorStatus(25, TRUE);
            fflush(stdin);
            cin >> dia;
            CursorStatus(25, FALSE);
            if (CheckPoint(dia)) break;
            else {
                gotoxy(90, 25);
                Color(4);
                cout << "Diem khong hop le!";
                Sleep(200);
                cin.clear();
                Color(15);
                delLine(90, 24, 10);
                delLine(90,25,30);
            }
        }


        gotoxy(71, 25);
        cout << "Diem tieng anh:";
        while (true) {
            gotoxy(90, 25);
            CursorStatus(25, TRUE);
            fflush(stdin);
            cin >> english;
            CursorStatus(25, FALSE);
            if (CheckPoint(english)) break;
            else {
                gotoxy(90, 26);
                Color(4);
                cout << "Diem khong hop le!";
                Sleep(200);
                cin.clear();
                Color(15);
                delLine(90, 25, 10);
                delLine(90,26,30);
            }
        }
    	dtb=DiemTrungBinh(toan,li,hoa,sinh,van,su,dia,english);
    	addTail2(l,mahs,lop,name,phone,toan,li,hoa,sinh,van,su,dia,english,dtb);  
		}
	delList(temp); delList(temp1);
	}

void WritePointToFile(ListP &hs){
    ofstream outfile;
    string filename= "Diem.txt";
    outfile.open(filename.c_str(), ios::out);
    if (!outfile.is_open()) {
        gotoxy(75,18);
        Sleep(50);
        Color(12);
        cout << "Error opening file.\n";
        return;
    } else {
        NodeP *temp = hs.head;
        while (temp != NULL) {
            outfile << fixed << setprecision(2);
            outfile << temp->mahs << ";";
            outfile  << temp->lop << ";";
            outfile  << temp->name << ";";
            outfile        << temp->phone << ";";
        	outfile        << temp->toan << ";";
            outfile        << temp->li << ";";
            outfile        << temp->hoa << ";";
            outfile        << temp->sinh << ";";
            outfile        << temp->van << ";";
            outfile        << temp->su << ";";
            outfile        << temp->dia << ";";
            outfile        << temp->english << ";";
            outfile        << temp->dtb << endl;
            temp = temp->next;
        }
    }
    outfile.close(); 
}

void GetFromFile2(string filename, ListP &l) {
    ifstream file;
    file.open(filename.c_str(), ios::in);
    if (!file.is_open()) {
        Sleep(50);
        cout << "Error opening file.\n";
        return;
    } else {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string mahs, lop, name, phone;
            float toan, li, hoa, sinh, van, su, dia, english, dtb;

            getline(ss, mahs, ';');
            getline(ss, lop, ';');
            getline(ss, name, ';');
            getline(ss, phone, ';');
            ss >> toan;
            ss.ignore(1, ';');
            ss >> li;
            ss.ignore(1, ';');
            ss >> hoa;
            ss.ignore(1, ';');
            ss >> sinh;
            ss.ignore(1, ';');
            ss >> van;
            ss.ignore(1, ';');
            ss >> su;
            ss.ignore(1, ';');
            ss >> dia;
            ss.ignore(1, ';');
            ss >> english;
            ss.ignore(1, ';');
            ss >> dtb;

            addTail2(l, mahs,lop,name,phone, toan, li, hoa, sinh, van, su, dia, english, dtb);
        }
    }
    file.close(); 
}


void MakeBorder4(int lenght) {
    Color(9);
    int pos_y = 6;
    for (int i = 2; i <= lenght + pos_y; i++) {
        gotoxy(1, i);
        printf("|");
        gotoxy(10,i);
        printf("|");
        gotoxy(16, i);
        printf("|");
        gotoxy(42, i);
        printf("|");
        gotoxy(52, i);
        printf("|");
        gotoxy(62, i);
        printf("|");
        gotoxy(72, i);
        printf("|");
        gotoxy(82, i);
        printf("|");
        gotoxy(92, i);
        printf("|");
        gotoxy(102, i);
        printf("|");
        gotoxy(110, i);
        printf("|");
        gotoxy(120, i);
        printf("|");
        gotoxy(140, i);
        printf("|");
    }

    for (int i = 2; i < 140; i++) {
        gotoxy(i, 2);
        printf("_");
        gotoxy(i, 4);
        printf("_");
        gotoxy(i, lenght + pos_y);
        printf("_");
    }
    gotoxy(30, 1);
    Color(12);
    cout << "__***In Bang diem***__ ";
    Color(11);
    gotoxy(2,3);
    cout <<"-Ma hs-";
    gotoxy(11,3);
    cout <<"-Lop-";
    gotoxy(25, 3);
    cout << "-Name-";
    gotoxy(46, 3);
    cout << "Toan";
    gotoxy(57,3);
    cout<< "Li";
    gotoxy(67, 3);
    cout << "Hoa";
    gotoxy(77, 3);
    cout << "Sinh";
    gotoxy(87, 3);
    cout << "Van";
    gotoxy(97, 3);
    cout << "Su";
    gotoxy(105, 3);
    cout << "Dia";
    gotoxy(111, 3);
    cout << "Tieng anh";
    gotoxy(123, 3);
    cout << "Diem trung binh";
    gotoxy(2, 5);
    Color(15);
}
void MakeMenuIn2() {
	Color(15);
	gotoxy(71,15);
	cout<< "In danh sach duoc sap xep theo?";
	gotoxy(71,16);
	cout<<"Ten ";
	gotoxy(71,17);
	cout<<"Lop ";
	gotoxy(71,18);
	cout<< "Diem trung binh ";
}
void BangDiem(ListP &l){
	Color(15);
	system("cls");
	MakeMenuDiem();
	int pos = 1;
    char choise;
    MakeMenuIn2();
    do {
        switch (pos) {
        	case 1:
                MakeMenuIn2();
                gotoxy(71, 16);
                Color(172);
                cout << "Ten ";
                char et;
                et = getch();
                if (int(et) == 13) {
                	Color(15);
                	SortByName(l);
                	DisplayPoint(l);
                	MainMenuDiem(l);
                }               
                break;
            case 2:
                MakeMenuIn2();
                gotoxy(71, 17);
                Color(172);
                cout << "Lop ";
                char et1;
                et1 = getch();
                if (int(et1) == 13) {
                	Color(15);
                	SortByClass(l);
                	DisplayPoint(l);
                	MainMenuDiem(l);
                }
                break;
            case 3:
                MakeMenuIn2();
                gotoxy(71, 18);
                Color(172);
                cout << "Diem trung binh ";
                char et2;
                et2 = getch();
                if (int(et2) == 13) {
                	Color(15);
                	SortByScore(l);
                	DisplayPoint(l);
                	MainMenuDiem(l);
                }
                break;
    }
    
        choise = getch();
        if (choise == 72 || choise == 80) pos = (choise == 72 && pos > 0) ? --pos : ((pos < 3) ? ++pos : pos = 1);

    } while (choise != 8);
}	

void DisplayPoint(ListP &l) { 
	NodeP* temp = l.head;
    int pos_y=6;
    Color(15);
    system("cls");
    MakeBorder4(lenghtNode2(l));
    while (temp != NULL) {
    gotoxy(3,pos_y);
    cout << temp->mahs;
    gotoxy(12,pos_y);
    cout << temp->lop;
    gotoxy(17, pos_y);
    cout << temp->name;
    gotoxy(45, pos_y);
    cout << temp->toan;
    gotoxy(55,pos_y);
    cout<<temp->li;
    gotoxy(65, pos_y);			
    cout << temp->hoa;
    gotoxy(75, pos_y);
    cout << temp->sinh;
    gotoxy(85, pos_y);
    cout << temp->van;
    gotoxy(95, pos_y);
    cout << temp->su;
    gotoxy(105, pos_y );
    cout << temp->dia;
    gotoxy(115, pos_y );
    cout << temp->english;
    gotoxy(130, pos_y );
    cout << temp->dtb;
    pos_y += 1;
    temp = temp->next;
	}
	gotoxy(110,1);
	system("PAUSE");
}

void DeletePoint(ListP &l) {
	system("cls");
	MakeMenuDiem();
    string keyMahs;
    Color(15);
    gotoxy(72, 17);
    cout << "Nhap ma hoc sinh can xoa: ";
    gotoxy(100, 17);
    CursorStatus(25, TRUE);
    cin>>keyMahs;
    CursorStatus(25, FALSE);
	NodeP *p = l.head; // 
    NodeP *prev = NULL;
    bool isDeleted = false;
    while (p != NULL) {
        if (p->mahs == keyMahs) {
            if (p == l.head) {
                l.head = p->next;
                if (l.head == NULL) {  // Neu danh sach chi co 1 node
                    l.tail = NULL;
                }
            } else {
                prev->next = p->next;
                if (p->next == NULL) {  // Neu node xoa la cuoi cung
                    l.tail = prev;
                }
            }
            delete p;
            isDeleted = true;
            break;
        }
        prev = p;
        p = p->next;
    }
    if (!isDeleted) {
        Color(4);
        gotoxy(75, 19);
        cout << "Khong tim thay hoc sinh do!";
        int pos = 1;
        bool continueDeletion = true;
        MakeMenuContinue();
        do {
            char choice;
            switch (pos) {
                case 1:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 22);
                    Color(172);
                    cout << "Tiep tuc";
                    char et1;
                    et1 = getch();
                    if (int(et1) == 13) {
                    	Color(15);
                    	delLine(100,17,20);
                    	delLine(70,19,50);
                    	delLine(85,22,12);
                    	delLine(85,23,12);                        
                        DeletePoint(l);
                        continueDeletion = false;
                    }
                    break;
                case 2:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 23);
                    Color(172);
                    cout << "Quay lai";
                    char et2;
                    et2 = getch();
                    if (int(et2) == 13) {
                    	Color(15);
                        MainMenuDiem(l);
                        return;
                    }
                    Color(15);
                    break;
            }
            if (!continueDeletion) break;
            choice = getch();
            if (choice != 0) {
                if (choice == 72 || choice == 80) pos = (choice == 72 && pos > 0) ? --pos : ((pos < 2) ? ++pos : pos = 1);
            }
        } while (continueDeletion);
    }
    else {
    	gotoxy(72,20);
    	cout<<"Da xoa! Xem danh sach sau khi xoa.";
    	gotoxy(72,22);
    	system("PAUSE");
    	SortByClass(l);
        DisplayPoint(l);
        gotoxy(110, 1);
        system("PAUSE");
    }
}
void SearchStudent(ListP &l) { 
    string key;
    Color(15);
    gotoxy(72, 17);
    cout << "Nhap noi dung can tim: ";
    gotoxy(100, 17);
    CursorStatus(25, TRUE);
    fflush(stdin);
    getline(cin, key);
    CursorStatus(25, FALSE);
   	ListP temp;
   	Init2(temp);
   	NodeP *p =l.head;
   	while (p != NULL) {
        if (search(p, key) != NULL) {
		NodeP*q = new NodeP;      
        copyNode2(p, q);
        addHead2(temp, q);
        }
        p = p->next;
        }
    if (isEmpty2(temp)) { // Neu danh sach rong
        Color(4);
        gotoxy(75, 19);
        cout << "Khong tim thay!";
        int pos = 1;
        bool continueDeletion = true;
        MakeMenuContinue();
        do {
            char choice;
            switch (pos) {
                case 1:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 22);
                    Color(172);
                    cout << "Tiep tuc";
                    char et1;
                    et1 = getch();
                    if (int(et1) == 13) {
                    	Color(15);
                    	delLine(100,17,20);
                    	delLine(70,19,50);
                    	delLine(85,22,12);
                    	delLine(85,23,12);                        
                        SearchStudent(l);
                        continueDeletion = false;
                    }
                    break;
                case 2:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 23);
                    Color(172);
                    cout << "Quay lai";
                    char et2;
                    et2 = getch();
                    if (int(et2) == 13) {
                    	Color(15);
                        MainMenuDiem(l);;
                        return;
                    }
                    Color(15);
                    break;
            }
            if (!continueDeletion) break;
            choice = getch();
            if (choice != 0) {
                if (choice == 72 || choice == 80) pos = (choice == 72 && pos > 0) ? --pos : ((pos < 2) ? ++pos : pos = 1);
            }
        } while (continueDeletion);

    } else {
    	SortByClass(temp);
        DisplayPoint(temp);
        delList(temp);
		gotoxy(110,1);
		system("Pause");
				
    }
}

void MakeBorder5(int lenght) {
    Color(9);
    int pos_y = 15;
    for (int i = 12; i <= lenght + pos_y; i++) {
        gotoxy(51, i);
        printf("|");
        gotoxy(60,i);
        printf("|");
        gotoxy(70, i);
        printf("|");
        gotoxy(80, i);
        printf("|");
        gotoxy(93, i);
        printf("|");
        gotoxy(103,i);
        printf("|");
}
    for (int i = 52; i < 103; i++) {
        gotoxy(i, 12);
        printf("_");
        gotoxy(i, 14);
        printf("_");
        gotoxy(i, lenght + pos_y);
        printf("_");
    }
    gotoxy(60, 11);
    Color(12);
    cout << "__***Bang Thong Ke***__ ";
    Color(11);
    gotoxy(53,13);
    cout <<"-Lop-";
    gotoxy(63, 13);
    cout << "-Gioi-";
    gotoxy(73, 13);
    cout << "-Kha-";
    gotoxy(81,13);
    cout<< "-Trung binh-";
    gotoxy(96,13);
    cout<< "-Yeu-";
    Color(15);
}

void ThongKeDiem(ListP &list) {
	NodeP* current = list.head;
    map<string, int> gioiCounts;
    map<string, int> khaCounts;
    map<string, int> tbCounts;
    map<string, int> yeuCounts;
    map<string, int> classCounts; // dem so hs moi lop
    int numberOfClasses = 0; // dem so luong lop

    while (current != NULL) {
        if (classCounts.find(current->lop) == classCounts.end()) {
            numberOfClasses++; // tang so lop neu lop chua duoc dem
        }
        classCounts[current->lop]++; // dem so hs moi lop

        if (current->dtb >= 8.0) {
            gioiCounts[current->lop]++;
        } else if (current->dtb >= 6.5) {
            khaCounts[current->lop]++;
        } else if (current->dtb >= 5.0) {
            tbCounts[current->lop]++;
        } else {
            yeuCounts[current->lop]++;
        }
        current = current->next;
    }

	int pos_y=15;
	Color(15);
	system("cls");
	MakeBorder5(numberOfClasses);
	for (map<string, int>::const_iterator it = classCounts.begin(); it != classCounts.end(); ++it) {
	   	Color(15);
	    string classKey = it->first;
		gotoxy(55,pos_y);
		cout<<classKey;
	    gotoxy(65, pos_y);
        cout << gioiCounts[classKey];
        gotoxy(75,pos_y);
        cout << khaCounts[classKey];
        gotoxy(85,pos_y);
        cout << tbCounts[classKey] ;
        gotoxy(97,pos_y);
		cout << yeuCounts[classKey];
		pos_y+=1;
	}
	gotoxy(85,11);
	system("PAUSE");
}

string phonetoPlay;
void StudentLogin() {
    bool loginSuccess = false;
    
    while (!loginSuccess) {
    	Color(15);
        //xoa cac dong truoc do
        delLine(70, 15, 30);
        delLine(70, 17, 30);
        delLine(75, 19, 30);

        // yeu cau nhap sdt 
        gotoxy(70, 15);
        cout << "Phone Number:";
        gotoxy(85, 15);
        CursorStatus(25, TRUE);
        fflush(stdin);
        cin >> phonetoPlay;
        CursorStatus(25, FALSE);

        // check sdt
        if (CheckAcc2(phonetoPlay)) {
            loginSuccess = true;
        } else {
            gotoxy(75, 19);
            cout << "So dien thoai chua dang ki!";
            Sleep(300);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // goi ham MainMenuStudent sau khi dang nhap thanh cong
    MainMenuStudent();
}
void MakeMenuEdit2(){
	Color(7);
	gotoxy(71,17);
	cout<<"Toan ";
	gotoxy(71,18);
	cout<<"Li ";
	gotoxy(71,19);
	cout<<"Hoa ";
	gotoxy(71,20);
	cout<<"Sinh ";
	gotoxy(71,21);
	cout<<"Van ";
	gotoxy(71,22);
	cout<<"Su ";
	gotoxy(71,23);
	cout<<"Dia ";
	gotoxy(71,24);
	cout<<"Tieng anh ";
	gotoxy(71,25);
	cout<<"Xem ket qua va thoat ";
}

void EditPoint(ListP &l){
	Color(15);
	system("cls");
					MakeMenuDiem();
					string mahsEdit;
					Color(15);
					gotoxy(71,16);
					cout<<"Nhap ma hoc sinh can sua:";
					gotoxy(100,16);
					CursorStatus(25, TRUE);
					cin>>mahsEdit;
					CursorStatus(25,FALSE);
	Color(15);
	system("cls");
	MakeMenuDiem();
        NodeP* p = l.head;
     while (p != NULL) {
        if (p->mahs == mahsEdit) { // tim hs dua tren ma hs
            break;
        }
        p = p->next;
    }
   if (p == NULL) {
   	Color(4);
   	gotoxy(71,17);
   	cout<<"Khong tim thay hoc sinh!";
   		int pos = 1;
        bool continueDeletion = true;
        MakeMenuContinue();
        do {
            char choice;
            switch (pos) {
                case 1:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 22);
                    Color(172);
                    cout << "Tiep tuc";
                    char et1;
                    et1 = getch();
                    if (int(et1) == 13) {
                    	Color(15);
                    	delLine(100,17,20);
                    	delLine(70,19,50);
                    	delLine(85,22,12);
                    	delLine(85,23,12);                        
                        EditPoint(l);
                        continueDeletion = false;
                    }
                    break;
                case 2:
                    Color(1);
                    MakeMenuContinue();
                    gotoxy(85, 23);
                    Color(172);
                    cout << "Quay lai";
                    char et2;
                    et2 = getch();
                    if (int(et2) == 13) {
                    	Color(15);
                        MainMenuDiem(l);
                        return;
                    }
                    Color(15);
                    break;
            }
            if (!continueDeletion) break;
            choice = getch();
            if (choice != 0) {
                if (choice == 72 || choice == 80) pos = (choice == 72 && pos > 0) ? --pos : ((pos < 2) ? ++pos : pos = 1);
            }
        } while (continueDeletion);
    }
	XoaVung();
	EditPointSection(l,p);
}	
      
void EditPointSection(ListP &l, NodeP*p){
	Color(15);
	XoaVung();
	int pos = 1;
    char choise;
    MakeMenuEdit2();
    do {
        switch (pos) {
            case 1:
                MakeMenuEdit2();
                gotoxy(71, 17);
                Color(172);
                cout << "Toan ";
                char et1;
                et1 = getch();
                if (int(et1) == 13) {
                	Color(15);
                	XoaVung();
                	gotoxy(71,17);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	gotoxy(90,17);
            		CursorStatus(25, TRUE);
                	while (true) {
            			fflush(stdin);
            			cin >> p->toan;
            			if (CheckPoint(p->toan)) {
				break;	
			}
            else {
                gotoxy(90, 17);
                Color(4);
                cout << "Diem khong hop le!";
               	Sleep(200);
                cin.clear();
                Color(15);
                delLine(90,17,30);
            }
        }
        CursorStatus(25, FALSE);
                	p->dtb=DiemTrungBinh(p->toan,p->li,p->hoa,p->sinh,p->van,p->su,p->dia,p->english);
                	Color(15);
                	EditPointSection(l,p);
                }
                break;
            case 2: 
                MakeMenuEdit2();
                gotoxy(71, 18);
                Color(172);
                cout << "Li ";
                char et2;
                et2 = getch();
                if (int(et2) == 13) {
                	Color(15);
                    XoaVung();
                	gotoxy(71,17);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	gotoxy(90,17);
            		CursorStatus(25, TRUE);
                	while (true) {
            			fflush(stdin);
            			cin >> p->li;
            			if (CheckPoint(p->li)) {
				break;	
			}
            else {
                gotoxy(90, 17);
                Color(4);
                cout << "Diem khong hop le!";
               	Sleep(200);
                cin.clear();
                Color(15);
                delLine(90,17,30);
            }
        }
        CursorStatus(25, FALSE);
                	p->dtb=DiemTrungBinh(p->toan,p->li,p->hoa,p->sinh,p->van,p->su,p->dia,p->english);
                	Color(15);
                	EditPointSection(l,p);
                }               
                break;
            case 3:
                MakeMenuEdit2();
                gotoxy(71, 19);
                Color(172);
                cout << "Hoa ";
                char et3;
                et3 = getch();
                if (int(et3) == 13) {
                	Color(15);
                    XoaVung();
                	gotoxy(71,17);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	gotoxy(90,17);
            		CursorStatus(25, TRUE);
                	while (true) {
            			fflush(stdin);
            			cin >> p->hoa;
            			if (CheckPoint(p->hoa)) {
				break;	
			}
            else {
                gotoxy(90, 17);
                Color(4);
                cout << "Diem khong hop le!";
               	Sleep(200);
                cin.clear();
                Color(15);
                delLine(90,17,30);
            }
        }
        CursorStatus(25, FALSE);
                	p->dtb=DiemTrungBinh(p->toan,p->li,p->hoa,p->sinh,p->van,p->su,p->dia,p->english);
                	Color(15);
                	EditPointSection(l,p);
                }               
                break;
            case 4: 
                MakeMenuEdit2();
                gotoxy(71, 20);
                Color(172);
                cout << "Sinh ";
                char et4;
                et4 = getch();
                if (int(et4) == 13) {
                	Color(15);
                    XoaVung();
                	gotoxy(71,17);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	gotoxy(90,17);
            		CursorStatus(25, TRUE);
                	while (true) {
            			fflush(stdin);
            			cin >> p->sinh;
            			if (CheckPoint(p->sinh)) {
				break;	
			}
            else {
                gotoxy(90, 17);
                Color(4);
                cout << "Diem khong hop le!";
               	Sleep(200);
                cin.clear();
                Color(15);
                delLine(90,17,30);
            }
        }
        CursorStatus(25, FALSE);
                	p->dtb=DiemTrungBinh(p->toan,p->li,p->hoa,p->sinh,p->van,p->su,p->dia,p->english);
                	Color(15);
                	EditPointSection(l,p);
                }                
                break;
            case 5:
                MakeMenuEdit2();
                gotoxy(71, 21);
                Color(172);
                cout << "Van ";
                char et5;
                et5 = getch();
                if (int(et5) == 13) {
                	Color(15);
                   	XoaVung();
                	gotoxy(71,17);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	gotoxy(90,17);
            		CursorStatus(25, TRUE);
                	while (true) {
            			fflush(stdin);
            			cin >> p->van;
            			if (CheckPoint(p->van)) {
				break;	
			}
            else {
                gotoxy(90, 17);
                Color(4);
                cout << "Diem khong hop le!";
               	Sleep(200);
                cin.clear();
                Color(15);
                delLine(90,17,30);
            }
        }
        CursorStatus(25, FALSE);
                	p->dtb=DiemTrungBinh(p->toan,p->li,p->hoa,p->sinh,p->van,p->su,p->dia,p->english);
                	Color(15);
                	EditPointSection(l,p);              	
                }
                break;
            case 6:
                MakeMenuEdit2();
                gotoxy(71, 22);
                Color(172);
                cout << "Su ";
                char et6;
                et6 = getch();
                if (int(et6) == 13) {
                	Color(15);
                    XoaVung();
                	gotoxy(71,17);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	gotoxy(90,17);
            		CursorStatus(25, TRUE);
                	while (true) {
            			fflush(stdin);
            			cin >> p->su;
            			if (CheckPoint(p->su)) {
				break;	
			}
            else {
                gotoxy(90, 17);
                Color(4);
                cout << "Diem khong hop le!";
               	Sleep(200);
                cin.clear();
                Color(15);
                delLine(90,17,30);
            }
        }
        CursorStatus(25, FALSE);
                	p->dtb=DiemTrungBinh(p->toan,p->li,p->hoa,p->sinh,p->van,p->su,p->dia,p->english);
                	Color(15);
                	EditPointSection(l,p);
                }
                break;
            case 7:
                MakeMenuEdit2();
                gotoxy(71, 23);
                Color(172);
                cout << "Dia ";
                char et7;
                et7 = getch();
                if (int(et7) == 13) {
                	Color(15);
                    XoaVung();
                	gotoxy(71,17);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	gotoxy(90,17);
            		CursorStatus(25, TRUE);
                	while (true) {
            			fflush(stdin);
            			cin >> p->dia;
            			if (CheckPoint(p->dia)) {
				break;	
			}
            else {
                gotoxy(90, 17);
                Color(4);
                cout << "Diem khong hop le!";
               	Sleep(200);
                cin.clear();
                Color(15);
                delLine(90,17,30);
            }
        }
        CursorStatus(25, FALSE);
                	p->dtb=DiemTrungBinh(p->toan,p->li,p->hoa,p->sinh,p->van,p->su,p->dia,p->english);
                	Color(15);
                	EditPointSection(l,p);
                }
                break;
            case 8:
                MakeMenuEdit2();
                gotoxy(71, 24);
                Color(172);
                cout << "Tieng anh ";
                char et8;
                et8 = getch();
                if (int(et8) == 13) {
                	Color(15);
                    XoaVung();
                	gotoxy(71,17);
                	Color(10);cout<<"Nhap noi dung sua:";Color(15);
                	gotoxy(90,17);
            		CursorStatus(25, TRUE);
                	while (true) {
            			fflush(stdin);
            			cin >> p->english;
            			if (CheckPoint(p->english)) {
				break;	
			}
            else {
                gotoxy(90, 17);
                Color(4);
                cout << "Diem khong hop le!";
               	Sleep(200);
                cin.clear();
                Color(15);
                delLine(90,17,30);
            }
        }
                	CursorStatus(25,FALSE);
                	p->dtb=DiemTrungBinh(p->toan,p->li,p->hoa,p->sinh,p->van,p->su,p->dia,p->english);
                	Color(15);
                	EditPointSection(l,p);
                }
                break;
            case 9: 
				MakeMenuEdit2();
                gotoxy(71, 25);
                Color(172);
                cout << "Xem ket qua va thoat ";
                char et9;
                et9 = getch();
                if (int(et9) == 13) {                    
                    Color(15);
                    ListP temp3;
                    Init2(temp3);
                    NodeP *temp31 = new NodeP;
                    copyNode2(p,temp31);
                    addHead2(temp3,temp31);
                    WritePointToFile(l);
                	gotoxy(76,20);
                	Sleep(300);
                	cout<<"Ket qua sau khi sua!";
                	DisplayPoint(temp3);
					delList(temp3);               	             	
                	MainMenuDiem(l);
                }

            default: break;
        }
        choise = getch();
        if (choise == 72 || choise == 80) pos = (choise == 72 && pos > 0) ? --pos : ((pos < 9) ? ++pos : pos = 1);

    } while (choise != 8);
}	


void MakeMainMenuStudent() {
	Color(15);
    gotoxy(46, 12);
    cout << "*MainMenu**" ;
    gotoxy(42, 15);
    cout << "Xem ho so ";
    gotoxy(42, 16);
    cout << "Xem diem ";
    gotoxy(42,17);
    cout<< "Exit ";
    MakeBorder();
}

void XemHoSo(ListT &hs) {
	Color(15);
	system("cls");
	NodeT *p=hs.head;
	ListT temp;
	Init(temp);
	while(p!=NULL) {
		if(p->phone == phonetoPlay) {
			addTail(temp,p->mahs,p->lop,p->name,p->birthday,p->sex,p->phone,p->fathername,p->fatherphone,p->mothername,p->motherphone);
		}
		p=p->next;
	}
	DisplayList(temp);
	delList(temp);
}

void XemDiem(ListP &hs){
	Color(15);
	system("cls");
	NodeP *p=hs.head;
	ListP temp;
	Init2(temp);
	while(p!=NULL) {
		if(p->phone == phonetoPlay) {
			addTail2(temp,p->mahs,p->lop,p->name,p->phone,p->toan,p->li,p->hoa,p->sinh,p->van,p->su,p->dia,p->english,p->dtb);
		}
		p=p->next;
	}
	DisplayPoint(temp);
	delList(temp);
}
void MainMenuStudent() {
	CursorStatus(25, FALSE);
    fflush(stdin);
    system("cls");
    int pos = 1;
    MakeMainMenuStudent();
    do {
        char choise;
        switch (pos) {
            case 1:Color(15);
                //system("cls");
                MakeMainMenuStudent();
                gotoxy(42, 15);
                Color(172);
                cout << "Xem ho so ";
                char et;
                et = getch();
				if (int(et) == 13) {
					XemHoSo(hs);
					MainMenuStudent();
				}
                Color(15);
                break;
            case 2:Color(15);               
                MakeMainMenuStudent();
                gotoxy(42, 16);
                Color(172);
                cout << "Xem diem ";
                char et2;
                et2 = getch();
                if(int(et2)==13) {
                	XemDiem(hs1);
                	MainMenuStudent();
				}
                Color(15);
                break; 
			case 3: Color(15);
			    MakeMainMenuStudent();
				gotoxy(42,17);
				Color(172);
				cout<< "Exit ";
				char et3;
				et3=getch();
				if(int(et3)==13) {
					Color(15);
					exit(1);}
				Color(15);
				break;			
        }
        choise = getch();
        if (choise != 0) {
            if (choise == 72 || choise == 80) pos = (choise == 72 && pos > 0) ? --pos : ((pos < 3) ? ++pos : pos = 1);
        }

    } while (1);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD NewSize;
    NewSize.X = width-1;
    NewSize.Y = height-1;

    SetConsoleScreenBufferSize(hStdout, NewSize);
}

void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
