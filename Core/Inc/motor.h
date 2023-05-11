/*
 * motor.h
 *
 *  Created on: Oct 24, 2021
 *      Author: zbyszek
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

typedef enum {motorLewo, motorPrawo, motorStop} flagMotor; //enumeratory pojedynczego silnika
typedef enum {przod, tyl, lewo, prawo, stop,
	przodLewo, przodPrawo, tylLewo, tylPrawo,
	obrotLewo, obrotPrawo} flagMotors;	//enumeratory sterujące kierunkiem jazdy pojazdu

void M0_ruch(flagMotor kierunek);
void M1_ruch(flagMotor kierunek);
void M2_ruch(flagMotor kierunek);
void M3_ruch(flagMotor kierunek);

void ruchPojazdu(flagMotors kierunek); //funkcja sterująca ruchem całego pojazdu
void przydzielKierunek(char RxData); //funkcja przypisująca odebrane dane Bluetooth na kierunek jazdy

#endif /* INC_MOTOR_H_ */
