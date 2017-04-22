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
		T *tem = data;
		Maxsize *= 2;
		data = (T*)::operator new(Maxsize*sizeof(T));
		for(int i = 0;i < currentLen;i++){
			data[i] = tem[i];
		}
		for(int i = Maxsize/2 - 1;i >= 0;i--){
			T* p = tem + i;
			p -> ~T();	
		}
		::operator delete(tem);
	}
	
	class const_iterator;
	class iterator {
		friend vector;
	private:
		int cur;
		vector *father;
		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
	public:
		iterator(vector * f = NULL,int p = 0):father(f),cur(p){}
		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, just return the answer.???????
		 * as well as operator-
		 */
		iterator operator+(const int &n) const {
			return iterator((*this).father,cur + n);
			//TODO
		}
		iterator operator-(const int &n) const {
			return iterator((*this).father,cur - n);
			//TODO
		}
		// return th distance between two iterator,
		// if these two iterators points to different vectors, throw invaild_iterator.
		int operator-(const iterator &rhs) const {
			if((*this).father != rhs.father)throw invalid_iterator();
			else return cur - rhs.cur;
			//TODO
		}
		iterator operator+=(const int &n) {
			return iterator((*this).father,cur + n);
			//TODO
		}
		iterator operator-=(const int &n){
			return iterator((*this).father,cur - n);
			//TODO
		}
		/**
		 * TODO iter++
		 */
		iterator operator++(int) {
			cur++;
			return iterator((*this).father,cur - 1);
		}
		/**
		 * TODO ++iter
		 */
		iterator& operator++() {
			cur++;
			return *this;
		}
		/**
		 * TODO iter--
		 */
		iterator operator--(int) {
			cur--;
			return iterator((*this).father,cur + 1);
		}
		/**
		 * TODO --iter
		 */
		iterator& operator--() {
			cur--;
			return *this;
		}
		/**
		 * TODO *it
		 */
		T& operator*() const{
			return (*father)[cur];
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		bool operator==(const iterator &rhs) const {
			return cur == rhs.cur;
		}
		bool operator==(const const_iterator &rhs) const {
			return cur == rhs.cur;
		}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const {
			return cur != rhs.cur;
		}
		bool operator!=(const const_iterator &rhs) const {
			return cur != rhs.cur;
		}
	};
	/**
	 * TODO
	 * has same function as iterator, just for a const object.
	 */
	 
class const_iterator {
		friend vector;
	private:
		int cur;
		const vector *father;
		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
	public:
		const_iterator(const vector * f,int p = 0):father(f),cur(p){}
		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, just return the answer.???????
		 * as well as operator-
		 */
		const_iterator operator+(const int &n) const {
			return iterator((*this).father,cur + n);
			//TODO
		}
		const_iterator operator-(const int &n) const {
			return iterator((*this).father,cur - n);
			//TODO
		}
		// return th distance between two iterator,
		// if these two iterators points to different vectors, throw invaild_iterator.
		int operator-(const iterator &rhs) const {
			if((*this).father != rhs.father)throw invalid_iterator();
			else return cur - rhs.cur;
			//TODO
		}
		const_iterator operator+=(const int &n) {
			return const_iterator((*this).father,cur + n);
			//TODO
		}
		const_iterator operator-=(const int &n){
			return const_iterator((*this).father,cur - n);
			//TODO
		}
		/**
		 * TODO iter++
		 */
		const_iterator operator++(int) {
			cur++;
			return const_iterator((*this).father,cur - 1);
		}
		/**
		 * TODO ++iter
		 */
		const_iterator& operator++() {
			cur++;
			return *this;
		}
		/**
		 * TODO iter--
		 */
		const_iterator operator--(int) {
			cur--;
			return const_iterator((*this).father,cur + 1);
		}
		/**
		 * TODO --iter
		 */
		const_iterator& operator--() {
			cur--;
			return *this;
		}
		/**
		 * TODO *it
		 */
		const T& operator*() const{
			return (*father)[cur];
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		bool operator==(const iterator &rhs) const {
			return cur == rhs.cur;
		}
		bool operator==(const const_iterator &rhs) const {
			return cur == rhs.cur;
		}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const {
			return cur != rhs.cur;
		}
		bool operator!=(const const_iterator &rhs) const {
			return cur != rhs.cur;
		}

	};
	/**
	 * TODO Constructs
	 * Atleast three: default constructor, copy constructor and a constructor for std::vector
	 */
	vector(int initsize = 10) {
		data = (T*)::operator new(sizeof(T)*initsize);
		Maxsize = initsize;
		currentLen = 0;
	}
	vector(const vector &other) {
		Maxsize = other.capacity();
		currentLen = other.size();
		data = (T*)::operator new(sizeof(T)*Maxsize);      //?duole
		for(int i = 0;i < currentLen;i++)data[i] = other[i];
	}
	/**
	 * TODO Destructor
	 */
	~vector() {
		for(int i = Maxsize - 1;i >= 0;i--){
			T* p = data + i;
			p -> ~T();	
		} 
		::operator delete(data);
	//	::operator delete(data);
	}
	/**
	 * TODO Assignment operator
	 */
	vector &operator=(const vector &other) {
		clear();
		currentLen = other.size();
		Maxsize = other.capacity();
		data = (T*)::operator new(sizeof(T)*Maxsize);
		for(int i = 0;i < currentLen;i++)data[i] = other[i];
	}
	/**
	 * assigns specified element with bounds checking
	 * throw index_out_of_bound if pos is not in [0, size)
	 */
	T & at(const size_t &pos) {
		if(pos<0 || pos >= Maxsize)throw index_out_of_bound();
		return data[pos];
	}
	const T & at(const size_t &pos) const {
		if(pos<0 || pos >= Maxsize)throw index_out_of_bound();
		return data[pos];
	}
	/**
	 * assigns specified element with bounds checking
	 * throw index_out_of_bound if pos is not in [0, size)
	 * !!! Pay attentions
	 *   In STL this operator does not check the boundary but I want you to do.
	 */
	T & operator[](const size_t &pos) {
		if(pos<0 || pos >= Maxsize)throw index_out_of_bound();
		return data[pos];
	}
	const T & operator[](const size_t &pos) const {
		if(pos<0 || pos >= Maxsize)throw index_out_of_bound();
		return data[pos];
	}
	/**
	 * access the first element.
	 * throw container_is_empty if size == 0
	 */
	const T & front() const {
		if(currentLen == 0)throw container_is_empty();
		return data[0];
	}
	/**
	 * access the last element.
	 * throw container_is_empty if size == 0
	 */
	const T & back() const {
		if(currentLen == 0)throw container_is_empty();
		return data[currentLen - 1];
	}
	/**
	 * returns an iterator to the beginning.
	 */
	iterator begin() {                                  //ERROR???
		return iterator(this,0);
	}
	const_iterator cbegin() const {
		return const_iterator(this,0);
	}
	/**
	 * returns an iterator to the end.
	 */
	iterator end() {
		return iterator(this,currentLen);
	}
	const_iterator cend() const {
		return const_iterator(this,currentLen);
	}
	/**
	 * checks whether the container is empty
	 */
	bool empty() const {
		return currentLen == 0;
	}
	/**
	 * returns the number of elements
	 */
	size_t size() const {
		return currentLen;
	}
	/**
	 * returns the number of elements that can be held in currently allocated storage.
	 */
	size_t capacity() const {
		return Maxsize;
	}
	/**
	 * clears the contents
	 */
	void clear() {           //???
		for(int i = Maxsize - 1;i >= 0;i--){
			T* p = data + i;
			p -> ~T();	
		} 
		::operator delete(data);
		Maxsize = currentLen = 0;
	}
	/**
	 * inserts value before pos
	 * returns an iterator pointing to the inserted value.
	 */
	iterator insert(iterator pos, const T &value) {
//		if(pos - begin() < 0 || end() - pos < 0)throw index_out_of_bound();  //自己加的
		if(currentLen == Maxsize)doublespace();
		int ind = pos - begin();
		for(int i = currentLen;i > ind;i--)data[i] = data[i - 1]; 
		data[ind] = value;
		currentLen++;
		return iterator(this,ind);
	}
	/**
	 * inserts value at index ind.
	 * after inserting, this->at(ind) == value is true
	 * returns an iterator pointing to the inserted value.
	 * throw index_out_of_bound if ind > size (in this situation ind can be size because after inserting the size will increase 1.)
	 */
	iterator insert(const size_t &ind, const T &value) {
		if(ind > currentLen)throw index_out_of_bound();
		if(currentLen == Maxsize)doublespace();
		new (data+(currentLen)) T(data[currentLen - 1]);
		for(int i = currentLen - 1;i > ind;i--)data[i] = data[i-1];
		data[ind] = value;
		currentLen++;
		return iterator(this,ind);
	}
	/**
	 * removes the element at pos.
	 * return an iterator pointing to the following element.
	 * If the iterator pos refers the last element, the end() iterator is returned.
	 */
	iterator erase(iterator pos) {
		if(pos - end() == 1){
			currentLen--;
			return end();
		}
		else{
			for(int i = pos - begin();i<currentLen - 1;i++)data[i] = data[i + 1];
			currentLen--;
			return pos;
		}
	}
	/**
	 * removes the element with index ind.
	 * return an iterator pointing to the following element.
	 * throw index_out_of_bound if ind >= size
	 */
	iterator erase(const size_t &ind) {
		if(ind >= currentLen)throw index_out_of_bound();
		for(int i = ind;i<currentLen - 1;i++)data[i] = data[i + 1];
			currentLen--;
		return iterator(this,ind);
	}
	/**
	 * adds an element to the end.
	 */
	void push_back(const T &value) {
		if(currentLen == Maxsize)doublespace();
		new (data+(currentLen++)) T(value);
	}
	/**
	 * remove the last element from the end.
	 * throw container_is_empty if size() == 0
	 */
	void pop_back() {
		if(size() == 0)throw container_is_empty();
		currentLen--;
	}
};


}

#endif
