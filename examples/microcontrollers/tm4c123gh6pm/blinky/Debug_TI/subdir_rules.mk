################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
blinky.obj: ../blinky.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/ahmed/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/media/ahmed/Data/Workshop/Embedded/Microcontroller/ARM/ccs/ZeeDK/examples/microcontrollers/tm4c123gh6pm/blinky" --include_path="/media/ahmed/Data/Workshop/Embedded/Microcontroller/ARM/ccs/ZeeDK/" --include_path="/home/ahmed/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="blinky.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

blinky2.obj: ../blinky2.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/ahmed/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/media/ahmed/Data/Workshop/Embedded/Microcontroller/ARM/ccs/ZeeDK/examples/microcontrollers/tm4c123gh6pm/blinky" --include_path="/media/ahmed/Data/Workshop/Embedded/Microcontroller/ARM/ccs/ZeeDK/" --include_path="/home/ahmed/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="blinky2.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_gnu_tm4c123gh6pm.obj: ../startup_gnu_tm4c123gh6pm.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/ahmed/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/media/ahmed/Data/Workshop/Embedded/Microcontroller/ARM/ccs/ZeeDK/examples/microcontrollers/tm4c123gh6pm/blinky" --include_path="/media/ahmed/Data/Workshop/Embedded/Microcontroller/ARM/ccs/ZeeDK/" --include_path="/home/ahmed/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="startup_gnu_tm4c123gh6pm.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_ti_tm4c123gh6pm.obj: ../startup_ti_tm4c123gh6pm.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/ahmed/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/media/ahmed/Data/Workshop/Embedded/Microcontroller/ARM/ccs/ZeeDK/examples/microcontrollers/tm4c123gh6pm/blinky" --include_path="/media/ahmed/Data/Workshop/Embedded/Microcontroller/ARM/ccs/ZeeDK/" --include_path="/home/ahmed/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="startup_ti_tm4c123gh6pm.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


