// Copyright (C) 2019-2020 Zilliz. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance
// with the License. You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied. See the License for the specific language governing permissions and limitations under the License.

#include "HDFSIOWriter.h"

namespace milvus{
namespace storage{

bool
HDFSIOWriter::open(const std::string& name){
        name_ = name;
        len_ = 0;

        hdfs_fs_ = hdfsConnect("default",0);

        if(hdfs_fs_ == nullptr)
            return false;
        //open file with append mode.
        hdfs_file_ = hdfsOpenFile(hdfs_fs_, name_.c_str(), O_WRONLY | O_APPEND, 0, 0, 0);
        return true;
}

void
HDFSIOWriter::write(void *ptr, int64_t size){
        tSize nums_write_bytes = hdfsWrite(hdfs_fs_, hdfs_file_, reinterpret_cast<char*>(ptr), static_cast<tSize>(size));
        len_ += size;
}

int64_t
HDFSIOWriter::length(){
    return len_;
}

void
HDFSIOWriter::close(){
    int flag = hdfsCloseFile(hdfs_fs_, hdfs_file_);
    //disconnect
    int status = hdfsDisconnect(hdfs_fs_);
}

}
}