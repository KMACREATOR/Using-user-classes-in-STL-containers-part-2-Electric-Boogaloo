#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <set>
#include <unordered_set>
#include <sstream>
#include <algorithm>

using namespace std;
//������ - ������� (����: ���, ������, ����� �������� ������, ������ 4-� ������  �� ������)
//���������� �� ���
//�������� ��������� - list, �������� � vector

class Student{
    public:
    string name;
    string group;
    string zachetka;
    int session[4];


    Student(){}


    Student(string name, string group, string zachetka, int session[4]){
    this->name = name;
    this->group = group;
    this->zachetka = zachetka;
    for (int i = 0; i < 4; ++i){
            this->session[i] = session[i];
   }
    }

    //����������� �����������
    Student(const Student& S){
    this->name = S.name;
    this->group = S.group;
    this->zachetka = S.zachetka;
    for (int i = 0; i < 4; ++i){
            this->session[i] = S.session[i];
    }
    }


    //����������� �����������
    Student(Student&& chel){
        swap(this->name, chel.name);
        swap(this->group, chel.group);
        swap(this->zachetka, chel.zachetka);
        for (int i = 0; i < 4; ++i){
            swap(this->session[i], chel.session[i]);
    }
    }

    print(){
        cout << "\n���: " << name << "\n������: " << group << "\n�������: " << zachetka << endl;
        for (auto pos: session){
            cout << session[pos];
        }
    }


Student& operator=(const Student& s1) {
		this->name = s1.name;
		this->group = s1.group;
		this->zachetka = s1.zachetka;
		for (int i = 0; i < 4; ++i){
            this->session[i] = s1.session[i];
    }

		return *this;
	}

//Student& operator <(const Student& s1, const Student& s2){
//    return (s1.name < s2.name);
//}

//��������������� ���������
    bool operator==(const Student& s1) const{
        return this->name == s1.name;
    }

    bool operator <(const Student& s) const{
        return (this->name < s.name);
        }

    friend ostream& operator << (ostream& osm, const Student& St){
        osm << "\n���: " << St.name << "\n������: " << St.group << "\n�������: " << St.zachetka << endl;
        for (int i = 0; i < 4; ++i){
            osm << St.session[i];
        }
    osm << endl;
    return osm;
    }
};


struct hashworker {
    size_t operator()(const Student& s) const{
        return hash<string>()(s.name);
    }

};


int main(){
    ifstream infile("input.txt");
    fstream outfile("output.txt");

    setlocale(LC_ALL, "RUS");

    //������� list, set, unordered_set
    list <Student> origin;
    set<Student> collection;
    unordered_set<Student, hashworker> un_collection;
    string name, group, zachetka;
    int session[4];

    //��������� �� �����
    while(!infile.eof()){
        getline(infile, name);
        infile >> group;
        infile.ignore();
        infile >> zachetka;
        infile.ignore();
        for (int i = 0; i < 4; ++i){
                infile >> session[i];
                cout << session[i];
        }
        cout << "\t";
        infile.ignore();
        origin.push_back(Student(name, group, zachetka, session));
        collection.insert(Student(name, group, zachetka, session));
        un_collection.insert(Student(name, group, zachetka, session));

    }


    //��������� � ������� sort ��� ����������
    cout << "�������� ������ �� ����������:\n";
    outfile << "�������� ������ �� ����������:\n";
    for (auto iter = origin.begin(); iter != origin.end(); iter++)
    {
        outfile << *iter << "\t";
        cout << *iter << "\t";
    }


    vector <Student> legacy;
    legacy.resize(origin.size());
    copy(origin.begin(), origin.end(), legacy.begin());
    cout << "��������� ����������� � ������ ���������:\n";
    outfile << "��������� ����������� � ������ ���������:\n";
    for (auto iter = legacy.begin(); iter != legacy.end(); iter++)
    {
        outfile << *iter << "\t";
        cout << *iter << "\t";
    }
    cout << "�������� ������ ����� ����������:\n";
    origin.sort();
    outfile << "�������� ������ ����� ����������:\n";
    for (auto iter = origin.begin(); iter != origin.end(); iter++)
    {
        outfile << *iter << "\t";
        cout << *iter << "\t";
    }



    cout << "���������� set:\n";
    outfile << "���������� set:\n";
    for (const auto& x : collection) {
        cout << x << endl;
		outfile << x << endl;
	}
    cout << "���������� unordered set:\n";
    outfile << "���������� unordered set:\n";
    for (const auto& x : un_collection) {
        cout << x << endl;
		outfile << x << endl;
	}



    return 0;
}
