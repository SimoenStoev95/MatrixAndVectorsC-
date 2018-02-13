#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include<cmath>
using namespace std;

#include "Matrix.h"

template<typename T, typename S = int>
class Vector {
public :
	friend ostream& operator<< (ostream&, const Vector<T>&); // Извеждане на вектор на екрана
	friend istream& operator>> (istream&, Vector<T>&); // Въвеждане на вектор от потребителя
public:
	// Голямата четворка
	Vector (T* = NULL, unsigned = 0);
	Vector (const Vector&);
	Vector& operator= (const Vector&);
	~Vector ();
	// Функция за въвеждане на вектор
	void setVector (T*, unsigned);
	// Функция, връщаща броя на координатите на един вектор
	unsigned getSize () const;
	// Функции за събиране на два вектора
	T* operator+ (const Vector&);
	void operator+= (const Vector&);
	// Функции за изваждане на два вектора
	T* operator- (const Vector&);
	void operator-= (const Vector&);
	// Събиране на вектор с число
	T* operator+ (const S&);
	void operator+= (const S&);
	// Изваждане на вектор с число
	T* operator- (const S&);
	void operator-= (const S&);
	// Умножение на вектор с число
	T* operator* (const S&);
	void operator*= (const S&);
	// Деление на вектор с число
	T* operator/ (const S&);
	void operator/= (const S&);
	// Скаларно произведение на вектори
	T operator* (const Vector&);
	void operator*= (const Vector&); // void !!!
	// Векторно произведение на вектори
	T* operator^ (const Vector&);
	void operator^= (const Vector&);
	// Нормализиране на вектор
	T* operator! ();
	// Умножение на вектор с матрица
	T* operator* (const Matrix<T>&);
	void operator*= (const Matrix<T>&);
	// Достъп до елемент с операцията []
	T& operator[] (unsigned);
private :
	T* vector; // Указател сочещ към координатите на вектора
	unsigned size; // Брой на координатите на вектор
};

ostream& operator<< (ostream& out, const Vector<int>& sample)
{
	out << "( ";
	for (unsigned i = 0; i < sample.getSize(); i++)
	{
		if (i < sample.getSize() - 1)
			out << sample.vector[i] <<" , ";
		else
			out << sample.vector[i] << " )";
	}
	return out;
}

ostream& operator<< (ostream& out, const Vector<double>& sample)
{
	out << "( ";
	for (unsigned i = 0; i < sample.getSize(); i++)
	{
		if (i < sample.getSize() - 1)
			out << sample.vector[i] <<" , ";
		else
			out << sample.vector[i] << " )";
	}
	return out;
}

istream& operator>> (istream& in, Vector<int>& sample)
{
	unsigned temp = 0;
	in >> temp;
	int* tmp = new int[temp];
	for (unsigned i = 0; i < temp; i++)
	{
		in >> tmp[i];
	}
	sample.vector = NULL;
	sample.setVector(tmp, temp);
	delete [] tmp;
	return in;
}

istream& operator>> (istream& in, Vector<double>& sample)
{
	unsigned temp = 0;
	in >> temp;
	double* tmp = new double[temp];
	for (unsigned i = 0; i < temp; i++)
	{
		in >> tmp[i];
	}
	sample.vector = NULL;
	sample.setVector(tmp, temp);
	delete [] tmp;
	return in;
}

template<typename T, typename S>
Vector<T, S>::Vector (T* vect, unsigned coor) : vector(NULL)
{
	setVector (vect, coor);
}

template<typename T, typename S>
Vector<T, S>::Vector (const Vector<T, S>& other)
{
	*this = other;
}

template<typename T, typename S>
Vector<T, S>::~Vector ()
{
	delete [] vector;
}

template<typename T, typename S>
Vector<T, S>& Vector<T, S>::operator= (const Vector<T, S>& other)
{
	if (this != &other)
	{
		delete [] vector;
		size = other.getSize();
		vector = new T[size];
		for (int i = 0; i < size; i++)
		{
			vector[i] = other.vector[i];
		}
	}
	return *this;
}

