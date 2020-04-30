TEMPLATE = app
#CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += TEST_TYPE_GTEST=1
DEFINES += TEST_TYPE_COVERAGE=2

CONFIG(gtest, gtest|lcov){
    message("Build for GoogleTest")
    DEFINES += UNIT_TEST_TYPE=TEST_TYPE_GTEST
}

CONFIG(lcov, gtest|lcov){
    message("Build for Code Coverage Report")
    DEFINES += UNIT_TEST_TYPE=TEST_TYPE_COVERAGE
}

DEFINES += TCC803x

LIBS += -lgtest -lpthread -lgcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CXXFLAGS += -fpermissive

QMAKE_CXXFLAGS += -Wno-unused-parameter -Wno-unused-variable

INCLUDEPATH += ../src/APP/NVMManagerApp
INCLUDEPATH += ../src/APP/SystemMonitoringApp
INCLUDEPATH += ../src/APP/PowerManagerApp
INCLUDEPATH += ../src/APP/VehicleSignalDemoApp
INCLUDEPATH += ../src/APP/KeyApp
INCLUDEPATH += ../src/APP/ConsoleDemoApp
INCLUDEPATH += ../src/APP/AudioApp
INCLUDEPATH += ../src/APP/TestApp/snor/include
INCLUDEPATH += ../src/APP/TestApp/snor
INCLUDEPATH += ../src/APP/TestApp
INCLUDEPATH += ../src/APP
INCLUDEPATH += ../src/OSAL/osal_ucos
INCLUDEPATH += ../src/OSAL/osal_none
INCLUDEPATH += ../src/OSAL/osal_freertos
INCLUDEPATH += ../src/OSAL
INCLUDEPATH += ../src/SERVICE/NVMManager
INCLUDEPATH += ../src/SERVICE/HSMManager
INCLUDEPATH += ../src/SERVICE/IPC
INCLUDEPATH += ../src/SERVICE/console
INCLUDEPATH += ../src/SERVICE
INCLUDEPATH += ../src/Scripts/CVD
INCLUDEPATH += ../src/Scripts/T32
INCLUDEPATH += ../src/Scripts
INCLUDEPATH += ../src/BSP/tcc803x/pinmux
INCLUDEPATH += ../src/BSP/tcc803x/dev/ipc/include
INCLUDEPATH += ../src/BSP/tcc803x/dev/ipc
INCLUDEPATH += ../src/BSP/tcc803x/dev/pm/include
INCLUDEPATH += ../src/BSP/tcc803x/dev/pm
INCLUDEPATH += ../src/BSP/tcc803x/dev/timer/include
INCLUDEPATH += ../src/BSP/tcc803x/dev/timer
INCLUDEPATH += ../src/BSP/tcc803x/dev/adc/include
INCLUDEPATH += ../src/BSP/tcc803x/dev/adc
INCLUDEPATH += ../src/BSP/tcc803x/dev/eeprom/include
INCLUDEPATH += ../src/BSP/tcc803x/dev/eeprom
INCLUDEPATH += ../src/BSP/tcc803x/dev/watchdog/include
INCLUDEPATH += ../src/BSP/tcc803x/dev/watchdog
INCLUDEPATH += ../src/BSP/tcc803x/dev/ictc/include
INCLUDEPATH += ../src/BSP/tcc803x/dev/ictc
INCLUDEPATH += ../src/BSP/tcc803x/dev/pwm/include
INCLUDEPATH += ../src/BSP/tcc803x/dev/pwm
INCLUDEPATH += ../src/BSP/tcc803x/dev
INCLUDEPATH += ../src/BSP/tcc803x/ARM/GCC
INCLUDEPATH += ../src/BSP/tcc803x/ARM/GHC
INCLUDEPATH += ../src/BSP/tcc803x/ARM
INCLUDEPATH += ../src/BSP/tcc803x
INCLUDEPATH += ../src/BSP
INCLUDEPATH += ../src/OS/freertos/portable/ARM_CA7/GCC
INCLUDEPATH += ../src/OS/freertos/portable/ARM_CA7
INCLUDEPATH += ../src/OS/freertos/portable/ARM_CR5/GCC
INCLUDEPATH += ../src/OS/freertos/portable/ARM_CR5/GHC
INCLUDEPATH += ../src/OS/freertos/portable/ARM_CR5
INCLUDEPATH += ../src/OS/freertos/portable/MemMang
INCLUDEPATH += ../src/OS/freertos/portable
INCLUDEPATH += ../src/OS/freertos/include
INCLUDEPATH += ../src/OS/freertos
INCLUDEPATH += ../src/OS/none/GCC
INCLUDEPATH += ../src/OS/none/GHC
INCLUDEPATH += ../src/OS/none
INCLUDEPATH += ../src/OS
INCLUDEPATH += ../src/HAL/HAL_CODEC
INCLUDEPATH += ../src/HAL/HAL_SPEED_INPUT_CAPTURE
INCLUDEPATH += ../src/HAL/HAL_IPC
INCLUDEPATH += ../src/HAL/HAL_CONSOLE
INCLUDEPATH += ../src/HAL/HAL_TIMER
INCLUDEPATH += ../src/HAL/HAL_ILL_PWM_OUT
INCLUDEPATH += ../src/HAL/HAL_GPIO_KEY
INCLUDEPATH += ../src/HAL/HAL_NVM
INCLUDEPATH += ../src/HAL/HAL_VEHICLE_SIGNAL
INCLUDEPATH += ../src/HAL/HAL_ADC_KEY
INCLUDEPATH += ../src/HAL/HAL_ILL_INPUT_CAPTURE
INCLUDEPATH += ../src/HAL/HAL_POWER_MANAGER
INCLUDEPATH += ../src/HAL/HAL_SPEED_PWM_OUT
INCLUDEPATH += ../src/HAL

