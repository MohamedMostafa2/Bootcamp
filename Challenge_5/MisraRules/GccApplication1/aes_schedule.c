/*
 *
 * Chinese Academy of Sciences
 * State Key Laboratory of Information Security
 * Institute of Information Engineering
 *
 * Copyright (C) 2016 Chinese Academy of Sciences
 *
 * LuoPeng, luopeng@iie.ac.cn
 * Updated in Oct 2016
 * Updated in Jan 2017, update muliple function on GF(2^8).
 *
 */
/*#include <stdint.h>*/


#include "aes_schedule.h"
#include "aes_encrypt.h"
/*
 * round constants
 */

void aes_key_schedule_128( const uint8_t key[], uint8_t roundkeys[]) { /* declare key & roundkeys as array*/
    const uint8_t  RC[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36}; /* only used in this function so i put it inside that function*/
    uint8_t temp[4];
    uint8_t i;

    for (i =(uint8_t) 0; i < (uint8_t)16; ++i) { /*casting for 0 & 16 */
        roundkeys[i] = key[i];

    }

    uint8_t j=16;
    for (i = (uint8_t)0; i < (uint8_t)AES_ROUNDS; ++i) {

        /* k0-k3 for next round*/

        temp[3] = SBOX[roundkeys[j-(uint8_t)4]];
            temp[0] = SBOX[roundkeys[j-(uint8_t)3]];
            temp[1] = SBOX[roundkeys[j-(uint8_t)2]];
            temp[2] = SBOX[roundkeys[j-(uint8_t)1]];
            temp[0] ^= RC[i];
/*            lastround = roundkeys-(uint8_t)16;*/
            roundkeys[j] = temp[0] ^ roundkeys[j-(uint8_t)16];
        j++;
            roundkeys[j] = temp[1] ^ roundkeys[j-(uint8_t)16];
            j++;
        roundkeys[j] = temp[2] ^ roundkeys[j-(uint8_t)16];
            j++;
        roundkeys[j] = temp[3] ^ roundkeys[j-(uint8_t)16];
            j++;
        /* k4-k7 for next round*/
            roundkeys[j] = roundkeys[j-(uint8_t)4] ^ roundkeys[j-(uint8_t)16];
        j++;
            roundkeys[j] = roundkeys[j-(uint8_t)4] ^ roundkeys[j-(uint8_t)16];
            j++;
        roundkeys[j] = roundkeys[j-(uint8_t)4] ^ roundkeys[j-(uint8_t)16];
            j++;
        roundkeys[j] = roundkeys[j-(uint8_t)4] ^ roundkeys[j-(uint8_t)16];
            j++;
        /* k8-k11 for next round*/
            roundkeys[j] = roundkeys[j-(uint8_t)4] ^ roundkeys[j-(uint8_t)16];
            j++;
        roundkeys[j] = roundkeys[j-(uint8_t)4] ^ roundkeys[j-(uint8_t)16];
            j++;
        roundkeys[j] = roundkeys[j-(uint8_t)4] ^ roundkeys[j-(uint8_t)16];
            j++;
        roundkeys[j] = roundkeys[j-(uint8_t)4] ^ roundkeys[j-(uint8_t)16];
            j++;
        /* k12-k15 for next round*/
            roundkeys[j] = roundkeys[j-(uint8_t)4] ^ roundkeys[j-(uint8_t)16];
            j++;
        roundkeys[j] = roundkeys[j-(uint8_t)4] ^ roundkeys[j-(uint8_t)16];
            j++;
        roundkeys[j] = roundkeys[j-(uint8_t)4] ^ roundkeys[j-(uint8_t)16];
            j++;
        roundkeys[j] = roundkeys[j-(uint8_t)4] ^ roundkeys[j-(uint8_t)16];
            j++;
        }
    }
