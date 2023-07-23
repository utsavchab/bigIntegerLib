#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

class bigInt {
	
	private:
	string data;
	bool isNeg;
	
	bigInt subtractHelper(const bigInt &b1, const bigInt &b2){ // return b1 - b2 
		int ptrB1 = b1.data.length() - 1;
		int ptrB2 = b2.data.length() - 1;
		int borrow = 0;
		bigInt newNum;
		newNum.data = "";
		while(ptrB1 >= 0 && ptrB2 >= 0){
			int diff = (b1.data[ptrB1] - '0') - (b2.data[ptrB2] - '0') - borrow;
			if(diff < 0){
				borrow = 1;
				diff = diff + 10;
			}else{
				borrow = 0;
			}
			char currDigit = diff + '0';
			newNum.data = currDigit + newNum.data;
			ptrB1--;
			ptrB2--;
		}
		
		// handle remaining digits in B1 if any
		while(ptrB1 >= 0){
			int diff = (b1.data[ptrB1] - '0') - borrow;
			if(diff < 0){
				borrow = 1;
				diff = diff + 10;
			}else{
				borrow = 0;
			}
			char currDigit = diff + '0';
			newNum.data = currDigit + newNum.data;
			ptrB1--;
		}

		//delete leading zeros
		int i = 0;
		while(i < newNum.data.length() && newNum.data[i] == '0'){
			i++;
		}
		newNum.data = newNum.data.substr(i);
		if(newNum.data.length() == 0){
			newNum.data = "0";
		}
		
		return newNum;
	}
	bigInt abs(const bigInt &num){
		bigInt newNum;
		newNum.data = num.data;
		newNum.isNeg = false;
		return newNum;
	}

	bigInt magnitudeSubtract(const bigInt &b1, const bigInt &b2){
		bigInt newNum;
		if(b1 == b2){
			return newNum;
		}else{			
			if(abs(b1) > abs(b2)){
				if(b2 == "0"){
					newNum = b1;
					return newNum;
				}
				else if(b2.isNeg){
					newNum = subtractHelper(b1,b2);
					newNum.isNeg = true;
					return newNum;
				}else{
					return newNum = subtractHelper(b1,b2);
				}
			}else{
				if(b1 == "0"){
					newNum.data = b2.data;
					if(b2.isNeg){
						newNum.isNeg = false;
					}else{
						newNum.isNeg = true;
					}
					return newNum;
				}
				if(b1.isNeg){
					newNum = subtractHelper(b2,b1);
					newNum.isNeg = true;
					return newNum;
				}else{
					newNum = subtractHelper(b2,b1);
					newNum.isNeg = true;
					return newNum;
				}
			}
		}
		
	}
	
	bigInt add(const bigInt &b1, const bigInt &b2){ 
		bigInt newNum;
		newNum.isNeg = b1.isNeg;
		newNum.data = "";

		string b1Data = b1.data;
		string b2Data = b2.data;

		int ptrB1 = b1Data.size() - 1;
		int ptrB2 = b2Data.size() - 1;

		int carry = 0;
		while(ptrB1 >= 0 && ptrB2 >= 0){
			int sum = (b1Data[ptrB1] - '0') + (b2Data[ptrB2] - '0') + carry;
			if(sum >= 10){
				carry = 1;
				sum = sum % 10;
			}else{
				carry = 0;
			}
			char currDigit = sum + '0';
			newNum.data = currDigit + newNum.data;
			ptrB1--;
			ptrB2--;
		}

		while(ptrB1 >= 0){
			int sum = (b1Data[ptrB1] - '0') + carry;
			if(sum >= 10){
				carry = 1;
				sum = sum % 10;
			}else{
				carry = 0;
			}
			char currDigit = sum + '0';
			newNum.data = currDigit + newNum.data;
			ptrB1--;
		}

		while(ptrB2 >= 0){
			int sum = (b2Data[ptrB2] - '0') + carry;
			if(sum >= 10){
				carry = 1;
				sum = sum % 10;
			}else{
				carry = 0;
			}
			char currDigit = sum + '0';
			newNum.data = currDigit + newNum.data;
			ptrB2--;
		}

		if(carry){
			char currDigit = carry + '0';
			newNum.data = currDigit + newNum.data;
		}

		return newNum;
	}

