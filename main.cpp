#include <iostream>
#include <vector>
#include <filesystem>
#include <time.h>
#include <unistd.h>

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
void analyze_fs(std::vector<std::pair<std::string, int> > &entry_vec, std::string full_path)
{
    for (const auto &entry : std::__fs::filesystem::recursive_directory_iterator(full_path))
    {
        if (entry.is_regular_file())
        {
            std::pair<std::string, int> new_entry = std::make_pair(entry.path(), entry.file_size());
            entry_vec.push_back(new_entry);
        }
    }
}

int main(int argc, char **argv)
{

    float startTime = (float)clock() / CLOCKS_PER_SEC;
    std::string full_path;

    if (argc > 2) // erroneous command line arguments passed
    {
        std::cerr << "Usage: " << argv[0] << " path_to_directory" << std::endl;
        return EXIT_FAILURE;
    }

    else if (argc == 1) // no path provided as argument
    {
        std::__fs::filesystem::path cwd = std::__fs::filesystem::current_path();
        if (!cwd.empty())
        {
            std::cout << "Defaulting to current directory" << std::endl;
            full_path = cwd;
        }
    }
    else // exactly one path provided as command line argument
    {
        full_path = argv[1];
    }

    // holds the values of files and their sizes found by analyze_fs()
    std::vector<std::pair<std::string, int> > entries;

    analyze_fs(entries, full_path);
    std::sort(entries.begin(), entries.end(), sort_by_desc);

    float endTIme = (float)clock() / CLOCKS_PER_SEC;

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

    printf("\nProgram completed in %f seconds", endTIme - startTime);

    return EXIT_SUCCESS;
}

// program completes in 0.002 seconds
