# Hash Part

Hash Part (`hashpart`) is a simple tool for creating hash codes for multiple slices of files.

# Why We Need `hashpart`?

I always found that computing the hash code for verfiying file to be a very time consuming thing. I wanted to speed up the calculation process but can t find the multi-threading algorithm for `SHA256`. Then, I thought may be I could create. So, the `hashpart` was created.

# Quick Start

```bash
hashpart large_v1.gz --thread 4 --size /8
```

*`/8` means let program automatic choose size of each block to generate 8 hash codes.*

```bash
hashpart large_v1.gz -v large_vx.gz.hpc
```

*`.hpc` the default extname of HashPartCollection.*

---

View this repository on [GitHub](https://github.com/Orange23333).
