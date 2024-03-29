#define PRJ_B
#include "stdafx.h"

#ifdef UNICODE
BDLLEXPIMPORT wistream & operator >>(wistream & is, bignum & num) {
	wstring str;
	size_t j = 0;
	BOOL a = 0, b = 0, c = 0, m = 0;
	getline(wcin, str);
	for (auto i : str) {
		if (i == _T('-')) {
			if (j != 0) {
				m = 1; //error
			}
		}
		else if (i <= _T('9') && i >= _T('0')) {

		}
		else if (i == _T('.')) {
			if (a == 1) {
				m = 1;
			}
			if (j == 0) {
				str = _T("0") + str;
			}
			a = 1;
		}
		else if (i == 0) {
			break;
		}
		else {
			m = 1;
		}
		++j;
	}
	if (m == 1) {
		num = _T("");
		return is;
	}
	else {
		num = str;
		return is;
	}
}
BDLLEXPIMPORT wostream & operator <<(wostream & os, bignum & num) {
	os << num.c_str();
	return os;
}
BDLLEXPIMPORT wistream & operator >>(wistream & is, bignum && num) {
	return is >> num;
}
BDLLEXPIMPORT wostream & operator <<(wostream & os, bignum && num) {
	return os << num;
}
#else
BDLLEXPIMPORT istream & operator >>(istream & is, bignum & num) {
	string str;
	size_t j = 0;
	BOOL a = 0, b = 0, c = 0, m = 0;
	getline(cin, str);
	for (auto i : str) {
		if (i == _T('-')) {
			if (j != 0) {
				m = 1; //error
			}
		}
		else if (i <= _T('9') && i >= _T('0')) {

		}
		else if (i == _T('.')) {
			if (a == 1) {
				m = 1;
			}
			if (j == 0) {
				str = "0" + str;
			}
			a = 1;
		}
		else if (i == 0) {
			break;
		}
		else {
			m = 1;
		}
		++j;
	}
	if (m == 1) {
		num = "";
		return is;
	}
	else {
		num = str;
		return is;
	}
}
BDLLEXPIMPORT ostream & operator <<(ostream & os, bignum & num) {
	os << num.c_str();
	return os;
}
BDLLEXPIMPORT istream & operator >>(istream & is, bignum && num) {
	return is >> num;
}
BDLLEXPIMPORT ostream & operator <<(ostream & os, bignum && num) {
	return os << num;
}
#endif
