#include <iostream>

using namespace std;


class testClass {
public:
	int data;
	testClass() {};
    testClass(int x) {data = x;}
    testClass operator+ (testClass);
};

testClass testClass::operator+ (testClass tre)
{

	testClass newtestClass;
 
    newtestClass.data = data + tre.data;

	return newtestClass;
}


int main()
{

   testClass A(100);
   testClass B(200);

   testClass C;


   C = A + B;

   cout << C.data << endl;


	return 0;

}