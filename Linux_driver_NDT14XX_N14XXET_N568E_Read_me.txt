  -----------------------------------------------------------------------------

                   --- CAEN SpA - Computing Systems Division --- 

  -----------------------------------------------------------------------------

  CAEN DT55xxE - DT/R/N14xxET - NDT14xx - N1570 - N568E Linux 32/64bit USB Linux Driver Information

  -----------------------------------------------------------------------------
  
  System Required 
  -------------------
  
  - Linux OS  
  
  - CAEN USB Card:
    - NIM High Voltage Power Supplies:
      > N1419ET - 4 Channel 500 V/200 µA NIM HV Power Supply Module (USB/Ethernet/T.screen)
	  > N1470ET - 4 Channel 8 kV/3 mA (8 W) NIM HV Power Supply Module (USB/Ethernet/T.screen)
	  > N1471ET - 4 Channel 5.5 kV/300 µA NIM HV Power Supply Module (USB/Ethernet/T.screen)
	  > N1471HET - 4 Channel 5.5 kV/20 µA NIM HV Power Supply High Accuracy Module (USB/Ethernet/T.screen)
	  > N1570 - 2 Channel 15 kV/1 mA (10 W) NIM HV Power Supply Module (USB/Ethernet/T.screen)
	
    - NIM/Desktop High Voltage Power Supplies:
      > NDT1419 - 4 Channel 500 V/200 µA NIM/Desktop HV Power Supply Module (USB/Ethernet/T.screen)
	  > NDT1470 - 4 Channel 8 kV/3 mA (8 W) NIM/Desktop HV Power Supply Module (USB/Ethernet/T.screen)
	  > NDT1471 - 4 Channel 5.5 kV/300 µA NIM/Desktop HV Power Supply Module (USB/Ethernet/T.screen)
	  > NDT1471H - 4 Channel 5.5 kV/20 µA NIM/Desktop HV Power Supply High Accuracy Module (USB/Ethernet/T.screen)
	  
	-  Rack-mount High Voltage Power Supplies
	  > R1419ET - 8/4 Ch Reversible 500 V/200 µA 19'' HV Power Supply Module (USB/Ethernet/T.screen)
	  > R1470ET - 8/4 Ch Reversible 8 kV/3 mA (8 W) Desktop 19'' Power Supply Module (USB/Ethernet/T.screen)
	  > R1471ET - 8/4 Ch Reversible 5.5 kV/300 µA Desktop 19'' Power Supply Module (USB/Ethernet/T.screen)
	  > R1471HET - 8/4 Ch Reversible 5.5 kV/20 µA 19'' HV Power Supply High Accuracy Module (USB/Ethernet/T.screen)
	  
	- Desktop High Voltage Power Supplies
	  > DT1419ET - 4 Ch Reversible 500 V/200 µA Desktop HV Power Supply Module (USB/Ethernet/T.screen)
	  > DT1470ET - 4 Ch Reversible 8 kV/3 mA (8 W) Desktop HV Power Supply Module (USB/Ethernet/T.screen)
	  > DT1471ET - 4 Ch Reversible 5.5 kV/300 µA Desktop HV Power Supply Module (USB/Ethernet/T.screen)
	  > DT1471HET - 4 Ch Reversible 5.5 kV/20 µA Desktop HV Power Supply High Accuracy Module (USB/Ethernet/T.screen)
	
	  > DT5519E - 4 Channel 500 V/3 mA Desktop HV Power Supply Module (USB/Ethernet)
	  > DT5521E - 4 Channel 6 kV/300 µA Desktop HV Power Supply Module (USB/Ethernet)
	  > DT5521HE - 4 Channel 6 kV/20 µA Desktop HV Power Supply Module (USB/Ethernet)
	  > DT5533E - 4 Channel 4 kV/3 mA (4 W) Desktop HV Power Supply Module (USB/Ethernet)
	  > DT5534E - 4 Channel 6 kV/1 mA (4 W) Desktop HV Power Supply Module (USB/Ethernet)
	  
	- NIM Spectroscopy Amplifiers
	  > N568E/N568ELC  16 Channel Programmable Spectroscopy Amplifier 
	  
  Description
  -----------

  CAEN Modules listed above are conform to USB Communication Device Class Abstract Control Model 
  (= USB CDC ACM) that is supported by Linux kernel since version 2.6.x
  
  If recognized by Linux OS, CAEN Module is assigned to serial port with name /dev/ttyACM[x], where [x] is device number; 
  for example 1st module connected  is /dev/ttyACM0, 2nd module is /dev/ttyACM1 etc. See more details with the dmesg command.
  
  In some Linux distributions the module is not recognized and it has to be added manually with the command: 
	modprobe usbserial vendor=0x21e1 product= [id]
  The product id can be found running the command dmesg after connecting the module.
  Once added the module, to get the serial port name (e.g. ttyUSB0), use dmesg command.

  How to get support
  ------------------

  For software support 
   - visit the page http://www.caen.it/csite/ProductSupport.jsp
   - or send mail to:  support.computing@caen.it
