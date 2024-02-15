

#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;
class Explorer {
public:
	string name;
	string kind_of_work;
	string owner;
	string telephone;
	string address;

	Explorer(string name, string kind_of_work, string owner, string telephone, string address) :
		name{ name } ,
		kind_of_work{ kind_of_work } ,
		owner{ owner } ,
		telephone{ telephone },
		address{ address } {};
	friend ostream& operator<<(ostream& os, Explorer a)
	{
		os << a.name << " " << a.kind_of_work << " " << a.owner << " " << a.telephone << " " << a.address << endl;
		return os;
	}

};
class Explorer_list {
	vector<Explorer> list;
public:
	Explorer_list(initializer_list<Explorer> list) : list(list) {};

	friend ostream& operator<<(ostream& os, Explorer_list a)
	{
		for (Explorer i : a.list)
		{
			os << i.name << " " << i.kind_of_work << " " << i.owner << " " << i.telephone << " " << i.address << endl;
		}
		return os;
	}
	Explorer& operator[](int i) { return list[i]; }

	void add(Explorer a) {
		list.push_back(a);
	}

	Explorer_list find_by_name(string name){
		Explorer_list a({});
		for (Explorer i : this->list)
		{
			if (i.name == name)
			{
				a.add(i);
			}
		}
		return a;
	}
	Explorer_list find_by_kind_of_work(string kind) {
		Explorer_list a({});
		for (Explorer i : this->list)
		{
			if (i.kind_of_work == kind)
			{
				a.add(i);
			}
		}
		return a;
	}

	Explorer_list find_by_telephone(string tel) {
		Explorer_list a({});
		for (Explorer i : this->list)
		{
			if (i.telephone == tel)
			{
				a.add(i);
			}
		}
		return a;
	}

	Explorer_list find_by_owner(string owner) {
		Explorer_list a({});
		for (Explorer i : this->list)
		{
			if (i.owner == owner)
			{
				a.add(i);
			}
		}
		return a;
	}

	Explorer_list find_by_address(string address) {
		Explorer_list a({});
		for (Explorer i : this->list)
		{
			if (i.address == address)
			{
				a.add(i); 
			}
		}
		return a;
	}
};
int main()
{
	Explorer a("Work", "none", "I", "00000000000", "Moscow ... 123");
	Explorer b("Work1", "yse", "I", "000000000300", "Moscow ... 133");
	Explorer c("Work1", "car washing", "I", "000000000100", "Moscow ... 223");
	Explorer d("Work3", "none", "I", "000000000200", "Moscow ... 1353");

	Explorer_list l({ a,b,c,d });
	cout << l;
	cout << l.find_by_name("Work1");

}

