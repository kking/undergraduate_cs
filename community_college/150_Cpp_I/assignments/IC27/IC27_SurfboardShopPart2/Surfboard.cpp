#include "Surfboard.h"
#include <string>

int Surfboard::s_nextId = 10000;

Surfboard::Surfboard()
{
	m_id = 0;
	m_brand = "";
	m_model = "";
	m_length = 0.0;
	m_width = 0.0;
	m_thickness = 0.0;
	m_quantity = 0;
	m_price = 0.0;
}

Surfboard::Surfboard(string brand, string model, double length=0.0, double width=0.0, double thickness=0.0, int quantity=0, double price=0.0)
{
	m_id = s_nextId++;
	m_brand = brand;
	m_model = model;
	m_length = length;
	m_width = width;
	m_thickness = thickness;
	m_quantity = quantity;
	m_price = price;
}

bool Surfboard::operator==(const Surfboard& other)
{
	return m_brand == other.m_brand && m_model == other.m_model && m_length == other.m_length && m_width == other.m_width
		&& m_thickness == other.m_thickness && m_quantity == other.m_quantity && m_price == other.m_price;
}

ostream& operator<<(ostream& os, const Surfboard& s)
{
	os << "Surfboard [ID#" << s.m_id << ", Brand=" << s.m_brand << ", Model=" << s.m_model << ", Length=" << s.m_length
		<< " ft, Width=" << s.m_width << " in, Thickness=" << s.m_thickness << " in, Quantity=" << s.m_quantity
		<< ", Price=$" << s.m_price << "]";
	return os;
}
