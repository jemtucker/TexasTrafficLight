// TableTrafficLight.c for Lab 10
// Runs on LM4F120/TM4C123
// Index implementation of a Moore finite state machine to operate a traffic light.  
// Daniel Valvano, Jonathan Valvano
// January 15, 2016

#include "TExaS.h"
#include "tm4c123gh6pm.h"

#include "port.h"
#include "utils.h"

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

TRAFFIC_LIGHT_CONTEXT g_context;

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
	Port_Init(PORT_B, &g_context.northSouthGreen, 4, TRUE);
	// pedestrian detector connected to PE2 (1=pedestrian present)
	Port_Init(PORT_E, &g_context.pedestrianDetector, 4, FALSE);
	// north/south car detector connected to PE1 (1=car present)
	Port_Init(PORT_E, &g_context.northSouthDetector, 4, FALSE);
	// east/west car detector connected to PE0 (1=car present)
	Port_Init(PORT_E, &g_context.eastWestDetector, 4, FALSE);
	// "walk" light connected to PF3 (built-in green LED)
	Port_Init(PORT_E, &g_context.pedestrianGreen, 4, TRUE);
	// "don't walk" light connected to PF1 (built-in red LED)
	Port_Init(PORT_E, &g_context.pedestrianRed, 4, TRUE);
}

int main(void){ 
  TExaS_Init(SW_PIN_PE210, LED_PIN_PB543210, ScopeOff); // activate grader and set system clock to 80 MHz
 
  Init();
	
  EnableInterrupts();
  while(1){
     
  }
}

