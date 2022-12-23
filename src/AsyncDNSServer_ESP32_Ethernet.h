/****************************************************************************************************************************
  AsyncDNSServer_ESP32_Ethernet.h

  For ESP32_Ethernet (ESP32/S2/S3/C3 + LwIP W5500 / ENC28J60)

  AsyncDNSServer_ESP32_Ethernet is a Async DNS Server library for the ESP32_Ethernet (ESP32/S2/S3/C3 + LwIP W5500 / ENC28J60)

  Based on and modified from ESPAsyncDNSServer Library (https://github.com/devyte/ESPAsyncDNSServer)
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncDNSServer_ESP32_Ethernet
  Licensed under GPLv3 license

  Version: 1.1.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      18/12/2022 Initial coding for ESP32/ES32_S3 using LwIP W5500 / ENC28J60
  1.1.0   K Hoang      22/12/2022 Add support to ESP32S2/C3 using LwIP W5500 / ENC28J60
  *****************************************************************************************************************************/

#pragma once

#ifndef ASYNC_DNS_SERVER_ESP32_ETHERNET_H
#define ASYNC_DNS_SERVER_ESP32_ETHERNET_H

////////////////////////////////////////////////////

#if ( ARDUINO_ESP32S2_DEV || ARDUINO_FEATHERS2 || ARDUINO_ESP32S2_THING_PLUS || ARDUINO_MICROS2 || \
        ARDUINO_METRO_ESP32S2 || ARDUINO_MAGTAG29_ESP32S2 || ARDUINO_FUNHOUSE_ESP32S2 || \
        ARDUINO_ADAFRUIT_FEATHER_ESP32S2_NOPSRAM )
	#if (_ASYNC_DNS_ESP32_ETHERNET_LOGLEVEL_ > 3)
		#warning Using ESP32_S2. To follow library instructions to install esp32-s2 core and WebServer Patch
		#warning You have to select HUGE APP or 1.9-2.0 MB APP to be able to run Config Portal. Must use PSRAM
	#endif

	#define USING_ESP32_S2        true

////////////////////////////////////////

#elif ( ARDUINO_ESP32C3_DEV )
	#if (_ASYNC_DNS_ESP32_ETHERNET_LOGLEVEL_ > 3)
		#if ( defined(ESP_ARDUINO_VERSION_MAJOR) && (ESP_ARDUINO_VERSION_MAJOR >= 2) )
		  #warning Using ESP32_C3 using core v2.0.0+. Either LittleFS, SPIFFS or EEPROM OK
		#else
		  #warning Using ESP32_C3 using core v1.0.6-. To follow library instructions to install esp32-c3 core. Only SPIFFS and EEPROM OK
		#endif

		#warning You have to select Flash size 2MB and Minimal APP (1.3MB + 700KB) for some boards

	#endif

	#define USING_ESP32_C3        true

////////////////////////////////////////

#elif ( defined(ARDUINO_ESP32S3_DEV) || defined(ARDUINO_ESP32_S3_BOX) || defined(ARDUINO_TINYS3) || \
        defined(ARDUINO_PROS3) || defined(ARDUINO_FEATHERS3) )

#if ( defined(ESP_ARDUINO_VERSION_MAJOR) && (ESP_ARDUINO_VERSION_MAJOR >= 2) )
  #warning Using ESP32_S3 using core v2.0.0+. To install esp32-s3-support branch if using core v2.0.2-
#else
  #error To use ESP32_S3 core v2.0.0+
#endif

#define USING_ESP32_S3        true

#elif defined(ESP32)

#define USING_ESP32           true

////////////////////////////////////////

#else
	#error This code is intended to run on the ESP32/S2/S3/C3 platform! Please check your Tools->Board setting.
#endif

////////////////////////////////////////////////////

#if USING_ESP32

  #if USING_W5500
    #if (_ASYNC_DNS_ESP32_ETHERNET_LOGLEVEL_ > 3)
      #warning USING_ESP32_W5500
    #endif

    #include <WebServer_ESP32_W5500.h>     // https://github.com/khoih-prog/WebServer_ESP32_W5500

  #elif USING_ENC28J60

    #if (_ASYNC_DNS_ESP32_ETHERNET_LOGLEVEL_ > 3)
      #warning USING_ESP32_ENC28J60
    #endif

    #include <WebServer_ESP32_ENC.h>       // https://github.com/khoih-prog/WebServer_ESP32_ENC

  #else

    #if (_ASYNC_DNS_ESP32_ETHERNET_LOGLEVEL_ > 3)
      #warning Default to USING_ESP32_W5500
    #endif

    #include <WebServer_ESP32_W5500.h>     // https://github.com/khoih-prog/WebServer_ESP32_W5500

  #endif

#elif (USING_ESP32_S2 || USING_ESP32_S3 || USING_ESP32_C3)

  #if USING_W5500

    #if (_ASYNC_DNS_ESP32_ETHERNET_LOGLEVEL_ > 3)
      #warning USING_ESP32_SC_W5500
    #endif

    #include <WebServer_ESP32_SC_W5500.h>     // https://github.com/khoih-prog/WebServer_ESP32_SC_W5500

  #elif USING_ENC28J60

    #if (_ASYNC_DNS_ESP32_ETHERNET_LOGLEVEL_ > 3)
      #warning USING_ESP32_SC_ENC28J60
    #endif

    #include <WebServer_ESP32_SC_ENC.h>       // https://github.com/khoih-prog/WebServer_ESP32_SC_ENC

  #else

    #if (_ASYNC_DNS_ESP32_ETHERNET_LOGLEVEL_ > 3)
      #warning Default to USING_ESP32_SC_W5500
    #endif

    #include <WebServer_ESP32_SC_W5500.h>     // https://github.com/khoih-prog/WebServer_ESP32_SC_W5500

  #endif

#else

  #error This code is intended to run on the ESP32/S2/S3/C3 platform using LwIP W5500 or ENC28J60

#endif

////////////////////////////////////////////////

#if USING_ESP32

  #if USING_W5500

    #include <AsyncUDP_ESP32_W5500.h>     // https://github.com/khoih-prog/AsyncUDP_ESP32_W5500

  #elif USING_ENC28J60

    #include <AsyncUDP_ESP32_ENC.h>       // https://github.com/khoih-prog/AsyncUDP_ESP32_ENC

  #else

    #include <AsyncUDP_ESP32_W5500.h>     // https://github.com/khoih-prog/AsyncUDP_ESP32_W5500

  #endif

#elif (USING_ESP32_S2 || USING_ESP32_S3 || USING_ESP32_C3)

  #include <AsyncUDP_ESP32_SC_Ethernet.h>

#endif

////////////////////////////////////////////////

#include "AsyncDNSServer_ESP32_Ethernet.hpp"
#include "AsyncDNSServer_ESP32_Ethernet_Impl.h"

////////////////////////////////////////////////

#endif    // ASYNC_DNS_SERVER_ESP32_ETHERNET_H
