#include <filesystem>
#include <prm/core.hpp>

#include <prm/json.hpp>

nlohmann::json config = {
  {"version", "1.0.0"},
  {"name", "PROJECT_NAME"},
  {"prm_version", }  
};

bool prm_project_exists() {
  if (fs::exists(".prm")) {
    if (fs::is_directory(".prm"))
      return true;
    prm::throw_error(".prm is a file, not a directory");
  }
  return false;
}

int prm::init(Ctx &ctx) {
  if (prm_project_exists()) {
    prm::throw_error("Project already exists");
  }

  try {
    fs::create_directory(".prm");
  } catch (const std::exception &e) {
    prm::throw_error("Failed to create .prm directory: " +
                     std::string(e.what()));
  }



  return 0;
}