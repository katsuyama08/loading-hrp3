/**
 * EV3RT Platform (Core Services Layer)
 */

#pragma once

typedef struct ev3_driver_information {
	ISR init_func;
	ISR softreset_func;
} ev3_driver_t;

extern ER platform_register_driver(const ev3_driver_t *p_driver);

ER platform_soft_reset();
bool_t platform_is_ready();
void platform_pause_application();

/**
 * EV3RT configurations
 */
extern const bool_t *ev3rt_bluetooth_disabled;     //!< True: Disable and turn off Bluetooth
extern const char   *ev3rt_bluetooth_local_name;   //!< Name for service discovery
extern const char   *ev3rt_bluetooth_pin_code;     //!< Pin code for authentication, up to 16 bytes + '\0'
extern const int    *ev3rt_bluetooth_pan_disabled; //!< True: Disable Bluetooth PAN support, might improve real-time performance slightly
extern const char   *ev3rt_bluetooth_ip_address;   //!< IP address of EV3 brick when using Bluetooth PAN
extern const bool_t *ev3rt_sensor_port_1_disabled; //!< True: use port 1 as a serial port, False: use port 1 as a normal sensor port
extern const bool_t *ev3rt_usb_auto_terminate_app; //!< True: Terminate application automatically if USB is connected
extern const bool_t *ev3rt_low_battery_warning;    //!< True: warn if battery voltage is low

extern int           DEBUG_UART;                   //!< UART used for debug in Linux drivers (0 = port1, 1 = port2, ... 4 = none)

/**
 * Tasks
 */
extern void ev3_main_task(intptr_t exinf);
extern void platform_busy_task(intptr_t exinf);
extern void ev3rt_logtask(intptr_t exinf);

/**
 * Cyclic handlers
 */
extern void ev3_battery_monitor_cyc(intptr_t);

/*
 *  Exception handling
 */
extern void platform_terminator_task(intptr_t);
extern void platform_exception_handler(void *p_excinf);

/*
 *  Provided interface
 */

extern void platform_add_segment_information(const char *name, uintptr_t paddr, size_t size);
