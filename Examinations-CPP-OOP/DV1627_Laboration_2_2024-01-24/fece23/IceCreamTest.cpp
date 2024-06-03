//#include "IceCream.h"
//#include <iostream>
//using namespace std;
//
//// used for testing
//const int NR_OF_ICECREAMS = 6;
//const string names[NR_OF_ICECREAMS]{ "Magnum mandel", "Solero", "Dajmstrut", "Nogger", "Igloo", "Nogger"};
//const float prices[NR_OF_ICECREAMS]{ 25.5f, 23.5f, 27.f, 25.5f, 28.5f, 25.5f };
//
//void prepareIceCreamObjects(IceCream iceCreams[])
//{
//	for (int i = 0; i < NR_OF_ICECREAMS; i++)
//	{
//		iceCreams[i].setName(names[i]);
//		iceCreams[i].setPrice(prices[i]);
//	}
//}
//
//bool testingBasics()
//{
//	cout << "Testing basics" << endl;
//
//	IceCream bIceCream("Solero", 23.5f);
//
//	if (bIceCream.getName() != "Solero")
//	{
//		cout << "NOT CORRECT 1:  name, expected Solero" << endl;
//		return false;
//	}
//	string iceCreamString = bIceCream.toString();
//	if (iceCreamString.find("23.5") == string::npos)
//	{
//		cout << "NOT CORRECT 2: result from toString(), expected 23 as part of the string" << endl;
//		return false;
//	}
//	IceCream aIceCream;
//	aIceCream.setName("88:an");
//	aIceCream.setPrice(123.f);
//	if (aIceCream.getName() != "88:an")
//	{
//		cout << "NOT CORRECT 3: name, expected 88:an" << endl;
//		return false;
//	}
//
//	iceCreamString = aIceCream.toString();
//	if (iceCreamString.find("88:an") == string::npos)
//	{
//		cout << "NOT CORRECT 4: result from toString(), expected 88:an as part of the string" << endl;
//		return false;
//
//	}
//	if (iceCreamString.find("123.") == string::npos)
//	{
//		cout << "NOT CORRECT 5: result from toString(), expected 123 as part of the string" << endl;
//		return false;
//
//	}
//	cout << "OK: Testing basics" << endl;
//	return true;
//}
//
//bool testingEqualsOperator()
//{
//	cout <<endl << "Testing == " << endl;
//	IceCream iceCreams[NR_OF_ICECREAMS];
//	IceCream iceCream("Igloo", 10.5);
//
//	prepareIceCreamObjects(iceCreams);
//	if (!(iceCreams[5] == iceCreams[3]))
//	{
//		cout << "NOT CORRECT 1: comparing == when two identical objects, expected true" << endl;
//		return false;
//	}
//	if (iceCreams[0] == iceCreams[5])
//	{
//		cout << "NOT CORRECT 2: comparing == when two different objects according to names, expected false" << endl;
//		return false;
//	}
//	if (iceCream == iceCreams[4])
//	{
//		cout << "NOT CORRECT 3: comparing == when two different objects according to price, expected false" << endl;
//		return false;
//	}
//
//	cout << "OK Testing == " << endl;
//	return true;
//}
//
//bool testingLessThanOperator()
//{
//	cout <<endl << "Testing < " << endl;
//	IceCream iceCreams[NR_OF_ICECREAMS];
//
//	prepareIceCreamObjects(iceCreams);
//	if (iceCreams[0] < iceCreams[1]) 
//	{
//		cout << "NOT CORRECT 1: comparing < expected false" << endl;
//		return false;
//	}
//	if (iceCreams[0] < iceCreams[3]) 
//	{
//		cout << "NOT CORRECT 2: comparing < expected false" << endl;
//		return false;
//	}
//	if (!(iceCreams[2] < iceCreams[4]))
//	{
//		cout << "NOT CORRECT 3: comparing < expected true" << endl;
//		return false;
//	}
//	cout << "OK: Testing < " << endl;
//	return true;
//}
//
//int main()
//{
//	bool ok = true;
//	ok = testingBasics();
//	if (!ok)
//	{
//		cout << "NOT OK : testingBasics" << endl;
//		return 1;
//	}
//
//	ok = testingEqualsOperator();
//	if (!ok)
//	{
//		cout << "NOT OK : testingEqualsOperator" << endl;
//		return 2;
//	}
//	
//	ok = testingLessThanOperator();
//	if (!ok)
//	{
//		cout << "NOT OK : testingLessThanOperator" << endl;
//		return 3;
//	}
//	
//	return 0;
//}