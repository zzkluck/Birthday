#ifndef TOD_ARRAY_H
#define TOD_ARRAY_H

#define START_WITH_ZERO

class ToD_array {
public:
	typedef const unsigned int index;

	ToD_array() = default;
	ToD_array(index r, index col);

	index above(index i);
	index right_above(index i);
	index right(index i);
	index right_low(index i);
	index low(index i);
	index left_low(index i);
	index left(index i);
	index left_above(index i);
	/*index(ToD_array::*func[8])(index) = 
		{ above,right_above,right,right_low,low,left_low,left,left_above };*/

	index position(index r, index col) { return colume*r + col - 1; }
	index getmax() { return max; }
	void resize(index col, index r) {
		colume = col;
		row = r;
		max = colume*row;

	}
private:
	unsigned colume;
	unsigned row;
	unsigned max;
};

#endif // !TOD_ARRAY_H