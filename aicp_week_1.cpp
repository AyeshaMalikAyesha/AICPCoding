#include <iostream>
#include <vector>
using namespace std;

//Task1-Setting up the system and ordering the main items.
double order_main_items(string cases,string ram,string disk,string item_code[],double price[]){
	double total_price=200;
	for(int i=0;i<17;i++){
		if(item_code[i]==cases){
			total_price+=price[i];
		}
		if(item_code[i]==ram){
			total_price+=price[i];
		}
		if(item_code[i]==disk){
			total_price+=price[i];
		}
	}
	return total_price;
}
void show_menu(){
    cout<<"***************Welcome to Online Computer Shop*****************************************"<<endl;
    cout << "Category\tItem code\tDescription\tPrice ($)" << endl;
    cout << "---------------------------------------------------" << endl;

    // Case
    cout << "Case\t\t\tA1\tCompact\t\t\t\t75.00" << endl;
    cout << "Case\t\t\tA2\tTower\t\t\t\t150.00" << endl;

    // RAM
    cout << "RAM\t\t\tB1\t8 GB\t\t\t\t79.99" << endl;
    cout << "RAM\t\t\tB2\t16 GB\t\t\t\t149.99" << endl;
    cout << "RAM\t\t\tB3\t32 GB\t\t\t\t299.99" << endl;

    // Main Hard Disk Drive
    cout << "Main Hard Disk Drive\tC1\t1 TB HDD\t\t\t49.99" << endl;
    cout << "Main Hard Disk Drive\tC2\t2 TB HDD\t\t\t89.99" << endl;
    cout << "Main Hard Disk Drive\tC3\t4 TB HDD\t\t\t129.99" << endl;

    // Solid State Drive
    cout << "Solid State Drive\tD1\t240 GB SSD\t\t\t59.99" << endl;
    cout << "Solid State Drive\tD2\t480 GB SSD\t\t\t119.99" << endl;

    // Second Hard Disk Drive
    cout << "Second Hard Disk Drive\tE1\t1 TB HDD\t\t\t49.99" << endl;
    cout << "Second Hard Disk Drive\tE2\t2 TB HDD\t\t\t89.99" << endl;
    cout << "Second Hard Disk Drive\tE3\t4 TB HDD\t\t\t129.99" << endl;

    // Optical Drive
    cout << "Optical Drive\t\tF1\tDVD/Blu-Ray Player\t\t50.00" << endl;
    cout << "Optical Drive\t\tF2\tDVD/Blu-Ray Re-writer\t\t100.00" << endl;

    // Operating System
    cout << "Operating System\tG1\tStandard Version\t\t100.00" << endl;
    cout << "Operating System\tG2\tProfessional Version\t\t175.00" << endl;
    cout<<"*******************************************************************************************"<<endl;
}
int main(){
	show_menu();
	string item_code[]={"A1","A2","B1","B2","B3","C1","C2","C3","D1","D2","E1","E2","E3","F1","F2","G1","G2"};
	string description[]={"Compact","Tower","8 GB","16 GB","32 GB","1 TB HDD","2 TB HDD","4 TB HDD","240 GB SSD","480 GB SSD","1 TB HDD","2 TB HDD","4 TB HDD","DVD/Blu-Ray Player","DVD/Blu-Ray Re-writer","Standard Version","Professional Version"};
	double price[]={75.00,150.00,79.99,149.99,299.99,49.99,89.99,129.99,59.99,119.99,49.99,89.99,129.99,50.00,100.00,100.00,175.00};
    string cases;
    string ram;
    string drive;
    vector<string> items;
    
	
//TASK1
	
	cout<<"Choose item code of one case"<<endl;
	cin>>cases;
	while(cases!="A1" && cases!="A2"){
		cout<<"ERROR! Please enter the case item code from above menu"<<endl;
		cin>>cases;
	}

	items.push_back(cases);
		
		cout<<"Choose item code of one RAM"<<endl;
	cin>>ram;
	while(ram!="B1" && ram!="B2" && ram!="B3"){
			cout<<"ERROR! Please enter the ram item code from above menu"<<endl;
		cin>>ram;
	}
	items.push_back(ram);

		cout<<"Choose one Main Hard Disk Drive"<<endl;
	cin>>drive;
	while(drive!="C1" && drive!="C2" && drive!="C3"){
			cout<<"ERROR! Please enter the drive item code from above menu"<<endl;
		cin>>drive;
	}
	items.push_back(drive);
	
	double total_price=order_main_items(cases,ram,drive,item_code,price);
	
	cout<<"The price of computer is "<<total_price<<endl;
	
	//TASK2
	int no_of_items=0;
	char choice;
    cout<<"Do you want to choose any items from the other categories"<<endl;
    cin>>choice;
    string code;
    if(choice=='Y' || choice=='y'){
    	
    	cout<<"Enter item code from above menu"<<endl;
    	cin>>code;
    	while(code=="D1" || code=="D2" || code=="E1" || code=="E2" || code=="E3" || code=="F1" || code=="F2" || code=="G1" || code=="G2"){
    		for(int i=0;i<17;i++){
    			if(item_code[i]==code){
    				items.push_back(item_code[i]);
    				no_of_items++;
    				total_price+=price[i];
    				break;
				}
			}
			cout<<"Do you want to buy more items"<<endl;
			cin>>choice;
			if(choice=='Y' || choice=='y'){
				cout<<"Enter item code from above menu"<<endl;
    	        cin>>code;
			}
			else{
				break;
			}
		}
		cout<<"YOUR TOTAL PRICE AFTER BUYING ADDITIONAL ITEMS IS "<<total_price<<endl;
	    
	    //TASK3
	    if(no_of_items==1){
	    	cout<<"The new price of computer after discount is "<<(total_price)-(0.05*total_price)<<endl;
	    	cout<<"The amount of money saved is "<<total_price*0.05<<endl;
		}
		else if(no_of_items>1){
				cout<<"The new price of computer after discount is "<<(total_price)-(0.1*total_price)<<endl;
				cout<<"The amount of money saved is "<<total_price*0.1<<endl;
		}
	
	}
	cout<<"THE ITEMS BOUGHT ARE:"<<endl;
	for(int i=0;i<items.size();i++){
		cout<<items[i]<<endl;
	}
	
	
	
	
	
	return 0;
}
