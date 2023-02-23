#include "heap.h"
#include <iostream>

int main() {
	Heap<int> heap(2);
	
	for (int i = 0; i < 20; i++){heap.push(i);}
	
	for (int i = 0; i < 20; i++){
	std::cout << "top: "<<heap.top() << std::endl;
	heap.pop();
	}
	
	return 0;
}