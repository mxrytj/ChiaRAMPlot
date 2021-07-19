# ChiaRAMPlot
This is a new implementation of a chia plotter which is designed as a processing pipeline, similar to how GPUs work, only the "cores" are normal software CPU threads.
## Usage

  * Select Temporary Directory   
    Temporary directory, needs ~220 GiB
  * Select 2nd Temporary Directory   
    Temporary directory 2, needs ~110 GiB
  * Select Final Directory  
    Final directory
  * Pool Public Key (48 bytes)
  * Pool Contract Address (62 chars)
  * Farmer Public Key (48 bytes)
  * Choose Number of Plots
    Number of plots to create (default = 1)
  * Number of threads
    Number of threads (default = 4)
  * Number of bucket 
    Number of buckets (default = 256)
 
## Results
![12](https://user-images.githubusercontent.com/86047703/126137558-26dc7f57-5ec2-4eeb-a29b-7d004be50fe2.PNG)

## How to Get Pool Contract Address
![444](https://user-images.githubusercontent.com/86047703/126138171-89eb8ed4-dd4b-4664-9268-18b055830f6e.PNG)

## Download
   * https://github.com/mxrytj/ChiaRAMPlot/releases
 
## Dependencies
* cmake (>=3.14)
* libsodium-dev
