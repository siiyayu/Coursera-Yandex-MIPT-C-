################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/расчет\ стоимости\ товара.cpp 

OBJS += \
./src/расчет\ стоимости\ товара.o 

CPP_DEPS += \
./src/расчет\ стоимости\ товара.d 


# Each subdirectory must supply rules for building sources it contributes
src/расчет\ стоимости\ товара.o: ../src/расчет\ стоимости\ товара.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/расчет стоимости товара.d" -MT"src/расчет\ стоимости\ товара.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


