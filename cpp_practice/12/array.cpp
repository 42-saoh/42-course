#include <iostream>

class Array;
class Int;

class Array {
	private:
		int			*size;
		const int	dim;

		struct	Address
		{
			int	level;
			void *next;
		};
		Address		*top;
		friend class Int;
	
	public:
		class Iterator
		{
			private:
				int		*location;
				Array	*arr;

			public:
				Iterator(Array *arr, int *loc = NULL) : arr(arr){
					location = new int[arr->dim];
					for (int i = 0; i != arr->dim; i++)
						location[i] = (loc != NULL ? loc[i] : 0);
				}
				Iterator(const Iterator &itr) : arr(itr.arr) {
					location = new int[arr->dim];
					for (int i = 0; i < arr->dim; i++)
						location[i] = itr.location[i];
				}
				~Iterator() { delete[] location; }
				Iterator	&operator++(void)
				{
					if (location[0] >= arr->size[0])
						return (*this);
					bool carry = true;
					int i = arr->dim - 1;
					while (i >= 0 && carry)
					{
						location[i]++;
						if (location[i] >= arr->size[i] && i >= 1)
						{
							location[i] -= arr->size[i];
							carry = true;
							i--;
						}
						else
							carry = false;
					}
					return (*this);
				}
				Iterator	operator++(int)
				{
					Iterator itr(*this);
					++(*this);
					return (itr);
				}
				bool operator!=(const Iterator &itr) {
					if (itr.arr->dim != arr->dim)
						return (true);
					for (int i = 0; i < arr->dim; i++)
					{
						if (itr.location[i] != location[i])
							return (true);
					}
					return (false);
				}
				Iterator &operator=(const Iterator itr){
					arr = itr.arr;
					location = new int[itr.arr->dim];
					for (int i = 0; i < arr->dim; i++)
						location[i] = itr.location[i];
					return (*this);
				}
				Int			operator*();
		};

		Array(int dim, int *array_size);
		Array(const Array &arr);
		~Array(void);
		void	initialize_address(Address *current);
		void	delete_address(Address *current);
		void	copy_address(Address *dst, Address *src);
		Int		operator[](const int index);
		Iterator	begin()
		{
			int *arr = new int[dim];
			for (int i = 0; i != dim; i++)
				arr[i] = 0;
			Iterator temp(this, arr);
			delete[] arr;
			return (temp);
		}
		Iterator	end()
		{
			int *arr = new int[dim];
			arr[0] = size[0];
			for (int i = 1; i < dim; i++)
				arr[i] = 0;
			Iterator temp(this, arr);
			delete[] arr;
			return (temp);
		}
};

class Int {
	private:
		int		level;
		void	*data;
		Array	*array;

	public:
		Int(int index, int _level = 0, void *_data = NULL, Array *_array = NULL);
		Int(const Int &i) : level(i.level), data(i.data), array(i.array) {}
		Int		operator[](const int index);
		Int		&operator=(const int &a);
		operator int();
};

Int Array::Iterator::operator*()
{
	Int start = arr->operator[](location[0]);
	for (int i = 1; i <= arr->dim - 1; i++)
		start = start.operator[](location[i]);
	return (start);
}

Int &Int::operator=(const int &a)
{
	if (data)
		*static_cast<int *>(data) = a;
	return (*this);
}

Int::operator int()
{
	if (data)
		return (*static_cast<int *>(data));
	return (0);
}

Int Int::operator[](const int index)
{
	if (!data)
		return 0;
	return (Int(index, level + 1, data, array));
}

Int Array::operator[](const int index)
{
	return Int(index, 1, static_cast<void *>(top), this);
}

Int::Int(int index, int _level, void *_data, Array *_array)
	: level(_level), data(_data), array(_array)
{
	if(_level < 1 || index >= array->size[_level - 1])
	{
		data = NULL;
		return ;
	}
	if (level == array->dim)
		data = static_cast<void *>((static_cast<int *> \
					(static_cast<Array::Address *>(data)->next) +index));
	else
		data = static_cast<void *>(static_cast<Array::Address *> \
				(static_cast<Array::Address *>(data)->next) + index);
}

Array::~Array(void)
{
	delete_address(top);
	delete[] size;
}

Array::Array(const Array &arr) : dim(arr.dim)
{
	size = new int[dim];
	for (int i = 0; i < dim; i++)
		size[i] = arr.size[i];
	top = new Address;
	top->level = 0;
	initialize_address(top);
	copy_address(top, arr.top);
}

Array::Array(int dim, int *array_size) : dim(dim)
{
	size = new int[dim];
	for (int i = 0; i < dim; i++)
		size[i] = array_size[i];
	top = new Address;
	top->level = 0;
	initialize_address(top);
}

void	Array::copy_address(Address *dst, Address *src)
{
	if (dst->level == dim - 1)
	{
		for (int i = 0; i < size[dst->level]; ++i)
			static_cast<int *>(dst->next)[i] = static_cast<int *>(src->next)[i];
		return ;
	}
	for (int i = 0; i < size[dst->level]; i++)
	{
		Address *new_dst = static_cast<Address *>(dst->next) + i;
		Address *new_src = static_cast<Address *>(src->next) + i;
		copy_address(new_dst, new_src);
	}
}

void	Array::delete_address(Address *current)
{
	if (!current)
		return ;
	for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++)
	{
		delete_address(static_cast<Address *>(current->next) + i);
	}
	if (current->level == dim - 1)
		delete[] static_cast<int *>(current->next);
	else
		delete[] static_cast<Address *>(current->next);
}

void	Array::initialize_address(Address *current)
{
	if (!current)
		return ;
	if (current->level == dim - 1)
	{
		current->next = new int[size[current->level]];
		return ;
	}
	current->next = new Address[size[current->level]];
	for (int i = 0; i < size[current->level]; i++)
	{
		(static_cast<Address *>(current->next) + i)->level = current->level + 1;
		initialize_address(static_cast<Address *>(current->next) + i);
	}
}

int main()
{
	int size[] = {2, 3, 4};
	Array arr(3, size);

	Array::Iterator itr = arr.begin();
	for (int i = 0; itr != arr.end(); itr++, i++)
		(*itr) = i;
	for (itr = arr.begin(); itr != arr.end(); itr++)
		std::cout << *itr << std::endl;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 4; k++)
				arr[i][j][k] = (i + 1) * (j + 1) * (k + 1);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 4; k++)
				std::cout << i << " " << j << " " << k << " " << arr[i][j][k] << std::endl;
		}
	}
}
