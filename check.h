#pragma once

#include <iostream>
#include <limits>
#include <string>

using namespace std;

int check_input();
int check_date_day();
int check_date_month();
bool exist_date(int d, int m, int y);
void check_date(int& d, int& m, int& y);
