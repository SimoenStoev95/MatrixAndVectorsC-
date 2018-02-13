#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
using namespace std;

const unsigned MAX = 200;

template<typename T, typename S = double>
class Matrix {
public :
	// Функция за извеждане на екрана на матрица
	friend ostream& operator<< (ostream& , const Matrix<T>&);
	// Функция за въвеждане на матрица от потребителя
	friend istream& operator>> (istream& , Matrix<T>&);
public :
	// Конструктури
	Matrix ();
	Matrix (unsigned , unsigned, T _matrix[][MAX]);
	// Set функция за промяна на матрица
	void setMatrix (unsigned, unsigned, T _matrix[][MAX]);
	// Член-функции за достъп
	unsigned getLength () const;
	unsigned getWidth () const;
	// Събиране и изваждане на матрици
	T* operator+ (const Matrix&);
	T* operator- (const Matrix&);
	void operator+= (const Matrix&);
	void operator-= (const Matrix&);
	// Добавяне и изваждане на число към матрица
	T* operator+ (const S&);
	T* operator- (const S&);
	void operator+= (const S&);
	void operator-= (const S&);
	// Умножение и деление на матрици с числа
	T* operator* (const S&);
	void operator*= (const S&);
	T* operator/ (const S&);
	void operator/= (const S&);
	// Достъп до елемент на матрицата чрез оператора []
	T operator[] (unsigned) const;
	// Транспониране на произволна правоъгълна матрица с оператора ~
	void operator~ ();
	// Намиране на детерминантата на матрица
	double findDeter () const;
	// Умножение на матрици с подходящи размерности
	T* operator* (const Matrix&);
	void operator*= (const Matrix&);
private :
	unsigned length, width;
	T matrix[MAX][MAX];
};

ostream& operator<< (ostream& out, const Matrix<int>& mat)
{
	if (mat.getLength() != 0 && mat.getWidth() != 0)
	{
		for (unsigned i = 0; i < mat.getLength(); i++)
		{
			for (unsigned j = 0; j < mat.getWidth(); j++)
			{
				out << mat.matrix[i][j] << " ";
			}
			out << endl;
		}
	}
	return out;
}

ostream& operator<< (ostream& out, const Matrix<double>& mat)
{
	if (mat.getLength() != 0 && mat.getWidth() != 0)
	{
		for (unsigned i = 0; i < mat.getLength(); i++)
		{
			for (unsigned j = 0; j < mat.getWidth(); j++)
			{
				out << mat.matrix[i][j] << " ";
			}
			out << endl;
		}
	}
	return out;
}

istream& operator>> (istream& in, Matrix<int>& mat)
{
	in >> mat.length;
	in >> mat.width;
	if (mat.getLength() > 0 && mat.getWidth() > 0)
	{
		for (unsigned i = 0; i < mat.getLength(); i++)
		{
			for (unsigned j = 0; j < mat.getWidth(); j++)
			{
				in >> mat.matrix[i][j];
			}
		}
	}
	return in;
}

istream& operator>> (istream& in, Matrix<double>& mat)
{
	in >> mat.length;
	in >> mat.width;
	if (mat.getLength() > 0 && mat.getWidth() > 0)
	{
		for (unsigned i = 0; i < mat.getLength(); i++)
		{
			for (unsigned j = 0; j < mat.getWidth(); j++)
			{
				in >> mat.matrix[i][j];
			}
		}
	}
	return in;
}

template<typename T, typename S>
Matrix<T, S>::Matrix ()
{
	length = 0;
	width = 0;
}

template<typename T, typename S>
Matrix<T, S>::Matrix (unsigned _length, unsigned _width, T _matrix[][MAX])
{
	setMatrix (_length, _width, _matrix);
}

template<typename T, typename S>
unsigned Matrix<T, S>::getLength () const
{
	return length;
}

template<typename T, typename S>
unsigned Matrix<T, S>::getWidth () const
{
	return width;
}



template<typename T, typename S>
void Matrix<T, S>::setMatrix (unsigned _length, unsigned _width, T _matrix[][MAX])
{
	length = _length;
	width = _width;
	for (unsigned i = 0; i < length; i++)
	{
		for (unsigned j = 0; i < width; j++)
		{
			matrix[i][j] = _matrix[i][j];
		}
	}
}

template<typename T, typename S>
T* Matrix<T, S>::operator+ (const Matrix<T, S>& other)
{
	if ( ( getLength() == other.getLength() ) && ( getWidth() == other.getWidth() ) )
	{
		T* ptr = new T[getLength() * getWidth()];
		unsigned count = 0;
		for (unsigned i = 0; i < length; i++)
		{
			for (unsigned j = 0; j < width; j++)
			{
				ptr[count++] = matrix[i][j] + other.matrix[i][j];
			}
		}
		return ptr;
	}
	else
	{
		cout << "Matrices with diferent dimensions ! " << endl;
		return NULL;
	}
}

