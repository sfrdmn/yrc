#ifndef _YRC_COMMON_H
#define _YRC_COMMON_H

#include <stddef.h>
#if defined(_MSC_VER) && _MSC_VER < 1600
# include "stdint-msvc2008.h"
#else
# include <stdint.h>
#endif
#include "yrc.h"

#define WHITESPACE_MAP(XX) \
  XX('\r') XX('\v') \
  XX('\f') XX('\n') \
  XX('\t') XX(' ')

#define ALPHA_MAP(XX) \
  XX('a') XX('b') XX('c') XX('d') XX('e') \
  XX('f') XX('g') XX('h') XX('i') XX('j') \
  XX('k') XX('l') XX('m') XX('n') XX('o') \
  XX('p') XX('q') XX('r') XX('s') XX('t') \
  XX('u') XX('v') XX('w') XX('x') XX('y') \
  XX('z') XX('_') XX('A') XX('B') XX('C') \
  XX('D') XX('E') XX('F') XX('G') XX('H') \
  XX('I') XX('J') XX('K') XX('L') XX('M') \
  XX('N') XX('O') XX('P') XX('Q') XX('R') \
  XX('S') XX('T') XX('U') XX('V') XX('W') \
  XX('X') XX('Y') XX('Z')

#define NUMERIC_MAP(XX) \
  XX('0') XX('1') XX('2') XX('3') XX('4') \
  XX('5') XX('6') XX('7') XX('8') XX('9') 

#define FASTOP_MAP(XX) \
  XX('?') XX(':') XX(',') \
  XX('~') XX('{') XX('}') \
  XX('[') XX(']') XX(';') \
  XX('(') XX(')')

#define OPERATOR_MAP(XX) \
  XX('/') XX('*') XX('=') \
  XX('+') XX('-') XX('%') \
  XX('&') XX('^') XX('|') \
  XX('<') XX('>') XX('!')

#define ALPHANUMERIC_MAP(XX) \
  ALPHA_MAP(XX) \
  NUMERIC_MAP(XX)

#endif