	bigInt multiply(const bigInt &b1, const bigInt &b2){
		bigInt newNum;
		newNum.data = "0";
		newNum.isNeg = false;

		string b1Data = b1.data;
		string b2Data = b2.data;

		int ptrB1 = b1Data.size() - 1;
		int ptrB2 = b2Data.size() - 1;

		int carry = 0;
		while(ptrB1 >= 0){
			string currNum = "";
			for(int i = 0; i < b1Data.size() - 1 - ptrB1; i++){
				currNum += '0';
			}
			carry = 0;
			ptrB2 = b2Data.size() - 1;
			while(ptrB2 >= 0){
				int sum = (b1Data[ptrB1] - '0') * (b2Data[ptrB2] - '0') + carry;
				if(sum >= 10){
					carry = sum / 10;
					sum = sum % 10;
				}else{
					carry = 0;
				}
				char currDigit = sum + '0';
				currNum = currDigit + currNum;
				ptrB2--;
			}
			if(carry){
				char currDigit = carry + '0';
				currNum = currDigit + currNum;
			}
			bigInt temp = currNum;
			newNum = add(newNum, temp);
			ptrB1--;
		}

		if((b1.isNeg && !b2.isNeg) || (!b1.isNeg && b2.isNeg)){
			newNum.isNeg = true;
		}

		return newNum;
	}

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
	

	bigInt divide(const bigInt &a,const  bigInt &b)
    {
		bigInt temp;
		if(a<b){	
			return temp;
		}
		temp = a;
		bigInt newNum;
	
		while(temp - b >= "0"){
			temp = temp - b;
			newNum = newNum + "1";
		}

		return newNum;
    }

public:

	/* Constructors */

	bigInt(){ // By default bigInt variable is initialized to 0;
		this->data = "0";
		this->isNeg = false;
	}

	bigInt(const char* num){ // char string to bigInt
		this->data = createValid((string)num);	
	}

	bigInt(long long int num){ // integer to bigInt
		this->data = createValid((string)to_string(num));
	}

	bigInt(const bigInt &num){ // bigInt to bigInt
		this->data = num.data;
		this->isNeg = num.isNeg;
	}

	bigInt(string num){
		this->data = createValid(num);
	}


	/* Comparison Opertions*/
	friend const bool operator == (const bigInt &b1, const bigInt &b2);
	friend const bool operator > (const bigInt &b1, const bigInt &b2);
	friend const bool operator >= (const bigInt &b1, const bigInt &b2);
	friend const bool operator < (const bigInt &b1, const bigInt &b2);
	friend const bool operator <= (const bigInt &b1, const bigInt &b2);
	friend const bool operator != (const bigInt &b1, const bigInt &b2);
	const bool operator ! (){
		if(this->data == "0"){
			return true;
		}else{
			return false;
		}
	}

	/* Arithmetic Operations */

	bigInt operator + (const bigInt &num){ // adding two bigint numbers
		bigInt newNum;
		if((!this->isNeg && !num.isNeg) || (this->isNeg && num.isNeg)){
			newNum = add(*this, num);
			return newNum;
		}else {
			newNum = magnitudeSubtract(*this, num);
			return newNum;
		}
	}

	bigInt operator - (const bigInt &num){
		bigInt newNum;
		if((!this->isNeg && !num.isNeg) || (this->isNeg && num.isNeg)){
			// cout << "here" << '\n';
			newNum = magnitudeSubtract(*this, num);
			return newNum;
		}else {
			newNum = add(*this, num);
			return newNum;
		}
	}
	bigInt operator * (const bigInt &num){
		return multiply(*this, num);
	}

