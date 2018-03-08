#include "DynArray.hh"

DynArray::DynArray()
{
	data = new int[DYN_ARRAY_DEFAULT_SIZE];
	DynArray::m_capacity = DYN_ARRAY_DEFAULT_SIZE;
	DynArray::m_size = 0;
}

DynArray::DynArray(size_t size)
{
	data = new int[size];
	DynArray::m_capacity = size;
	DynArray::m_size = 0;
}

DynArray::DynArray(size_t size, const int & value)
{
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = value;
	}
	DynArray::m_size = size;
	DynArray::m_capacity = size;
}

int * DynArray::begin()
{

	return &data[0];
}

int * DynArray::end()
{
	return &data[m_size-1];
}

void DynArray::resize(size_t n)
{
	data = new int[n];
	DynArray::m_size = n;
}

void DynArray::reserve(size_t n)
{
	DynArray::m_capacity = n;
}

void DynArray::shrink()
{

}

bool DynArray::empty()
{
	return false;
}

size_t DynArray::capacity()
{
	return size_t();
}

size_t DynArray::size()
{
	return size_t();
}

size_t DynArray::maxSize()
{
	return size_t();
}

int & DynArray::operator[](size_t n)
{
	// TODO: insert return statement here
}

int & DynArray::at(size_t n)
{
	// TODO: insert return statement here
}

int & DynArray::front()
{
	// TODO: insert return statement here
}

int & DynArray::back()
{
	// TODO: insert return statement here
}

void DynArray::push(const int & val)
{
}

void DynArray::pop()
{
}

void DynArray::insert(size_t position, const int & val)
{
}

void DynArray::erase(size_t position)
{
}

void DynArray::erase(size_t first, size_t last)
{
}

void DynArray::clear()
{
}

void DynArray::fill(int * first, int * last, int value)
{
}

void DynArray::copy(int * first, int * last, int * dest)
{
}

void DynArray::print()
{
}
