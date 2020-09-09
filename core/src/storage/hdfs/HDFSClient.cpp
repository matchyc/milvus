

#include "HDFSClient.h"

namespace milvus{
namespace storage{

HDFSClient::HDFSClient() {
    //read file from ***.xml to get the setting. then connect
    bld_ = hdfsNewBuilder();
    hdfsBuilderSetNameNode(bld_, namdenode_addr);
    hdfs_fs_ = hdfsBuilderConnect(bld_);
}


Status 
HDFSClient::open(const char* name) {
    hdfs_file_ = hdfsOpenFile(hdfs_fs_, name, O_RDONLY, 0, 0 ,0);
    if(hdfs_file_ == nullptr)
        //error
    return Status::OK();
}

void 
HDFSClient::read(char* ptr, int64_t size) {
    tSize nums_of_bytes = hdfsRead(hdfs_fs_, hdfs_file_, reinterpret_cast<char*>(ptr), static_cast<int32_t>(size));
    if(nums_of_bytes == -1);
    //error
}

void
HDFSClient::seekg(int64_t pos) {
    int seek_pos = hdfsSeek(hdfs_fs_, hdfs_file_, pos);
    // if seek_pos == 0 success  , -1 error, but can't be used because of the return value.
}

int64_t
HDFSClient::length(std::string name) {
    hdfsFileInfo *hdfs_file_info = hdfsGetPathInfo(hdfs_fs_, name.c_str());
    return hdfs_file_info->mSize;
}

void
HDFSClient::close() {
     //close file
    int flag = hdfsCloseFile(hdfs_fs_, hdfs_file_);
    //but did not disconnect
}


}
}