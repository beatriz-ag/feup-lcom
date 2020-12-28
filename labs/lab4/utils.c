#include <lcom/lcf.h>

#include <stdint.h>
int(util_sys_inb)(int port, uint8_t *value) {
  uint32_t val32bit;
  if (sys_inb(port, &val32bit)) {
    printf("Error in sys_inb()\n");
    return 1;
  }
  *value = (uint8_t) val32bit; //Truncation won't be a problem in this specific case
  return 0;
}
