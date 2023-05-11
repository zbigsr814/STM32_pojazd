/*
 * motor.c
 *
 *  Created on: Oct 24, 2021
 *      Author: zbyszek
 */

#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "motor.h"



//funkcja sterująca ruchem pojedynczego silnika M0 w zależności od parametru
//parametrem jest enumerator flagMotor
void M0_ruch(flagMotor kierunek)
{
	if(kierunek == motorLewo)
	{
	HAL_GPIO_WritePin(M0_left_GPIO_Port, M0_left_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M0_right_GPIO_Port, M0_right_Pin, GPIO_PIN_RESET);
	}
	if(kierunek == motorPrawo)
	{
		HAL_GPIO_WritePin(M0_right_GPIO_Port, M0_right_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(M0_left_GPIO_Port, M0_left_Pin, GPIO_PIN_RESET);
	}
	if(kierunek == motorStop)
	{
		HAL_GPIO_WritePin(M0_left_GPIO_Port, M0_left_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(M0_right_GPIO_Port, M0_right_Pin, GPIO_PIN_RESET);
	}
}

//funkcja sterująca ruchem pojedynczego silnika M1 w zależności od parametru
//parametrem jest enumerator flagMotor
void M1_ruch(flagMotor kierunek)
{
	if(kierunek == motorLewo)
	{
	HAL_GPIO_WritePin(M1_left_GPIO_Port, M1_left_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M1_right_GPIO_Port, M1_right_Pin, GPIO_PIN_RESET);
	}
	if(kierunek == motorPrawo)
	{
		HAL_GPIO_WritePin(M1_right_GPIO_Port, M1_right_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(M1_left_GPIO_Port, M1_left_Pin, GPIO_PIN_RESET);
	}
	if(kierunek == motorStop)
	{
		HAL_GPIO_WritePin(M1_left_GPIO_Port, M1_left_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(M1_right_GPIO_Port, M1_right_Pin, GPIO_PIN_RESET);
	}
}

//funkcja sterująca ruchem pojedynczego silnika M2 w zależności od parametru
//parametrem jest enumerator flagMotor
void M2_ruch(flagMotor kierunek)
{
	if(kierunek == motorLewo)
	{
	HAL_GPIO_WritePin(M2_left_GPIO_Port, M2_left_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M2_right_GPIO_Port, M2_right_Pin, GPIO_PIN_RESET);
	}
	if(kierunek == motorPrawo)
	{
		HAL_GPIO_WritePin(M2_right_GPIO_Port, M2_right_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(M2_left_GPIO_Port, M2_left_Pin, GPIO_PIN_RESET);
	}
	if(kierunek == motorStop)
	{
		HAL_GPIO_WritePin(M2_left_GPIO_Port, M2_left_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(M2_right_GPIO_Port, M2_right_Pin, GPIO_PIN_RESET);
	}
}

//funkcja sterująca ruchem pojedynczego silnika M3 w zależności od parametru
//parametrem jest enumerator flagMotor
void M3_ruch(flagMotor kierunek)
{
	if(kierunek == motorLewo)
	{
	HAL_GPIO_WritePin(M3_left_GPIO_Port, M3_left_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(M3_right_GPIO_Port, M3_right_Pin, GPIO_PIN_RESET);
	}
	if(kierunek == motorPrawo)
	{
		HAL_GPIO_WritePin(M3_right_GPIO_Port, M3_right_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(M3_left_GPIO_Port, M3_left_Pin, GPIO_PIN_RESET);
	}
	if(kierunek == motorStop)
	{
		HAL_GPIO_WritePin(M3_left_GPIO_Port, M3_left_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(M3_right_GPIO_Port, M3_right_Pin, GPIO_PIN_RESET);
	}
}

//funkcja sterująca ruchem całego pojazdu w zależności od parametru
//parametrem jest enumerator flagMotors
void ruchPojazdu(flagMotors kierunek)
{
	switch(kierunek)
	{
	//kierunki podstawowe
	case przod:
		M0_ruch(motorPrawo); M1_ruch(motorPrawo); M2_ruch(motorPrawo); M3_ruch(motorPrawo);
		break;
	case tyl:
		M0_ruch(motorLewo); M1_ruch(motorLewo); M2_ruch(motorLewo); M3_ruch(motorLewo);
		break;
	case lewo:
		M0_ruch(motorLewo); M1_ruch(motorPrawo); M2_ruch(motorPrawo); M3_ruch(motorLewo);
		break;
	case prawo:
		M0_ruch(motorPrawo); M1_ruch(motorLewo); M2_ruch(motorLewo); M3_ruch(motorPrawo);
		break;

	//kierunki po skosie
	case przodPrawo:
		M0_ruch(motorPrawo); M1_ruch(motorStop); M2_ruch(motorStop); M3_ruch(motorPrawo);
		break;
	case przodLewo:
		M0_ruch(motorStop); M1_ruch(motorPrawo); M2_ruch(motorPrawo); M3_ruch(motorStop);
		break;
	case tylPrawo:
		M0_ruch(motorStop); M1_ruch(motorLewo); M2_ruch(motorLewo); M3_ruch(motorStop);
		break;
	case tylLewo:
		M0_ruch(motorLewo); M1_ruch(motorPrawo); M2_ruch(motorPrawo); M3_ruch(motorLewo);
		break;

	//obrót lewo/prawo
	case obrotLewo:
		M0_ruch(motorLewo); M1_ruch(motorPrawo); M2_ruch(motorLewo); M3_ruch(motorPrawo);
		break;
	case obrotPrawo:
		M0_ruch(motorPrawo); M1_ruch(motorLewo); M2_ruch(motorPrawo); M3_ruch(motorLewo);
		break;

	//zatrzymanie pojazdu
	case stop:
		M0_ruch(motorStop); M1_ruch(motorStop); M2_ruch(motorStop); M3_ruch(motorStop);
		break;
	}
}

void przydzielKierunek(char RxData)
{
	switch(RxData)
	{
	case 'a': ruchPojazdu(przod); break;
	case 'b': ruchPojazdu(tyl); break;
	case 'c': ruchPojazdu(prawo); break;
	case 'd': ruchPojazdu(lewo); break;
	case 'e': ruchPojazdu(przodPrawo); break;
	case 'f': ruchPojazdu(przodLewo); break;
	case 'g': ruchPojazdu(tylPrawo); break;
	case 'h': ruchPojazdu(tylLewo); break;
	case 'i': ruchPojazdu(obrotPrawo); break;
	case 'j': ruchPojazdu(obrotLewo); break;
	default: ruchPojazdu(stop);
	}
}
