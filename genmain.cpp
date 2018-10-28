#include <iostream>
#include <fstream>  


int main(int argc, const char* argv[])
{
	std::cout << argc << " " << argv[1] << std::endl;


	std::ofstream outfile (argv[1]);

	outfile << "#include <iostream>" << std::endl;

	outfile << std::endl;
	outfile << std::endl;

	outfile << "using namespace std;" << std::endl;

	outfile << std::endl;
	outfile << std::endl;

	outfile << "int main(int argc, const char* argv[])" << std::endl;
	outfile << "{" << std::endl;

	outfile << "    return 0;" << std::endl;

	outfile << "}" << std::endl;

	outfile.close();

	return 0;
}
