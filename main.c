#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  c.red = MAX_COLOR;
  c.green = 245;
  c.blue = 100;
  struct matrix *edges;
  struct matrix *temp;
  struct matrix *copy;

  edges = new_matrix(4, 4);
  temp = new_matrix(4, 4);
  copy = new_matrix(4, 4);
  ident(temp);
  print_matrix(edges);
  print_matrix(temp);
  print_matrix(copy);

  add_point(temp, 32, 16, 32);
  print_matrix(temp);
  add_point(temp, 16, 0, 16);
  print_matrix(temp);
  add_point(temp, 4, 0, 4);
  print_matrix(temp);
  add_point(temp, 16, 32, 16);
  print_matrix(temp);

  add_edge(edges, 164, 132, 144, 19, 72, 81);
  add_edge(edges, 32, 84, 91, 27, 364, 11);
  add_edge(edges, 91, 361, 444, 69, 93, 13);
  add_edge(edges, 222, 231, 98, 174, 300, 210);
  print_matrix(edges);

  add_edge(copy, 1, 0, 0 , 1, 1, 1);
  add_edge(copy, 0, 0, 12, 1, 4, 10);
  print_matrix(copy);

  matrix_mult(temp, edges);
  print_matrix(edges);

  matrix_mult(copy, edges);
  print_matrix(edges);

  draw_lines(edges, s, c);
  display(s);
  free_matrix( edges );
  free_matrix( copy );
  free_matrix( temp );
}
