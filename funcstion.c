//my changes: dump all layers
void dump_x_layer_temp_grid (grid_model_t *model, char *file, grid_model_vector_t *temp, int x)
{
  int i, j;
  char str[STR_SIZE];
  FILE *fp;
  int silidx;

  //layer to print
  if (!model->config.model_secondary) {
      silidx = LAYER_SI;
  } else {
      if(model->has_lcf)
        silidx = SEC_PACK_LAYERS;
      else
        silidx = SEC_PACK_LAYERS + SEC_CHIP_LAYERS;
  }

  /*my changes: 
   *if the cmd_line parameters specifies which layer
   *to print, print that one instead of top
  */
  if (model->layer_specified){
    silidx = model->num_layer;
  }

  if (!model->r_ready)
    fatal("R model not ready\n");

  if (!strcasecmp(file, "stdout"))
    fp = stdout;
  else if (!strcasecmp(file, "stderr"))
    fp = stderr;
  else  
    fp = fopen (file, "w");

  if (!fp) {
      sprintf (str,"error: %s could not be opened for writing\n", file);
      fatal(str);
  }

//my changes: iterate files output instead of a specific file
 
 for(i=0; i < model->rows; i++){
      for(j=0; j < model->cols; j++){
          /* top layer of the most-recently computed 
           * steady state temperature 
           */
  //        fprintf(fp, "%d\t%d\t%.2f\n", j, model->rows-i-1, 
  //                model->last_steady->cuboid[silidx][i][j]); 
          fprintf(fp, "%d\t%.2f\n", i*model->cols+j, 
                  model->last_steady->cuboid[x][i][j]); 
      }
      fprintf(fp, "\n");  
  }

  
}

void dump_all_layer_temp_grid(grid_model_t *model){
  int i;
  char index[2];
  char* layer="layer_"
  sprintf(index, "%d", i);
  for (i = 0; i < model->n_layers; ++i)
  {
    /* code */  
    strcat(layer, index);
    dump_x_layer_temp_grid(model, layer, i)
  }
}
