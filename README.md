# cpp_filesystem_size
A simple command line tool to find large files within a specified directory. 

After creating a [similar program using Rust](https://github.com/harr1424/hello_rust), I was curious to learn how to do the same using C++. 

This program will display the ten largest files in the specified directory, as measured in bytes.


```
./cpp_fs_size ~/google-cloud-sdk 
```

```
/Users/user/google-cloud-sdk/bin/anthoscli      94968320
/Users/user/google-cloud-sdk/bin/anthoscli      94968320
/Users/user/google-cloud-sdk/data/cli/gcloud.json       71649707
/Users/user/google-cloud-sdk/data/cli/gcloud.json       71649707
/Users/user/google-cloud-sdk/data/cli/gcloud.json       71649707
/Users/user/google-cloud-sdk/data/cli/gcloud.json       71649707
/Users/user/google-cloud-sdk/lib/googlecloudsdk/generated_clients/apis/compute_alpha.json       4728478
/Users/user/google-cloud-sdk/lib/googlecloudsdk/generated_clients/apis/compute_alpha.json       4728478
/Users/user/google-cloud-sdk/lib/googlecloudsdk/generated_clients/apis/compute_alpha.json       4728478
/Users/user/google-cloud-sdk/lib/googlecloudsdk/generated_clients/apis/compute_alpha.json       4728478
```

I created the same program using [Go](https://github.com/harr1424/go_filesystem_size). 
