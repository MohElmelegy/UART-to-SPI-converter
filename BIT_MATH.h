

#ifndef BIT_MATH_H_
#define BIT_MATH_H_
// data: this return data == DDR  //
#define SET_BIT( data , bit )			( data |= (1 << bit) )
#define GET_BIT( data , bit )			(( data >> bit ) & 1)
#define CLR_BIT( data , bit )			( data &= (~(1 << bit)) )
#define TOGGIL_BIT( data , bit )	   	( data ^= (1<<bit) )

#define SET_PORT(data)		(0xff)
#define CLR_PORT(data)		(0x00)

#endif /* BIT_MATH_H_ */

