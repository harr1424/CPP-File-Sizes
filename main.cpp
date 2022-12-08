#include <iostream>
#include <vector>
#include <filesystem>

bool sortByDesc(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
{
    return a.second > b.second;
}

void analyze_fs(std::vector<std::pair<std::string, int>> &entry_vec, std::string full_path)
{
    for (const auto &entry : std::__fs::filesystem::recursive_directory_iterator(full_path))
    {
        if (entry.is_regular_file())
        {
            std::pair<std::string, int> new_entry = std::make_pair(entry.path(), entry.file_size());
            entry_vec.push_back(new_entry);
        }
        else if (entry.is_directory() && entry.path() != full_path)
        {
            analyze_fs(entry_vec, entry.path());
        }
    }
}

int main(int argc, char **argv)
{
    std::vector<std::pair<std::string, int>> entries;

    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " path_to_directory" << std::endl;
    }
    else
    {
        const std::string full_path = argv[1];
        analyze_fs(entries, full_path);
        std::sort(entries.begin(), entries.end(), sortByDesc);

        for (int i = 0; i < 10; i++)
        {
            std::cout << entries[i].first << "\t" << entries[i].second << std::endl;
        }
    }
}
