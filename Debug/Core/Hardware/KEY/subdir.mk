################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Hardware/KEY/led_control.c 

OBJS += \
./Core/Hardware/KEY/led_control.o 

C_DEPS += \
./Core/Hardware/KEY/led_control.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Hardware/KEY/led_control.o: ../Core/Hardware/KEY/led_control.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Core/Hardware/KEY -I../Core/Hardware/LED -I../Core/Hardware -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Hardware/KEY/led_control.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

