// TableTrafficLight.c for Lab 10
// Runs on LM4F120/TM4C123
// Index implementation of a Moore finite state machine to operate a traffic light.  
// Daniel Valvano, Jonathan Valvano
// January 15, 2016

#include "TExaS.h"
#include "tm4c123gh6pm.h"

#include "port.h"
#include "utils.h"
#include "state.h"

#define IS_PRESSED(port) (Port_Read(&port) == 0) 

void DisableInterrupts(void);
void EnableInterrupts(void);

typedef struct TrafficLightContext {
	PORT eastWestRed;
	PORT eastWestGreen;
	PORT eastWestYellow;
	PORT eastWestDetector;
	PORT northSouthRed;
	PORT northSouthGreen;
	PORT northSouthYellow;
	PORT northSouthDetector;
	PORT pedestrianRed;
	PORT pedestrianGreen;
	PORT pedestrianDetector;
} TRAFFIC_LIGHT_CONTEXT, *PTRAFFIC_LIGHT_CONTEXT;

#define GoWest    0
#define WaitWest  1
#define GoNorth   2
#define WaitNorth 3
#define GoPed     4
#define WaitPed 	5
#define Off				6

static TRAFFIC_LIGHT_CONTEXT g_context;

static STATE g_fsm[6] = {
	{ .output = 0, .next = { GoWest,  GoWest,    WaitWest, WaitWest,  WaitWest,  WaitWest,  WaitWest,  WaitWest }},
	{ .output = 0, .next = { GoNorth, GoNorth,   GoNorth,  GoNorth,   GoPed,     GoPed,     GoNorth,   GoNorth }},
	{ .output = 0, .next = { GoNorth, WaitNorth, GoNorth,  WaitNorth, WaitNorth, WaitNorth, WaitNorth, WaitNorth }},
	{ .output = 0, .next = { GoWest,  GoWest,    GoWest,   GoWest,    GoPed,     GoWest,    GoPed,     GoWest }},
	{ .output = 0, .next = { GoPed,   WaitPed,   WaitPed,  GoPed,     WaitPed,   WaitPed,   WaitPed,   WaitPed }},
	{ .output = 0, .next = { GoWest,  GoWest,		 GoNorth,	 GoWest, 		GoWest, 	 GoNorth, 	GoWest,		 GoWest }}
};

void Init(void) {
	// east/west red light connected to PB5
	Port_Init(PORT_B, &g_context.eastWestRed, 5, TRUE);
	// east/west yellow light connected to PB4
	Port_Init(PORT_B, &g_context.eastWestYellow, 4, TRUE);
	// east/west green light connected to PB3
	Port_Init(PORT_B, &g_context.eastWestGreen, 3, TRUE);
	// north/south facing red light connected to PB2
	Port_Init(PORT_B, &g_context.northSouthRed, 2, TRUE);
	// north/south facing yellow light connected to PB1
	Port_Init(PORT_B, &g_context.northSouthYellow, 1, TRUE);
	// north/south facing green light connected to PB0
	Port_Init(PORT_B, &g_context.northSouthGreen, 0, TRUE);
	// pedestrian detector connected to PE2 (1=pedestrian present)
	Port_Init(PORT_E, &g_context.pedestrianDetector, 2, FALSE);
	// north/south car detector connected to PE1 (1=car present)
	Port_Init(PORT_E, &g_context.northSouthDetector, 1, FALSE);
	// east/west car detector connected to PE0 (1=car present)
	Port_Init(PORT_E, &g_context.eastWestDetector, 0, FALSE);
	// "walk" light connected to PF3 (built-in green LED)
	Port_Init(PORT_E, &g_context.pedestrianGreen, 3, TRUE);
	// "don't walk" light connected to PF1 (built-in red LED)
	Port_Init(PORT_E, &g_context.pedestrianRed, 1, TRUE);
}

int main(void){ 
  TExaS_Init(SW_PIN_PE210, LED_PIN_PB543210, ScopeOff); // activate grader and set system clock to 80 MHz
 
  Init();
	
  EnableInterrupts();
  while(1){
     // Read input (PE)
		 
		 // Write output (PF)
  }
}

