/**
 * implement a container like std::map
 */
#ifndef SJTU_MAP_HPP
#define SJTU_MAP_HPP

// only for std::less<T>
#include <functional>
#include <cstddef>
#include "utility.hpp"
#include "exceptions.hpp"
#include "binfstream.hpp"
#include "binfstream.hpp"

namespace sjtu {

template<
	class Key,
	class T,
	class Compare = std::less<Key>
> class map {
public:
	/**
	 * the internal type of data.
	 * it should have a default constructor, a copy constructor.
	 * You can use sjtu::map as value_type by typedef.
	 */
	typedef pair<const Key, T> value_type;
	/**
	 * see BidirectionalIterator at CppReference for help.
	 *
	 * if there is anything wrong throw invalid_iterator.
	 *     like it = map.begin(); --it;
	 *       or it = map.end(); ++end();
	 */
private:
	class node {
	public:
		node *lson, *rson;
		node *pre, *suc;
		size_t size;
		value_type *value;
		
		node(const value_type *v) {
			lson = rson = nullptr;
			pre = suc = nullptr;
			size = v == nullptr ? 0 : 1;
			if(v == nullptr) {
				value = nullptr;
			} else {
				value = new value_type(*v);
			}
		}
		
		void del() {
			delete value;
			delete this;
		}
		
		void clear() {
			if(this == nullptr) {
				return;
			}
			if(lson != nullptr) {
				lson->clear();
			}
			if(rson != nullptr) {
				rson->clear();
			}
			del();
		}
		
		void write(binofstream &fout) const {
			fout << size;
			if(value != nullptr) {
				fout << true;
				fout << value->first;
				fout << value->second;
			} else {
				fout << false;
			}
			if(lson != nullptr) {
				fout << true;
				lson->write(fout);
			} else {
				fout << false;
			}
			if(rson != nullptr) {
				fout << true;
				rson->write(fout);
			} else {
				fout << false;
			}
		}
		void read(binifstream &fin) {
			bool has;
			
			fin >> size;
			fin >> has;
			if(has == true) {
				Key key;
				T t;
				fin >> key;
				fin >> t;
				value = new value_type(key, t);
			}
			fin >> has;
			if(has == true) {
				lson = new node(nullptr);
				lson->read(fin);
			}
			fin >> has;
			if(has == true) {
				rson = new node(nullptr);
				rson->read(fin);
			}
		}
		void init(node *&pre) {
			if(lson != nullptr) {
				lson->init(pre);
			}
			
			if(pre != nullptr) {
				pre->suc = this;
			}
			this->pre = pre;
			this->suc = nullptr;
			pre = this;
			
			if(rson != nullptr) {
				rson->init(pre);
			}
		}
	};
	node *root, *endNode;
	Compare cmp;
	bool equal(const Key &a, const Key &b) const {
		return !(cmp(a, b) || cmp(b, a));
	}
	void LeftRotate(node *&x) {
		if(x == nullptr) {
			return;
		}
		node *k = x->rson;
		x->rson = k->lson;
		k->lson = x;
		k->size = x->size;
		x->size = x->value != nullptr ? 1 : 0;
		if(x->lson != nullptr) {
			x->size += x->lson->size;
		}
		if(x->rson != nullptr) {
			x->size += x->rson->size;
		}
		x = k;
	}
	void RightRotate(node *&x) {
		if(x == nullptr) {
			return;
		}
		node *k = x->lson;
		x->lson = k->rson;
		k->rson = x;
		k->size = x->size;
		x->size = x->value != nullptr ? 1 : 0;
		if(x->lson != nullptr) {
			x->size += x->lson->size;
		}
		if(x->rson != nullptr) {
			x->size += x->rson->size;
		}
		x = k;
	}
	void maintain(node *&u, const bool flag) {
		if(u == nullptr) {
			return;
		}
		if(flag == false) {
			if(u->lson != nullptr) {
				if(u->lson->lson != nullptr && (u->rson == nullptr || u->lson->lson->size > u->rson->size)) {
					RightRotate(u);
				} else {
					if(u->lson->rson != nullptr && (u->rson == nullptr || u->lson->rson->size > u->rson->size)) {
						LeftRotate(u->lson);
						RightRotate(u);
					} else {
						return;
					}
				}
			} else {
				return;
			}
		} else {
			if(u->rson != nullptr) {
				if(u->rson->rson != nullptr && (u->lson == nullptr || u->rson->rson->size > u->lson->size)) {
					LeftRotate(u);
				} else {
					if(u->rson->lson != nullptr && (u->lson == nullptr || u->rson->lson->size > u->lson->size)) {
						RightRotate(u->rson);
						LeftRotate(u);
					} else {
						return;
					}
				}
			} else {
				return;
			}
		}
		maintain(u->lson, false);
		maintain(u->rson, true);
		maintain(u, true);
		maintain(u, false);
	}
	node* find(node *u, const Key &k) const {
		while(u != nullptr) {
			if(u == endNode || cmp(k, u->value->first)) {
				u = u->lson;
			} else if(equal(u->value->first, k)) {
				return u;
			} else {
				u = u->rson;
			}
		}
		return nullptr;
	}
	node* getpre(node *u, const Key &k) const {
		node* res = nullptr;
		while(u != nullptr) {
			if(u == endNode || cmp(k, u->value->first)) {
				u = u->lson;
			} else {
				res = u;
				u = u->rson;
			}
		}
		return res;
	}
	node* getsuc(node *u, const Key &k) const {
		node* res = nullptr;
		while(u != nullptr) {
			if(u != endNode && cmp(u->value->first, k)) {
				u = u->rson;
			} else {
				res = u;
				u = u->lson;
			}
		}
		return res;
	}
	node* _insert(node *&u, const value_type *v) {
		if(u == nullptr) {
			return u = new node(v);
		} else {
			node* ret;
			u->size++;
			if(u == endNode || cmp(v->first, u->value->first)) {
				ret = _insert(u->lson, v);
			} else {
				ret = _insert(u->rson, v);
			}
			maintain(u, !(u == endNode || cmp(v->first, u->value->first)));
			return ret;
		}
	}
	pair<node*, bool> ninsert(const value_type *v) {
		node *ret = find(root, v->first);
		if(ret != nullptr) {
			return make_pair(ret, false);
		} else {
			node *pre = getpre(root, v->first), *suc = getsuc(root, v->first);
			node *nd = _insert(root, v);
			if(pre != nullptr) {
				pre->suc = nd;
			}
			if(suc != nullptr) {
				suc->pre = nd;
			}
			nd->pre = pre;
			nd->suc = suc;
			return make_pair(nd, true);
		}
	}
	void erase(node *&u, const Key &k) {
		u->size--;
		if(u != endNode && equal(u->value->first, k)) {
			if(u->lson == nullptr) {
				node *tmp = u->rson;
				if(u->pre != nullptr) {
					u->pre->suc = u->suc;
				}
				u->suc->pre = u->pre;
				u->del();
				u = tmp;
			} else if(u->rson == nullptr) {
				node *tmp = u->lson;
				if(u->pre != nullptr) {
					u->pre->suc = u->suc;
				}
				u->suc->pre = u->pre;
				u->del();
				u = tmp;
			} else {
				node *l = u->lson, *fa = u;
				while(l->rson != nullptr) {
					fa = l;
					l = l->rson;
				}
				l->size = u->size;
				if(fa != u) {
					fa->rson = l->lson;
					l->lson = u->lson;
				}
				l->rson = u->rson;
				u->pre->suc = u->suc;
				u->suc->pre = u->pre;
				u->del();
				u = l;
			}
		} else {
			if(u == endNode || cmp(k, u->value->first)) {
				erase(u->lson, k);
			} else {
				erase(u->rson, k);
			}
		}
	}
	node* getbegin(node *u) const {
		while(u->lson != nullptr) {
			u = u->lson;
		}
		return u;
	}
	node* getend(node *u) const {
		while(u->rson != nullptr) {
			u = u->rson;
		}
		return u;
	}
	void copy(node *&to, const node *from, node *&last) {
		to = new node(from->value);
		to->size = from->size;
		if(from->lson != nullptr) {
			copy(to->lson, from->lson, last);
		}
		to->pre = last;
		to->suc = nullptr;
		if(last != nullptr) {
			last->suc = to;
		}
		last = to;
		if(from->rson != nullptr) {
			copy(to->rson, from->rson, last);
		}
	}
public:
	class const_iterator;
	class iterator {
	private:
		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
		 node *nd;
	public:
			friend class const_iterator;
		iterator() {
			// TODO
			nd = nullptr;
		}
		iterator(const iterator &other) {
			// TODO
			nd = other.nd;
		}
		iterator(node* nd):nd(nd) { }
		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, just return the answer.
		 * as well as operator-
		 */
		/**
		 * TODO iter++
		 */
		iterator operator++(int) {
			iterator tmp(nd);
			if(nd != nullptr) {
				if(nd->suc == nullptr) {
					throw invalid_iterator();
				}
				nd = nd->suc;
			}
			return tmp;
		}
		/**
		 * TODO ++iter
		 */
		iterator & operator++() {
			if(nd != nullptr) {
				if(nd->suc == nullptr) {
					throw invalid_iterator();
				}
				nd = nd->suc;
			}
			return *this;
		}
		/**
		 * TODO iter--
		 */
		iterator operator--(int) {
			iterator tmp(nd);
			if(nd != nullptr) {
				if(nd->pre == nullptr) {
					throw invalid_iterator();
				}
				nd = nd->pre;
			}
			return tmp;
		}
		/**
		 * TODO --iter
		 */
		iterator & operator--() {
			if(nd != nullptr) {
				if(nd->pre == nullptr) {
					throw invalid_iterator();
				}
				nd = nd->pre;	
			}
			return *this;
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		value_type & operator*() const {
			return *nd->value;
		}
		bool operator==(const iterator &rhs) const {
			return nd == rhs.nd;
		}
		bool operator==(const const_iterator &rhs) const {
			return nd == rhs.nd;
		}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const {
			return nd != rhs.nd;
		}
		bool operator!=(const const_iterator &rhs) const {
			return nd != rhs.nd;
		}
		/**
		 * for the support of it->first. 
		 * See <http://kelvinh.github.io/blog/2013/11/20/overloading-of-member-access-operator-dash-greater-than-symbol-in-cpp/> for help.
		 */
		value_type* operator->() const {
			if(nd->value == nullptr) {
				throw invalid_iterator();
			}
			return nd->value;
		}
	};
	class const_iterator {
		// it should has similar member method as iterator.
		//  and it should be able to construct from an iterator.
		private:
			// data members.
		 	node *nd;
		public:
			friend class iterator;
			const_iterator() {
				// TODO
				nd = nullptr;
			}
			const_iterator(const const_iterator &other) {
				// TODO
				nd = other.nd;
			}
			const_iterator(const iterator &other) {
				// TODO
				nd = other.nd;
			}
			/**
			 * TODO iter++
			 */
			const_iterator operator++(int) {
				const_iterator tmp(nd);
				if(nd != nullptr) {
					if(nd->suc == nullptr) {
						throw invalid_iterator();
					}
					nd = nd->suc;
				}
				return tmp;
			}
			/**
			 * TODO ++iter
			 */
			const_iterator & operator++() {
				if(nd != nullptr) {
					if(nd->suc == nullptr) {
						throw invalid_iterator();
					}
					nd = nd->suc;
				}
				return *this;
			}
			/**
			 * TODO iter--
			 */
			const_iterator operator--(int) {
				const_iterator tmp(nd);
				if(nd != nullptr) {
					if(nd->pre == nullptr) {
						throw invalid_iterator();
					}
					nd = nd->pre;
				}
				return tmp;
			}
			/**
			 * TODO --iter
			 */
			const_iterator & operator--() {
				if(nd != nullptr) {
					if(nd->pre == nullptr) {
						throw invalid_iterator();
					}
					nd = nd->pre;	
				}
				return *this;
			}
			value_type & operator*() const {
				return *nd->value;
			}
			bool operator==(const iterator &rhs) const {
				return nd == rhs.nd;
			}
			bool operator==(const const_iterator &rhs) const {
				return nd == rhs.nd;
			}
			/**
			 * some other operator for iterator.
			 */
			bool operator!=(const iterator &rhs) const {
				return nd != rhs.nd;
			}
			bool operator!=(const const_iterator &rhs) const {
				return nd != rhs.nd;
			}
			value_type* operator->() const {
				if(nd->value == nullptr) {
					throw invalid_iterator();
				}
				return nd->value;
			}
	};
	/**
	 * TODO two constructors
	 */
	map() {
		endNode = new node(nullptr);
		root = endNode;
	}
	map(const map &other) {
		node *null = nullptr;
		copy(root, other.root, null);
		endNode = getend(root);
	}
	/**
	 * TODO assignment operator
	 */
	map & operator=(const map &other) {
		if(root != other.root) {
			node *null = nullptr;
			copy(root, other.root, null);
			endNode = getend(root);
		}
		return *this;
	}
	/**
	 * TODO Destructors
	 */
	~map() {
		root->clear();
	}
	/**
	 * TODO
	 * access specified element with bounds checking
	 * Returns a reference to the mapped value of the element with key equivalent to key.
	 * If no such element exists, an exception of type `index_out_of_bound'
	 */
	T & at(const Key &key) {
		node *nd = find(root, key);
		if(nd == nullptr) {
			throw invalid_iterator();
		}
		return nd->value->second;
	}
	const T & at(const Key &key) const {
		node *nd = find(root, key);
		if(nd == nullptr) {
			throw invalid_iterator();
		}
		return nd->value->second;
	}
	/**
	 * TODO
	 * access specified element 
	 * Returns a reference to the value that is mapped to a key equivalent to key,
	 *   performing an insertion if such key does not already exist.
	 */
	T & operator[](const Key &key) {
		value_type v = sjtu::make_pair(key, T());
		return ninsert(&v).first->value->second;
	}
	/**
	 * behave like at() throw index_out_of_bound if such key does not exist.
	 */
	const T & operator[](const Key &key) const {
		node *nd = find(root, key);
		if(nd == nullptr) {
			throw invalid_iterator();
		}
		return nd->value->second;
		
	}
	/**
	 * return a iterator to the beginning
	 */
	iterator begin() {
		iterator it(getbegin(root));
		return it;
	}
	const_iterator cbegin() const {
		const_iterator it(getbegin(root));
		return it;
	}
	/**
	 * return a iterator to the end
	 * in fact, it returns past-the-end.
	 */
	iterator end() {
		iterator it(endNode);
		return it;
	}
	const_iterator cend() const {
		const_iterator it(endNode);
		return it;
	}
	/**
	 * checks whether the container is empty
	 * return true if empty, otherwise false.
	 */
	bool empty() const {
		return root->size == 0;
	}
	/**
	 * returns the number of elements.
	 */
	size_t size() const {
		return root->size;
	}
	/**
	 * clears the contents
	 */
	void clear() {
		root->clear();
		endNode = new node(nullptr);
		root = endNode;
	}
	/**
	 * insert an element.
	 * return a pair, the first of the pair is
	 *   the iterator to the new element (or the element that prevented the insertion), 
	 *   the second one is true if insert successfully, or false.
	 */
	pair<iterator, bool> insert(const value_type &value) {
		pair<node*, bool> ret = ninsert(&value);
		iterator it(ret.first);
		return make_pair(it, ret.second);
	}
	/**
	 * erase the element at pos.
	 *
	 * throw if pos pointed to a bad element (pos == this->end() || pos points an element out of this)
	 */
	void erase(const iterator &pos) {
		if(pos == end()) {
			throw invalid_iterator();
			return;
		}
		node *nd = find(root, pos->first);
		iterator it(nd);
		if(it == pos) {
			erase(root, pos->first);
		} else {
			throw invalid_iterator();
		}
	}
	/**
	 * Returns the number of elements with key 
	 *   that compares equivalent to the specified argument,
	 *   which is either 1 or 0 
	 *     since this container does not allow duplicates.
	 * The default method of check the equivalence is !(a < b || b > a)
	 */
	size_t count(const Key &key) const {
		return find(root, key) != nullptr;
	}
	/**
	 * Finds an element with key equivalent to key.
	 * key value of the element to search for.
	 * Iterator to an element with key equivalent to key.
	 *   If no such element is found, past-the-end (see end()) iterator is returned.
	 */
	iterator find(const Key &key) {
		node *nd = find(root, key);
		if(nd == nullptr) {
			nd = endNode;
		}
		return iterator(nd);
	}
	const_iterator find(const Key &key) const {
		node *nd = find(root, key);
		if(nd == nullptr) {
			nd = endNode;
		}
		return const_iterator(nd);
	}
	
	friend binifstream operator>>(binifstream &fin, map &map) {
		map.clear();
		
		map.root = new node(nullptr);
		map.root->read(fin);
		map.endNode = map.getend(map.root);
		
		node *null = nullptr;
		map.root->init(null);
		return fin;
	}
	friend binofstream operator<<(binofstream &fout, const map &map) {
		map.root->write(fout);
		return fout;
	}
};

}

#endif
