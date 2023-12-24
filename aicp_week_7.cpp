#include <iostream>
using namespace std;
  double charity_total[3];
  string charity_choices[3];
void set_charity_choices(){
	
	for(int i=0;i<3;i++){
		cout<<"Enter name of charity "<<i+1<<endl;
		cin>>charity_choices[i];
	}
	for(int i=0;i<3;i++){
		cout<<i+1<<". "<<charity_choices[i]<<endl;
	}
	for(int i=0;i<3;i++){
		charity_total[i]=0.0;
	}
}

void calculate_charity(int ch,double bill){
	
	charity_total[ch-1]+=0.01*bill;
	cout<<"The name of charity is "<<charity_choices[ch-1]
	<<" and the amount donated is "<<0.01*bill<<endl;
}

void show_total() {
    // Display totals in descending order
    cout << "\nCharities and Totals (Descending Order):" << endl;
    for (int i = 0; i <3;i++) {
        int maxIndex = 0;
        for (int j = 1; j <3;j++) {
            if (charity_total[j] > charity_total[maxIndex]) {
                maxIndex = j;
            }
        }
        cout << charity_choices[maxIndex] << ": " << charity_total[maxIndex] << endl;
        charity_total[maxIndex] = -1.0; 
    }

    // Calculate and display grand total
    double grandTotal = 0.0;
    for (int i = 0; i < 3; i++) {
        grandTotal += charity_total[i];
    }
    cout << "\nGRAND TOTAL DONATED TO CHARITY: " << grandTotal << endl;
}


int main(){
  int choice,idx=1;
  double bill;
  //set the donation system
  set_charity_choices();
  
  cout<<"Enter choice (1,2,3) to which charity you want to donate or -1 to check the totals so far\n";
  cin>>choice;
 while(choice>=1 && choice<=3){
  cout<<"Welcome customer number "<<idx++<<endl;
  cout<<"Enter bill\n";
  cin>>bill;
   //calculate charity
  calculate_charity(choice,bill);
  cout<<"Enter choice again\n";
  cin>>choice;
 
}

//show the totals 
show_total();
  
  	
}