template<typename T, typename S>
T* Matrix<T, S>::operator- (const Matrix<T, S>& other)
{
	if ( ( getLength() == other.getLength() ) && ( getWidth() == other.getWidth() ) )
	{
		T* ptr = new T[getLength() * getWidth()];
		unsigned count = 0;
		for (unsigned i = 0; i < length; i++)
		{
			for (unsigned j = 0; j < width; j++)
			{
				ptr[count++] = matrix[i][j] - other.matrix[i][j];
			}
		}
		return ptr;
	}
	else
	{
		cout << "Matrices with diferent dimensions ! " << endl;
		return NULL;
	}
}

template<typename T, typename S>
void Matrix<T, S>::operator-= (const Matrix<T, S>& other)
{
	if ( (getLength() == other.getLength() ) && ( getWidth() == other.getWidth() ) )
	{
		for (unsigned i = 0; i < length; i++)
		{
			for (unsigned j = 0; j < width; j++)
			{
				matrix[i][j] -= other.matrix[i][j];
			}
		}
	}
	else
	{
		cout << "Not permitted command ! " << endl;
	}
}

template<typename T, typename S>
void Matrix<T, S>::operator+= (const Matrix<T, S>& other)
{
	if ( ( getLength() == other.getLength() ) && ( getWidth() == other.getWidth() ) )
	{
		for (unsigned i = 0; i < length; i++)
		{
			for (unsigned j = 0; j < width; j++)
			{
				matrix[i][j] += other.matrix[i][j];
			}
		}
	}
	else
	{
		cout << "Not permitted command ! " << endl;
	}
}

template<typename T, typename S>
T* Matrix<T, S>::operator+ (const S& digit)
{
	if (getLength() != 0 && getWidth() != 0)
	{
		T* ptr = new T[getLength() * getWidth()];
		unsigned count = 0;
		for (unsigned i = 0; i < length; i++)
		{
			for (unsigned j = 0; j < width; j++)
			{
				ptr[count++] = matrix[i][j] + digit;
			}
		}
		return ptr;
	}
	cout << " Incorrect input for the matrix ! " << endl;
	return NULL;
}

template<typename T, typename S>
T* Matrix<T, S>::operator- (const S& digit)
{
	if (getLength() != 0 && getWidth() != 0)
	{	
		T* ptr = new T[getLength() * getWidth()];
		unsigned count = 0;
		for (unsigned i = 0; i < length; i++)
		{
			for (unsigned j = 0; j < width; j++)
			{
				ptr[count++] = matrix[i][j] - digit;
			}
		}
		return ptr;
	}
	cout << " Incorrect input for the matrix ! " << endl;
	return NULL;
}

template<typename T, typename S>
void Matrix<T, S>::operator+= (const S& digit)
{
	if (getLength() != 0 && getWidth() != 0)
	{
		for (unsigned i = 0; i < length; i++)
		{
			for (unsigned j = 0; j < width; j++)
			{
				matrix[i][j] += digit;
			}
		}
	}
	else
	{
		cout << "Not permitted command ! " << endl;
	}
}

template<typename T, typename S>
void Matrix<T, S>::operator-= (const S& digit)
{
	if (getLength() != 0 && getWidth() != 0)
	{
		for (unsigned i = 0; i < length; i++)
		{
			for (unsigned j = 0; j < width; j++)
			{
				matrix[i][j] -= digit;
			}
		}
	}
	else
	{
		cout << "Not permitted command ! " << endl;
	}
}

template<typename T, typename S>
T* Matrix<T, S>::operator* (const S& digit)
{
	if (getLength() != 0 && getWidth() != 0)
	{
		T* ptr = new T[getLength() * getWidth()];
		unsigned count = 0;
		for (unsigned i = 0; i < length; i++)
		{
			for (unsigned j = 0; j < width; j++)
			{
				ptr[count++] = matrix[i][j] * digit;
			}
		}
		return ptr;
	}
	cout << " Incorrect input for the matrix ! " << endl;
	return NULL;
}

template<typename T, typename S>
void Matrix<T, S>::operator*= (const S& digit)
{
	if (getLength() != 0 && getWidth() != 0)
	{
		for (unsigned i = 0; i < length; i++)
		{
			for (unsigned j = 0; j < width; j++)
			{
				matrix[i][j] *= digit;
			}
		}
	}
	else
	{
		cout << "Not permitted command ! " << endl;
	}
}

template<typename T, typename S>
T* Matrix<T, S>::operator/ (const S& digit)
{
	if (getLength() != 0 && getWidth() != 0 && digit != 0)
	{
		T* ptr = new T[getLength() * getWidth()];
		unsigned count = 0;
		for (unsigned i = 0; i < length; i++)
		{
			for (unsigned j = 0; j < width; j++)
			{
				ptr[count++] = matrix[i][j] / digit;
			}
		}
		return ptr;
	}
	cout << " Incorrect command ! " << endl;
	return NULL;
}

