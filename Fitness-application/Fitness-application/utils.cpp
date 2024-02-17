#include "utils.hpp"

/*overloads*/
ostream& operator<< (ostream& lhs, Day& rhs) {

	switch (rhs) {
	case 0:
		lhs << "Monday";
		break;
	case 1:
		lhs << "Tuesday";
		break;
	case 2:
		lhs << "Wednesday";
		break;
	case 3:
		lhs << "Thursday";
		break;
	case 4:
		lhs << "Friday";
		break;
	case 5:
		lhs << "Saturday";
		break;
	case 6:
		lhs << "Sunday";
		break;
	}

	return lhs;
}