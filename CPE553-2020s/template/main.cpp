#include <iostream>

int main(int argc, char **argv)
{

	int sum = 0;
	for (int i = 1; i < argc; ++i)
	{
		int num_i = atoi(argv[i]);  // 字符串转换成整数
		sum += num_i;
	}
	std::cout << sum;

	return 0;
}