/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<iostream>

#include<string.h>

using namespace std;

 

struct student{
    int stu_roll;
    string stu_name;
    long long int stu_phone;
    int d,m,y;
    string stu_address;

    void getdetails(int roll);
    void displaydetails();
    void search(student* arr,int n,int rollno);
    void delt(student* arr,int n,int rollno);
    void update(student* arr,int n,int rollno);
  

};

 
void search(student* arr,int n,int rollno){
        student f;

        for(int i=n/2;i>=0;){

            if((*(arr+i)).stu_roll == rollno){

                f= *(arr+i);
                break;
            }
            else if((*(arr+i)).stu_roll > rollno){
            	i=i/2;
			}
			 else if((*(arr+i)).stu_roll < rollno){
            	i=(n+i)/2;
			}
        }
        cout << " \nThe details of the student are: \n";
        f.displaydetails();

    }
void delt(student* arr,int n,int rollno){
        for(int i=0;i<n;i++){
            if((*(arr+i)).stu_roll == rollno){
                (*(arr+i)).stu_name='0';
                (*(arr+i)).stu_phone=0;
                (*(arr+i)).d=0;
                (*(arr+i)).m=0;
                (*(arr+i)).y=0;
                (*(arr+i)).stu_address='0';
                cout<<"data is deleted successfully"<<endl;                    
                   
            }
          }
    }
void update(student* arr,int n,int rollno){
      student f;

        for(int i=0;i<n;i++){

            if((*(arr+i)).stu_roll == rollno){
                
                cout << "\n1.name\n2.phone no.\n3.date of birth\n4.address \n";
                int no;
                cout<<"enter no of information for updating:";
                cin>>no;
                switch(no){
                    case 1:{cout<<"name:";
                    cin>>(*(arr+i)).stu_name;};break;
                    case 2:{cout<<"phone no.:";
                    cin>>(*(arr+i)).stu_phone;};break;
                    case 3:{cout<<"date:";
                    cin>>(*(arr+i)).d;
                        cout<<"month:";
                        cin>>(*(arr+i)).m;
                        cout<<"year:";
                        cin>>(*(arr+i)).y;
                    };break;
                    case 4:{cout<<"address:";
                    cin>>(*(arr+i)).stu_address;};break;
                    default:cout<<"enter valid number!";
                }
            }
        }
      cout<<"data is updated successfully"<<endl;
}


 void student::getdetails(int roll){
     stu_roll = roll;
    cout<<"enter student name: ";
    cin.ignore();
    getline(cin,stu_name);
    cout<<"enter student phone number: ";
    cin>>stu_phone;
    int i;
    for(i=0;i>=0;i++){
        if(stu_phone>9999999999||stu_phone<=0||stu_phone<1000000000)
        {
        cout<<"enter valid phone no: ";
        cin>>stu_phone;
        }
        else
           break;

    }
    cout<<"enter student date of birth:\n";
    cout<<"date:";
    cin>>d;
    cout<<"month:";
    cin>>m;
    cout<<"year:";
    cin>>y;
    int k;
    for(k=0;k>=0;k++){
        if(d>31||d<=0||m<=0||m>12){
    cout<<"enter valid student date of birth:\n";
    cout<<"date:";
    cin>>d;
    cout<<"month:";
    cin>>m;
    cout<<"year:";
    cin>>y;

        }
        else
            break;
    }
    cout<<"enter student address: ";
    cin.ignore();
    getline(cin,stu_address);
    cout << "Student with roll no. " << roll << " added successfully!\n";
    
}
void student::displaydetails(){
    cout<<"student roll no= "<<stu_roll<<endl;
    cout<<"student name= "<<stu_name<<endl;
    cout<<"student phone no.= "<<stu_phone<<endl;
    cout<<"student DOB: "<<d<<"/"<<m<<"/"<<y<<endl;
    cout<<"student address: "<<stu_address<<endl;
}
void menubar(student*x,int y);
// void mainmenu();
int main()

{

    int n,m,roll;

    cout<<"enter no. of students=";

    cin>>n;
    cout<<"-----------------------";

    student stu[n];

    for(m=0;m<n;m++){

        cout<<"\nEnter roll no. of student "<<m+1<<":\n";
        cin>>roll;

       stu[m].getdetails(roll);   //change

    }
   
    student *a=&stu[0];
    menubar(a,n);
    return 0;

}


void menubar(student* arr,int n){
     int roll;
     cout<<"------------------------\n";
    cout<<"1.Search Data\n2.Update Data\n3.Delete Data\n4.Exit\n";
    int k;
    cout<<"enter no of function:";
    cin>>k;
    student** a=&arr;
    switch(k){

        case 1:{cout << "Enter the roll no of student to find: ";
              cin >> roll;
              search(*a,n,roll);menubar(*a,n);};break;
        case 2:{cout << "Enter the roll no of student to update data: ";
              cin >> roll;
              update(*a,n,roll);menubar(*a,n);};break;
         case 3:{cout << "Enter the roll no of student to delete data: ";
              cin >> roll;
              delt(*a,n,roll);menubar(*a,n);};break;
        case 4:break;
        default:cout<<"enter valid number!";



    }
}





