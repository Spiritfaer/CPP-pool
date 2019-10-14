#include <iostream>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

void* serialize(void) {
	Data *ref = new Data;
	std::srand(std::time(nullptr));
	int cof = 1;
	std::string buff;

	for (int i = 65; i < 128; ++i) {
		if (isalpha(static_cast<char>(i)))
			buff += static_cast<char>(i);
		ref->n = i;
	}

	for (int i = 0; i < 8; ++i) {
		ref->s1 += buff[(rand() * ++cof) % buff.length()];
	}

	for (int i = 0; i < 8; ++i) {
		ref->s2 += buff[(rand() * ++cof) % buff.length()];
	}

	ref->n = (rand() * std::time(nullptr)) % buff.length();

	return reinterpret_cast<void*>(ref);
}

Data* deserialize(void *raw) {
	return reinterpret_cast<Data*>(raw);
}

int main()
{
	void *ser = serialize();
	Data *data = deserialize(ser);

	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;

	return 0;
}