template<typename T, typename S>
void Vector<T, S>::setVector (T* _vector, unsigned _size)
{
	if (vector != NULL)
	{
		delete [] vector;
	}
	size = _size;
	vector = new T[size];
	for (int i = 0; i < size; i++)
	{
		vector[i] = _vector[i];
	}
}

template<typename T, typename S>
unsigned Vector<T, S>::getSize () const
{
	return size;
}

template<typename T, typename S>
T* Vector<T, S>::operator+ (const Vector<T, S>& other)
{
	if (getSize() == other.getSize())
	{
		T* temp = new T[getSize()];
		for (int i = 0; i < getSize(); i++)
		{
			temp[i] = vector[i] + other.vector[i];
		}
		return temp;
	}
	cout << "Not permitted command. You get the NULL pointer ! " << endl;
	return NULL;
}

template<typename T, typename S>
void Vector<T, S>::operator+= (const Vector<T, S>& other)
{
	if (getSize() == other.getSize())
	{
		for (int i = 0; i < getSize(); i++)
		{
			vector[i] += other.vector[i];
		}
	}
	else
	{
		cout << "Not permitted command ! " << endl;
	}
}

template<typename T, typename S>
T* Vector<T, S>::operator- (const Vector<T, S>& other)
{
	if (getSize() == other.getSize())
	{
		T* temp = new T[getSize()];
		for (int i = 0; i < getSize(); i++)
		{
			temp[i] = vector[i] - other.vector[i];
		}
		return temp;
	}
	cout << "Not permitted command. You get the NULL pointer ! " << endl;
	return NULL;
}

template<typename T, typename S>
void Vector<T, S>::operator-= (const Vector<T, S>& other)
{
	if (getSize() == other.getSize())
	{
		for (int i = 0; i < getSize(); i++)
		{
			vector[i] -= other.vector[i];
		}
	}
	else
	{
		cout << "Not permitted command ! " << endl;
	}
}

template<typename T, typename S>
T* Vector<T, S>::operator+ (const S& digit)
{
	T* temp = new T[getSize()];
	for (int i = 0; i < getSize(); i++)
	{
		temp[i] = vector[i] + digit;
	}
	return temp;
}

template<typename T, typename S>
void Vector<T, S>::operator+= (const S& digit)
{
	for (int i = 0; i < getSize(); i++)
	{
		vector[i] += digit;
	}
}

template<typename T, typename S>
T* Vector<T, S>::operator- (const S& digit)
{
	T* temp = new T[getSize()];
	for (int i = 0; i < getSize(); i++)
	{
		temp[i] = vector[i] - digit;
	}
	return temp;
}

template<typename T, typename S>
void Vector<T, S>::operator-= (const S& digit)
{
	for (int i = 0; i < getSize(); i++)
	{
		vector[i] -= digit;
	}
}

template<typename T, typename S>
T* Vector<T, S>::operator* (const S& digit)
{
	T* temp = new T[getSize()];
	for (int i = 0; i < getSize(); i++)
	{
		temp[i] = vector[i] * digit;
	}
	return temp;
}

template<typename T, typename S>
void Vector<T, S>::operator*= (const S& digit)
{
	for (int i = 0; i < getSize(); i++)
	{
		vector[i] *= digit;
	}
}

template<typename T, typename S>
T* Vector<T, S>::operator/ (const S& digit)
{
	if (digit != 0)
	{
		T* temp = new T[getSize()];
		for (int i = 0; i < getSize(); i++)
		{
			temp[i] = vector[i] / digit;
		}
		return temp;
	}
	cout << "Not permitted command . You get the NULL pointer ! " << endl;
	return NULL;
}

template<typename T, typename S>
void Vector<T, S>::operator/= (const S& digit)
{
	if (digit != 0)
	{
		for (int i = 0; i < getSize(); i++)
		{
			vector[i] /= digit;
		}
	}
	else
		cout << "Not permitted command ! " << endl;
}

template<typename T, typename S>
T Vector<T, S>::operator* (const Vector<T, S>& other)
{
	if (getSize() == other.getSize())
	{
		T temp = 0;
		for (int i = 0; i < getSize(); i++)
		{
			temp += (vector[i] * other.vector[i]);
		}
		return temp;
	}
	else
	{
		cout << "Incorrect command ! " << endl;
		return 0;
	}
}

