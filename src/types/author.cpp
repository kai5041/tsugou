#include <tsu/types/author.hpp>

#include <sstream>

namespace tsugou {

Author::Author(std::string username, Dict contacts) : contacts(contacts) {
  this->username = username;
}

void Author::set_contact(std::string platform, std::string value) {
  this->contacts[platform] = value;
}

std::string Author::get_username() { return username; }
Dict Author::get_contacts() { return contacts; }

std::string Author::get_contact(std::string platform) {
  auto it = contacts.find(platform);
  if (it == contacts.end()) {
    return "";
  }

  return it->second;
}

std::string Author::to_string() {
  std::ostringstream oss;
  oss << username;

  if (!contacts.empty()) {
    oss << " ";
    bool first = true;
    for (const auto &contact : contacts) {
      if (contact.first.empty() || contact.second.empty()) {
        continue;
      }

      if (!first) {
        oss << " ";
      }
      oss << contact.first << ":" << contact.second;
      first = false;
    }
  }

  return oss.str();
}

} // namespace tsugou