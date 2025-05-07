################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/CCS/ccs/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/CCS/Project/Example_2833xScia_FFDLB/Hardware/INS" --include_path="D:/CCS/ccs/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="D:/CCS/Project/Example_2833xScia_FFDLB" -g --define=_DEBUG --define=LARGE_MODEL --quiet --diag_wrap=off --display_error_number --issue_remarks --output_all_syms --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/CCS/ccs/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/CCS/Project/Example_2833xScia_FFDLB/Hardware/INS" --include_path="D:/CCS/ccs/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="D:/CCS/Project/Example_2833xScia_FFDLB" -g --define=_DEBUG --define=LARGE_MODEL --quiet --diag_wrap=off --display_error_number --issue_remarks --output_all_syms --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


