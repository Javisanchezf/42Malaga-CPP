#pragma once
#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

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

#endif