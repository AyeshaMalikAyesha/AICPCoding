#include <iostream>
using namespace std;
	int c,g,s;
bool check_sack(char ch,float weight){
	if((ch=='S'||ch=='s') ){
		if(weight>=49.9 && weight<=50.1){
			cout<<"Sack of sand accepted\n";
			return true;
		}
		
	}
	else if((ch=='G'||ch=='g')){
		if(weight>=49.9 && weight<=50.1){
			cout<<"Sack of gravel accepted\n";
			return true;
		}
	
	}
	else if((ch=='C'||ch=='c')){
		if(weight>=24.9 && weight<=25.1){
			cout<<"Sack of cement accepted\n";
			return true;
		}
		
	}
	return false;
}

void order(float cem[],float sand[],float gravel[]){
	int rejected=0;
	float total_weight=0.0;
	for(int i=0;i<c;i++){
		if(check_sack('c',cem[i])){
			cout<<"price of cement is "<<cem[i]<<endl;
			total_weight+=cem[i];
		}
		else{
		    rejected++;
			c--;
		}
	}
	for(int i=0;i<s;i++){
		if(check_sack('s',sand[i])){
			total_weight+=sand[i];
		}
		else{
			rejected++;
			s--;
		}
	}
	for(int i=0;i<g;i++){
		if(check_sack('c',gravel[i])){
			total_weight+=gravel[i];
		}
		else{
			rejected++;
			g--;
		}
	}
	cout<<"The total weight of the order is "<<total_weight<<endl;
	cout<<"The number of sacks rejected from the order is "<<rejected++<<endl;
	if(c==1 && s==2 && g==2){
		cout<<"The price is $10"<<endl;
	}
}

//calculating price
int price(int c,int s,int g){
	return c*3+s*2+g*2;
}
int main(){

    cout<<"Enter number of sacks required for cement\n";
    cin>>c;
    float cement[c];
    for(int i=0;i<c;i++){
    	cout<<"Enter weight for cement sack number "<<i+1<<endl;
    	cin>>cement[i];
    		if(cement[i]<24.9){
			cout<<"Sack of cement is underweight\n";
		}
		else if(cement[i]>25.1){
			cout<<"Sack of cement is overweight\n";
		}
	}
	  cout<<"Enter number of sacks required for gravel\n";
    cin>>g;
    float gravel[g];
    for(int i=0;i<g;i++){
    	cout<<"Enter weight for gravel sack number "<<i+1<<endl;
    	cin>>gravel[i];
    	if(gravel[i]<49.9){
			cout<<"Sack of gravel is underweight\n";
		}
		else if(gravel[i]>50.1){
			cout<<"Sack of gravel is overweight\n";
		}
	}
	  cout<<"Enter number of sacks required for sand\n";
    cin>>s;
    float sand[s];
    for(int i=0;i<s;i++){
    	cout<<"Enter weight for sand sack number "<<i+1<<endl;
    	cin>>sand[i];
    	if(sand[i]<49.9){
			cout<<"Sack of sand is underweight\n";
		}
		else if(sand[i]>50.1){
			cout<<"Sack of sand is overweight\n";
		}
	}
	order(cement,sand,gravel);
	
	//now calculate price


	
	cout<<"The total price is "<<price(c,s,g);

	
	return 0;
}
