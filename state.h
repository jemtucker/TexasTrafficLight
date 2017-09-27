#ifndef __STATE_H_
#define __STATE_H_

typedef struct State {
	unsigned int output;
	unsigned int next[8];
} STATE, *PSTATE;

#endif