
#Generate all layers of *.grid.steady:
$ ./hotspot -c ../hotspot.config -f <random>.flp -p <powertrace>.ptrace -model_type grid -detailed_3D on \
  -grid_layer_file <layer_configuration>.lcf -steady_file <steadyfile>.steady 

#Generate all layers of *.grid.steady:
$ ./hotspot -c ../hotspot.config -f <random>.flp -p <powertrace>.ptrace -model_type grid -detailed_3D on \
  -grid_layer_file <layer_configuration>.lcf -steady_file <steadyfile>.steady -grid_steady_file <random>.grid.steady

#Generate svg with *.grid.seady:
$ perl ./grid_thermal_map_V2.pl <layer_configuration>.lcf <random>.grid.steady

#Generate svg of a specific layer 
$ ./hotspot -c ../hotspot.config -f <random>.flp -p <powertrace>.ptrace -model_type grid -detailed_3D on \
  -grid_layer_file <layer_configuration>.lcf -steady_file <steadyfile>.steady \
  -grid_steady_file <random>.grid.steady -nof <the number specified in lcf>
$ perl ./grid_thermal_map.pl <flooplan>.flp <grid_steady>.grid.steady > <svg_name>.svg
