#include <iostream>
#include <vector>
#include <filesystem>

// function to pass to std::sort in order to sort a vector of pairs by second item in descending order
bool sort_by_desc(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
{
    return a.second > b.second;
}

/*
Recursively visit all filesystem entries at the provided path, and if the entry is a regular file,
add its file name and file size to a vector of pairs. If the entry is a directory, this
function will be called recursively.
*/
void analyze_fs(std::vector<std::pair<std::string, int>> &entry_vec, std::string full_path)
{
    for (const auto &entry : std::__fs::filesystem::recursive_directory_iterator(full_path))
    {
        if (entry.is_regular_file())
        {
            std::pair<std::string, int> new_entry = std::make_pair(entry.path(), entry.file_size());
            entry_vec.push_back(new_entry);
        }
        else if (entry.is_directory())
        {
            analyze_fs(entry_vec, entry.path());
        }
    }
}

int main(int argc, char **argv)
{
    // holds the values of files and their sizes found by analyze_fs()
    std::vector<std::pair<std::string, int>> entries;

    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " path_to_directory" << std::endl;
    }
    else
    {
        const std::string full_path = argv[1];
        analyze_fs(entries, full_path);
        std::sort(entries.begin(), entries.end(), sort_by_desc);

        // output the ten largest files found
        if (entries.size() > 10)
        {
            for (int i = 0; i < 10; i++)
            {
                std::cout << entries[i].first << "\t" << entries[i].second << std::endl;
            }
        }
        else
            for (int i = 0; i < entries.size(); i++)
            {
                std::cout << entries[i].first << "\t" << entries[i].second << std::endl;
            }
    }
}
