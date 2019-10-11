#include <iostream>

using namespace std;

class myClass
{
    public:
    	int age;
    	myClass() {};
    	myClass(int a) {age = a;};
        myClass operator- (myClass);

};


myClass myClass::operator- (myClass odf)
{

	myClass newClass;
    newClass.age = age - odf.age;

	return newClass;
}

int main()
{
    myClass a(300);
    myClass b(50);

    myClass c;

    c = a - b;

    cout << c.age << endl;

	return 0;
}