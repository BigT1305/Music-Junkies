# 
# Synthesis run script generated by Vivado
# 

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
set_msg_config -id {Synth 8-256} -limit 10000
set_msg_config -id {Synth 8-638} -limit 10000
create_project -in_memory -part xc7a100tcsg324-1

set_param project.singleFileAddWarning.threshold 0
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir {Y:/Google Drive/SLU/_CMPS 375/_units/02_ vivado 1bit adder/And2/And2.cache/wt} [current_project]
set_property parent.project_path {Y:/Google Drive/SLU/_CMPS 375/_units/02_ vivado 1bit adder/And2/And2.xpr} [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language VHDL [current_project]
set_property ip_output_repo {y:/Google Drive/SLU/_CMPS 375/_units/02_ vivado 1bit adder/And2/And2.cache/ip} [current_project]
set_property ip_cache_permissions {read write} [current_project]
read_vhdl -library xil_defaultlib {{Y:/Google Drive/SLU/_CMPS 375/_units/02_ vivado 1bit adder/And2/And2.srcs/sources_1/imports/__demo source files__/And2.vhd}}
foreach dcp [get_files -quiet -all *.dcp] {
  set_property used_in_implementation false $dcp
}
read_xdc {{Y:/Google Drive/SLU/_CMPS 375/_units/02_ vivado 1bit adder/And2/And2.srcs/constrs_1/imports/__demo source files__/Nexys4DDR_Master.xdc}}
set_property used_in_implementation false [get_files {{Y:/Google Drive/SLU/_CMPS 375/_units/02_ vivado 1bit adder/And2/And2.srcs/constrs_1/imports/__demo source files__/Nexys4DDR_Master.xdc}}]


synth_design -top And2 -part xc7a100tcsg324-1


write_checkpoint -force -noxdef And2.dcp

catch { report_utilization -file And2_utilization_synth.rpt -pb And2_utilization_synth.pb }
