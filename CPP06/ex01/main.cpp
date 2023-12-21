#include "Serialization.hpp"


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
