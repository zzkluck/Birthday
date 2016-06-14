#include"ToD_array.h"

ToD_array::ToD_array(index r, index col):
colume(r), row(col), max(r*col) {};

ToD_array::index ToD_array::right(index i) {
#ifdef START_WITH_ZERO
	if ((i + 1) % colume == 0 || i == max)
		return max;
	return i + 1;
#else
	if (i % colume == 0 || i == max)
		return max;
	return i + 1;
#endif // START_WITH_ZERO
}
ToD_array::index ToD_array::left(index i) {
#ifdef START_WITH_ZERO
	if (i%colume == 0 || i == max)
		return max;
	return i - 1;
#else
	if ((i - 1) % colume == 0 || i == max)
		return max;
	return i - 1;
#endif // START_WITH_ZERO

}
ToD_array::index ToD_array::above(index i) {
#ifdef START_WITH_ZERO
	if (i / colume == 0 || i == max)
		return max;
	return i - colume;
#else
	if ((i - 1) / colume == 0 || i == max)
		return max;
	return i - colume;
#endif // START_WITH_ZERO

}
ToD_array::index ToD_array::low(index i) {
#ifdef START_WITH_ZERO
	if (i / colume == row - 1 || i == max)
		return max;
	return i + colume;
#else
	if ((imax + 1) / colume == row - 1 || i == max)
		return max;
	return i + colume;
#endif // START_WITH_ZERO

}
ToD_array::index ToD_array::right_above(index i) {
	return above(right(i));
}
ToD_array::index ToD_array::left_above(index i) {
	return above(left(i));
}
ToD_array::index ToD_array::right_low(index i) {
	return low(right(i));
}
ToD_array::index ToD_array::left_low(index i) {
	return low(left(i));
}