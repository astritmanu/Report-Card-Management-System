#ifndef globalvars
#define globalvars

#include<iostream>
#include "classprimary.h"
#include "classsecondary.h"
#include "classsenior.h"

std::fstream fs;
char rec_file[13][15]={{'\0'},
{"class1.dat"},
{"class2.dat"},
{"class3.dat"},
{"class4.dat"},
{"class5.dat"},
{"class6.dat"},
{"class7.dat"},
{"class8.dat"},
{"class9.dat"},
{"class10.dat"},
{"class11.dat"},
{"class12.dat"}};
// To create separate data file for each class with unique name

primary pri_class[6];
secondary sec_class[11];
senior sen_class[13];

#endif