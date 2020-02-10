################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/второе\ вхождение\ 2.cpp 

OBJS += \
./src/второе\ вхождение\ 2.o 

CPP_DEPS += \
./src/второе\ вхождение\ 2.d 


# Each subdirectory must supply rules for building sources it contributes
src/второе\ вхождение\ 2.o: ../src/второе\ вхождение\ 2.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/второе вхождение 2.d" -MT"src/второе\ вхождение\ 2.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


