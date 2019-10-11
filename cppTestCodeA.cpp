#include <iostream>

using namespace std;

class OperatorOverloadingExample
{

public:
	int num;
	OperatorOverloadingExample(void);
	OperatorOverloadingExample(int);
	OperatorOverloadingExample operator+(OperatorOverloadingExample);
};

OperatorOverloadingExample::OperatorOverloadingExample(void)
{

}

OperatorOverloadingExample::OperatorOverloadingExample(int a)
{
	num = a;
}

OperatorOverloadingExample OperatorOverloadingExample::operator+ (OperatorOverloadingExample osf)
{
	OperatorOverloadingExample OperatorOverloadingExampleNew;

	OperatorOverloadingExampleNew.num = num + osf.num;

	return OperatorOverloadingExampleNew;

}


int main()
{

    OperatorOverloadingExample inst_a(34);
    OperatorOverloadingExample inst_b(50);

    OperatorOverloadingExample inst_c;

    inst_c = inst_a + inst_b;

    cout << inst_c.num << endl;

	return 0;
}


