#pragma once

#include <ostream>
using std::ostream;

/*enums*/
enum Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

/*overloads*/
ostream& operator<< (ostream& lhs, Day& rhs);