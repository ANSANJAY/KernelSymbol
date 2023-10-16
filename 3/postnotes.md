$ nm ./hello.ko | grep static
0000000000000000 d static_var

$ nm ./hello.ko | grep global
0000000000000000 T global_fn
0000000000000004 D global_var

$ nm ./hello.ko | grep local

You cannot access to local variables from object files, because gcc does not save information about it. 


