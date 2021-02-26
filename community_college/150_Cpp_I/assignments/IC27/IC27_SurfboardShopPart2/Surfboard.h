#ifndef SURFBOARD_H
#define SURFBOARD_H

#include <iostream>

using namespace std;

class Surfboard
{
	private:
		static int s_nextId;
		int m_id;
		string m_brand;
		string m_model;
		double m_length;
		double m_width;
		double m_thickness;
		int m_quantity; 
		double m_price;
	

	public:
		Surfboard();
		Surfboard(string, string, double, double, double, int, double);
		inline int getId() const { return m_id; }
		inline string getBrand() const { return m_brand; }
		inline string getModel() const { return m_model; }
		inline double getLength() const { return m_length; }
		inline double getWidth() const { return m_width; }
		inline double getThickness() const { return m_thickness; }
		inline double getPrice() const { return m_price; }
		inline int getQuantity() const { return m_quantity; }

		inline void setBrand(string brand) { m_brand = brand; }
		inline void setModel(string model) { m_model = model; }
		inline void setLength(double length) { m_length = length; }
		inline void setWidth(double width) { m_width = width; }
		inline void setThickness(double thickness) { m_thickness = thickness; }
		inline void setPrice(double price) { m_price = price; }
		inline void setQuantity(int quantity) { m_quantity = quantity; }

		bool operator==(const Surfboard& other);

		friend ostream& operator<<(ostream& os, const Surfboard& s);
};

#endif
