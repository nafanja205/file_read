

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

std::string split(std::string&, char);

void rek()
{

}

template<typename T, typename... T2>
void rek(T a, T2 ...  b)
{
	std::cout << a;
	rek(b...);
}


int main()
{
	
	std::fstream data("ip_filter.tsv", std::fstream::in);

	std::string buf;

	std::vector<std::string> mas_file;

	auto my = [](std::string& str, char delim) mutable->std::string {  str = str.substr(0, str.find(delim)); return  str; };

	while (std::getline(data, buf, '\n'))
	{
		
		my(buf, '\t');
		//buf = split(buf, '\t');
		

		mas_file.push_back(buf);

	}
	
	std::sort(mas_file.begin(), mas_file.end());

	rek(1, 2, 4, 6);
	

	return 0;
}

std::string split(std::string& str, char spl)
{
	return str.substr(0, str.find(spl));
}


