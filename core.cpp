#include "core.h"

void Init(ListT &l) {
    l.head = l.tail = NULL;
}

bool isEmpty(ListT l) {
    if (l.head == NULL) return true;
    return false;
}

bool isEmpty2(ListP l) {
    if (l.head == NULL) return true;
    return false;
}

int CheckAcc1(const string& username, const string& password) {
    ifstream file("giaovien.txt");
    string correctUsername, correctPassword;
    int found = 0;
   
    if (!file.is_open()) {
        cerr << "Khong the mo file" << endl;
        return found;
    }
    while (file >> correctUsername >> correctPassword) {
        if (correctUsername == username && correctPassword == password) {
            found = 1;
            break;
        }
    }
    file.close();
    return found;
}

int CheckAcc2(const string& phone) {
    ifstream file("HocSinh.txt");
    string filePhone;
    int found = 0;

    if (!file.is_open()) {
        cerr << "Khong the mo file" << endl;
        return found;
    }

    // doc tung dong trong file de check sdt
    while (file >> filePhone) {
        if (filePhone == phone) {
            found = 1;
            break;
        }
    }

    file.close();

    return found;
}

void addTail(ListT &l,string mahs, string lop,string name, string birthday, string sex,string phone,  string fathername, string fatherphone, string mothername, string motherphone) {
    NodeT*p = creatNode(mahs,lop,name,birthday,sex,phone,fathername,fatherphone,mothername,motherphone);
    if (isEmpty(l)) addHead(l,mahs,lop,name,birthday,sex,phone,fathername,fatherphone,mothername,motherphone);
    else {
        l.tail->next = p; //tro thuan
        l.tail = p; //cap nhat tail
    }
}

NodeT*searchName(NodeT*p, string key) {

     if (strcmp(p->name.c_str(), key.c_str()) == 0)  return p;
    return NULL;
}

bool isSameString(string s1, string s2) { //so sanh 2 string
    bool k = true;

    if (s1.find(s2) == -1) k = false;

    return k;
}

bool isSameName(NodeT *p, string key) {
	 if (strcmp(p->name.c_str(), key.c_str()) == 0) return true;
	return false;
}


NodeT*creatNode(string mahs,string lop,string name, string birthday,string sex, string phone,  string fathername, string fatherphone, string mothername, string motherphone) {
    NodeT*p = new NodeT; //ham cap phat bo nho;
    if (p == NULL) exit(1); // khong duoc cap phat thi thoat;
    else {
    	p->mahs = mahs;
		p->lop = lop;
        p->name = name;
        p->birthday = birthday;
        p->sex = sex;
        p->phone = phone;
        p->fathername = fathername;
        p->fatherphone = fatherphone;
        p->mothername = mothername;
        p->motherphone = motherphone;
        p->next = NULL;
        return p; //kieu ham la ham con tro nen phai tra ve con tro
    }
}

void addHead(ListT &l,string mahs, string lop,string name, string birthday,string sex, string phone,  string fathername, string fatherphone, string mothername, string motherphone) {
    NodeT*p = creatNode(mahs,lop,name,birthday,sex,phone,fathername,fatherphone,mothername,motherphone);
    if (isEmpty(l))l.head = l.tail = p;
    else {
        p->next = l.head; //con tro next cua p tro toi node head(ban dau)

        l.head = p; //cap nhat head (lucsau);
    }
}

void addHead(ListT &l, NodeT*p) {
    if (isEmpty(l))l.head = l.tail = p;
    else {
        p->next = l.head; //con tro next cua p tro toi node head(ban dau)

        l.head = p; //cap nhat head (lucsau);
    }
}

int lenghtNode(ListT &l) {
    NodeT*p = l.head;
    int lenght = 0;
    while (p != NULL) {
        lenght++;
        p = p->next;
    }
    return lenght;
}

int lenghtNode2(ListP &l) {
    NodeP*p = l.head;
    int lenght = 0;
    while (p != NULL) {
        lenght++;
        p = p->next;
    }
    return lenght;
}

void copyNode(NodeT*p, NodeT*q) {
    if (p == NULL) q = NULL;
    else {
    	q->mahs=p->mahs;
    	q->lop = p->lop;
        q->name = p->name;
        q->birthday = p->birthday;
        q->sex = p->sex;
        q->phone =p-> phone;
        q->fathername = p->fathername;
        q->fatherphone = p->fatherphone;
        q->mothername = p->mothername;
        q->motherphone = p->motherphone;
        q->next = NULL;
    }
}

void DeleteInFile(string &filename) {
	fstream file(filename.c_str(), ios::out | ios::trunc);
	if (!file.is_open()) {
        
        return ;
    }
    file.close();
}

