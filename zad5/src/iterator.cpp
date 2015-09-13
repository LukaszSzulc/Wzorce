#include <iostream>

template <typename type>
class Iterator
{
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual type CurrentElement() = 0;
protected:
	Iterator() {}
};

template <typename type>
class EverySecondIterator : public Iterator<type>
{
private:
	const type* array;
	int length;
	int index;
public:
	EverySecondIterator(type* _array, int _length)
	{
		array = _array;
		length = _length;
	}
	void First()
	{
		index = 1;
	}
	void Next()
	{
		index += 2;
	}
	bool IsDone()
	{
		return index >= length - 1;
	}
	type CurrentElement()
	{
		return array[index];
	}


protected:
	EverySecondIterator() {}
};

template <typename type>
class ReversedIterator : public Iterator<type>
{
private:
	const type* array;
	int length;
	int index;
public:
	ReversedIterator(type* _array, int _length)
	{
		array = _array;
		length = _length;
	}
	void First()
	{
		index = length - 1;
	}
	void Next()
	{
		index--;
	}
	bool IsDone()
	{
		return index < 0;
	}
	type CurrentElement()
	{
		return array[index];
	}


protected:
	ReversedIterator() {}
};

template <typename type>
class IterableArray
{
private:
	type* array;
	int length;
public:
	IterableArray(type* _array, int _length)
	{
		array = _array;
		length = _length;
	}
	type &operator[](int i)
	{
		return array[i];
	}
	EverySecondIterator<type>* CreateEverySecondIterator()
	{
		return new EverySecondIterator<type>(array, length);
	}
	ReversedIterator<type>* CreateReversedIterator()
	{
		return new ReversedIterator<type>(array, length);
	}
protected:
	IterableArray() {}
};


int main()
{
	int sampleTable[10] = { 1,2,3,4,5,6,7,8,9,0 };
	IterableArray<int> iterators(sampleTable, 10);

	auto reversed = iterators.CreateReversedIterator();
	reversed->First();
	while (!reversed->IsDone())
	{
		std::cout << reversed->CurrentElement();
		reversed->Next();
	}
        std::cout << "\n";

	std::cout << "Show n+2 element\n";
	auto secondElements = iterators.CreateEverySecondIterator();
	secondElements->First();
	while (!secondElements->IsDone())
	{
		std::cout << secondElements->CurrentElement();
		secondElements->Next();
	}
        std::cout << "\n";
	return 0;
}
