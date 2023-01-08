#include <iostream>
#include <vector>
#include <filesystem>
#include <time.h>
#include <unistd.h>


// Struct to contain a string representing a filename and unsigned long long to 
// represent its size. 
struct FS_info
{
    std::string name;
    unsigned long long size;
};

// Number of entries to output 
const size_t NUM_ENTRIES = 10;

// function to pass to sort array of FS_info structs descending
bool sort_by_desc(FS_info const& lhs, FS_info const& rhs)
{
    return lhs.size > rhs.size;
}

// return index of the struct having the smallest file size
int index_of_smallest_entry(FS_info entries[]) {
    unsigned long long smallest = entries[0].size;
    int index = 0;

    for (int i = 0; i < NUM_ENTRIES; i++) {
        if (entries[i].size < smallest) {
            smallest = entries[i].size;
            index = i;
        }
    }

    return index;
}

/*
Recursively visit all filesystem entries at the provided path, and updates the 
FS_Info array as appropriate.
*/
void analyze_fs(FS_info entries[], std::string full_path)
{
    static int num_entries = 0;

    for (const auto &entry : std::__fs::filesystem::recursive_directory_iterator(full_path))
    {
        if (entry.is_regular_file()) 
        {
            if (num_entries < 10)
            {
                entries[num_entries] = FS_info{entry.path(), entry.file_size()};
                num_entries++;
            }
            else 
            {
                int index = index_of_smallest_entry(entries);

                if (entries[index].size < entry.file_size()) {
                    entries[index].name = entry.path();
                    entries[index].size = entry.file_size();
                }
            }
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

    FS_info entries[NUM_ENTRIES];

    analyze_fs(entries, full_path);
    std::sort(std::begin(entries), std::end(entries), sort_by_desc);

    float endTIme = (float)clock() / CLOCKS_PER_SEC;

    // output the specified number of largest files found
    for (int i = 0; i < NUM_ENTRIES; i++) {
        if (entries[i].size > 0) 
        std::cout << entries[i].name << "\t" << entries[i].size << std::endl;
    }
    

    printf("\nProgram completed in %f seconds", endTIme - startTime);

    return EXIT_SUCCESS;
}

// program completes in 0.002 seconds
