#include <iostream>
#include <list>
#include <iterator> 
using namespace std;

struct SINHVIEN {
	char HoTen[51]; // Họ tên sinh viên
	char MSSV[10]; // Mã số sinh viên
	float DiemLT; // Điểm lý thuyết
	float DiemTH; // Điểm thực hành
	float DiemTB; // Điểm trung bình
};

void showlist(list <SINHVIEN> g)
{
	list <SINHVIEN> ::iterator it;
	int i = 1;
	for (it = g.begin(); it != g.end(); ++it) {

		cout << "\nInfo of student "<< i << ": " << endl;
		cout << "Name: " << it->HoTen << endl;
		cout << "ID: " << it->MSSV << endl;
		cout << "LT: " << it->DiemLT << endl;
		cout << "TH: " << it->DiemTH << endl;
		cout << "TB: " << it->DiemTB << endl;
		i++;

	}
		cout << endl;
}

void inputStudent(SINHVIEN& sv)
{
		
	cout << "Enter Name: ";
	cin >> sv.HoTen;
	cout << "Enter ID: ";
	cin >> sv.MSSV;
	cout << "Enter diem LT: ";
	cin >> sv.DiemLT;
	cout << "Enter diem TH: ";
	cin >> sv.DiemTH;
	sv.DiemTB = sv.DiemLT * 0.7 + sv.DiemTH * 0.3;

}

void checkStudent(list <SINHVIEN> g)
{
	list <SINHVIEN> ::iterator it;
	cout << "Check student: " << endl;
	for (it = g.begin(); it != g.end(); ++it) {
		cout << "\nName: " << it->HoTen << endl;
		cout << "ID: " << it->MSSV << endl;
		if (it->DiemTB < 5 || it->DiemLT == 0 || it->DiemTH == 0) {
			cout << "Hoc Lai\n";
		}
		else if (it->DiemTB < 7) {
			cout << "Trung Binh" << endl;
		}
		else if (it->DiemTB < 8) {
			cout << "Kha" << endl;
		}
		else if (it->DiemTB < 9) {
			cout << "Gioi" << endl;
		}
		else {
			cout << "Xuat Sac" << endl;
		}

	}
	cout << endl;
}

void earseStudent(list <SINHVIEN> g)
{
	list <SINHVIEN> ::iterator it;
	int count = 0;
	for (it = g.begin(); it != g.end(); ++it) {
		if (it->DiemTB < 5)
			g.erase(it);
	}
}

int main()
{
	int n;
	SINHVIEN sv;
	list <SINHVIEN> Slist;

	//nhập danh sách sinh viên
	do
	{
		cout << "Enter number of student: ";
		cin >> n;
	} while (n <= 0);
	
	for (int i = 0; i < n; ++i)
	{
		cout << "\nInput info of student "<< i << ": " << endl;
		inputStudent(sv);
		Slist.push_back(sv);
	}

	//xuất danh sách sinh viên
	cout << "\nList student: " << endl;
	showlist(Slist);

	// sắp xếp danh sách sinh viên	
	//list.sort();
	//showlist(list);

	//xếp loại học sinh và in ra 
	checkStudent(Slist);
		

	//xóa học sinh điểm dưới 5 và in ra 
	//earsestudent(slist);
	//showlist(slist);

	

	return 0;

}