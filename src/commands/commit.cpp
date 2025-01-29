#include <tsugou/commands.hpp>

#include <tsugou/commit.hpp>
#include <tsugou/sha2_256.hpp>

void tsugou::commit_changes(Ctx &ctx) {
  THROW_ERROR(ctx.get_args().size() == 0, "Missing commit message")

  Commit commit;
  commit.message = "";
  for (const auto &arg : ctx.get_args()) {
    commit.message += arg;
    if (arg != ctx.get_args().back())
      commit.message += " ";
  }

  commit.timestamp = time(nullptr);
  commit.hash =
      tsugou::sha2_256(commit.message + std::to_string(commit.timestamp));

  std::ofstream f("history", std::ios::app);
  f << commit.hash << " " << commit.timestamp << " '" << commit.message
    << "'\n";
  f.close();
}
