#ifndef COREI_H
#define CORE_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

struct NodeT {
    string name;
    string birthday;
    string lop;
    string sex;
	string phone;
	string fathername;
	string fatherphone;
	string mothername;
	string motherphone;
	string mahs;
    NodeT*next;
    
};

struct ListT {
    NodeT*head;
    NodeT*tail;
};

struct NodeP {
	string mahs;
	string name;
	string lop;
	string phone;
	float toan;
	float li;
	float hoa;
	float sinh;
	float van;
	float su;
	float dia;
	float english;
	float dtb;
	NodeP *next;
};

struct ListP {
	NodeP *head;
	NodeP *tail;
};

void Init(ListT &l);
void Init2(ListP &l);
bool isEmpty(ListT l);
bool isEmpty2(ListP l);

struct Account {
    string username;
    string password;
};

int CheckAcc1(const string& username, const string& password);
int CheckAcc2(const string& phone);

void addTail(ListT &l, string mahs,string lop, string name, string birthday, string sex,string phone,  string fathername, string fatherphone, string mothername, string motherphone);
void FindStudent(ListT &l);
NodeT*searchName(NodeT*p, string key);
bool isSameString(string s1, string s2);
NodeT*creatNode(string mahs,string lop,string name, string birthday,string sex, string phone,  string fathername, string fatherphone, string mothername, string motherphone);
void addHead(ListT &l, string mahs, string lop,string name, string birthday, string sex,string phone,  string fathername, string fatherphone, string mothername, string motherphone);
void addHead(ListT &l, NodeT*p) ;
int lenghtNode(ListT &l);
void Searcpointtudent(ListT &point) ;
NodeT *search(NodeT *p, string key);
bool ClassCompare(NodeT* n1, NodeT* n2);
void SortByClass(ListT &l);


void WriteToFile(ListT &l);
void DeleteInFile(string &filename);
void copyNode(NodeT*p, NodeT*q);
void delList(ListT &l);
bool NameCompare(NodeT* n1, NodeT* n2);
void SortByName(ListT &list);
bool isSameName(NodeT *p, string key);
bool checkIfExists(ListT &l, string name, string phone);
void ChuanHoa(string *s);
bool isPhoneNumberValid(const string &phone);
void deleteList(ListT &l);
bool CheckPoint(float n);
void addTail2(ListP &l,string mahs,string lop, string name,string phone, float toan, float li,float hoa, float sinh, float van, float su, float dia, float english,float dtb);
NodeP*creatNode2(string mahs,string lop,string name,string phone, float toan, float li,float hoa, float sinh, float van, float su, float dia, float english,float dtb);
void addHead2(ListP &l,string mahs, string lop,string name, string phone,float toan, float li,float hoa, float sinh, float van, float su, float dia, float english,float dtb);
float DiemTrungBinh(float toan,float li,float hoa,float sinh,float van,float su,float dia,float english);

bool NameCompare(NodeP* n1, NodeP* n2);
void SortByClass(ListP &l);
bool ClassCompare(NodeP* n1, NodeP* n2);
void SortByName(ListP &list);
void SortStudents(ListP &list);
int lenghtNode2(ListP &l);
void copyNode2(NodeP*p, NodeP*q);
bool isSameFloat(float value, const string& key);
NodeP *search(NodeP *p, string key);
void addHead2(ListP &l, NodeP*p);
void delList(ListP &l);

void SortByScore(ListP &list);
bool ScoreCompare(NodeP* n1, NodeP* n2);

bool isStudentIDExists(const ListT& l, const string& id);
string MakeID(ListT& l);

#endif // CORE_H