NodeT *search(NodeT *p, string key){
	if(isSameString(p->mahs,key) || isSameString(p->lop,key) || isSameString(p->name,key) || isSameString(p->birthday,key) || isSameString(p->sex,key)|| isSameString(p->phone,key)
	 || isSameString(p->fathername,key) || isSameString(p->fatherphone,key)  
	|| isSameString(p->mothername,key)|| isSameString(p->motherphone,key) ) return p;
	return NULL;
}

bool isSameFloat(float value, const string& key) {
    stringstream ss;
    ss << fixed << setprecision(2) << value;
    string valueS = ss.str();
    bool k = true;
    if (valueS.find(key) == -1) k = false;
    return k;
    
}

NodeP *search(NodeP *p, string key){
    if(isSameString(p->mahs, key) || isSameString(p->lop,key) || isSameString(p->name,key) || isSameFloat(p->toan,key) || isSameFloat(p->li,key) || isSameFloat(p->hoa,key)
    || isSameFloat(p->sinh,key) || isSameFloat(p->van,key) || isSameFloat(p->su,key)  
    || isSameFloat(p->dia,key) || isSameFloat(p->english,key) || isSameFloat(p->dtb,key)) {
        return p;
    }
    return NULL;
}

void delList(ListT &l) {
    while (l.head != NULL) {
        NodeT*p = l.head;
        l.head = l.head->next;
        delete p;
    }
}

bool NameCompare(NodeT* n1, NodeT* n2) {
    // Tach ten thanh cac thanh phan
    vector< string> nameParts1, nameParts2;
    stringstream ss1(n1->name), ss2(n2->name);
    string temp;

    while (ss1 >> temp) nameParts1.push_back(temp);
    while (ss2 >> temp) nameParts2.push_back(temp);

    // dao nguoc thu tu
    reverse(nameParts1.begin(), nameParts1.end());
    reverse(nameParts2.begin(), nameParts2.end());

    // so sanh tung phan cua ten
    for (size_t i = 0; i <  min(nameParts1.size(), nameParts2.size()); ++i) {
        if (nameParts1[i] != nameParts2[i]) {
            return nameParts1[i] < nameParts2[i];
        }
    }
	//neu da so sanh tat ca cac phan thi ten ngan hon dung truoc
    return nameParts1.size() < nameParts2.size();
}

