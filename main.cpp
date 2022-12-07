#include <iostream>
#include <set>
#include <filesystem>

int main(int argc, char** argv) {
    if (argc != 2) 
    {
        std::cout << "Usage: " << argv[0] << " path_to_directory" << std::endl;
    } 
    else 
    {
        const std::string full_path = argv[1];
        //std::cout << full_path << std::endl;

        std::set<std::string> entries;

        for (const auto& entry : std::filesystem::recursive_directory_iterator(full_path)) {
            //std::cout << entry << std::endl;
            entries.insert(entry.path());
        }
    }
}