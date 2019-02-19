/*
 * DIO.h
 *
 * Created: 2/13/2019 2:03:41 PM
 *  Author: Mohamed Mostafa Abdel Karim
 */ 

#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#define TRUE 1U
#define INTIAL_VALUE 0U

void Keypad_init(void);
uint8 Keypad_getPressedKey(void);

#endif