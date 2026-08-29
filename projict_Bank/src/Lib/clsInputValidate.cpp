// ProgrammingAdivces.com
// Mohammed Abu-Hadhoud

#pragma once
#include <iostream>
#include <string>

#include "../../include/Lib/clsInputValidate.h"
#include "../../include/Lib/clsString.h"
#include "../../include/Lib/clsDate.h"



	
	template <typename T>
	 bool clsInputValidate::IsNumberBetween(T Number, T From, T To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	} /*
	 static bool IsNumberBetween(short Number, short From, short To)
	 {
		 if (Number >= From && Number <= To)
			 return true;
		 else
			 return false;
	 }

	 static bool IsNumberBetween(int Number, int From, int To)
	 {
		 if (Number >= From && Number <= To)
			 return true;
		 else
			 return false;
	 }

	 static bool IsNumberBetween(float Number, float From, float To)
	 {
		 if (Number >= From && Number <= To)
			 return true;
		 else
			 return false;
	 }

	 static bool IsNumberBetween(double Number, double From, double To)
	 {
		 if (Number >= From && Number <= To)
			 return true;
		 else
			 return false;
	 }*/





	 string clsInputValidate::ReadString(string Massege)
	{
		string Text = "";

		cout << Massege;
		getline(cin >> ws, Text);

		return Text;
	}

	 char clsInputValidate::ReadChar(string Message)
	{
		string Input;

		while (true)
		{
			cout << Message;
			getline(cin >> ws, Input);

			if (Input.length() == 1)
				return Input[0];

			cout << "\nInvalid input. Please enter exactly one character.\n\n";
		}
	}
	 bool clsInputValidate::IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		// Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) &&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
		{
			return true;
		}

		// Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) &&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
		{
			return true;
		}

		return false;
	}

	template <typename T>
	 T clsInputValidate::ReadNumber(string Message)
	{
		T Number;

		if (!Message.empty()) {
			cout << Message;
		}

		while (!(cin >> Number) || (cin.peek() != '\n' && cin.peek() != ' ' && !cin.eof()))
		{
			cout << Message;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		return Number;
	}

	template <typename T>
	 T clsInputValidate::ReadNumberBetween(T From, T To, string ErrorMessage)
	{
		T Number = ReadNumber<T>();


		while (!IsNumberBetween(Number, From, To))
		{
			printf(ErrorMessage.c_str(), From, To);

			Number = ReadNumber<T>();
		}
		return Number;
	}

	 int clsInputValidate::ReadPositiveNumber(string Message)
	{
		int Number = 0;
		do
		{
			cout << Message << endl;
			Number = ReadNumber<int>();
		} while (Number < 0);

		return Number;
	}


	

	/*
		static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
		{
			int Number;
			while (!(cin >> Number))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << ErrorMessage;
			}
			return Number;
		}

		static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
		{
			int Number = ReadIntNumber();

			while (!IsNumberBetween(Number, From, To))
			{
				cout << ErrorMessage;
				Number = ReadIntNumber();
			}
			return Number;
		}

		static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
		{
			double Number;
			while (!(cin >> Number))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << ErrorMessage;
			}
			return Number;
		}

		static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
		{
			double Number = ReadDblNumber();

			while (!IsNumberBetween(Number, From, To))
			{
				cout << ErrorMessage;
				Number = ReadDblNumber();
			}
			return Number;
		}
	*/
	 bool clsInputValidate::IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}


	// أضف هذه الدالة داخل كلاس clsInputValidate
	 int clsInputValidate::ReadPermissionsFromUser()
	{
		// 1. قراءة السلسلة النصية من المستخدم مباشرة
		string Input = ReadString();

		// 2. تقسيم النص إلى فيكتور نصي بناءً على المسافة
		std::vector<string> vStrings = clsString::Split(Input, " ");

		// 3. تحويل الفيكتور النصي وحساب الصلاحيات مباشرة داخل حلقة واحدة لتوفر الذاكرة
		int TotalPermission = 0;
		for (const string& S : vStrings)
		{
			if (!S.empty())
			{
				int Option = stoi(S);
				if (Option >= 1)
				{
					TotalPermission |= (1 << (Option - 1));
				}
			}
		}

		return TotalPermission;
	}



	// تم تعديل الدالة لتستقبل فيكتور يحتوي على أسماء الشاشات ديناميكياً
	 int clsInputValidate::ReadPermissionsDynamic(const vector<string>& vPermissionsScreens)
	{
		char Answer = 'n';

		Answer = clsInputValidate::ReadChar("\nDo you want to give full access? y/n? ");

		if (Answer == 'y' || Answer == 'Y') return -1;

		int TotalPermissions = 0;

		system("cls");
		cout << "===========================================\n";
		cout << "\t\tSet User Permissions\n";
		cout << "===========================================\n";

		// الحلقة الآن تدور بناءً على الحجم الفعلي للفيكتور الممرر ديناميكياً
		for (size_t i = 0; i < vPermissionsScreens.size(); i++)
		{
			Answer = clsInputValidate::ReadChar("Do you want to give access to [" + vPermissionsScreens[i] + "]? y/n: ");;


			if (Answer == 'y' || Answer == 'Y')
			{
				TotalPermissions |= (1 << i); // تفعيل البت المقابل ديناميكياً
			}
		}

		return TotalPermissions;
	}


	 // Explicit template instantiations

	 template bool clsInputValidate::IsNumberBetween<short>(
		 short Number,
		 short From,
		 short To
	 );

	 template bool clsInputValidate::IsNumberBetween<int>(
		 int Number,
		 int From,
		 int To
	 );

	 template bool clsInputValidate::IsNumberBetween<float>(
		 float Number,
		 float From,
		 float To
	 );

	 template bool clsInputValidate::IsNumberBetween<double>(
		 double Number,
		 double From,
		 double To
	 );


	 template int clsInputValidate::ReadNumber<int>(string Message);

	 template short clsInputValidate::ReadNumber<short>(string Message);

	 template float clsInputValidate::ReadNumber<float>(string Message);

	 template double clsInputValidate::ReadNumber<double>(string Message);


	 template int clsInputValidate::ReadNumberBetween<int>(
		 int From,
		 int To,
		 string ErrorMessage
	 );

	 template short clsInputValidate::ReadNumberBetween<short>(
		 short From,
		 short To,
		 string ErrorMessage
	 );

	 template float clsInputValidate::ReadNumberBetween<float>(
		 float From,
		 float To,
		 string ErrorMessage
	 );

	 template double clsInputValidate::ReadNumberBetween<double>(
		 double From,
		 double To,
		 string ErrorMessage
	 );