/*
 * COMP2011 (Fall 2020) Assignment 1: Binary Numbers
 *
 * Student name: FILL YOUR NAME HERE
 * Student ID: FILL YOUR STUDENT ID NUMBER HERE
 * Student email: FILL YOUR EMAIL HERE
 *
 * Note:
 * 1. You CANNOT define and use any arrays.
 * 2. You CANNOT define and use any global variables.
 * 3. You CANNOT use the static keyword.
 * 4. You CANNOT include any extra libraries other than iostream.
 * 5. You CANNOT use any bitwise operators: ~, ^, |, & (since they are not taught in this course).
 * 6. You CANNOT change the function headers of the functions given in the tasks.
 * 7. You CANNOT use any string operations.
 * 8. You can add helper functions.
 */

#include <iostream>

using namespace std;

// Task 1
int power(int num,int n){
    int output = 1;
    for(int j = 1; j<=n ; j++){
        output *= num;
    }
    return output;
}
int get_min_bits_length(int x)
{int n = 1;
    int binary = 2;
    if(x>-1){ 
        while(x>power(binary,n)-1){
                n++;
                if(n == 31){break;}
            }
    }else{
        while(x<-power(binary,n)){
                n++;
                if(n == 31){break;}
            }
    }
    return n+1;
}

// Task 2
int get_bit_positive(int x, int n)
{
int bit = 0;
int count = 0;
if(x<0 || n<0){
	return -1;
}else if(n >= get_min_bits_length(x)){
	return 0;
}else{
    while(count != n+1){
        bit = x%2;
		x = x/2;
        count++;
		}
	}
    return bit;
}

// Task 3
int get_bit_negative(int x, int n)
{int bit = 0;
int count = 0;
bool add_1 = false;
if(x>=0 || n<0){
	return -1;
}else if(n >= get_min_bits_length(x)){
	return 1;
}else{
while(count != n+1){
    bit=(!(x%2));
    x=x/2;
    if(count == 0){
        if(bit==1){
            bit=0;
            add_1 =true;
        }else{
            bit=1;
            add_1=false;
        }
    }else{
        if(bit==1 && add_1==true){
            bit=0;
        }else if(bit==0 && add_1==true){
            bit=1;
            add_1=false;
        }
    }
    count++;
    }
    return bit;
}
}

// Task 4
void print_2s_complement_representation(int x)
{int n = get_min_bits_length(x)-1;
if(x>=0){
	while(n>=0){
		cout<<get_bit_positive(x,n);
		n--;
	}
}else if(x<0){
	while(n>=0){
		cout<<get_bit_negative(x,n);
		n--;
	}
}
cout<<endl;
}

// Task 5
void print_addition_carry_out(int a, int b)
{int carry_out;
int diff = get_min_bits_length(a) - get_min_bits_length(b);
int bit_a, bit_b;
int max;
bool add_1 = false;
if(diff>=0){
    max = get_min_bits_length(a);
}else{
    max = get_min_bits_length(b);
}for(int j = max; j >= 1; j--){
    carry_out = 0;
    for(int i = 0; i<j; i++){
        if(a >= 0){
            bit_a = get_bit_positive(a,i);
        }else{
            bit_a = get_bit_negative(a,i);
        }if(b >= 0){
            bit_b = get_bit_positive(b,i);
        }else{
            bit_b = get_bit_negative(b,i);
        }
        if(bit_a == 0 && bit_b == 0){
            carry_out = 0;
        }else if(bit_a == 1 && bit_b == 1){
            carry_out = 1;
        }else if(bit_a == 1 && bit_b == 0){
            if(carry_out == 0){
            carry_out = 0;
            }else{
            carry_out = 1;
            }
        }else if(bit_a == 0 && bit_b == 1){
            if(carry_out == 0){
                carry_out = 0;
            }else{
                carry_out =1;
            }
        }
}
cout<<carry_out;
}
cout<<endl;
}

// DO NOT WRITE ANYTHING AFTER THIS LINE. ANYTHING AFTER THIS LINE WILL BE REPLACED

int main()
{
	while (true) {
		int option = 0;

		do {
			cout << "1. Task 1" << endl;
			cout << "2. Task 2" << endl;
			cout << "3. Task 3" << endl;
			cout << "4. Task 4" << endl;
			cout << "5. Task 5" << endl;
			cout << "0. Exit" << endl;
			cout << "Enter an option (0-5): ";
			cin >> option;
		} while (option < 0 || option > 5);
		
		if (option == 0)
			break;
		else if (option == 1) {
			int number;
			cout << "Enter a number: ";
			cin >> number;
			cout << number << " needs " << get_min_bits_length(number) << " bits." << endl;
		}
		else if (option == 2) {
			int number;
			int bit;

			cout << "Enter a number: ";
			cin >> number;

			cout << "Which bit? ";
			cin >> bit;
			
			cout << "The number " << bit << " bit of " << number << " is " << get_bit_positive(number, bit) << endl;
		}
		else if (option == 3) {
			int number;
			int bit;

			cout << "Enter a number: ";
			cin >> number;

			cout << "Which bit? ";
			cin >> bit;
			
			cout << "The number " << bit << " bit of " << number << " is " << get_bit_negative(number, bit) << endl;
		}
		else if (option == 4) {
			int number;
			cout << "Enter a number: ";
			cin >> number;
			cout << "The 2's complement representation of " << number << " is:" << endl;
			print_2s_complement_representation(number);
		}
		else if (option == 5) {
			int a, b;
			cout << "Enter number A: ";
			cin >> a;
			cout << "Enter number B: ";
			cin >> b;
			cout << "The sum of " << a << " and " << b << " is " << a + b << ". The carry bits are:" << endl;
			print_addition_carry_out(a, b);
		}

		cout << endl;
	}

	return 0;
}