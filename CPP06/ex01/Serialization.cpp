#include <iostream>

struct Data {
    int value;
};

class Serializer {
private:
    Serializer() {}
	Serializer(Serializer const &other) {(void)other;}
	Serializer &operator=(Serializer const &other) {(void)other; return *this;}
	~Serializer() {}

public:
    static uintptr_t serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }

    static Data* deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    }
};

int main() {
    Data myData;
	myData.value = 42;

    uintptr_t serializedValue = Serializer::serialize(&myData);

    Data* deserializedData = Serializer::deserialize(serializedValue);

    if (deserializedData == &myData) {
        std::cout << "Serialization and deserialization successful." << std::endl;
        std::cout << "Original Data value: " << myData.value << std::endl;
        std::cout << "Deserialized Data value: " << deserializedData->value << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed." << std::endl;
    }

    return 0;
}
