#include "hid.h"


void usb_hid_process_report(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize)
{
  (void) instance;
  
  if(report_id == REPORT_ID_CUSTOM){
    
    if(buffer[0] == ENTER_BOOTLOADER_COMMAND){
      enter_bootloader();
    }
  }
}