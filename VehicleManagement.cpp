#include<iostream>
#define MAX_FLEET_LIMIT 100
using namespace std;
class Vehicle{
	protected:
		string make, model;
		int year;
		float price;
	public:
		virtual float calculateTax() {
			return 0.0;
		} 
		void setMake(string make){
			this->make = make;
		}
		void setModel(string model){
			this->model = model;
		}
		void setYear(int year){
			this->year = year;
		}
		void setPrice(float price){
			this->price = price;
		}
		string getMake(){
			return make;
		}
		string getModel(){
			return model;
		}
		int getYear(){
			return year;
		}
		float getPrice(){
			return price;
		}
		virtual void displayInfo(){
			cout<<"***MAKE: "<<make<<endl;
			cout<<"***MODEL: "<<model<<endl;
			cout<<"***YEAR: "<<year<<endl;
			cout<<"***PRICE: $"<<price<<endl;	
		}
};
class Car : public Vehicle{
	private:
		int NumDoors;
	public:
		void setNumDoors(int NumDoors){
			this->NumDoors = NumDoors;
		}
		int getNumDoors(){
			return NumDoors;
		}
		float calculateTax() override{  
			return price*0.1;
		}
		void displayInfo() override{
			Vehicle::displayInfo();
			cout<<"***NUMBER OF DOORS: "<<NumDoors<<endl;
			cout<<"***TAX: $"<<calculateTax()<<endl<<endl;
		}
}; 
class Truck : public Vehicle {
	private:
		int towingCapacity, payload;
	public: 
		void setPayload(int payload){ 
			this->payload = payload; 
		}
		int getPayload(){ 
			return payload; 
		}
		void setTowingCapacity(int towingCapacity){ 
			this->towingCapacity = towingCapacity; 
		}

		int getTowingCapacity(){ 
			return towingCapacity; 
		}
		float calculateTax() override { 
			return price * 0.12; 
		}
		void displayInfo(){
			Vehicle::displayInfo();
			cout<<"***TOWING CAPACITY: "<<towingCapacity<<" lbs"<<endl;
			cout<<"***PAYLOAD: "<<payload<<" lbs"<<endl;
			cout<<"***TAX: $"<<calculateTax()<<endl<<endl;
		}
};
int main(){
	cout<<"***********WELCOME TO VEHICLE MANAGEMENT SYSTEM***********"<<endl;
	Vehicle* fleet[MAX_FLEET_LIMIT];
	int numVehicles = 0, choice;
	do{
		cout<<"\n\t"<<"MENU:"<<"\n";
		cout<<"|\t1. Add Vehicles"<<endl;
		cout<<"|\t2. Remove Vehicle"<<endl;
		cout<<"|\t3. Search for Vehicles"<<endl;
		cout<<"|\t4. Exit"<<endl;
		cout<<"\n=>\tEnter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:{
				string type, make, model;
				int year;
				float price;
				if(numVehicles == 100){
					cout<<"No vacancy available in the fleet"<<endl;
					break;
				}
				cout<<"Enter Vehicle Type (Car/Truck): ";
				cin>>type;
				Vehicle* vehicle = nullptr;
				if(type == "car" || type == "Car"){
					vehicle = new Car();
					int numDoors;
					cout<<"Enter Number Of Doors: ";
					cin>>numDoors;
					static_cast<Car*>(vehicle)->setNumDoors(numDoors);
				}
				else if(type == "truck" || type == "Truck"){
					vehicle = new Truck();
			      	int payload, towingCapacity;
			      	cout << "Enter Payload of Truck (in lbs): ";
			      	cin >> payload;
			      	cout << "Enter Towing Capacity of Truck (in lbs): ";
			      	cin >> towingCapacity;
			      	static_cast<Truck*>(vehicle)->setPayload(payload);
			      	static_cast<Truck*>(vehicle)->setTowingCapacity(towingCapacity);
				}
				else{
					cout<<"INVALID TYPE ENTERED";
					break;
				}
				cout<<"Enter Vehicle Make: ";
			    cin>>make;
			    cout<<"Enter Vehicle Model: ";
			    cin>>model;
			    cout<<"Enter Vehicle Year: ";
			    cin>>year;
			    cout<<"Enter Vehicle Price: ";
			    cin>>price;
				vehicle->setMake(make);
				vehicle->setModel(model);
				vehicle->setYear(year);
				vehicle->setPrice(price);
				fleet[numVehicles] = vehicle;
				numVehicles++;
				cout<<"\n*****Vehicle Added to fleet*****\n";	
				break;
			}
			case 2:{
				if(numVehicles == 0){
					cout<<"Fleet is Empty"<<endl;
					break;
				}
				int index;
				cout<<"Enter The index of vehicle to remove (0-" << numVehicles-1 << "): ";
				cin>>index;
				if(index<0 || index>=numVehicles){
					cout<<"INVALID INDEX NUM ENTERED"<<endl;
					break;
				}
				delete fleet[index];
				for(int i=index; i<numVehicles-1; i++){
					fleet[i] = fleet[i+1];
				}
				numVehicles--;
				cout<<"\n****Vehicle REMOVED from fleet!*****\n"<<endl;
				break;
			}
			case 3:{
				if(numVehicles == 0){
					cout<<"Fleet is Curently Empty!"<<endl;
					break;
				}
				string Make, Model;
				int Year;
				float Price;
				bool found = false;
				cout<<"***Enter Search Criteria***"<<endl;
				cout<<"Enter Make: ";
				cin>>Make;
				cout<<"Enter Model: ";
				cin>>Model;
				cout<<"Enter Year: ";
				cin>>Year;
				cout<<"Enter Price: ";
				cin>>Price;	
				for(int i=0; i<numVehicles; i++){
					if(fleet[i]->getMake()==Make && fleet[i]->getModel()==Model && fleet[i]->getYear()==Year && fleet[i]->getPrice()<=Price){
						cout<<"\n*****MATCH FOUND*****\n";
						fleet[i]->displayInfo();
						found = true;
					}
				}
				if(!found){
					cout<<"***NO Such Vehicle Found***"<<endl;
				}
				break;
			}
			case 4:{
				cout<<"Exiting Vehicle Management System...."<<endl;
				break;
			}
			default:{
				cout<<"INVALID CHOICE"<<endl;
				break;		
			}
		} 
	}while(choice != 4);
	for(int i=0; i<numVehicles; i++){
		delete fleet[i];
	}
	return 0;
}