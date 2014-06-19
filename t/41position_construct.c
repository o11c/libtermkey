#include "../termkey.h"
#include "taplib.h"

int main(int argc, char *argv[])
{
  TermKey   *tk;
  TermKeyKey key;
  int        line, col;

  plan_tests(4);

  tk = termkey_new_abstract("vt100", 0);


  termkey_construct_position(tk, &key, 15, 7);
  is_int(key.type, TERMKEY_TYPE_POSITION, "key.type for position report");

  is_int(termkey_interpret_position(tk, &key, &line, &col), TERMKEY_RES_KEY, "interpret_position yields RES_KEY");

  is_int(line, 15, "line for position report");
  is_int(col,   7, "column for position report");


  termkey_destroy(tk);

  return exit_status();
}
