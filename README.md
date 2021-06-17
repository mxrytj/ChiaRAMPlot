# ChiaRAMPlot
This is a new implementation of a chia plotter which is designed as a processing pipeline, similar to how GPUs work, only the "cores" are normal software CPU threads.
## Usage

  * Select Temporary Directory   
    Temporary directory, needs ~220 GiB
  * Select 2nd Temporary Directory   
    Temporary directory 2, needs ~110 GiB
  * Select Final Directory  
    Final directory (default = <tmpdir>)
  * Pool Public Key (48 bytes)
  * Farmer Public Key (48 bytes)
  * Choose Number of Plots
    Number of plots to create (default = 1)
  * Number of threads
    Number of threads (default = 4)
  * Number of bucket 
    Number of buckets (default = 256)
 
## Results
![5](https://user-images.githubusercontent.com/86047703/122373639-2c738180-cf51-11eb-8367-4e9fb24b424d.PNG)

## Download
   * https://github.com/mxrytj/ChiaRAMPlot/releases
 
## Dependencies
* cmake (>=3.14)
* libsodium-dev
