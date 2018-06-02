//============================================================================
// Name        : BST_Driver.cpp
// Author      : vupham
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "BST.h"
#include "Product.h"
#include "ProductS.h"
using namespace std;
using namespace std;

const string IN_NAME = "Products_in.txt";
const string OUT_NAME = "Products_out.txt";

Product readData(ifstream &fin);
void printHeader(ostream &out);

int main() {
	BST<Product> bst_primary;		//will be sorted by primary key - make
	BST<ProductS> bst_secondary;	//will be sorted by secondary key - model
	Product tempP;
	ProductS tempS;
	ifstream fin(IN_NAME);
	ofstream fout(OUT_NAME);

	while (fin) {
		tempP = readData(fin);
		tempS = tempP;				//using operator= in ProductS.h
		bst_primary.insert(tempP);
		bst_secondary.insert(tempS);
	}
	fin.close();

	cout << "***SORTED BY MAKE***" << endl;
	printHeader(cout);
	bst_primary.printToConsole();		//USE THIS TO PRINT TO CONSOLE

	cout << endl << "***SORTED BY MODEL***" << endl;
	printHeader(cout);
	bst_secondary.printToConsole();		//USE THIS TO PRINT TO CONSOLE

	cout << endl << "Writing to file..." << endl;
	bst_primary.printToFile(fout);
	//USE THIS TO PRINT TO FILE BECAUSE WE'RE READING DATA IN THIS FORMAT AND NOT COLUMN-FORMAT LIKE IN CONSOLE
	cout << "Writing finished!" << endl;
	fout.close();

	return 0;
}

Product readData(ifstream &fin) {
	string make, model;
	double screenSize, price;
	unsigned cpuGen, year;

	getline(fin, make, '\n');
	getline(fin, model, '\n');
	fin >> screenSize;
	fin >> cpuGen;
	fin >> year;
	fin >> price;
	Product p(make, model, screenSize, cpuGen, year, price);

	while (fin.peek() == '\n')
		fin.get();

	return p;
}

void printHeader(ostream& out) {
	out << "Index           Make            Model                           Screen size     CPU Gen         Year            Price\n"
	    << "                                                                (in.)           (Intel)                         ($)  \n"
	    << "---------------------------------------------------------------------------------------------------------------------\n";
	return;
}

