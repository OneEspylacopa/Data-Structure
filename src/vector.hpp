#ifndef SJTU_VECTOR_HPP
#define SJTU_VECTOR_HPP

#include "exceptions.hpp"

#include <climits>
#include <cstddef>

namespace sjtu {
/**
 * a data container like std::vector
 * store data in a successive memory and support random access.
 */
template<class T>
class vector {

    /**
     * TODO
     * a type for actions of the elements of a vector, and you should write
     *   a class named const_iterator with same interfaces.
     */
    /**
     * you can see RandomAccessIterator at CppReference for help.
     */
private:
    T *data;
    int Maxsize;
    int currentLen;
public:
    void doublespace(){
    	if(data == NULL){                        //add
    		Maxsize = 10;
    		data = (T*)::operator new(Maxsize*sizeof(T));
    		return;
		} 
        T *tem = data;
        Maxsize *= 2;
        data = (T*)::operator new(Maxsize*sizeof(T));
        for(int i = 0;i < currentLen;i++){
            new (data + i) T(tem[i]);
        }
        for(int i = Maxsize/2 - 1;i >= 0;i--){
            T* p = tem + i;
            p -> ~T();
        }
        ::operator delete(tem);
    }

    void resize(size_t size){
    	if(data == NULL){
    		Maxsize = 10;
    		data = (T*)::operator new(Maxsize*sizeof(T));
		}
        if(size < currentLen){
            for(int i = size;i < currentLen;i++){
                T* p = data + i;
                p -> ~T();
            }
            currentLen = size;
        }

        else if(size > Maxsize){
            T *tem = data;
            data = (T*)::operator new(size * sizeof(T));
            for(int i = 0;i < currentLen;i++){
                new (data + i) T(tem[i]);
            }
            for(int i = currentLen;i < size;i++){
                new (data + i) T();
            }
            for(int i = currentLen - 1;i >= 0;i--){
                T* p = tem + i;
                p -> ~T();
            }
            ::operator delete(tem);
            currentLen = Maxsize = size;
        }

        else{
            for(int i = currentLen;i < size;i++){
                new (data + i) T();
            }
            currentLen = size;
        }
    }


