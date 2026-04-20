#include "traffic_light.h"
#include <stdio.h>

extern UART_HandleTypeDef huart2;

void traffic_light_loop()
{
    TrafficLightPhase current_phase = PHASE_RED;

    while (1)
    {
        switch (current_phase)
        {
            case PHASE_RED:
                printf("PHASE: RED\r\n");
                HAL_GPIO_WritePin(SEM_RED_GPIO_Port, SEM_RED_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(SEM_YELLOW_GPIO_Port, SEM_YELLOW_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(SEM_GREEN_GPIO_Port, SEM_GREEN_Pin, GPIO_PIN_RESET);
                HAL_Delay(3000);
                current_phase = PHASE_RED_YELLOW;
                break;

            case PHASE_RED_YELLOW:
                printf("PHASE: RED_YELLOW\r\n");
                HAL_GPIO_WritePin(SEM_RED_GPIO_Port, SEM_RED_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(SEM_YELLOW_GPIO_Port, SEM_YELLOW_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(SEM_GREEN_GPIO_Port, SEM_GREEN_Pin, GPIO_PIN_RESET);
                HAL_Delay(1000);
                current_phase = PHASE_GREEN;
                break;

            case PHASE_GREEN:
                printf("PHASE: GREEN\r\n");
                HAL_GPIO_WritePin(SEM_RED_GPIO_Port, SEM_RED_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(SEM_YELLOW_GPIO_Port, SEM_YELLOW_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(SEM_GREEN_GPIO_Port, SEM_GREEN_Pin, GPIO_PIN_SET);
                HAL_Delay(3000);
                current_phase = PHASE_YELLOW;
                break;

            case PHASE_YELLOW:
                printf("PHASE: YELLOW\r\n");
                HAL_GPIO_WritePin(SEM_RED_GPIO_Port, SEM_RED_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(SEM_YELLOW_GPIO_Port, SEM_YELLOW_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(SEM_GREEN_GPIO_Port, SEM_GREEN_Pin, GPIO_PIN_RESET);
                HAL_Delay(1000);
                current_phase = PHASE_RED;
                break;
        }
    }
}