// ProgrammingAdivces.com
// Mohammed Abu-Hadhoud

#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"


class clsInputValidate
{

public:
	
	template <typename T>
	static bool IsNumberBetween(T Number, T From, T To);

	static string ReadString(string Massege = "Please enter string?\n");

	static char ReadChar(string Message = "Please enter one character: ");

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To);

	template <typename T>
	static T ReadNumber(string Message = "Invalid Number, Enter again\n");

	template <typename T>
	static T ReadNumberBetween(T From, T To, string ErrorMessage = "\nEnter a number from %d to %d : \n");

	static int ReadPositiveNumber(string Message = "\nEnter a positve number: ");

	static bool IsValideDate(clsDate Date);

	// أضف هذه الدالة داخل كلاس clsInputValidate
	static int ReadPermissionsFromUser();

	// تم تعديل الدالة لتستقبل فيكتور يحتوي على أسماء الشاشات ديناميكياً
	static int ReadPermissionsDynamic(const vector<string>& vPermissionsScreens);


};
