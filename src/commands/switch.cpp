#include <tsugou/commands.hpp>
#include <tsugou/exception.hpp>

void tsugou::switch_branch(Ctx &ctx) {
  THROW_ERROR(ctx.get_args().size() == 0, "Branch name missing");

  THROW_ERROR(ctx.get_args()[0].find(' ') != std::string::npos,
              "Branch name should not contain spaces");

  ctx.set_config_field("branch", ctx.get_args()[0]);
  ctx.apply_changes();
}