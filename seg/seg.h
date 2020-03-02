/*******************************************************************************
 * -----------------------------------------------------------------------------
 * File Name    : seg.h
 * Library Ver. : 1.1
 * Description  : This file implements the seg .
 ******************************************************************************/
#ifndef _SEG_H_
#define _SEG_H_
/*----------------------------------------------------------------------------*/
/* Header file include                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global variable definition                                                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant value definition                                                  */
/*----------------------------------------------------------------------------*/

//------LCD DIG's seg define--------------------
// 7-segment arragment :
//       a
//     -----
//    |     |
//   f|     |b
//    |  g  |
//     -----
//    |     |
//   e|     |c
//    |  d  |
//     -----  . h

#define seg_a           0x01                    //bit of SEG. a.
#define seg_b           0x02                    //bit of SEG. b.
#define seg_c           0x04                    //bit of SEG. c.
#define seg_d           0x80                    //bit of SEG. d.
#define seg_e           0x40                    //bit of SEG. e.
#define seg_f           0x10                    //bit of SEG. f.
#define seg_g           0x20                    //bit of SEG. g.
#define seg_h           0x08                    //bit of SEG. h.


#define Char_H          seg_b+seg_c+seg_e+seg_f+seg_g
#define Char_Y          seg_b+seg_c+seg_d+seg_f+seg_g
#define Char_c          seg_d+seg_e+seg_g
#define Char_o          seg_c+seg_d+seg_e+seg_g
#define Char_n          seg_c+seg_e+seg_g

#define Char_P          seg_a+seg_b+seg_e+seg_f+seg_g
#define Char_A          seg_a+seg_b+seg_c+seg_e+seg_f+seg_g
#define Char_S          seg_a+seg_c+seg_d+seg_f+seg_g

#define Char_E          seg_a+seg_d+seg_e+seg_f+seg_g
#define Char_r          seg_e+seg_g

#define Char_S          seg_a+seg_c+seg_d+seg_f+seg_g
#define Char_C          seg_a+seg_d+seg_e+seg_f
#define Char_A          seg_a+seg_b+seg_c+seg_e+seg_f+seg_g
#define Char_L          seg_d+seg_e+seg_f
#define Char_Blank      0
#define Char_9          seg_a+seg_b+seg_c+seg_d+seg_f+seg_g


#endif  //_USER_LCD_H_

