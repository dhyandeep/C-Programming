#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graphic//component class
{
public:
	virtual void Draw() = 0;
	virtual bool isComposite() = 0;
};
class Line: public Graphic//Line
{
public:
	void Draw() override { cout << "Drawing Line" << endl; };
	bool isComposite() override { return false; };
};
class Picture: public Graphic // Composite class
{
	list<Graphic*> m_Comps;
public:
	void AddItem(Graphic* item) { m_Comps.push_back(item); };
	void Draw() override { cout << "Drawing Composite picture" << endl; };
	bool isComposite() override { return false; };
};
void main()
{
	Picture *pic1 = new Picture();
	pic1->AddItem(new Line());
	pic1->AddItem(new Line());
	pic1->AddItem(new Picture());
	Graphic* g = pic1;
	queue<Graphic*> items;
	items.push(g);
	while (!items.empty())
	{
		Graphic* curr = items.back();
		items.pop();
		if (curr->isComposite())
		{
			for (auto i: curr->)
			{

			}
		}
	}

}