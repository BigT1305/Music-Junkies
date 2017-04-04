# 
# Synthesis run script generated by Vivado
# 

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7a100tcsg324-1

set_param project.singleFileAddWarning.threshold 0
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir C:/Cmps375/DispAlu4/DispAlu4.cache/wt [current_project]
set_property parent.project_path C:/Cmps375/DispAlu4/DispAlu4.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language VHDL [current_project]
set_property ip_output_repo c:/Cmps375/DispAlu4/DispAlu4.cache/ip [current_project]
set_property ip_cache_permissions {read write} [current_project]
read_vhdl -library xil_defaultlib {
  C:/Cmps375/DispAlu4/DispAlu4.srcs/sources_1/imports/Cmps375/Adder1.vhd
  C:/Cmps375/DispAlu4/DispAlu4.srcs/sources_1/new/Alu1.vhd
  C:/Cmps375/DispAlu4/DispAlu4.srcs/sources_1/new/Bin2Hex.vhd
  C:/Cmps375/DispAlu4/DispAlu4.srcs/sources_1/new/Alu4.vhd
  C:/Cmps375/DispAlu4/DispAlu4.srcs/sources_1/new/DispAlu4.vhd
}
foreach dcp [get_files -quiet -all *.dcp] {
  set_property used_in_implementation false $dcp
}

synth_design -top DispAlu4 -part xc7a100tcsg324-1


write_checkpoint -force -noxdef DispAlu4.dcp

catch { report_utilization -file DispAlu4_utilization_synth.rpt -pb DispAlu4_utilization_synth.pb }
