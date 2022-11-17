#pragma once

class Container
{
public:
	int * data;
};

template<typename T>
class TContainer
{
public:
	T * data;

	// don't actually write this in production
	void SetData(T * newData);
};

template<typename T>
void TContainer<T>::SetData(T * newData)
{
	data = newData;
}