//OUTPUT
/*
***SORTED BY MAKE***
Index           Make            Model                           Screen size     CPU Gen         Year            Price
                                                                (in.)           (Intel)                         ($)
---------------------------------------------------------------------------------------------------------------------
1               Acer            Aspire R 13 (R7-372T)           13.3            6               2015            900
2               Acer            Aspire Switch 12 S              12.5            6               2016            1000
3               Acer            Aspire Switch Alpha 12          12              6               2016            700
4               Acer            Nitro 5 Spin                    15.6            8               2017            1000
5               Acer            Switch 5                        12              7               2017            800
6               Acer            Switch 7 Black Edition          13.5            8               2018            1700
7               Acer            Z3-700                          17.5            6               2015            600
8               Asus            Transformer 3 (T305CA)          12.6            7               2016            750
9               Asus            ZenBook Flip 15                 15.6            8               2017            1000
10              Asus            ZenBook Flip S                  13.3            7               2017            1000
11              Chuwi           CoreBook                        13.3            7               2018            680
12              Dell            Inspiron 13 7000 2-in-1         13.3            8               2017            900
13              Dell            Inspiron 15 7000 2-in-1         15.6            8               2017            850
14              Dell            Inspiron 17 7000 2-in-1         17.3            8               2017            950
15              Dell            Latitude 5290 2-in-1            12.3            8               2018            900
16              Dell            Latitude 7390 2-in-1            13.3            8               2017            1150
17              Dell            XPS 12 (2015)                   12.5            6               2015            1000
18              Eve             V                               12.3            7               2017            1600
19              Fujitsu         Lifebook Y936                   13.3            6               2015            1400
20              Fujitsu         Stylistic Q736                  13.3            6               2016            1400
21              HP              Elite x2 1012                   12              6               2015            900
22              HP              EliteBook x360 (1030 G2)        13.3            7               2017            1250
23              HP              Envy x360 15 (2017)             15.6            7               2017            900
24              HP              Pavilion x2                     12.1            6               2016            500
25              HP              Spectre x360 13 (late 2017)     13.3            8               2017            1150
26              HP              Spectre x360 15 (early 2018)    15.6            8               2018            1450
27              HP              ZBook x2                        14              8               2017            2280
28              Lenovo          IdeaPad Flex 5 15"              15.6            7               2017            930
29              Lenovo          Miix 520                        12.2            8               2017            600
30              Lenovo          ThinkPad L380 Yoga              13.3            8               2018            740
31              Lenovo          ThinkPad X380 Yoga              13.3            8               2018            1360
32              Lenovo          Thinkpad X1 Tablet (2017)       12              7               2017            1000
33              Lenovo          Yoga 520                        14              7               2017            1000
34              Lenovo          Yoga 720 13"                    13.3            7               2017            700
35              Lenovo          Yoga 900S                       12.5            6               2016            1600
36              Microsoft       Surface Book 2 15"              13.5            6               2015            2500
37              Microsoft       Surface Pro (2017)              12.3            7               2017            800
38              Porsche         Design Book One                 13.3            7               2017            2500
39              Samsung         Notebook 9 Pen                  13.3            8               2018            1400
40              Samsung         Notebook 9 Pro 13"              13.3            7               2017            1000
41              Vaio            Z Canvas                        12.3            4               2015            2200
42              Vaio            Z flip                          13.3            6               2016            1800
43              Wacom           MobileStudio Pro 16             15.6            6               2016            2400


***SORTED BY MODEL***
Index           Make            Model                           Screen size     CPU Gen         Year            Price
                                                                (in.)           (Intel)                         ($)
---------------------------------------------------------------------------------------------------------------------
1               Acer            Aspire R 13 (R7-372T)           13.3            6               2015            900
2               Acer            Aspire Switch 12 S              12.5            6               2016            1000
3               Acer            Aspire Switch Alpha 12          12              6               2016            700
4               Chuwi           CoreBook                        13.3            7               2018            680
5               Porsche         Design Book One                 13.3            7               2017            2500
6               HP              Elite x2 1012                   12              6               2015            900
7               HP              EliteBook x360 (1030 G2)        13.3            7               2017            1250
8               HP              Envy x360 15 (2017)             15.6            7               2017            900
9               Lenovo          IdeaPad Flex 5 15"              15.6            7               2017            930
10              Dell            Inspiron 13 7000 2-in-1         13.3            8               2017            900
11              Dell            Inspiron 15 7000 2-in-1         15.6            8               2017            850
12              Dell            Inspiron 17 7000 2-in-1         17.3            8               2017            950
13              Dell            Latitude 5290 2-in-1            12.3            8               2018            900
14              Dell            Latitude 7390 2-in-1            13.3            8               2017            1150
15              Fujitsu         Lifebook Y936                   13.3            6               2015            1400
16              Lenovo          Miix 520                        12.2            8               2017            600
17              Wacom           MobileStudio Pro 16             15.6            6               2016            2400
18              Acer            Nitro 5 Spin                    15.6            8               2017            1000
19              Samsung         Notebook 9 Pen                  13.3            8               2018            1400
20              Samsung         Notebook 9 Pro 13"              13.3            7               2017            1000
21              HP              Pavilion x2                     12.1            6               2016            500
22              HP              Spectre x360 13 (late 2017)     13.3            8               2017            1150
23              HP              Spectre x360 15 (early 2018)    15.6            8               2018            1450
24              Fujitsu         Stylistic Q736                  13.3            6               2016            1400
25              Microsoft       Surface Book 2 15"              13.5            6               2015            2500
26              Microsoft       Surface Pro (2017)              12.3            7               2017            800
27              Acer            Switch 5                        12              7               2017            800
28              Acer            Switch 7 Black Edition          13.5            8               2018            1700
29              Lenovo          ThinkPad L380 Yoga              13.3            8               2018            740
30              Lenovo          ThinkPad X380 Yoga              13.3            8               2018            1360
31              Lenovo          Thinkpad X1 Tablet (2017)       12              7               2017            1000
32              Asus            Transformer 3 (T305CA)          12.6            7               2016            750
33              Eve             V                               12.3            7               2017            1600
34              Dell            XPS 12 (2015)                   12.5            6               2015            1000
35              Lenovo          Yoga 520                        14              7               2017            1000
36              Lenovo          Yoga 720 13"                    13.3            7               2017            700
37              Lenovo          Yoga 900S                       12.5            6               2016            1600
38              Vaio            Z Canvas                        12.3            4               2015            2200
39              Vaio            Z flip                          13.3            6               2016            1800
40              Acer            Z3-700                          17.5            6               2015            600
41              HP              ZBook x2                        14              8               2017            2280
42              Asus            ZenBook Flip 15                 15.6            8               2017            1000
43              Asus            ZenBook Flip S                  13.3            7               2017            1000


Writing to file...
Writing finished!
 */
