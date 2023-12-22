#include "iter.tpp"

template <typename T>
void print(T &x)
{
	std::cout << "T: " << x << std::endl;
	return;
}

int main(void) {
	int arrayInt[] = {0, 1, 2, 3, 4, 5};
	float arrayFloat[] = {0.2f, 1.3f, 2.4f, 3.5f, 4.6f, 5.7f};
	double arrayDouble[] = {0.2, 1.3, 2.4, 3.5, 4.6, 5.7};
	std::string arrayString[] = {"yakup", "acis", "hello", "world"};

	iter(arrayInt, 6, print<int>);
	iter(arrayFloat, 6, print<float>);
	iter(arrayDouble, 6, print<double>);
	iter(arrayString, 4, print<std::string>);

	return (0);
}