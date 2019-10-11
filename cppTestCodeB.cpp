#include <iostream>
#include <typeinfo>
using namespace std;



class testClass 
{

	public:
    const char* name;
    const char* iiname;
	int age;
	testClass() { name = __func__; };
	testClass(char* inssf) { name = __func__; iiname = inssf; };
	testClass(char* inssf, int a) {age = a; name = __func__; iiname = inssf;};
	testClass operator* (testClass);
};

testClass testClass::operator*(testClass ood)
{

	testClass testClassNew;

	testClassNew.age = ood.age + age;

	cout << name << " " << iiname  << " " << ood.iiname << endl;

	return testClassNew;
}

int main(void)
{
    testClass a((char*)"a", 10);
    testClass b((char*)"b", 20);

    testClass c((char*)"c");
    c = a*b;
    c.iiname = (char*)"c";


    cout << a.age << " " << b.age  << " " << c.age << " "<< c.iiname << endl;
	return 0;
}
