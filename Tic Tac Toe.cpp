#include <iostream>
using namespace std;
char space[3][3]=
	{
		{'1','2','3'
		},
		{'4','5','6'
		},
		{'7','8','9'
		}
	};
	
	char p1[40];
	char p2[40];
	int row;
	int col;
	char token='x';
	bool tie=false;
	
	
	
	//it is used to display structore of game
void display(){
	
	cout<<"    |   |  \n";
	cout<<"  "<<space[0][0]<<" | "<<space[0][1]<<" | "<<space[0][2]<<" \n";
	cout<<"____|___|____\n";
	cout<<"    |   |  \n";
	cout<<"  "<<space[1][0]<<" | "<<space[1][1]<<" | "<<space[1][2]<<" \n";
    cout<<"____|___|____\n";
	cout<<"    |   |  \n";
	cout<<"  "<<space[2][0]<<" | "<<space[2][1]<<" | "<<space[2][2]<<" \n";

}

//it is uused to assign tokens
void assign(){
	int digit;
	
	if(token=='x'){
		cout<<p1<<" its your turn enter position"<<endl;
		cin>>digit;
		
	}
	else if(token=='0'){
		cout<<p2<<" its your turn enter position"<<endl;
		cin>>digit;
		
	}
	if(digit==1){
		row=0;
		col=0;
	}
	else if(digit==2){
		row=0;
		col=1;
	}
	else if(digit==3){
		row=0;
		col=2;
	}
	else if(digit==4){
		row=1;
		col=0;
	}
	else if(digit==5){
		row=1;
		col=1;
	}
	else if(digit==6){
		row=1;
		col=2;
	}
	else if(digit==7){
		row=2;
		col=0;
	}
	else if(digit==8){
		row=2;
		col=1;
	}
	else if(digit==9){
		row=2;
		col=2;
	}
	else{
		cout<<"Invalid digit"<<endl;
		assign();
	}
	//p1 will enter any symbol to any position
	if(token=='x' && space[row][col]!='x' && space[row][col]!='0'){
	     space[row][col]='x';
		 token='0';	
	}
	//p2 will enter any symbol to any position
	else if(token=='0' && space[row][col]!='x' && space[row][col]!='0'){
	     space[row][col]='0';
		 token='x';	
	}
	else{
		cout<<"this space is fill already";
	}
}

//to check results
bool result(){
	//to check horizontal and vertical
	for(int i=0;i<3;i++){
		if(space[i][0]==space[i][1] && space[i][1]==space[i][2]){
			return true;
		}
		if(space[0][i]==space[1][i] && space[2][i]==space[1][i]){
			return true;
		}
	}
	//check for diagonal
if(space[0][0]==space[1][1] && space[1][1]==space[2][2]){
		
		return true;
	}
	if(space[0][2]==space[1][1] && space[1][1]==space[2][0]){
		
		return true;
	}
	
	//to check that space is full
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(space[i][j]!='x' && space[i][j]!='0'){
				
				return false;
			}
			if(i==2 && j==2){
				tie=true;
				return true;
			}
		}
	}
	return false;
}
int main(){
cout<<"Enter name of first player"<<endl;
cin.getline(p1,40);	
cout<<"Enter name of second player"<<endl;
cin.getline(p2,40);
	
	while(!result()){
		display();
		assign();
		result();
	}
	display();
	if(tie==false && token=='x'){
		cout<<p2<<" wins"<<endl;
	}
		else if(tie==false && token=='0'){
		cout<<p1<<" wins"<<endl;
	}
	else{
		cout<<"Draw"<<endl;
	}
	
}
