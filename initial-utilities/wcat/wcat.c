#include <stdio.h>
#include <stdlib.h>

void wcat(char *filename){
// Open the file for reading
  FILE *file = fopen(filename, "r");

  //checking whether the fopen() succeeded or not.
  if (file == NULL) {
      printf("cannot open file\n");
      exit(1);
  }
  // Read into buffer and display it line by line
  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), file) != NULL){
    printf("%s", buffer);
  }
  
  // Close the file
  fclose(file);
  
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
      // In the case of command not recognized, just exit
      printf("%s", "Usage: ./wcat filename.");
      return 0;
  }

  for (int i = 1; i < argc; i++) {
      wcat(argv[i]);
    }
  
  return 0;
}
