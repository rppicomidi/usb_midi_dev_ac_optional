# usb_midi_dev_ac_optional
A TinyUSB application USB MIDI Device driver that permits no AUDIO CONTROL in the descriptor.

There are a number of commercial USB MIDI devices on the market that do
not include an AUDIO CONTROL interface in the USB Configuration descriptor.
Major operating systems work fine with them. The master branch of TinyUSB
is strict about requiring the AUDIO CONTROL interface. This is fine
behavior normally. However, projects such as
[pico-usb-midi-filter](https://github.com/rppicomidi/pico-usb-midi-filter) and 
[pico-usb-midi-processor](https://github.com/rppicomidi/pico-usb-midi-processor)
attempt to present exact copies of the USB Descriptor of the MIDI device connected
to the USB Host port. If the MIDI device happens to lack an AUDIO CONTROL
interface, then the native TinyUSB driver will not accept the descriptor
copied from the attached device.

At the time of this writing, this driver is identical to the TinyUSB MIDI Device
driver with a few minor tweaks to make the AUDIO CONTROL interface in the
USB configuration descriptor optional. It is constructed as an application
driver and installed using the `usbd_app_driver_get_cb()` function.

If, for some reason, you need multiple instances of this driver, redefine
`CFG_TUD_MIDI_AC_OPTIONAL` to something greater than 1.

The CMakeLists.txt creates two interface libraries: `usb_midi_device_ac_optional`
builds the USB MIDI device driver only. `usb_midi_device_app_driver` implements
the `usbd_app_driver_get_cb()` function assuming that `usb_midi_device_ac_optional`
is the only application device driver. If you need the `usb_midi_device_ac_optional`
driver plus other application drivers, you will need to write your own version
of `usbd_app_driver_get_cb()`.

