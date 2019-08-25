#ifndef CONTAINER_H
#define CONTAINER_H



template<class T>
class Container
{
    friend class iteratore;
private:
    T* vector;
    int size;
    int maxSize;
public:
    class iteratore {
        friend class Container<T>;
    private:
        T* punt;
    public:
        bool operator==(const iteratore& ) const;
        bool operator!=(const iteratore&) const;
        iteratore& operator=(iteratore);
        iteratore& operator++();
        iteratore& operator++(int);
        T& operator*() const;
        T* operator->() const;
    };
    class constiteratore {
        friend class Container<T>;
    private:
        T* punt;
    private:
        bool operator==(const constiteratore&) const;
        bool operator!=(const constiteratore&) const;
        constiteratore& operator=(constiteratore&);
        constiteratore& operator++();
        constiteratore& operator++(int);
        const T& operator*() const;
        const T* operator->() const;
    };

    Container(T* p = nullptr, int s = 0);
	Container(const Container& c);
    ~Container();
    T* copia(T* a, int s);
    unsigned int getSize() const;
    unsigned int getMaxSize() const;
    void increaseSize();
    void removeEl(int);
    void insertEl(T&);
    T* getEl(unsigned int) const;
    iteratore& begin() const;
    iteratore& end() const;
    Container<T>& operator=(const Container& c);
    T& operator[](iteratore) const;
    T& operator[](int) const;
    T& operator*(iteratore&) const;
};



template<class T>
Container<T>::Container(T* p, int s)
{
    if (s != 0)
    {
        T* a = new T[s*2];
        if (p)
        {
            for(int i = 0; i < s; i++)
            {
                a[i] = p[i];
            }
    }
    vector = a;
    size = s;
    maxSize = s*2;
    }
    else
    {
        T* a = new T[10];
        size = 0;
        maxSize = 10;
        vector = a;
    }

}

template<class T>
Container<T>::Container(const Container& c)
{
    if (this->vector != c.vector)
	{
        vector = new T[c.maxSize];
        vector = copia(c.vector,c.size);
		size = c.size;
		maxSize = c.maxSize;
	}
}
template<class T>
Container<T>& Container<T>::operator=(const Container& c)
{
    if (this->vector != c.vector)
    {
        vector = copia(c.vector,c.size);
        size = c.size;
        maxSize = c.maxSize;
    }
    return *this;
}
template<class T>
T* Container<T>::copia(T* a , int s)
{
	for (int i = 0; i < s; i++)
	{
		vector[i] = a[i];
	}
    return vector;
}
template<class T>
Container<T>::~Container()
{
    if(vector)
    delete[] vector;
}
template<class T>
unsigned int Container<T>::getSize() const
{
    return size;
}
template<class T>
unsigned int Container<T>::getMaxSize() const
{
    return maxSize;
}
template<class T>
bool Container<T>::iteratore::operator==(const iteratore& it) const
{
    return (punt->p == it.punt->p);
}
template<class T>
bool Container<T>::iteratore::operator!=(const iteratore& it) const
{
    return !(punt->p == it.punt->p);
}
template<class T>
typename Container<T>::iteratore& Container<T>::iteratore::operator++()
{
    punt = punt+1;
    return *this;
}
template<class T>
typename Container<T>::iteratore& Container<T>::iteratore::operator++(int)
{
    iteratore aux = *this;
    punt = punt+1;
    return aux;
}
template<class T>
T& Container<T>::iteratore::operator*() const
{
    return *punt;
}
template<class T>
T* Container<T>::iteratore::operator->() const
{
    return punt;
}
template <class T>
bool Container<T>::constiteratore::operator==(const constiteratore& it) const
{
    return (punt->p == it.punt->p);
}
template<class T>
bool Container<T>::constiteratore::operator!=(const constiteratore& it) const
{
    return !(punt->p == it.punt->p);
}
template<class T>
typename Container<T>::constiteratore& Container<T>::constiteratore::operator++()
{
    punt = punt+1;
    return *this;
}
template<class T>
typename Container<T>::constiteratore& Container<T>::constiteratore::operator++(int)
{
    constiteratore aux = *this;
    punt = punt+1;
    return aux;
}
template<class T>
const T& Container<T>::constiteratore::operator*() const
{
    return *punt;
}
template<class T>
const T* Container<T>::constiteratore::operator->() const
{
    return punt;
}

template<class T>
void Container<T>::increaseSize()
{
    T* temp = new T[maxSize*2];
    for (int i = 0; i < maxSize; i++)
    {
        temp[i] = vector[i];
    }
    maxSize = maxSize * 2;
    vector = temp;
}
template<class T>
void Container<T>::insertEl(T& p)
{
    if (maxSize == size)
    {
        increaseSize();
    }
	iteratore it = begin();
    for (int i = 0; i < size; i++)
		it++;
    *(it) = p;
    size++;
}
template<class T>
void Container<T>::removeEl(int j)
{
    if (j <= size && size > 0)
    {
        iteratore it = begin();
		T* v = new T[maxSize]; 
        for(int i = 0; i <= (j-1); i++)
        {
			*(v + i) = *(it);
            it++;
        }
		it++;
        for(unsigned int i = j+1; i < maxSize; i++)
        {
			*(v + i-1) = *(it);
			it++;

        }
        size--;
        delete[] vector;
		vector = v;
    }
}
template<class T>
T* Container<T>::getEl(unsigned int j) const
{
    iteratore it = begin();
    for(int i = 0; i < j; i++)
    {
        ++it;
    }
    T* aux = new T((*it));
    return aux;
}


template<class T>
typename Container<T>::iteratore& Container<T>::begin() const
{
    iteratore aux;
    aux.punt = vector;
    return aux;
}
template<class T>
typename Container<T>::iteratore& Container<T>::end() const
{
    iteratore aux;
    aux.punt = &vector[size];
    return aux;
}
template<class T>
T& Container<T>::operator[](iteratore it) const
{
    return *(it.punt);
}

template<class T>
T& Container<T>::operator[](int i) const
{
    return vector[i];
}
template<class T>
T& Container<T>::operator*(iteratore& it) const
{
    return *(it.punt);
}
template<class T>
typename Container<T>::iteratore& Container<T>::iteratore::operator=(iteratore it)
{
    if (it.punt != this->punt)
    {
        this->punt = it.punt;
    }
    return *this;
}

#endif // CONTAINER_H
