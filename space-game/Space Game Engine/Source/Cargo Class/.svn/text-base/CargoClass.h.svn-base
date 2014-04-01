#pragma once
#include <string>
#include <vector>

class TradeMission;

class Cargo
{
private:
	class CargoItem
	{
	public:
		std::string name;

		double value;//The value it has per "unit" or ton, or whatever weight/mass unit will be used

		CargoItem(double value, std::string name);
	};
public:
	std::vector<CargoItem*> item;

	void addCargoItem(std::string name, int iValue);

	~Cargo();

	friend class CargoBay;//CargoBay class needs to be able to access the CargoItem class
	friend class TradeMission;
}; 