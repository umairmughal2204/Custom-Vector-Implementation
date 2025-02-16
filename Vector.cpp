# include <iostream>
# include<stdexcept>
# include"Vector.h"
    template<typename T>
    Vector<T>::Vector()
    {
        arr=nullptr;
        maxSize=3;
        currentSize=0;
        arr = new T[maxSize];
    }
    template<typename T>
    Vector<T>::Vector(int maxSize)
    {
        currentSize=0;
        if(maxSize>0)
        {
            this->maxSize=maxSize;
            arr=new T[maxSize];
            for(int i=0;i<maxSize;i++)
            {
                arr[i]=0;
            }
        }
        else
        {
            throw invalid_argument("SIZE CAN NOT BE NEGATIVE.");
        }
    }
    template<typename T>
    Vector<T>::Vector(const Vector<T> &orig)
    {

        maxSize=orig.maxSize;
        currentSize=orig.currentSize;
        arr=new T [maxSize];
        for(int i=0;i<maxSize;i++)
        {
            arr[i]=orig.arr[i];
        }
    }
    template<typename T>
    Vector<T>::~Vector()
    {
        if(arr!=nullptr)
        {
            delete [] arr;
            arr=nullptr;
        }
        currentSize=0;
        maxSize=0;
    }
    template<typename T>
    int Vector<T>:: getSize()const
    {
        return currentSize;
    }
    template<typename T>
    int Vector<T>::getMaxSize()const
    {
        return maxSize;
    }
    template<typename T>
    void Vector<T>::push_back(T num)
    {
        
        if (currentSize == maxSize)
        {
            resize();
        }
       
        arr[currentSize] = num;
        currentSize++;
    }
    template<typename T>
    T Vector<T>:: pop_back()
    {
        if(!is_empty())
        {
            T temp=arr[currentSize-1];
            arr[currentSize-1]=0;
            currentSize--;
            if(currentSize<maxSize/4)
            {
                resize();
            }
            return temp;
        }
        else
        {
            return 0;
        }
    }
    template<typename T>
    bool Vector<T>::is_empty()const
    {
        if(currentSize==0)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    template<typename T>
    bool Vector<T>:: is_full()const
    {
        if(currentSize==maxSize)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    template<typename T>
    T Vector<T>:: at(int index)
    {
        return arr[index];
    }
    template<typename T>
    void Vector<T>:: swap(Vector<T> &other)
    {
        if (currentSize != other.currentSize) 
         {
            throw invalid_argument("Cannot swap vectors with different sizes");
        }
        for(int i=0;i<currentSize;i++)
        {
            int temp= arr[i];
            arr[i]=other.arr[i];
            other.arr[i]=temp;
        }
    }
    template<typename T>
    T Vector<T>:: erase(int index)
    {
        if(index>=currentSize || index<0)
        {
            throw invalid_argument("INDEX IS OUT OF RANGE");
        }
        T tempint=arr[index];
        currentSize--;
        T *temp=new T [currentSize];
        int j=0;
        for(int i=0;i<currentSize+1;i++)
        {
            if(i!=index)
            {
                temp[j++]=arr[i];
            }      
        }
        delete [] arr;
        arr=temp;
        temp=nullptr;
        return tempint;  
    }
    template<typename T>
    void Vector<T>:: insert(T num,int index)
    {
        if(index<0 || index>currentSize)
        {
            throw invalid_argument("OUT OF BOUNDS.");
        }
        T * temp=new T[currentSize+1];
        for(int i=0;i<currentSize;i++)
        {
            if(i<index)
            {
                temp[i]=arr[i];
            }
            else
            {
                temp[i+1]=arr[i];
            }
        }
        temp[index]=num;
        delete []arr;
        arr=temp;
        temp=nullptr;
        currentSize++;
    }
    template<typename T>
    void Vector<T>::sort()
    {
        for(int i=0;i<currentSize;i++)
        {
            for(int j=i;j<currentSize;j++)
            {
                if(arr[i]>arr[j])
                {
                    T temp;
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
    }
    template<typename T>
    void Vector<T>:: move(int num)
    {
        if( num>currentSize)
        {
            throw invalid_argument("OUT OF THE BOUNDS.");
        }
        T * temp=new T [currentSize];
        if(num>0)
        {
            for(int i=0;i<currentSize;i++)
            {
                int newindex=(num+i)%currentSize;
                temp[newindex]=arr[i];
            }
            delete[] arr;
            arr=temp;
            temp=nullptr;
        }
        else
        {
            for(int i=0;i<currentSize;i++)
            {
                int newindex=(-num+i)%currentSize;
                temp[i]=arr[newindex];
            }
            delete [] arr;
            arr=temp;
            temp=nullptr;
        }
    }
    template<typename T>
    int Vector<T>:: count(const T& element)
    {
        int count=0;
        for(int i=0;i<currentSize;i++)
        {
            if(arr[i]==element)
            {
                count++;
            }
        }
        return count;
    }
    template<typename T>
    Vector<T> Vector<T>:: unionOfVectors (const Vector<T> &other)
    {
        Vector result;
        for (int i = 0; i < currentSize; ++i) 
        {
            result.push_back(arr[i]);
        }
        for (int i = 0; i < other.currentSize; ++i) 
        {
            bool found = false;
            for (int j = 0; j < result.currentSize; ++j) 
            {
                if (other.arr[i] == result.arr[j]) 
                {
                    found = true;
                    break;
                }
            }
            if (!found) 
            {
                result.push_back(other.arr[i]);
            }
        }

        return result;
    }
    template<typename T>
    Vector<T> Vector<T>:: intersectionOfVectors(const Vector<T> &other)
    {
        Vector result;
        for(int i=0;i<currentSize;i++)
        {
            bool flag = false;
            for(int j=0;j<other.currentSize;j++)
            {
                if(arr[i]==other.arr[j])
                {
                    flag = true;
                    break;
                }
            }
            if (flag) 
            {
                result.push_back(arr[i]);
            }
        }
        return result;
    }
    template<typename T>
    Vector<T> Vector<T>:: unique()
    {
        // int count=0;
        Vector result;
        for(int i=0;i<this->currentSize;i++)
        {
            bool flag= false;
            for(int j=0;j<this->currentSize;j++)
            {
                if((i!=j) && (arr[i]==arr[j]))
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                result.push_back(arr[i]);
            }
            
        }
        return result;
    }
    template<typename T>
    bool Vector<T>::subset(const Vector<T> &other)
    {
        if (other.currentSize > currentSize)
        {
            return false;
        }

        for (int i = 0; i < other.currentSize; ++i)
        {
            bool found = false;
            for (int j = 0; j < currentSize; ++j)
            {
                if (other.arr[i] == arr[j])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                return false;
            }
        }
        return true;
    }
    template<typename T>
    bool Vector<T>:: search(T key)
    {
        for(int i=0;i<currentSize;i++)
        {
            if(arr[i]==key)
            {
                return true;
            }
        }
        return false;
    }
    template<typename T>
    Vector<T> Vector<T>:: operator+(const Vector<T> & other) const
    {
        Vector<T> result(currentSize+other.currentSize);
        for(int i=0;i<currentSize;i++)
        {
            result.push_back(arr[i]);
        }
        for(int i=0;i<other.currentSize;i++)
        {
            result.push_back(other.arr[i]);
        }
        return result;

    }
    template<typename T>
    T& Vector<T>:: operator [](int index)
    {
        if(index<0 || index>=currentSize)
        {
            throw invalid_argument("OUT OF BOUNDS");
        }
        return arr[index];
    }
    template<typename T>
    bool Vector<T>:: operator==(const Vector<T> & other) const
    {
        if(currentSize!=other.currentSize)
        {
            return false;
        }
        for(int i=0;i<currentSize;i++)
        {
            if(arr[i]!=other.arr[i])
            {
                return false;
            }
        }
        return true;
    }
    template<typename T>
    bool Vector<T>:: operator >(const Vector<T>& other)const
    {
        if(currentSize>other.currentSize)
        {
            return true;
        }
        return false;
    }
    template<typename T>
    bool Vector<T>:: operator <(const Vector<T>& other)const
    {
        if(currentSize<other.currentSize)
        {
            return true;
        }
        return false;
    }
    template<typename T>
    Vector<T>& Vector<T>:: operator = (const Vector<T> & other)
    {
        if (this == &other) 
        {
            return *this;
        }
        if(arr!=nullptr)
        delete[] arr;
        currentSize = other.currentSize;
        maxSize = other.maxSize;
        arr = new T[maxSize];
        for (int i = 0; i < currentSize; ++i) 
        {
            cout<<other.arr[i]<<endl;
            arr[i] = other.arr[i];
        }
        return *this;
    }
    template<typename T>
    Vector<T> Vector<T>:: operator -(const Vector<T> &other) const
    {
        Vector<T> result;
        for (int i=0;i<currentSize;i++)
        {
            bool flag=false;
            for(int j=0;j<other.currentSize;j++)
            {
                if(arr[i]==other.arr[j])
                {
                    flag =true;
                    break;
                }
            }
            if(!flag)
            {
                result.push_back(arr[i]);
            }
            
        }
        return result;

    }
    template<typename T>
ostream & operator <<(ostream& out,const Vector<T>&  other)
{
    if (other.currentSize == 0)
    {
        out << "Vector is empty";
        return out;
    }
    for(int i=0;i<other.currentSize;i++)
    {
        out<<other.arr[i]<<"  ";
    }
    return out;
}
template<typename T>
istream & operator >> (istream & input,Vector<T> & other)
 {
    T num;
    other.currentSize = 0;
    while (input >> num)
    {
        other.push_back(num);
        if (input.peek() == '\n' || input.eof())
        {
            break;
        }
    }
    return input;
}