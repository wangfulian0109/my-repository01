//dma10.cpp--- dma class methods
//
#include"dma10.h"
#include<cstring>

//baseDMA class methods
baseDMA::baseDMA(const char * label, int rating) {
	m_label = new char[std::strlen(label) + 1];
	std::strcpy(m_label, label);
	m_rating = rating;
}

baseDMA::baseDMA(const baseDMA & bs) {
	m_label = new char[std::strlen(bs.m_label) + 1];
	std::strcpy(m_label, bs.m_label);
	m_rating = bs.m_rating;
}

baseDMA::~baseDMA() {
	delete [] m_label;
}

baseDMA & baseDMA::operator=(const baseDMA & bs) {
	if (this == &bs)
		return *this;
	else {
		delete [] m_label;
		m_label = new char[std::strlen(bs.m_label) + 1];
		std::strcpy(m_label, bs.m_label);
		m_rating = bs.m_rating;

		return *this;
	}
}

std::ostream & operator<<(std::ostream & os, const baseDMA & bs) {
	os << "Label: " << bs.m_label << std::endl;
	os << "Rating: $" << bs.m_rating << std::endl;

	return os;
}

//lacksDMA methods
lacksDMA::lacksDMA(const char * color, const char * label, int rating) : baseDMA(label, rating)
{
	std::strncpy(m_color, color, 39);
	m_color[39] = '\0';
}

lacksDMA::lacksDMA(const char * color, const baseDMA & bs) : baseDMA(bs)
{
	std::strncpy(m_color, color, COL_LEN - 1);
	m_color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls) {
	os << (const baseDMA &) ls;
	os << "Color: " << ls.m_color << std::endl;

	return os;
}
//hasDMA methods
hasDMA::hasDMA(const char * style, const char * label, int rating) : baseDMA(label, rating)
{
	m_style = new char[std::strlen(style) + 1];
	std::strcpy(m_style, style);
}
hasDMA::hasDMA(const char * style, const baseDMA & bs) : baseDMA(bs)
{
	m_style = new char[std::strlen(style) + 1];
	std::strcpy(m_style, style);
}
hasDMA::~hasDMA() {
	delete [] m_style;
}
hasDMA::hasDMA(const hasDMA & hs) : baseDMA(hs) {
	m_style = new char[std::strlen(hs.m_style) + 1];
	std::strcpy(m_style, hs.m_style);
}

hasDMA & hasDMA::operator=(const hasDMA & hs) {
	if ( this == &hs)
		return *this;
	else {
		baseDMA::operator=(hs);
		delete [] m_style;
		m_style = new char[std::strlen(hs.m_style) + 1];
		std::strcpy(m_style, hs.m_style);

		return *this;
	}
}
std::ostream & operator<<(std::ostream & os , const hasDMA & hs) {
	os << (const baseDMA &) hs;
	os << "Style: " << hs.m_style << std::endl;

	return os;
}





