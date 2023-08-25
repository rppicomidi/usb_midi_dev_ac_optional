/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
 * Changes Copyright (c) 2023 rppicomidi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * This file is part of the TinyUSB stack.
 */
 
 /**
  * This file implements the usbh_app_driver_get_cb() for the
  * usb_midi_dev_ac_optional driver. You can use this file if
  * the usb_midi_dev_ac_optional is the only application usb
  * device driver you wish to install. Otherwise, you will need
  * to implement the usbh_app_driver_get_cb() yourself.
  */
 #include "tusb_option.h"

#if (CFG_TUD_ENABLED)

//--------------------------------------------------------------------+
// INCLUDE
//--------------------------------------------------------------------+
#include "device/usbd.h"
#include "device/usbd_pvt.h"

#include "class/midi/midi_device.h"
usbd_class_driver_t const* usbd_app_driver_get_cb(uint8_t* driver_count)
{
  static usbd_class_driver_t app_driver =
  {
    .init = midid_init,
    .reset = midid_reset,
    .open = midid_open,
    .control_xfer_cb = midid_control_xfer_cb,
    .xfer_cb = midid_xfer_cb,
    .sof = NULL
  };
  *driver_count = 1;
  return &app_driver;
}

#endif