    class const_iterator;
    class iterator {
        friend vector;
    private:
        int cur;
        vector *father;
    public:
        iterator(vector * f = NULL,int p = 0):father(f),cur(p){}
        iterator operator+(const int &n) const {
            return iterator((*this).father,cur + n);
        }
        iterator operator-(const int &n) const {
            return iterator((*this).father,cur - n);
        }
        int operator-(const iterator &rhs) const {
            if((*this).father != rhs.father)throw invalid_iterator();
            else return cur - rhs.cur;
        }
        iterator operator+=(const int &n) {
            return iterator((*this).father,cur + n);
        }
        iterator operator-=(const int &n){
            return iterator((*this).father,cur - n);
        }
        iterator operator++(int) {
            cur++;
            return iterator((*this).father,cur - 1);
        }
        iterator& operator++() {
            cur++;
            return *this;
        }
        iterator operator--(int) {
            cur--;
            return iterator((*this).father,cur + 1);
        }
        iterator& operator--() {
            cur--;
            return *this;
        }
        T& operator*() const{
            return (*father)[cur];
        }
        bool operator==(const iterator &rhs) const {
            return cur == rhs.cur;
        }
        bool operator==(const const_iterator &rhs) const {
            return cur == rhs.cur;
        }
        bool operator!=(const iterator &rhs) const {
            return cur != rhs.cur;
        }
        bool operator!=(const const_iterator &rhs) const {
            return cur != rhs.cur;
        }
        T* operator->(){return &((*father)[cur]);}
    };

class const_iterator {
        friend vector;
    private:
        int cur;
        const vector *father;
    public:
        const_iterator(const vector * f,int p = 0):father(f),cur(p){}
        const_iterator operator+(const int &n) const {
            return iterator((*this).father,cur + n);
        }
        const_iterator operator-(const int &n) const {
            return iterator((*this).father,cur - n);
        }
        int operator-(const iterator &rhs) const {
            if((*this).father != rhs.father)throw invalid_iterator();
            else return cur - rhs.cur;
        }
        const_iterator operator+=(const int &n) {
            return const_iterator((*this).father,cur + n);
        }
        const_iterator operator-=(const int &n){
            return const_iterator((*this).father,cur - n);
        }
        const_iterator operator++(int) {
            cur++;
            return const_iterator((*this).father,cur - 1);
        }
        const_iterator& operator++() {
            cur++;
            return *this;
        }
        const_iterator operator--(int) {
            cur--;
            return const_iterator((*this).father,cur + 1);
        }
        const_iterator& operator--() {
            cur--;
            return *this;
        }
        const T& operator*() const{
            return (*father)[cur];
        }
        bool operator==(const iterator &rhs) const {
            return cur == rhs.cur;
        }
        bool operator==(const const_iterator &rhs) const {
            return cur == rhs.cur;
        }
        bool operator!=(const iterator &rhs) const {
            return cur != rhs.cur;
        }
        bool operator!=(const const_iterator &rhs) const {
            return cur != rhs.cur;
        }
        const T* operator->(){return &((*father)[cur]);}
    };
    vector(size_t initsize = 10) {
        data = (T*)::operator new(sizeof(T)*initsize);
        Maxsize = initsize;
        currentLen = 0;
    }
    vector(const vector &other) {
        Maxsize = other.capacity();
        currentLen = other.size();
        data = (T*)::operator new(sizeof(T)*Maxsize);
        for(int i = 0;i < currentLen;i++)
            new (data + i) T (other[i]);
    }
    ~vector() {
    	if(data == NULL)return;
        for(int i = currentLen - 1;i >= 0;i--){
            T* p = data + i;
            p -> ~T();
        }
        ::operator delete(data);
    }
    vector &operator=(const vector &other) {
        clear();
        currentLen = other.size();
        Maxsize = other.capacity();
        data = (T*)::operator new(sizeof(T)*Maxsize);
        for(int i = 0;i < currentLen;i++)
            new (data + i) T (other[i]);
    }
    T & at(const size_t &pos) {
        if(pos<0 || pos >= Maxsize)throw index_out_of_bound();
        return data[pos];
    }
    const T & at(const size_t &pos) const {
        if(pos<0 || pos >= Maxsize)throw index_out_of_bound();
        return data[pos];
    }
    T & operator[](const size_t &pos) {
        if(pos<0 || pos >= Maxsize)throw index_out_of_bound();
        return data[pos];
    }
    const T & operator[](const size_t &pos) const {
        if(pos<0 || pos >= Maxsize)throw index_out_of_bound();
        return data[pos];
    }
    const T & front() const {
        if(currentLen == 0)throw container_is_empty();
        return data[0];
    }
    const T & back() const {
        if(currentLen == 0)throw container_is_empty();
        return data[currentLen - 1];
    }
    iterator begin() {                                  //ERROR???
        return iterator(this,0);
    }
    const_iterator cbegin() const {
        return const_iterator(this,0);
    }
    iterator end() {
        return iterator(this,currentLen);
    }
    const_iterator cend() const {
        return const_iterator(this,currentLen);
    }
    bool empty() const {
        return currentLen == 0;
    }
    size_t size() const {
        return currentLen;
    }
    size_t capacity() const {
        return Maxsize;
    }
    void clear() {
        for(int i = currentLen - 1;i >= 0;i--){
            T* p = data + i;
            p -> ~T();
        }
        ::operator delete(data);
        Maxsize = currentLen = 0;
        data = NULL;
    }
    iterator insert(iterator pos, const T &value) {
        if(currentLen == Maxsize)doublespace();
        int ind = pos - begin();
        new (data + currentLen) T(data[currentLen - 1]);
        for(int i = currentLen - 1;i > ind;i--)data[i] = data[i - 1];
        data[ind] = value;
        currentLen++;
        return iterator(this,ind);
    }
    iterator insert(const size_t &ind, const T &value) {
        if(ind > currentLen)throw index_out_of_bound();
        if(currentLen == Maxsize)doublespace();
        new (data+(currentLen)) T(data[currentLen - 1]);
        for(int i = currentLen - 1;i > ind;i--)data[i] = data[i-1];
        data[ind] = value;
        currentLen++;
        return iterator(this,ind);
    }
    iterator erase(iterator pos) {
        if(pos - end() == 1){
            currentLen--;
            T*p = data + currentLen;
            p-> ~T();
            return end();
        }
        else{
            for(int i = pos - begin();i<currentLen - 1;i++)data[i] = data[i + 1];
            currentLen--;
            T*p = data + currentLen;
            p-> ~T();
            return pos;
        }
    }
    iterator erase(const size_t &ind) {
        if(ind >= currentLen)throw index_out_of_bound();
        for(int i = ind;i<currentLen - 1;i++)data[i] = data[i + 1];
            currentLen--;
            T*p = data + currentLen;
            p-> ~T();
        return iterator(this,ind);
    }
    void push_back(const T &value) {
        if(currentLen == Maxsize)doublespace();
        new (data+(currentLen++)) T(value);
    }
    void pop_back() {
        if(size() == 0)throw container_is_empty();
        currentLen--;
        T*p = data + currentLen;
        p-> ~T();
    }
};


}

#endif

