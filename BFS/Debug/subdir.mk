################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BFS_helper_queue.c \
../BFS_helper_stack.c \
../BFS_main.c \
../shortest_path_in_binary_matrix.c 

OBJS += \
./BFS_helper_queue.o \
./BFS_helper_stack.o \
./BFS_main.o \
./shortest_path_in_binary_matrix.o 

C_DEPS += \
./BFS_helper_queue.d \
./BFS_helper_stack.d \
./BFS_main.d \
./shortest_path_in_binary_matrix.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


