//License...


#include "storage/hdfs/HDFSIOReader.h"

namespace milvus{
namespace storage{

bool
HDFSIOReader::open(const std::string & name){
    name_ = name;
    hdfs_fs = hdfsConnect("default",0);

    if(hdfs_fs == nullptr)
        return false;

    hdfs_file = hdfsOpenFile(hdfs_fs, name_.c_str(), O_RDONLY, 0, 0, 0);
    return true;
}

void
HDFSIOReader::read(void* ptr, int64_t size){
    tSize nums_of_bytes = hdfsRead(hdfs_fs, hdfs_file, reinterpret_cast<char*>(ptr), static_cast<int32_t>(size));
    //nums_of_bytes is useless because of the base class
}

void
HDFSIOReader::seekg(int64_t pos){
    int seek_pos = hdfsSeek(hdfs_fs, hdfs_file, pos);
    // if seek_pos == 0 success  , -1 error
}






}//storage

}//milvus




