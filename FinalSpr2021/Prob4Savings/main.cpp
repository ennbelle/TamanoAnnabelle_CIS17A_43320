/* 
 * File:   main.cpp
 * Author: Annabelle Tamano
 * Created on June 11, 2021, 3:37 AM
 * Purpose: Driver Program for Savngs Account
 */

#include <iostream>

using namespace std;

#include "SvngAcc.h"
int main(int argc, char** argv) {


	SvngAcc mine(-300);

	for(int i=1;i<=10;i++)
	{
		mine.Transaction((float)(rand()%500)*(rand()%3-1));
	}
	mine.toString();
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.Total((float)(0.10),7)<<endl;
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.TotalRecursive((float)(0.10),7)
		<<" Recursive Calculation "<<endl;
    return 0;
}

