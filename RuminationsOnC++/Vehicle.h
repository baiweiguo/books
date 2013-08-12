/*
 * Ruminations on C++
 * Chapter 5:������
 * 
 * ���ܣ�һ���򵥵Ĵ����ࣨ��������ʾ���ۣ�
 * baiweiguo
 * 2013.08.10
*/

class Vehicle
{
public:
	virtual Vehicle* copy()const = 0;
	virtual ~Vehicle(){}
};

class Bus:public Vehicle
{
public:
	Bus* copy()const;
};

Bus* Bus::copy()const
{
	return new Bus(*this);
}

class VehicleSurrogate
{
public:
	VehicleSurrogate();
	VehicleSurrogate(const Vehicle&);
	VehicleSurrogate(const VehicleSurrogate&);
	VehicleSurrogate& operator=(const VehicleSurrogate&);
	~VehicleSurrogate();
private:
	Vehicle* pv;
};

VehicleSurrogate::VehicleSurrogate():pv(0){}

VehicleSurrogate::VehicleSurrogate(const Vehicle& v):pv(v.copy()){}

VehicleSurrogate::VehicleSurrogate(const VehicleSurrogate& v):pv(v.pv?v.pv->copy():0){}

VehicleSurrogate& VehicleSurrogate::operator=(const VehicleSurrogate& v)
{
	if (this!=&v)
	{
		delete pv;
		pv = v.pv?v.pv->copy():0;
	}
	return *this;
}

VehicleSurrogate::~VehicleSurrogate(){delete pv;}