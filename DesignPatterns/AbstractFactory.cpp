#include<iostream>
using namespace std;
enum FurnitureType {
	FUR_CLASSIC,
	FUR_MODERN,
	FUR_VICTORIAN
};
class Furniture
{
	FurnitureType m_fType;
public:
	void SetFurnitureType(FurnitureType type) { m_fType = type; };
};

class VictorianTable : public Furniture
{
public:
	VictorianTable()
	{
		SetFurnitureType(FUR_VICTORIAN);
		cout << __FUNCTION__ << " Created " << endl;
	}
};
class VictorianSofa : public Furniture
{
public:
	VictorianSofa()
	{
		SetFurnitureType(FUR_VICTORIAN);
		cout << __FUNCTION__ << " Created " << endl;
	}
};

class VictorianChair : public Furniture
{
public:
	VictorianChair() 
	{
		SetFurnitureType(FUR_VICTORIAN);
		cout << __FUNCTION__ << " Created " << endl;
	}
};
class ModernTable : public Furniture
{
public:
	ModernTable()
	{
		SetFurnitureType(FUR_MODERN);
		cout << __FUNCTION__ << " Created " << endl;
	}
};
class ModernSofa : public Furniture
{
public:
	ModernSofa()
	{
		SetFurnitureType(FUR_MODERN);
		cout << __FUNCTION__ << " Created " << endl;
	}
};
class ModernChair : public Furniture
{
public:
	ModernChair()
	{
		SetFurnitureType(FUR_MODERN);
		cout << __FUNCTION__ << " Created " << endl;
	}
};
class ClassicChair : public Furniture
{
public:
	ClassicChair()
	{
		SetFurnitureType(FUR_CLASSIC);
		cout << __FUNCTION__ << " Created " << endl;
	}
};
class ClassicTable : public Furniture
{
public:
	ClassicTable()
	{
		SetFurnitureType(FUR_CLASSIC);
		cout << __FUNCTION__ << " Created " << endl;
	}
};
class ClassicSofa : public Furniture
{
public:
	ClassicSofa()
	{
		SetFurnitureType(FUR_CLASSIC);
		cout << __FUNCTION__ << " Created " << endl;
	}
};

class FurnitureFactory 
{
public:
	virtual Furniture* GetChair() = 0;
	virtual Furniture* GetTable() = 0;
	virtual Furniture* GetSofa() = 0;
};
class ClassicFactory : FurnitureFactory
{
public:
	Furniture* GetChair() override{ return new ClassicChair(); };
	Furniture* GetTable() override { return new ClassicTable(); };
	Furniture* GetSofa() override { return new ClassicSofa(); };
};

class ModernFactory : FurnitureFactory
{
public:
	Furniture* GetChair() override { return new ModernChair(); };
	Furniture* GetTable() override { return new ModernTable(); };
	Furniture* GetSofa() override { return new ModernSofa(); };
};

class VictorianFactory : FurnitureFactory
{
public:
	Furniture* GetChair() override { return new VictorianChair(); };
	Furniture* GetTable() override { return new VictorianTable(); };
	Furniture* GetSofa() override { return new VictorianSofa(); };
};
int main()
{
	VictorianFactory vf;
	Furniture* tmp = vf.GetSofa();
	delete(tmp);
}