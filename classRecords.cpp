#include<iostream>
#include<string>
#define MAX_RECORDS 100
using namespace std;
struct StudentRecord{
	int rollNo, yearOfAdmission, tentativeYearOfPassing;
	string name, fathersName, dateOfBirth, branch, state, pin, country;
};
StudentRecord records[MAX_RECORDS];
void addRecord(int &count){ 
	if (count < MAX_RECORDS){ 
		cout << "Enter Student Details\n"; 
		cout << "Roll No: "; 
		cin >> records[count].rollNo; 
		cout << "Name: "; 
		cin.ignore(); 
		getline(cin, records[count].name); 
		cout << "Father's Name: "; 
		getline(cin, records[count].fathersName); 
		cout << "Date of Birth: "; 
		getline(cin, records[count].dateOfBirth); 
		cout << "Branch: "; 
		getline(cin, records[count].branch); 
		cout << "Year of Admission: "; 
		cin >> records[count].yearOfAdmission; 
		cout << "Tentative Year of Passing: "; 
		cin >> records[count].tentativeYearOfPassing; 
		cout << "State: "; 
		cin.ignore(); 
		getline(cin, records[count].state); 
		cout << "PIN: "; 
		getline(cin, records[count].pin); 
		cout << "Country: "; 
		getline(cin, records[count].country); 
		count++; 
		cout << "\nRecord ADDED successfully!\n"; 
	} 
	else{ 
		cout << "Maximum records reached. Cannot add more." << endl; 
	} 
}
void updateRecord(int count, int rollNo){ 
	for (int i = 0; i < count; i++){ 
		if (records[i].rollNo == rollNo){ 
			cout << "Enter updated information for Roll No " << rollNo << ":" << endl; 
			cout << "Name: "; 
			cin.ignore(); 
			getline(cin, records[i].name); 
			cout << "Father's Name: "; 
			getline(cin, records[i].fathersName); 
			cout << "Date of Birth: "; 
			getline(cin, records[i].dateOfBirth); 
			cout << "Branch: "; 
			getline(cin, records[i].branch); 
			cout << "Year of Admission: "; 
			cin >> records[i].yearOfAdmission; 
			cout << "Tentative Year of Passing: "; 
			cin >> records[i].tentativeYearOfPassing; 
			cout << "State: "; 
			cin.ignore(); 
			getline(cin, records[i].state); 
			cout << "PIN: "; 
			getline(cin, records[i].pin); 
			cout << "Country: "; 
			getline(cin, records[i].country); 
			cout << "\n Record UPDATE successfully!" << endl; 
			return; 
		} 
	} 
	cout << "Record with Roll No " << rollNo << " not found." << endl; 
}
void deleteRecord(int &count, int rollNo){
	for (int i = 0; i < count; i++){ 
		if (records[i].rollNo == rollNo){ 
			for (int j = i; j < count - 1; j++){ 
				records[j] = records[j + 1]; 
			} 
			count--; 
			cout << "\n Record bearing Roll No. " << rollNo << " DELETED Successfully!\n"; 
			return; 
		} 
	} 
	cout << "Record with Roll No " << rollNo << " not found. \n"; 	
}
void generateReport(int count, const string &attribute, const string &value){ 
	bool found = false; 
	cout << "Students with " << attribute << " '" << value << "':" << endl; 
	for (int i = 0; i < count; i++){ 
		if (attribute == "Name" && records[i].name == value){ 
			cout << "\n\tRoll No: " << records[i].rollNo << ", Name: " << records[i].name << endl; 
			found = true; 
		} 
		else if (attribute == "State" && records[i].state == value){ 
			cout << "\n\tRoll No: " << records[i].rollNo << ", State: " << records[i].state << endl; 
			found = true; 
		} 
		else if (attribute == "District" && records[i].pin == value){ 
			cout << "\n\tRoll No: " << records[i].rollNo << ", PIN: " << records[i].pin << endl; 
			found = true; 
		} 
	} 
	if (!found){ 
		cout << "No records found with " << attribute << " '" << value << "'" << endl; 
	} 
}
int main(){
	int count = 0;
	bool continuepgrm = true;
	while(continuepgrm){
		int choice, rollNo;
		string state, name, district;
		cout<<"\n******** MENU ********\n";
		cout<<"\n***** 1. Add a Record\n";
		cout<<"***** 2. Update a Record\n";
		cout<<"***** 3. Delete a Record\n";
		cout<<"***** 4. Generate Report by Name\n";
		cout<<"***** 5. Generate Report by State\n";
		cout<<"***** 6. Generate Report by District(PIN)\n";
		cout<<"***** 7. Exit \n";
		cout<<"*** Enter Your Choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				addRecord(count);
				break;
			case 2:
				cout<<"Enter Roll Number of Record That You Want To Update: ";
				cin>>rollNo;
				updateRecord(count, rollNo);
				break;
			case 3:
				cout<<"Enter Roll Number of Record That You Want To Delete: ";
				cin>>rollNo;
				deleteRecord(count, rollNo);
				break;	
			case 4:
				cout<<"Enter Name to Generate Report: ";
				cin.ignore();
				getline(cin, name);
				generateReport(count, "Name", name);
				break;
			case 5:
				cout<<"Enter State to Generate Report: ";
				cin.ignore();
				getline(cin, state);
				generateReport(count, "State", state);
				break;
			case 6:
				cout<<"Enter District to Generate Report: ";
				cin.ignore();
				getline(cin, district);
				generateReport(count, "District", district);
				break;
			case 7:
				cout<<"Exiting The Program. Thank You!";
				continuepgrm = false;
				break;
			default:
				cout<<"Invalid Input \n";
				break;		
		}	
	}
	return 0;
}