//STUDENT MANAGEMENT SYSTEM

using namespace std;

#include<iostream>
struct student
{
	int Roll_No;
	string Name;
	int Marks;
	struct student *Next;
};
typedef struct student NODE;
typedef struct student *PNODE;


class Students
{
	private:
	  PNODE Head;
	  int iSize;
	public:
	Students()
	{
		Head=NULL;
		iSize=0;
	}
int CheckRollNo(int RollNo)
{
	int Flag=0;
	PNODE Temp=Head;
	while(Temp!=NULL)
	{
		if(Temp->Roll_No==RollNo)
		{   
	        Flag=1;
			break;
		}
		Temp=Temp->Next;
	}
	if(Flag==1)
	  return 1;
    else
		return 0;
}

void InsertStudent(int RollNo,string cValue,int iMarks)
{   
    int iRet=0;
	PNODE Newn=NULL;
	Newn=new NODE;
	Newn->Roll_No=RollNo;
	Newn->Name=cValue;
	Newn->Marks=iMarks;
	Newn->Next=NULL;
	if(Head==NULL)
	{
		Head=Newn;
		iSize++;
	}
	else
	{ 
        iRet=CheckRollNo(RollNo);
		if(iRet==1)
		{  
	        cout<<"Roll Number is Already Inserted..Please Try Another"<<"\n";
			return;
		}
		else
		{
		Newn->Next=Head;
		Head=Newn;
		iSize++;
		}
	}
}

void Display()
{
	PNODE Temp=Head;
	cout<<"Roll No\tName\tMarks\n";
	while(Temp!=NULL)
	{
		cout<<Temp->Roll_No<<"\t";
		cout<<Temp->Name<<"\t";
		cout<<Temp->Marks<<"\t";
		cout<<"\n";
		Temp=Temp->Next;
	}
}
int Count()
{
	return iSize;
}

void DeleteStudent(int RollNo)
{
	PNODE Temp=Head;
	PNODE Target=NULL;
	if(Head->Roll_No==RollNo)
	{
		Target=Head;
		Head=Head->Next;
		delete(Target);
		iSize--;
	}
	else
	{
		while(Temp->Next->Roll_No!=RollNo)
		{
			Temp=Temp->Next;
		}
		Target=Temp->Next;
		Temp->Next=Temp->Next->Next;
		delete(Target);
		iSize--;
	}
}

void SearchByRoll(int RollNo)
{
	PNODE Temp=Head;
	while(Temp->Roll_No!=RollNo)
	{
		Temp=Temp->Next;
	}
	cout<<"Name Of Studet is:\t"<<Temp->Name<<"\t";
	cout<<"Marks Of Studet is:"<<Temp->Marks<<"\t";
}

void SearchByName(string Name)
{
	PNODE Temp=Head;
	while(Temp->Name!=Name)
	{
		Temp=Temp->Next;
	}
	cout<<"Roll No Of Studet is:"<<Temp->Roll_No<<"\t";
	cout<<"Marks Of Studet is:"<<Temp->Marks<<"\t";

}

void SearchByMarks(int Marks)
{
	PNODE Temp=Head;
	while(Temp->Marks!=Marks)
	{
		Temp=Temp->Next;
	}
	cout<<"Roll No Of Studet is:"<<Temp->Roll_No<<"\t";
	cout<<"Name Of Studet is:"<<Temp->Name<<"\t";
}
void UpdateMarks(int RollNo,int Marks)
{
	PNODE Temp=Head;
	while(Temp->Roll_No!=RollNo)
	{
		Temp=Temp->Next;
	}
	Temp->Marks=Marks;
}

int MaximumMarks()
{
	PNODE Temp=Head;
	int iTemp=0;
	iTemp=Temp->Marks;
	while(Temp!=NULL)
	{
	    if(iTemp<Temp->Marks)
		{
			iTemp=Temp->Marks;
		}
		Temp=Temp->Next;
	}
	return iTemp;
}

int ManimumMarks()
{
	PNODE Temp=Head;
	int iTemp=0;
	iTemp=Temp->Marks;
	while(Temp!=NULL)
	{
	    if(iTemp>Temp->Marks)
		{
			iTemp=Temp->Marks;
		}
		Temp=Temp->Next;
	}
	return iTemp;
}

int AvgMarks()
{
	PNODE Temp=Head;
	int iTemp=0,iRes=0,iCnt=0;
	iCnt=Count();
	while(Temp!=NULL)
	{
	    iTemp=iTemp+Temp->Marks;
		Temp=Temp->Next;
	}
	iRes=(iTemp)/iCnt;
	return iRes;
}

};
int main()
{  
    int ch=0,Roll_No=0,Marks=0,iRet=0;
    string Name;	
	Students obj;
	while(1)
	{
	cout<<"\nStudent Management System.!\n";
	cout<<"1.Add Student\n";
	cout<<"2.Delete Student\n";
	cout<<"3.Display All Students\n";
	cout<<"4.Search Student By Roll No\n";
	cout<<"5.Search Student By Name\n";
	cout<<"6.Search Student By Marks\n";
	cout<<"7.Update Students Marks\n";
	cout<<"8.Count Number Of Students\n";
	cout<<"9. Get Maximum Student Marks\n";
	cout<<"10.Get Minimum Student Marks\n";
	cout<<"11.Get Average Students Marks\n";
	cout<<"0.Exit\n";
    cin>>ch;
	switch(ch)
	{
	
case 1:cout<<"Enter Roll No Of Student:\n";
       cin>>Roll_No;
	   cout<<"Enter Name Of Student:\n";
       cin>>Name;
	   cout<<"Enter Marks Of Student:\n";
       cin>>Marks;
       obj.InsertStudent(Roll_No,Name,Marks);
        break;

case 2:cout<<"Enter Roll No Of Student:\n";
       cin>>Roll_No;
       obj.DeleteStudent(Roll_No);
       break;
	
case 3:obj.Display();
        break;
		
case 4:cout<<"Enter Roll No Of Student:\n";
       cin>>Roll_No;
       obj.SearchByRoll(Roll_No);
       break;

case 5:cout<<"Enter Name Of Student:\n";
       cin>>Name;
       obj.SearchByName(Name);
       break;

case 6:cout<<"Enter Marks Of Student:\n";
       cin>>Marks;
       obj.SearchByMarks(Marks);
       break;

case 7:cout<<"Enter Roll Of Student:\n";
       cin>>Roll_No;
	   cout<<"Enter Updated Marks Of Student:\n";
       cin>>Marks;
       obj.UpdateMarks(Roll_No,Marks);
       break;
	   
case 8:iRet=obj.Count();
       cout<<"Number Of Students:"<<iRet;
        break;

case 9:iRet=obj.MaximumMarks();
       cout<<"Maximum Marks Of Students:"<<iRet;
        break;

case 10:iRet=obj.ManimumMarks();
       cout<<"Minimum Marks Of Students:"<<iRet;
        break;


case 11:iRet=obj.AvgMarks();
       cout<<"Average Marks Of Students:"<<iRet;
        break;
		
case 0:cout<<"Thank You!\n";
       exit(0);		

default:cout<<"Invalid Input";
	}
  }
	return(0); 
}