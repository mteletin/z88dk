//-----------------------------------------------------------------------------
// zlink - object store name -> (ID, object), owns the objects
// Copyright (c) Paulo Custodio, 2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#ifndef STORE_H_
#define STORE_H_

#include <string>
#include <vector>
#include <map>

template<class T>
class Store {
public:
	Store();
	virtual ~Store();

	// get metrics
	bool empty() const;
	std::size_t size() const;
	
	// check if object exists
	bool exists(const std::string& name) const;			
	bool exists(unsigned id) const;
	
	// get ID of NAME, id_not_found() if not found
	static unsigned id_not_found() { return static_cast<unsigned>(-1); }
	unsigned get_id(const std::string& name) const;	

	// get NAME of ID, name_not_found() if not found
	static const std::string& name_not_found() { static std::string s; return s; }
	const std::string& get_name(unsigned id) const;

	// get stored object, NULL if none, set current object
	T* get_obj(const std::string& name);
	T* get_obj(unsigned id);

	// add/update object, delete old of the same name if found, set current object
	void set(const std::string& name, T* obj);

	// get current object
	unsigned cur_id() const;
	const std::string& cur_name() const;
	T* cur_obj();

private:
	std::vector<T*>					objs_;
	std::vector<std::string>		names_;
	std::map<std::string, unsigned>	ids_;
	unsigned						cur_id_;	// last referenced object
};

//-----------------------------------------------------------------------------
// Implementation
//-----------------------------------------------------------------------------
template<class T>
Store<T>::Store() 
	: cur_id_(0) {}

//-----------------------------------------------------------------------------
template<class T>
Store<T>::~Store() {
	for (std::vector<T*>::iterator it = objs_.begin(); it != objs_.end(); ++it)
		delete *it;
}

//-----------------------------------------------------------------------------
template<class T>
bool Store<T>::empty() const {
	return objs_.empty();
}

//-----------------------------------------------------------------------------
template<class T>
std::size_t Store<T>::size() const {
	return objs_.size();
}

//-----------------------------------------------------------------------------
template<class T>
bool Store<T>::exists(const std::string& name) const {
	std::map<std::string, unsigned>::const_iterator it = ids_.find(name);
	if (it == ids_.end())
		return false;
	else
		return true;
}

//-----------------------------------------------------------------------------
template<class T>
bool Store<T>::exists(unsigned id) const {
	if (id >= size())
		return false;
	else
		return true;
}

//-----------------------------------------------------------------------------
template<class T>
unsigned Store<T>::get_id(const std::string& name) const {
	std::map<std::string, unsigned>::const_iterator it = ids_.find(name);
	if (it == ids_.end()) 
		return id_not_found();
	else
		return it->second;
}

//-----------------------------------------------------------------------------
template<class T>
const std::string& Store<T>::get_name(unsigned id) const {
	if (id >= size()) 
		return name_not_found();
	else 
		return names_[id];
}

//-----------------------------------------------------------------------------
template<class T>
T* Store<T>::get_obj(const std::string& name) {
	std::map<std::string, unsigned>::const_iterator it = ids_.find(name);
	if (it == ids_.end()) {
		return NULL;
	}
	else {
		cur_id_ = it->second;
		return objs_[cur_id_];
	}
}

//-----------------------------------------------------------------------------
template<class T>
T* Store<T>::get_obj(unsigned id) {
	if (id >= size()) {
		return NULL;
	}
	else {
		cur_id_ = id;
		return objs_[cur_id_];
	}
}

//-----------------------------------------------------------------------------
template<class T>
void Store<T>::set(const std::string& name, T* obj) {
	std::map<std::string, unsigned>::const_iterator it = ids_.find(name);
	if (it == ids_.end()) {
		cur_id_ = size();
		names_.push_back(name);
		objs_.push_back(obj);
		ids_.insert(std::pair<std::string, unsigned>(name, cur_id_));
	}
	else {
		cur_id_ = it->second;
		delete objs_[cur_id_];
		objs_[cur_id_] = obj;
	}
}


//-----------------------------------------------------------------------------
template<class T>
unsigned Store<T>::cur_id() const {
	if (cur_id_ < size())
		return cur_id_;
	else
		return id_not_found();
}

//-----------------------------------------------------------------------------
template<class T>
const std::string& Store<T>::cur_name() const {
	if (cur_id_ < size())
		return names_[cur_id_];
	else
		return name_not_found();
}

//-----------------------------------------------------------------------------
template<class T>
T* Store<T>::cur_obj() {
	if (cur_id_ < size())
		return objs_[cur_id_];
	else
		return NULL;
}

#endif // ndef STORE_H_
