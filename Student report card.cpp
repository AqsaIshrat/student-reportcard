#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
class student
{
	int rollno;
	char name[50];
	int p_marks, c_marks, m_marks, e_marks, cs_marks;
	float per;
	char grade;
	void calculate();	
public:
	void getdata();		 
	void showdata();	 
	void show_tabular();
	int retrollno();
}; 


void student::calculate()
{
	per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
	if(per>=60)
		grade='A';
	else if(per>=50)
		grade='B';
	else if(per>=33)
		grade='C';
	else
		grade='F';
}

void student::getdata()
{
	cout<<"\nEnter The roll number of student ";
	cin>>rollno;
START:	cout<<"\n\nEnter The Name of student ";  					 
	cin>>name;
	
	for(int i=0; i<50;i++)
	{
		if(name[i]=='0' ||name[i]=='1' || name[i]=='2' ||name[i]=='3' ||name[i]=='4' ||name[i]=='5' ||name[i]=='6' ||name[i]=='7' ||name[i]=='8' ||name[i]=='9'){
			cout<<"invalid input..."<<endl;
			goto START; 													
			
		}
	}
AgainPhy:	cout<<"\nEnter The marks in physics out of 100 : ";       
	cin>>p_marks;
	if(p_marks>100)
	{
		
		p_marks=0;
		cout<<"Invalid input. Enter valid input . zada dramay na lagayn :p "<<endl;
		goto AgainPhy;
	}
AgainChe:	cout<<"\nEnter The marks in chemistry out of 100 : ";
	cin>>c_marks;
		if(c_marks>100)
	{
		p_marks=0;
	    cout<<"Invalid input. Enter valid input.. "<<endl;
		goto AgainChe;
	}
AgainMaths:	cout<<"\nEnter The marks in maths out of 100 : ";
	cin>>m_marks;
		if(m_marks>100)
	{
		p_marks=0;
		cout<<"Invalid input. Enter valid input"<<endl;
		goto AgainMaths;
	}
AgainEng:	cout<<"\nEnter The marks in english out of 100 : ";
	cin>>e_marks;
		if(e_marks>100)
	{
		p_marks=0;
		cout<<"Invalid input. Enter valid input"<<endl;
		goto AgainEng;
	}
computerSci:	cout<<"\nEnter The marks in computer science out of 100 : ";
	cin>>cs_marks;
		if(cs_marks>100)
	{
		p_marks=0;
		cout<<"Invalid input. Enter valid input"<<endl;
		goto computerSci;
	}
	calculate();
}

void student::showdata()
{
	cout<<"\nRoll number of student : "<<rollno;
	cout<<"\nName of student : "<<name;
	cout<<"\nMarks in Physics out of 100 : "<<p_marks;
	cout<<"\nMarks in Chemistry out of 100 : "<<c_marks;
	cout<<"\nMarks in Maths  out of 100: "<<m_marks;
	cout<<"\nMarks in English out of 100 : "<<e_marks;
	cout<<"\nMarks in Computer Science  out of 100:"<<cs_marks;
	cout<<"\nPercentage of student is  :"<<per;
	cout<<"\nGrade of student is :"<<grade;
    cout<<endl << endl << endl;   
}

void student::show_tabular()
{
	cout<<rollno<<setw(6)<<" "<<name<<setw(10)<<p_marks<<setw(4)<<c_marks<<setw(4)<<m_marks<<setw(4)
		<<e_marks<<setw(4)<<cs_marks<<setw(4)<<per<<setw(4)<<" "<<grade<<endl;
}

int  student::retrollno()
{
	return rollno;
}


void write_student();	
void display_all();	 
void display_sp(int);	
void modify_student(int);	
void delete_student(int);	
void class_result();	
void result();		
void intro();		
void entry_menu();	







int main()
{
	
	system("color 97");
	char ch;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); 
	
	intro();
	do
	{
		
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. RESULT MENU";
		cout<<"\n\n\t02. ENTRY/EDIT MENU";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		cin>>ch;
		
		switch(ch)
		{
			case '1': result();
				break;
			case '2': entry_menu();
				break;
			case '3':
				break;
			default :cout<<"\a";
		}
    	}while(ch!='3');
	return 0;
}


void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write((char *) &st, sizeof(student));
	outFile.close();
    	cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	getch();
}


void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read((char *) &st, sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	getch();
}


void display_sp(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}

	int flag=0;
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.retrollno()==n)
		{
			 st.showdata();
			 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nrecord not exist";
	getch();
}

void modify_student(int n)
{
	int found=0;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	while(File.read((char *) &st, sizeof(student)) && found==0)
	{
		if(st.retrollno()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata();
		    	int pos=(-1)*sizeof(st);
		    	File.seekp(pos,ios::cur);
		    	File.write((char *) &st, sizeof(student));
		    	cout<<"\n\n\t Record Updated";
		    	found=1;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}


void delete_student(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.retrollno()!=n)
		{
			outFile.write((char *) &st, sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ..";
	getch();
}


void class_result()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"==========================================================\n";
	cout<<"R.No       Name        P   C   M   E   CS   %age   Grade"<<endl;
	cout<<"==========================================================\n";
	while(inFile.read((char *) &st, sizeof(student)))
	{
		st.show_tabular();
	}
	getch();
	inFile.close();
}


void result()
{
	char ch;
	int rno;
	cout<<"\n\n\n\tRESULT MENU";
	cout<<"\n\n\n\t1. Class Result";
	cout<<"\n\n\t2. Student Report Card";
	cout<<"\n\n\t3. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice (1/2/3)? ";
	cin>>ch;

	switch(ch)
	{
	case '1' :class_result(); break;
	case '2' :cout<<"\n\n\tEnter Roll Number Of Student : ";
		  cin>>rno;
		  display_sp(rno); break;
	case '3' :break;
	default :cout<<"\a";
	}
}


void intro()
{
	cout<<"\n\n\n\t\t  STUDENT";
	cout<<"\n\n\t\tREPORT CARD";
	cout<<"\n\n\t\t  PROJECT";
	cout<<"\n\n\n\tMADE BY : Aqsa Ishrat";
	cout<<"\n\tSCHOOL : Saint marries School System";
	getch();
}

void entry_menu()
{
	char ch;
	int num;
	
	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch;
	
	switch(ch)
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			display_sp(num); break;
	case '4':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			modify_student(num);break;
	case '5':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			delete_student(num);break;
	case '6':	break;
	default:	cout<<"\a"; entry_menu();
	}
}