template<typename T, typename S>  // PROBLEM
void Vector<T, S>::operator*= (const Vector<T, S>&  other)
{
	if (getSize() == other.getSize())
	{
		for (int i = 0; i < getSize(); i++)
		{
			vector[i] *= other.vector[i];
		}
	}
	else
	{
		cout << "Incorrect command ! " << endl;
	}
}

template<typename T, typename S>
T* Vector<T, S>::operator^ (const Vector<T, S>& other)
{
	if (getSize() == 3 && other.getSize() == 3)
	{
		T a, b, c;
		a = vector[1] * other.vector[2] - vector[2] * other.vector[1];
		b = (-1) * (vector[0] * other.vector[2] - vector[2] * other.vector[0]);
		c = vector[0] * other.vector[1] - vector[1] * other.vector[0];
		T* temp = new T[3];
		temp[0] = a; temp[1] = b; temp[2] = c;
		return temp;
	}
	else
	{
		cout << "Incorrect command ! " << endl;
		return NULL;
	}
}

template<typename T, typename S>
void Vector<T, S>::operator^= (const Vector<T, S>& other)
{
	if (getSize() == 3 && other.getSize() == 3)
	{
		T a, b, c;
		a = vector[1] * other.vector[2] - vector[2] * other.vector[1];
		b = (-1) * (vector[0] * other.vector[2] - vector[2] * other.vector[0]);
		c = vector[0] * other.vector[1] - vector[1] * other.vector[0];
		vector[0] = a; vector[1] = b; vector[2] = c;
	}
	else
	{
		cout << "Incorrect command ! " << endl;
	}
}

template<typename T, typename S>
T* Vector<T, S>::operator! () // FIX ME
{
	if (vector != NULL)
	{
		double tmp = 0;
		for (int i = 0; i < getSize(); i++)
		{
			tmp += pow((double)vector[i], 2);
		}
		double temp = sqrt(tmp);
		T* ptr = new T[getSize()];
		for (int i = 0; i < getSize(); i++)
		{
			ptr[i] = vector[i] / temp;
		}	
		return ptr;
	}
	else 
	{
		cout << "Not valid vector ! " << endl;
		return NULL;
	}
}

template<typename T, typename S>
T* Vector<T, S>::operator* (const Matrix<T>& mat)
{
	if (getSize() == mat.getWidth())
	{
		T* temp = new T[mat.getLength()];
		T sum = 0;
		int goo = -1;
		int count = 0;
		unsigned tmp = 0;
		for (unsigned i = 0; i < mat.getLength(); i++)
		{
			for (unsigned j = 0; j < mat.getWidth(); j++)
			{
				if (j == 1)
					tmp++;
				sum += mat[tmp] * vector[++goo];
				if (j > 1)
					tmp++;
			}
			temp[count++] = sum;
			sum = 0;
			goo = -1;
			tmp++;
		}
		return temp;
	}
	else
	{
		cout << "Incorrect multiplying of vector and matrix ! " << endl;
		return NULL;
	}
}

template<typename T, typename S>
void Vector<T, S>::operator*= (const Matrix<T>& mat)
{
	if (getSize() == mat.getWidth())
	{
		T* helpMe = new T[mat.getLength()];
		int goo = -1;
		int count = 0;
		T sum = 0;
		int temp = 0;
		for (unsigned i = 0; i < mat.getLength(); i++)
		{
			for (unsigned j = 0; j < mat.getWidth(); j++)
			{
				if (j > 0)
					temp++;
				sum += mat[temp] * vector[++goo];
			}
			helpMe[count++] = sum;
			sum = 0;
			goo = -1;
			temp++;
		}
		setVector(helpMe, mat.getLength());
		delete [] helpMe;
	}
	else
	{
		cout << "Incorrect multiplying of vector and matrix ! " << endl;
	}
}

template<typename T, typename S>
T& Vector<T, S>::operator[] (unsigned index)
{
	if (index >= getSize())
	{
		cout << "Trying to get a coordinate which does not exist. You take the first coordinate ! " << endl;
		return vector[0];
	}
	return vector[index];
}

#endif // VECTOR_H