SOURCES += \
    utest_main.cc \
    dummy.cc

DISTFILES += \
    ../src/APP/AudioApp/Audio_App.c \
    ../src/APP/ConsoleDemoApp/ConsoleDemoApp.c \
    ../src/APP/KeyApp/Key_App.c \
    ../src/APP/NVMManagerApp/NVMManager_App.c \
    ../src/APP/PowerManagerApp/PowerManager_App.c \
    ../src/APP/SystemMonitoringApp/SystemMonitoring_App.c \
    ../src/APP/TestApp/snor/snor.c \
    ../src/APP/TestApp/snor/snor_mio.c \
    ../src/APP/TestApp/SnorTest.c \
    ../src/APP/TestApp/Test_App.c \
    ../src/APP/TestApp/UartRouting.c \
    ../src/APP/VehicleSignalDemoApp/VehicleSignalDemoApp.c \
    ../src/APP/main.c \
    ../src/BSP/tcc803x/ARM/bsp_int.c \
    ../src/BSP/tcc803x/ARM/bsp_os_timer.c \
    ../src/BSP/tcc803x/ARM/libgcc.c \
    ../src/BSP/tcc803x/ARM/mpu.c \
    ../src/BSP/tcc803x/dev/adc/tcc_adc.c \
    ../src/BSP/tcc803x/dev/eeprom/eeprom.c \
    ../src/BSP/tcc803x/dev/ictc/ictc.c \
    ../src/BSP/tcc803x/dev/ipc/tcc_ipc_buffer.c \
    ../src/BSP/tcc803x/dev/ipc/tcc_ipc_cmd.c \
    ../src/BSP/tcc803x/dev/ipc/tcc_ipc_ctl.c \
    ../src/BSP/tcc803x/dev/ipc/tcc_ipc_mbox.c \
    ../src/BSP/tcc803x/dev/ipc/tcc_ipc_os.c \
    ../src/BSP/tcc803x/dev/pm/tcc_pmgpio.c \
    ../src/BSP/tcc803x/dev/pwm/pwm.c \
    ../src/BSP/tcc803x/dev/timer/tcc_timer.c \
    ../src/BSP/tcc803x/dev/watchdog/tcc_wdt.c \
    ../src/BSP/tcc803x/bsp.c \
    ../src/BSP/tcc803x/bsp_os.c \
    ../src/BSP/tcc803x/clock.c \
    ../src/BSP/tcc803x/debug.c \
    ../src/BSP/tcc803x/device_share_config.c \
    ../src/BSP/tcc803x/div64.c \
    ../src/BSP/tcc803x/gdma.c \
    ../src/BSP/tcc803x/gpio.c \
    ../src/BSP/tcc803x/i2c-detect.c \
    ../src/BSP/tcc803x/i2c.c \
    ../src/BSP/tcc803x/reg_test.c \
    ../src/BSP/tcc803x/spi-test.c \
    ../src/BSP/tcc803x/spi.c \
    ../src/BSP/tcc803x/tcc_ckc.c \
    ../src/BSP/tcc803x/uart.c \
    ../src/BSP/tcc803x/udma.c \
    ../src/HAL/HAL_ADC_KEY/HAL_ADCKey.c \
    ../src/HAL/HAL_CODEC/HAL_CODEC.c \
    ../src/HAL/HAL_CONSOLE/HAL_Console.c \
    ../src/HAL/HAL_GPIO_KEY/HAL_GPIOKey.c \
    ../src/HAL/HAL_GPIO_KEY/HAL_Rotary.c \
    ../src/HAL/HAL_ILL_INPUT_CAPTURE/HAL_IlluminateInputCapture.c \
    ../src/HAL/HAL_ILL_PWM_OUT/HAL_IlluminatePwmOut.c \
    ../src/HAL/HAL_IPC/HAL_IPC_CA53.c \
    ../src/HAL/HAL_IPC/HAL_IPC_CA7.c \
    ../src/HAL/HAL_IPC/HAL_IPC_CM4.c \
    ../src/HAL/HAL_NVM/HAL_FRAM.c \
    ../src/HAL/HAL_NVM/HAL_NVM.c \
    ../src/HAL/HAL_POWER_MANAGER/HAL_PowerManager.c \
    ../src/HAL/HAL_SPEED_INPUT_CAPTURE/HAL_SpeedInputCapture.c \
    ../src/HAL/HAL_SPEED_PWM_OUT/HAL_SpeedPwmOut.c \
    ../src/HAL/HAL_TIMER/HAL_Timer.c \
    ../src/HAL/HAL_VEHICLE_SIGNAL/HAL_VehicleSignal.c \
    ../src/HAL/HAL_API.c \
    ../src/HAL/HAL_devices.c \
    ../src/OS/freertos/portable/ARM_CA7/port.c \
    ../src/OS/freertos/portable/ARM_CR5/port.c \
    ../src/OS/freertos/portable/MemMang/heap_1.c \
    ../src/OS/freertos/portable/MemMang/heap_2.c \
    ../src/OS/freertos/portable/MemMang/heap_3.c \
    ../src/OS/freertos/portable/MemMang/heap_4.c \
    ../src/OS/freertos/portable/MemMang/heap_5.c \
    ../src/OS/freertos/croutine.c \
    ../src/OS/freertos/event_groups.c \
    ../src/OS/freertos/list.c \
    ../src/OS/freertos/queue.c \
    ../src/OS/freertos/tasks.c \
    ../src/OS/freertos/timers.c \
    ../src/OSAL/osal_freertos/osal_freertos_impl.c \
    ../src/OSAL/osal_none/osal_none_impl.c \
    ../src/OSAL/osal_ucos/osal_ucos_impl.c \
    ../src/SERVICE/console/Console.c \
    ../src/SERVICE/HSMManager/HSMManager.c \
    ../src/SERVICE/IPC/IPC_Parser.c \
    ../src/SERVICE/IPC/tcc_ipc_protocol.c \
    ../src/SERVICE/NVMManager/NVMManager.c \
    ../src/SERVICE/FWUG_SysFunc.c

