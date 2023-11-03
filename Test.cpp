#include <iostream>
using namespace std;

 bool isValidFrequentParkingNumber(int number){

    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += number % 10;
        number /= 10;
    }
    return (sum % 11) == (number % 10);

}

int priceToPark(string day,int arrivalHour,int stayHours,int parkingNumber){
	int price=0;
	if(day=="Sunday" && stayHours<=8){
		if(isValidFrequentParkingNumber && (arrivalHour>=16 && arrivalHour<=24) ){
			price= (2*stayHours)/2;
		}
		else if(isValidFrequentParkingNumber && (arrivalHour>=8 && arrivalHour<=16)){
			price= (2*stayHours)-(0.1*(2*stayHours));
		}
		else if((arrivalHour>=8 && arrivalHour<=16) || (arrivalHour>=16 && arrivalHour<=24)){
			price= 2*stayHours;
		}
	}
	else if(day=="Monday" && stayHours<=2){
		if(parkingNumber<10000 && (arrivalHour>=16 && arrivalHour<=24) ){
			price= (2*stayHours)/2;
		}
		else if(isValidFrequentParkingNumber && (arrivalHour>=8 && arrivalHour<=16)){
			price= (10*stayHours)-(0.1*(2*stayHours));
		}
		else if(arrivalHour>=8 && arrivalHour<=16){
			price= 10*stayHours;
		}
		else if(arrivalHour>=16 && arrivalHour<=24){
			price= 2*stayHours;
		}
	}
	else if(day=="Tuesday" && stayHours<=2){
		if(isValidFrequentParkingNumber && (arrivalHour>=16 && arrivalHour<=24) ){
			price= (2*stayHours)/2;
		}
		else if(isValidFrequentParkingNumber && (arrivalHour>=8 && arrivalHour<=16)){
			return (10*stayHours)-(0.1*(2*stayHours));
		}
		else if(arrivalHour>=8 && arrivalHour<=16){
			price= 10*stayHours;
		}
		else if(arrivalHour>=16 && arrivalHour<=24){
			price= 2*stayHours;
		}
	}
	else if(day=="Wednesday" && stayHours<=2){
		if(isValidFrequentParkingNumber && (arrivalHour>=16 && arrivalHour<=24) ){
			price= (2*stayHours)/2;
		}
		else if(isValidFrequentParkingNumber && (arrivalHour>=8 && arrivalHour<=16)){
			price= (10*stayHours)-(0.1*(2*stayHours));
		}
		else if(arrivalHour>=8 && arrivalHour<=16){
			price= 10*stayHours;
		}
		else if(arrivalHour>=16 && arrivalHour<=24){
			price= 2*stayHours;
		}
	}
	else if(day=="Thursday" && stayHours<=2){
		if(isValidFrequentParkingNumber && (arrivalHour>=16 && arrivalHour<=24) ){
			price= (2*stayHours)/2;
		}
		else if(parkingNumber<10000 && (arrivalHour>=8 && arrivalHour<=16)){
			price= (10*stayHours)-(0.1*(2*stayHours));
		}
		else if(arrivalHour>=8 && arrivalHour<=16){
			price= 10*stayHours;
		}
		else if(arrivalHour>=16 && arrivalHour<=24){
			price= 2*stayHours;
		}
	}
	else if(day=="Friday" && stayHours<=2){
		if(isValidFrequentParkingNumber && (arrivalHour>=16 && arrivalHour<=24) ){
			price= (2*stayHours)/2;
		}
		else if(isValidFrequentParkingNumber && (arrivalHour>=8 && arrivalHour<=16)){
			price= (10*stayHours)-(0.1*(2*stayHours));
		}
		else if(arrivalHour>=8 && arrivalHour<=16){
			price= 10*stayHours;
		}
		else if(arrivalHour>=16 && arrivalHour<=24){
			price= 2*stayHours;
		}
	}
	else if(day=="Saturday" && stayHours<=2){
		if(isValidFrequentParkingNumber && (arrivalHour>=16 && arrivalHour<=24) ){
			price= (2*stayHours)/2;
		}
		else if(isValidFrequentParkingNumber && (arrivalHour>=8 && arrivalHour<=16)){
			price= (3*stayHours)-(0.1*(2*stayHours));
		}
		else if(arrivalHour>=8 && arrivalHour<=16){
			price= 3*stayHours;
		}
		else if(arrivalHour>=16 && arrivalHour<=24){
			price= 2*stayHours;
		}
	}
	
}


int main(){
	char check;
	string day="Sunday";
	int arrivalHour;
	int stayHours;
	int parkingNumber;
	int cost=0;
	int amountPaid=0;
	int totalPaymentOfDay=0;
	string dayChange;
	 
	
	do{
		dayChange=day;
		cout<<"Enter day of week"<<endl;
		cin>>day;
		
		cout<<"Enter hour of arrival 0-24"<<endl;
		cin>>arrivalHour;
		cout<<"Enter number of hours to park"<<endl;
		cin>>stayHours;
		cout<<"Enter frequent parking number if available or 0 if none"<<endl;
		cin>>parkingNumber;
		cost=priceToPark(day,arrivalHour,stayHours,parkingNumber);
		cout<<"Your amount is "<<cost<<endl;
		cout<<"Enter amount paid"<<endl;
		cin>>amountPaid;
		if(dayChange!=day){
			cout<<"Next day started"<<endl;
			totalPaymentOfDay=0;
		}
		if(amountPaid==cost ){
			totalPaymentOfDay+=amountPaid;
		}
		
		
		cout<<"Another customer Y/N"<<endl;
		
		cin>>check;
		
	}while(check=='Y' || check=='y');
	
	cout<<"Total payment of the day is "<<totalPaymentOfDay<<endl;
	
}


