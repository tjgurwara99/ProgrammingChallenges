#include<iostream>
// I want to allocate this memory in stack not heap so I will be doing it with 
// standard c++ array class
#include<array>

#define SIZE 1000

struct _1000digit {
	std::array<int, SIZE> data;

	_1000digit(){
		for(int i=0; i<SIZE; ++i){
			this->data[i] = 0;
		}
	}

	_1000digit& operator=(_1000digit a) { this->data=_1000digit(a).data; return *this;}

	_1000digit& operator=(int a) {
		int i=SIZE-1;
		while(SIZE - 1 - i != SIZE - 1) {
			data[i] = a%10;
			a /=10 ;
			--i;
		}
		return *this;
	}
	_1000digit operator+(const _1000digit& a) {
		_1000digit arr;
		for (int i=SIZE-1; i>=0; --i){
			int temp = this->data[i] + a.data[i];
			int tens = temp/10;
			temp = temp%10;
			arr.data[i] += temp;
			arr.data[i-1] = tens;
		}
		return arr;
	}

	void print(){

		for(int i = 0; i< SIZE; ++i){
			std::cout<<this->data[i];
		}
	}
};


int main(){
	_1000digit arr, arr2, arr3;
	arr = 1;
	arr2 = 1;
	
	int count = 2;
	while(arr3.data[0]==0){
		arr3 = arr + arr2;
		arr = arr2;
		arr2 = arr3;
		count++;
	}
	std::cout<<count<<std::endl;
	arr3.print();
	return 0;
}


