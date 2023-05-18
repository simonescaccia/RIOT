#include "net/loramac.h"     /* core loramac definitions */
#include "semtech_loramac.h" /* package API */

#include <string.h>

semtech_loramac_t loramac;  /* The loramac stack device descriptor */

/* define the required keys for OTAA, e.g over-the-air activation (the
   null arrays need to be updated with valid LoRa values) */
static const uint8_t deveui[LORAMAC_DEVEUI_LEN] = { 0x70, 0xB3, 0xD5, 0x7E, \
                                                    0xD0, 0x05, 0xD1, 0xE7 };
static const uint8_t appeui[LORAMAC_APPEUI_LEN] = { 0x00, 0x00, 0x00, 0x00, \
                                                    0x00, 0x00, 0x00, 0x00 };
static const uint8_t appkey[LORAMAC_APPKEY_LEN] = { 0x27, 0x2E, 0x77, 0x9C, \
                                                    0x39, 0x6D, 0x1E, 0x51, \
                                                    0xE9, 0x4B, 0x9B, 0xDD, \
                                                    0x39, 0x55, 0x8E, 0xB0 };

int main(void)
{
    /* 1. initialize the LoRaMAC MAC layer */
    semtech_loramac_init(&loramac);
 
    /* 2. set the keys identifying the device */
    semtech_loramac_set_deveui(&loramac, deveui);
    semtech_loramac_set_appeui(&loramac, appeui);
    semtech_loramac_set_appkey(&loramac, appkey);
 
    /* 3. join the network */
    if (semtech_loramac_join(&loramac, LORAMAC_JOIN_OTAA) != SEMTECH_LORAMAC_JOIN_SUCCEEDED) {
        puts("Join procedure failed");
        return 1;
    }
    puts("Join procedure succeeded");
 
    /* 4. send some data */
    char *message = "This is RIOT";
    if (semtech_loramac_send(&loramac,
                             (uint8_t *)message, strlen(message)) != SEMTECH_LORAMAC_TX_DONE) {
        printf("Cannot send message '%s'\n", message);
        return 1;
    }
 
}