void SortByName(ListT &list) {
    if (list.head == NULL || list.head->next == NULL) {
        return;
    }

    NodeT* sorted = NULL;
    NodeT* current = list.head;

    while (current != NULL) {
        NodeT* next = current->next;
        if (sorted == NULL || !NameCompare(sorted, current)) {
            current->next = sorted;
            sorted = current;
        } else {
            NodeT* temp = sorted;
            while (temp->next != NULL && NameCompare(temp->next, current)) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    list.head = sorted;

  	//Cap nhat lai tail cua danh sach
    NodeT* tailNode = list.head;
    while (tailNode != NULL && tailNode->next != NULL) {
        tailNode = tailNode->next;
    }
    list.tail = tailNode;
}

bool ClassCompare(NodeT* n1, NodeT* n2) {
    // tach phan so voi phan chu
    string classNum1 = n1->lop.substr(0, n1->lop.size() - 1);
    string classNum2 = n2->lop.substr(0, n2->lop.size() - 1);
    char section1 = n1->lop[classNum1.size()];
    char section2 = n2->lop[classNum2.size()];

    // Chuyen doi phan so thanh so nguyen
    int grade1 = atoi(classNum1.c_str());
    int grade2 = atoi(classNum2.c_str());

    // So sanh phan so
    if (grade1 != grade2) {
        return grade1 < grade2;
    }
    // Neu phan so giong nhau thi so sanh phan chu
    return section1 < section2;
}


void SortByClass(ListT &l) {
    if (l.head == NULL || l.head->next == NULL) {
        return;
    }

    NodeT* sorted = NULL;
    NodeT* current = l.head;
    while (current != NULL) {
        NodeT* next = current->next;
        if (sorted == NULL || ClassCompare(current, sorted)) {
            current->next = sorted;
            sorted = current;
        } else {
            NodeT* temp = sorted;
            while (temp->next != NULL && !ClassCompare(current, temp->next)) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    l.head = sorted;

    NodeT* tailNode = l.head;
    while (tailNode != NULL && tailNode->next != NULL) {
        tailNode = tailNode->next;
    }
    l.tail = tailNode;
}

void ChuanHoa(string *s) {
    while (s->at(0) == ' ') 
		s->erase(0, 1); //loai bo khoang trang o dau chuoi
		
	//loai bo khoang trang va ki tu ko hop le o cuoi chuoi
    while (s->at(s->length() - 1) == ' ' || s->at(s->length() - 1) < 65 || s->at(s->length() - 1) > 122 )
		s->erase(s->length() - 1, 1);
		
	//loai bo cac khoang trang thua va ki tu ko hop le trong chuoi
    for (int i = 0; i < s->length() - 1; i++) {
        if (s->at(i) == s->at(i + 1)  || (s->at(i) < 65 || s->at(i) > 122)&& s->at(i) != 32 ) {
            s->erase(i, 1);
            i--;
        }
    }
    for (int i = 0; i < s->length(); i++) {// dua xau ve ki tu thuong
        if (s->at(i) >= 65 and s->at(i) <= 90) s->at(i) = s->at(i) + 32;
    }
    
	//viet hoa chu cai dau tien sau moi khoang trang
    s->at(0) = s->at(0) - 32;
    for (int i = 0; i < s->length() - 1; i++) {
        if (s->at(i) == ' ') s->at(i + 1) = s->at(i + 1) - 32;
    }
    if(s->size()==0) s=s+' ';
}

bool isPhoneNumberValid(const string &phone) {
    if (phone.length() != 10) return false;
    	for (size_t i = 0; i < phone.length(); ++i) {
    if (!isdigit(phone[i])) return false;
	}
    return true;
}

void deleteList(ListT &l) {
    NodeT* current = l.head;
    NodeT* nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    l.head = NULL;
}

bool CheckPoint(float n) {
    return ! cin.fail() && n >= 0.0 && n <= 10.0;
}

void addTail2(ListP &l,string mahs,string lop, string name, string phone, float toan, float li,float hoa, float sinh, float van, float su, float dia, float english,float dtb) {
    NodeP*p = creatNode2(mahs,lop,name,phone,toan,li,hoa,sinh,van,su,dia,english,dtb);
    if (isEmpty2(l)) addHead2(l,mahs,lop,name,phone,toan,li,hoa,sinh,van,su,dia,english,dtb);
    else {
        l.tail->next = p; //tro thuan
        l.tail = p; //cap nhat tail
    }
}

NodeP*creatNode2(string mahs,string lop,string name,string phone, float toan, float li,float hoa, float sinh, float van, float su, float dia, float english,float dtb) {
    NodeP*p = new NodeP; //ham cap phat bo nho;
    if (p == NULL) exit(1); // khong duoc cap phat thi thoat;
    else {
    	p->mahs=mahs;
		p->lop = lop;
        p->name = name;
        p->phone = phone;
        p->toan = toan;
        p->li = li;
        p->hoa = hoa;
        p->sinh = sinh;
        p->van = van;
        p->su = su;
        p->dia = dia;
        p->english = english;
        p->dtb=dtb;
        p->next = NULL;

        return p; //kieu ham la ham con tro nen phai tra ve con tro
    }
}

void addHead2(ListP &l,string mahs, string lop,string name, string phone,float toan, float li,float hoa, float sinh, float van, float su, float dia, float english,float dtb) {
    NodeP*p = creatNode2(mahs,lop,name,phone,toan,li,hoa,sinh,van,su,dia,english,dtb);
    if (isEmpty2(l))l.head = l.tail = p;
    else {
        p->next = l.head; //con tro next cua p tro toi node head(ban dau)

        l.head = p; //cap nhat head (lucsau);
    }
}

void Init2(ListP &l) {
    l.head = l.tail = NULL;
}

float DiemTrungBinh(float toan,float li,float hoa,float sinh,float van,float su,float dia,float english){
	float dtb = (toan + li + hoa + sinh + van + su + dia + english) / 8;
    return round(dtb * 100) / 100;  
}

bool checkIfExists(ListT &l, string name, string phone) {
    // Duyet qua danh sach
    for (NodeT *p = l.head; p != NULL; p = p->next) {
        if (p->name == name && p->phone == phone) {
            return true; // Hoc sinh da ton tai
        }
    }
    return false; // Khong tim thay hoc sinh trung lap
}

bool NameCompare(NodeP* n1, NodeP* n2) {
    vector< string> nameParts1, nameParts2;
    stringstream ss1(n1->name), ss2(n2->name);
    string temp;

    while (ss1 >> temp) nameParts1.push_back(temp);
    while (ss2 >> temp) nameParts2.push_back(temp);
 
    reverse(nameParts1.begin(), nameParts1.end());
    reverse(nameParts2.begin(), nameParts2.end());

    for (size_t i = 0; i <  min(nameParts1.size(), nameParts2.size()); ++i) {
        if (nameParts1[i] != nameParts2[i]) {
            return nameParts1[i] < nameParts2[i];
        }
    }
    return nameParts1.size() < nameParts2.size();
}

void SortByName(ListP &list) {
    if (list.head == NULL || list.head->next == NULL) {
        return;
    }

    NodeP* sorted = NULL;
    NodeP* current = list.head;

    while (current != NULL) {
        NodeP* next = current->next;
        if (sorted == NULL || !NameCompare(sorted, current)) {
            current->next = sorted;
            sorted = current;
        } else {
            NodeP* temp = sorted;
            while (temp->next != NULL && NameCompare(temp->next, current)) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    list.head = sorted;

    // cap nhat lai tail cua danh sach
    NodeP* tailNode = list.head;
    while (tailNode != NULL && tailNode->next != NULL) {
        tailNode = tailNode->next;
    }
    list.tail = tailNode;
}


bool ClassCompare(NodeP* n1, NodeP* n2) {
    string classNum1 = n1->lop.substr(0, n1->lop.size() - 1);
    string classNum2 = n2->lop.substr(0, n2->lop.size() - 1);
    char section1 = n1->lop[classNum1.size()];
    char section2 = n2->lop[classNum2.size()];

    int grade1 = atoi(classNum1.c_str());
    int grade2 = atoi(classNum2.c_str());

    if (grade1 != grade2) {
        return grade1 < grade2;
    }
    return section1 < section2;
}


void SortByClass(ListP &l) {
    if (l.head == NULL || l.head->next == NULL) {
        return;
    }

    NodeP* sorted = NULL;
    NodeP* current = l.head;
    while (current != NULL) {
        NodeP* next = current->next;
        if (sorted == NULL || ClassCompare(current, sorted)) {
            current->next = sorted;
            sorted = current;
        } else {
            NodeP* temp = sorted;
            while (temp->next != NULL && !ClassCompare(current, temp->next)) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    l.head = sorted;

    NodeP* tailNode = l.head;
    while (tailNode != NULL && tailNode->next != NULL) {
        tailNode = tailNode->next;
    }
    l.tail = tailNode;
}


void copyNode2(NodeP*p, NodeP*q) {
    if (p == NULL) q = NULL;
    else {
    	q->mahs=p->mahs;
    	q->lop = p->lop;
        q->name = p->name;
        q->phone = p-> phone;
        q->toan = p->toan;
        q->li = p->li;
        q->hoa =p->hoa;
        q->sinh = p->sinh;
        q->van = p->van;
        q->su = p->su;
        q->dia = p->dia;
        q->english = p->english;
        q->dtb = p->dtb;
        q->next = NULL;
    }
}

void addHead2(ListP &l, NodeP*p) {
    if (isEmpty2(l))l.head = l.tail = p;
    else {
        p->next = l.head; //con tro next cua p tro toi node head(ban dau)

        l.head = p; //cap nhat head (lucsau);
    }
}

void delList(ListP &l) {
    while (l.head != NULL) {
        NodeP*p = l.head;
        l.head = l.head->next;
        delete p;
    }
}

bool ScoreCompare(NodeP* n1, NodeP* n2) {
    return n1->dtb > n2->dtb;
}

void SortByScore(ListP &list) {
    if (list.head == NULL || list.head->next == NULL) {
        return;
    }

    NodeP* sorted = NULL;
    NodeP* current = list.head;

    while (current != NULL) {
        NodeP* next = current->next;
        if (sorted == NULL || ScoreCompare(current, sorted)) {
            current->next = sorted;
            sorted = current;
        } else {
            NodeP* temp = sorted;
            while (temp->next != NULL && !ScoreCompare(current, temp->next)) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    list.head = sorted;
   	//Cap nhat lai tail cua danh sach
    NodeP* tailNode = list.head;
    while (tailNode != NULL && tailNode->next != NULL) {
        tailNode = tailNode->next;
    }
    list.tail = tailNode;
}

bool isStudentIDExists(const ListT& l, const string& id) {
    NodeT* p = l.head;
    while (p != NULL) {
        if (p->mahs == id) {
            return true;
        }
        p = p->next;
    }
    return false;
}

//Ham lay ma hoc sinh
string MakeID(ListT& l) {
    string uniqueID;
    int count = 1;
    while (true) {
        // Tao ma hoc sinh dua tren so luong hoc sinh da co
        stringstream ss;
        ss << setw(4) << setfill('0') << count;
        uniqueID = ss.str();

        // Kiem tra ma da co chua
        if (!isStudentIDExists(l, uniqueID)) {
            break; // neu khong thoat vong lap
        }

        count++; // tang so luong hoc sinh len 1
    }
    return uniqueID;
}


