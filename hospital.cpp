#include <iostream>

using namespace std;

const int spots=5,specializations=20;	

string patientsNamesRegular[specializations][spots];	
string patientsNamesUrgent[specializations][spots];
int patientsCnt[specializations];

void addNewPatient();
void printAllPatients();
void getNextPatient();
int menu();

int main(){
	while(true){
		int choice=menu();
		if(choice==1)addNewPatient();
		if(choice==2)printAllPatients();
		if(choice==3)getNextPatient();
		if(choice==4)return 0;
	}	
}

int menu(){
	cout<<"1) Add new patient\n";
	cout<<"2) Pring all patients\n";
	cout<<"3) Get next patient\n";
	cout<<"4) Exit\n";
	int choice;cin>>choice;
	return choice;
}

void addNewPatient(){
	cout<<"Enter specialization, name, statis(0/1): ";
	int specialization;
	string name;
	bool statis;
	cin>>specialization>>name>>statis;
	specialization--;
	if(patientsCnt[specialization]==spots)
		cout<<"Sorry we can't add more patients for this specialization\n";
	else{
		patientsCnt[specialization]++;
		if(statis==0){
			for(int patient=0;patient<spots;patient++){
				if(patientsNamesUrgent[specialization][patient].empty()){
					patientsNamesUrgent[specialization][patient]=name;
					break;
				}
			}
		}else{
			for(int patient=0;patient<spots;patient++){
				if(patientsNamesRegular[specialization][patient].empty()){
					patientsNamesRegular[specialization][patient]=name;
					break;
				}
			}
		}
	}
}

void printAllPatients(){
	for(int specialization=0;specialization<specializations;specialization++){
		if(!patientsCnt[specialization])continue;
		cout<<"There are "<<patientsCnt[specialization]<<" in specialization "<<specialization+1<<'\n';
		for(int patient=spots-1;patient>=0;patient--){
			if(patientsNamesUrgent[specialization][patient]!=""){
				cout<<patientsNamesUrgent[specialization][patient]<<" urgent\n";
			}
		}
		for(int patient=0;patient<spots;patient++){
			if(patientsNamesRegular[specialization][patient]!=""){
				cout<<patientsNamesRegular[specialization][patient]<<" regular\n";
			}
		}
		cout<<'\n';
	}
	cout<<'\n';
}

void getNextPatient(){
	cout<<"Enter specialization: ";
	int specialization;
	cin>>specialization;
	specialization--;
	if(!patientsCnt[specialization]){
		cout<<"No patients at the moment. Have reset, Dr\n";
		return;
	}
	bool found=false;
	for(int patient=spots-1;patient>=0;patient--){
		if(!patientsNamesUrgent[specialization][patient].empty()){
			cout<<patientsNamesUrgent[specialization][patient]<<" please go with the Dr\n";
			patientsNamesUrgent[specialization][patient]="";
			found=true;
			break;
		}
	}
	if(!found){
		for(int patient=0;patient<spots;patient++){
			if(!patientsNamesRegular[specialization][patient].empty()){
				cout<<patientsNamesRegular[specialization][patient]<<" please go with the Dr\n";
				patientsNamesRegular[specialization][patient]="";
				found=true;
				break;
			}
		}	
	}
	if(found)
		patientsCnt[specialization]--;
}
