################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/MotorsDriver/motorsdriver.cpp 

OBJS += \
./Core/Src/MotorsDriver/motorsdriver.o 

CPP_DEPS += \
./Core/Src/MotorsDriver/motorsdriver.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/MotorsDriver/%.o Core/Src/MotorsDriver/%.su Core/Src/MotorsDriver/%.cyclo: ../Core/Src/MotorsDriver/%.cpp Core/Src/MotorsDriver/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0plus -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/stornabene/STM32CubeIDE/workspace_1.10.1/Apophis/Core/Src" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-MotorsDriver

clean-Core-2f-Src-2f-MotorsDriver:
	-$(RM) ./Core/Src/MotorsDriver/motorsdriver.cyclo ./Core/Src/MotorsDriver/motorsdriver.d ./Core/Src/MotorsDriver/motorsdriver.o ./Core/Src/MotorsDriver/motorsdriver.su

.PHONY: clean-Core-2f-Src-2f-MotorsDriver

