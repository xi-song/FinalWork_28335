################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/CCS/ccs/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./DSP2833x_ADC_cal.obj" \
"./DSP2833x_CodeStartBranch.obj" \
"./DSP2833x_DefaultIsr.obj" \
"./DSP2833x_GlobalVariableDefs.obj" \
"./DSP2833x_PieCtrl.obj" \
"./DSP2833x_PieVect.obj" \
"./DSP2833x_Sci.obj" \
"./DSP2833x_SysCtrl.obj" \
"./DSP2833x_usDelay.obj" \
"./Hardware/SRC/DCmotor.obj" \
"./Hardware/SRC/DSP2833x_CpuTimers.obj" \
"./Hardware/SRC/key.obj" \
"./Hardware/SRC/keyboard.obj" \
"./Hardware/SRC/led.obj" \
"./Hardware/SRC/scic.obj" \
"./Hardware/SRC/step_motor.obj" \
"./Hardware/SRC/timer.obj" \
"./User/Example_2833xScia_FFDLB.obj" \
"../28335_RAM_lnk.cmd" \
"../DSP2833x_Headers_nonBIOS.cmd" \
$(GEN_CMDS__FLAG) \
-lrts2800_fpu32.lib \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Hardware/SRC/subdir_vars.mk
-include User/subdir_vars.mk
-include subdir_rules.mk
-include Hardware/SRC/subdir_rules.mk
-include User/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Example_2833xScia_FFDLB.out \

EXE_OUTPUTS__QUOTED += \
"Example_2833xScia_FFDLB.out" \


# All Target
all: Example_2833xScia_FFDLB.out

# Tool invocations
Example_2833xScia_FFDLB.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"D:/CCS/ccs/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --define=_DEBUG --define=LARGE_MODEL --quiet --diag_wrap=off --display_error_number --issue_remarks --output_all_syms -z -m"Example_2833xScia_FFDLB.map" --stack_size=0X200 --warn_sections -i"D:/CCS/ccs/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/lib" -i"D:/CCS/ccs/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" -i"D:/CCS/Project/Example_2833xScia_FFDLB" -i"D:/2017.3.6/SourceCode16_SciC232_9600_OK" -i"D:/DSP2833x_headers/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="Example_2833xScia_FFDLB_linkInfo.xml" --rom_model -o "Example_2833xScia_FFDLB.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "DSP2833x_ADC_cal.obj" "DSP2833x_CodeStartBranch.obj" "DSP2833x_DefaultIsr.obj" "DSP2833x_GlobalVariableDefs.obj" "DSP2833x_PieCtrl.obj" "DSP2833x_PieVect.obj" "DSP2833x_Sci.obj" "DSP2833x_SysCtrl.obj" "DSP2833x_usDelay.obj" "Hardware\SRC\DCmotor.obj" "Hardware\SRC\DSP2833x_CpuTimers.obj" "Hardware\SRC\key.obj" "Hardware\SRC\keyboard.obj" "Hardware\SRC\led.obj" "Hardware\SRC\scic.obj" "Hardware\SRC\step_motor.obj" "Hardware\SRC\timer.obj" "User\Example_2833xScia_FFDLB.obj" 
	-$(RM) "DSP2833x_DefaultIsr.d" "DSP2833x_GlobalVariableDefs.d" "DSP2833x_PieCtrl.d" "DSP2833x_PieVect.d" "DSP2833x_Sci.d" "DSP2833x_SysCtrl.d" "Hardware\SRC\DCmotor.d" "Hardware\SRC\DSP2833x_CpuTimers.d" "Hardware\SRC\key.d" "Hardware\SRC\keyboard.d" "Hardware\SRC\led.d" "Hardware\SRC\scic.d" "Hardware\SRC\step_motor.d" "Hardware\SRC\timer.d" "User\Example_2833xScia_FFDLB.d" 
	-$(RM) "DSP2833x_ADC_cal.d" "DSP2833x_CodeStartBranch.d" "DSP2833x_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

