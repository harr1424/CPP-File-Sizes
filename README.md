# CPP-File-Sizes
A simple command line tool to find large files within a specified directory. 

After creating a [similar program using Rust](https://github.com/harr1424/Rust-Files), I was curious to learn how to do the same using C++. 

This program will display the ten largest files in the specified directory, as measured in bytes.


```
./cpp_fs_size ~/google-cloud-sdk 
```

```
/Users/user/google-cloud-sdk/bin/anthoscli      94968320
/Users/user/google-cloud-sdk/data/cli/gcloud.json       71649707
/Users/user/google-cloud-sdk/lib/googlecloudsdk/generated_clients/apis/compute_alpha.json       4728478
/Users/user/google-cloud-sdk/lib/googlecloudsdk/generated_clients/apis/compute_beta.json        4147516
/Users/user/google-cloud-sdk/lib/googlecloudsdk/generated_clients/apis/compute/alpha/compute_alpha_messages.py  4034669
/Users/user/google-cloud-sdk/lib/googlecloudsdk/generated_clients/apis/compute_v1.json  3904144
/Users/user/google-cloud-sdk/data/cli/gcloud_completions.py     3754693
/Users/user/google-cloud-sdk/lib/googlecloudsdk/generated_clients/apis/compute/beta/compute_beta_messages.py    3537222
/Users/user/google-cloud-sdk/lib/googlecloudsdk/generated_clients/apis/compute/v1/__pycache__/compute_v1_messages.cpython-37.pyc        3388318
/Users/user/google-cloud-sdk/lib/googlecloudsdk/generated_clients/apis/compute/v1/compute_v1_messages.py        3360648
```

I created the same program using [Go](https://github.com/harr1424/go_filesystem_size), and [C](https://github.com/harr1424/c_filesystem_size). 