	bigInt operator / (const bigInt &num){
		return divide(*this, num);
	}

	
	// Input Output Operations
	void getData(){
		string num; cin >> num;
		data = createValid(num);
	}
	
	friend const ostream & operator << (ostream &out, const bigInt &a);
	friend  istream & operator >> (istream &in, bigInt &a);

};

const bool operator == (const bigInt &b1, const bigInt &b2 ){
	if(b1.isNeg != b2.isNeg){
		return false;
	}else{
		return (b1.data == b2.data);
	}
}

const bool operator > (const bigInt &b1, const bigInt &b2){

	if(b1.isNeg && !(b2.isNeg)){ // negative > positive
		return false;
	}else if(!(b1.isNeg) && b2.isNeg){ // positive > negative
		return true;
	}else if(!(b1.isNeg) && !(b2.isNeg)){ //  positive > positive
		if(b1.data.length() > b2.data.length()){
			return true;
		}else if(b1.data.length() < b2.data.length()){
			return false;
		}else{
			return (b1.data > b2.data);
		}
	}else{ //  negative > negative
		if(b1.data.length() < b2.data.length()){
			return true;
		}else if(b1.data.length() > b2.data.length()){
			return false;
		}else{
			return (b1.data < b2.data);
		}
	}

}

const bool operator >= (const bigInt &b1, const bigInt &b2){

	if(b1.isNeg && !(b2.isNeg)){ // negative >= positive
		return false;
	}else if(!(b1.isNeg) && b2.isNeg){ // positive >= negative
		return true;
	}else if(!(b1.isNeg) && !(b2.isNeg)){ // positive >= positive
		if(b1.data.length() > b2.data.length()){
			return true;
		}else if(b1.data.length() < b2.data.length()){
			return false;
		}else{
			return (b1.data >= b2.data);
		}
	}else{ 									// negative >= negative
		if(b1.data.length() < b2.data.length()){
			return true;
		}else if(b1.data.length() > b2.data.length()){
			return false;
		}else{
			return (b1.data <= b2.data);
		}
	}
		
}

const bool operator < (const bigInt &b1, const bigInt &b2){

	if(b1.isNeg && !(b2.isNeg)){ // negative < positive
		return true;
	}else if(!(b1.isNeg) && b2.isNeg){ // positive < negative
		return false;
	}else if(!(b1.isNeg) && !(b2.isNeg)){ //  positive < positive
		if(b1.data.length() < b2.data.length()){
			return true;
		}else if(b1.data.length() > b2.data.length()){
			return false;
		}else{
			return (b1.data < b2.data);
		}
	}else{ // negative < negative
		if(b1.data.length() > b2.data.length()){
			return true;
		}else if(b1.data.length() < b2.data.length()){
			return false;
		}else{
			return (b1.data > b2.data);
		}
	}

}

const bool operator <= (const bigInt &b1, const bigInt &b2){

	if(b1.isNeg && !(b2.isNeg)){ // negative <= positive
		return true;
	}else if(!(b1.isNeg) && b2.isNeg){ // positive <= negative
		return false;
	}else if(!(b1.isNeg) && !(b2.isNeg)){ //  positive <= positive
		if(b1.data.length() < b2.data.length()){
			return true;
		}else if(b1.data.length() > b2.data.length()){
			return false;
		}else{
			return (b1.data <= b2.data);
		}
	}else{ // negative <= negative
		if(b1.data.length() > b2.data.length()){
			return true;
		}else if(b1.data.length() < b2.data.length()){
			return false;
		}else{
			return (b1.data >= b2.data);
		}
	}

}

const bool operator != (const bigInt &b1, const bigInt &b2){
	return !(b1 == b2);
}

const ostream & operator << (ostream &out, const bigInt &a){
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
};