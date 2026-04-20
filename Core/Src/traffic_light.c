#include "traffic_light.h"

void traffic_light_loop()
{
    TrafficLightPhase current_phase = PHASE_RED;

    while (1)
    {
        switch (current_phase)
        {
            case PHASE_RED:
                HAL_GPIO_WritePin(SEM_RED_GPIO_Port, SEM_RED_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(SEM_YELLOW_GPIO_Port, SEM_YELLOW_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(SEM_GREEN_GPIO_Port, SEM_GREEN_Pin, GPIO_PIN_RESET);
                HAL_Delay(3000);
                current_phase = PHASE_RED_YELLOW;
                break;

            case PHASE_RED_YELLOW:
                HAL_GPIO_WritePin(SEM_RED_GPIO_Port, SEM_RED_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(SEM_YELLOW_GPIO_Port, SEM_YELLOW_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(SEM_GREEN_GPIO_Port, SEM_GREEN_Pin, GPIO_PIN_RESET);
                HAL_Delay(1000);
                current_phase = PHASE_GREEN;
                break;

            case PHASE_GREEN:
                HAL_GPIO_WritePin(SEM_RED_GPIO_Port, SEM_RED_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(SEM_YELLOW_GPIO_Port, SEM_YELLOW_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(SEM_GREEN_GPIO_Port, SEM_GREEN_Pin, GPIO_PIN_SET);
                HAL_Delay(3000);
                current_phase = PHASE_YELLOW;
                break;

            case PHASE_YELLOW:
                HAL_GPIO_WritePin(SEM_RED_GPIO_Port, SEM_RED_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(SEM_YELLOW_GPIO_Port, SEM_YELLOW_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(SEM_GREEN_GPIO_Port, SEM_GREEN_Pin, GPIO_PIN_RESET);
                HAL_Delay(1000);
                current_phase = PHASE_RED;
                break;
        }
    }
}