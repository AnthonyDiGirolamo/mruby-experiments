#include "mruby.h"
#include "mruby/irep.h"
#include "mruby/string.h"

#include <string.h>

static mrb_value software_root(mrb_state* mrb, mrb_value obj)
{
  char *message = NULL;
  mrb_get_args(mrb, "z", &message);
  fprintf(stderr, "set software_root: %s\n", message);
  return mrb_nil_value();
}

static mrb_value arch(mrb_state* mrb, mrb_value obj)
{
  char *message = NULL;
  mrb_get_args(mrb, "z", &message);
  fprintf(stderr, "set arch: %s\n", message);
  // mrb_value v = mrb_str_new(mrb, message, strlen(message));
  // return mrb_string_value_ptr(mrb, v);
  return mrb_true_value();
}

// static mrb_value foo_bar(mrb_state* mrb, mrb_value obj)
// {
//   mrb_value block;
//   mrb_get_args(mrb, "&", &block);
//   fprintf(stderr, "Before block\n");
//   mrb_yield_argv(mrb, block, 0, NULL);
//   fprintf(stderr, "After block\n");
//   return mrb_nil_value();
// }

int main(void)
{
  mrb_state *mrb = mrb_open();

  struct RClass *smithy_config_module = mrb_define_module(mrb, "SmithyConfig");
  mrb_define_class_method(mrb, smithy_config_module, "software_root", software_root, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, smithy_config_module, "arch", arch, MRB_ARGS_REQ(1));
  // mrb_define_method(mrb, foo_class, "bar", foo_bar, ARGS_BLOCK());

  // mrb_load_irep(mrb, simple_module_mrb);
  FILE *f = fopen("smithy_config.rb", "r");
  mrb_load_file(mrb, f);

  mrb_value r;
  printf("running test_call method\n");
  r = mrb_funcall(mrb, mrb_top_self(mrb), "test_call", 0);
  printf("return value: %i\n", r.value.i);
  mrb_value s = mrb_obj_inspect(mrb, r);
  printf("return value: %s\n", mrb_str_to_cstr(mrb, s));

  mrb_close(mrb);
  return 0;
}
