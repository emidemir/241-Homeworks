#pragma once
#include <iostream>
#include <initializer_list>
using namespace std;

namespace _DayofYear{

	/*Months are stored as strong enum inside dayOfYearSet header file as integer forms*/
	enum class Months{
		January   =  1,
		February  =  2,
		March     =  3,
		April     =  4,
		May       =  5,
		June      =  6,
		July      =  7,
		August    =  8,
		September =  9,
		October   = 10,
		November  = 11,
		December  = 12,
	};

	/*Set is here*/
	class dayOfYearSet
	{
		public:

		class DayofYear{
		private:
			int Day;
			Months Month;
		public:
			friend ostream& operator<<(ostream& COUT, const DayofYear& obj);
			DayofYear()
			{
				Day = 1;
				Month = Months::January;
			};
			DayofYear(int day, Months month){
				Day = day;
				Month = month;
			};
			DayofYear(int day, int month){
				Day = day;
				if (month == 1) Month = Months::January;
				else if (month == 2){ Month = Months::February;}
				else if (month == 3){ Month = Months::March;}
				else if (month == 4){ Month = Months::April;}
				else if (month == 5){ Month = Months::May;}
				else if (month == 6){ Month = Months::June;}
				else if (month == 7){ Month = Months::July;}
				else if (month == 8){ Month = Months::August;}
				else if (month == 9){ Month = Months::September;}
				else if (month == 10){ Month = Months::October;}
				else if (month == 11){ Month = Months::November;}
				else if (month == 12){ Month = Months::December;}
			}
			int getDay()const{return Day;};
			Months getMonth()const{return Month;};
		};

		dayOfYearSet(const initializer_list<DayofYear> &objL);
		dayOfYearSet(){
			_used = 0;
			_size = 2;
			setArr = new DayofYear[_size];
		};
		dayOfYearSet(int size){
			_used = 0;
			if (size > 0)
				_size = size;
			else
				_size = 2;
			setArr = new dayOfYearSet::DayofYear [_size];
		}
		~dayOfYearSet(){
			delete [] setArr;
			setArr = nullptr;
		}
		void remove(int day, Months Month);
		inline int size()const{return _size;};
		inline int getUsed()const{return _used;};
		dayOfYearSet::DayofYear& operator[](int index);
		void operator=(const dayOfYearSet& set);
		dayOfYearSet& operator!();
		friend dayOfYearSet& operator+(dayOfYearSet& doy_set, const dayOfYearSet::DayofYear& day_obj);
		friend ostream& operator<<(ostream& COUT, const dayOfYearSet& obj);
		friend bool operator==(const dayOfYearSet& set1 ,const dayOfYearSet& set2);
		friend bool operator!=(const dayOfYearSet& set1 ,const dayOfYearSet& set2);
		friend dayOfYearSet& operator+(dayOfYearSet& set1, const dayOfYearSet& set2);
		friend dayOfYearSet& operator-(const dayOfYearSet& set1, const dayOfYearSet& set2);
		friend dayOfYearSet& operator-(dayOfYearSet& set ,const DayofYear& obj);
		friend dayOfYearSet& operator^(const dayOfYearSet& set1, const dayOfYearSet& set2);

		private:
			int _size;
			int _used;
			DayofYear* setArr;
	};

	/*Friend function for printing objects of  ___INNER CLAS___*/
	ostream& operator<<(ostream& COUT, const dayOfYearSet::DayofYear& obj);

	/*Friend function for printing objects of ___OUTER CLASS___*/
	// ostream& operator<<(ostream& COUT, const dayOfYearSet& obj);

	/*Outer Class Declerations*/
	dayOfYearSet& operator-(dayOfYearSet& set ,const dayOfYearSet::DayofYear& obj);
	dayOfYearSet& operator-(const dayOfYearSet& set1, const dayOfYearSet& set2);
	dayOfYearSet& operator+(dayOfYearSet& set1, const dayOfYearSet& set2);
	dayOfYearSet& operator+(dayOfYearSet&doy_set, const dayOfYearSet::DayofYear& day_obj);
	ostream& operator<<(ostream& COUT, const dayOfYearSet& obj);
	bool operator==(const dayOfYearSet& set1 ,const dayOfYearSet& set2);
	bool operator!=(const dayOfYearSet& set1 ,const dayOfYearSet& set2);
	dayOfYearSet& operator^(const dayOfYearSet& set1, const dayOfYearSet& set2);

	bool convertInt(string ui_input, int &amount);
	/*Input validation on main*/
	bool inputChecker(int& Day, Months& Month);
}