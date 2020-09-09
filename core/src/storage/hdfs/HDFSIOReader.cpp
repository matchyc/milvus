//License...


#include "storage/hdfs/HDFSIOReader.h"
#include "HDFSClient.h"

namespace milvus{
namespace storage{

bool
HDFSIOReader::open(const std::string & name){
    name_ = name;
    //without Singleton
    /*
    hdfs_fs_ = hdfsConnect("default",0);
    if(hdfs_fs_ == nullptr)
        return false;
    hdfs_file_ = hdfsOpenFile(hdfs_fs_, name_.c_str(), O_RDONLY, 0, 0, 0);
    */
    return HDFSClient::getInstance().open(name.c_str()).ok();
}

void
HDFSIOReader::read(void* ptr, int64_t size){
    tSize nums_of_bytes = hdfsRead(hdfs_fs_, hdfs_file_, reinterpret_cast<char*>(ptr), static_cast<int32_t>(size));
    //nums_of_bytes is useless because of the base class
}

void
HDFSIOReader::seekg(int64_t pos){
    int seek_pos = hdfsSeek(hdfs_fs_, hdfs_file_, pos);
    // if seek_pos == 0 success  , -1 error, but can't be used because of the return value.
}

int64_t
HDFSIOReader::length(){
    hdfsFileInfo *hdfs_file__info = hdfsGetPathInfo(hdfs_fs_, name_.c_str());
    return hdfs_file__info->mSize;
}

void
HDFSIOReader::close(){
    //close file
    int flag = hdfsCloseFile(hdfs_fs_, hdfs_file_);
    //disconnect
    int status = hdfsDisconnect(hdfs_fs_);
}


}//storage

}//milvus