template<typename T, typename S>
void Matrix<T, S>::operator/= (const S& digit)
{
	if (getLength() != 0 && getWidth() != 0 && digit != 0)
	{
		for (unsigned i = 0; i < length; i++)
		{
			for (unsigned j = 0; j < width; j++)
			{
				matrix[i][j] /= digit;
			}
		}
	}
	else
	{
		cout << "Not permitted command ! " << endl;
	}
}

template<typename T, typename S>
T Matrix<T, S>::operator[] (unsigned index) const
{
	unsigned count  = -1;
	if (index < length * width)
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < width; j++)
			{
				count++;
				if (count == index)	
					return matrix[i][j];
			}
		}
			cout << "No element ! You get the first element in the matrix !" << endl;
			return matrix[0][0];
	}
	cout << "Wrong index, you get the first element in the matrix . " << endl;
	return matrix[0][0];
}

template<typename T, typename S>
void Matrix<T, S>::operator~ ()
{
	if (getLength() != 0 && getWidth() != 0)
	{
		T help[MAX][MAX];
		for (int j = 0; j < getLength(); j++)
		{
			for (int i = 0 ; i < getWidth(); i++)
			{
				help[i][j] = matrix[j][i];
			}
		}
		std::swap(length, width);
		for (int i = 0; i < getLength(); i++)
		{
			for (int j = 0; j < getWidth(); j++)
			{
				matrix[i][j] = help[i][j];
			}
		}
	}
}

template<typename T, typename S>
T* Matrix<T, S>::operator* (const Matrix<T, S>& other)
{
	T help[MAX][MAX];
	T sum = 0;
	T* ptr = new T[getLength() * other.getWidth()];
	unsigned count = 0;
	if (getWidth() == other.getLength())
	{
		for (unsigned i = 0; i < getLength(); i++)
		{
			for (unsigned k = 0; k < other.getWidth(); k++)
			{
				for (unsigned j = 0; j < getWidth(); j++)
				{
					sum += matrix[i][j] * other.matrix[j][k];
				}
				help[i][k] = sum;
				sum = 0;
			}
		}
		// width = other.getWidth();
		for (int i = 0; i < getLength(); i++)
		{
			for (int j = 0; j < other.getWidth(); j++)
			{
				ptr[count++] = help[i][j];
			}
		}
		return ptr;
	}
	else
	{
		cout << "Incorrect multiplyning of two matrices ! " << endl;
		return NULL;
	}
}

template<typename T, typename S>
void Matrix<T, S>::operator*= (const Matrix<T, S>& other)
{
	T help[MAX][MAX];
	T sum = 0;
	if (getWidth() == other.getLength())
	{
		for (unsigned i = 0; i < getLength(); i++)
		{
			for (unsigned k = 0; k < other.getWidth(); k++)
			{
				for (unsigned j = 0; j < getWidth(); j++)
				{
					sum += matrix[i][j] * other.matrix[j][k];
				}
				help[i][k] = sum;
				sum = 0;
			}
		}
		width = other.getWidth();
		for (int i = 0; i < getLength(); i++)
		{
			for (int j = 0; j < getWidth(); j++)
			{
				matrix[i][j] = help[i][j];
			}
		}
	}
	else
	{
		cout << "Incorrect multiplying of two matrices ! " << endl;
	}
}

template<typename T, typename S>
double Matrix<T, S>::findDeter () const // Some errors
{
	if (getLength() == getWidth()) 
	{
		T help[MAX][MAX];
		for (int i = 0; i < getLength(); i++)
		{
			for (int j = 0; j < getWidth(); j++)
			{
				help[i][j] = matrix[i][j];
			}
		}
		// Правя всеки елемент под главния диагонал 0
		int t = 0;
		for (int i = 1; i < getLength(); i++)
		{
			int z = 0, y = 0, p = 0;
			while (t < i)
			{
				for (int j = 0; j < getWidth(); j++)
				{
					help[i][j] += (-1) * (help[i][y] / help[p][y]) * help[z][j];
					// z++;
				}
				p++;
				y++;
				t++;
			}
			t = 0;
		}/*
		for (int i = 0; i < this->getLength(); i++)
		{
			for (int j = 0; j < this->getWidth(); j++)
			{
				cout << help[i][j] << " ";
			}
			cout << endl;
		}*/
		double sum = 1;
		for (int i = 0; i < getLength(); i++)
			sum *= help[i][i];
		return sum;
	}
	else
	{
		cout << "Incorrect command ! " << endl;
		return 0;
	}
}

#endif // MATRIX_H