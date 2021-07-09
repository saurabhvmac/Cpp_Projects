#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<conio.h>
using namespace std;

// the class that stores data
class hospital 
{
     int patient_id;
     char first_name[50];
     char last_name[50];
     int age;
     char blood[5];
     char gender;
     long long phone;
     char problem[50];
     public:
     void getdata();
     void showdata() const;
     int patient_id_fun() const;
}; 
//get data function
void hospital::getdata()
{
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
     cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
     cout << "\n   Please enter data for patient\n";
     cout<<"\n   Patient ID: ";
     cin>>patient_id;
     cout<<"   First name     : ";
     cin.ignore();
     cin.getline(first_name,50);
     cout<<"   Last name      : ";
     cin.getline(last_name,50);
     cout<<"   Blood Group    : ";
     cin>>blood;
     cout<<"   Gender(M/F)    : ";
     cin>>gender;
     cout<<"   Age            : ";
     cin>>age;
     cout<<"   Mobile Number  : ";
     cin>>phone;
     cout<<"   Problem        : ";
     cin.ignore();
     cin.getline(problem,50);
}
//show data function
void hospital::showdata() const
{
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
	cout<<"\n   Patient Admission Form:\n";
     cout<<"\n   Patient ID         : "<<patient_id;
	cout<<"\n   First Name         : "<<first_name;
	cout<<"\n   Last Name          : "<<last_name;
	cout<<"\n   Gender             : "<<gender;
	cout<<"\n   Age                : "<<age;
	cout<<"\n   Blood Group        : "<<blood;
	cout<<"\n   Mobile Number      : "<<phone;
     cout<<"\n   Problem            : "<<problem;
	cout<<"\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
}
//storing id
int  hospital::patient_id_fun() const
{
     return patient_id;
}
//All Functions Defined here
void create_newpatient();
void display_record_id(int);
void display_record();
void discharge_patient(int); 
//create new patient 
void create_newpatient()
{
     hospital patient;
     ofstream oFile;
     oFile.open("hospital.dat",ios::binary|ios::app);
     patient.getdata();
     oFile.write(reinterpret_cast<char *> (&patient), sizeof(hospital));
     oFile.close();
     cout<<"\n Patient Added in Record  ";
     cout<<"\n\t Press Enter: ";
}
//display all records
void display_record()
{
     hospital patient;
     ifstream inFile;
     inFile.open("hospital.dat",ios::binary);
     if(!inFile)
     {
          cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
          cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
          cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
          cout<<"\n\tAll Patients Discharged";
          cout<<"\n\t Press Enter: ";
          return;
     }
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
     cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
     cout<<"\n\n\n\tDISPLAYING ALL RECORDS\n\n";
     while(inFile.read(reinterpret_cast<char *> (&patient), sizeof(hospital)))
     {
          patient.showdata();
     }
     inFile.close();
     cout<<"\n\t Press Enter: ";

}
//read specific record based on patient id
void display_record_id(int id)
{
     hospital patient;
     ifstream iFile;
     iFile.open("hospital.dat",ios::binary);
     if(!iFile)
     {
          cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
          cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
          cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
          cout<<"\n\tAll Patients Discharged...";
          cout<<"\n\t Press Enter: ";
          cin.ignore();
          return;
     }
     bool flag=false;
     while(iFile.read(reinterpret_cast<char *> (&patient), sizeof(hospital)))
     {
          if(patient.patient_id_fun()==id)
          {
               cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
               cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
               cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
               patient.showdata();
               flag=true;
          }
     }
     iFile.close();
     if(flag==false)
     cout<<"\n\nRecord does not exist";
     cout<<"\n\t Press Enter: ";
     

}
//function to discharge patient by giving and id and deleting the specific patient record
void discharge_patient(int id)
{
     hospital patient;
     ifstream iFile;
     iFile.open("hospital.dat",ios::binary);
     if(!iFile)
     {
          
          cin.ignore();
          cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
          cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
          cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
          cout<<"\n\tAll Patients Discharged... ";
          cout<<"\n\t Press Enter: ";
          return;
     }
     ofstream oFile;
     oFile.open("Temp.dat",ios::out);
     iFile.seekg(0,ios::beg);
     while(iFile.read(reinterpret_cast<char *> (&patient), sizeof(hospital)))
     {
          if(patient.patient_id_fun()!=id)
          {
               oFile.write(reinterpret_cast<char *> (&patient), sizeof(hospital));
          }
     }
     oFile.close();
     iFile.close();
     remove("hospital.dat");
     rename("Temp.dat","hospital.dat");
     cout<<"\n\n\tPatient Discharged..";
     cout<<"\n\t Press Enter: ";
}
//the Mian function with login and pass 
int main()
{
     string login;
     int pass;
     system("cls");
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
     cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
     cout<<"\t ADMIN LOGIN \n\n";
     cout<<"\t Login ID : ";
     cin>>login;
     cout<<"\t Password : ";
     cin>>pass;
     if (login=="Hms1234" && pass==998877)
     {
          char choose;
          cout<<setprecision(2); 
          do
          {
               char choose;
               int num;
               system("cls");
               cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
               cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
               cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";         
               cout<<"\n\t LOGED IN";
               cout<<"\n\t MAIN MENU";
               cout<<"\n   [1] Add Patient\n";
               cout<<"   [2] Display Record By ID \n";
               cout<<"   [3] Display All Record \n";
               cout<<"   [4] Discharge Patient\n";
               cout<<"   [5] LOGOUT\n";
               cout<<"\n     Enter your choice : ";
               cin>>choose;
               cout<<"  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";

               system("cls");
               switch(choose)
               {
                    case '1':	create_newpatient();
                              getch();
                              break;

                    case '2':	cout<<"\n\t Enter Patient ID: ";
                              cin>>num;
                              display_record_id(num);
                              getch();
                              break;

                    case '3':	system("cls");
                              display_record();
                              getch();
                              break;

                    case '4':	cout<<"\n\t Enter Patient ID: ";
                              cin>>num;
                              discharge_patient(num);
                              getch();
                              break;

                    case '5':   cout<<"\n\t\tThank You!\n";
                              exit(0);
               }
          }while(choose!='6');
               return 0;
     }
     else
     {
          cout<<"Wrong LoginID / Password";
     }
}
