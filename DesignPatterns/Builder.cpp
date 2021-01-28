#include<iostream>
#include<list>
using namespace std;
class Product
{
	
public:
	list<string> parts;
	void PrintList() {
		cout << "Printing the features "<<endl;
		for (auto i : parts)
		{
			cout << i.c_str() << " ";
		}
		cout << endl;
	}
};

class Builder
{
public:
	virtual ~Builder() {};
	virtual void CreatePartA() = 0;
	virtual void CreatePartB() = 0;
	virtual void Reset() = 0;
};
class ConcreteBuilder : public Builder
{
	Product* ptr;
public:
	void CreatePartA() { ptr->parts.push_back("PARTA."); };
	void CreatePartB() { ptr->parts.push_back("PARTB."); };
	ConcreteBuilder() { this->Reset(); };
	void Reset() { ptr = new Product(); };
	Product* GetProduct() { Product* tmp = ptr; this->Reset(); return tmp; };
};
class Director
{
	ConcreteBuilder *bldr;
public:
	void SetBuilder(ConcreteBuilder* input) { bldr = input; };
	Product* GetFullOption() { bldr->CreatePartA(); bldr->CreatePartB(); return bldr->GetProduct(); };
	Product* GetBaseOption() { bldr->CreatePartA(); return bldr->GetProduct(); };
};
int main()
{
	Director Dir;
	ConcreteBuilder* cBuilder = new ConcreteBuilder();
	Dir.SetBuilder(cBuilder);
	Product* p = Dir.GetFullOption();
	p->PrintList();
	if (cBuilder)
		delete (cBuilder);
	if (p)
			delete p;

}