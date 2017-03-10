//-----------------------------------------------------------------------------
// Unit tests
// Copyright (c) Paulo Custodio, 2015-2017
// License: http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------
#include "../memcheck.h"
#include "../store.h"
#include "taptest.h"

class Name {
public:
	Name(const std::string& name) : name_(new std::string(name)) {}
	virtual ~Name() { delete name_; }

private:
	std::string* name_;
};

int main() {
	START_TESTING();

	// empty
	Store<Name> d;
	OK(d.empty());
	IS(d.size(), 0);

	NOK(d.exists(0));
	NOK(d.exists(1));
	NOK(d.exists("f0"));
	NOK(d.exists("f1"));

	IS(d.get_obj(0), NULL);
	IS(d.get_obj(1), NULL);
	IS(d.get_obj("f0"), NULL);
	IS(d.get_obj("f1"), NULL);

	IS(d.get_id("f0"), d.id_not_found());
	IS(d.get_id("f1"), d.id_not_found());

	IS(d.get_name(0), d.name_not_found());
	IS(d.get_name(1), d.name_not_found());

	// set
	Name* name0 = new Name("name0");
	Name* name1 = new Name("name1");

	d.set("f0", name0); 
	IS(d.cur_id(), 0);
	IS(d.cur_name(), "f0");
	IS(d.cur_obj(), name0);

	d.set("f1", name1); 
	IS(d.cur_id(), 1);
	IS(d.cur_name(), "f1");
	IS(d.cur_obj(), name1);

	IS(d.get_obj("f0"), name0);
	IS(d.cur_id(), 0);
	IS(d.cur_name(), "f0");
	IS(d.cur_obj(), name0);

	IS(d.get_obj(1), name1);
	IS(d.cur_id(), 1);
	IS(d.cur_name(), "f1");
	IS(d.cur_obj(), name1);

	NOK(d.empty());
	IS(d.size(), 2);

	OK(d.exists(0));
	OK(d.exists(1));
	OK(d.exists("f0"));
	OK(d.exists("f1"));

	IS(d.get_obj(0), name0);
	IS(d.get_obj(1), name1);
	IS(d.get_obj("f0"), name0);
	IS(d.get_obj("f1"), name1);

	IS(d.get_id("f0"), 0);
	IS(d.get_id("f1"), 1);

	IS(d.get_name(0), "f0");
	IS(d.get_name(1), "f1");

	// modify
	Name* name2 = new Name("name2");
	d.set("f0", name2);
	IS(d.cur_id(), 0);
	IS(d.cur_name(), "f0");
	IS(d.cur_obj(), name2);

	DONE_TESTING();
}
