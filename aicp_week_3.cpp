#include <iostream>
using namespace std;

void showMenu(){
	cout<<"My Student ID is XY12345678"<<endl;
	cout<<"Enter your choice"<<endl;
	cout<<"Press 1 to display the bill of slab 1 and slab 2."<<endl;
	cout<<"Press 2 to display the bill of slab 3."<<endl;
	cout<<"Press any other key to exit."<<endl;
	
}
int costSlab1(int slab1[3][3]){
	cout<<"Bill for Slab 1 is "<<endl;
	for(int i=0;i<3;i++){
		cout<<slab1[0][i]*10<<"\t";
	}
	cout<<endl;
}
int costSlab2(int slab2[3][3]){
	cout<<"Bill for Slab 1 is "<<endl;
	for(int i=0;i<3;i++){
		cout<<(slab2[1][i])*15<<"\t";
	}
	cout<<endl;
}
int costSlab3(int slab3[3][3]){
	cout<<"Bill for Slab 1 is "<<endl;
	for(int i=0;i<3;i++){
		cout<<(slab3[2][i])*20<<"\t";
	}
	cout<<endl;
}

int main(){
	int costs[3][3]={{55,65,75},{120,150,170},{210,230,240}};
	int choice;
	do{
		showMenu();
		cin>>choice;
		if(choice==1){
		
		costSlab1(costs);
		costSlab2(costs);
	}
	else if(choice==2){
		costSlab3(costs);
	}
		
		
		
	}while(choice==1 || choice==2);
	
	return 0;
}
