################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/наибольший\ общий\ делитель.cpp 

OBJS += \
./src/наибольший\ общий\ делитель.o 

CPP_DEPS += \
./src/наибольший\ общий\ делитель.d 


# Each subdirectory must supply rules for building sources it contributes
src/наибольший\ общий\ делитель.o: ../src/наибольший\ общий\ делитель.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/наибольший общий делитель.d" -MT"src/наибольший\ общий\ делитель.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


