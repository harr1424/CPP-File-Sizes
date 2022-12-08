#include <iostream>
#include <vector>
#include <filesystem>

int main(int argc, char** argv) {
    if (argc != 2) 
    {
        std::cout << "Usage: " << argv[0] << " path_to_directory" << std::endl;
    } 
    else 
    {
        const std::string full_path = argv[1];

        std::vector<std::pair<std::string, int> > entries;

        for (const auto& entry : std::filesystem::recursive_directory_iterator(full_path)) {
            std::cout << entry.path() << "\t" << entry.file_size() << std::endl;
            std::pair<std::string, int> new_entry = std::make_pair(entry.path(), entry.file_size());
            entries.push_back(new_entry);
        }
    }
}