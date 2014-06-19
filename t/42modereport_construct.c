#include "../termkey.h"
#include "taplib.h"

int main(int argc, char *argv[])
{
  TermKey   *tk;
  TermKeyKey key;
  int        initial, mode, value;

  plan_tests(10);

  tk = termkey_new_abstract("vt100", 0);


  termkey_construct_modereport(tk, &key, '?', 1, 2);

  is_int(key.type, TERMKEY_TYPE_MODEREPORT, "key.type for mode report");

  is_int(termkey_interpret_modereport(tk, &key, &initial, &mode, &value), TERMKEY_RES_KEY, "interpret_modereoprt yields RES_KEY");

  is_int(initial, '?', "initial indicator from mode report");
  is_int(mode,      1, "mode number from mode report");
  is_int(value,     2, "mode value from mode report");


  termkey_construct_modereport(tk, &key, 0, 4, 1);

  is_int(key.type, TERMKEY_TYPE_MODEREPORT, "key.type for mode report");

  is_int(termkey_interpret_modereport(tk, &key, &initial, &mode, &value), TERMKEY_RES_KEY, "interpret_modereoprt yields RES_KEY");

  is_int(initial, 0, "initial indicator from mode report");
  is_int(mode,    4, "mode number from mode report");
  is_int(value,   1, "mode value from mode report");


  termkey_destroy(tk);

  return exit_status();
}
