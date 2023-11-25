#include <iostream>
using namespace std;

void showMenu(){
	cout<<"**********************************************************************"<<endl;
	cout<<"Enter 1 to calculate area, perimeter and sum of all angles of hexagon"<<endl;
	cout<<"Enter 2 to calculat area and perimeter of square"<<endl;
	cout<<"Press any key to exit"<<endl;
	cout<<"**********************************************************************"<<endl;
}
class Hexagon{
	//member variables
	public:
		int lastDigit=6;
		int s=lastDigit;
		int a=120;
		
	//member functions
	
	//calculating area of hexagon
	double calcArea(){
		return 1.5*1.732*s;
	}
	
	//calculating perimeter of hexagon
	int calcPeri(){
		return 6*s;
	}
	
	//calculating sum of all angles of hexagon
	int calcAngleSum(){
		return 6*a;
	}
	
	void display(){
		cout<<"Area of heaxagon is: "<<calcArea()<<endl;
		cout<<"Perimeter of hexagon is: "<<calcPeri()<<endl;
		cout<<"Sum of angles of hexagon is: "<<calcAngleSum()<<endl;
	}
			
};
class Square{
	//member variables
	public:
		int lastDigit=7;
		int length=lastDigit;
		int a=120;
		
	//member functions
	
	//calculating area of square
	double calcAreaSquare(){
		return length*length;
	}
	
	//calculating perimeter of square
	int calcPeriSquare(){
		return 4*length;
	}
	
	
	
	void display(){
		cout<<"Area of heaxagon is: "<<calcAreaSquare()<<endl;
		cout<<"Perimeter of hexagon is: "<<calcPeriSquare()<<endl;
	}
			
};
int main(){
	int ch;
	do{
		showMenu();
		cin>>ch;
		if(ch==1){
			Hexagon hex;
			hex.display();
		}
		else if(ch==2){
			Square sq;
			sq.display();
		}
	}while(ch==1 || ch==2);
	
	return 0;
}
