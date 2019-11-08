################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../_main.c \
../group_anagrams.c \
../is_subsequence.c \
../longest_common_subsequence.c \
../longest_palindrome_subsequence.c \
../longest_palindrome_substring.c \
../string_atmost_k.c 

OBJS += \
./_main.o \
./group_anagrams.o \
./is_subsequence.o \
./longest_common_subsequence.o \
./longest_palindrome_subsequence.o \
./longest_palindrome_substring.o \
./string_atmost_k.o 

C_DEPS += \
./_main.d \
./group_anagrams.d \
./is_subsequence.d \
./longest_common_subsequence.d \
./longest_palindrome_subsequence.d \
./longest_palindrome_substring.d \
./string_atmost_k.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


