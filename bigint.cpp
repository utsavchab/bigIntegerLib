#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

class bigInt {
public:

	string data;
	bool isNeg;
	
	bool isDigit(char s){
		if('0' <= s && s <= '9'){
			return true;
		}else{
			return false;
		}
	}

	string createValid(string num){

		if(num.length() != 0){

			if(num[0] == '-'){
				isNeg = true;
				num = num.substr(1);
			}else if(num[0] == '+'){
				isNeg = false;
				num = num.substr(1);
			}else{
				isNeg = false;
			}

			// checking if num is a valid number
			bool isNumber = true;
			for(int i = 0; i < num.length(); i++){
				if(!isDigit(num[i])){
					isNumber = false;
					break;
				}
			}
			assert(isNumber);

			// Removing leading zeros
			int i = 0;
			while(i < num.length() && num[i] == '0'){
				i++;
			}
			num = num.substr(i);
			if(num.length() == 0){
				num = "0";
				isNeg = false;
			}

		}else{ // Initializing num to zero;
			num = "0";
			isNeg = false;
		}
		return num;
	}
public:

	/* Constructors */

	bigInt(){ // By default bigInt variable is initialized to 0;
		this->data = "0";
		this->isNeg = false;
	}

	bigInt(const char*num){ // char string to bigInt
		this->data = createValid((string)num);	
	}

	bigInt(long long int num){ // integer to bigInt
		this->data = createValid((string)to_string(num));
	}

	bigInt(const bigInt &num){ // bigInt to bigInt
		this->data = num.data;
		this->isNeg = num.isNeg;
	}


	/* Comparison Opertions*/

	bool operator == (const bigInt &num){
		if(this->isNeg != num.isNeg){
			return false;
		}else{
			return (this->data == num.data);
		}
	}

	bool operator > (const bigInt &num){

		if(this->isNeg && !(num.isNeg)){ // negative > positive
			return false;
		}else if(!(this->isNeg) && num.isNeg){ // positive > negative
			return true;
		}else if(!(this->isNeg) && !(num.isNeg)){ //  positive > positive
			if(this->data.length() > num.data.length()){
				return true;
			}else if(this->data.length() < num.data.length()){
				return false;
			}else{
				return (this->data > num.data);
			}
		}else{ //  negative > negative
			if(this->data.length() < num.data.length()){
				return true;
			}else if(this->data.length() > num.data.length()){
				return false;
			}else{
				return (this->data < num.data);
			}
		}

	}

	bool operator >= (const bigInt &num){

		if(this->isNeg && !(num.isNeg)){ // negative >= positive
			return false;
		}else if(!(this->isNeg) && num.isNeg){ // positive >= negative
			return true;
		}else if(!(this->isNeg) && !(num.isNeg)){ // positive >= positive
			if(this->data.length() > num.data.length()){
				return true;
			}else if(this->data.length() < num.data.length()){
				return false;
			}else{
				return (this->data >= num.data);
			}
		}else{ 									// negative >= negative
			if(this->data.length() < num.data.length()){
				return true;
			}else if(this->data.length() > num.data.length()){
				return false;
			}else{
				return (this->data <= num.data);
			}
		}
		
	}

	bool operator < (const bigInt &num){

		if(this->isNeg && !(num.isNeg)){ // negative < positive
			return true;
		}else if(!(this->isNeg) && num.isNeg){ // positive < negative
			return false;
		}else if(!(this->isNeg) && !(num.isNeg)){ //  positive < positive
			if(this->data.length() < num.data.length()){
				return true;
			}else if(this->data.length() > num.data.length()){
				return false;
			}else{
				return (this->data < num.data);
			}
		}else{ // negative < negative
			if(this->data.length() > num.data.length()){
				return true;
			}else if(this->data.length() < num.data.length()){
				return false;
			}else{
				return (this->data > num.data);
			}
		}

	}

	bool operator <= (const bigInt &num){

		if(this->isNeg && !(num.isNeg)){ // negative <= positive
			return true;
		}else if(!(this->isNeg) && num.isNeg){ // positive <= negative
			return false;
		}else if(!(this->isNeg) && !(num.isNeg)){ //  positive <= positive
			if(this->data.length() < num.data.length()){
				return true;
			}else if(this->data.length() > num.data.length()){
				return false;
			}else{
				return (this->data <= num.data);
			}
		}else{ // negative <= negative
			if(this->data.length() > num.data.length()){
				return true;
			}else if(this->data.length() < num.data.length()){
				return false;
			}else{
				return (this->data >= num.data);
			}
		}

	}

	bool operator != (const bigInt &num){
		return !(*this == num);
	}

	bool operator ! (){
		if(this->data == "0"){
			return true;
		}else{
			return false;
		}
	}

	/* Arithmetic Operations */

	bool operator + (const bigInt &num){

	}





	// Input Output Operations
	void getData(){
		string num; cin >> num;
		data = createValid(num);
	}
	friend ostream & operator << (ostream &out, const bigInt &a);
	friend istream & operator >> (istream &in, bigInt &a);

};

ostream & operator << (ostream &out, const bigInt &a){
	if(a.isNeg){
		out << '-' << a.data;
	}else{
		out << a.data;
	}
	return out;
}
istream & operator >> (istream &in, bigInt &a){
	string num;
	in >> num;
	a.data = a.createValid(num);
	return in;
}


int main(){

	bigInt a;
	cin >> a;
	cout << a << '\n';
	int b = 1000;
	bigInt c = 1e18;
	bigInt d = "2342342344254234";

	cout << (a == "-10") << '\n';



}