DISTFILES += \
    run_utest.sh \
    ../src/APP/AudioApp/Audio_App.h \
    ../src/APP/ConsoleDemoApp/ConsoleDemoApp.h \
    ../src/APP/KeyApp/Key_App.h \
    ../src/APP/NVMManagerApp/NVMManager_App.h \
    ../src/APP/PowerManagerApp/PowerManager_App.h \
    ../src/APP/SystemMonitoringApp/SystemMonitoring_App.h \
    ../src/APP/TestApp/snor/include/mmc_bl1.h \
    ../src/APP/TestApp/snor/include/snor.h \
    ../src/APP/TestApp/snor/include/SNOR_Loader_TCC8020_on_eeprom.h \
    ../src/APP/TestApp/snor/include/SNOR_Loader_TCC803X.h \
    ../src/APP/TestApp/snor/include/SNOR_Loader_TCC897X.h \
    ../src/APP/TestApp/snor/include/snor_mio.h \
    ../src/APP/TestApp/snor/include/snor_mio_gdma.h \
    ../src/APP/TestApp/snor/include/snor_mio_gpio.h \
    ../src/APP/TestApp/22m_hac_pinmux_define.h \
    ../src/APP/TestApp/SnorTest.h \
    ../src/APP/TestApp/Test_App.h \
    ../src/APP/TestApp/UartRouting.h \
    ../src/APP/VehicleSignalDemoApp/VehicleSignalDemoApp.h \
    ../src/APP/app_cfg.h \
    ../src/APP/main.h \
    ../src/BSP/tcc803x/ARM/bsp_int.h \
    ../src/BSP/tcc803x/ARM/bsp_os_timer.h \
    ../src/BSP/tcc803x/ARM/cache.h \
    ../src/BSP/tcc803x/ARM/mpu.h \
    ../src/BSP/tcc803x/dev/adc/include/mt_adc.h \
    ../src/BSP/tcc803x/dev/eeprom/include/eeprom.h \
    ../src/BSP/tcc803x/dev/eeprom/include/eeprom_gpio.h \
    ../src/BSP/tcc803x/dev/ictc/include/ictc.h \
    ../src/BSP/tcc803x/dev/ipc/include/tcc_ipc.h \
    ../src/BSP/tcc803x/dev/ipc/include/tcc_ipc_buffer.h \
    ../src/BSP/tcc803x/dev/ipc/include/tcc_ipc_cmd.h \
    ../src/BSP/tcc803x/dev/ipc/include/tcc_ipc_ctl.h \
    ../src/BSP/tcc803x/dev/ipc/include/tcc_ipc_mbox.h \
    ../src/BSP/tcc803x/dev/ipc/include/tcc_ipc_os.h \
    ../src/BSP/tcc803x/dev/ipc/include/tcc_ipc_typedef.h \
    ../src/BSP/tcc803x/dev/pm/include/tcc_pmgpio.h \
    ../src/BSP/tcc803x/dev/pwm/include/pwm.h \
    ../src/BSP/tcc803x/dev/timer/include/tcc_timer.h \
    ../src/BSP/tcc803x/dev/watchdog/include/tcc_wdt.h \
    ../src/BSP/tcc803x/bsp.h \
    ../src/BSP/tcc803x/bsp_os.h \
    ../src/BSP/tcc803x/ckc_reg.h \
    ../src/BSP/tcc803x/clock.h \
    ../src/BSP/tcc803x/debug.h \
    ../src/BSP/tcc803x/device_share_config.h \
    ../src/BSP/tcc803x/div64.h \
    ../src/BSP/tcc803x/gdma.h \
    ../src/BSP/tcc803x/gpio.h \
    ../src/BSP/tcc803x/i2c.h \
    ../src/BSP/tcc803x/pll_config.h \
    ../src/BSP/tcc803x/reg_phys.h \
    ../src/BSP/tcc803x/spi.h \
    ../src/BSP/tcc803x/tcc_ckc.h \
    ../src/BSP/tcc803x/types.h \
    ../src/BSP/tcc803x/uart.h \
    ../src/BSP/tcc803x/udma.h \
    ../src/HAL/HAL_ADC_KEY/HAL_ADCKey.h \
    ../src/HAL/HAL_CODEC/HAL_CODEC.h \
    ../src/HAL/HAL_CONSOLE/HAL_Console.h \
    ../src/HAL/HAL_GPIO_KEY/HAL_GPIOKey.h \
    ../src/HAL/HAL_GPIO_KEY/HAL_Rotary.h \
    ../src/HAL/HAL_ILL_INPUT_CAPTURE/HAL_IlluminateInputCapture.h \
    ../src/HAL/HAL_ILL_PWM_OUT/HAL_IlluminatePwmOut.h \
    ../src/HAL/HAL_IPC/HAL_IPC.h \
    ../src/HAL/HAL_IPC/HAL_IPC_CA53.h \
    ../src/HAL/HAL_IPC/HAL_IPC_CA7.h \
    ../src/HAL/HAL_IPC/HAL_IPC_CM4.h \
    ../src/HAL/HAL_NVM/HAL_FRAM.h \
    ../src/HAL/HAL_NVM/HAL_NVM.h \
    ../src/HAL/HAL_POWER_MANAGER/HAL_PowerManager.h \
    ../src/HAL/HAL_SPEED_INPUT_CAPTURE/HAL_SpeedInputCapture.h \
    ../src/HAL/HAL_SPEED_PWM_OUT/HAL_SpeedPwmOut.h \
    ../src/HAL/HAL_TIMER/HAL_Timer.h \
    ../src/HAL/HAL_VEHICLE_SIGNAL/HAL_VehicleSignal.h \
    ../src/HAL/HAL_API.h \
    ../src/HAL/HAL_devices.h \
    ../src/OS/freertos/include/croutine.h \
    ../src/OS/freertos/include/deprecated_definitions.h \
    ../src/OS/freertos/include/event_groups.h \
    ../src/OS/freertos/include/FreeRTOS.h \
    ../src/OS/freertos/include/FreeRTOSConfig.h \
    ../src/OS/freertos/include/list.h \
    ../src/OS/freertos/include/mpu_prototypes.h \
    ../src/OS/freertos/include/mpu_wrappers.h \
    ../src/OS/freertos/include/portable.h \
    ../src/OS/freertos/include/projdefs.h \
    ../src/OS/freertos/include/queue.h \
    ../src/OS/freertos/include/semphr.h \
    ../src/OS/freertos/include/StackMacros.h \
    ../src/OS/freertos/include/task.h \
    ../src/OS/freertos/include/timers.h \
    ../src/OS/freertos/portable/ARM_CA7/portmacro.h \
    ../src/OS/freertos/portable/ARM_CR5/portmacro.h \
    ../src/OSAL/osal_freertos/osal_freertos_impl.h \
    ../src/OSAL/osal_none/osal_none_impl.h \
    ../src/OSAL/osal_ucos/osal_ucos_impl.h \
    ../src/OSAL/osal.h \
    ../src/SERVICE/console/Console.h \
    ../src/SERVICE/HSMManager/HSMManager.h \
    ../src/SERVICE/IPC/IPC_Parser.h \
    ../src/SERVICE/IPC/tcc_ipc_protocol.h \
    ../src/SERVICE/NVMManager/NVMManager.h \
    ../src/SERVICE/FWUG_SysFunc.h

HEADERS += \
    utest_main.h

